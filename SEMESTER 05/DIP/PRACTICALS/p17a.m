clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');

if size(img, 3) == 3
    img = rgb2gray(img);
end

img_double = double(img);

% 1. Initial Threshold Guess (Mean of all pixels)
T = mean(img_double(:)); 
prev_T = 0; 
tolerance = 0.5;

while abs(T - prev_T) > tolerance
    prev_T = T;
    
    % 2. Segment based on current T
    fg = img_double(img_double > T);
    bg = img_double(img_double <= T);

    % 3. Calculate new means
    mean_fg = mean(fg);
    mean_bg = mean(bg);

    % Handle empty sets (pixels are all in one group, which rarely happens)
    if isempty(fg)
        mean_fg = 0;
    end
    if isempty(bg)
        mean_bg = 0;
    end
    
    % 4. Calculate new threshold
    T = (mean_fg + mean_bg) / 2;
end

% 5. Apply the final threshold
img_binary = img_double > T;

figure;
subplot(1, 2, 1);
imshow(uint8(img));
title('Original Grayscale Image');

subplot(1, 2, 2);
imshow(img_binary);
title(['Binary Image (Threshold T = ', num2str(T, '%.2f'), ')']);