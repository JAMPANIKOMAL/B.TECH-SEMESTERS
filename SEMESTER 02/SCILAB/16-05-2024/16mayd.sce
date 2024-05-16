
clc
clear
clf

l = input("Enter length of rod: ")
k = input("Enter value of coefficient k: ")
n = input("Enter number of terms required in solution: ")

function w=f(x)
    w = sin(3*%pi*x)
endfunction

for i=1:n
    function w1=f1(x)
        w1 = f(x)*sin(i*%pi*x/l)
    endfunction
    b(i) = (2/l)*integrate('f1(x)','x',0,l)
end

function u=f2(x, t)
    u=0
    for i=1:n
        u = u + b(i)*sin(i*%pi*x/l)*cos(i*%pi*k*t/l)	
    end
endfunction

x = 0:0.05:1
t = 0:0.025:0.25

f1 = feval(x,t,f2)
plot3d(x,t,f1,'x@t@f2(x,t)')

scf(1)
plot(x',f1(:,1),'m.*',x',f1(:,3),'g.-',x',f1(:,6),'b.+',x',f1(:,9),'r.x')
