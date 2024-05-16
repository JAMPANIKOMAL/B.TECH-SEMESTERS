//2. Write a scilab code to find solution of the first order initial value problem at x=0.8:
//3. Solve and Plot the solution: (dx/dt)+(tant)x=cost, y(0)=0 ; in interval [0,1]


clc; 
clf;
clear;

function [tdot]= f1(x, t)
    tdot = cos(t) - x * tan(t)
endfunction

    x1 = 0
    y1 = 1
    
    x = linspace(0,1,100)
    y = ode(y1, x1, x, f1)
    
    disp(x,y)
    plot(x,y)
