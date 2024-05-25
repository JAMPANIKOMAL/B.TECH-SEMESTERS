// Clear the workspace
clc; clear;

// Define matrix A5
A5 = [2 0 0; 0 2 0; 0 0 2];

// Calculate eigenvalues
eigenvalues = spec(A5);

// Display eigenvalues with a label
disp('Eigenvalues of A5:');
disp(eigenvalues);

// Calculate eigenvectors and diagonal matrix
[eigenvectors, diagonal_matrix] = spec(A5);

// Display eigenvectors and diagonal matrix with labels
disp('Eigenvectors of A5 (columns represent eigenvectors):');
disp(eigenvectors);
disp('Diagonal matrix of eigenvalues:');
disp(diagonal_matrix);
