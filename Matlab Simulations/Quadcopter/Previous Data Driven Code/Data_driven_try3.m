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
    if (abs (TT3(i,2))< .001 || TT3(i,1)<0.5)%
        TT3(i,:)= 0;
   end
end

TT3(~any(TT3,2),:) = [];
figure(10);
plot3(TT3(:,2),TT3(:,3),TT3(:,4),'o');
hold on;
x = linspace(min(TT3(:,2)), max(TT3(:,2)),500);
y = linspace(min(TT3(:,3)),max(TT3(:,3)), numel(x))';
[XX, YY] = meshgrid(x,y);
F = scatteredInterpolant(TT3(:,2), TT3(:,3), TT3(:,4));
ZZ = F(XX,YY) ;
ZZ(ZZ>5) = 5;
ZZ(ZZ<-5) = -5;
% mesh(XX,YY,ZZ);
surfdata=surface(XX,YY,ZZ,50);
x1 = surfdata.XData;
y1 = surfdata.YData;
z1 = surfdata.ZData;
  
%% Extracting INformation from database %%

% Normalizing and sorting the Data 
TT5 = TT3;
TT5(:,2) = (TT3(:,2) - min(TT3(:,2))) / (max(TT3(:,2))-min(TT3(:,2)));
TT5(:,3) = (TT3(:,3) - min(TT3(:,3))) / (max(TT3(:,3))-min(TT3(:,3)));
TT5(:,4) = (TT3(:,4) - min(TT3(:,4))) / (max(TT3(:,4))-min(TT3(:,4)));
[TT6, trind] = sortrows(TT5,2);
%TT6 = TT5;
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
% Rindices = [1  Rindices  length(TT6(:,3))];

% maxerror(1) = 0.11;
% Tolerence = .1;
%  looptimes = 0;
%  while(maxerror(looptimes) > Tolerence)
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
% NewPoint=[];
%% Generating Surface Array for initial points pickup

% InitArray = [x1 ; y1 ; z1];
% init = 0;
% for t=1:3
% row =1;
%     for i=1:500
%     init = init + 1;
%         for k=1:500
%         dataArray(row,t) = InitArray(init,k);
%         row = row+1;
%         end
%     end
% end
% 
% CentrePoint = [dataArray(1,:); dataArray(length(dataArray)/4,:);dataArray(148247,:); dataArray(length(dataArray)*2.85/4,:);dataArray(length(dataArray)-5,:)];

%% Starting Loop for iterations
  
 for looprep = 1:20
close all; clf;

 CentrePoint = [CentrePoint ; GenT25(points1,:)];  % Adding point from simulated surface of test data after each iteration

%% New Attempt to generate centre points

% separatingv the columns
centre1 =   CentrePoint(:,1);
centre2 =   CentrePoint(:,2);
centre3 =   CentrePoint(:,3);

% % Defining the tolerance level for MF centre points
% t1= ((max(TT3(:,2))-min(TT3(:,2)))/20-.01);
% t2 = ((max(TT3(:,3))-min(TT3(:,3)))/20-.001);
% t3 = ((max(TT3(:,4))-min(TT3(:,4)))/20-.01);
% 
% % Merging points below tolerance limits
% for i=1:(length(centre1))-1
%    for j=i+1:length(centre1)
%        if (abs(centre1(i)-centre1(j))<t1)
%             
%             if (centre1(i<0))
%                     if(centre1(i)>=centre1(j)) 
%                     centre1(j) = centre1(i); 
%                     else
%                     centre1(i) = centre1(j);
%                     end
%             else
%                     if(centre1(i)<centre1(j)) 
%                     centre1(j) = centre1(i); 
%                     else
%                     centre1(i) = centre1(j);
%                     end
%             end
%             
%        end
%        
%    end
% end
% 
% for i=1:(length(centre2))-1
%    for j=i+1:length(centre2)
%        if (abs(centre2(i)-centre2(j))<t2)
%             
%             if (centre2(i<0))
%                     if(centre2(i)>=centre2(j)) 
%                     centre2(j) = centre2(i); 
%                     else
%                     centre2(i) = centre2(j);
%                     end
%             else
%                     if(centre2(i)<centre2(j)) 
%                     centre2(j) = centre2(i); 
%                     else
%                     centre2(i) = centre2(j);
%                     end
%             end
%             
%        end
%        
%    end
% end
% 
% for i=1:(length(centre3))-1
%    for j=i+1:length(centre3)
%        if (abs(centre3(i)-centre3(j))<t3)
%             
%             if (centre3(i<0))
%                     if(centre3(i)>=centre3(j)) 
%                     centre3(j) = centre3(i); 
%                     else
%                     centre3(i) = centre3(j);
%                     end
%             else
%                     if(centre3(i)<centre3(j)) 
%                     centre3(j) = centre3(i); 
%                     else
%                     centre3(i) = centre3(j);
%                     end
%             end
%             
%        end
%        
%    end
% end

