clc, clear;

A = [1 2 3; 4 5 6; 7 8 9]
r = rank(A)
disp(r)
k = kernel(A)
nullity = size(k, 2)
disp(nullity)
n = size(A, 2)
if r + nullity == n then
    disp(r)
end
