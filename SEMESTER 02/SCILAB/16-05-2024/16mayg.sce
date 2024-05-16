clc
clear
u = [2 5 -1]
v = [-2;1;1]
V = u * v
disp(V)
if V == 0 then
    disp("It is orthogonal")
else
    disp("It is not orthogonal")
end
