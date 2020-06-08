Range = 1;                    % Defining Input Range ; Later make it custom
Ipgrid(:,1) = 0: 1/Nogp : Range;
Ipgrid(:,2) = 0: 1/Nogp : Range;
% Creating a Mesh
Meshgrid=[];
n=1;
for i=1:length(Ipgrid(:,1))
    for j= 1:length(Ipgrid(:,2))
        Meshgrid(n,1) = Ipgrid (i,1);
        Meshgrid(n,2) = Ipgrid (j,2);
        n= n+1;
    end     
end
Centres= ModCentre;
Ep = Epsilon;
Rulelist= RuleList;
nu = nu;
% For all grid points
for i=1:length(Meshgrid(:,1))

    X1 = CalculateT2df_a(Meshgrid(i,1), Centres(:,1), Ep, nu, Noise);
    X2 = CalculateT2df_a(Meshgrid(i,2), Centres(:,2), Ep, nu, Noise);
 
    for j=1:length(Rulelist(:,1))     % Evaluating Rule Firing Strengths
    WL(j,1)= 1/(1+(((1-X1(Rulelist(j,1),1))/X1(Rulelist(j,1),1))^1+((1-X2(Rulelist(j,2),1))/X2(Rulelist(j,2),1))^1)^(1/1));
    WU(j,1)= 1/(1+(((1-X1(Rulelist(j,1),2))/X1(Rulelist(j,1),2))^1+((1-X2(Rulelist(j,2),2))/X2(Rulelist(j,2),2))^1)^(1/1));
    end
%     WL(1,1) = X1(Rulelist(1,1),1);
%     WL(2,1) = X1(Rulelist(2,1),1);
%     WU(1,1) = X1(Rulelist(1,1),2);
%     WU(2,1) = X1(Rulelist(2,1),2);
    
    Sum1L = sum(WL);
    WnL = WL./(Sum1L);
    Sum1U = sum(WU);
    WnU = WU./(Sum1U);
    ValueL=0;
    for k=1:length(Rulelist(:,3))
    ValueL = ValueL + WnL(k) * (Centres(Rulelist(k,3),3));
    end
    Meshgrid(i,3) = ValueL;
    
    
    ValueU=0;
    for k=1:length(Rulelist(:,3))
    ValueU = ValueU + WnU(k) * (Centres(Rulelist(k,3),3));
    end
    Meshgrid(i,4) = ValueU;
    ValueC=0;
    for k=1:length(Rulelist(:,3))
    ValueC = ValueC + ((WnL(k) * (Centres(Rulelist(k,3),3)) + WnU(k) * (Centres(Rulelist(k,3),3)))/2);
    end
    Meshgrid(i,5) = ValueC;

end
points2 = Nogp+1;
xcor = reshape (Meshgrid(:,1), [points2,points2]);
ycor = reshape (Meshgrid(:,2), [points2,points2]);
zcor = reshape (Meshgrid(:,3), [points2,points2]);
surface(xcor, ycor, zcor);
