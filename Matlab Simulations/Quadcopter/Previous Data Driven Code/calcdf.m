% Function for calculating the distending Membership Function values at
% particulr value of x
function out = calcdf (x,params)
vl=params(1);
el=params(2);
ll=params(3);
vr=params(4);
er=params(5);
lr=params(6);
ls=params(7);
c=params(8);

fl=(((1-vl)/vl)*(((x-c)/(el*(1+exp(ls*(x-c))))^2)^(ll/2)));

fr=(((1-vr)/vr)*(((x-c)/(er*(1+exp(-ls*(x-c))))^2)^(lr/2)));
    
f= 1/(1+(fl+fr));

out = real (f);
end

