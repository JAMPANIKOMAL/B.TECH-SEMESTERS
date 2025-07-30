% Power Law Transformation(use tire.tif and spine images). Print subplot of 2 x 2 (original, gamma = 0.4, 2, 2.5)

clc;
clear;
close all;

imageFiles = {'spine.tif', 'tire.tif'};
gammas = [0.4, 2, 2.5];

for i = 1:length(imageFiles)
    img = imread(imageFiles{i});
    imgDouble = im2double(img);
    figure;
    
    subplot(2, 2, 1);
    imshow(img);
    title('Original Image');
    
    for j = 1:length(gammas)
        gammaImg = imgDouble .^ gammas(j);
        subplot(2, 2, j + 1);
        imshow(gammaImg);
        title(['\gamma = ', num2str(gammas(j))]);
    end
    
    sgtitle(['Power Law Transformations for "', imageFiles{i}, '"']);
end