ModCentre = [centre1 centre2 centre3];
% ModCentre = unique(ModCentre, 'rows', 'stable');
ModCentreb = ModCentre;
%% Calculating the Epsilon Parameter of each MF

% Calculating the Euclidean Distnace
    if (looprep ==1)                % For first run only
      

        for i= 1: length(ModCentre(:,1))

            for j= 1: length(ModCentre(:,1))
               Euc1(i,j) = sqrt( (ModCentre(j,1) - ModCentre(i,1))^2 + (ModCentre(j,2) - ModCentre(i,2))^2 );  
            end

            Euc1(Euc1==0) = 10000;  % Making self distnace high enough
            [value(i), ind1(i)] = min(Euc1(i,:));
        end
        
% Finding Epsilon for each Membership Function        
            
            [Centre1D, inds2] = unique(ModCentre(:,1)  ,'rows','stable');
            [Centre2D, inds3] = unique(ModCentre(:,2)  ,'rows','stable');
            [Centre3D, inds4] = unique(ModCentre(:,3)   ,'rows','stable');
 
            pointer1 = 1;
       for i=1:length(Centre1D)
           
            Epx(pointer1) = value(i)/(1.4142);
%             Epx(pointer1) = (abs (ModCentre(ind1(inds2(i)),1)- Centre1D(i)))/2;
%             if (Epx(pointer1)==0)
%              [w, e] = unique(abs((Centre1D(i)-Centre1D)));
%              Epx(pointer1) = (abs (Centre1D(e(2))- Centre1D(i)))/2;
%             end
            pointer1 = pointer1 + 1;
            Epx(pointer1) = Epx(pointer1-1);
            pointer1 = pointer1 + 1;
       end
       pointer2 = 1;
       for i=1:length(Centre2D)
           Epy(pointer2) =value(i)/(1.41);
%              Epy(pointer2) = (abs (ModCentre(ind1(inds3(i)),2)- Centre2D(i)))/2;  
%              if (Epy(pointer2)==0)
%              [w, e] = unique(abs((Centre2D(i)-Centre2D)));
%              Epy(pointer2) = (abs (Centre2D(e(2))- Centre2D(i)))/2;
%             end
             pointer2 = pointer2 + 1;
             Epy(pointer2) = Epy(pointer2-1);
             pointer2 = pointer2 + 1;
       end
       pointer3 = 1;
         for i=1:length(Centre3D)
               Epz(pointer3) = value(i)/(1.4142);
%              Epz(pointer3) = (abs (ModCentre(ind1(inds4(i)),3)- Centre3D(i)))/2;  
%               if (Epz(pointer3)==0)
%               [w, e] = unique(abs((Centre3D(i)-Centre3D)));
%               Epz(pointer3) = (abs (Centre3D(e(2))- Centre3D(i)))/2;
%               end
             pointer3 = pointer3 + 1;
             Epz(pointer3) = Epz(pointer3-1);
             pointer3 = pointer3 + 1;
         end
       
