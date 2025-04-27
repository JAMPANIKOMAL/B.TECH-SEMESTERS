import 'package:flutter/material.dart';

class MapLegend extends StatelessWidget {
  const MapLegend({super.key});

  @override
  Widget build(BuildContext context) {
    return Card(
      shape: RoundedRectangleBorder(
        borderRadius: BorderRadius.circular(12.0),
      ),
      elevation: 6,
      color: Theme.of(context).cardColor.withOpacity(0.9),
      child: Padding(
        padding: const EdgeInsets.all(12.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            const Padding(
              padding: EdgeInsets.only(bottom: 8.0),
              child: Text(
                'Map Legend',
                style: TextStyle(
                  fontWeight: FontWeight.bold,
                  fontSize: 16,
                ),
              ),
            ),
            const Divider(height: 8),
            const SizedBox(height: 4),
            _buildLegendItem(Colors.green, 'Food Area', Icons.restaurant),
            const SizedBox(height: 8),
            _buildLegendItem(Colors.blue, 'Water Source', Icons.water_drop),
            const SizedBox(height: 8),
            _buildLegendItem(Colors.grey, 'Washroom', Icons.wc),
            const SizedBox(height: 8),
            _buildLegendItem(Colors.blue, 'Your Location', Icons.my_location),
          ],
        ),
      ),
    );
  }

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
              BoxShadow(
                color: Colors.black.withOpacity(0.1),
                blurRadius: 2,
                spreadRadius: 1,
              ),
            ],
          ),
          child: Icon(
            icon,
            size: 16,
            color: Colors.white,
          ),
        ),
        const SizedBox(width: 12),
        Text(
          text,
          style: const TextStyle(
            fontSize: 14,
          ),
        ),
      ],
    );
  }
}