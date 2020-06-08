% Frank Operator Case
p=.5000;
q=.5000;
r= .2500;

for t=0:.01:0.99
    s = t/(1-t);
    cal = (log (1+ (((s^p - 1)*(s^q - 1))/(s-1))) )/ (log(s));
    
    if (abs(cal - r)<0.001)
    TT=t;
    break;
    end
end

% for t=0.5:.01:0.99
%     s = t/(1-t);
%     cal = (log (1+ (((s^p - 1)*(s^q - 1))/(s-1))) )/ (log(s));
%     
%     if (abs(cal - r)<0.001)
%     TT=t;
%     break;
%     end
% end
