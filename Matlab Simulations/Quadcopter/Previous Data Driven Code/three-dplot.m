x = [-3:.1:3];
% Create the x Gaussian distribution
sigma1 = 1;
mu1=0;
normpdf1 = 1/(sigma1*sqrt(2*pi)) * exp(-(x-mu1).^2/(2*sigma1^2));
% Create the y Gaussian distribution
sigma2 = 2;
mu2=0;
normpdf2 = 1/(sigma2*sqrt(2*pi)) * exp(-(x-mu2).^2/(2*sigma2^2));

height = 2; % height in Z direction is the same for all points

for i=1:length(normpdf1)

    len = normpdf2(i)/2;
    xdata = [x(i) x(i) x(i) x(i)];
    ydata = [normpdf1(i)- len normpdf1(i)- len normpdf1(i)+ len 
    normpdf1(i)+ len];
    zdata = [0 height  height 0];

%     patch('Xdata',xdata, 'Ydata',ydata, 'Zdata',zdata, 'FaceColor', 'red')
%     hold on
end
plot(xdata,ydata,zdata)