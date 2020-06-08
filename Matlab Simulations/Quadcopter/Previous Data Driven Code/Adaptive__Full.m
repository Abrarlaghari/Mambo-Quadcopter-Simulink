%Running Simulations and Extarcting the reference control signals  
%Refereence Control signal generation Control 
 counter = 10000; 
 SimOut2= sim('vehicle_lateral_control_Ref');
 Refudatapoint = 18;
 controlRef = udataRef.data(Refudatapoint);
 SimOut1 = sim('vehicle_lateral_control');
 Firstdata = ydata.data(1:length(ydata.data),:);
 time=ydata.time(1:length(ydata.time),:);
%  figure(1);
%  pathgen(simout.time, simout.data(:,1),simout.data(:,2),simout.data(:,3),simout.data(:,4),simout.data(:,5),simout.data(:,6));
 figure(1);
 grid on;
 plot(time,Firstdata,'--r');
 hold on;
 
 %% 
   iterations = 0;
   flag_adap = 1;
   adapted1 = 0;
   adapted2 = 0;

  while (flag_adap ~= 0)   
   iterations = iterations + 1;
   counter = 0; 
   udatapoint = 28;
   SimOut1 = sim('vehicle_lateral_control');

  control = udata.data(udatapoint);
  error_u = (controlRef-control);
  display('Error in Control signals is');
  display(error_u);
  
  ErrorData = ydata.data;
  MaxError1 = ErrorData(45);
  MaxError2 = ErrorData(250);
  disp('Max error are');
  disp(MaxError1);
  disp(MaxError2);
%   MaxError2 = 0;
    if ((MaxError1 >= 20.4 || MaxError1 <= 19.6) || (MaxError2 >= .4 || MaxError2 <= -.4))
        disp('Adaptivity Required');
   % pathgen(simout.time, simout.data(:,1),simout.data(:,2),simout.data(:,3),simout.data(:,4),simout.data(:,5),simout.data(:,6));
flag_adap = 1;
    else
        disp('No Adaptvity Required');
        flag_adap = 0;
    end 
  
    %% 
%Extracting Highest Weight Rule and Input at Adaptation instant 
[Maxweight, index]= max(extweights);
display('Maximum Weights is');
display(Maxweight);
display('and rule no is');
display(index);

display ('No of inputs in the rule are');
y1 = VA1.rule(index).antecedent;
yy = y1(1) ;
zz = y1(2) ;
if (yy==0 || zz==0)
    inputsno = 1;
else 
    inputsno = 2;
end
display(inputsno);
%calculating values of input at adaptation instant
inputdata1 = inputdata.data(40,1);
inputdata2 = inputdata.data(40,2);

if (yy ~= 0)
     temp1=VA1.input(1).mf(yy).params;
     val1df = calcdf(inputdata1, temp1);
end 

if (zz ~= 0)
     temp2=VA1.input(2).mf(zz).params;
     val2df = calcdfs(inputdata2, temp2);
else 
    val2df = -10;
end 
%Deciding about the input to be tuned
%% 

if (val1df >= val2df)
   flag=1;
    selinpval = val1df;
else
    flag=2;
    selinpval = val2df;
 end
deltax = selinpval
%% 

%Calculating all the required constants C1, C2, C3, A, B and C

A = [0 .30 -.30 -.25 .25];
% wi = sort(extweights, 'descend')
W = extweights;
%calculating C1
cll = zeros(size(A));
for i = 1: length(A)
    c11(i) = A(i)* W(i);
end
anss = A(4) * W (4);
C1 = sum(c11) - anss;
%calculating C2 and C3 
C2 = sum (W(1: length(W))) - W(index); 
C3 = (1- val2df) / (val2df);
if flag==1
    C3 = (1-val2df)/(val2df);
else
    C3 = (1-val1df)/(val1df);
end
%% 

%Calculating A, B and C
Lm = 100;
% 
% A = ((1-deltax)/deltax)^Lm + C3
% % A=1
% B = 1 + A^(1/Lm)
% 
% C = ((1-deltax)/deltax)
% C=1;

%Extracting Epsilon_old from Membership Function 

if flag==1
Epsilon_old_R = VA1.input(1).mf(yy).params(5);
Epsilon_old_L = VA1.input(1).mf(yy).params(2);
end 

