import 'package:flutter/material.dart';

class ThemeManager {
  static final ValueNotifier<ThemeMode> currentTheme = ValueNotifier<ThemeMode>(
    ThemeMode.light,
  );

  static void toggleTheme() {
    currentTheme.value =
        currentTheme.value == ThemeMode.light
            ? ThemeMode.dark
            : ThemeMode.light;
  }
}
