clc
clear
clf
function result=binom(n,k,p);
    result=factorial(n)*(p^k)*((1-p)^(n-k))/(factorial(k)*factorial(n-k));
endfunction
children=4;
reqblue=2;
probblue=0.5*0.5;
prob=binom(children,reqblue,probblue);
disp(prob)
