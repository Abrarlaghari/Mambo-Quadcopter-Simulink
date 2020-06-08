clear all;
xx=-5:.1:5;
figure(1);
for i=1:1:1
params=[0.5 0.5 5 0.8 0.7 5 5 0];
plot(xx,Asymdistendmf(xx,params));

hold on;

end
% legend('\epsilon =.1','\epsilon =.2','\epsilon =.3','\epsilon =.4','\epsilon =5','\epsilon =6','\epsilon =7','\epsilon =8','\epsilon =9','\epsilon =10');