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
for i=1:r 
    if (abs (TT3(i,2))< .0001 || TT3(i,1)<0.5)
        TT3(i,:)= 0;
   end
end
TT3(~any(TT3,2),:) = [];
x = linspace(min(TT3(:,2)), max(TT3(:,2)),500);
y = linspace(min(TT3(:,3)),max(TT3(:,3)), numel(x))';
[XX, YY] = meshgrid(x,y);
F = scatteredInterpolant(TT3(:,2), TT3(:,3), TT3(:,4));
ZZ = F(XX,YY) ;
ZZ(ZZ>5) = 5;
ZZ(ZZ<-5) = -5;
%  mesh(XX,YY,ZZ);
surfdata=surface(XX,YY,ZZ,50);
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
Points_1 =[0.01 0.99 .01 .99 .5  .5  .01 .99];
Points_2 =[0.01 0.99 .99 .01 .01 .99  .5  .5];  

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

Epsilon1 = 0.33  * ones(length(ModCentre)/2,1);
Epsilon2 = 0.33 * ones(length(ModCentre)/2,1);
Epsilon = [Epsilon1;Epsilon2];

%  CentrePoint = [Centre1D Centre2D Centre3D];

%% Starting Loop for iterations
 deltaL=0;
 points1 = [];
 epl1 = []; epl2=[]; epl3=[];
 epr1 =[]; epr2=[]; epr3=[];

                [Centre1D, inds2] = unique(ModCentre(:,1)  ,'rows','stable');
                [Centre2D, inds3] = unique(ModCentre(:,2)  ,'rows','stable');
                [Centre3D, inds4] = unique(ModCentre(:,3)   ,'rows','stable');
 
 
%    Epsilon_1 =  0.33;%sqrt(1/length(ModCentre(:,1)));          %length(ModCentre(:,1))
%                                 
%                 pointer1 = 1;
%           for i=1:length(Centre1D)-1
%                 Epx(pointer1) =  Epsilon_1  ;       %value(i)/(2);
%                 pointer1 = pointer1 + 1;
%                 Epx(pointer1) = Epx(pointer1-1);
%                 pointer1 = pointer1 + 1;
%           end
%           
%           
%            for i=1:length(Centre1D)-1
%                 epl1(i) =  Epsilon_1;
%                 epr1(i) =   Epsilon_1;
%           end
%           
%           
%                 pointer2 = 1;
%            for i=1:length(Centre2D)-1
%                 Epy(pointer2) =    Epsilon_1 ;       %0.5 * sqrt((2*.2)/((size(CentrePoint(:,2),1))*pi)) ; %value(i)/(.0001);
%                 pointer2 = pointer2 + 1;
%                 Epy(pointer2) = Epy(pointer2-1);
%                 pointer2 = pointer2 + 1;
%            end
% 
%             for i=1:length(Centre2D)-1
%                 epl2(i) =  Epsilon_1;
%                 epr2(i) =   Epsilon_1;
%           end
%              
%            
%                 pointer3 = 1;
%              for i=1:length(Centre3D)-1
%                 Epz(pointer3) =  Epsilon_1 ;     %value(i)/(2);
%                 pointer3 = pointer3 + 1;
%                 Epz(pointer3) = Epz(pointer3-1);
%                 pointer3 = pointer3 + 1;
%              end
%  
%               for i=1:length(Centre3D)-1
%                 epl3(i) =  Epsilon_1;
%                 epr3(i) =   Epsilon_1;
%           end
 
 
%   for looprep = 1:100
      close all;
      clf;
%  CentrePoint = [CentrePoint ; GenT25(points1,:)];  % Adding point from simulated surface of test data after each iteration

ModCentre = [ModCentre; points1]; 
ModCentreb = ModCentre; 

%% Calculating the Epsilon Parameter of each MF
                [Centre1D, inds2] = unique(ModCentre(:,1)  ,'rows','stable');
                [Centre2D, inds3] = unique(ModCentre(:,2)  ,'rows','stable');
                [Centre3D, inds4] = unique(ModCentre(:,3)   ,'rows','stable');
                   
                Epsilon_1 =  0.33;%sqrt(1/length(ModCentre(:,1)));    
             
                Epx = [Epx Epsilon_1 Epsilon_1];
                Epy = [Epy Epsilon_1 Epsilon_1];
                Epz = [Epz Epsilon_1 Epsilon_1];
      
%% Plotting Membership Functions
 dd1 = PlottingDMFConEp(Centre1D, Epx, ind_5);
 dd2 = PlottingDMFConEp(Centre2D, Epy, ind_6);
 dd3 = PlottingDMFConEp(Centre3D, Epz, ind_7);

% dd1 = PlottingDMFConEpR(Centre1D, Epx, min(Centre1D), max(Centre1D));
% dd2 = PlottingDMFConEpR(Centre2D, Epy, min(Centre2D), max(Centre2D));
% dd3 = PlottingDMFConEpR(Centre3D, Epz, min(Centre3D), max(Centre3D));

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
 
