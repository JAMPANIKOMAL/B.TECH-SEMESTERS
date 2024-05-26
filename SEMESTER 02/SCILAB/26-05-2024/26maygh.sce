// Clear the workspace
clc; clear; clf;

// Define parameters (modify if needed)
L = 2;  // Length
H = 1;  // Height
n = 20;  // Number of terms in the solution (adjust for accuracy)

// Function for initial condition at y=H (u(x, H))
function w = f(x)
  w = 100*x*(L-x)^3;
endfunction

// Function for integrand in coefficient calculation (a_n)
function w1 = f1(x)
  w1 = f(x) * sin(n*pi*x/L);
endfunction

// Function to calculate coefficient a_n
function a = a1(n)
  // Use integrate for numerical integration
  a = 2 * integrate('f1(x)', 'x', 0, L) / (L * sinh(n*pi*H/L));
endfunction

// Calculate coefficients a_n for n terms
a = [];
for i = 1:n
  a = [a a1(i)];
end

// Solution function u(x, y)
function u = u1(x, y)
  u = 0;
  for j = 1:n
    u = u + a(j) * sin(j*pi*x/L) * sinh(j*pi*y/L);
  end
endfunction

// Define ranges for independent variables (x and y)
x = 0:L/40:L;
y = 0:H/20:H;

// Calculate the solution using u1
u2 = u1(x, y);

// Optional: Plot the 3D solution (comment out if not needed)
// plot3d(x, y, u2, 25, 5, 'x@t@u(x, t)');

// Plot the contour of the solution
scf(1);
contour(x, y, u2, 15);
xtitle('x');  // Label axes for clarity
ylabel('y');
title('Contour Plot for Two-Dimensional Laplace Equation');
