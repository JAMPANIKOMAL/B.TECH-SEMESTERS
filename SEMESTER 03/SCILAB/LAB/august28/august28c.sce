clc ;
clear ;
clf ;
N = 10000; 
count = 0;
for i = 1: N
y1 = ceil ( rand (1) *6) ; 
y2 = ceil ( rand (1) *6) ;
if (( y1 + y2 ) == 3)
count = count + 1;
end
prob1 ( i ) = count / i ;
end
plot ( prob1 )
xlabel ('Number of Trials') ;
ylabel ('Probaility') ;
title ('Probabilty of getting sum of dots on faces of a die to be 3') ;
