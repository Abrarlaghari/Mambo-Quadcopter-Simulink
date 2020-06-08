%% Data Driven based Fuzzy Control %%
%% Extracting the Simulation Data and plotting the surface %%
clc; close all; clf;
% sim('ball.mdl');
%sim('sltank1');
sim('vehicle_lateral_control');
TT1 = [InputError.Time   InputError.Data];
TT11 = [InputError1.Time   InputError1.Data];
TT2 = [InputPositionDot.Time   InputPositionDot.Data];
TT22 = [InputPositionDot1.Time   InputPositionDot1.Data];
TO = [outputFC.Time outputFC.Data];
TT3 = [TT1 TT11 TT2 TT22 TO];
TT3 (:,3)= [];
TT3(:,4) = [];
TT3 (:,5)= [];
TT3(:,6) = [];
r = size(TT3,1);
% for i=1:r 
%    if (abs (TT3(i,2))< .0001 || TT3(i,1)<0.5)
%         TT3(i,:)= 0;
%    end
% end
TT3(~any(TT3,2),:) = [];
x = linspace(min(TT3(:,2)), max(TT3(:,2)),500);
y = linspace(min(TT3(:,4)),max(TT3(:,4)), numel(x))';
% For third input use u and v for fourth
u = linspace(min(TT3(:,3)),max(TT3(:,3)), numel(x)');
v = linspace(min(TT3(:,5)),max(TT3(:,5)), numel(x)');

[XX, YY] = meshgrid(x,y);
F = scatteredInterpolant(TT3(:,2), TT3(:,4), TT3(:,6),'natural');
ZZ = F(XX,YY) ;
% ZZ(ZZ>5) = 5;
% ZZ(ZZ<-5) = -5;
%  mesh(XX,YY,ZZ);
surfdata1=surface(XX,YY,ZZ);
x1 = surfdata1.XData;
y1 = surfdata1.YData;
z1 = surfdata1.ZData;

% Surface for third input
[XX1, YY1] = meshgrid(x,u);
F1 = scatteredInterpolant(TT3(:,2), TT3(:,3), TT3(:,6),'natural');
ZZ1 = F1(XX1,YY1) ;
surfdata2=surface(XX1,YY1,ZZ1);
x_2 = surfdata2.XData;
u1 = surfdata2.YData;
% z12 = surfdata2.ZData;

% Surface for fouth input
[XX2, YY2] = meshgrid(x,v);
F2 = scatteredInterpolant(TT3(:,2), TT3(:,5), TT3(:,6),'natural');
ZZ2 = F2(XX2,YY2) ;
surfdata3=surface(XX2,YY2,ZZ2);
x3 = surfdata3.XData;
v1 = surfdata3.YData;
% z3 = surfdata3.ZData;

%Normalize X1 and Y1    
x11 = (x1 - min(min(x1))) / (max(max(x1))-min(min(x1)));
y11 = (y1 - min(min(y1))) / (max(max(y1))-min(min(y1)));
u11 = (u1 - min(min(u1))) / (max(max(u1))-min(min(u1)));
v11 = (v1 - min(min(v1))) / (max(max(v1))-min(min(v1)));


%Normalizing TT4(:,:) for searching input 3 and input 4
TT4 = TT3;
TT4(:,2) = (TT4(:,2) - min(TT4(:,2))) / (max(TT4(:,2))-min(TT4(:,2)));
TT4(:,4) = (TT4(:,4) - min(TT4(:,4))) / (max(TT4(:,4))-min(TT4(:,4)));
TT4(:,3) = (TT4(:,3) - min(TT4(:,3))) / (max(TT4(:,3))-min(TT4(:,3)));
TT4(:,5) = (TT4(:,5) - min(TT4(:,5))) / (max(TT4(:,5))-min(TT4(:,5)));
%% Extracting Information from input data surface  and extracting points of interest%%
%Creating Input Database
GenT_1 = [x1 ; y1 ; z1; u1'; v1'];
rowgt_1 = 0;
for t=1:5
row_1 =1;
    for i=1:numel(x)
    rowgt_1 = rowgt_1 + 1;
        for k=1:numel(x)
        GenT_12(row_1,t) = GenT_1(rowgt_1,k);
        row_1 = row_1 + 1;
        end
    end
end

% Normalizing the Inputs only (not output)
GenT_12(:,1) = (GenT_12(:,1) - min(GenT_12(:,1))) / (max(GenT_12(:,1))-min(GenT_12(:,1)));
GenT_12(:,2) = (GenT_12(:,2) - min(GenT_12(:,2))) / (max(GenT_12(:,2))-min(GenT_12(:,2)));
GenT_12(:,4) = (GenT_12(:,4) - min(GenT_12(:,4))) / (max(GenT_12(:,4))-min(GenT_12(:,4)));
GenT_12(:,5) = (GenT_12(:,5) - min(GenT_12(:,5))) / (max(GenT_12(:,5))-min(GenT_12(:,5)));
GenT_12 = sortrows(GenT_12,1);
GenT_12 = fix(GenT_12*10^3)/10^3;

% Points of interest

Points_1 =  [0.01 0.99  .5  .5   .01 .99 .5];       % Points_1 =[0.01 0.99 .01 .99 .5  .5  .01 .99 .5];
Points_2 =  [0.01 0.99 .01 .99   .5  .5  .5];       % Points_2 =[0.01 0.99 .99 .01 .01 .99  .5  .5 .5];
Points_4 =  [0.01 0.99 .5 .99   .01  .5  .5];         
Points_5 =  [0.01 0.99 .01 .5   .5  .99  .5];         

[max_5, ind_5] = max(Points_1);
[max_6, ind_6] = max(Points_2);

[max_9, ind_9]   = max(Points_4);
[max_10, ind_10] = max(Points_5);

% Extracing the points
for i=1:length(Points_1)
    [row_1(i), col_1] = find(((Points_1(i)-GenT_12(:,1))<.0001) & ((Points_2(i)-GenT_12(:,2))<.0001),1,'first');
end

% Creating the centre points

for i=1:length(row_1)
CentrePoints(i,:) = GenT_12(row_1(i),:);
end 
ModCentre = CentrePoints;
[max_7, ind_7] = max(ModCentre(:,3));

% Defining the Epsilon for boundary conditions 

Epsilon1 = 0.33  * ones(4,1);
Epsilon2 = 0.33 * ones(length(ModCentre)-4,1);
Epsilon = [Epsilon1;Epsilon2];

%% Selection of nu values for initial points

k1= 100;
lambda = 4;

for i=1:length(ModCentre)

    for j=1:length(ModCentre)
        
        if (j~=i)
            d(i,j) = (((ModCentre(i,1)- ModCentre(j,1))./Epsilon(j))^lambda) + (((ModCentre(i,2)- ModCentre(j,2))./Epsilon(j))^lambda)+(((ModCentre(i,4)- ModCentre(j,4))./Epsilon(j))^lambda)+(((ModCentre(i,5)- ModCentre(j,5))./Epsilon(j))^lambda) ; 
            nu(i,j) = (1./ (1 + (((k1* abs(1))-1)./d(i,j)))) ;                  %ModCentre(j,3)  
        end
            nu(i,i) = 10000;
            
    end
    
end
nu111 = nu;
nu = min(nu);
% nu(9)= 0.044;
%   nu = min(nu,[],2);
% nu = 0.5 * ones(length(Epsilon),1);
% Epsilon = 0.33  * ones(length(ModCentre),1);
% CentrePoint = [Centre1D Centre2D Centre3D];

%% Starting Loop for iterations
 deltaL=0;
 reducenu = 0;
 points1 = [];
 EpsilonDelta = [];
 NuDelta =[];
 for looprep = 1:15
      close all;
      clf;
%  CentrePoint = [CentrePoint ; GenT25(points1,:)];  % Adding point from simulated surface of test data after each iteration
   
%% Adding points and Epsilon

    ModCentre = [ModCentre; points1]; 
    ModCentreb = ModCentre; 
    Epsilon = [Epsilon; EpsilonDelta];
    nu = [nu NuDelta];
%% Calculating the Epsilon Parameter of each MF
    [Centre1D, inds2] = unique(ModCentre(:,1),'rows','stable');
    [Centre2D, inds3] = unique(ModCentre(:,2),'rows','stable');
    [Centre3D, inds4] = unique(ModCentre(:,3),'rows','stable');
    [Centre4D, inds5] = unique(ModCentre(:,4),'rows','stable');
    [Centre5D, inds6] = unique(ModCentre(:,5),'rows','stable');
     
    Ep1 = Epsilon(inds2);
    Ep2 = Epsilon(inds3);
    Ep3 = Epsilon(inds4);
    Ep4 = Epsilon(inds5);
    Ep5 = Epsilon(inds6);
     
    nu1 = nu(inds2);
    nu2 = nu(inds3);
    nu3 = nu(inds4);
    nu4 = nu(inds5);
    nu5 = nu(inds6);
           
    dd1 = PlottingDMFConEp(Centre1D, Ep1, ind_5  , nu1);
    dd2 = PlottingDMFConEp(Centre2D, Ep2, ind_6  , nu2);
    dd3 = PlottingDMFConEp(Centre3D, Ep3, ind_7  , nu3);
    dd4 = PlottingDMFConEp(Centre4D, Ep4, ind_9  , nu4);
    dd5 = PlottingDMFConEp(Centre5D, Ep5, ind_10 , nu5);
    
x = min(Centre1D)-1:(max(Centre1D)-min(Centre1D))/100:max(Centre1D)+1;
figure(1);
 for j=1: size(dd1,1)
 plot(x,dd1(j,:));
 axis([0 1 0 1]);
 hold on;
 end
 x = min(Centre2D)-1:(max(Centre2D)-min(Centre2D))/100:max(Centre2D)+1;
figure(2);
 for j=1: size(dd2,1)
 plot(x ,dd2(j,:));
 axis([0 1 0 1]);
 hold on;
 end
x = min(Centre3D)-1:(max(Centre3D)-min(Centre3D))/100:max(Centre3D)+1; 
figure(3);
 for j=1: size(dd3,1)
 plot(x ,dd3(j,:));
 axis([-1 1 0 1]);
 hold on;
 end
 
 x = min(Centre4D)-1:(max(Centre4D)-min(Centre4D))/100:max(Centre4D)+1;
figure(14);
 for j=1: size(dd4,1)
 plot(x,dd4(j,:));
 axis([0 1 0 1]);
 hold on;
 end
 x = min(Centre5D)-1:(max(Centre5D)-min(Centre5D))/100:max(Centre5D)+1;
figure(15);
 for j=1: size(dd5,1)
 plot(x,dd5(j,:));
 axis([0 1 0 1]);
 hold on;
 end
 
%% Custom Inference Engine
Nogp = 100;  % Number of grid points
for i=1:length(ModCentre) 
   RuleList(i,1) = i;
   RuleList(i,2) = i;
   RuleList(i,3) = i;
end
Meshgrid = customInference(Nogp, [ModCentre(:,1:3) Epsilon nu'], RuleList(:,1:3));
points2 = Nogp+1;
xcor = reshape (Meshgrid(:,1), [points2,points2]);
ycor = reshape (Meshgrid(:,2), [points2,points2]);
zcor = reshape (Meshgrid(:,3), [points2,points2]);
figure(4);
Consurf = surface( xcor,ycor, zcor);
x2 = Consurf.XData;
y2 = Consurf.YData;
z2 = Consurf.ZData;

%% Generating and plotting the Error surface  

%Generating database
GenT = [x2 ; y2 ; z2];
rowgt = 0;
for t=1:3
row =1;
    for i=1:size(x2,1)
    rowgt = rowgt + 1;
        for k=1:size(x2,1)
        GenT2(row,t) = GenT(rowgt,k);
        row = row+1;
        end
    end
end

min1 = min(x11(1,:));
min2 = min(x2(1,:));
    if(min1 ~= min2)
    x11(x11==min1)= min2;
    end
    
min3 = min(y11(:,1));
min4 = min(y2(:,1));
    if(min3 ~= min4)
    y11(y11==min3)= min4;
    end

% Truncating the decimal part
x11 = fix(x11*10^2)/10^2;
y11 = fix(y11*10^2)/10^2;
z1 = fix(z1*10^2)/10^2;
GenT2 = fix(GenT2*10^2)/10^2;
    
for i=1:length(GenT2)
    [raw1, colind6]=find(x11==GenT2(i,1),1,'first');
    if (isempty(colind6))
       [raw1, colind6]=find((x11-GenT2(i,1))<.01,1,'last');    % Must be checked   
    end
    [rowind6 , raw2]=find(y11==GenT2(i,2),1,'first');
    if (isempty(rowind6))
       [rowind6, raw2]=find((y11-GenT2(i,2))<.01,1,'last');    % Must be checked   
    end
    errz(i)=(z1(rowind6, colind6) - GenT2(i,3));
end

% Forming the z for error

pointerrz = 1;

for i=1:size(x2,1)  % same number of rows as x
    
    for j =1:size(x2,2)  % same colums of errz as x  
        z3(i,j) = errz(pointerrz);
        pointerrz = pointerrz + 1;
    end
    
end

figure(5);
errorsurface = surface(x2,y2,z3);
x4 = errorsurface.XData;
y4 = errorsurface.YData;
z4 = errorsurface.ZData;

% Plotting the error plus generated surface == original (required surface)
z33 = z2 + z3 ;
figure(6);
surface(x2,y2,z33);
 
%% Searching the max error points for feedback
GenT4 = [x4 ; y4 ; z4];
rowgt4 = 0;
for t=1:3
row4 =1;
    for i=1:size(x2,1)
        rowgt4 = rowgt4 + 1;
        for k=1:size(x2,2)
        GenT24(row4,t) = GenT4(rowgt4,k);
        row4 = row4  +1;
        end
    end
end
[maxerr, errindx] = max(abs( GenT24(:,3)));
 %%  Repairing the surface at Max Error points
% 
% % Calculating strength of rules at maxx error point
%     X1 = Calculatedf(GenT24(errindx,1), ModCentre(:,1), Epsilon, nu);
%     X2 = Calculatedf(GenT24(errindx,2), ModCentre(:,2), Epsilon, nu);
%     for j=1:length(RuleList(:,1))     % Evaluating Rule Firing Strengths
%     W(j)= 1/(1+(((1-X1(RuleList(j,1)))/X1(RuleList(j,1)))^1+((1-X2(RuleList(j,2)))/X2(RuleList(j,2)))^1)^(1/1));
%     end
%     Sum1 = sum(W);
%     Wn = W./(Sum1);
%     Value=0;
%     for k=1:length(RuleList(:,3))
%     Value(k) = Wn(k) * ModCentre(RuleList(k,3),3);
%     end
%     
% % Calculating the Distance Measure
% % nu = 0.5;
% lambda = 1;
% 
% for i=1:length(ModCentre(:,1))
%     nuR = ((1-nu(i))/nu(i));
%     xx = ((GenT24(errindx,1) - ModCentre(i,1))/Epsilon(i))^lambda; 
%     yy = ((GenT24(errindx,2) - ModCentre(i,2))/Epsilon(i))^lambda; 
%     alpha(i) = ModCentre(i,3) /(1 + (nuR * (xx + yy )));
% end
%    sum_alpha = sum(alpha);
%    
%  % Place here the condition for split of adding a new MF point or reducing nu
%    
%    
%    
% % Reducing/increasing the nu of maximum error contributors (Selecting first two)  
%    reducenu = 1;
%   [contr, indxcont] = max(abs(alpha));
%   
% %   if (alpha(indxcont)< 0 )
%     if(abs(maxerr) > .2 && nu(indxcont) > .1) 
%         nu(indxcont) = nu(indxcont)/2; 
% %   else
% %       nu(indxcont) = nu(indxcont)+ nu(indxcont)/4;     
%     end
   

%% Searching the point in the surface formed by Test Data

% Creating database from surface points
GenT5 = [x11 ; y11 ; z1 ; u11 ; v11];
rowgt5 = 0;
for t=1:5
row5 =1;
    for i=1:500
    rowgt5 = rowgt5 + 1;
        for k=1:500
        GenT25(row5,t) = GenT5(rowgt5,k);
        row5 = row5  +1;
        end
    end
end

% Searching in GenT25
rowind2=[];
   
rowind1 = find(abs(GenT25(:,1 ) - ( GenT24(errindx,1))) <=.02);
    
    if(~isempty(rowind1))
        
          for k=1:length(rowind1)
           
               TF = find(abs(GenT25(rowind1(k),2) - ( GenT24(errindx,2))) <=.01, 1, 'first') ;         % correct it
            
                if (fix(GenT24(errindx,1)*10^2)/10^2 ==0.82 && fix(GenT24(errindx,2)*10^2)/10^2==0.58)                                 % special case of missing data
                    TF = find(abs(GenT25(rowind1(k),2) - ( GenT24(errindx,2))) <=.01, 1, 'first') ;      
                end
                        
                    if (TF==1)
                        rowind2 = rowind1(k); 
                        break;
                    end
           
          end

                 
    end

 maxerror(looprep) = maxerr;
 if (reducenu)
    points1 = []; 
 else 
    points1 = GenT25(rowind2,:) ;
     
 end

 % Finding corrresponding values for input 3 and input 4
  [row_3, col_3] = find((abs(TT4(:,2)- points1(:,1))<.01) & abs((TT4(:,4)- points1(:,2))<.01),1,'first');
  if (isempty(row_3))
  [row_3, col_3] = find((abs(TT4(:,2)- points1(:,1))<.1) & abs((TT4(:,4)- points1(:,2))<.1),1,'first');
  end
  if (isempty(row_3))
  [row_3, col_3] = find((abs(TT4(:,2)- points1(:,1))<.2) & abs((TT4(:,4)- points1(:,2))<.5),1,'first');
  end
    if (isempty(row_3))
  [row_3, col_3] = find((abs(TT4(:,2)- points1(:,1))<.2) & abs((TT4(:,4)- points1(:,2))<.9),1,'first');
  end
 points1(:,4)= TT4(row_3,3);
 points1(:,5)= TT4(row_3,5);
 
 %modified up % original starts here
 figure(5);
 surface(x2,y2,z3);
 hold on;
 xi = GenT24(errindx,1);
 yi = GenT24(errindx,2);
 zi = GenT24(errindx,3);
 scatter3(xi,yi,zi,'filled');
%  
%% Calculating the nu of new point based on minimum influence to the sorrunding points

k2 = 20;
lambda = 4;
    for j=1:length(ModCentre)
         d1(j) = ((( ModCentre(j,1)- points1(1))./Epsilon(j))^lambda) + (((ModCentre(j,2)- points1(2))./Epsilon(j))^lambda); 
         nu_point(j) = (1./ (1 + (((k2* abs(points1(3)))-1)./d1(j))));  
    end 
NuDelta = min(nu_point);
if (NuDelta < 0.001)
   NuDelta = 0.001 ;
end
EpsilonDelta = 0.33;
figure(7);plot(maxerror);
  end

  
 %% Denormalizing the Inputs 
  XcorRange = max(max(x1))-min(min(x1));
  Nxcor = (x2*XcorRange) - max(max(x1)); 
  YcorRange = max(max(y1))-min(min(y1));
  Nycor = (y2*YcorRange) - max(max(y1)); 
  GenT6 = [Nxcor;Nycor;zcor];
  rowgt6 = 0;
for t=1:3
 row6 =1;
    for i=1:Nogp+1
    rowgt6 = rowgt6 + 1;
        for k=1:Nogp+1
        GenT26(row6,t) = GenT6(rowgt6,k);
        row6 = row6  +1;
        end
    end
end
GenT261 = GenT26(:,1); 
GenT262 = GenT26(:,2);
GenT263 = GenT26(:,3);
  
  
  
   
  
  
  
  
  
  