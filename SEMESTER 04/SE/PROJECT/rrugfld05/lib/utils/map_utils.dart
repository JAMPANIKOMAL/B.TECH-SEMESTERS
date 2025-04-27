import 'package:flutter/material.dart';

class MapUtils {
  /// Gets the marker color based on facility type
  static Color getMarkerColor(String type) {
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

  /// Returns icon for the facility type
  static IconData getMarkerIcon(String type) {
    switch (type) {
      case 'food':
        return Icons.restaurant;
      case 'water':
        return Icons.water_drop;
      case 'washroom':
        return Icons.wc;
      case 'academic':
        return Icons.school;
      default:
        return Icons.location_on;
    }
  }
}