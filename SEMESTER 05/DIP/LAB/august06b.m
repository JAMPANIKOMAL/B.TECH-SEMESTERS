% Aim: Perform contrast stretching using inbuilt function. Using imadjust
% and stretchlimit

clc;
clear;
close all;

% Read images from the sample directory
imageFiles = ["sample/pout.tif", "sample/spine.tif", "sample/low.tif"];

% Process each image
for i = 1:length(imageFiles)
    % Read the image
    img = imread(imageFiles(i));
    
    % Perform contrast stretching
    stretchedImg = imadjust(img, stretchlim(img), []);
    
    % Display original and stretched images
    figure;
    subplot(1, 2, 1);
    imshow(img);
    title('Original Image');
    
    subplot(1, 2, 2);
    imshow(stretchedImg);
    title('Contrast Stretched Image');
end