if flag==2 
Epsilon_old_R = VA1.input(2).mf(yy).params(5);
Epsilon_old_L = VA1.input(2).mf(yy).params(2);
end

%% 
%Applying Gradient Descent to calculate new Epsilon
Lms = 0.5;

% ai = VA1.input(1).mf(yy).params(8) 
ai = -.25 ;
wi = Maxweight  ;

Lm_b_Ep1 = - Lm / Epsilon_old_R ;

Lm_b_Ep2 = - Lm / Epsilon_old_L ;

fac1 =  (2* ai * wi )+(ai * C2) + C1;

fac2 = ((wi + C2)^2) ; 

% ffac =  Lms *(error_u) * ((Lm_b_Ep1 * A^((1-Lm)/Lm) * C^(Lm) * fac1) / (B^2 * fac2))
   
    if ((MaxError1 >= 20.4 || MaxError1 <= 19.6))
    ffac1 =  Lms *(error_u) *(deltax *(1-deltax))*((Lm_b_Ep1 *fac1) / (fac2));
    else
    ffac1=0;
    end
    
    if (MaxError1 > 20)
    Epsilon_new_R = Epsilon_old_R + ffac1 ;
    else
    Epsilon_new_R = Epsilon_old_R - ffac1 ;
    end
% Epsilon_new_R = Epsilon_old_R + ffac1 ;

% Epsilon_new_L = Epsilon_old_L + Lms *(-error_u) * ((Lm_b_Ep2 * A^((1-Lm)/Lm) * C^(Lm) * fac1) / (B^2 * fac2))

    if ((MaxError2 >= .4 || MaxError2 <= -.4))
        ffac2 =  Lms *(error_u) *(deltax *(1-deltax))*((Lm_b_Ep2 *fac1) / (fac2));
    else
        ffac2 =0;
    end
    
    if (MaxError2 < 0)
    Epsilon_new_L = Epsilon_old_L + ffac2 ;
    else
    Epsilon_new_L = Epsilon_old_L - ffac2 ;
    end

display ('After')
display(iterations);
display ('Iteration, Epsilon are ');
display (Epsilon_new_R); 
display (Epsilon_new_L); 
 
%% 

%Updating the paramters of the membership function

 if flag==1
VA1.input(1).mf(yy).params(5) = Epsilon_new_R ;
VA1.input(1).mf(yy).params(2) = Epsilon_new_L ;
end 

if flag==2 
 VA1.input(2).mf(yy).params(5) = Epsilon_new_R;
 VA1.input(2).mf(yy).params(2)= Epsilon_new_L;
end

%Again Simulating to check the response 
%% 

SimOut1 = sim('vehicle_lateral_control');
  %control = udata.data(udatapoint)
  %error_u = (controlRef-control) ;
  %display('Error in Control signals is');
  %display(error_u);
 
  ErrorData = ydata.data;
  MaxError1 = ErrorData(45);
  MaxError2 = ErrorData(250);
  
  disp('Max error are');
  disp(MaxError1);
  disp(MaxError2);
  
%   MaxError2 = 0;
   
    if ((MaxError1 >= 20.4 || MaxError1 <= 19.6) || (MaxError2 >= .4 || MaxError2 <= -.4))
        disp('Adaptivity Required');
   % pathgen(simout.time, simout.data(:,1),simout.data(:,2),simout.data(:,3),simout.data(:,4),simout.data(:,5),simout.data(:,6));
        flag_adap = 1;
    else
        disp('No Adaptvity Required');
        flag_adap = 0;
    end
    
    Newdata = ydata.data(1:length(ydata.data),:);
    time=ydata.time(1:length(ydata.time),:);
    plot(time,Newdata,'--');
    hold on;
    
  end 
  
  display('Adaptation Ended after iterations:');
  display(iterations)
%   Lastdata = ydata.data(1:145,:);
%   time=ydata.time(1:145,:);
% figure(2);
%   pathgen(simout.time, simout.data(:,1),simout.data(:,2),simout.data(:,3),simout.data(:,4),simout.data(:,5),simout.data(:,6));
%   figure;
%   plot(time,Firstdata,'r');
%   hold on;
%   plot(time,Lastdata,'b--');
 % pathgen(simout.time, simout.data(:,1),simout.data(:,2),simout.data(:,3),simout.data(:,4),simout.data(:,5),simout.data(:,6));
  
   
   