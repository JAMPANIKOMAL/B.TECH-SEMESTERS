clc; clear; clf;  // Clear screen, figure, and workspace

// Define the differential equation (dy/dx)
function [ydot] = myfunction(x, y)
  // Right-hand side of the equation: ydot = 2*x*y
  ydot = 2*x*y;
endfunction

// Initial conditions
x0 = 0;
y0 = 1.8;

// Define the independent variable range
x = linspace(0, 1, 100);  // Create 100 points from 0 to 1

// Solve the ODE using ode function
y = ode(y0, x0, x, @myfunction);  // Use @myfunction handle

// Display solution (x and y values)
disp('Solution (x, y):');
disp([x; y]);  // Display x and y values in a matrix

// Plot the solution
plot(x, y);
xlabel('x');
ylabel('y');
title('Solution of dy/dx = 2xy, y(0) = 1.8');
