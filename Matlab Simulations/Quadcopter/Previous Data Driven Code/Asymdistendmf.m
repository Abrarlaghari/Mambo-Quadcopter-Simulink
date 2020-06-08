function out = Asymdistendmf( xx,params )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

vl=params(1);
el=params(2);
ll=params(3);
vr=params(4);
er=params(5);
lr=params(6);
ls=params(7);
c=params(8);
%[row col]=size(xx);
%f=zeros(col);
%fl=zeros(col);
%fr=zeros(col);
%f=zeros(col);
for i=1:length(xx)

    fl(i)=(((1-vl)/vl)*(((xx(i)-c)/(el*(1+exp(ls*(xx(i)-c))))^2)^(ll/2)));
    
    fr(i)=(((1-vr)/vr)*(((xx(i)-c)/(er*(1+exp(-ls*(xx(i))-c)))^2)^(lr/2)));
    
f(i)= 1/(1+(fl(i)+fr(i)));
end
% a=x(1);
% b=x(i);
% figure; 
% plot(xx,f');
out=real(f');

end



