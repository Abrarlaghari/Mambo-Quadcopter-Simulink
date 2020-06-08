function out=distendmf(xx,params)

v=params(1);
e=params(2);
l=params(3);
c=params(4);
% [row col]=size(xx);
% f=zeros(col);
 %f=0;
for i=1:length(xx)
f(i)= 1/(1+((1-v)/v)*((((xx(i)-c)/e)^2)^(l/2)));
end
% a=x(1);
% b=x(i);
% 
%plot(xx,f);
out=f';

end