%% Data Driven based Fuzzy Control %%
%% Extracting the Simulation Data and plotting the surface %%
clc; close all; clf;
% sim('ball.mdl');
sim('sltank1');
TT1 = [InputError.Time   InputError.Data];
TT2 = [InputPositionDot.Time   InputPositionDot.Data];
TO = [outputFC.Time outputFC.Data];
TT3 = [TT1 TT2 TO];
TT3 (:,3)= [];
TT3(:,4) = [];
r = size(TT3,1);
% for i=1:r 
%    if (abs (TT3(i,2))< .0001 || TT3(i,1)<0.5)
%         TT3(i,:)= 0;
%    end
% end
TT3(~any(TT3,2),:) = [];
x = linspace(min(TT3(:,2)), max(TT3(:,2)),300);
y = linspace(min(TT3(:,3)),max(TT3(:,3)), numel(x))';
[XX, YY] = meshgrid(x,y);
F = scatteredInterpolant(TT3(:,2), TT3(:,3), TT3(:,4));
ZZ = F(XX,YY) ;
% ZZ(ZZ>5) = 5;
% ZZ(ZZ<-5) = -5;
%  mesh(XX,YY,ZZ);
surfdata=surface(XX,YY,ZZ);
x1 = surfdata.XData;
y1 = surfdata.YData;
z1 = surfdata.ZData;

%Normalize X1 and Y1    
x11 = (x1 - min(min(x1))) / (max(max(x1))-min(min(x1)));
y11 = (y1 - min(min(y1))) / (max(max(y1))-min(min(y1)));

%% Extracting Information from input data surface  and extracting points of interest%%
%Creating Input Database
GenT_1 = [x1 ; y1 ; z1];
rowgt_1 = 0;
for t=1:3
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
GenT_12 = sortrows(GenT_12,1);
GenT_12 = fix(GenT_12*10^3)/10^3;

% Points of interest
Points_1 =[0.01 0.99 .01 .99 .5  .5  .01 .99 .5];
Points_2 =[0.01 0.99 .99 .01 .01 .99  .5  .5 .5];  

[max_5, ind_5] = max(Points_1);
[max_6, ind_6] = max(Points_2);
% Extracing the points
for i=1:length(Points_1)
    [row_1(i), col_1]=find((Points_1(i)-GenT_12(:,1))<.0001 & (Points_2(i)-GenT_12(:,2))<.0001,1,'first');
end

% Creating the centre points

for i=1:length(row_1)
CentrePoints(i,:) = GenT_12(row_1(i),:);
end 
ModCentre = CentrePoints;
[max_7, ind_7] = max(ModCentre(:,3));

% Defining the Epsilon for boundary conditions 

Epsilon1 = 0.33  * ones(4,1);
Epsilon2 = 0.165 * ones(length(ModCentre)-4,1);
Epsilon = [Epsilon1;Epsilon2];
nu = 0.5 * ones(length(Epsilon),1);
% Epsilon = 0.33  * ones(length(ModCentre),1);
%  CentrePoint = [Centre1D Centre2D Centre3D];

%% Starting Loop for iterations
 deltaL=0;
 reducenu = 0;
 points1 = [];
 EpsilonDelta = [];
    for looprep = 1:10
      close all;
      clf;
%  CentrePoint = [CentrePoint ; GenT25(points1,:)];  % Adding point from simulated surface of test data after each iteration
   
%% Adding points and Epsilon

    ModCentre = [ModCentre; points1]; 
    ModCentreb = ModCentre; 
    Epsilon = [Epsilon; EpsilonDelta];
    
%% Calculating the Epsilon Parameter of each MF
    [Centre1D, inds2] = unique(ModCentre(:,1)  ,'rows','stable');
    [Centre2D, inds3] = unique(ModCentre(:,2)  ,'rows','stable');
    [Centre3D, inds4] = unique(ModCentre(:,3)   ,'rows','stable');
     
    Ep1 = Epsilon(inds2);
    Ep2 = Epsilon(inds3);
    Ep3 = Epsilon(inds4);
    
    nu1 = nu(inds2);
    nu2 = nu(inds3);
    nu3 = nu(inds4);
          
    dd1 = PlottingDMFConEp(Centre1D, Ep1, ind_5 , nu1);
    dd2 = PlottingDMFConEp(Centre2D, Ep2, ind_6 , nu2);
    dd3 = PlottingDMFConEp(Centre3D, Ep3, ind_7 , nu3);

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
 

%% Custom Inference Engine
Nogp = 50;  % Number of grid points
for i=1:length(ModCentre) 
   RuleList(i,1) = i;
   RuleList(i,2) = i;
   RuleList(i,3) = i;
end
Meshgrid = customInference(Nogp, [ModCentre Epsilon nu], RuleList(:,1:3));
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

% Calculating strength of rules at maxx error point
    X1 = Calculatedf(GenT24(errindx,1), ModCentre(:,1), Epsilon, nu);
    X2 = Calculatedf(GenT24(errindx,2), ModCentre(:,2), Epsilon, nu);
    for j=1:length(RuleList(:,1))     % Evaluating Rule Firing Strengths
    W(j)= 1/(1+(((1-X1(RuleList(j,1)))/X1(RuleList(j,1)))^1+((1-X2(RuleList(j,2)))/X2(RuleList(j,2)))^1)^(1/1));
    end
    Sum1 = sum(W);
    Wn = W./(Sum1);
    Value=0;
    for k=1:length(RuleList(:,3))
    Value(k) = Wn(k) * ModCentre(RuleList(k,3),3);
    end
    
% Calculating the Distance Measure
% nu = 0.5;
lambda = 1;

for i=1:length(ModCentre(:,1))
    nuR = ((1-nu(i))/nu(i));
    xx = ((GenT24(errindx,1) - ModCentre(i,1))/Epsilon(i))^lambda; 
    yy = ((GenT24(errindx,2) - ModCentre(i,2))/Epsilon(i))^lambda; 
    alpha(i) = ModCentre(i,3) /(1 + (nuR * (xx + yy )));
end
   sum_alpha = sum(alpha);
   
 % Place here the condition for split of adding a new MF point or reducing nu
   
   
   
% Reducing/increasing the nu of maximum error contributors (Selecting first two)  
   reducenu = 1;
  [contr, indxcont] = max(abs(alpha));
  
%   if (alpha(indxcont)< 0 )
    if(abs(maxerr) > .2 && nu(indxcont) > .1) 
        nu(indxcont) = nu(indxcont)/2; 
%   else
%       nu(indxcont) = nu(indxcont)+ nu(indxcont)/4;     
    end
    
%% Searching the point in the surface formed by Test Data

% Creating database from surface points
GenT5 = [x11 ; y11 ; z1];
rowgt5 = 0;
for t=1:3
row5 =1;
    for i=1:300
    rowgt5 = rowgt5 + 1;
        for k=1:300
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
           
               TF = find(abs(GenT25(rowind1(k),2) - ( GenT24(errindx,2))) <=.009, 1, 'first') ;
           
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
    points1 = GenT25(rowind2,:);  
     
 end

 figure(5);
 surface(x2,y2,z3);
 hold on;
 xi = GenT24(errindx,1);
 yi = GenT24(errindx,2);
 zi = GenT24(errindx,3);
 scatter3(xi,yi,zi,'filled');
%  EpsilonDelta = 0.165;
 
 end
 



