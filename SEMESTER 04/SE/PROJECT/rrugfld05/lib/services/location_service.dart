import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';
import 'package:location/location.dart' as loc;

class LocationService {
  final MapController mapController;
  final TickerProvider tickerProvider;
  final VoidCallback onLocationChanged;

  loc.Location location = loc.Location();
  loc.LocationData? _currentLocation;
  final double _currentLocationZoom = 19.0;
  bool _locationPermissionGranted = false;
  bool _isLocating = false;

  Marker? _currentLocationMarker;

  LocationService({
    required this.mapController,
    required this.tickerProvider,
    required this.onLocationChanged,
  }) {
    // Configure location settings for better accuracy
    location.changeSettings(
      accuracy: loc.LocationAccuracy.high,
      interval: 1000,
      distanceFilter: 10,
    );

    _requestLocationPermission();
  }

  bool get isLocating => _isLocating;
  Marker? get currentLocationMarker => _currentLocationMarker;

  Future<void> _requestLocationPermission() async {
    bool serviceEnabled;
    loc.PermissionStatus permissionGranted;

    serviceEnabled = await location.serviceEnabled();
    if (!serviceEnabled) {
      serviceEnabled = await location.requestService();
      if (!serviceEnabled) {
        return;
      }
    }

    permissionGranted = await location.hasPermission();
    if (permissionGranted == loc.PermissionStatus.denied) {
      permissionGranted = await location.requestPermission();
      if (permissionGranted != loc.PermissionStatus.granted) {
        return;
      }
    }

    _locationPermissionGranted = true;
    _getCurrentLocation();
  }

  Future<bool> _getCurrentLocation() async {
    if (_isLocating) return false; // Prevent multiple simultaneous location requests

    _isLocating = true;
    onLocationChanged();

    try {
      final loc.LocationData locationData = await location.getLocation();

      // Check if the location data is valid
      if (locationData.latitude == null || locationData.longitude == null) {
        _isLocating = false;
        onLocationChanged();
        debugPrint('Invalid location data');
        return false;
      }

      _currentLocation = locationData;
      _currentLocationMarker = Marker(
        width: 40.0,
        height: 40.0,
        point: LatLng(locationData.latitude!, locationData.longitude!),
        child: Container(
          decoration: const BoxDecoration(
            shape: BoxShape.circle,
            color: Colors.blue,
            boxShadow: [
              BoxShadow(
                color: Colors.black26,
                spreadRadius: 2,
                blurRadius: 5,
              )
            ],
          ),
          child: const Icon(
            Icons.my_location,
            size: 24,
            color: Colors.white,
          ),
        ),
      );
      _isLocating = false;
      onLocationChanged();

      return true;
    } catch (e) {
      _isLocating = false;
      onLocationChanged();
      debugPrint('Error fetching location: $e');
      return false;
    }
  }

  void goToCurrentLocation(BuildContext context) async {
    // Clear any existing snackbars
    ScaffoldMessenger.of(context).hideCurrentSnackBar();

    // Show loading indicator
    ScaffoldMessenger.of(context).showSnackBar(
      const SnackBar(
        content: Text('Finding your location...'),
        duration: Duration(seconds: 1),
      ),
    );

    // Get fresh location data and check if successful
    bool locationFound = await _getCurrentLocation();

    // Clear any existing snackbars to remove the "finding location" message
    ScaffoldMessenger.of(context).hideCurrentSnackBar();

    // If we have location data, animate to it with smooth transition
    if (locationFound && _currentLocation != null && _locationPermissionGranted) {
      final targetLatLng = LatLng(_currentLocation!.latitude!, _currentLocation!.longitude!);

      debugPrint('Moving to location: $targetLatLng with zoom: $_currentLocationZoom');

      // Force rebuild to ensure marker is visible
      onLocationChanged();

      // Add small delay before animation to ensure state is updated
      Future.delayed(const Duration(milliseconds: 100), () {
        // Animate to the user's current location with a zoom level that mimics Google Maps
        _animatedMapMove(
          targetLatLng,
          _currentLocationZoom,
        );
      });

      // Show confirmation
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('Location found!'),
          duration: Duration(seconds: 1),
        ),
      );
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('Unable to find your location. Please check your location permissions.'),
          duration: Duration(seconds: 3),
        ),
      );
    }
  }

  // Animated map movement function
  void _animatedMapMove(LatLng destLocation, double destZoom) {
    debugPrint('Starting animation from: ${mapController.camera.center} to: $destLocation');
    debugPrint('Zoom: from ${mapController.camera.zoom} to $destZoom');

    try {
      // Create a controller for this animation
      final latTween = Tween<double>(
          begin: mapController.camera.center.latitude,
          end: destLocation.latitude);
      final lngTween = Tween<double>(
          begin: mapController.camera.center.longitude,
          end: destLocation.longitude);
      final zoomTween = Tween<double>(begin: mapController.camera.zoom, end: destZoom);

      // Create an animation controller with longer duration for visibility
      final controller = AnimationController(
          duration: const Duration(milliseconds: 800), vsync: tickerProvider);
      final Animation<double> animation =
      CurvedAnimation(parent: controller, curve: Curves.easeInOut);

      controller.addListener(() {
        try {
          final newLat = latTween.evaluate(animation);
          final newLng = lngTween.evaluate(animation);
          final newZoom = zoomTween.evaluate(animation);

          // Only update if valid
          if (newLat.isFinite && newLng.isFinite && newZoom.isFinite) {
            mapController.moveAndRotate(
              LatLng(newLat, newLng),
              newZoom,
              0,
            );
          }
        } catch (e) {
          debugPrint('Error during animation frame: $e');
        }
      });

      animation.addStatusListener((status) {
        if (status == AnimationStatus.completed) {
          debugPrint('Animation completed successfully');
          controller.dispose();
        } else if (status == AnimationStatus.dismissed) {
          controller.dispose();
        }
      });

      controller.forward();
    } catch (e) {
      debugPrint('Error setting up animation: $e');
      // Fallback to immediate move if animation fails
      mapController.move(destLocation, destZoom);
    }
  }
}