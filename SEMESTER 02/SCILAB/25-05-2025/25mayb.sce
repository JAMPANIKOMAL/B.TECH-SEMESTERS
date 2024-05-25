// Clear the command window and workspace
clc; clear;

// Create row vectors with different data types
x1 = [1, 2, 3, 4, 5, 6];     // Integer vector
disp('x1 (integer vector): ');
disp(x1);

x2 = [.1 2.2 3.0 4];         // Double vector (contains decimals)
disp('x2 (double vector): ');
disp(x2);

x3 = ['Delhi', 'USA', 'UK'];  // Character vector (contains text)
disp('x3 (character vector): ');
disp(x3);

// Create row vectors using built-in functions
x4 = 1:5;                    // Creates vector from 1 to 5 (inclusive)
disp('x4 (1 to 5): ');
disp(x4);

x5 = 1:2:7;                   // Creates vector with increment of 2 (1, 3, 5, 7)
disp('x5 (1 to 7 with increment 2): ');
disp(x5);

// Create column vectors
y1 = [1; 2; 3; 4; 5];        // Semicolon (;) creates columns
disp('y1 (column vector): ');
disp(y1);

y2 = linspace(0, 8, 6);        // Creates linearly spaced vector from 0 to 8 with 6 elements
disp('y2 (linspace 0 to 8 with 6 elements): ');
disp(y2);

// Create matrices
A1 = [1 2 3 ; 3 4 5];         // Matrix with rows and columns separated by semicolons and spaces
disp('A1 (matrix): ');
disp(A1);
size(A1);                     // Display size of A1 (number of rows, columns)

A2 = [1 2 3; 3 4 5 ; 4 5 6];  // Matrix with multiple rows
disp('A2 (matrix with multiple rows): ');
disp(A2);

// Matrix addition, subtraction, multiplication
A3 = [1 2; 3 4];
A4 = [1 2; 3 4];

disp('A3 + A4 (element-wise addition): ');
disp(A3 + A4);

disp('A3 - A4 (element-wise subtraction): ');
disp(A3 - A4);

disp('A3 * A4 (matrix multiplication): ');
disp(A3 * A4);  // Note: Multiplication only works for compatible matrix dimensions

disp('A3 .* A4 (element-wise multiplication): ');
disp(A3 .* A4);

// Matrix operations
disp('Sum of elements in A3: ');
disp(sum(A3));

disp('Mean of elements in A3: ');
disp(mean(A3));

disp('Maximum and minimum elements in A3: ');
disp(max(A3), min(A3));

// Matrix transpose (flips rows and columns)
disp('Transpose of A3: ');
disp(A3');

// More matrix operations
disp('Inverse (if exists), determinant, diagonal elements, rank, and trace of A3: ');
disp(inv(A3), det(A3), diag(A3), rank(A3), trace(A3));  // Note: Inverse may not exist for all matrices

// Accessing specific elements in a matrix
disp('A3(1,1), A3(1,2), A3(2,1), A4(2,2): ');
disp(A3(1,1), A3(1,2), A3(2,1), A4(2,2));

// Accessing rows and columns
disp('First row of A3, first column of A3: ');
disp(A3(1,:), A3(:,1));

disp('Second row of A3, second column of A3: ');
disp(A3(2,:), A3(:,2));

// Creating special matrices
disp('zeros(2,2) - Creates a 2x2 matrix of zeros: ');
disp(zeros(2,2));

disp('eye(2,2) - Creates a 2x2 identity matrix: ');
disp(eye(2,2));

disp('ones(2,2) - Creates a 2x2 matrix of ones: ');
disp(ones(2,2));
