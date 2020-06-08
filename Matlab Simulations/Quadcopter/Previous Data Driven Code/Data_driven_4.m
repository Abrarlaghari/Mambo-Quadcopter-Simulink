%% Data Driven based Fuzzy Control %%
%% Plotting Simulation Data %%
clc; close all; clf;
% clear all;
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
    if (abs (TT3(i,2))< .001 || TT3(i,1)<0.5)
        TT3(i,:)= 0;
   end
end
TT3(~any(TT3,2),:) = [];
x = linspace(min(TT3(:,2)),max(TT3(:,2)),500);
y = linspace(min(TT3(:,3)),max(TT3(:,3)), numel(x))';
[XX, YY] = meshgrid(x,y);
F = scatteredInterpolant(TT3(:,2), TT3(:,3), TT3(:,4));
ZZ = F(XX,YY);
ZZ(ZZ>5) = 5;
ZZ(ZZ<-5) = -5;
% mesh(XX,YY,ZZ);
surfdata=surface(XX,YY,ZZ,50);
x1 = surfdata.XData;
y1 = surfdata.YData;
z1 = surfdata.ZData;
%% Extracting Information from database %%

% Normalizing and sorting the Data 
TT5 = TT3;
TT5(:,2) = (TT3(:,2) - min(TT3(:,2))) / (max(TT3(:,2))-min(TT3(:,2)));
TT5(:,3) = (TT3(:,3) - min(TT3(:,3))) / (max(TT3(:,3))-min(TT3(:,3)));
TT5(:,4) = (TT3(:,4) - min(TT3(:,4))) / (max(TT3(:,4))-min(TT3(:,4)));
[TT6, trind] = sortrows(TT5,2);
TT6(:,1) = [];

% Indices and Data from CDF Plots of Primary Input 
[H, stats] = cdfplot (TT6(:,3));
% datta = H.XData;
indicesvalue = [0.01 0.5 .99];  %[0.01 0.25 0.4 0.5 0.6 0.75 0.99]
Rindices = 0;
for i=1:length(indicesvalue)
   Rindices(i) = int32(((find(H.XData> indicesvalue(i),1,'first'))-1)/2);     
end

GenT25=[];
points1 = [];
Vector = [];
quadsel = 1;
CentrePoint = zeros(length(Rindices),1) ;

  for i=1:length(Rindices)

    Pointidx = find ( abs (TT6(:,3)- TT6(Rindices(i),3)) < 1e-2 );

        for k = 1:3
 
        summ=0;

        for j=1:length(Pointidx)
           summ = summ + TT6(Pointidx(j),k); 
        end
        summ = summ/length(Pointidx);
        CentrePoint(i, k) = summ;
        end
  end
centre1 =   CentrePoint(:,1);
centre2 =   CentrePoint(:,2);
centre3 =   CentrePoint(:,3); 
Centre1D = (centre1 * ((max(TT3(:,2))-min(TT3(:,2))) ) + min(TT3(:,2)));
Centre2D = (centre2 * ((max(TT3(:,3))-min(TT3(:,3))) ) + min(TT3(:,3)));
Centre3D = (centre3 * ((max(TT3(:,4))-min(TT3(:,4))) ) + min(TT3(:,4)));

CentrePoint = [Centre1D Centre2D Centre3D];

%% Starting Loop for iterations
deltaL=0;  
 for looprep = 1:10
      close all;
        clf;
    CentrePoint = [CentrePoint ; GenT25(points1,:)];  % Adding point from simulated surface of test data after each iteration

ModCentre = [CentrePoint(:,1) CentrePoint(:,2) CentrePoint(:,3)];
ModCentreb = ModCentre;

