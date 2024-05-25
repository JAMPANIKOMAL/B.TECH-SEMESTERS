// Clear the workspace
clc; clear;

// Define matrix A6
A6 = [1 2 3; 4 4 3; 2 2 4];

// Calculate eigenvalues (complex and real parts)
eigenvalues = spec(A6);

// Display eigenvalues (complex and real parts)
disp('Eigenvalues of A6 (complex):');
disp(eigenvalues);
disp('Eigenvalues of A6 (real and imaginary parts):');
disp(real(eigenvalues), imag(eigenvalues));

// Calculate eigenvectors and diagonal matrix
[eigenvectors, diagonal_matrix] = spec(A6);

// Display eigenvectors and diagonal matrix
disp('Eigenvectors of A6 (columns represent eigenvectors):');
disp(eigenvectors);
disp('Diagonal matrix of eigenvalues:');
disp(diagonal_matrix);
