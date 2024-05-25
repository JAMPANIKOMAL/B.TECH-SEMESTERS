// Clear the workspace
clc; clear; clf;  // Clear screen, figure, and workspace

// Define the differential equation (dx/dt)
function [tdot] = myfunction(x, t)
  // Right-hand side of the equation: tdot = cos(t) - x*tan(t)
  tdot = cos(t) - x*tan(t);
endfunction

// Initial conditions
x0 = 0;  // Note: Here, 't' represents the independent variable
y0 = 0;  // Initial value for x (dependent variable)

// Define the independent variable range (time interval)
t = linspace(0, 1, 100);  // Create 100 points from 0 to 1

// Solve the ODE using ode function
y = ode(y0, x0, t, @myfunction);  // Use @myfunction handle

// Display solution (t and y values)
disp('Solution (t, x):');
disp([t; y]);  // Display t and y values in a matrix

// Plot the solution (x vs t)
plot(t, y);
xlabel('t');
ylabel('x');
title('Solution of dx/dt + tan(t)x = cos(t), x(0) = 0');
