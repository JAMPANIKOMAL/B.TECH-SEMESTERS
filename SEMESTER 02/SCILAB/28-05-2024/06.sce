clc;
clear;
clf;

function[ydof] = myfunction(x, y)
    ydof = x + y;
endfunction

x0 = 0;
y0 = 1;

x = linspace(x0, 1, 100);

y = ode(y0, x0, x, myfunction);

disp([x; y]);

plot(x, y);

