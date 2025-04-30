import 'package:flutter/material.dart';

class ContactPage extends StatelessWidget {
  const ContactPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Contact Us')),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: ListView(
          children: const [
            ListTile(
              leading: Icon(Icons.phone),
              title: Text('Security Office'),
              subtitle: Text('+91 98765 43210'),
            ),
            ListTile(
              leading: Icon(Icons.phone),
              title: Text('Admin Block Reception'),
              subtitle: Text('+91 91234 56789'),
            ),
            ListTile(
              leading: Icon(Icons.email),
              title: Text('Email Support'),
              subtitle: Text('help@rru.ac.in'),
            ),
            ListTile(
              leading: Icon(Icons.location_on),
              title: Text('Campus Location'),
              subtitle: Text('RRU, Lavad, Gandhinagar, Gujarat, India'),
            ),
          ],
        ),
      ),
    );
  }
}
