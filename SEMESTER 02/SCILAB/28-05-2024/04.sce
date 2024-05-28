clc; clear; clf;

// Generate angle values in degrees
x = 0:1:360;  // Create an array from 0 to 360 with increment of 1

// Calculate sine and cosine values
y = sind(x);  // Sine of x in degrees
z = cosd(x);  // Cosine of x in degrees

// Plot sine and cosine functions on the same graph
plot(x, y, 'b-', x, z, 'r-');  // Blue line for sine, red line for cosine



// Add labels and title
xtitle('Angle (degrees)');
ylabel('Sin(X) and Cos(X)');
title('Sine and Cosine Functions (Degrees)');

// Create a legend
legend('Sin(X)', 'Cos(X)');
