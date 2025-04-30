import 'package:flutter/material.dart';
import '../data/markers.dart';

class FacilityCard extends StatelessWidget {
  final Facility facility;
  final VoidCallback onClose;

  const FacilityCard({super.key, required this.facility, required this.onClose});

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
                      style: const TextStyle(fontWeight: FontWeight.bold, fontSize: 16),
                    ),
                    const SizedBox(height: 4),
                    Text(facility.description, style: const TextStyle(fontSize: 14)),
                  ],
                ),
              ),
              IconButton(icon: const Icon(Icons.close), onPressed: onClose),
            ],
          ),
        ),
      ),
    );
  }
}
