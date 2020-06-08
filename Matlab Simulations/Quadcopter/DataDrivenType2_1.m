%% Data Driven based Fuzzy Control %%
%% Extracting the Simulation Data and plotting the surface %%
clc; close all; clf;
open('asbQuadcopter.prj');
sim('asbQuadcopter.slx');
bound1=0.15;
bound2=0.16;
nuc=0.05;
TT1 = [InputError.Time   InputError.Data];
TT2 = [InputPositionDot.Time   InputPositionDot.Data];
TO = [outputFC.Time outputFC.Data];
TT3 = [TT1 TT2 TO];
TT3 (:,3)= [];
TT3(:,4) = [];
TT3(~any(TT3,2),:) = [];
TT3(:,2) = (TT3(:,2) - min(TT3(:,2))) / (max(TT3(:,2))-min(TT3(:,2)));  % TT3(:,2) = (TT3(:,2) - (-1.1)) / (2.2);
TT3(:,3) = (TT3(:,3) - min(TT3(:,3))) / (max(TT3(:,3))-min(TT3(:,3)));  % TT3(:,3) = (TT3(:,3) - (-2)) / (4);

x = linspace(min(TT3(:,2)), max(TT3(:,2)),300);
y = linspace(min(TT3(:,3)),max(TT3(:,3)), numel(x))';
[XX, YY] = meshgrid(x,y);
F = scatteredInterpolant(TT3(:,2), TT3(:,3), TT3(:,4));
ZZ = F(XX,YY) ;
surfdata=surface(XX,YY,ZZ);
x1 = surfdata.XData;
y1 = surfdata.YData;
    z1 = surfdata.ZData;
%Normalize X1 and Y1    
% x11 = (x1 - min(min(x1))) / (max(max(x1))-min(min(x1)));
% y11 = (y1 - min(min(y1))) / (max(max(y1))-min(min(y1)));

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
% GenT_12(:,1) = (GenT_12(:,1) - min(GenT_12(:,1))) / (max(GenT_12(:,1))-min(GenT_12(:,1)));
% GenT_12(:,2) = (GenT_12(:,2) - min(GenT_12(:,2))) / (max(GenT_12(:,2))-min(GenT_12(:,2)));
GenT_12 = sortrows(GenT_12,1);
GenT_12 = fix(GenT_12*10^3)/10^3;

% Points of interest
Points_1 =[0 1 0 1 .5];
Points_2 =[0 1 1 0 .5];

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
Epsilon2 = 0.33 * ones(length(ModCentre)-4,1);
Epsilon = [Epsilon1;Epsilon2];

%% Selection of nu values for initial points

k1= 20;
lambda = 4;

for i=1:length(ModCentre)

    for j=1:length(ModCentre)
        
        if (j~=i)
            d(i,j) = (((ModCentre(i,1)- ModCentre(j,1))./Epsilon(j))^lambda) + (((ModCentre(i,2)- ModCentre(j,2))./Epsilon(j))^lambda); 
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
 Noise = 0.1;
 for looprep = 1:40
%       close all;
      clf;
% %  CentrePoint = [CentrePoint ; GenT25(points1,:)];  % Adding point from simulated surface of test data after each iteration
   
%% Adding points and Epsilon

    ModCentre = [ModCentre; points1]; 
    ModCentreb = ModCentre; 
    Epsilon = [Epsilon; EpsilonDelta];
    nu = [nu NuDelta];
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
    
[dd11, dd12] = PlottingT2DMF(Centre1D, Ep1, lambda , nu1, Noise);
[dd21, dd22] = PlottingT2DMF(Centre2D, Ep2, lambda , nu2, Noise);
[dd31, dd32] = PlottingT2DMF(Centre3D, Ep3, lambda , nu3, Noise);

x = min(Centre1D)-1:(max(Centre1D)-min(Centre1D))/200:max(Centre1D)+1;
figure(1);
plot(x, dd11', x, dd12');
axis([0 1 0 1.1]);

x = min(Centre2D)-1:(max(Centre2D)-min(Centre2D))/200:max(Centre2D)+1;
figure(2);
plot(x, dd21', x, dd22');
axis([0 1 0 1.1]);

x = min(Centre3D)-1:(max(Centre3D)-min(Centre3D))/200:max(Centre3D)+1;
figure(3);
plot(x, dd31', x, dd32');
axis([-1.26 1.26 0 1.1]);