%             Epx(pointer1) = (abs (ModCentre(ind1,1)- ModCentre(i,1)))/2;
%             Epy(pointer1) = (abs (ModCentre(ind1,2)- ModCentre(i,2)))/2;
%             Epz(pointer1) = (abs (ModCentre(ind1,3)- ModCentre(i,3)))/2;
%             pointer1 = pointer1 + 1;        % duplicating the Epsilon values for EPl and EPr
%             Epx(pointer1) = Epx(pointer1-1);
%             Epy(pointer1) = Epy(pointer1-1);
%             Epz(pointer1) = Epz(pointer1-1);
%             pointer1 = pointer1 + 1;

%         end
                Epx(1) = 1; Epy(1) = 1; Epz (1) = 1;

                [maxx, maxind1] = max(Centre1D);
                [maxx, maxind2] = max(Centre2D);
                [maxx, maxind3] = max(Centre3D); 

                Epx(2*maxind1) = 1; Epy(2*maxind2) = 1; Epz(2*maxind3) = 1;

        
    else
       
            [Centre1D, inds2] = unique(ModCentre(:,1)  ,'rows','stable');
            [Centre2D, inds3] = unique(ModCentre(:,2)  ,'rows','stable');
            [Centre3D, inds4] = unique(ModCentre(:,3)   ,'rows','stable');
        
        
           for j= 1: length(ModCentre(:,1))
                Euc2(j) = sqrt( (ModCentre(j,1) - ModCentre(length(ModCentre(:,1)),1))^2 + (ModCentre(j,2) - ModCentre(length(ModCentre(:,1)),2))^2 );  
           end
        
                Euc2(length(ModCentre(:,1))) = 10000;              % Making seold distnace high enough
                [valu2, ind1] = min(Euc2);
                
                Epxn = valu2 /(1.4142);
                Epyn = valu2/(1.4142);
                Epzn = valu2 /(1.4142);
                
%                 Epxn = (abs (ModCentre(ind1,1)- ModCentre(length(ModCentre(:,1)),1)))/2;
%                 Epyn = (abs (ModCentre(ind1,2)- ModCentre(length(ModCentre(:,1)),2)))/2;
%                 Epzn = (abs (ModCentre(ind1,3)- ModCentre(length(ModCentre(:,1)),3)))/2;

                Epx = [Epx Epxn Epxn];
                Epy = [Epy Epyn Epyn];
                Epz = [Epz Epzn Epzn];

    end
        
        
%% Generating Membership Functions
%Centre1D = ModCentre(:,1);
%Centre2D = ModCentre(:,2);
%Centre3D = ModCentre(:,3);

%Denormalizing Centres
%Centre1D = (centre1 * ((max(TT3(:,2))-min(TT3(:,2))) ) + min(TT3(:,2)));

dd1 = PlottingDMFConEp(Centre1D, Epx);
dd2 = PlottingDMFConEp(Centre2D, Epy);
dd3 = PlottingDMFConEp(Centre3D, Epz);
clf;
% x = -1:.01:2;
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
% Generating the Parameters for input and output distending functions

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

% Plotting first input
% x = -1:.01:IP1(length(IP1))+1;
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
% 
% epr3(length(IP3)) = 1;
% nur3(length(IP3)) = 1;
 
% Plotting first input
% x = -1:.01:IP1(length(IP1))+1;
ls = 100;
% Creating the Required FIS
a=newfis('tank1fis');
a=addvar(a,'input','PoistionError',[-1 1]);

for i=1: length(IP1)
    a=addmf(a,'input',1,'around o','Asymdistendmf', [nul1(i) epl1(i) 5  nur1(i) epr1(i) 5 200 IP1(i)]); 
end