% %% Creating Fuzzy Controller
% IP1 = sort(Centre1D); 
% IP2 = sort(Centre2D); 
% IP3 = sort(Centre3D); 
% deltaL=0;
%  for i=1:length(IP1)
%      nul1(i)=0.5; 
%      nur1(i)=0.5;   
%  end
% % [max1, maxind1] = max(IP1);
% nul1(1) = 1;
% nur1(ind_5) = 1;
% 
%  for i=1:length(IP2)
%      nul2(i)=0.5; 
%      nur2(i)=0.5;   
%  end
% % [max2, maxind2] = max(IP2);
% nul2(1) = 1;
% nur2(ind_6) = 1;
% 
%  for i=1:length(IP3)
%      nul3(i)=0.5; 
%      nur3(i)=0.5;   
%  end
% % [max3, maxind3] = max(IP3);
% nul3(1) = 1;
% nur3(ind_7) = 1;
% 
% %  pointer2=1;
% % for i=1:2:length(Epx)
% %     epl1(pointer2) = Epx(i);
% %     epr1(pointer2) = Epx(i+1);
% %     pointer2 = pointer2 + 1;
% % end    
% epl1(length(epl1)+1) = Epsilon_1; 
% epr1(length(epr1)+1) = Epsilon_1; 
% % pointer2=1;
% % for i=1:2:length(Epy)
% %     epl2(pointer2) = Epy(i);
% %     epr2(pointer2) = Epy(i+1);
% %     pointer2 = pointer2 + 1;
% % end    
% epl2(length(epl2)+1) = Epsilon_1; 
% epr2(length(epr2)+1) = Epsilon_1; 
% % 
% % pointer2=1;
% % for i=1:2:length(Epz)
% %     epl3(pointer2) = Epz(i);
% %     epr3(pointer2) = Epz(i+1);
% %     pointer2 = pointer2 + 1;
% % end
% epl3(length(epl3)+1) = Epsilon_1; 
% epr3(length(epr3)+1) = Epsilon_1; 
% 
% 
% ls = 100;
% % Creating the Required FIS
% a=newfis('tank1fis');
% a=addvar(a,'input','PoistionError',[0 1]);
% 
% for i=1: length(IP1)
%     a=addmf(a,'input',1,'around o','Asymdistendmf', [nul1(i) epl1(i) 4+deltaL  nur1(i) epr1(i) 4+deltaL 200 IP1(i)]); 
% end
% 
% a=addvar(a,'input','PoistionRate',[0 1]);
% for i=1:length(IP2)
%  a=addmf(a,'input',2,'around -.17','Asymdistendmf', [nul2(i) epl2(i) 4+deltaL  nur2(i) epr2(i) 4+deltaL 200 IP2(i)]);
% end
% 
% a=addvar(a,'output','valveoutput',[-1 1]);
% for i=1: length(IP3)
% a=addmf(a,'output',1,'around -3','Asymdistendmf', [nul3(i) epl3(i) 4+deltaL  nur3(i) epr3(i) 4+deltaL 200 IP3(i)]);   
% end
% 
% % Rule List Generation
% temp = ModCentreb;
% 
% for k  = 1: size(temp,2)
%     
%   val1 = unique(temp(:,k));                         %unique(temp(:,k)); 
%     
%   for i= 1 : length(val1)
%       
%      for  j= 1: length(temp(:,k))
%          
%          if (temp(j,k)== val1(i))
%          
%                ModCentreb(j,k) = i;
%          end
%               
%      end
%         
%  end
%    
% end
% 
% weights = ones(length(ModCentreb),1);
% Opr= 0.333*ones(length(ModCentreb),1);
% RuleList = [ModCentreb Opr weights];
% % RuleList(1,:)= [1 0 1 1 1];
% % RuleList(2,:)= [2 0 2 1 1];
% % RuleList(3,:)= [3 0 3 1 1];
% 
% if (RuleList(size(RuleList,1),1:4)== RuleList(size(RuleList,1)-1,1:4))
%     deltaL = deltaL + (2/10);
% end
% 
% % 
% a.andMethod = 'customcon';
%   a.aggMethod = 'customagT';
%   a.impMethod = 'customimp';
%  a.defuzzMethod = 'customdefuzi';
% a=addrule(a,RuleList);
% % showfis(a);
% % showrule(a);
% figure(4);
% % gensurf(a);
% gensurf(a,[1 2],1,[30 30],[nan nan],301);
% [x2,y2,z2] = gensurf(a,[1 2],1,[30 30],[nan nan],301);

%% Custom Inference Engine
Nogp = 50 ;  % Number of grid points

for i=1:length(ModCentre)
   RuleList(i,1) = i;
   RuleList(i,2) = i;
   RuleList(i,3) = i;
end

Meshgrid = customInference(Nogp, [ModCentre Epsilon], RuleList(:,1:3));
points2 = Nogp+1;
xcor = reshape (Meshgrid(:,1), [points2,points2]);
ycor = reshape (Meshgrid(:,2), [points2,points2]);
zcor = reshape (Meshgrid(:,3), [points2,points2]);
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

%% Searching the point in the surface formed by Test Data

% Creating database from surface points
GenT5 = [x11 ; y11 ; z1];
rowgt5 = 0;
for t=1:3
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
           
               TF = find(abs(GenT25(rowind1(k),2) - ( GenT24(errindx,2))) <=.009, 1, 'first') ;
           
                    if (TF==1)
                        rowind2 = rowind1(k); 
                        break;
                    end
           
          end

                 
    end

 maxerror(looprep) = maxerr;
 points1 = GenT25(rowind2,:);

 
 
 figure(5);
 surface(x2,y2,z3);
 hold on;
 xi = GenT24(errindx,1);
 yi = GenT24(errindx,2);
 zi = GenT24(errindx,3);
 scatter3(xi,yi,zi,'filled');
 

%     end
 