%% Custom Inference Engine
Nogp = 100;  % Number of grid points
for i=1:length(ModCentre) 
   RuleList(i,1) = i;
   RuleList(i,2) = i;
   RuleList(i,3) = i;
end
Meshgrid1 = customInferenceT2df_a(Nogp, ModCentre(:,1:3), Epsilon, nu, RuleList(:,1:3), Noise);
points2 = Nogp+1;
xcor = reshape (Meshgrid1(:,1), [points2,points2]);
ycor = reshape (Meshgrid1(:,2), [points2,points2]);
zcorL = reshape (Meshgrid1(:,3), [points2,points2]);
zcorU = reshape (Meshgrid1(:,4), [points2,points2]);
zcorC = reshape (Meshgrid1(:,5), [points2,points2]);
figure(4);
ConsurfL = surface(xcor,ycor,zcorL);
figure(4);
ConsurfU = surface(xcor,ycor,zcorU);
figure(5);
ConsurfC = surface(xcor,ycor,zcorC);
% figure(4);
% Consurf = surface( xcor,ycor, zcor);
x2 = ConsurfC.XData;
y2 = ConsurfC.YData;
z2 = ConsurfC.ZData;

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

min1 = min(x1(1,:));
min2 = min(x2(1,:));
    if(min1 ~= min2)
    x1(x1==min1)= min2;
    end
    
min3 = min(y1(:,1));
min4 = min(y2(:,1));
    if(min3 ~= min4)
    y1(y1==min3)= min4;
    end

% Truncating the decimal part
x11 = fix(x1*10^2)/10^2;
y11 = fix(y1*10^2)/10^2;
z1 = fix(z1*10^2)/10^2;
GenT2 = fix(GenT2*10^2)/10^2;
    
for i=1:length(GenT2)
    [raw1, colind6]=find(x1==GenT2(i,1),1,'first');
    if (isempty(colind6))
       [raw1, colind6]=find((x1-GenT2(i,1))<.01,1,'last');    % Must be checked   
    end
    [rowind6 , raw2]=find(y1==GenT2(i,2),1,'first');
    if (isempty(rowind6))
       [rowind6, raw2]=find((y1-GenT2(i,2))<.01,1,'last');    % Must be checked   
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

figure(6);
errorsurface = surface(x2,y2,z3);
x4 = errorsurface.XData;
y4 = errorsurface.YData;
z4 = errorsurface.ZData;

% Plotting the error plus generated surface == original (required surface)
z33 = z2 + z3 ;
figure(7);
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
GenT5 = [x1 ; y1 ; z1];
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
 if (maxerr<bound1)
     disp("Surface found within bounds");
     break;
 end
 if (reducenu)
    points1 = []; 
 else 
    points1 = GenT25(rowind2,:);  
     
 end

 figure(8);
 surface(x2,y2,z3);
 hold on;
 xi = GenT24(errindx,1);
 yi = GenT24(errindx,2);
 zi = GenT24(errindx,3);
 scatter3(xi,yi,zi,'filled');
%  
 %% Calculating the nu of new point based on minimum influence to the sorrunding points

k2 = 20;
lambda =4;

    for j=1:length(ModCentre)
         d1(j) = ((( ModCentre(j,1)-points1(1))./Epsilon(j))^lambda) + (((ModCentre(j,2)-points1(2))./Epsilon(j))^lambda); 
         nu_point(j) = (1./ (1 + (((k2* abs(points1(3)))-1)./d1(j))));  
    end 
    if (min(nu_point)<nuc)    
    NuDelta = nuc;
    else 
    NuDelta = min(nu_point);
    end
EpsilonDelta = 0.33;
   end
 Epsilonb= Epsilon;
figure(9);
ConsurfC = surface(xcor,ycor,zcorC);
figure(10);
surface(x2,y2,z3); hold on;
scatter3(xi,yi,zi,'filled');
figure(100);plot(ModCentre(:,1),ModCentre(:,2),'*');


%% Reducing the number of the rules 

% Splitting the points based on boundary and principle feature centre values

% Boundary Values
newcentre= ModCentre;
nub= nu;

i=1;
for c =1:length(newcentre(:,1))
     if (newcentre(c,1)<0.001 || newcentre(c,2)<0.001 || (newcentre(c,1)==0.5010 && newcentre(c,2)==0.5010) || (newcentre(c,1)==1 && newcentre(c,2)==1))
        boundaryp(i,:) = newcentre(c,:);
        store(i)= c;
        i= i+1;
    end
