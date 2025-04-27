import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';

// Example locations
final List<Marker> facilityMarkers = [

  // Washroom Marker
  Marker(
    width: 40.0,
    height: 40.0,
    point: LatLng(23.1540, 72.8860), // Example washroom location
    child: _buildFacilityMarker(Colors.grey, Icons.wc),
  ),

  // Water Source Marker
  Marker(
    width: 40.0,
    height: 40.0,
    point: LatLng(23.1520, 72.8840), // Example water source location
    child: _buildFacilityMarker(Colors.blue, Icons.water_drop),
  ),

  // Food Area Marker
  Marker(
    width: 40.0,
    height: 40.0,
    point: LatLng(23.1550, 72.8870), // Example food stall location
    child: _buildFacilityMarker(Colors.green, Icons.restaurant),
  ),

  // Academic Building Marker
  Marker(
    width: 40.0,
    height: 40.0,
    point: LatLng(23.1535, 72.8855), // Example academic building location
    child: _buildFacilityMarker(Colors.red, Icons.school),
  ),
];

// Helper widget for building markers
Widget _buildFacilityMarker(Color color, IconData icon) {
  return Container(
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
    child: Icon(
      icon,
      color: Colors.white,
      size: 20,
    ),
  );
}
