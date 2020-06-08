%% Data Driven based Fuzzy Control %%
%% Plotting Simulation Data %%
clc; 
clf;
% clear all;
sim('sltank1.slx');
% sim('sltank');
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
% figure(1);
% plot3(TT3(:,2),TT3(:,3),TT3(:,4),'o');
% hold on;
% x = linspace(min(TT3(:,2)), max(TT3(:,2)), 1000);
% y = linspace(min(TT3(:,3)),max(TT3(:,3)), numel(x))';
% [XX, YY] = meshgrid(x,y);
% F = scatteredInterpolant(TT3(:,2), TT3(:,3), TT3(:,4));
% ZZ = F(XX,YY) ;
% ZZ(ZZ>5) = 5;
% ZZ(ZZ<-5) = -5;
% mesh(XX,YY,ZZ);
%surface(XX,YY,ZZ,50)
    
%% Extracting INformation from database %%

% Normalizing and sorting the Data 

TT5 = TT3;
TT5(:,2) = (TT3(:,2) - min(TT3(:,2))) / (max(TT3(:,2))-min(TT3(:,2)));
TT5(:,3) = (TT3(:,3) - min(TT3(:,3))) / (max(TT3(:,3))-min(TT3(:,3)));
TT5(:,4) = (TT3(:,4) - min(TT3(:,4))) / (max(TT3(:,4))-min(TT3(:,4)));
TT6 = sortrows(TT5,2);
TT6(:,1) = [];

%Indices and Data from CDF Plots of Primary Input
[H, stats] = cdfplot (TT6(:,1));

indicesvalue = [0.11 0.2 0.33 0.5 0.667 0.8 0.89];
Rindices = 0;
for i=1:length(indicesvalue)
   
    Rindices(i) = int32(((find(H.YData> indicesvalue(i),1,'first'))-1)/2);
     
end

Rindices = [1  Rindices  length(TT6(:,1))];

% Generating the points for distending MF
CentrePoint = zeros(length(Rindices),1) ;

for i=1:length(Rindices)

Pointidx = find ( abs (TT6(:,1)- TT6(Rindices(i),1)) < 1e-2 );

    for k = 1:3
        
        summ=0;
        
        for j=1:length(Pointidx)

           summ = summ + TT6(Pointidx(j),k); 

        end

        summ = summ/length(Pointidx);

        CentrePoint(i, k) = summ;
    end
end

% Combining Similar points
%Sorting CentrePoint
% CentrePoint1 = sort (CentrePoint, 'ascending')

% CentrePointb = CentrePoint ;

for m = 1: 3

% k = 1;

for i = 1 : length(CentrePoint(:,m))
      
    idx2 = find ( ceil (10*CentrePoint(:,m)- ceil (10* CentrePoint(i,m))) == 0 );
    
    summ2 = 0;
    
    for j=1:length(idx2)

           summ2 = summ2 + CentrePoint(idx2(j),m);
           CentrePoint(idx2(j),m) = 0;

    end
    
    summ2 = summ2/ length(idx2) ;
    
    if summ2 ~=0 
        
        for n = 1: length(idx2)
            
            ModCentre(idx2(n),m) = summ2;
        
        end
        
    else
        
    end
    
%   k = k+1;
 
    idx2 = 0;

end

end
Match = 0;
% Deleting duplicate rows
temp2 = ModCentre;
for i=1:m
    if (temp2(i,1)== temp2(i+1,1) && temp2(i,2)== temp2(i+1,2) && temp2(i,3)== temp2(i+1,3))
        ModCentre(i,:) = []; 
    end
end
% Copy of centre points for rule generation

ModCentreb = ModCentre;


%% Generating Membership Functions
Centre1 = unique (ModCentre(:,1));
Centre2 = unique (ModCentre(:,2));
Centre3 = unique (ModCentre(:,3));


% Denormalizing Centres
Centre1D = (Centre1 * (max(TT3(:,2))-min(TT3(:,2))) ) + min(TT3(:,2));
Centre2D = (Centre2 * (max(TT3(:,3))-min(TT3(:,3))) ) + min(TT3(:,3));
Centre3D = (Centre3 * (max(TT3(:,4))-min(TT3(:,4))) ) + min(TT3(:,4));

dd1 = PlottingSysDf (Centre1D);
dd2 = PlottingSysDf (Centre2D);
dd3 = PlottingSysDf (Centre3D);
clf;
% x = -1:.01:2;
x = min(Centre1D)-1:(max(Centre1D)-min(Centre1D))/100:Centre1D(length(Centre1D))+1;
figure(1);
 for j=1: size(dd1,1)
 plot(x,dd1(j,:));
 hold on;
 end
 x = min(Centre2D)-1:(max(Centre2D)-min(Centre2D))/100:Centre2D(length(Centre2D))+1;
figure(2);
 for j=1: size(dd2,1)
 plot(x ,dd2(j,:));
 hold on;
 end
x = min(Centre3D)-1:(max(Centre3D)-min(Centre3D))/100:Centre3D(length(Centre3D))+1; 
figure(3);
 for j=1: size(dd3,1)
 plot(x ,dd3(j,:));
  hold on;
 end

%% Creating Fuzzy Controller
 
% Generating the Parameters for input and output distending functions

IP1 = Centre1D; 
 
epr1 = IP1;
nur1 = IP1;
epl1 = IP1;
nul1 = IP1;

%lml1 = [2 2 2 2];
%lmr1 = [2 2 2 2];

epl1(1) = 1;
nul1(1) = 1;

