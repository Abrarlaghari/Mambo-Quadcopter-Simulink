function delta = PlottingDMFConEp (IP1, EP, ind , nu)
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

 nul1(1) = 1;
%nur1(3) = 1;
 nur1(maxind1)=1;
%epr(length(IP1)) = 1;
%Plotting first input

 x = min(IP1)-1:(max(IP1)-min(IP1))/100:max(IP1)+1;
 ls = 128;

for j=1:length(IP1)
    
for i=1:length(x)
    
    deltal(i) = abs( ((x(i)-IP1(j))/ epl1(j) ) * (1 / (1 + exp(100*((x(i)-IP1(j))) ))) )^4;
    nulterm = (1-nul1(j))/nul1(j);
    %deltal(i)=(abs((x(i)-IP1(j))/(epl1(j)*(1+exp(ls*(x(i)-IP1(j)))))))^lml1(j);
    %deltar(i)=(abs((x(i)-IP1(j))/(epr1(j)*(1+exp(-ls*(x(i))-IP1(j)))))^lmr1(j));
    deltar(i) = abs( ((x(i)-IP1(j))/ epr1(j) ) * (1 / (1 + exp(-100*((x(i)-IP1(j))) ))))^4; 
    nurterm = (1-nur1(j))/nur1(j);
    delta(j,i)= 1/(1+ (nulterm * deltal(i)) + (nurterm *deltar(i)));

end
%   figure(1); 
%   plot(x, delta');
%   axis([-5 5 0 1.2]);
%   hold on;
end


end