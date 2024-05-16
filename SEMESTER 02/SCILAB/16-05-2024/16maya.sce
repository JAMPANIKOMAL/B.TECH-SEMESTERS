//1. To solve: (dy/dx)=x+y, y(0)=1, when x=[0,1]

clc; 
clf;
clear;

function [ydot]= f1(x, y)
    ydot = x+y
endfunction

    x1 = 0
    y1 = 1
    
    x = linspace(0,1,100)
    y = ode(y1, x1, x, f1)
    
    disp(x,y)
    plot(x,y)
