//To find the root of  y=x^3 - 100 using Regular Falsi Method

deff('d=f(x)','d=x^3-100')
a=input("Enter the value of a:")
b=input("Enter the value of b:")
n=input("Enter the number of iterations n:")
for i=1:n
    c=(a*f(b)-b*f(a))/(f(b)-f(a))
    disp([i,c])
if f(a)*f(c)<0 then
    b=c
end
if f(b)*f(c)<0 then
    a=c
end
c1=(a*f(b)-b*f(a))/(f(b)-f(a))
if abs(c1-c)<0.00001 then
    disp("We get accurate roots")
    break;
    end
end
