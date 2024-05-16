//Code for Fourier series

clc;
clear;
clf;

deff('a=f(x)','a=x*x')

function [a0, A, B]=myfourier(l, n, f)
    a0 = (1/l)*integrate('f(x)','x',-l,l)
    for i=1:n
        function an=f1(x, f)
            an = f(x)*cos(i*%pi*x/l)
            disp(an)
        endfunction
        
        function bn=f2(x, f)
            bn = f(x)*sin(i*%pi*x/l)
            disp(bn)
        endfunction
        
        A(i) = (1/l)*integrate('f1(x)','x',-l,l)
        B(i) = (1/l)*integrate('f2(x)','x',-l,l)
        
    end
    
    x = -5*l:0.1:5*l
    series = a0/2;
    
    for i=1:n
        series = series + A(i)*cos(i*%pi*x/l) + B(i)*sin(i*%pi*x/l)
    end
    
    plot(x,series)
endfunction

//myfourier(2,6,f)    Write in terminal.