%% Calculating the Epsilon Parameter of each MF
    

                [Centre1D, inds2] = unique(ModCentre(:,1)  ,'rows','stable');
                [Centre2D, inds3] = unique(ModCentre(:,2)  ,'rows','stable');
                [Centre3D, inds4] = unique(ModCentre(:,3)   ,'rows','stable');
                                
                pointer1 = 1;
          for i=1:length(Centre1D)
                Epx(pointer1) =  0.5 *sqrt((2*.2)/((size(CentrePoint(:,1),1))*pi))      ;          %value(i)/(2);
                pointer1 = pointer1 + 1;
                Epx(pointer1) = Epx(pointer1-1);
                pointer1 = pointer1 + 1;
          end
            
           pointer2 = 1;
           for i=1:length(Centre2D)
               Epy(pointer2) =   0.5* sqrt((2*.2)/((size(CentrePoint(:,2),1))*pi)) ;             %0.5 * sqrt((2*.2)/((size(CentrePoint(:,2),1))*pi)) ; %value(i)/(.0001);
               pointer2 = pointer2 + 1;
               Epy(pointer2) = Epy(pointer2-1);
               pointer2 = pointer2 + 1;
           end

           pointer3 = 1;
             for i=1:length(Centre3D)
                   Epz(pointer3) = 0.5* sqrt((2*.2)/((size(CentrePoint(:,3),1))*pi)) ;             %value(i)/(2);

                 pointer3 = pointer3 + 1;
                 Epz(pointer3) = Epz(pointer3-1);
                 pointer3 = pointer3 + 1;
             end


    
%% Plotting Membership Functions
 dd1 = PlottingDMFConEp(Centre1D, Epx);
 dd2 = PlottingDMFConEp(Centre2D, Epy);
 dd3 = PlottingDMFConEp(Centre3D, Epz);

% dd1 = PlottingDMFConEpR(Centre1D, Epx, min(Centre1D), max(Centre1D));
% dd2 = PlottingDMFConEpR(Centre2D, Epy, min(Centre2D), max(Centre2D));
% dd3 = PlottingDMFConEpR(Centre3D, Epz, min(Centre3D), max(Centre3D));


x = min(Centre1D)-1:(max(Centre1D)-min(Centre1D))/100:max(Centre1D)+1;
figure(1);
 for j=1: size(dd1,1)
 plot(x,dd1(j,:));
 axis([-1 1 0 1]);
 hold on;
 end
 x = min(Centre2D)-1:(max(Centre2D)-min(Centre2D))/100:max(Centre2D)+1;
figure(2);
 for j=1: size(dd2,1)
 plot(x ,dd2(j,:));
 axis([-.12 .12 0 1]);
 hold on;
 end
x = min(Centre3D)-1:(max(Centre3D)-min(Centre3D))/100:max(Centre3D)+1; 
figure(3);
 for j=1: size(dd3,1)
 plot(x ,dd3(j,:));
 axis([-1 1 0 1]);
 hold on;
 end
 
%% Creating Fuzzy Controller
IP1 = Centre1D; 
IP2 = Centre2D; 
IP3 = Centre3D; 

 for i=1:length(IP1)
     nul1(i)=0.5; 
     nur1(i)=0.5;   
 end
[max1, maxind1] = max(IP1);
nul1(1) = 1;
nur1(maxind1) = 1;

 for i=1:length(IP2)
     nul2(i)=0.5; 
     nur2(i)=0.5;   
 end
[max2, maxind2] = max(IP2);
nul2(1) = 1;
nur2(maxind2) = 1;

 for i=1:length(IP3)
     nul3(i)=0.5; 
     nur3(i)=0.5;   
 end
[max3, maxind3] = max(IP3);
nul3(1) = 1;
nur3(maxind3) = 1;

pointer2=1;
for i=1:2:length(Epx)
    epl1(pointer2) = Epx(i);
    epr1(pointer2) = Epx(i+1);
    pointer2 = pointer2 + 1;
end    
pointer2=1;
for i=1:2:length(Epy)
    epl2(pointer2) = Epy(i);
    epr2(pointer2) = Epy(i+1);
    pointer2 = pointer2 + 1;
