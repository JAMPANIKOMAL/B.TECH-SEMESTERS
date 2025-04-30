import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';

class Facility {
  final LatLng location;
  final Color color;
  final IconData icon;
  final String shortName;
  final String description;
  final void Function(Facility)? onTap;

  Facility({
    required this.location,
    required this.color,
    required this.icon,
    this.shortName = "",
    this.description = "",
    this.onTap,
  });
}

final List<Facility> allFacilities = [
  Facility(
    location: LatLng(23.1540, 72.8860),
    color: Colors.grey,
    icon: Icons.wc,
    shortName: "Washroom",
    description: "Main campus washroom facility",
  ),
  Facility(
    location: LatLng(23.1520, 72.8840),
    color: Colors.blue,
    icon: Icons.water_drop,
    shortName: "Water Point",
    description: "Clean drinking water available here",
  ),
  Facility(
    location: LatLng(23.1550, 72.8870),
    color: Colors.green,
    icon: Icons.restaurant,
    shortName: "Cafeteria",
    description: "Main campus cafeteria serving breakfast, lunch and dinner",
  ),
  Facility(
    location: LatLng(23.1535, 72.8855),
    color: Colors.red,
    icon: Icons.school,
    shortName: "Main Academic",
    description: "Main academic building hosting classrooms and laboratories",
  ),
  Facility(
    location: LatLng(23.15325, 72.88511),
    color: Colors.red,
    icon: Icons.school,
    shortName: "SISPP",
    description: "School of International Studies, Policy & Practice",
  ),
  Facility(
    location: LatLng(23.1535, 72.88511),
    color: Colors.red,
    icon: Icons.school,
    shortName: "SBSFI",
    description: "School of Business Studies & Financial Innovation",
  ),
  Facility(
    location: LatLng(23.1535, 72.88547),
    color: Colors.red,
    icon: Icons.school,
    shortName: "SASET",
    description: "School of Applied Sciences & Emerging Technologies",
  ),
  Facility(
    location: LatLng(23.15353, 72.88581),
    color: Colors.red,
    icon: Icons.school,
    shortName: "SBSFI 2",
    description: "School of Business Studies & Financial Innovation - Second Building",
  ),
  Facility(
    location: LatLng(23.15353, 72.88625),
    color: Colors.red,
    icon: Icons.school,
    shortName: "SCLML",
    description: "School of Creative Learning & Media Literacy",
  ),
  Facility(
    location: LatLng(23.15356, 72.88669),
    color: Colors.red,
    icon: Icons.school,
    shortName: "SITAICS",
    description: "School of Information Technology, AI & Cybersecurity",
  ),
  Facility(
    location: LatLng(23.15367, 72.88764),
    color: Colors.red,
    icon: Icons.school,
    shortName: "BCORE",
    description: "Building for Collaborative Research",
  ),
  Facility(
    location: LatLng(23.15181, 72.88386),
    color: Colors.red,
    icon: Icons.school,
    shortName: "SISDSS",
    description: "School of Interdisciplinary Studies & Data Science",
  ),
  Facility(
    location: LatLng(23.15414, 72.88328),
    color: Colors.purple,
    icon: Icons.local_parking,
    shortName: "Parking",
    description: "Main parking area for vehicles",
  ),
  Facility(
    location: LatLng(23.15597, 72.88458),
    color: Colors.purple,
    icon: Icons.door_front_door,
    shortName: "Main Gate",
    description: "Main entrance to the campus",
  ),
  Facility(
    location: LatLng(23.15561, 72.88592),
    color: Colors.green,
    icon: Icons.sports_soccer,
    shortName: "Football",
    description: "Football ground",
  ),
  Facility(
    location: LatLng(23.15217, 72.88100),
    color: Colors.purple,
    icon: Icons.flight_takeoff,
    shortName: "Helipad",
    description: "Campus helipad for emergency services",
  ),
  Facility(
    location: LatLng(23.15300, 72.88492),
    color: Colors.blue,
    icon: Icons.water,
    shortName: "Lake View",
    description: "Scenic lake view point",
  ),
  Facility(
    location: LatLng(23.15350, 72.88672),
    color: Colors.green,
    icon: Icons.sports_handball,
    shortName: "Handball",
    description: "Handball court",
  ),
  Facility(
    location: LatLng(23.15419, 72.88794),
    color: Colors.green,
    icon: Icons.sports_volleyball,
    shortName: "Volleyball",
    description: "Volleyball court",
  ),
  Facility(
    location: LatLng(23.15181, 72.88356),
    color: Colors.green,
    icon: Icons.fitness_center,
    shortName: "Gym",
    description: "Indoor fitness center",
  ),
  Facility(
    location: LatLng(23.15458, 72.88799),
    color: Colors.green,
    icon: Icons.fitness_center,
    shortName: "Open Gym",
    description: "Outdoor fitness equipment area",
  ),
  Facility(
    location: LatLng(23.15542, 72.88403),
    color: Colors.green,
    icon: Icons.sports_cricket,
    shortName: "Cricket",
    description: "Cricket field",
  ),
  Facility(
    location: LatLng(23.15150, 72.88317),
    color: Colors.blue,
    icon: Icons.water_drop,
    shortName: "Water Tank",
    description: "Campus main water storage facility",
  ),
  Facility(
    location: LatLng(23.15150, 72.88447),
    color: Colors.purple,
    icon: Icons.theater_comedy,
    shortName: "Open Theater",
    description: "Outdoor amphitheater for performances",
  ),
  Facility(
    location: LatLng(23.15150, 72.88667),
    color: Colors.purple,
    icon: Icons.cell_tower,
    shortName: "Tower",
    description: "Communications tower",
  ),
  Facility(
    location: LatLng(23.15253, 72.88431),
    color: Colors.purple,
    icon: Icons.hotel,
    shortName: "Guest Room 1",
    description: "Guest accommodation for visitors",
  ),
  Facility(
    location: LatLng(23.15122, 72.88131),
    color: Colors.purple,
    icon: Icons.hotel,
    shortName: "Guest Room 2",
    description: "Additional guest accommodation",
  ),
  Facility(
    location: LatLng(23.15428, 72.88472),
    color: Colors.purple,
    icon: Icons.mic,
    shortName: "Auditorium",
    description: "Main campus auditorium for events",
  ),
  Facility(
    location: LatLng(23.15408, 72.88511),
    color: Colors.purple,
    icon: Icons.account_balance,
    shortName: "Admin",
    description: "Administration building",
  ),
];

Widget buildMarker(BuildContext context, Facility facility) {
  return GestureDetector(
    onTap: () {
      showDialog(
        context: context,
        builder: (BuildContext context) {
          return AlertDialog(
            shape: RoundedRectangleBorder(
              borderRadius: BorderRadius.circular(16),
            ),
            title: Row(
              children: [
                Icon(facility.icon, color: facility.color),
                const SizedBox(width: 10),
                Text(facility.shortName),
              ],
            ),
            content: Column(
              mainAxisSize: MainAxisSize.min,
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text(facility.description),
                const SizedBox(height: 10),
                Text(
                  "Location: ${facility.location.latitude.toStringAsFixed(6)}, ${facility.location.longitude.toStringAsFixed(6)}",
                  style: const TextStyle(
                    fontSize: 12,
                    color: Colors.grey,
                  ),
                ),
              ],
            ),
            actions: [
              TextButton(
                onPressed: () {
                  Navigator.of(context).pop();
                },
                child: const Text("Close"),
              ),
            ],
          );
        },
      );
    },
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
        Container(
          width: 30,
          height: 30,
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
          child: Icon(facility.icon, color: Colors.white, size: 16),
        ),
      ],
    ),
  );
}