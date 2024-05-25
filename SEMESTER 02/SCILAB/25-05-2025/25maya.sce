clc;clear;  //Clear the command window and workspace

// Addition operations
a = 2;
b = 2;

c1 = a + b;  // Add a and b, store the result in c1
disp('a + b = ' + string(c1));  // Display "a + b = " followed by the value of c1

c2 = a - b;  // Subtract b from a, store the result in c2
disp('a - b = ' + string(c2));  // Display "a - b = " followed by the value of c2

c3 = a * b;  // Multiply a and b, store the result in c3
disp('a * b = ' + string(c3));  // Display "a * b = " followed by the value of c3

c4 = a / b;  // Divide a by b, store the result in c4
disp('a / b = ' + string(c4));  // Display "a / b = " followed by the value of c4

c5 = a ^ b;  // Raise a to the power of b, store the result in c5
disp('a ^ b = ' + string(c5));  // Display "a ^ b = " followed by the value of c5

// Absolute value operations
d1 = -5.5;   // Assign value -5.5 to variable d1
disp('abs(-5.5) = ' + string(abs(d1)));  // Calculate absolute value of d1 and display with message

d2 = -5;     // Assign value -5 to variable d2
disp('abs(-5) = ' + string(abs(d2)));  // Calculate absolute value of d2 and display with message

// Square root operations
d3 = 2;       // Assign value 2 to variable d3
d4 = 3;       // Assign value 3 to variable d4
disp('sqrt(2) = ' + string(sqrt(d3)));  // Calculate square root of d3 and display with message
disp('sqrt(3) = ' + string(sqrt(d4)));  // Calculate square root of d4 and display with message

// Nth root operations
e1 = 3;       // Assign value 3 to variable e1
e2 = 27;      // Assign value 27 to variable e2
e3 = 4;       // Assign value 4 to variable e3
e4 = 16;      // Assign value 16 to variable e4
disp('3rd root of 27 = ' + string(nthroot(e2,e1)));  // Calculate 3rd root of 27 and display with message
disp('2nd root of 16 = ' + string(nthroot(e4,e3)));  // Calculate 2nd root of 16 and display with message

// Factorial operations
f1 = 4;       // Assign value 4 to variable f1
f2 = 5;       // Assign value 5 to variable f2
disp('factorial(4) = ' + string(factorial(f1)));  // Calculate factorial of 4 and display with message
disp('factorial(5) = ' + string(factorial(f2)));  // Calculate factorial of 5 and display with message

// Logarithmic operations
disp('log(2) = ' + string(log(a)) + ', log10(2) = ' + string(log10(b)));  // Calculate logarithms and display with messages

// Exponential operation
disp('exp(2) = ' + string(exp(a)));  // Calculate the exponential of a and display with message

// Display mathematical constants
disp('pi = ' + string(%pi) + ', e = ' + string(%e)); // Display pi and Euler's number with messages

// Imaginary unit operations
disp('Imaginary unit i = ' + string(//i));  // Display the imaginary unit with message
disp('sqrt(-1) = ' + string(sqrt(-1)));  // Calculate square root of -1 and display with message

// Trigonometric operations in radians
disp('sin(pi/2) = ' + string(sin(%pi/2)) + ', cos(pi/2) = ' + string(cos(%pi/2)) + ', cot(pi/4) = ' + string(cotg(%pi/4)));  % Calculate trigonometric operations and display with messages

// Trigonometric
