clc
clear
sum=0
deff('d=f(x)','d=exp(x)')
n=input('The number of subinterval: ')
a=input('Enter the lower limit: ')
b=input('Enter the upper limit: ')
sum=f(a)+f(b)
h=(b-a)/n
for i=1:n
if(modulo(i,2)==0)
sum=sum+2*f(a+i*h)
else
sum=sum+4*f(a+i*h)
end
end
I=h*(sum)/3
disp(I,'Integral is= ')
