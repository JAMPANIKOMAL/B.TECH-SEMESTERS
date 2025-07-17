clc;
clear;
close all;

i = imread('sample/badminton.jpg');

r = i(:,:,1);
g = i(:,:,2);
b = i(:,:,3);

figure;
subplot(2,2,1);
imshow(i);
title('Original');

subplot(2,2,2);
imshow(r);
title('Red component');

subplot(2,2,3);
imshow(b);
title('Blue component');

subplot(2,2,4);
imshow(g);
title('Green component');
