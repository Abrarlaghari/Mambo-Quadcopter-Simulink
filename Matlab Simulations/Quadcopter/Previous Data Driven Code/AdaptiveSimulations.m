%%%%Adaptive Fuzzy Control For Car Lateral Dynamics%%%%%%
%Here We will study the  Change in th e control signal when the
%Co-efficient Frcition changes with the external conditions%%%%
%% Simulating the Lateral Dynamics System and Obtaining the steady state error%%%
    SimOut1 = sim('vehicle_lateral_control');
    Firstdata = ydata.data(1:290,:);
    ErrorData = ydata.data;
    %MaxError = max(ErrorData);
    MaxError1 = ErrorData(60);
    MaxError2 = ErrorData(220);
    disp('Max error are');
    disp(MaxError1);
    disp(MaxError2);
    if ((MaxError1 >= 20.5 || MaxError1 <= 19.5) || (MaxError2 >= .3 || MaxError2 <= -.3))
        disp('Adaptivity Required');
    pathgen(simout.time, simout.data(:,1),simout.data(:,2),simout.data(:,3),simout.data(:,4),simout.data(:,5),simout.data(:,6));

    else
        disp('No Adaptvity Required');
    end 
    %% Correction Loop%%
     i=0;
while ((MaxError1 >= 20.5 || MaxError1 <= 19.5) || (MaxError2 >= .3 || MaxError2 <= -.3))
%% Generating the Correction Parameter %%
    setpoint1=20;
    adaptError1 = MaxError1 - setpoint1;
    corfac1 = evalfis(adaptError1,adaptation);
    disp('Correction Factor 1 Required');
    disp(corfac1);
    
    i=i+1;
    
    setpoint2=0;
    adaptError2 = MaxError2 - setpoint2;
    corfac2 = evalfis(-adaptError2,adaptation);
    disp('Correction Factor 2 Required');
    disp(corfac2);
    
%% Updating the Membership function %%
    temp1=vehicleA.input(1).mf(3).params(5);
    temp1= temp1 + corfac1;
    vehicleA.input(1).mf(3).params(5)= temp1;
    
    temp2=vehicleA.input(1).mf(3).params(2);
    temp2= temp2 + corfac2;
    vehicleA.input(1).mf(3).params(2)= temp2;
    
    disp('Updated Parameter');
    disp(temp1);
    disp(temp2);
%% Checking the updation 
    SimOut2 = sim('vehicle_lateral_control');
    ErrorData= ydata.data;
    %MaxError=max(ErrorData);
    MaxError1 = ErrorData(60);
    MaxError2 = ErrorData(220);
    disp('Max errors after');
    disp(i);
    disp('iteratiion are');
    disp(MaxError1);
    disp(MaxError2);
    if ((MaxError1 >= 20.3 || MaxError1 <= 19.3) || (MaxError2 >= .3 || MaxError1 <= -.3))
        disp('Adaptivity Required');
    else
        disp('No Adaptvity Required');
    end    
end 
      
%% Displaying the Corrected and Original Response %%
   Lastdata = ydata.data(1:290,:);
   time=ydata.time(1:290,:);
   pathgen(simout.time, simout.data(:,1),simout.data(:,2),simout.data(:,3),simout.data(:,4),simout.data(:,5),simout.data(:,6));
   figure;
   plot(time,Firstdata,'r');
   hold on;
   plot(time,Lastdata,'b--');


