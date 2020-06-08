function delta = PlottingSysDf (IP1)
%% Calculating the parameters of the input and ouput Membership Functions


% %%%First Input

epr1 = IP1;
nur1 = IP1;
epl1 = IP1;
nul1 = IP1;

% lml1 = [2 2 2 2];
% lmr1 = [2 2 2 2];

epl1(1) = 1;
nul1(1) = 1;

for i =1: length(IP1) - 1
    epr1(i) = (IP1(i+1) - IP1 (i))/2;
    nur1(i) = 0.5;
    epl1(i+1) = epr1(i);
    nul1(i+1) = 0.5;
end

epr1(length(IP1)) = 1;
nur1(length(IP1)) = 1;
% Plotting first input
x = min(IP1)-1:(max(IP1)-min(IP1))/100:IP1(length(IP1))+1;
ls = 500;

for j=1:length(IP1)
    
for i=1:length(x)
   
    deltal(i) = abs( ((x(i)-IP1(j))/ epl1(j) ) * (1 / (1 + exp(100*((x(i)-IP1(j))) ))) )^5 ;
    nulterm = (1-nul1(j))/nul1(j);
    
    %deltal(i)=(abs((x(i)-IP1(j))/(epl1(j)*(1+exp(ls*(x(i)-IP1(j)))))))^lml1(j);
    
    %deltar(i)=(abs((x(i)-IP1(j))/(epr1(j)*(1+exp(-ls*(x(i))-IP1(j)))))^lmr1(j));
    
    deltar(i) = abs( ((x(i)-IP1(j))/ epr1(j) ) * (1 / (1 + exp(-100*((x(i)-IP1(j))) ))))^5 ; 
   
    nurterm = (1-nur1(j))/nur1(j);
        
    delta(j,i)= 1/(1+ (nulterm * deltal(i)) + (nurterm *deltar(i)));

end
%   figure(1); 
%   plot(x, delta');
%   hold on; 
end


end