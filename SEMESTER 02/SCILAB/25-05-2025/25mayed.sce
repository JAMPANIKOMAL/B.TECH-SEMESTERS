// Clear the workspace
clc; clear;

// Define vectors v1, v2, and v3
v1 = [2 2 1];
v2 = [1 -1 1];
v3 = [1 0 1];

// Create matrix A by stacking vectors vertically
A = [v1; v2; v3];

// Display matrix A
disp('Matrix A:');
disp(A);

// Calculate the rank of A (number of linearly independent rows/columns)
rank_A = rank(A);

// Check for linear independence based on rank
if rank_A == 3
  disp('The vectors are linearly independent.');
else
  disp('The vectors are linearly dependent.');
end
