% Aim: Perform contrast stretching using inbuilt function. Using imadjust
% and stretchlimit

clc;
clear;
close all;

% Read images from the sample directory
imageFiles = ["sample/pout.tif", "sample/spine.tif", "sample/low.tif"];

% Create a single figure for displaying images
figure;

% Process each image
for i = 1:length(imageFiles)
    % Read the image
    img = imread(imageFiles(i));
    
    % Perform contrast stretching
    stretchedImg = imadjust(img, stretchlim(img), []);
    
    % Display original and stretched images in the same figure
    subplot(length(imageFiles), 2, 2*i-1);
    imshow(img);
    title(['Original Image ', num2str(i)]);
    
    subplot(length(imageFiles), 2, 2*i);
    imshow(stretchedImg);
    title(['Contrast Stretched Image ', num2str(i)]);
end
