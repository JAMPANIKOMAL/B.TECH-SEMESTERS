// Clear the workspace
clc; clear;

// Define polynomials
// p1: 3x^2 + 2x (roots specified, variable named 'x', coefficients in reverse order)
p1 = poly([3 2], 'x', 'r');
disp('p1 (roots specified, variable x, coefficients reversed):');
disp(p1);

// p2: 3x^2 + 2x (coefficients specified, variable named 'x', coefficients reversed)
p2 = poly([3 2], 'x', 'c');
disp('p2 (coefficients specified, variable x, coefficients reversed):');
disp(p2);

// p3: 3x^2 + 2x - 1 (coefficients specified, variable named 'x', coefficients reversed)
p3 = poly([3 2 -1], 'x', 'c');
disp('p3 (coefficients specified, variable x, coefficients reversed):');
disp(p3);

// p4: 4x^2 + 2x - 1 (coefficients specified, variable named 'x', coefficients reversed)
p4 = poly([4 2 -1], 'x', 'c');
disp('p4 (coefficients specified, variable x, coefficients reversed):');
disp(p4);

// Polynomial addition (p3 + p4)
disp('p3 + p4:');
disp(p3 + p4);

// Polynomial subtraction (p3 - p4)
disp('p3 - p4:');
disp(p3 - p4);

// Polynomial multiplication (p3 * p4)
disp('p3 * p4:');
disp(p3 * p4);
