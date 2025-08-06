% Aim: Perform contrast stretching manually (using formulae) use pout, spine, low images.

clc;
clear;
close all;

% Read images from the sample directory
imageFiles = ["sample/pout.tif", "sample/spine.tif", "sample/low.tif"];

% Initialize an array to store the contrast stretched images
stretchedImages = cell(1, length(imageFiles));

% Define the input intensity range for contrast stretching
r1 = 0; % lower bound of input intensity
r2 = 1; % upper bound of input intensity
s1 = 0; % lower bound of output intensity
s2 = 1; % upper bound of output intensity

% Loop through each image file
for i = 1:length(imageFiles)
    % Read the image
    img = imread(imageFiles(i));
    
    % Convert to double for processing
    imgDouble = im2double(img);
    
    % Perform contrast stretching using the specified formula
    stretchedImg = (imgDouble - r1) * (s2 - s1) / (r2 - r1) + s1;
    
    % Store the contrast stretched image
    stretchedImages{i} = stretchedImg;
    
    % Display the original and stretched images
    figure;
    subplot(1, 2, 1);
    imshow(imgDouble);
    title(['Original Image: ', imageFiles(i)]);
    
    subplot(1, 2, 2);
    imshow(stretchedImg);
    title(['Contrast Stretched Image: ', imageFiles(i)]);
end
