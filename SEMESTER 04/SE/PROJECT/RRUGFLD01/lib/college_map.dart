import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';

class CollegeMapPage extends StatefulWidget {
  @override
  _CollegeMapPageState createState() => _CollegeMapPageState();
}

class _CollegeMapPageState extends State<CollegeMapPage> {
  List<LatLng> _coordinates = [];

  @override
  void initState() {
    super.initState();
    // Load the OSM data
    loadMapData();
  }

  // Load map data from .osm file
  void loadMapData() async {
    final coordinates = await parseOsmFile('assets/rru_college_map.osm');
    setState(() {
      _coordinates = coordinates;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('RRU College Map'),
      ),
      body: FlutterMap(
        options: MapOptions(
          center: LatLng(23.0225, 72.5714), // Set this to the center of your college
          zoom: 16.0, // Zoom level
        ),
        children: [
          TileLayerWidget(
            options: TileLayerOptions(
              urlTemplate: 'https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png',
              subdomains: ['a', 'b', 'c'],
            ),
          ),
          MarkerLayerWidget(
            options: MarkerLayerOptions(
              markers: _coordinates.map((coord) {
                return Marker(
                  point: coord,
                  width: 40.0,
                  height: 40.0,
                  builder: (context) => Icon(
                    Icons.location_on,
                    color: Colors.red,
                    size: 40.0,
                  ),
                );
              }).toList(),
            ),
          ),
        ],
      ),
    );
  }
}
