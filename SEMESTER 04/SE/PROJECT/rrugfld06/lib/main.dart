import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';
import 'package:location/location.dart' as loc;
import 'markers.dart'; // <-- Important: import this after other packages

class ThemeManager {
  static final ValueNotifier<ThemeMode> currentTheme =
  ValueNotifier<ThemeMode>(ThemeMode.light);

  static void toggleTheme() {
    currentTheme.value = currentTheme.value == ThemeMode.light
        ? ThemeMode.dark
        : ThemeMode.light;
  }
}

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return ValueListenableBuilder(
      valueListenable: ThemeManager.currentTheme,
      builder: (context, value, child) => MaterialApp(
        title: 'RRUG Facility Locator',
        theme: ThemeData(
          colorScheme: ColorScheme.fromSeed(seedColor: Colors.blue),
          useMaterial3: true,
          fontFamily: 'Roboto',
        ),
        darkTheme: ThemeData(
          colorScheme: ColorScheme.fromSeed(
              seedColor: Colors.blue, brightness: Brightness.dark),
          useMaterial3: true,
          fontFamily: 'Roboto',
        ),
        themeMode: value,
        home: const MapScreen(),
      ),
    );
  }
}

class MapScreen extends StatefulWidget {
  const MapScreen({super.key});

  @override
  State<MapScreen> createState() => _MapScreenState();
}

