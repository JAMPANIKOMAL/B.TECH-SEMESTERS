clc;
clear;
close all;

i = imfinfo("sample/badminton.jpg");
fprintf('Filename: %s\n', i.Filename);
fprintf('Bit Depth: %d\n', i.BitDepth);
fprintf('Format: %s\n', i.Format);
fprintf('Color Type: %s\n', i.ColorType);
fprintf('File Size: %d bytes\n', i.FileSize);