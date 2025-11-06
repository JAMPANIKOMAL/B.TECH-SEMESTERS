clc;
clear;
close all;

files = {'pout.tif', 'spine.tif', 'foosball.png'};
num_files = length(files);

figure; 

for k = 1:num_files
    img_path = ['sample/', files{k}];
    img = imread(img_path);

    if size(img, 3) == 3
        img = rgb2gray(img);
    end
    
    low_high_limits = stretchlim(img);
    stretched_img = imadjust(img, low_high_limits, [0 1]);
    
    subplot(num_files, 2, (k-1)*2 + 1);
    imshow(img);
    title(['Original: ', files{k}]);
    
    subplot(num_files, 2, (k-1)*2 + 2);
    imshow(stretched_img);
    title('Auto Contrast Stretched');
end