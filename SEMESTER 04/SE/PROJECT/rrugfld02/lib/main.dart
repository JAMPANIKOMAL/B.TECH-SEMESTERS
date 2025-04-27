import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';
import 'package:location/location.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'RRUG Facility Locator',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MapScreen(),
    );
  }
}

class MapScreen extends StatefulWidget {
  const MapScreen({super.key});

  @override
  State<MapScreen> createState() => _MapScreenState();
}

class _MapScreenState extends State<MapScreen> {
  final MapController _mapController = MapController();
  Location location = Location();
  LocationData? _currentLocation;
  final LatLng _rruCenter = LatLng(23.1535, 72.8850);
  final double _initialZoom = 17.0;

  @override
  void initState() {
    super.initState();
    // Locking the map's center and zoom level after the widget is built
    WidgetsBinding.instance.addPostFrameCallback((_) {
      _mapController.moveAndRotate(_rruCenter, _initialZoom, 0);
    });
    _getCurrentLocation();
  }

  // Function to get the current location
  Future<void> _getCurrentLocation() async {
    try {
      final LocationData locationData = await location.getLocation();
      setState(() {
        _currentLocation = locationData;
      });
    } catch (e) {
      // Using debugPrint instead of print for production code
      debugPrint('Could not get location: $e');
    }
  }

  // Function to move the map to the current location
  void _goToCurrentLocation() {
    if (_currentLocation != null) {
      _mapController.moveAndRotate(
        LatLng(_currentLocation!.latitude!, _currentLocation!.longitude!),
        _initialZoom,
        0,
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    // Define bounds for restricting map movement
    final bounds = LatLngBounds(
      LatLng(23.150039, 72.878816), // South-West (SW) corner
      LatLng(23.156697, 72.891541), // North-East (NE) corner
    );

    return Scaffold(
      appBar: AppBar(
        title: const Text('RRUG Facility Locator'),
      ),
      body: FlutterMap(
        mapController: _mapController,
        options: MapOptions(
          initialCenter: _rruCenter,
          initialZoom: _initialZoom,
          minZoom: 14.0,
          maxZoom: 19.0,
          // Use bounds and proper syntax for constraints
          cameraConstraint: CameraConstraint.contain(bounds: bounds),
        ),
        children: [
          TileLayer(
            urlTemplate: 'https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png',
            subdomains: const ['a', 'b', 'c'],
          ),
          MarkerLayer(
            markers: [
              Marker(
                width: 40.0,
                height: 40.0,
                point: _rruCenter,
                child: const Icon(
                  Icons.location_on,
                  size: 40,
                  color: Colors.red,
                ),
              ),
            ],
          ),
        ],
      ),
      floatingActionButton: Column(
        mainAxisAlignment: MainAxisAlignment.end,
        children: [
          // Current location button
          FloatingActionButton(
            onPressed: _goToCurrentLocation,
            tooltip: 'Go to Current Location',
            child: const Icon(Icons.my_location),
          ),
          const SizedBox(height: 10),
          // Zoom-in button
          FloatingActionButton(
            onPressed: () {
              final currentZoom = _mapController.camera.zoom;
              if (currentZoom < 19.0) {
                _mapController.moveAndRotate(
                  _mapController.camera.center,
                  currentZoom + 1.0,
                  0,
                );
              }
            },
            tooltip: 'Zoom In',
            child: const Icon(Icons.zoom_in),
          ),
          const SizedBox(height: 10),
          // Zoom-out button
          FloatingActionButton(
            onPressed: () {
              final currentZoom = _mapController.camera.zoom;
              if (currentZoom > 14.0) {
                _mapController.moveAndRotate(
                  _mapController.camera.center,
                  currentZoom - 1.0,
                  0,
                );
              }
            },
            tooltip: 'Zoom Out',
            child: const Icon(Icons.zoom_out),
          ),
        ],
      ),
    );
  }
}