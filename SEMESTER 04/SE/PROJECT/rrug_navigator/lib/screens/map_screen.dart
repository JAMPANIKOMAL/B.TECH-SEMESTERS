// ignore_for_file: use_build_context_synchronously, curly_braces_in_flow_control_structures, deprecated_member_use

import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';
import 'package:location/location.dart' as loc;

import '../data/markers.dart';
import 'package:url_launcher/url_launcher.dart';

import '../widgets/facility_card.dart';
import '../widgets/legend_card.dart';
import '../utils/theme_manager.dart';
import 'contact_page.dart';

import 'dart:convert';
import 'package:http/http.dart' as http;

class MapScreen extends StatefulWidget {
  const MapScreen({super.key});

  @override
  State<MapScreen> createState() => _MapScreenState();
}

class _MapScreenState extends State<MapScreen> with TickerProviderStateMixin {
  final MapController _mapController = MapController();


  // Future<LatLng?> _getNearestRoutablePoint(LatLng point) async {
  //   const String apiKey =
  //       '5b3ce3597851110001cf6248646274dcd2cc4a06ad26c6522df8ce86'; // replace with your actual key
  //   final Uri uri = Uri.parse(
  //     'https://api.openrouteservice.org/nearest?api_key=$apiKey&point.lon=${point.longitude}&point.lat=${point.latitude}',
  //   );
  //
  //   try {
  //     final response = await http.get(uri);
  //
  //     if (response.statusCode == 200) {
  //       final data = jsonDecode(response.body);
  //       final coords = data['coordinates'];
  //       if (coords != null && coords.length >= 2) {
  //         return LatLng(coords[1], coords[0]); // lat, lon
  //       }
  //     } else {
  //       debugPrint("Nearest API failed: ${response.body}");
  //     }
  //   } catch (e) {
  //     debugPrint("Nearest point error: $e");
  //   }
  //
  //   return null; // fallback if snapping fails
  // }

  double _mapRotation = 0.0;
  Facility? _selectedFacility;
  final TextEditingController _searchController = TextEditingController();
  String _searchQuery = "";

  final ValueNotifier<bool> _legendVisible = ValueNotifier(true);
  loc.Location location = loc.Location();
  loc.LocationData? _currentLocation;
  final LatLng _rruCenter = LatLng(23.1535, 72.8850);
  final double _initialZoom = 17.0;
  final double _currentLocationZoom = 19.0;
  double _currentZoomLevel = 17.0;
  bool _locationPermissionGranted = false;
  bool _isLocating = false;
  final Map<String, bool> _categoryFilter = {
    'Food Stalls': true,
    'Restrooms': true,
    'Academic Buildings': true,
    'Water Sources': true,
    'Miscellaneous': true,
  };

  List<LatLng> _routePoints = [];

