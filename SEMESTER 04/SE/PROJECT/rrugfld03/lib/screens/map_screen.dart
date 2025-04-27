import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';
import 'package:location/location.dart' as loc;
import 'package:rrugfld02/widgets/location_legend.dart';

class MapScreen extends StatefulWidget {
  const MapScreen({super.key});

  @override
  State<MapScreen> createState() => _MapScreenState();
}

class _MapScreenState extends State<MapScreen> {
  final MapController _mapController = MapController();
  loc.Location location = loc.Location(); // Location object with prefix
  loc.LocationData? _currentLocation; // LocationData object with prefix
  final LatLng _rruCenter = LatLng(23.1535, 72.8850);
  final double _initialZoom = 17.0;
  bool _locationPermissionGranted = false; // Flag to track location permission status

  final List<Map<String, dynamic>> _locations = [
    {
      'name': 'Food Area',
      'position': LatLng(23.1540, 72.8870),
      'type': 'food',
    },
    {
      'name': 'Water Source',
      'position': LatLng(23.1520, 72.8890),
      'type': 'water',
    },
    {
      'name': 'Washroom',
      'position': LatLng(23.1550, 72.8900),
      'type': 'washroom',
    },
  ];

  @override
  void initState() {
    super.initState();
    _requestLocationPermission(); // Request permissions in initState
    WidgetsBinding.instance.addPostFrameCallback((_) {
      _mapController.moveAndRotate(_rruCenter, _initialZoom, 0);
    });
  }
  // Function to request location permissions
  Future<void> _requestLocationPermission() async {
    bool serviceEnabled;
    loc.PermissionStatus permissionGranted;
    print('request permission start');
    serviceEnabled = await location.serviceEnabled();
    if (!serviceEnabled) {
      serviceEnabled = await location.requestService();
      if (!serviceEnabled) {
        print('service not enable');
        return;
      }
    }

    permissionGranted = await location.hasPermission();
    if (permissionGranted == loc.PermissionStatus.denied) {
      permissionGranted = await location.requestPermission();
      if (permissionGranted != loc.PermissionStatus.granted) {
        print('permission not granted');
        return;
      }
    }
    setState(() {
      _locationPermissionGranted = true;
    });
    print('permission granted');
    _getCurrentLocation();
  }
  // Function to get the current location
  Future<void> _getCurrentLocation() async {
    try {
      final loc.LocationData locationData = await location.getLocation();
      setState(() {
        _currentLocation = locationData;
      });
      debugPrint(_currentLocation.toString());
      // Move the map to the current location here
      if (_currentLocation != null && _locationPermissionGranted) {
        _mapController.moveAndRotate(
          LatLng(
            _currentLocation!.latitude!,
            _currentLocation!.longitude!,
          ),
          _initialZoom,
          0,
        );
      }
    } catch (e) {
      debugPrint('Error fetching location: $e');
    }
  }

  // Function to move the map to the current location
  void _goToCurrentLocation() {
    print('Go to current location');
    if (!_locationPermissionGranted) {
      debugPrint("Location permission has not been granted.");
      _requestLocationPermission();
    }
    else if (_currentLocation == null) {
      debugPrint("Current location has not been set");
    }

  }

  // Function to get the appropriate color for the marker
  Color _getMarkerColor(String type) {
    switch (type) {
      case 'food':
        return Colors.green;
      case 'water':
        return Colors.blue;
      case 'washroom':
        return Colors.grey;
      default:
        return Colors.red;
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
      body: Stack(
        children: [
          FlutterMap(
            mapController: _mapController,
            options: MapOptions(
              initialCenter: _rruCenter,
              initialZoom: _initialZoom,
              minZoom: 14.0,
              maxZoom: 21.0, // Set to 21 for more zoom
              cameraConstraint: CameraConstraint.contain(bounds: bounds),
            ),
            children: [
              TileLayer(
                urlTemplate: 'https://tile.openstreetmap.org/{z}/{x}/{y}.png',
              ),
              MarkerLayer(
                markers: [
                  // Marker for the RRUG Center
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
                  // Add additional markers for each location
                  ..._locations.map((location) {
                    return Marker(
                      width: 40.0,
                      height: 40.0,
                      point: location['position'],
                      child: Column(
                        children: [
                          Icon(
                            Icons.location_on,
                            size: 40,
                            color: _getMarkerColor(location['type']),
                          ),
                          Text(
                            location['name'],
                            style: const TextStyle(
                              color: Colors.black,
                              fontSize: 12,
                            ),
                          ),
                        ],
                      ),
                    );
                  }).toList(),
                  if (_currentLocation != null && _locationPermissionGranted)
                    Marker(
                      width: 80.0,
                      height: 80.0,
                      point: LatLng(
                        _currentLocation!.latitude!,
                        _currentLocation!.longitude!,
                      ),
                      child: const Icon(
                        Icons.location_on,
                        size: 40,
                        color: Colors.blue,
                      ),
                    ),
                ],
              ),
            ],
          ),
          // Legend at the top-right corner
          const Positioned(
            top: 10,
            right: 10,
            child: LocationLegend(),
          ),
        ],
      ),
      floatingActionButton: Column(
        mainAxisAlignment: MainAxisAlignment.end,
        children: [
          // Current location button
          if(_locationPermissionGranted) FloatingActionButton(
            onPressed: _goToCurrentLocation,
            tooltip: 'Go to Current Location',
            child: const Icon(Icons.my_location),
          ),
          const SizedBox(height: 10),
          // Zoom-in button
          FloatingActionButton(
            onPressed: () {
              final currentZoom = _mapController.camera.zoom;
              if (currentZoom < 21.0) {
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