%First Input MFs
% a=addvar(a,'input','PoistionError',[-.25 .25]);
% a=addmf(a,'input',1,'around o','Asymdistendmf', [nul(1) 1 5  nur(1) .46 5 100 IP1(1)]);     % Parameters  [0.5 0.3 2 0.03 0.02 2 2 -1]    Asymdistendmf
% a=addmf(a,'input',1,'around .17','Asymdistendmf', [nul(2) .46 5  nur(2) .46 5 100 IP1(2)]);  
% a=addmf(a,'input',1,'around .2','Asymdistendmf', [nul(3) .46 5  nur(3) 1 5 100 IP1(3)]);  
% a=addmf(a,'input',1,'around .3','Asymdistendmf', [nul1(4) epl1(4) 2  nur1(4) epr1(4) 2 100 IP1(4)]);  
% a=addmf(a,'input',1,'around .5','Asymdistendmf', [nul1(5) epl1(5) 2  nur1(5) epr1(5) 2 100 IP1(5)]);  
% a=addmf(a,'input',1,'around .667','Asymdistendmf', [nul1(6) epl1(6) 2  nur1(6) epr1(6) 2 100 IP1(6)]);  
% a=addmf(a,'input',1,'around .8','Asymdistendmf', [nul1(7) epl1(7) 2  nur1(7) epr1(7) 2 100 IP1(7)]);  
% Second Input MF

a=addvar(a,'input','PoistionRate',[-.1 .1]);
for i=1: length(IP2)
 a=addmf(a,'input',2,'around -.17','Asymdistendmf', [nul2(i) epl2(i) 5  nur2(i) epr2(i) 5 200 IP2(i)]);
end
% a=addvar(a,'input','PoistionRate',[-.5 .55]);
% a=addmf(a,'input',2,'around -.17','Asymdistendmf', [nul(1) 1 2  nur(1) .086 2 100 IP2(1)]);     % Parameters  [0.5 0.3 2 0.03 0.02 2 2 -1]    Asymdistendmf
% a=addmf(a,'input',2,'around .0143','Asymdistendmf', [nul(2) .086 2  nur(2) .086 2 100 IP2(2)]);  
% a=addmf(a,'input',2,'around .5027','Asymdistendmf', [nul(3) .086 2  nur(3) 1 2 100 IP2(3)]);  
% Output MF

a=addvar(a,'output','valveoutput',[-1 1]);
for i=1: length(IP3)
a=addmf(a,'output',1,'around -3','Asymdistendmf', [nul3(i) epl3(i) 5  nur3(i) epr3(i) 5 200 IP3(i)]);   
end
% a=addmf(a,'output',1,'around -3','Asymdistendmf', [nul(1) 1 5  nur(1) .46 5 100 IP3(1)]);     % Parameters  [0.5 0.3 2 0.03 0.02 2 2 -1]    Asymdistendmf
% a=addmf(a,'output',1,'around -2','Asymdistendmf', [nul(2) .46 5  nur(2) .46 5 100 IP3(2)]);  
% a=addmf(a,'output',1,'around -1','Asymdistendmf', [nul(3) .46 5  nur(3) 1 5 100 IP3(3)]);  
% a=addmf(a,'output',1,'around 0','Asymdistendmf', [nul3(4) epl3(4) 2  nur3(4) epr3(4) 2 100 IP3(4)]);  
% a=addmf(a,'output',1,'around 1','Asymdistendmf', [nul3(5) epl3(5) 2  nur3(5) epr3(5) 2 100 IP3(5)]);  
% a=addmf(a,'output',1,'around 2','Asymdistendmf', [nul3(6) epl3(6) 2  nur3(6) epr3(6) 2 100 IP3(6)]);  
% a=addmf(a,'output',1,'around 4','Asymdistendmf', [nul3(7) epl3(7) 2  nur3(7) epr3(7) 2 100 IP3(7)]);  
% Creating Rule list
% Static Rule List
% ruleList = [ ...
% 1 3 1 1 1
% 2 1 3 1 1
% 3 2 3 1 1
% 4 3 3 1 1
% 4 4 3 1 1
% 5 5 3 1 1
% 6 6 2 1 1
% 7 7 3 1 1
% 8 8 4 1 1] ;
% Dynamic Rule list
% [aa1 bb1] = sort(ModCentre(:,1));
% [aa2 bb2] = sort(ModCentre(:,2));
% [aa3 bb3] = sort(ModCentre(:,3));
% %First column of rule list
% for i=1:length(ModCentreb)-1
%     for j = i+1:length(ModCentreb)
%         if (ModCentreb(bb1(i),1)== ModCentreb(bb1(j),1))
%         bb1(j) = bb1(i);
%         end
%     end
%     
% end
%     
% %Second column of rule list
% for i=1:length(ModCentreb)-1
%     for j = i+1:length(ModCentreb)
%         if (ModCentreb(bb2(i),2)== ModCentreb(bb2(j),2))
%         bb2(j) = bb2(i);
%         end
%     end
%     
% end
% %Third column of rule list
% 
% for i=1:length(ModCentreb)-1
%     for j = i+1:length(ModCentreb)
%         if (ModCentreb(bb3(i),3)== ModCentreb(bb3(j),3))
%         bb3(j) = bb3(i);
%         end
%     end
%     
% end


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

