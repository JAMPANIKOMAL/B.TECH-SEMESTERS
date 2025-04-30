
import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';
import 'package:url_launcher/url_launcher.dart';
import 'package:location/location.dart' as loc;

import '../data/markers.dart';

class FacilityCard extends StatelessWidget {
  final Facility facility;
  final VoidCallback onClose;
  final MapController mapController;
  final loc.Location location;
  final LatLng? currentLocation;
  final Function(List<LatLng>) updateNavigationPath;
  final Function(loc.LocationData) updateCurrentLocation;

  const FacilityCard({
    super.key,
    required this.facility,
    required this.onClose,
    required this.mapController,
    required this.location,
    required this.currentLocation,
    required this.updateNavigationPath,
    required this.updateCurrentLocation,
  });

  void _navigate(BuildContext context) async {
    try {
      final locData = await location.getLocation();
      if (locData.latitude != null && locData.longitude != null) {
        final from = LatLng(locData.latitude!, locData.longitude!);
        final to = facility.location;
        updateCurrentLocation(locData);
        updateNavigationPath([from, to]);

        final bounds = LatLngBounds(from, to);
        mapController.fitCamera(CameraFit.bounds(
          bounds: bounds,
          padding: const EdgeInsets.all(50),
        ));

        final distance = Distance().as(LengthUnit.Meter, from, to);
        final distanceInKm = (distance / 1000).toStringAsFixed(2);

        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('Distance: $distanceInKm km')),
        );
      } else {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(content: Text("Could not get your current location")),
        );
      }
    } catch (e) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text("Error: $e")),
      );
    }
  }

  void _openInGoogleMaps(BuildContext context) async {
    final destination = facility.location;
    final url = Uri.parse("https://www.google.com/maps/dir/?api=1&destination=${destination.latitude},${destination.longitude}&travelmode=walking");
    if (await canLaunchUrl(url)) {
      await launchUrl(url, mode: LaunchMode.externalApplication);
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text("Could not open Google Maps")),
      );
    }
  }

  void _clearRoute() {
    updateNavigationPath([]);
  }

  @override
  Widget build(BuildContext context) {
    return Positioned(
      bottom: 80,
      left: 40,
      right: 75,
      child: Card(
        elevation: 8,
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(12),
        ),
        color: Theme.of(context).cardColor.withOpacity(0.95),
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Row(
            children: [
              Icon(facility.icon, color: facility.color),
              const SizedBox(width: 12),
              Expanded(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Text(
                      facility.name,
                      style: const TextStyle(
                        fontWeight: FontWeight.bold,
                        fontSize: 16,
                      ),
                    ),
                    const SizedBox(height: 4),
                    Text(
                      facility.description,
                      style: const TextStyle(fontSize: 14),
                    ),
                    const SizedBox(height: 8),
                    Wrap(
                      spacing: 8,
                      children: [
                        ElevatedButton.icon(
                          onPressed: () => _navigate(context),
                          icon: const Icon(Icons.navigation),
                          label: const Text("Navigate"),
                          style: ElevatedButton.styleFrom(backgroundColor: Colors.blue),
                        ),
                        ElevatedButton.icon(
                          onPressed: () => _openInGoogleMaps(context),
                          icon: const Icon(Icons.map_outlined),
                          label: const Text("Google Maps"),
                          style: ElevatedButton.styleFrom(backgroundColor: Colors.green),
                        ),
                        ElevatedButton.icon(
                          onPressed: _clearRoute,
                          icon: const Icon(Icons.clear),
                          label: const Text("Clear Route"),
                          style: ElevatedButton.styleFrom(backgroundColor: Colors.red),
                        ),
                      ],
                    ),
                  ],
                ),
              ),
              IconButton(
                icon: const Icon(Icons.close),
                onPressed: onClose,
              ),
            ],
          ),
        ),
      ),
    );
  }
}
