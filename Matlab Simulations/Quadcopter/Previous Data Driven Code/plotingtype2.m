v1=.5;
e1=.8;
l1=2;
c1=0;
% [row col]=size(xx);
% f=zeros(col);
v2=.9;
e2=.9;
l2=2;
c2=0;
%f=0;
xx=-20:.1:20;
yy=0:.001:1;
[xxx,yyy]=meshgrid(xx,yy);
[w d]=size(xxx);
[z c]=size(yyy);
for k=1:d
    
f1(d)= 1/(1+((1-v1)/v1)*((((xxx(1,d)-c1)/e1)^2)^(l1/2)));
f2(d)= 1/(1+((1-v2)/v2)*((((xxx(1,d)-c2)/e2)^2)^(l2/2)));
     
 det=f2(d)-f1(d)
% det=1;
% v3=det/6;
% e3=det/4;
% l3=2;
% c3=det/2;
% for j=1:z
% f3(k,j)= 1/(1+((1-v3)/v3)*((((yyy(j,k))/e3)^2)^(l3/2)));
% end
end
figure;
%surf(xxx,f2,f3')
% plot3(xxx,f1,f3');
% % hold on;
plot(xxx(1,1),f2);
hold on;
plot (xxx(1,1),f1);