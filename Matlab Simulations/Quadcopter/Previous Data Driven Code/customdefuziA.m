function defuzzfuna = customdefuziA(xmf,ymf)
% total_area = sum(ymf);
% defuzzfun1 = sum(ymf.*xmf)/total_area;

%%%%Distending Calculations%%%%%
 
 ymff=ymf';
%  vl=ymff(1,1);
%  el=ymff(1,2);
%  ll=ymff(1,3);
 c=ymff(1,4);
%  vr=ymff(1,5);
%  er=ymff(1,6);
%  lr=ymff(1,7);
%  ls=5;
%  f=0;

%  for i=1:length(xmf)
%  f(i)= 1/(1+((1-v)/v)*((((xmf(i)-c)/e)^2)^(l/2)));
%  end
 
%  
%  for i=1:length(xmf)
% 
%     fl(i)=(((1-vl)/vl)*(((xmf(i)-c)/(el*(1+exp(ls*(xmf(i)-c))))^2)^(ll/2)));
%     
%     fr(i)=(((1-vr)/vr)*(((xmf(i)-c)/(er*(1+exp(-ls*(xmf(i))-c)))^2)^(lr/2)));
%     
% f(i)= 1/(1+(fl(i)+fr(i)));
% end
%  
% a=x(1);
% b=x(i);
% figure;
% plot(xmf,f);
%  total_area1 = sum(f);
%  defuzzfuna = sum(f'.*xmf)/total_area1;
   defuzzfuna=c;