end
newcentre(store,:)=[];
%%
% Principle feature

  i = 1;
  j = 1;
for c =1:length(newcentre(:,1))
     if (newcentre(c,1)<0.5)
        quad(i,:,1) = newcentre(c,:);
        i=i+1;
    end
    if (newcentre(c,1)>0.5)
        quad(j,:,2) = newcentre(c,:);
        j=j+1;
    end
end
%%
% Finding distances between all the points
% for first quadrant

 % number of quadrants

% for m = 1:q
%     b = quad(:,:,m);
%     b = b(any(b,2),:);
%     no_of_points= length(b(:,1));
%     dist = zeros(no_of_points,no_of_points);
%     threshold1 = (sqrt(0.5^2 + 1))/no_of_points; 
%     for i=1:no_of_points
%           k = 1;
%         for j=k: no_of_points
%             if (i==j)
%             dist(i,j)= 0; dist(j,i)=0;
%             else
%             distt = sqrt((b(i,1)-b(j,1))^2 + (b(i,2)-b(j,2))^2);    
%                 if (distt<= threshold1)     
%                     dist(i,j) = distt; dist(j,i) = distt;
%                 else
%                     dist(i,j) = 0; dist(j,i) = 0;
%                 end
%             end
%         end                              
%         k = k+1;
%     end
% end
%% New method for distance calculation
%q=2;
Epsilon = Epsilonb;
nu = nub;
ModCentrenew = ModCentre;
groupnew =[];
%%
for qq=1:2
    
    q = quad(:,1:2,qq);
    q( all( ~any( q'), 1 ), : ) = [] ;
    dist1 = dist(q');
    % q = quad(:,1:2,2);
    % q( all( ~any( q'), 1 ), : ) = [];
    % dist2 = dist(q');
    no_of_points = length(dist1(:,1));
    threshold1 = (sum(dist1(1,:)))/no_of_points; 
    %threshold1 = (sqrt(0.5^2 + 1^2))/2;  % no of points
    count=1;
    rowxld=zeros(size(dist1,1),1);

for i=1:size(dist1,1)
  
    if sum(any(rowxld==i))==0
        
        for j=1:size(dist1,2)

            if (dist1(i,j)<= threshold1)
                 if (i==j)
                   dist1(i,j) = 0;
                 else
                    if sum(any(rowxld==j))==0
                    dist1(i,j) = 1;
                    rowxld(count) = j;
                    count = count+1;
                    else
                    dist1(i,j) = 0;
                    end
                 end
            else 
            dist1(i,j)=0;
            end
        end
     
    else
      dist1(i,:)=0;  
        
    end
    
end

% forming groups
% ModCentrenew = ModCentre;
group_no= nnz(any(dist1));
fprintf('number of groups in quadrant: %d are : %d \n', qq , group_no );
% groupnew =[];
% Do optimization for each group individually 
% count=1;
 for i=1:size(dist1,1)
     
    if nnz(any(dist1(i,:)))
        %pointer(count)=i;
        %count = count+1;
        group =  quad(i,:,qq);
        group = [group; quad(dist1(i,:)~=0,:,qq)];
  
        Epsilonnew = Epsilon(ismember(ModCentrenew,group,'rows'));
        Epsilon(ismember(ModCentrenew,group,'rows'))=[];
        Epsilon= [Epsilon; max(Epsilonnew)];
                
       % nunew = nu(ismember(ModCentrenew,group,'rows'));
        nu(ismember(ModCentrenew,group,'rows'))=[];
        ModCentrenew(ismember(ModCentrenew,group,'rows'),:)=[];
        group = sort (group,'ascend');
        % Calculate new nu
        
        k2 =10;
        lambda =4;
        ModCentretest= [ModCentrenew; groupnew];
        
        for k=1:size(ModCentretest,1)
             d1(k) = ((( ModCentretest(k,1)-((group(1,1)+ group(end,1))/2))./0.33)^lambda) + (((ModCentretest(k,2)-((group(1,2)+ group(end,2))/2))./0.33)^lambda); 
             nu_point(k) = (1./ (1 + (((k2* abs(((group(1,3)+ group(end,3))/2)))-1)./d1(k))));  
        end 
        if (min(nu_point)<nuc)    
           NuDelta = nuc;
        else 
            NuDelta = min(nu_point);
        end
         
        nu = [nu NuDelta];
%       nu = [nu max(nunew)];
        %sorting values in group columns
        %group1= sort(group(:,1),'ascend');
        %group2= sort(group(:,2),'ascend');
%       ModCentrenew = [ModCentrenew; groupnew];
        if (size(group,1)<=2)
        groupnew = [groupnew; group(1,:); group(end,:)];
        else
%          a= sum(group(1:(size(group,1)-1),1))/(size(group,1)-1);   
%          b= sum(group(1:(size(group,1)-1),2))/(size(group,1)-1);
         c= sum(group(1:(size(group,1)-1),3))/(size(group,1)-1);
         groupnew =[groupnew; [group(1,1) group(1,2) c];    group(end,:)];
        end
        
        
        Nogp = 100;                     % Number of grid points
        RuleListnew=[];
        for j=1:length(ModCentrenew)   
           RuleListnew(j,1) = j;
           RuleListnew(j,2) = j;
           RuleListnew(j,3) = j;
        end
        RuleListnew1=[];
        k=1;
        for j=1:2:size(groupnew,1)   
           RuleListnew1(k,1) = k;
           RuleListnew1(k,2) = k;
           RuleListnew1(k,3) = k;
           k=k+1;
        end
      
        Meshgrid1 = customInferenceT2df_a_red(Nogp, ModCentrenew(:,1:3),groupnew, Epsilon, nu, RuleListnew(:,1:3),RuleListnew1, Noise); 
        points2 = Nogp+1;
        xcor = reshape (Meshgrid1(:,1), [points2,points2]);
        ycor = reshape (Meshgrid1(:,2), [points2,points2]);
        zcorL = reshape (Meshgrid1(:,3), [points2,points2]);
        zcorU = reshape (Meshgrid1(:,4), [points2,points2]);
        zcorC = reshape (Meshgrid1(:,5), [points2,points2]);
        figure(11);
        ConsurfL = surface(xcor,ycor,zcorL);
        figure(12);
        ConsurfU = surface(xcor,ycor,zcorU);
        figure(13);
        ConsurfC = surface(xcor,ycor,zcorC);
        % figure(4);
        % Consurf = surface( xcor,ycor, zcor);
        x2 = ConsurfC.XData;
        y2 = ConsurfC.YData;
        z2 = ConsurfC.ZData;
        
        %Calculating maximum error
            GenT = [x2 ; y2 ; z2];
            rowgt = 0;
            for t=1:3
            row =1;
                for n=1:size(x2,1)
                rowgt = rowgt + 1;
                    for k=1:size(x2,1)
                    GenT2(row,t) = GenT(rowgt,k);
                    row = row+1;
                    end
                end
            end

            min1 = min(x1(1,:));
            min2 = min(x2(1,:));
                if(min1 ~= min2)
                x1(x1==min1)= min2;
                end

            min3 = min(y1(:,1));
            min4 = min(y2(:,1));
                if(min3 ~= min4)
                y1(y1==min3)= min4;
                end

            % Truncating the decimal part
            x11 = fix(x1*10^2)/10^2;
            y11 = fix(y1*10^2)/10^2;
            z1 = fix(z1*10^2)/10^2;
            GenT2 = fix(GenT2*10^2)/10^2;

            for n=1:length(GenT2)
                [raw1, colind6]=find(x1==GenT2(n,1),1,'first');
                if (isempty(colind6))
                   [raw1, colind6]=find((x1-GenT2(n,1))<.01,1,'last');    % Must be checked   
                end
                [rowind6 , raw2]=find(y1==GenT2(n,2),1,'first');
                if (isempty(rowind6))
                   [rowind6, raw2]=find((y1-GenT2(n,2))<.01,1,'last');    % Must be checked   
                end
                errz(n)=(z1(rowind6, colind6) - GenT2(n,3));
            end

            % Forming the z for error

            pointerrz = 1;

            for o=1:size(x2,1)  % same number of rows as x

                for j =1:size(x2,2)  % same colums of errz as x  
                    z3(o,j) = errz(pointerrz);
                    pointerrz = pointerrz + 1;
                end

            end

            figure(14);
            errorsurface = surface(x2,y2,z3);
            x4 = errorsurface.XData;
            y4 = errorsurface.YData;
            z4 = errorsurface.ZData;

            % Plotting the error plus generated surface == original (required surface)
            z33 = z2 + z3 ;
            figure(15);
            surface(x2,y2,z33);
            
            %
            GenT4 = [x4 ; y4 ; z4];
            rowgt4 = 0;
            for t=1:3
            row4 =1;
                for p=1:size(x2,1)
                    rowgt4 = rowgt4 + 1;
                    for k=1:size(x2,2)
                    GenT24(row4,t) = GenT4(rowgt4,k);
                    row4 = row4  +1;
                    end
                end
            end
            [maxerr, errindx] = max(abs( GenT24(:,3)));
            
            %Checking maximum error
            GenT5 = [x1 ; y1 ; z1];
            rowgt5 = 0;
            for t=1:3
            row5 =1;
                for p=1:300
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

%              maxerror(looprep) = maxerr;
               fprintf('The maximum error is: %.2f \n',maxerr);
            
                figure(16);
                surface(x2,y2,z3);
                hold on;
                xi = GenT24(errindx,1);
                yi = GenT24(errindx,2);
                zi = GenT24(errindx,3);
                scatter3(xi,yi,zi,'filled');
    end
    
    
 end
end 

groupnewb=groupnew;
nub=nu;
Epsilonb= Epsilon;

%% Optimizing the boundary points

groupnew = groupnewb;
nu= nub;
Epsilon= Epsilonb;

disp('Now reducing the boundary points');
boundarypoint= boundaryp;
% removing the corner points (boundary conditions)
boundarypoint(1:5,:)=[];
boundary=[];
%capturing boundary points
i=1;j=1;k=1;l=1;
for c =1:length(boundarypoint(:,1))
     if (boundarypoint(c,1)==0)
        boundary(i,:,1) = boundarypoint(c,:);
        i=i+1;
     elseif (boundarypoint(c,2)==0)
         boundary(j,:,2) = boundarypoint(c,:);
        j=j+1;
    
     elseif (boundarypoint(c,1)==1)
         boundary(k,:,3) = boundarypoint(c,:);
        k=k+1;
     elseif (boundarypoint(c,2)==1)
         boundary(l,:,4) = boundarypoint(c,:);
        l=l+1;
     
     end
end



for qq=1:size(boundary,3)
   q = boundary(:,1:2,qq);
   q( all( ~any( q'), 1 ), : ) = []; 
    dist1 = dist(q');
    % q = quad(:,1:2,2);
    % q( all( ~any( q'), 1 ), : ) = [];
    % dist2 = dist(q');
    no_of_points = length(dist1(:,1));
    threshold1 = (sum(dist1(1,:)))/no_of_points; 
    %threshold1 = (sqrt(0.5^2 + 1^2))/2;  % no of points
    count=1;
    rowxld=zeros(size(dist1,1),1);

for i=1:size(dist1,1)
  
    if sum(any(rowxld==i))==0
        
        for j=1:size(dist1,2)

            if (dist1(i,j)<= threshold1)
                 if (i==j)
                   dist1(i,j) = 0;
                 else
                    if sum(any(rowxld==j))==0
                    dist1(i,j) = 1;
                    rowxld(count) = j;
                    count = count+1;
                    else
                    dist1(i,j) = 0;
                    end
                 end
            else 
            dist1(i,j)=0;
            end
        end
     
    else
      dist1(i,:)=0;  
        
    end
    
end

% forming groups
% ModCentrenew = ModCentre;

    group_no= nnz(any(dist1));
    fprintf('number of groups in boundary: %d are : %d \n', qq , group_no );

    for i=1:size(dist1,1)
     
        if nnz(any(dist1(i,:)))
        %pointer(count)=i;
        %count = count+1;
        group =  boundary(i,:,qq);
        group = [group; boundary(dist1(i,:)~=0,:,qq)];
  
        Epsilonnew = Epsilon(ismember(ModCentrenew,group,'rows'));
        Epsilon(ismember(ModCentrenew,group,'rows'))=[];
        Epsilon= [Epsilon; max(Epsilonnew)];
                
       % nunew = nu(ismember(ModCentrenew,group,'rows'));
        nu(ismember(ModCentrenew,group,'rows'))=[];
        ModCentrenew(ismember(ModCentrenew,group,'rows'),:)=[];
        group = sort (group,'ascend');
        % Calculate new nu
        
        k2 =10;
        lambda =4;
        ModCentretest= [ModCentrenew; groupnew];
        
        for k=1:size(ModCentretest,1)
             d1(k) = ((( ModCentretest(k,1)-((group(1,1)+ group(end,1))/2))./0.33)^lambda) + (((ModCentretest(k,2)-((group(1,2)+ group(end,2))/2))./0.33)^lambda); 
             nu_point(k) = (1./ (1 + (((k2* abs(((group(1,3)+ group(end,3))/2)))-1)./d1(k))));  
        end 
        if (min(nu_point)<nuc)    
           NuDelta = nuc;
        else 
            NuDelta = min(nu_point);
        end
         
        nu = [nu NuDelta];
%       nu = [nu max(nunew)];
        %sorting values in group columns
        %group1= sort(group(:,1),'ascend');
        %group2= sort(group(:,2),'ascend');
%       ModCentrenew = [ModCentrenew; groupnew];
        if (size(group,1)<=2)
        groupnew = [groupnew; group(1,:); group(end,:)];
        else
%          a= sum(group(1:(size(group,1)-1),1))/(size(group,1)-1);   
%          b= sum(group(1:(size(group,1)-1),2))/(size(group,1)-1);
         c= sum(group(1:(size(group,1)-1),3))/(size(group,1)-1);
         groupnew =[groupnew; [group(1,1) group(1,2) c]; group(end,:)];
        end
        
        Nogp = 100;                     % Number of grid points
        RuleListnew=[];
        for j=1:length(ModCentrenew)   
           RuleListnew(j,1) = j;
           RuleListnew(j,2) = j;
           RuleListnew(j,3) = j;
        end
        RuleListnew1=[];
        k=1;
        for j=1:2:size(groupnew,1)   
           RuleListnew1(k,1) = k;
           RuleListnew1(k,2) = k;
           RuleListnew1(k,3) = k;
           k=k+1;
        end
      
        Meshgrid1 = customInferenceT2df_a_red(Nogp, ModCentrenew(:,1:3),groupnew, Epsilon, nu, RuleListnew(:,1:3),RuleListnew1, Noise); 
        points2 = Nogp+1;
        xcor = reshape (Meshgrid1(:,1), [points2,points2]);
        ycor = reshape (Meshgrid1(:,2), [points2,points2]);
        zcorL1 = reshape (Meshgrid1(:,3), [points2,points2]);
        zcorU1 = reshape (Meshgrid1(:,4), [points2,points2]);
        zcorC1 = reshape (Meshgrid1(:,5), [points2,points2]);
        figure(11);
        ConsurfL = surface(xcor,ycor,zcorL1);
        figure(12);
        ConsurfU = surface(xcor,ycor,zcorU1);
        figure(13);
        ConsurfC = surface(xcor,ycor,zcorC1);
        % figure(4);
        % Consurf = surface( xcor,ycor, zcor);
        x2 = ConsurfC.XData;
        y2 = ConsurfC.YData;
        z2 = ConsurfC.ZData;
        
        %Calculating maximum error
            GenT = [x2 ; y2 ; z2];
            rowgt = 0;
            for t=1:3
            row =1;
                for n=1:size(x2,1)
                rowgt = rowgt + 1;
                    for k=1:size(x2,1)
                    GenT2(row,t) = GenT(rowgt,k);
                    row = row+1;
                    end
                end
            end

            min1 = min(x1(1,:));
            min2 = min(x2(1,:));
                if(min1 ~= min2)
                x1(x1==min1)= min2;
                end

            min3 = min(y1(:,1));
            min4 = min(y2(:,1));
                if(min3 ~= min4)
                y1(y1==min3)= min4;
                end

            % Truncating the decimal part
            x11 = fix(x1*10^2)/10^2;
            y11 = fix(y1*10^2)/10^2;
            z1 = fix(z1*10^2)/10^2;
            GenT2 = fix(GenT2*10^2)/10^2;

            for n=1:length(GenT2)
                [raw1, colind6]=find(x1==GenT2(n,1),1,'first');
                if (isempty(colind6))
                   [raw1, colind6]=find((x1-GenT2(n,1))<.01,1,'last');    % Must be checked   
                end
                [rowind6 , raw2]=find(y1==GenT2(n,2),1,'first');
                if (isempty(rowind6))
                   [rowind6, raw2]=find((y1-GenT2(n,2))<.01,1,'last');    % Must be checked   
                end
                errz(n)=(z1(rowind6, colind6) - GenT2(n,3));
            end

            % Forming the z for error

            pointerrz = 1;

            for o=1:size(x2,1)  % same number of rows as x

                for j =1:size(x2,2)  % same colums of errz as x  
                    z3(o,j) = errz(pointerrz);
                    pointerrz = pointerrz + 1;
                end

            end

            figure(14);
            errorsurface = surface(x2,y2,z3);
            x4 = errorsurface.XData;
            y4 = errorsurface.YData;
            z4 = errorsurface.ZData;

            % Plotting the error plus generated surface == original (required surface)
            z33 = z2 + z3 ;
            figure(15);
            surface(x2,y2,z33);
            
            %
            GenT4 = [x4 ; y4 ; z4];
            rowgt4 = 0;
            for t=1:3
            row4 =1;
                for p=1:size(x2,1)
                    rowgt4 = rowgt4 + 1;
                    for k=1:size(x2,2)
                    GenT24(row4,t) = GenT4(rowgt4,k);
                    row4 = row4  +1;
                    end
                end
            end
            [maxerr, errindx] = max(abs( GenT24(:,3)));
            
            %Checking maximum error
            GenT5 = [x1 ; y1 ; z1];
            rowgt5 = 0;
            for t=1:3
            row5 =1;
                for p=1:300
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
                
               points1 = GenT25(rowind2,:);  
%              maxerror(looprep) = maxerr;
               fprintf('The maximum error is: %.2f \n',maxerr);
               figure(16);
               surface(x2,y2,z3);
               hold on;
               xi = GenT24(errindx,1);
               yi = GenT24(errindx,2);
               zi = GenT24(errindx,3);
               scatter3(xi,yi,zi,'filled');
        end
    
    
    end

end

%% Reducing maximum Error

for i=1:20
    
    if (maxerr<bound2)
     disp("Surface found within bounds");
     break;
    else
        fprintf('Running Iteration no: %d',i);
    end
    
    k2 =10;
    lambda =4;
    ModCentretest= [ModCentrenew; groupnew];
        
        for k=1:size(ModCentretest,1)
             d1(k) = ((( ModCentretest(k,1)-(points1(1,1)))/0.33)^lambda) + (((ModCentretest(k,2)-(points1(1,2)))/0.33)^lambda); 
             nu_point(k) = (1./ (1 + (((k2* abs(((points1(1,3)))))-1)./d1(k))));  
        end 
        if (min(nu_point)<nuc)    
           NuDelta = nuc;
        else 
            NuDelta = min(nu_point);
        end
         
        nug= nu(size(ModCentrenew,1)+1:end);
        nu(size(ModCentrenew,1)+1:end)=[];
        nu = [nu NuDelta];
        nu = [nu nug];
        Epsilon= [Epsilon; 0.333];
        ModCentrenew = [ModCentrenew; points1] ;
        Nogp = 100;                     % Number of grid points
        RuleListnew=[];
        for j=1:length(ModCentrenew)   
           RuleListnew(j,1) = j;
           RuleListnew(j,2) = j;
           RuleListnew(j,3) = j;
        end
        RuleListnew1=[];
        k=1;
        for j=1:2:size(groupnew,1)   
           RuleListnew1(k,1) = k;
           RuleListnew1(k,2) = k;
           RuleListnew1(k,3) = k;
           k=k+1;
        end
        Meshgrid1 = customInferenceT2df_a_red(Nogp, ModCentrenew(:,1:3),groupnew, Epsilon, nu, RuleListnew(:,1:3),RuleListnew1, Noise); 
        points2 = Nogp+1;
        xcor = reshape (Meshgrid1(:,1), [points2,points2]);
        ycor = reshape (Meshgrid1(:,2), [points2,points2]);
        zcorL2 = reshape (Meshgrid1(:,3), [points2,points2]);
        zcorU2 = reshape (Meshgrid1(:,4), [points2,points2]);
        zcorC2 = reshape (Meshgrid1(:,5), [points2,points2]);
        figure(21);
        ConsurfL = surface(xcor,ycor,zcorL2);
        figure(22);
        ConsurfU = surface(xcor,ycor,zcorU2);
        figure(23);
        ConsurfC = surface(xcor,ycor,zcorC2);
        x2 = ConsurfC.XData;
        y2 = ConsurfC.YData;
        z2 = ConsurfC.ZData;
        %Calculating maximum error
            GenT = [x2 ; y2 ; z2];
            rowgt = 0;
            for t=1:3
            row =1;
                for n=1:size(x2,1)
                rowgt = rowgt + 1;
                    for k=1:size(x2,1)
                    GenT2(row,t) = GenT(rowgt,k);
                    row = row+1;
                    end
                end
            end
            min1 = min(x1(1,:));
            min2 = min(x2(1,:));
                if(min1 ~= min2)
                x1(x1==min1)= min2;
                end
            min3 = min(y1(:,1));
            min4 = min(y2(:,1));
                if(min3 ~= min4)
                y1(y1==min3)= min4;
                end
            % Truncating the decimal part
            x11 = fix(x1*10^2)/10^2;
            y11 = fix(y1*10^2)/10^2;
            z1 = fix(z1*10^2)/10^2;
            GenT2 = fix(GenT2*10^2)/10^2;
            for n=1:length(GenT2)
                [raw1, colind6]=find(x1==GenT2(n,1),1,'first');
                if (isempty(colind6))
                   [raw1, colind6]=find((x1-GenT2(n,1))<.01,1,'last');    % Must be checked   
                end
                [rowind6 , raw2]=find(y1==GenT2(n,2),1,'first');
                if (isempty(rowind6))
                   [rowind6, raw2]=find((y1-GenT2(n,2))<.01,1,'last');    % Must be checked   
                end
                errz(n)=(z1(rowind6, colind6) - GenT2(n,3));
            end
            % Forming the z for error
            pointerrz = 1;
            for o=1:size(x2,1)  % same number of rows as x

                for j =1:size(x2,2)  % same colums of errz as x  
                    z3(o,j) = errz(pointerrz);
                    pointerrz = pointerrz + 1;
                end
            end
            figure(24);
            errorsurface = surface(x2,y2,z3);
            x4 = errorsurface.XData;
            y4 = errorsurface.YData;
            z4 = errorsurface.ZData;
            % Plotting the error plus generated surface == original (required surface)
            z33 = z2 + z3 ;
            figure(25);
            surface(x2,y2,z33);
            %
            GenT4 = [x4 ; y4 ; z4];
            rowgt4 = 0;
            for t=1:3
            row4 =1;
                for p=1:size(x2,1)
                    rowgt4 = rowgt4 + 1;
                    for k=1:size(x2,2)
                    GenT24(row4,t) = GenT4(rowgt4,k);
                    row4 = row4  +1;
                    end
                end
            end
            [maxerr, errindx] = max(abs( GenT24(:,3)));
           %Checking maximum error
            GenT5 = [x1 ; y1 ; z1];
            rowgt5 = 0;
            for t=1:3
            row5 =1;
                for p=1:300
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
               points1 = GenT25(rowind2,:);  
%              maxerror(looprep) = maxerr;
               fprintf('The maximum error is: %.2f \n',maxerr);
               figure(16);
               surface(x2,y2,z3);
               hold on;
               xi = GenT24(errindx,1);
               yi = GenT24(errindx,2);
               zi = GenT24(errindx,3);
               scatter3(xi,yi,zi,'filled');
end
%% Plotting Final Figures

[d1,d2,d3,d4] = PlottingT2DMF_new(ModCentrenew(1:end-2,1), Epsilon,nu, Noise,groupnew(:,1));
x = 0:.01:1;
figure(17);
plot(x, d1', x, d2',x, d3',x, d4');
axis([0 1 0 1.1]);


[d1,d2,d3,d4] = PlottingT2DMF_new(ModCentrenew(1:end-2,2), Epsilon,nu, Noise,groupnew(:,2));
x = 0:.01:1;
figure(18);
plot(x, d1', x, d2',x, d3',x, d4');
axis([0 1 0 1.1]);

%% Generating data centre points

    k=1;
for i=1:size(groupnew,1)/2
    
   datapoints(i,1) = (groupnew(k,1) + groupnew(k+1,1))/2;
   datapoints(i,2) = (groupnew(k,2) + groupnew(k+1,2))/2;
   k=k+2;
      
end

reduced_points = [ModCentrenew(:,1:2); datapoints(:,:)];

figure(200);
plot(reduced_points(:,1),reduced_points(:,2),'*');
























