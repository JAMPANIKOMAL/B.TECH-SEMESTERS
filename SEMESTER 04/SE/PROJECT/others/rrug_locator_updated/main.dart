import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';
import 'package:flutter_map_marker_cluster_plus/flutter_map_marker_cluster_plus.dart';
import 'package:location/location.dart' as loc;
import 'package:flutter/services.dart'; // For SystemChrome
import 'package:flutter_map/flutter_map.dart' as fmap;
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
  WidgetsFlutterBinding.ensureInitialized();
  SystemChrome.setPreferredOrientations([
    DeviceOrientation.portraitUp,
  ]);
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
  bool _isLegendPinned = true;
  Facility? _selectedFacility;
  bool _showInfoWindow = false;
  LatLng? _infoWindowPosition;
  bool _isOfflineMapLoaded = false;
  bool _isLoadingOfflineMap = false;

  Marker? _currentLocationMarker;

  @override
  void initState() {
    super.initState();
    _requestLocationPermission();
    _mapController.mapEventStream.listen((event) {
      if (event is MapEventMove) {
        setState(() {
          // Close info window when map is moved
          if (_showInfoWindow) {
            _showInfoWindow = false;
          }
        });
      }
    });
    WidgetsBinding.instance.addPostFrameCallback((_) {
      _mapController.moveAndRotate(_rruCenter, _initialZoom, 0);
      // Simulate loading offline map
      _loadOfflineMap();
    });
  }

  // Simulate loading offline map data
  Future<void> _loadOfflineMap() async {
    if (_isOfflineMapLoaded || _isLoadingOfflineMap) return;

    setState(() {
      _isLoadingOfflineMap = true;
    });

    // Simulate loading time
    await Future.delayed(const Duration(seconds: 2));

    setState(() {
      _isOfflineMapLoaded = true;
      _isLoadingOfflineMap = false;
    });

    ScaffoldMessenger.of(context).showSnackBar(
      const SnackBar(
        content: Text('Offline map data loaded successfully!'),
        duration: Duration(seconds: 2),
      ),
    );
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

  void _showMarkerInfo(Facility facility) {
    setState(() {
      _selectedFacility = facility;
      _showInfoWindow = true;
      _infoWindowPosition = facility.location;

      // Center the map on the selected facility
      _animatedMapMove(facility.location, _mapController.camera.zoom);
    });
  }

  @override
  Widget build(BuildContext context) {
    final bounds = LatLngBounds(
      LatLng(23.150039, 72.878816),
      LatLng(23.156697, 72.891541),
    );

    // Create a list of markers, implementing tap functionality
    final List<Marker> markersWithTap = allFacilities.map((facility) {
      return Marker(
        width: 120.0,
        height: 40.0,
        point: facility.location,
        child: GestureDetector(
          onTap: () => _showMarkerInfo(facility),
          child: Column(
            children: [
              if (facility.shortName.isNotEmpty)
                Container(
                  padding: const EdgeInsets.symmetric(horizontal: 4, vertical: 2),
                  decoration: BoxDecoration(
                    color: Colors.black87,
                    borderRadius: BorderRadius.circular(4),
                  ),
                  child: Text(
                    facility.shortName,
                    style: const TextStyle(color: Colors.white, fontSize: 12),
                  ),
                ),
              _buildFacilityMarker(facility.color, facility.icon),
            ],
          ),
        ),
      );
    }).toList();

    if (_currentLocationMarker != null) {
      markersWithTap.add(_currentLocationMarker!);
    }

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
          children: <Widget>[
            DrawerHeader(
              decoration: const BoxDecoration(
                color: Colors.blue,
              ),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  const Text(
                    'Facilities',
                    style: TextStyle(
                      color: Colors.white,
                      fontSize: 24,
                    ),
                  ),
                  const SizedBox(height: 10),
                  Container(
                    padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
                    decoration: BoxDecoration(
                      color: _isOfflineMapLoaded ? Colors.green : Colors.orange,
                      borderRadius: BorderRadius.circular(12),
                    ),
                    child: Row(
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        Icon(
                          _isOfflineMapLoaded ? Icons.check_circle : Icons.cloud_download,
                          color: Colors.white,
                          size: 16,
                        ),
                        const SizedBox(width: 4),
                        Text(
                          _isOfflineMapLoaded ? 'Offline Map Ready' : 'Online Mode',
                          style: const TextStyle(color: Colors.white, fontSize: 12),
                        ),
                      ],
                    ),
                  ),
                ],
              ),
            ),
            ListTile(
              leading: const Icon(Icons.food_bank),
              title: const Text('Food Stalls'),
              contentPadding: const EdgeInsets.symmetric(horizontal: 16.0),
              onTap: () {
                // Find a food stall facility and center the map on it
                final foodStall = allFacilities.firstWhere(
                      (facility) => facility.icon == Icons.restaurant,
                  orElse: () => allFacilities.first,
                );
                _animatedMapMove(foodStall.location, 18.0);
                Navigator.pop(context); // Close drawer
              },
            ),
            ListTile(
              leading: const Icon(Icons.wc),
              title: const Text('Restrooms'),
              contentPadding: const EdgeInsets.symmetric(horizontal: 16.0),
              onTap: () {
                // Find a restroom facility and center the map on it
                final restroom = allFacilities.firstWhere(
                      (facility) => facility.icon == Icons.wc,
                  orElse: () => allFacilities.first,
                );
                _animatedMapMove(restroom.location, 18.0);
                Navigator.pop(context); // Close drawer
              },
            ),
            ListTile(
              leading: const Icon(Icons.school),
              title: const Text('Academic Buildings'),
              contentPadding: const EdgeInsets.symmetric(horizontal: 16.0),
              onTap: () {
                // Find an academic building and center the map on it
                final academic = allFacilities.firstWhere(
                      (facility) => facility.icon == Icons.school,
                  orElse: () => allFacilities.first,
                );
                _animatedMapMove(academic.location, 18.0);
                Navigator.pop(context); // Close drawer
              },
            ),
            ListTile(
              leading: const Icon(Icons.water_drop),
              title: const Text('Water Sources'),
              contentPadding: const EdgeInsets.symmetric(horizontal: 16.0),
              onTap: () {
                // Find a water source and center the map on it
                final waterSource = allFacilities.firstWhere(
                      (facility) => facility.icon == Icons.water_drop,
                  orElse: () => allFacilities.first,
                );
                _animatedMapMove(waterSource.location, 18.0);
                Navigator.pop(context); // Close drawer
              },
            ),
            const Divider(),
            if (!_isOfflineMapLoaded)
              ListTile(
                leading: const Icon(Icons.download),
                title: _isLoadingOfflineMap
                    ? const Row(
                  children: [
                    Text('Downloading map...'),
                    SizedBox(width: 10),
                    SizedBox(
                      width: 16,
                      height: 16,
                      child: CircularProgressIndicator(strokeWidth: 2),
                    ),
                  ],
                )
                    : const Text('Download Offline Map'),
                contentPadding: const EdgeInsets.symmetric(horizontal: 16.0),
                onTap: _isLoadingOfflineMap ? null : _loadOfflineMap,
              ),
          ],
        ),
      ),
      body: Stack(
        children: [
          // Main map view
          FlutterMap(
            mapController: _mapController,
            options: MapOptions(
              initialCenter: _rruCenter,
              initialZoom: _initialZoom,
              minZoom: 14.0,
              maxZoom: 21.0,
              cameraConstraint: CameraConstraint.contain(bounds: bounds),
              onTap: (_, __) {
                // Close info window when tapping on the map
                if (_showInfoWindow) {
                  setState(() {
                    _showInfoWindow = false;
                  });
                }
              },
            ),
            children: [
              // Tile layer
              TileLayer(
                urlTemplate: Theme.of(context).brightness == Brightness.dark
                    ? 'https://{s}.basemaps.cartocdn.com/dark_all/{z}/{x}/{y}{r}.png'
                    : 'https://tile.openstreetmap.org/{z}/{x}/{y}.png',
                subdomains: const ['a', 'b', 'c'],
                userAgentPackageName: 'com.example.app',
              ),

              // Marker cluster layer
              MarkerClusterLayerWidget(
                options: MarkerClusterLayerOptions(
                  maxClusterRadius: 45,
                  size: const Size(40, 40),
                  alignment: Alignment.center,
                  padding: const EdgeInsets.all(50),
                  maxZoom: 15,
                  markers: markersWithTap,
                  builder: (context, markers) {
                    return Container(
                      decoration: BoxDecoration(
                        shape: BoxShape.circle,
                        color: Colors.blue.withOpacity(0.7),
                      ),
                      child: Center(
                        child: Text(
                          '${markers.length}',
                          style: const TextStyle(color: Colors.white, fontSize: 14),
                        ),
                      ),
                    );
                  },
                ),
              ),
            ],
          ),

          // Info window when a marker is selected
          if (_showInfoWindow && _selectedFacility != null && _infoWindowPosition != null)
            Positioned(
              left: 0,
              right: 0,
              bottom: 16,
              child: Center(
                child: Container(
                  width: MediaQuery.of(context).size.width * 0.8,
                  padding: const EdgeInsets.all(16),
                  decoration: BoxDecoration(
                    color: Theme.of(context).cardColor,
                    borderRadius: BorderRadius.circular(12),
                    boxShadow: [
                      BoxShadow(
                        color: Colors.black.withOpacity(0.2),
                        blurRadius: 6,
                        offset: const Offset(0, 3),
                      ),
                    ],
                  ),
                  child: Column(
                    mainAxisSize: MainAxisSize.min,
                    children: [
                      Row(
                        children: [
                          Container(
                            padding: const EdgeInsets.all(8),
                            decoration: BoxDecoration(
                              color: _selectedFacility!.color,
                              shape: BoxShape.circle,
                            ),
                            child: Icon(
                              _selectedFacility!.icon,
                              color: Colors.white,
                              size: 24,
                            ),
                          ),
                          const SizedBox(width: 12),
                          Expanded(
                            child: Column(
                              crossAxisAlignment: CrossAxisAlignment.start,
                              children: [
                                Text(
                                  _selectedFacility!.shortName,
                                  style: const TextStyle(
                                    fontWeight: FontWeight.bold,
                                    fontSize: 18,
                                  ),
                                ),
                                const SizedBox(height: 4),
                                Text(
                                  _selectedFacility!.description ?? 'No additional information available',
                                  style: TextStyle(
                                    color: Theme.of(context).textTheme.bodySmall?.color,
                                  ),
                                ),
                              ],
                            ),
                          ),
                        ],
                      ),
                      const SizedBox(height: 12),
                      Row(
                        mainAxisAlignment: MainAxisAlignment.end,
                        children: [
                          TextButton(
                            onPressed: () {
                              setState(() {
                                _showInfoWindow = false;
                              });
                            },
                            child: const Text('Close'),
                          ),
                        ],
                      ),
                    ],
                  ),
                ),
              ),
            ),

          // Legend card with pin toggle
          Positioned(
            top: 16,
            right: 16,
            child: Card(
              shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.circular(12.0),
              ),
              elevation: 6,
              color: Theme.of(context).cardColor.withOpacity(0.9),
              child: Column(
                children: [
                  Padding(
                    padding: const EdgeInsets.all(12.0),
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Row(
                          mainAxisAlignment: MainAxisAlignment.spaceBetween,
                          children: [
                            const Text(
                              'Map Legend',
                              style: TextStyle(
                                fontWeight: FontWeight.bold,
                                fontSize: 16,
                              ),
                            ),
                            IconButton(
                              padding: EdgeInsets.zero,
                              constraints: const BoxConstraints(),
                              icon: Icon(
                                _isLegendPinned ? Icons.push_pin : Icons.push_pin_outlined,
                                size: 20,
                              ),
                              onPressed: () {
                                setState(() {
                                  _isLegendPinned = !_isLegendPinned;
                                });
                              },
                              tooltip: _isLegendPinned ? 'Unpin legend' : 'Pin legend',
                            ),
                          ],
                        ),
                        const Divider(height: 8),
                        const SizedBox(height: 4),
                        if (_isLegendPinned) ...[
                          _buildLegendItem(Colors.green, 'Food Area', Icons.restaurant),
                          const SizedBox(height: 8),
                          _buildLegendItem(Colors.blue, 'Water Source', Icons.water_drop),
                          const SizedBox(height: 8),
                          _buildLegendItem(Colors.grey, 'Washroom', Icons.wc),
                          const SizedBox(height: 8),
                          _buildLegendItem(Colors.red, 'Academic Building', Icons.school),
                          const SizedBox(height: 8),
                          _buildLegendItem(Colors.purple, 'Others', Icons.location_on),
                          const SizedBox(height: 8),
                          _buildLegendItem(Colors.blue, 'Your Location', Icons.my_location),
                        ],
                      ],
                    ),
                  ),
                ],
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

  Widget _buildFacilityMarker(Color color, IconData icon) {
    return Container(
      width: 30,
      height: 30,
      decoration: BoxDecoration(
        color: color,
        shape: BoxShape.circle,
        boxShadow: [
          BoxShadow(
            color: Colors.black26,
            spreadRadius: 2,
            blurRadius: 5,
          ),
        ],
      ),
      child: Icon(icon, color: Colors.white, size: 16),
    );
  }
}