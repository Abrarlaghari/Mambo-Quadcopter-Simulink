function X = Calculatedf (Point1, Centres, Epsilon, nu)

% nu = 0.5;
lambda = 4;
ls = 128;

for l=1: length(Centres)
    
    fl = (((1-nu(l))/nu(l))*abs((((Point1-Centres(l))/(Epsilon(l)*(1+exp(ls*(Point1-Centres(l))))))^(lambda))));
    fr = (((1-nu(l))/nu(l))*abs((((Point1-Centres(l))/(Epsilon(l)*(1+exp(-ls*(Point1-Centres(l))))))^(lambda))));
    f = 1/(1+(fl+fr));
    X(l) = f;     
    
end

end