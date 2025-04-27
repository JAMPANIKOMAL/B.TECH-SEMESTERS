import 'package:flutter/material.dart';
import 'college_map.dart';  // Import the map screen

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'RRU College Map',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: CollegeMapPage(),  // Navigate to the College Map Page
    );
  }
}
