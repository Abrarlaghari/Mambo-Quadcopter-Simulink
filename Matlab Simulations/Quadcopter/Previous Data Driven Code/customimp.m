function y = customimp(x1,x2) %#codegen
if nargin == 1
    % x1 assumed to be non-empty column vector or matrix.    
    minVal = zeros(1,size(x1,2));
    y = ones(1,size(x1,2));    
 
    for i = 1:size(x1,1)
        y = max(minVal,x1(i,:));
    end
else    
    % x1 and x2 assumed to be non-empty matrices.                  
    minVal = zeros(1,size(x1,2));
    y = zeros(size(x1));
  
    for i = 1:size(x1,1)
        y(i,:) = max(minVal,x1(i,:));
    end    
end