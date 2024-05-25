// Clear the workspace
clc; clear; clf;  // Clear screen, figure, and workspace

// Define the differential equation (dy/dx)
function [ydot] = myfunction(x, y)
  // Right-hand side of the equation: ydot = x + y
  ydot = x + y;
endfunction

// Initial conditions
x0 = 0;
y0 = 1;

// Define the independent variable range
x = linspace(x0, 1, 100);  // Create 100 points from x0 to 1

// Solve the ODE using ode function
y = ode(y0, x0, x, @myfunction);  // Use @myfunction handle

// Display solution (x and y values)
disp('Solution (x, y):');
disp([x; y]);  // Display x and y values in a matrix

// Plot the solution
plot(x, y);
xlabel('x');
ylabel('y');
title('Solution of dy/dx = x+y, y(0) = 1');
