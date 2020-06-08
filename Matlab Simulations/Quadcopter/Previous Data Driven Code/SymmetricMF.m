clear all;
xx=-10:.1:10;
figure(1);
% for i=1:1:1
params=[.999 .999 2 0];
plot(xx,distendmf(xx,params));
% legend('\nu =.999 , \epsilon =.999 , \lambda =2');
hold on;
%  end
% legend('\epsilon =.1','\epsilon =.2','\epsilon =.3','\epsilon =.4','\epsilon =5','\epsilon =6','\epsilon =7','\epsilon =8','\epsilon =9','\epsilon =10');
params=[.9 .9 2 0];
plot(xx,distendmf(xx,params));
% legend('\nu =.9 ,\epsilon =.9 , \lambda =2');
hold on;

params=[0.7 0.7 2 0];
plot(xx,distendmf(xx,params));
% legend('\nu =.7 ,\epsilon =.7 , \lambda =2');
hold on;

params=[0.5 0.5 20 0];
plot(xx,distendmf(xx,params));
% legend('\nu =.999 , \epsilon =.999 , \lambda =2','\nu =.9 ,\epsilon =.9 , \lambda =2','\nu =.7 ,\epsilon =.7 , \lambda =2','\nu =.5, \epsilon =.5 , \lambda =20');
hold on;

legend('\nu =.999 , \epsilon =.999 , \lambda =2','\nu =.9 ,\epsilon =.9 , \lambda =2','\nu =.7 ,\epsilon =.7 , \lambda =2','\nu =.5, \epsilon =.5 , \lambda =20');