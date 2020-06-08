function Meshgrid = customInference (Nogp, ModCentre, Rulelist)

Range = 1;                    % Defining Input Range ; Later make it custom
Ipgrid(:,1) = 0: 1/Nogp : Range;
Ipgrid(:,2) = 0: 1/Nogp : Range;

% Creating a Mesh
Meshgrid=[];
n=1;
% x = linspace(0,Range,Nogp);
% y = linspace(0,Range,numel(x))';
% [XX, YY] = meshgrid(x,y);
% Meshgrid(:,1) = XX(1,:);
% Meshgrid(:,2) = YY(:,1);

for i=1:length(Ipgrid(:,1))
    for j= 1:length(Ipgrid(:,2))
        Meshgrid(n,1) = Ipgrid (i,1);
        Meshgrid(n,2) = Ipgrid (j,2);
        n= n+1;
    end     
end

% For all grid points
for i=1:length(Meshgrid(:,1))

    X1 = Calculatedf(Meshgrid(i,1), ModCentre(:,1), ModCentre(:,4), ModCentre(:,5));
    X2 = Calculatedf(Meshgrid(i,2), ModCentre(:,2), ModCentre(:,4), ModCentre(:,5));
    
    for j=3:length(Rulelist(:,1))     % Evaluating Rule Firing Strengths
    W(j)= 1/(1+(((1-X1(Rulelist(j,1)))/X1(Rulelist(j,1)))^1+((1-X2(Rulelist(j,2)))/X2(Rulelist(j,2)))^1)^(1/1));
    end
    W(1) = X1(Rulelist(1,1));
    W(2) = X1(Rulelist(2,1));
    Sum1 = sum(W);
    Wn = W./(Sum1);
    Value=0;

    for k=1:length(Rulelist(:,3))
    Value = Value + Wn(k) * ModCentre(Rulelist(k,3),3);
    end
    
    Meshgrid(i,3) = Value;
end
% points2 = Nogp+1;
% xcor = reshape (Meshgrid(:,1), [points2,points2]);
% ycor = reshape (Meshgrid(:,2), [points2,points2]);
% zcor = reshape (Meshgrid(:,3), [points2,points2]);
% surface(xcor, ycor, zcor);

end



