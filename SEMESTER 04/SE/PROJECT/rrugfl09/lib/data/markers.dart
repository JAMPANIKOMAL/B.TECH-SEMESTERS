import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';

class Facility {
  final String name;
  final String description;
  final LatLng location;
  final Color color;
  final IconData icon;
  final bool showLabel;

  Facility({
    required this.name,
    required this.description,
    required this.location,
    required this.color,
    required this.icon,
    this.showLabel = false,
  });
}

// Define your facility list
final List<Facility> facilities = [
  Facility(
    name: 'Washroom 1',
    description: 'Public restroom near admin block.',
    location: LatLng(23.1540, 72.8860),
    color: Colors.grey,
    icon: Icons.wc,
  ),
  Facility(
    name: 'Water Source 1',
    description: 'Filtered drinking water.',
    location: LatLng(23.1520, 72.8840),
    color: Colors.blue,
    icon: Icons.water_drop,
  ),
  Facility(
    name: 'Food Stall 1',
    description: 'Snacks and beverages available here.',
    location: LatLng(23.1550, 72.8870),
    color: Colors.green,
    icon: Icons.restaurant,
  ),
  Facility(
    name: 'Academic Block A',
    description: 'Engineering department building.',
    location: LatLng(23.1535, 72.8855),
    color: Colors.red,
    icon: Icons.school,
    showLabel: true,
  ),
  Facility(
    name: 'Miscellaneous Point',
    description: 'Other facility or landmark.',
    location: LatLng(23.1510, 72.8890),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
];

// Generate markers from facilities
List<Marker> buildFacilityMarkers(Function(Facility) onTap, Map<String, bool> categoryFilter) {
  return facilities.where((facility) {
    if (facility.icon == Icons.restaurant && !(categoryFilter['Food Stalls'] ?? true)) return false;
    if (facility.icon == Icons.wc && !(categoryFilter['Restrooms'] ?? true)) return false;
    if (facility.icon == Icons.school && !(categoryFilter['Academic Buildings'] ?? true)) return false;
    if (facility.icon == Icons.water_drop && !(categoryFilter['Water Sources'] ?? true)) return false;
    if (facility.icon == Icons.place && !(categoryFilter['Miscellaneous'] ?? true)) return false;
    return true;
  }).map((facility) {
    return Marker(
      width: 160.0,
      height: 50.0,
      point: facility.location,
      child: GestureDetector(
        onTap: () => onTap(facility),
        child: Container(
          constraints: const BoxConstraints(maxWidth: 160),
          child: Row(
            children: [
              Container(
                decoration: BoxDecoration(
                  color: facility.color,
                  shape: BoxShape.circle,
                  boxShadow: const [
                    BoxShadow(
                      color: Colors.black26,
                      spreadRadius: 2,
                      blurRadius: 5,
                    ),
                  ],
                ),
                padding: const EdgeInsets.all(6),
                child: Icon(
                  facility.icon,
                  color: Colors.white,
                  size: 20,
                ),
              ),
              if (facility.showLabel)
                Flexible(
                  child: Container(
                    margin: const EdgeInsets.only(left: 6),
                    padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
                    decoration: BoxDecoration(
                      color: Colors.white,
                      borderRadius: BorderRadius.circular(6),
                      boxShadow: const [
                        BoxShadow(
                          color: Colors.black26,
                          blurRadius: 4,
                        ),
                      ],
                    ),
                    child: Text(
                      facility.name,
                      overflow: TextOverflow.ellipsis,
                      softWrap: false,
                      style: const TextStyle(fontSize: 12, color: Colors.black),
                    ),
                  ),
                ),
            ],
          ),
        ),
      ),
    );
  }).toList();
}
