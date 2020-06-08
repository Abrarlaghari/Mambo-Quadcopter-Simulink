function defuzzfun = customdefuzi(xmf,ymf)
% total_area = sum(ymf);
% defuzzfun1 = sum(ymf.*xmf)/total_area;

%%%%Distending Calculations%%%%%
  ymff=ymf';
%  v=ymff(1,1);
%  e=ymff(1,2);
%  l=ymff(1,3);
 c=ymff(1,4);
%  f=0;
%  for i=1:length(xmf)
%  f(i)= 1/(1+((1-v)/v)*((((xmf(i)-c)/e)^2)^(l/2)));
%  end
% a=x(1);
% b=x(i);
% 
% plot(xmf,f);
% total_area1 = sum(f);
% defuzzfun = sum(f'.*xmf)/total_area1;
 defuzzfun=c;

