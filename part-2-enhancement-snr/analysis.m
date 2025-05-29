cd '/MATLAB Drive/BMEN609/Hess';
currentFolder = pwd;
destination = currentFolder + "/data/";
blackOnWhite=1; % set black on white vessels to true for US + IR
list = strsplit(ls("data"));
list = list(1:30);
disp(length(list));
% initialize empty arrays
SNRIRs = [];
PSNRIRs = [];
SNRUSs = [];
PSNRUSs = [];
MSEIRs = [];
MSEUSs = [];
% loop through images
for k = 1:length(list)
    imageName = list(k);
    disp(imageName);
    disp(string(k)+ ": " + string(2*k-1)+ " " + string(2*k) + " " +string(blackOnWhite));
    I = imread(destination+list{1,k}); % read image
    if ndims(I) == 3 % convert RGB black and white
        I = rgb2gray(I);
    end
    I = mat2gray(I); % apply graying
    I = im2double(I); % scale to 1
    disp("max original "+ string(max(I, [], "all")));
    figure(2*k-1); % create grayed image
    imshow(I); % show grayed image
    s.BlackWhite=blackOnWhite; % set black and white to true
    s.verbose=true; % set verbose true
    % get Frangi vesselness filter results
    [outIm,whatScale,Direction] = FrangiFilter2D(I, s);
    outIm = mat2gray(outIm); % gray output image
    outIm = im2double(outIm); % scale to 1
    figure(2*k); % create figure
    imshow(outIm); % display segmentation
    % check scaling
    disp("max " + string(max(outIm, [], "all")));
    % compute the SNR and PSNRs
    varI = (std(double(I(:))))^2; % sample std
    D0 = sum(sum((double(I) - double(outIm)).^2));
    SNR=10*log10(varI/D0);
    PSNR=10*log10((2^8-1)^2/D0);
    disp(PSNR + " " + SNR);
    % grow PSNR and SNR arrays
    if list{1,k}(1:2) == "IR" || list{1,k}(1:2) == "im"
        PSNRIRs = [PSNRIRs, PSNR];
        SNRIRs = [SNRIRs, SNR];
        MSEIRs = [MSEIRs, D0];
    else
        PSNRUSs = [PSNRUSs, PSNR];
        SNRUSs = [SNRUSs, SNR];
        MSEUSs = [MSEUSs, D0];
    end
end

% compute Manny-Whitney U test
cd '/MATLAB Drive/BMEN609/mwwtest-2.0.0.0';
mwwtest(double(SNRUSs), double(SNRIRs));
disp(" ");
mwwtest(double(PSNRUSs), double(PSNRIRs));
