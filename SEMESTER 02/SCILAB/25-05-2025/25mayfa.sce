// Clear the workspace
clc; clear;

// Define matrix A
A = [1 2 3; 4 5 6; 7 8 9];

// Calculate the rank of A (number of linearly independent rows/columns)
rank_A = rank(A);

// Display the rank of A
disp('Rank of A:');
disp(rank_A);

// Calculate the null space (kernel) of A
null_space = kernel(A);

// Calculate the nullity (dimension of the null space)
nullity = size(null_space, 2);

// Display the nullity of A
disp('Nullity of A:');
disp(nullity);

// Get the number of columns in A
num_columns = size(A, 2);

// Check if the sum of rank and nullity equals the number of columns
if rank_A + nullity == num_columns
  disp('The sum of rank and nullity equals the number of columns.');
else
  disp('The sum of rank and nullity does not equal the number of columns.');
end
