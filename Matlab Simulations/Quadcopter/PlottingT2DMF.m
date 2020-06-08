function [delta1, delta2] = PlottingT2DMF(IP1, EP, lambda , nu, Noise)
%% Calculating the parameters of the input and ouput Membership Functions

 pointer=1;
for i= 1: 1: length(EP)
   epr1(pointer) = EP(i);
   nur1(pointer) = nu(i);
   pointer = pointer + 1;
end

 pointerr=1;
for i= 1: 1: length(EP)
   epl1(pointerr) = EP(i);
   nul1(pointerr) = nu(i);
   pointerr = pointerr + 1;
end

[maxx, maxind1] = max(IP1);
[minn, minind1] = min(IP1);
 nul1(minind1) = 1;
 nur1(maxind1)=1;

 x = min(IP1)-1:(max(IP1)-min(IP1))/200:max(IP1)+1;
 
 
for j=1:length(IP1)
    
for i=1:length(x)
    
    deltal1(i) = abs( ((x(i)-IP1(j))/ epl1(j) ) * (1 / (1 + exp(100*((x(i)-IP1(j))) ))) )^lambda;
    deltal2(i) = abs( (((x(i)-IP1(j))-Noise)/ (epl1(j)) ) * (1 / (1 + exp(100*((x(i)-IP1(j))- Noise) ))) )^lambda;
    nulterm = (1-nul1(j))/nul1(j);
%   nulterm = 1;
    %deltal(i)=(abs((x(i)-IP1(j))/(epl1(j)*(1+exp(ls*(x(i)-IP1(j)))))))^lml1(j);
    %deltar(i)=(abs((x(i)-IP1(j))/(epr1(j)*(1+exp(-ls*(x(i))-IP1(j)))))^lmr1(j));
    deltar1(i) = abs( ((x(i)-IP1(j))/ epr1(j) ) * (1 / (1 + exp(-100*((x(i)-IP1(j))) ))))^lambda; 
    deltar2(i) = abs( (((x(i)-IP1(j))+ Noise)/ (epr1(j)) ) * (1 / (1 + exp(-100*((x(i)-IP1(j))+ Noise) ))))^lambda; 
    nurterm = (1-nur1(j))/nur1(j);
%   nurterm = 1;
    delta1(j,i)= 1/(1+ (nulterm * deltal1(i)) + (nurterm *deltar1(i)));
    delta2(j,i)= 1/(1+ (nulterm * deltal2(i)) + (nurterm *deltar2(i)));

end
%   figure(1); 
%   plot(x, delta');
%   axis([-5 5 0 1.2]);
%   hold on;
end


end