if (RuleList(size(RuleList,1),1:4)== RuleList(size(RuleList,1)-1,1:4))
    RuleList(size(RuleList,1)-1,5)= RuleList(size(RuleList,1)-1,5)+1; 
    RuleList(size(RuleList,1),:) = [];
end


% rulelist = [bb1 bb2 bb3];
% a=addmf(a,'input',1,'good','gaussmf',[1.5 5]);
% a=addmf(a,'input',1,'excellent','gaussmf',[1.5 10]);
% a=addvar(a,'input','food',[0 10]);
% a=addmf(a,'input',2,'rancid','trapmf',[-2 0 1 3]);
% a=addmf(a,'input',2,'delicious','trapmf',[7 9 10 12]);
% a=addvar(a,'output','tip',[0 30]);
% a=addmf(a,'output',1,'cheap','trimf',[0 5 10]);
% a=addmf(a,'output',1,'average','trimf',[10 15 20]);
% a=addmf(a,'output',1,'generous','trimf',[20 25 30]);
% ruleList=[ ...
% 1 1 1 1 2
% 2 0 2 1 1
% 3 2 3 1 2 ];
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
% output = evalfis([ 1 2], a); % Output calculation, input = [ 1 2]
%% Comparing the points between the generated surface and original data 

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

%Generating and PLotting the error surface

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

z33 = z2 + z3 ;
figure(6);
surface(x2,y2,z33);

% Searching for relevnat elements

% Generating the error points--->Second Attempt
% Dividing the error surface into 4 quadranrts

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

% midpoint1 = (min(GenT24(:,1)) + max(GenT24(:,1)))/2;
% midpoint2 = (min(GenT24(:,2)) + max(GenT24(:,2)))/2;
% 
% for i=1:length(GenT24)
%  
%     if (GenT24(i,1) >= midpoint1)
%     
%         if (GenT24(i,2)<= midpoint2)
%             quad1(i,:) = GenT24(i,:);  
%         else
%         
%             quad4(i,:) = GenT24(i,:);    
%         end     
%     else  
%     
%          if (GenT24(i,2)<= midpoint2)
%             quad2(i,:) = GenT24(i,:);    
%          else
%             quad3(i,:) = GenT24(i,:);
%          end
%     end
%   
% end
% 
% quad1( ~any(quad1,2), : ) = []; % delete empty rows
% quad2( ~any(quad2,2), : ) = [];
% quad3( ~any(quad3,2), : ) = [];
% quad4( ~any(quad4,2), : ) = [];
% %determining the quadrant for current loop
% 
%     if(quadsel ==1)
%        [maxerr, errindx] = max(abs(quad1(:,3)));
%         searchquad = quad1;
%     end
% 
%     if(quadsel==2)
%         [maxerr, errindx] = max(abs(quad2(:,3)));
%         searchquad = quad2;
%     end
%     
%     if(quadsel==3)
%         [maxerr, errindx] = max(abs(quad3(:,3)));
%          searchquad = quad3;  
%     end
%     
%     if(quadsel==4)
%             [maxerr, errindx] = max(abs(quad4(:,3)));
%             searchquad = quad4;
%     end
% 
% % Next Quadrant Selection
%     if (quadsel~=4)
%        quadsel = quadsel + 1;
%     else
%         quadsel =1;
%      end

% %% Searching the Index of maximum error in original data i.e. TT3 
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

          % if point index is not found we can extend the flexibility of
          % range
         
    end

 maxerror(looprep) = maxerr;
 points1 = rowind2;

  end