end    
pointer2=1;
for i=1:2:length(Epz)
    epl3(pointer2) = Epz(i);
    epr3(pointer2) = Epz(i+1);
    pointer2 = pointer2 + 1;
end

ls = 100;
% Creating the Required FIS
a=newfis('tank1fis');
a=addvar(a,'input','PoistionError',[-1 1]);

for i=1: length(IP1)
    a=addmf(a,'input',1,'around o','Asymdistendmf', [nul1(i) epl1(i) 4+deltaL  nur1(i) epr1(i) 4+deltaL 200 IP1(i)]); 
end

a=addvar(a,'input','PoistionRate',[-.1 .1]);
for i=1: length(IP2)
 a=addmf(a,'input',2,'around -.17','Asymdistendmf', [nul2(i) epl2(i) 4+deltaL  nur2(i) epr2(i) 4+deltaL 200 IP2(i)]);
end

a=addvar(a,'output','valveoutput',[-1 1]);
for i=1: length(IP3)
a=addmf(a,'output',1,'around -3','Asymdistendmf', [nul3(i) epl3(i) 4+deltaL  nur3(i) epr3(i) 4+deltaL 200 IP3(i)]);   
end

% Rule List Generation
temp = ModCentreb;

for k  = 1: size(temp,2)
    
  val1 = unique(temp(:,k)); 
    
  for i= 1 : length(val1)
      
     for  j= 1: length(temp(:,k))
         
         if (temp(j,k)== val1(i))
         
               ModCentreb(j,k) = i;
         end
              
     end
        
 end
   
end

weights = ones(length(ModCentreb),1);
Opr= ones(length(ModCentreb),1);
RuleList = [ModCentreb Opr weights];
% RuleList(1,:)= [1 0 1 1 1];
% RuleList(2,:)= [2 0 2 1 1];
% RuleList(3,:)= [3 0 3 1 1];

if (RuleList(size(RuleList,1),1:4)== RuleList(size(RuleList,1)-1,1:4))
    deltaL = deltaL + (2/10);
end


a.andMethod = 'customcon';
% a.aggMethod = 'customagT';
% a.impMethod = 'customimp';
% a.defuzzMethod = 'customdefuzi';
a=addrule(a,RuleList);
% showfis(a);
% showrule(a);
figure(4);
gensurf(a);
[x2,y2,z2] = gensurf(a);

%% Generating and plotting the Error surface  

%Generating database
GenT = [x2 ; y2 ; z2];
rowgt = 0;
for t=1:3
row =1;
    for i=1:15
    rowgt = rowgt + 1;
        for k=1:15
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
    
x1 = fix(x1*10^2)/10^2;
y1 = fix(y1*10^2)/10^2;
z1 = fix(z1*10^2)/10^2;
GenT2 = fix(GenT2*10^2)/10^2;
    
for i=1:length(GenT2)
    [raw1, colind6]=find(x1==GenT2(i,1),1,'first');
    if (isempty(colind6))
       [raw1, colind6]=find((x1-GenT2(i,1))<.01,1,'last');    % Must be checked   
    end
    [rowind6 , raw2]=find(y1==GenT2(i,2),1,'first');
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
    for i=1:15
    rowgt4 = rowgt4 + 1;
        for k=1:15
        GenT24(row4,t) = GenT4(rowgt4,k);
        row4 = row4  +1;
        end
    end
end

[maxerr, errindx] = max(abs( GenT24(:,3)));

%% Searching the point in the surface formed by Test Data

% Creating database from surface points
GenT5 = [x1 ; y1 ; z1];
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
 points1 = rowind2;

 
 
 figure(5);
 surface(x2,y2,z3);
 hold on;
 xi = GenT24(errindx,1);
 yi = GenT24(errindx,2);
 zi = GenT24(errindx,3);
 scatter3(xi,yi,zi,'filled');
 

  end
 



