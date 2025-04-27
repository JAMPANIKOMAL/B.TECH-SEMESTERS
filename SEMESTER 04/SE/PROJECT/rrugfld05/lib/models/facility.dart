import 'package:latlong2/latlong.dart';

/// Represents a facility on the map
class Facility {
  final String id;
  final String name;
  final String type; // food, water, washroom, academic, etc.
  final LatLng location;
  final String? description;

  const Facility({
    required this.id,
    required this.name,
    required this.type,
    required this.location,
    this.description,
  });

  // Factory constructor to create a Facility from JSON
  factory Facility.fromJson(Map<String, dynamic> json) {
    return Facility(
      id: json['id'],
      name: json['name'],
      type: json['type'],
      location: LatLng(json['latitude'], json['longitude']),
      description: json['description'],
    );
  }

  // Convert to JSON
  Map<String, dynamic> toJson() {
    return {
      'id': id,
      'name': name,
      'type': type,
      'latitude': location.latitude,
      'longitude': location.longitude,
      'description': description,
    };
  }
}