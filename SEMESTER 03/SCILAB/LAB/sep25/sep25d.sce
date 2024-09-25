//poision distribution
clc
clear
[probX0,Q]=cdfpoi("PQ",0,3);
probX1=1-probX0;
disp(probX1);
