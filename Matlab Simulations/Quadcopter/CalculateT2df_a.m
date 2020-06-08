function Val = CalculateT2df_a(Point, Centres,EP, nu, Noise)
% mu1=0.3526;
% mu2=0.3526;
% mu1r= (1-mu1)./(mu1);
% mu2r= (1-mu2)./(mu2);
% e1=.33; 
l1=4;
l2=4;
ls=100;

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

[maxx, ~] = max(Centres);
[minn, ~] = min(Centres);
 nul1(Centres==minn) = 1;
 nur1(Centres==maxx)=1;


for i= 1: length(Centres)
 mul= (1-nul1(i))./(nul1(i));
 mur= (1-nur1(i))./(nur1(i));
    
 %dist1 = 1/(1+mu1r*((abs((Point-Centres(i))/e1)^l1)));
 deltal1 = abs(((Point-Centres(i))/ epl1(i) ) * (1 / (1 + exp(ls*((Point-Centres(i)))))))^l1;
 deltar1 = abs(((Point-Centres(i))/ epr1(i) ) * (1 / (1 + exp(-ls*((Point-Centres(i)))))))^l1;
 delta1 = 1/(1+ (mul * deltal1) + (mur *deltar1));
 
%  e2=e1;

%dist2 = .8/(1+mu2r*((abs((Point-Centres(i))/e2)^l2)));
 deltal2 = abs((((Point-Centres(i))- Noise)/ epl1(i) ) * (1 / (1 + exp(ls*(((Point-Centres(i))- Noise))))))^l2;
 deltar2 = abs((((Point-Centres(i))+ Noise)/ epr1(i) ) * (1 / (1 + exp(-ls*(((Point-Centres(i))+ Noise))))))^l2;
 delta2 = 1/(1+ (mul * deltal2) + (mur *deltar2));

Val(i,1) = delta1;
Val(i,2) = delta2;
end