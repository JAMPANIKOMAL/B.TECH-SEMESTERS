// ignore_for_file: unused_import, avoid_print

import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';
import 'dart:math';

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
  // Facility(
  //   name: 'Academic Block A',
  //   description: 'Engineering department building.',
  //   location: LatLng(23.1535, 72.8855),
  //   color: Colors.red,
  //   icon: Icons.school,
  //   showLabel: true,
  // ),

  Facility(
    name: 'SISPP',
    description: 'School of Internal Security and Police Practices',
    location: LatLng(23.15325, 72.88511),
    color: Colors.red,
    icon: Icons.school,
    showLabel: true,
  ),
  Facility(
    name: 'Parking Lot',
    description: 'Parking Lot',
    location: LatLng(23.15414, 72.88328),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Main Gate',
    description: 'Main Gate',
    location: LatLng(23.15500, 72.88458),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Footbal Ground',
    description: 'Footbal Ground',
    location: LatLng(23.15561, 72.88592),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Helipad',
    description: 'Helipad',
    location: LatLng(23.15217, 72.88211),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Lake view point',
    description: 'Lake view point',
    location: LatLng(23.15300, 72.88492),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Handball court',
    description: 'Handball court',
    location: LatLng(23.15406, 72.88561),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Vollyball court',
    description: 'Vollyball court',
    location: LatLng(23.15420, 72.88683),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Gym',
    description: 'Gym',
    location: LatLng(23.15181, 72.88356),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Open Gym',
    description: 'Open Gym',
    location: LatLng(23.15458, 72.88689),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Cricket Ground',
    description: 'Cricket Ground',
    location: LatLng(23.15542, 72.88403),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Water Tank',
    description: 'Water Tank',
    location: LatLng(23.15150, 72.88317),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Open air theater',
    description: 'Open air theater',
    location: LatLng(23.15150, 72.88317),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Microwave Tower',
    description: 'Microwave Tower',
    location: LatLng(23.15150, 72.88497),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Guest Room-1',
    description: 'Guest Room-1',
    location: LatLng(23.15253, 72.88431),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Guest Room-2',
    description: 'Guest Room-2',
    location: LatLng(23.15122, 72.88131),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Auditorium',
    description: 'Auditorium',
    location: LatLng(23.15428, 72.88472),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),
  Facility(
    name: 'Admin',
    description: 'Admin',
    location: LatLng(23.15397, 72.88511),
    color: Colors.deepPurple,
    icon: Icons.place,
    showLabel: true,
  ),

  Facility(
    name: 'SBSFI',
    description: 'School of Behavioural Sciences and Forensic Investigations',
    location: LatLng(23.15350, 72.88511),
    color: Colors.red,
    icon: Icons.school,
    showLabel: true,
  ),
  Facility(
    name: 'SASET',
    description: 'School of Applied Sciences and Engineering Technology',
    location: LatLng(23.15350, 72.88547),
    color: Colors.red,
    icon: Icons.school,
    showLabel: true,
  ),
  Facility(
    name: 'SBSFI',
    description: 'School of Behavioural Sciences and Forensic Investigations',
    location: LatLng(23.15353, 72.88581),
    color: Colors.red,
    icon: Icons.school,
    showLabel: true,
  ),
  Facility(
    name: 'SCLML',
    description: 'School of Criminal Law and Military Law',
    location: LatLng(23.15353, 72.88625),
    color: Colors.red,
    icon: Icons.school,
    showLabel: true,
  ),
  Facility(
    name: 'SITAICS',
    description:
        'School of Information Technology, Artificial Intelligence, and Cyber Security',
    location: LatLng(23.15356, 72.88669),
    color: Colors.red,
    icon: Icons.school,
    showLabel: true,
  ),
  Facility(
    name: 'BCORE',
    description: 'Bharat Centre for Operational Research and Engineering',
    location: LatLng(23.15367, 72.88764),
    color: Colors.red,
    icon: Icons.school,
    showLabel: true,
  ),
  Facility(
    name: 'SISDSS',
    description: 'School of Internal Security, Defence, and Strategic Studies',
    location: LatLng(23.15181, 72.88386),
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
List<Marker> buildFacilityMarkers(
    Function(Facility) onTap,
    Map<String, bool> categoryFilter,
    double zoomLevel,
    ) {
  final filtered = facilities.where((facility) {
    // Category filtering
    if (facility.icon == Icons.restaurant && !(categoryFilter['Food Stalls'] ?? true)) return false;
    if (facility.icon == Icons.wc && !(categoryFilter['Restrooms'] ?? true)) return false;
    if (facility.icon == Icons.school && !(categoryFilter['Academic Buildings'] ?? true)) return false;
    if (facility.icon == Icons.water_drop && !(categoryFilter['Water Sources'] ?? true)) return false;
    if (facility.icon == Icons.place && !(categoryFilter['Miscellaneous'] ?? true)) return false;

    // Dynamic hash-based zoom filtering
    final hash = facility.name.hashCode.abs() % 10;
    if (zoomLevel >= 18.0) {
      // show all markers
      return true;
    }

// Zoomed out — filter some markers
    return hash <= 4; // show only ~50% when zoomed out


    return true;
  }).toList();

  print('Zoom level: $zoomLevel, displaying ${filtered.length} markers');

  return filtered.map((facility) {
    return Marker(
      width: 160.0,
      height: 50.0,
      point: facility.location,
      child: GestureDetector(
        onTap: () => onTap(facility),
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
    );
  }).toList();
}
