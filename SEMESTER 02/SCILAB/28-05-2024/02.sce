clc;
clear;

x = [1, 2, 3, 4, 5, 6];
disp(x);

x2 = 1 : 5 : 30;
disp(x2);

x3 = [1; 2; 3; 4];
disp(x3);

x4 = linspace(0, 8, 6);
disp(x4);

x5 = [1, 2, 3; 4, 5, 6; 7, 8, 9];
disp(x5);
x6 = [1, 0, 0; 0, 1, 0; 0, 0, 1];
disp(x5.*x6);
disp(x5');
disp(inv(x5), det(x5), diag(x5), rank(x5), trace(x5));
disp(zeros(2, 2), eye(2, 2), ones(2, 2));
