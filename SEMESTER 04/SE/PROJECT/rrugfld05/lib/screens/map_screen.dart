import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';
import 'package:location/location.dart' as loc;
import 'package:rrugfld05/main.dart';

class MapScreen extends StatefulWidget {
  const MapScreen({super.key});

  @override
  State<MapScreen> createState() => _MapScreenState();
}

class _MapScreenState extends State<MapScreen> {
  final MapController _mapController = MapController();
  loc.Location location = loc.Location();
  loc.LocationData? _currentLocation;
  final LatLng _rruCenter = LatLng(23.1535, 72.8850);
  final double _initialZoom = 17.0;
  bool _locationPermissionGranted = false;

  Marker? _currentLocationMarker;

  @override
  void initState() {
    super.initState();
    _requestLocationPermission();
    _mapController.mapEventStream.listen((event) {
      if (event is MapEventMove) {
        setState(() {});
      }
    });
    WidgetsBinding.instance.addPostFrameCallback((_) {
      _mapController.moveAndRotate(_rruCenter, _initialZoom, 0);
    });
  }

  Future<void> _requestLocationPermission() async {
    bool serviceEnabled;
    loc.PermissionStatus permissionGranted;

    serviceEnabled = await location.serviceEnabled();
    if (!serviceEnabled) {
      serviceEnabled = await location.requestService();
      if (!serviceEnabled) {
        // Show error message: location service not enabled
        ScaffoldMessenger.of(context).showSnackBar(const SnackBar(
          content: Text(
              'Unable to find your location. Please check that the location services are enabled.'),
        ));
        return;
      }
    }

    permissionGranted = await location.hasPermission();
    if (permissionGranted == loc.PermissionStatus.denied) {
      permissionGranted = await location.requestPermission();
      if (permissionGranted != loc.PermissionStatus.granted) {
        // Show error message: location permission not granted
        ScaffoldMessenger.of(context).showSnackBar(const SnackBar(
          content: Text(
              'Unable to find your location. Please check your location permissions.'),
        ));
        return;
      }
    }
    setState(() {
      _locationPermissionGranted = true;
    });
    _goToCurrentLocation();
  }

  Future<void> _getCurrentLocation() async {
    try {
      final loc.LocationData locationData = await location.getLocation();
      setState(() {
        _currentLocation = locationData;
        _currentLocationMarker = Marker(
          width: 40.0,
          height: 40.0,
          point: LatLng(locationData.latitude!, locationData.longitude!),
          child: Container(
            decoration: BoxDecoration(
              shape: BoxShape.circle,
              color: Colors.blue,
            ),
            child: const Icon(
              Icons.location_on,
              size: 24,
              color: Colors.white,
            ),
          ),
        );
      });
      if (_currentLocation != null && _locationPermissionGranted) {
        _mapController.move(
          LatLng(_currentLocation!.latitude!, _currentLocation!.longitude!),
          19.0,
        );
      }
    } catch (e) {
      //debugPrint('Error fetching location: $e');
    }
  }

  void _goToCurrentLocation() {
    if (_currentLocation != null && _locationPermissionGranted) {
      _mapController.move(
        LatLng(_currentLocation!.latitude!, _currentLocation!.longitude!),
        19.0,
      );
    }
    _getCurrentLocation();
  }

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
    final bounds = LatLngBounds(
      LatLng(23.150039, 72.878816),
      LatLng(23.156697, 72.891541),
    );

    return Scaffold(
      appBar: AppBar(
        title: const Text('RRUG Facility Locator'),
        actions: [
          IconButton(
            onPressed: ThemeManager.toggleTheme,
            icon: ValueListenableBuilder(
              valueListenable: ThemeManager.currentTheme,
              builder: (context, value, child) => Icon(
                value == ThemeMode.light
                    ? Icons.light_mode
                    : Icons.dark_mode,
              ),
            ),
          )
        ],
      ),
      drawer: Drawer(
        child: ListView(
          padding: EdgeInsets.zero,
          children: <Widget>[
            const DrawerHeader(
              decoration: BoxDecoration(
                color: Colors.blue,
              ),
              child: Text(
                'Facilities',
                style: TextStyle(
                  color: Colors.white,
                  fontSize: 24,
                ),
              ),
            ),
            ListTile(
              leading: const Icon(Icons.food_bank),
              title: const Text('Food Stalls'),
              contentPadding: const EdgeInsets.symmetric(horizontal: 16.0),
            ),
            ListTile(
              leading: const Icon(Icons.wc),
              title: const Text('Restrooms'),
              contentPadding: const EdgeInsets.symmetric(horizontal: 16.0),
            ),
            ListTile(
              leading: const Icon(Icons.school),
              title: const Text('Academic Buildings'),
              contentPadding: const EdgeInsets.symmetric(horizontal: 16.0),
            ),
            ListTile(
              leading: const Icon(Icons.water_drop),
              title: const Text('Water Sources'),
              contentPadding: const EdgeInsets.symmetric(horizontal: 16.0),
            ),
          ],
        ),
      ),
      body: Stack(
        children: [
          FlutterMap(
            mapController: _mapController,
            options: MapOptions(
              initialCenter: _rruCenter,
              initialZoom: _initialZoom,
              minZoom: 14.0,
              maxZoom: 21.0,
              cameraConstraint: CameraConstraint.contain(bounds: bounds),
            ),
            children: [
              TileLayer(
                urlTemplate: 'https://tile.openstreetmap.org/{z}/{x}/{y}.png',
              ),
              MarkerLayer(
                markers: [
                  // If current location marker exists, use it. Otherwise, fallback to RRUG center.
                  if (_currentLocationMarker != null)
                    _currentLocationMarker!
                  else
                    Marker(
                      width: 40.0,
                      height: 40.0,
                      point: _rruCenter,
                      child: Container(
                        decoration: BoxDecoration(
                          shape: BoxShape.circle,
                          color: Colors.red,
                        ),
                        child: const Icon(
                          Icons.location_on,
                          size: 24,
                          color: Colors.white,
                        ),
                      ),
                    ),
                ],
              ),
            ],
          ),
          Positioned(
            top: 10,
            right: 10,
            child: Card(
              shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.circular(15.0),
              ),
              elevation: 4,
              color: Theme.of(context).cardColor.withOpacity(0.8),
              child: Padding(
                padding: const EdgeInsets.all(8.0),
                child: Column(
                  children: [
                    Row(
                      children: [
                        Container(
                          width: 20,
                          height: 20,
                          color: Colors.green,
                        ),
                        const SizedBox(width: 5),
                        const Text('Food Area'),
                      ],
                    ),
                    Row(
                      children: [
                        Container(
                          width: 20,
                          height: 20,
                          color: Colors.blue,
                        ),
                        const SizedBox(width: 5),
                        const Text('Water Source'),
                      ],
                    ),
                    Row(
                      children: [
                        Container(
                          width: 20,
                          height: 20,
                          color: Colors.grey,
                        ),
                        const SizedBox(width: 5),
                        const Text('Washroom'),
                      ],
                    ),
                  ],
                ),
              ),
            ),
          ),
        ],
      ),
      floatingActionButton: Column(
        mainAxisAlignment: MainAxisAlignment.end,
        children: [
          FloatingActionButton(
            onPressed: _goToCurrentLocation,
            tooltip: 'Go to Current Location',
            child: const Icon(Icons.my_location),
          ),
          const SizedBox(height: 10),
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
            child: const Icon(Icons.add),
          ),
          const SizedBox(height: 10),
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
            child: const Icon(Icons.remove),
          ),
        ],
      ),
    );
  }
}