for i =1: length(IP1) - 1
    epr1(i) = (IP1(i+1) - IP1 (i))/2;
    nur1(i) = 0.5;
    epl1(i+1) = epr1(i);
    nul1(i+1) = 0.5;
end

epr1(length(IP1)) = 1;
nur1(length(IP1)) = 1;

% Second Input


IP2 = Centre2D; 
 
epr2 = IP2;
nur2 = IP2;
epl2 = IP2;
nul2 = IP2;

%lml1 = [2 2 2 2];
%lmr1 = [2 2 2 2];

epl2(1) = 1;
nul2(1) = 1;

for i =1: length(IP1) - 1
    epr2(i) = (IP1(i+1) - IP1 (i))/2;
    nur2(i) = 0.5;
    epl2(i+1) = epr2(i);
    nul2(i+1) = 0.5;
end

epr2(length(IP2)) = 1;
nur2(length(IP2)) = 1;

% Third Input
IP3 = Centre3D; 
 
epr3 = IP3;
nur3 = IP3;
epl3 = IP3;
nul3 = IP3;

%lml1 = [2 2 2 2];
%lmr1 = [2 2 2 2];

epl3(1) = 1;
nul3(1) = 1;

for i =1: length(IP3) - 1
    epr3(i) = (IP3(i+1) - IP3 (i))/2;
    nur3(i) = 0.5;
    epl3(i+1) = epr3(i);
    nul3(i+1) = 0.5;
end

epr3(length(IP3)) = 1;
nur3(length(IP3)) = 1;
 
% Plotting first input
% x = -1:.01:IP1(length(IP1))+1;

ls = 100;
 
% Creating the Required FIS
 
a=newfis('tankfis');

a=addvar(a,'input','PoistionError',[-2 2]);
for i=1: length(IP1)
    a=addmf(a,'input',1,'around o','Asymdistendmf', [nul1(i) epl1(i) 2  nur1(i) epr1(i) 2 100 IP1(i)]); 
end

%First Input MFs

% a=addvar(a,'input','PoistionError',[-.25 .25]);
% a=addmf(a,'input',1,'around o','Asymdistendmf', [nul1(1) epl1(1) 2  nur1(1) epr1(1) 2 100 IP1(1)]);     % Parameters  [0.5 0.3 2 0.03 0.02 2 2 -1]    Asymdistendmf
% a=addmf(a,'input',1,'around .17','Asymdistendmf', [nul1(2) epl1(2) 2  nur1(2) epr1(2) 2 100 IP1(2)]);  
% a=addmf(a,'input',1,'around .2','Asymdistendmf', [nul1(3) epl1(3) 2  nur1(3) epr1(3) 2 100 IP1(3)]);  
% a=addmf(a,'input',1,'around .3','Asymdistendmf', [nul1(4) epl1(4) 2  nur1(4) epr1(4) 2 100 IP1(4)]);  
% a=addmf(a,'input',1,'around .5','Asymdistendmf', [nul1(5) epl1(5) 2  nur1(5) epr1(5) 2 100 IP1(5)]);  
% a=addmf(a,'input',1,'around .667','Asymdistendmf', [nul1(6) epl1(6) 2  nur1(6) epr1(6) 2 100 IP1(6)]);  
% a=addmf(a,'input',1,'around .8','Asymdistendmf', [nul1(7) epl1(7) 2  nur1(7) epr1(7) 2 100 IP1(7)]);  

% Second Input MF


a=addvar(a,'input','PoistionRate',[-.15 .15]);
for i=1: length(IP2)
 a=addmf(a,'input',2,'around -.17','Asymdistendmf', [nul2(i) epl2(i) 2  nur2(i) epr2(i) 2 100 IP2(i)]);
end

% a=addvar(a,'input','PoistionRate',[-.5 .55]);
% a=addmf(a,'input',2,'around -.17','Asymdistendmf', [nul2(1) epl2(1) 2  nur2(1) epr2(1) 2 100 IP2(1)]);     % Parameters  [0.5 0.3 2 0.03 0.02 2 2 -1]    Asymdistendmf
% a=addmf(a,'input',2,'around .0143','Asymdistendmf', [nul2(2) epl2(2) 2  nur2(2) epr2(2) 2 100 IP2(2)]);  
% a=addmf(a,'input',2,'around .5027','Asymdistendmf', [nul2(3) epl2(3) 2  nur2(3) epr2(3) 2 100 IP2(3)]);  

% Output MF

a=addvar(a,'output','valveoutput',[-2 2]);
for i=1: length(IP3)
a=addmf(a,'output',1,'around -3','Asymdistendmf', [nul3(i) epl3(i) 2  nur3(i) epr3(i) 2 100 IP3(i)]);   
end

% a=addmf(a,'output',1,'around -3','Asymdistendmf', [nul3(1) epl3(1) 2  nur3(1) epr3(1) 2 100 IP3(1)]);     % Parameters  [0.5 0.3 2 0.03 0.02 2 2 -1]    Asymdistendmf
% a=addmf(a,'output',1,'around -2','Asymdistendmf', [nul3(2) epl3(2) 2  nur3(2) epr3(2) 2 100 IP3(2)]);  
% a=addmf(a,'output',1,'around -1','Asymdistendmf', [nul3(3) epl3(3) 2  nur3(3) epr3(3) 2 100 IP3(3)]);  
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
showfis(a);
showrule(a);
figure(4);
gensurf(a);

% output = evalfis([ 1 2], a); % Output calculation, input = [ 1 2]
