
Noise = 0.1; 
nu= [0.5 0.5 0.5];
Ep= [0.33 0.33 0.33];
Centre1D = [0 0.5 1];
[maxx,ind_5] = max(Centre1D);

[dd11, dd12] = PlottingT2DMF_a_change(Centre1D, Ep, ind_5 , nu, Noise);

x = min(Centre1D)-1:(max(Centre1D)-min(Centre1D))/100:max(Centre1D)+1;
figure(1);
for j=1: size(dd11,1)
    plot(x,dd11(j,:),'b',x,dd12(j,:),'r');
    axis([-.2 1.2 0 1.05]);
    hold on;
end

%% Plotting Output Membership Functions

Centre2D = [-1 -.7 0 .7 1];
nu= [0.5 0.5 0.5 0.5 0.5];
Ep= [0.33 0.33 0.33 0.33 0.33];

[maxx,ind_5] = max(Centre2D);

[dd11, dd12] = PlottingT2DMF_a_change(Centre2D, Ep, ind_5 , nu, Noise);

x = min(Centre2D)-1:(max(Centre2D)-min(Centre2D))/100:max(Centre2D)+1;
figure(2);
for j=1: size(dd11,1)
    plot(x,dd11(j,:),'b',x,dd12(j,:),'r');
    axis([-1.5 1.5 0 1.05]);
    hold on;
end

%% Plotting the surface
Nogp = 100;  % Number of grid points

ModCentr = [   0   0   -.9;
                0.5 0.5 -.7;
                1   1   0;
                1   1   .7;
                1   1   .9 ];

RuleList = [   3    2    5;
               1    2    1;
               2    2    3;
               2    3   2;
               2    1   4];


Meshgrid = customInferenceT2df_a(Nogp, ModCentr(:,1:3), RuleList(:,1:3), Noise);
points2 = Nogp+1;
xcor = reshape (Meshgrid(:,1), [points2,points2]);
ycor = reshape (Meshgrid(:,2), [points2,points2]);
zcorL = reshape (Meshgrid(:,3), [points2,points2]);
zcorU = reshape (Meshgrid(:,4), [points2,points2]);
zcorC = reshape (Meshgrid(:,5), [points2,points2]);
figure(4);
ConsurfL = surface(xcor,ycor,zcorL);
figure(4);
ConsurfU = surface(xcor,ycor,zcorU);
figure(5);
ConsurfC = surface(xcor,ycor,zcorC);


