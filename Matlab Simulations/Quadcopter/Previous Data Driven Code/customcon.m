function y = customcon(x) %#codegen
%PROBOR	Probabilistic OR.
%	Y = PROBOR(X) returns the probabilistic OR (also known
%	as the algebraic sum) of the columns of X. If X has two
%	rows such that X = [A; B], then Y = A + B - AB. If X has
%	only one row, then Y = X.
%
%	For example:
%	
%		x = (0:0.1:10);
%               figure('Name','Probabilistic OR','NumberTitle','off');
%               y1 = gaussmf(x, [0.5 4]);
%               y2 = gaussmf(x, [2 7]);
%		yy = probor([y1; y2]);
%		plot(x,[y1; y2; yy])

%	Copyright 1994-2017 The MathWorks, Inc. 
x(1,:);
x(2,:);
if size(x,1)<=1
    y = x;
    return
end
lm=3;
y = x(1,:);
for count = 2:size(x,1)
    %y(:) = y + x(count,:) - y.*x(count,:)
    y(:)=1/(1+(((1-x(count,:))/x(count,:))^lm+((1-y(:))/y(:))^lm)^(1/lm));
end


