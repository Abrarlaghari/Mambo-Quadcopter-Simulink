x = -2:0.01:2;
epl=0.3;

nul=0.5;
nur=0.5;
nulterm = (1-nul)/nul;
nurterm = (1-nur)/nur;

for i=1:length(x)
    
    delta1(i) = abs( ((x(i))/ epl ))^2 * (1 / (1 + exp(100*((x(i))) )));
    delta12(i) = 1/(1+ (nulterm * delta1(i)));
    
        
    %3rd
    
    delta2(i) = abs( ((x(i))/ epl )^-2) * (1 / (1 + exp(-100*((x(i))) )));
    delta21(i) = 1/(1+ (nulterm * delta2(i)));
    
        
end

   figure(1);
%    subplot(1,2,1)
   xlim= [-1 1 0 2] ;
   plot(x,delta12);
   figure(2);
   plot(x, delta21);