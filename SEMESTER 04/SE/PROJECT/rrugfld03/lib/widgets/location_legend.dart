import 'package:flutter/material.dart';

class LocationLegend extends StatelessWidget {
  const LocationLegend({super.key});

  @override
  Widget build(BuildContext context) {
    return Material(
      color: Colors.white.withOpacity(0.8),
      borderRadius: BorderRadius.circular(10),
      child: Padding(
        padding: const EdgeInsets.all(8.0),
        child: Column(
          children: [
            Row(
              children: [
                Container(
                  width: 20,
                  height: 20,
                  color: Colors.green,
                ),
                const SizedBox(width: 5),
                const Text('Food Area'),
              ],
            ),
            Row(
              children: [
                Container(
                  width: 20,
                  height: 20,
                  color: Colors.blue,
                ),
                const SizedBox(width: 5),
                const Text('Water Source'),
              ],
            ),
            Row(
              children: [
                Container(
                  width: 20,
                  height: 20,
                  color: Colors.grey,
                ),
                const SizedBox(width: 5),
                const Text('Washroom'),
              ],
            ),
          ],
        ),
      ),
    );
  }
}