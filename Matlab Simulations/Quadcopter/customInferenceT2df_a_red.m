function Meshgrid = customInferenceT2df_a_red (Nogp, Centres,GCentres, Ep, nu, Rulelist,GRulelist, Noise)
disp("Running");
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
mm=size(Centres,1);
% For all grid points
for i=1:length(Meshgrid(:,1))
    
    WL=[];
    WU=[];
    
    X1 = CalculateT2df_a(Meshgrid(i,1), Centres(:,1), Ep(1:mm), nu(1:mm), Noise);
    X2 = CalculateT2df_a(Meshgrid(i,2), Centres(:,2), Ep(1:mm), nu(1:mm), Noise);
    
    
    %for group points
    nn=1;
    X1_new=[]; X2_new=[];
    
    for k=1:2:size(GCentres,1)
    X1_new1 = CalculateT2df_a_red(Meshgrid(i,1), GCentres(k:k+1,1), Ep(mm+nn), nu(mm+nn), Noise);
    X2_new1 = CalculateT2df_a_red(Meshgrid(i,2), GCentres(k:k+1,2), Ep(mm+nn), nu(mm+nn), Noise);
    X1_new = [X1_new;X1_new1];
    X2_new = [X2_new;X2_new1];
    nn=nn+1;
    end
    
    for j=1:length(Rulelist(:,1))     % Evaluating Rule Firing Strengths
    WL(j,1)= 1/(1+(((1-X1(Rulelist(j,1),1))/X1(Rulelist(j,1),1))^1+((1-X2(Rulelist(j,2),1))/X2(Rulelist(j,2),1))^1)^(1/1));
    WU(j,1)= 1/(1+(((1-X1(Rulelist(j,1),2))/X1(Rulelist(j,1),2))^1+((1-X2(Rulelist(j,2),2))/X2(Rulelist(j,2),2))^1)^(1/1));
    end
    
    %Firing strength for Group Points
    
    for j=1:length(GRulelist(:,1))     
    WL_new(j,1)= 1/(1+(((1-X1_new(GRulelist(j,1),1))/X1_new(GRulelist(j,1),1))^1+((1-X2_new(GRulelist(j,2),1))/X2_new(GRulelist(j,2),1))^1)^(1/1));
    WU_new(j,1)= 1/(1+(((1-X1_new(GRulelist(j,1),2))/X1_new(GRulelist(j,1),2))^1+((1-X2_new(GRulelist(j,2),2))/X2_new(GRulelist(j,2),2))^1)^(1/1));
    end
    
    WL = [WL; WL_new];
    WU = [WU; WU_new];
  
%   WL(1,1) = X1(Rulelist(1,1),1);
%   WL(2,1) = X1(Rulelist(2,1),1);     
%   WU(1,1) = X1(Rulelist(1,1),2);
%   WU(2,1) = X1(Rulelist(2,1),2);
    
    Sum1L = sum(WL);
    WnL = WL./(Sum1L);
    
    Sum1U = sum(WU);
    WnU = WU./(Sum1U);
    
    
    
    
    ValueL=0;
    for k=1:size(Rulelist,1)
    ValueL = ValueL + WnL(k) * (Centres(Rulelist(k,3),3));
    end
    
    % finding distance of the two points from meshgrid current point
    n=0;
    l=0;
    for j=(k+1):k+size(GRulelist,1)
    UU=0;
    dd=0;
    for m=n+1:n+2 % for two
        distt = sqrt((Meshgrid(i,1)-GCentres(m,1))^2 + (Meshgrid(i,2)-GCentres(m,2))^2);
        dis(m) = 1/distt;
        UU = UU + ( dis(m) * GCentres(m,3));   
        dd = dd+ dis(m);
    end
    l=l+1;
    Valuered(l) = UU/dd;
    ValueL = ValueL + (WnL(j) * Valuered(l)) ;
    n=n+2;
    end
    Meshgrid(i,3) = ValueL;
    
%     if (Meshgrid(i,1)==0.96 && Meshgrid(i,2)==0.31)
%         keyboard;          
%     end
%     



    ValueU=0;
    for k=1:length(Rulelist(:,3))
    ValueU = ValueU + WnU(k) * (Centres(Rulelist(k,3),3));
    end
    l=0;
    for j=(k+1):k+size(GRulelist,1)
    l=l+1;
    ValueU = ValueU + (WnU(j) * Valuered(l)) ;
    end
     
%   ValueU = ValueU + (WnU(end) * Valuered) ;
    
    Meshgrid(i,4) = ValueU;
    
    
    
    
    
    
    ValueC=0;
    for k=1:length(Rulelist(:,3))
    ValueC = ValueC + ((WnL(k) * (Centres(Rulelist(k,3),3)) + WnU(k) * (Centres(Rulelist(k,3),3)))/2);
    end
    
    l=0;
    for j=(k+1):k+size(GRulelist,1)
    l=l+1;
    ValueC = ValueC + (((WnU(j) * Valuered(l))+(WnL(j) * Valuered(l)))/2) ;
    end
   
%  ValueC = ValueC + (((WnU(end) * Valuered)+(WnL(end) * Valuered))/2) ;
   
    Meshgrid(i,5) = ValueC;
        
    
end
points2 = Nogp+1;
% xcor = reshape (Meshgrid(:,1), [points2,points2]);
% ycor = reshape (Meshgrid(:,2), [points2,points2]);
% zcor = reshape (Meshgrid(:,3), [points2,points2]);
% figure(20);
% surface(xcor, ycor, zcor);

end



