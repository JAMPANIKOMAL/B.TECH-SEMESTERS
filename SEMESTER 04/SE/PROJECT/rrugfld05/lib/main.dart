import 'package:flutter/material.dart';
import 'screens/map_screen.dart';

class ThemeManager {
  static final ValueNotifier<ThemeMode> currentTheme =
  ValueNotifier<ThemeMode>(ThemeMode.light);

  static void toggleTheme() {
    currentTheme.value = currentTheme.value == ThemeMode.light
        ? ThemeMode.dark
        : ThemeMode.light;
  }
}

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return ValueListenableBuilder(
      valueListenable: ThemeManager.currentTheme,
      builder: (context, value, child) => MaterialApp(
        title: 'RRUG Facility Locator',
        theme: ThemeData(
          colorScheme: ColorScheme.fromSeed(seedColor: Colors.blue),
          useMaterial3: true,
          fontFamily: 'Roboto',
        ),
        darkTheme: ThemeData(
          colorScheme: ColorScheme.fromSeed(
              seedColor: Colors.blue, brightness: Brightness.dark),
          useMaterial3: true,
          fontFamily: 'Roboto',
        ),
        themeMode: value,
        home: const MapScreen(),
      ),
    );
  }
}