class _MapScreenState extends State<MapScreen> with TickerProviderStateMixin {
  final MapController _mapController = MapController();
  loc.Location location = loc.Location();
  loc.LocationData? _currentLocation;
  final LatLng _rruCenter = LatLng(23.1535, 72.8850);
  final double _initialZoom = 17.0;
  final double _currentLocationZoom = 19.0;
  bool _locationPermissionGranted = false;
  bool _isLocating = false;

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
    setState(() {
      _locationPermissionGranted = true;
    });
    _getCurrentLocation();
  }

  Future<void> _getCurrentLocation() async {
    if (_isLocating) return;

    setState(() {
      _isLocating = true;
    });

    try {
      final loc.LocationData locationData = await location.getLocation();
      setState(() {
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
      });
    } catch (e) {
      setState(() {
        _isLocating = false;
      });
      debugPrint('Error fetching location: $e');
    }
  }

  void _goToCurrentLocation() async {
    if (_currentLocation != null && _locationPermissionGranted) {
      final targetLatLng =
      LatLng(_currentLocation!.latitude!, _currentLocation!.longitude!);
      _animatedMapMove(targetLatLng, _currentLocationZoom);
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('Centered to your current location!'),
          duration: Duration(seconds: 1),
        ),
      );
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('Finding your location...'),
          duration: Duration(seconds: 1),
        ),
      );

      await _getCurrentLocation();

      if (_currentLocation != null) {
        final targetLatLng =
        LatLng(_currentLocation!.latitude!, _currentLocation!.longitude!);
        _animatedMapMove(targetLatLng, _currentLocationZoom);

        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(
            content: Text('Centered to your current location!'),
            duration: Duration(seconds: 1),
          ),
        );
      } else {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(
            content: Text('Unable to find your location. Please check permissions.'),
            duration: Duration(seconds: 3),
          ),
        );
      }
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
                value == ThemeMode.light ? Icons.light_mode : Icons.dark_mode,
              ),
            ),
          )
        ],
      ),
      drawer: Drawer(
        child: ListView(
          padding: EdgeInsets.zero,
          children: const <Widget>[
            DrawerHeader(
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
              leading: Icon(Icons.food_bank),
              title: Text('Food Stalls'),
              contentPadding: EdgeInsets.symmetric(horizontal: 16.0),
            ),
            ListTile(
              leading: Icon(Icons.wc),
              title: Text('Restrooms'),
              contentPadding: EdgeInsets.symmetric(horizontal: 16.0),
            ),
            ListTile(
              leading: Icon(Icons.school),
              title: Text('Academic Buildings'),
              contentPadding: EdgeInsets.symmetric(horizontal: 16.0),
            ),
            ListTile(
              leading: Icon(Icons.water_drop),
              title: Text('Water Sources'),
              contentPadding: EdgeInsets.symmetric(horizontal: 16.0),
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
                urlTemplate: Theme.of(context).brightness == Brightness.dark
                    ? 'https://{s}.basemaps.cartocdn.com/dark_all/{z}/{x}/{y}{r}.png'
                    : 'https://tile.openstreetmap.org/{z}/{x}/{y}.png',
                subdomains: const ['a', 'b', 'c'],
                userAgentPackageName: 'com.example.app',
              ),
              MarkerLayer(
                markers: [
                  if (_currentLocationMarker != null) _currentLocationMarker!,
                  ...facilityMarkers, // <-- Facility markers from markers.dart
                ],
              ),
            ],
          ),
          Positioned(
            top: 16,
            right: 16,
            child: Card(
              shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.circular(12.0),
              ),
              elevation: 6,
              color: Theme.of(context).cardColor.withOpacity(0.9),
              child: Padding(
                padding: const EdgeInsets.all(12.0),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    const Padding(
                      padding: EdgeInsets.only(bottom: 8.0),
                      child: Text(
                        'Map Legend',
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 16,
                        ),
                      ),
                    ),
                    const Divider(height: 8),
                    const SizedBox(height: 4),
                    _buildLegendItem(Colors.green, 'Food Area', Icons.restaurant),
                    const SizedBox(height: 8),
                    _buildLegendItem(Colors.blue, 'Water Source', Icons.water_drop),
                    const SizedBox(height: 8),
                    _buildLegendItem(Colors.grey, 'Washroom', Icons.wc),
                    const SizedBox(height: 8),
                    _buildLegendItem(Colors.blue, 'Your Location', Icons.my_location),
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
            heroTag: 'location',
            backgroundColor: Colors.blue,
            child: _isLocating
                ? const SizedBox(
              width: 24,
              height: 24,
              child: CircularProgressIndicator(
                color: Colors.white,
                strokeWidth: 2.5,
              ),
            )
                : const Icon(Icons.my_location, color: Colors.white),
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
            heroTag: 'zoomIn',
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
            heroTag: 'zoomOut',
            child: const Icon(Icons.remove),
          ),
        ],
      ),
    );
  }

  void _animatedMapMove(LatLng destLocation, double destZoom) {
    final latTween = Tween<double>(
        begin: _mapController.camera.center.latitude,
        end: destLocation.latitude);
    final lngTween = Tween<double>(
        begin: _mapController.camera.center.longitude,
        end: destLocation.longitude);
    final zoomTween = Tween<double>(begin: _mapController.camera.zoom, end: destZoom);

    final controller =
    AnimationController(duration: const Duration(milliseconds: 500), vsync: this);
    final animation = CurvedAnimation(parent: controller, curve: Curves.fastOutSlowIn);

    controller.addListener(() {
      _mapController.moveAndRotate(
        LatLng(latTween.evaluate(animation), lngTween.evaluate(animation)),
        zoomTween.evaluate(animation),
        0,
      );
    });

    animation.addStatusListener((status) {
      if (status == AnimationStatus.completed ||
          status == AnimationStatus.dismissed) {
        controller.dispose();
      }
    });

    controller.forward();
  }

  Widget _buildLegendItem(Color color, String text, IconData icon) {
    return Row(
      children: [
        Container(
          width: 28,
          height: 28,
          decoration: BoxDecoration(
            color: color,
            shape: BoxShape.circle,
            boxShadow: [
              BoxShadow(
                color: Colors.black.withOpacity(0.1),
                blurRadius: 2,
                spreadRadius: 1,
              ),
            ],
          ),
          child: Icon(
            icon,
            size: 16,
            color: Colors.white,
          ),
        ),
        const SizedBox(width: 12),
        Text(
          text,
          style: const TextStyle(fontSize: 14),
        ),
      ],
    );
  }
}