function Val = CalculateT2df_a_red(Point,Centres,Ep, nu, Noise)
% mu1=0.3526;
% mu2=0.3526;
% mu1r= (1-mu1)./(mu1);
% mu2r= (1-mu2)./(mu2);
% e1=.33; 
l1=4;
l2=4;
ls=100;
  
 mul= (1-nu)/(nu);
 mur= (1-nu)/(nu);


 %dist1 = 1/(1+mu1r*((abs((Point-Centres(i))/e1)^l1)));
 deltal1 = abs(((Point-Centres(1))/ Ep ) * (1 / (1 + exp(ls*((Point-Centres(1)))))))^l1;
 deltar1 = abs(((Point-Centres(2))/ Ep ) * (1 / (1 + exp(-ls*((Point-Centres(2)))))))^l1;
 delta1 = 1/(1+ (mul * deltal1) + (mur *deltar1));
 
%  e2=e1;

%dist2 = .8/(1+mu2r*((abs((Point-Centres(i))/e2)^l2)));
 deltal2 = abs((((Point-Centres(1))- Noise)/ Ep ) * (1 / (1 + exp(ls*(((Point-Centres(1))- Noise))))))^l2;
 deltar2 = abs((((Point-Centres(2))+ Noise)/ Ep ) * (1 / (1 + exp(-ls*(((Point-Centres(2))+ Noise))))))^l2;
 delta2 = 1/(1+ (mul * deltal2) + (mur *deltar2));

Val(1,1) = delta1;
Val(1,2) = delta2;

% 
% 
%  Point = 0:1/200:1;
% 
%     for i=1:length(Point)
%     
%         deltal1(i) =  abs(((Point(i)-Centres(1))/ Ep ) * (1 / (1 + exp(ls*((Point(i)-Centres(1)))))))^l1;
%         deltal2(i) = abs(((Point(i)-Centres(2))/ Ep ) * (1 / (1 + exp(-ls*((Point(i)-Centres(2)))))))^l1;
%         nulterm =(1-nu)/(nu);
%     %   nulterm = 1;
%         %deltal(i)=(abs((x(i)-IP1(j))/(epl1(j)*(1+exp(ls*(x(i)-IP1(j)))))))^lml1(j);
%         %deltar(i)=(abs((x(i)-IP1(j))/(epr1(j)*(1+exp(-ls*(x(i))-IP1(j)))))^lmr1(j));
% %         deltar1(i) = abs((((Point(i)-Centres(1))- Noise)/ Ep ) * (1 / (1 + exp(ls*(((Point(i)-Centres(1))- Noise))))))^l2;
% %         deltar2(i) = abs((((Point(i)-Centres(2))+ Noise)/ Ep ) * (1 / (1 + exp(-ls*(((Point(i)-Centres(2))+ Noise))))))^l2; 
%          nurterm = (1-nu)/(nu);
%     %   nurterm = 1;
%         delta(1,i)= 1/(1+ (nulterm * deltal1(i)) + (nurterm *deltal2(i)));
% %         delta(2,i)= 1/(1+ (nulterm * deltal2(i)) + (nurterm *deltar2(i)));
% 
%     end
% 
%   figure(1); 
%   plot(Point, delta');
%   axis([0 1 0 1.2]);
%   hold on;    
% Val=1;
%   
end



