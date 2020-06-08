% Function for calculating the distending Membership Function values at
% particulr value of x
function out = calcdfs (x,params)

v=params(1);
e=params(2);
l=params(3);
c=params(4);

f= 1/(1+((1-v)/v)*((((x-c)/e)^2)^(l/2)));

out = real (f);
end