  Future<void> _fetchAndDrawRoute(LatLng start, LatLng end) async {
    const String apiKey =
        '5b3ce3597851110001cf6248646274dcd2cc4a06ad26c6522df8ce86'; // Replace with your actual key
    const String profile = 'foot-walking'; // Change to 'driving-car' if needed

    final Uri uri = Uri.parse(
      'https://api.openrouteservice.org/v2/directions/$profile?api_key=$apiKey&snap_waypoints=true',
    );

    final body = jsonEncode({
      "coordinates": [
        [start.longitude, start.latitude],
        [end.longitude, end.latitude],
      ],
    });

    try {
      final response = await http.post(
        uri,
        headers: {'Content-Type': 'application/json'},
        body: body,
      );

      if (response.statusCode == 200) {
        final data = jsonDecode(response.body);
        final geometry = data['features'][0]['geometry']['coordinates'];
        setState(() {
          _routePoints =
              geometry
                  .map<LatLng>((point) => LatLng(point[1], point[0]))
                  .toList();
        });
      } else {
        debugPrint("ORS Error: ${response.statusCode} - ${response.body}");
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(
            content: Text(
              "In-app navigation is currently unavailable. Use Google Maps instead.",
            ),
            duration: Duration(seconds: 4),
          ),
        );
      }
    } catch (e) {
      debugPrint("Route fetch error: $e");
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text(
            "In-app navigation is currently unavailable. Use Google Maps instead.",
          ),
          duration: Duration(seconds: 4),
        ),
      );
    }
  }

  Marker? _currentLocationMarker;

  @override
  void initState() {
    super.initState();
    _requestLocationPermission();
    _mapController.mapEventStream.listen((event) {
      print('Zoom updated: ${_mapController.camera.zoom}');
      if (event is MapEventMove || event is MapEventRotate) {
        setState(() {
          _mapRotation = _mapController.camera.rotation;
          _currentZoomLevel = _mapController.camera.zoom;
        });
      }
    });



    WidgetsBinding.instance.addPostFrameCallback((_) {
      _mapController.moveAndRotate(_rruCenter, _initialZoom, 0);
    });
  }

  Future<void> _requestLocationPermission() async {
    bool serviceEnabled = await location.serviceEnabled();
    if (!serviceEnabled) {
      serviceEnabled = await location.requestService();
      if (!serviceEnabled) return;
    }

    var permissionGranted = await location.hasPermission();
    if (permissionGranted == loc.PermissionStatus.denied) {
      permissionGranted = await location.requestPermission();
      if (permissionGranted != loc.PermissionStatus.granted) return;
    }

    setState(() => _locationPermissionGranted = true);
    _getCurrentLocation();
  }

  Future<void> _getCurrentLocation() async {
    if (_isLocating) return;
    setState(() => _isLocating = true);
    try {
      final loc.LocationData locationData = await location.getLocation();
      if (locationData.latitude == null || locationData.longitude == null) {
        throw Exception("Location data is null");
      }

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
                ),
              ],
            ),
            child: const Icon(Icons.my_location, size: 24, color: Colors.white),
          ),
        );
        _isLocating = false;
      });
    } catch (e) {
      setState(() => _isLocating = false);
      ScaffoldMessenger.of(
        context,
      ).showSnackBar(SnackBar(content: Text('Failed to get location: $e')));
    }
  }

  void _animatedRotateToNorth() {
    final rotationTween = Tween<double>(
      begin: _mapController.camera.rotation,
      end: 0.0,
    );
    final controller = AnimationController(
      duration: const Duration(milliseconds: 500),
      vsync: this,
    );
    final animation = CurvedAnimation(
      parent: controller,
      curve: Curves.easeOut,
    );

    controller.addListener(() {
      _mapController.rotate(rotationTween.evaluate(animation));
    });

    animation.addStatusListener((status) {
      if (status == AnimationStatus.completed) controller.dispose();
    });

    controller.forward();
  }

  void _goToCurrentLocation() async {
    if (_currentLocation != null && _locationPermissionGranted) {
      final targetLatLng = LatLng(
        _currentLocation!.latitude!,
        _currentLocation!.longitude!,
      );
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
        final targetLatLng = LatLng(
          _currentLocation!.latitude!,
          _currentLocation!.longitude!,
        );
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
            content: Text(
              'Unable to find your location. Please check permissions.',
            ),
            duration: Duration(seconds: 3),
          ),
        );
      }
    }
  }

  Future<void> _openInGoogleMaps(LatLng dest) async {
    final url = Uri.parse(
      "https://www.google.com/maps/dir/?api=1&destination=${dest.latitude},${dest.longitude}&travelmode=walking",
    );
    if (!await launchUrl(url, mode: LaunchMode.externalApplication)) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text("Could not open Google Maps")),
      );
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text("Could not open Google Maps")),
      );
    }
  }

  void _startInAppNavigation(LatLng destination) {
    if (_currentLocation == null) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text("Current location not available")),
      );
      return;
    }

    final LatLng start = LatLng(
      _currentLocation!.latitude!,
      _currentLocation!.longitude!,
    );
    _fetchAndDrawRoute(start, destination);
  }

  void _animatedMapMove(LatLng destLocation, double destZoom) {
    final latTween = Tween<double>(
      begin: _mapController.camera.center.latitude,
      end: destLocation.latitude,
    );
    final lngTween = Tween<double>(
      begin: _mapController.camera.center.longitude,
      end: destLocation.longitude,
    );
    final zoomTween = Tween<double>(
      begin: _mapController.camera.zoom,
      end: destZoom,
    );

    final controller = AnimationController(
      duration: const Duration(milliseconds: 500),
      vsync: this,
    );
    final animation = CurvedAnimation(
      parent: controller,
      curve: Curves.fastOutSlowIn,
    );

    controller.addListener(() {
      _mapController.moveAndRotate(
        LatLng(latTween.evaluate(animation), lngTween.evaluate(animation)),
        zoomTween.evaluate(animation),
        0,
      );
    });

    animation.addStatusListener((status) {
      if (status == AnimationStatus.completed) controller.dispose();
    });

    controller.forward();
  }

  @override
  Widget build(BuildContext context) {
    final bounds = LatLngBounds(
      LatLng(23.150039, 72.878816),
      LatLng(23.156697, 72.891541),
    );

    return Scaffold(
      appBar: AppBar(
        titleSpacing: 0,
        title: Container(
          height: 44,
          margin: const EdgeInsets.only(right: 8.0),
          child: TextField(
            controller: _searchController,
            decoration: InputDecoration(
              hintText: 'Search facilities...',
              hintStyle: TextStyle(color: Theme.of(context).hintColor),
              prefixIcon: const Icon(Icons.search, color: Colors.grey),
              contentPadding: const EdgeInsets.symmetric(vertical: 0, horizontal: 16),
              filled: true,
              fillColor: Theme.of(context).cardColor.withOpacity(0.9),
              border: OutlineInputBorder(
                borderRadius: BorderRadius.circular(30),
                borderSide: BorderSide.none,
              ),
            ),
            style: const TextStyle(fontSize: 15),
            onChanged: (query) {
              setState(() {
                _searchQuery = query.toLowerCase();
                final match = facilities.firstWhere(
                      (f) => f.name.toLowerCase().contains(_searchQuery),
                  orElse: () => Facility(
                    name: '',
                    description: '',
                    location: _rruCenter,
                    icon: Icons.help,
                    color: Colors.transparent,
                  ),
                );
                if (match.name.isNotEmpty) {
                  _animatedMapMove(match.location, 19);
                }
              });
            },
          ),
        ),
//title: const Text('RRUG Facility Locator'),
        actions: [
          IconButton(
            onPressed: ThemeManager.toggleTheme,
            icon: ValueListenableBuilder(
              valueListenable: ThemeManager.currentTheme,
              builder:
                  (context, value, _) => Icon(
                    value == ThemeMode.light
                        ? Icons.light_mode
                        : Icons.dark_mode,
                  ),
            ),
          ),
        ],
      ),
      drawer: _buildDrawer(),
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
              interactionOptions: const InteractionOptions(
                flags:
                    InteractiveFlag.pinchZoom |
                    InteractiveFlag.drag |
                    InteractiveFlag.doubleTapZoom,
              ),
            ),

            children: [
              TileLayer(
                urlTemplate:
                    Theme.of(context).brightness == Brightness.dark
                        ? 'https://{s}.basemaps.cartocdn.com/dark_all/{z}/{x}/{y}{r}.png'
                        : 'https://tile.openstreetmap.org/{z}/{x}/{y}.png',
                subdomains: const ['a', 'b', 'c'],
                userAgentPackageName: 'com.example.app',
              ),
              MarkerLayer(
                markers: [
                  if (_currentLocationMarker != null) _currentLocationMarker!,
                  ...buildFacilityMarkers(
                        (facility) => setState(() => _selectedFacility = facility),
                    _categoryFilter,
                    _currentZoomLevel, // 👈 zoom passed here
                  ),
                ],
              ),


              PolylineLayer(
                polylines: [
                  if (_routePoints.isNotEmpty)
                    Polyline(
                      points: _routePoints,
                      color: Colors.orange,
                      strokeWidth: 5.0,
                    ),
                ],
              ),
            ],
          ),
          if (_selectedFacility != null)
            FacilityCard(
              facility: _selectedFacility!,
              onClose:
                  () => setState(() {
                    _selectedFacility = null;
                    _routePoints.clear();
                  }),

              actions: [
                ElevatedButton.icon(
                  onPressed: () async {
                    await _getCurrentLocation();
                    if (_currentLocation != null) {
                      _startInAppNavigation(_selectedFacility!.location);
                    } else {
                      ScaffoldMessenger.of(context).showSnackBar(
                        const SnackBar(
                          content: Text(
                            "Location not available. Grant permission or enable GPS.",
                          ),
                        ),
                      );
                    }
                  },
                  icon: const Icon(Icons.navigation),
                  label: const Text("Navigate"),
                  style: ElevatedButton.styleFrom(backgroundColor: Colors.blue),
                ),
                const SizedBox(width: 8),
                ElevatedButton.icon(
                  onPressed: () async {
                    await _getCurrentLocation();
                    if (_currentLocation != null) {
                      _openInGoogleMaps(_selectedFacility!.location);
                    } else {
                      ScaffoldMessenger.of(context).showSnackBar(
                        const SnackBar(
                          content: Text(
                            "Cannot open Google Maps without location.",
                          ),
                        ),
                      );
                    }
                  },
                  icon: const Icon(Icons.map_outlined),
                  label: const Text("Google Maps"),
                  style: ElevatedButton.styleFrom(
                    backgroundColor: Colors.green,
                  ),
                ),
              ],
            ),

          Positioned(
            top: 16,
            right: 16,
            child: ValueListenableBuilder<bool>(
              valueListenable: _legendVisible,
              builder:
                  (context, visible, _) =>
                      visible
                          ? LegendCard(
                            onClose: () => _legendVisible.value = false,
                          )
                          : IconButton(
                            icon: const Icon(Icons.push_pin_outlined),
                            tooltip: 'Show Legend',
                            onPressed: () => _legendVisible.value = true,
                          ),
            ),
          ),
        ],
      ),
      floatingActionButton: _buildFABs(),
    );
  }

  Widget _buildFABs() {
    return Column(
      mainAxisAlignment: MainAxisAlignment.end,
      children: [
        FloatingActionButton(
          onPressed: _animatedRotateToNorth,
          tooltip: 'Reset North',
          heroTag: 'compass',
          backgroundColor: Colors.orange,
          child: Transform.rotate(
            angle: -_mapRotation * (3.1415926535 / 180),
            child: const Icon(Icons.explore, color: Colors.white),
          ),
        ),
        const SizedBox(height: 10),
        FloatingActionButton(
          onPressed: _goToCurrentLocation,
          tooltip: 'Go to Current Location',
          heroTag: 'location',
          backgroundColor: Colors.blue,
          child:
              _isLocating
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
            if (currentZoom < 21.0)
              _mapController.moveAndRotate(
                _mapController.camera.center,
                currentZoom + 1.0,
                0,
              );
          },
          tooltip: 'Zoom In',
          heroTag: 'zoomIn',
          child: const Icon(Icons.add),
        ),
        const SizedBox(height: 10),
        FloatingActionButton(
          onPressed: () {
            final currentZoom = _mapController.camera.zoom;
            if (currentZoom > 14.0)
              _mapController.moveAndRotate(
                _mapController.camera.center,
                currentZoom - 1.0,
                0,
              );
          },
          tooltip: 'Zoom Out',
          heroTag: 'zoomOut',
          child: const Icon(Icons.remove),
        ),
      ],
    );
  }

  Widget _buildDrawer() {
    return SizedBox(
      width: 250,
      child: Drawer(
        child: ListView(
          padding: EdgeInsets.zero,
          children: [
            Container(
              height: 100,
              padding: const EdgeInsets.all(16),
              color: Colors.blue,
              alignment: Alignment.centerLeft,
              child: const Text(
                'Filter Facilities',
                style: TextStyle(color: Colors.white, fontSize: 20),
              ),
            ),
            ..._categoryFilter.keys.map((category) {
              IconData icon;
              switch (category) {
                case 'Food Stalls':
                  icon = Icons.restaurant;
                  break;
                case 'Restrooms':
                  icon = Icons.wc;
                  break;
                case 'Academic Buildings':
                  icon = Icons.school;
                  break;
                case 'Water Sources':
                  icon = Icons.water_drop;
                  break;
                default:
                  icon = Icons.place;
              }
              return CheckboxListTile(
                title: Text(category),
                secondary: Icon(icon),
                value: _categoryFilter[category],
                onChanged:
                    (value) =>
                        setState(() => _categoryFilter[category] = value!),
              );
            }),
            const Divider(),
            Padding(
              padding: const EdgeInsets.all(8.0),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text(
                    'Tip: Use this menu to show or hide types of facilities on the map.',
                    style: TextStyle(fontSize: 13, color: Colors.grey[600]),
                  ),
                  const SizedBox(height: 8),
                  const Divider(),
                ],
              ),
            ),
            ListTile(
              leading: const Icon(Icons.contact_page),
              title: const Text('Contact'),
              onTap:
                  () => Navigator.push(
                    context,
                    MaterialPageRoute(builder: (_) => const ContactPage()),
                  ),
            ),
          ],
        ),
      ),
    );
  }
}
