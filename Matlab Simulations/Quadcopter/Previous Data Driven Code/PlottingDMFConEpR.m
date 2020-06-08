function delta = PlottingDMFConEpR (IP1, EP, min1 ,max1)
%% Calculating the parameters of the input and ouput Membership Functions
% %%%First Input
% 
%     epr1 = IP1;
%     nur1 = IP1;
%     epl1 = IP1;
%     nul1 = IP1;
% lml1 = [2 2 2 2];
% lmr1 = [2 2 2 2];
% epl(1) = 1;

Range = max1 - min1;
pointer=1;
for i= 2: 2: length(EP)
   epr1(pointer) = EP(i);
   nur1(pointer) = 0.5;
   pointer = pointer + 1;
end

pointerr=1;
for i= 1: 2: length(EP)-1
   epl1(pointerr) = EP(i);
   nul1(pointerr) = 0.5;
   pointerr = pointerr + 1;
end


[maxx, maxind1] = max(IP1);
nul1(1) = 1;
nur1(maxind1) = 1;
 
%epr(length(IP1)) = 1;
%Plotting first input

x = min(IP1)-1:(max(IP1)-min(IP1))/100:max(IP1)+1;
ls = 500;

for j=1:length(IP1)
    
for i=1:length(x)
   
   
    deltal(i) = abs( ((((x(i)-min1)/Range)-IP1(j))/ epl1(j) ) * (1 / (1 + exp(100*((((x(i)-min1)/Range)-IP1(j))) ))) )^2 ;
    nulterm = (1-nul1(j))/nul1(j);
    
       %deltal(i)=(abs((x(i)-IP1(j))/(epl1(j)*(1+exp(ls*(x(i)-IP1(j)))))))^lml1(j);
       %deltar(i)=(abs((x(i)-IP1(j))/(epr1(j)*(1+exp(-ls*(x(i))-IP1(j)))))^lmr1(j));
    
    deltar(i) = abs( ((((x(i)-min1)/Range)-IP1(j))/ epr1(j) ) * (1 / (1 + exp(-100*((((x(i)-min1)/Range)-IP1(j))) ))))^2; 
   
    nurterm = (1-nur1(j))/nur1(j);
        
    delta(j,i)= 1/(1+ (nulterm * deltal(i)) + (nurterm *deltar(i)));

end
%   figure(1); 
%   plot(x, delta');
%   axis([-5 5 0 1.2]);
%   hold on; 
end


end