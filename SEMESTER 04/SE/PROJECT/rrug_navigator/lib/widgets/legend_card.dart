// ignore_for_file: deprecated_member_use

import 'package:flutter/material.dart';

class LegendCard extends StatelessWidget {
  final VoidCallback onClose;

  const LegendCard({super.key, required this.onClose});

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
              BoxShadow(color: Colors.black.withOpacity(0.1), blurRadius: 2, spreadRadius: 1),
            ],
          ),
          child: Icon(icon, size: 16, color: Colors.white),
        ),
        const SizedBox(width: 12),
        Text(text, style: const TextStyle(fontSize: 14)),
      ],
    );
  }

  @override
  Widget build(BuildContext context) {
    return Card(
      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12.0)),
      elevation: 6,
      color: Theme.of(context).cardColor.withOpacity(0.9),
      child: Padding(
        padding: const EdgeInsets.all(12.0),
        child: Stack(
          children: [
            Padding(
              padding: const EdgeInsets.only(right: 32.0),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  const Padding(
                    padding: EdgeInsets.only(bottom: 8.0),
                    child: Text('Map Legend', style: TextStyle(fontWeight: FontWeight.bold, fontSize: 16)),
                  ),
                  const Divider(height: 8),
                  const SizedBox(height: 4),
                  _buildLegendItem(Colors.green, 'Food Area', Icons.restaurant),
                  const SizedBox(height: 8),
                  _buildLegendItem(Colors.blue, 'Water Source', Icons.water_drop),
                  const SizedBox(height: 8),
                  _buildLegendItem(Colors.grey, 'Washroom', Icons.wc),
                  const SizedBox(height: 8),
                  _buildLegendItem(Colors.red, 'Academic Building', Icons.school),
                  const SizedBox(height: 8),
                  _buildLegendItem(Colors.deepPurple, 'Miscellaneous', Icons.place),
                  const SizedBox(height: 8),
                  _buildLegendItem(Colors.blue, 'Your Location', Icons.my_location),
                ],
              ),
            ),
            Positioned(
              top: 0,
              right: 0,
              child: IconButton(
                icon: const Icon(Icons.push_pin),
                tooltip: 'Hide Legend',
                onPressed: onClose,
              ),
            ),
          ],
        ),
      ),
    );
  }
}
