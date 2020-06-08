function [sys,x0,str,ts] = SimpleVehicleSFunction(t,x,u,flag)
% This file is a s-function template for simulating the simple vehicle model in Simulink.

% Choosing tire model
TireModel = VehicleDynamicsLateral.TirePacejka();
% Defining tire parameters
TireModel.a0 = 1;
TireModel.a1 = 0;
TireModel.a2 = 800;
TireModel.a3 = 3000;
TireModel.a4 = 50;
TireModel.a5 = 0;
TireModel.a6 = 0;
TireModel.a7 = -1;
TireModel.a8 = 0;
TireModel.a9 = 0;
TireModel.a10 = 0;
TireModel.a11 = 0;
TireModel.a12 = 0;
TireModel.a13 = 0;

%  a0 % Shape factor [-]
%         a1 % Load dependency of lateral friction (*1000) [1/kN]
%         a2 % Lateral friction level (*1000) [-]
%         a3 % Maximum cornering stiffness [N/deg]
%         a4 % Load at maximum cornering stiffness [kN]
%         a5 % Camber sensitivity of cornering stiffness
%         a6 % Load dependency of curvature factor
%         a7 % Curvature factor level
%         a8 % Camber sensitivity of horizontal shift
%         a9 % Load dependency of horizontal shift
%         a10 % Horizontal shift level
%         a11 % Combined load and camber sensitivity of vertical shift
%         a12 % Load dependency of vertical shift
%         a13 % Vertical shift level



%  mT     % Mass of the car (tractor) [kg]
%         IT     % Moment of inertia the car (tractor) [kg * m2]
%         a      % Distance from front axle of the car (tractor) to the center of mass of the car (tractor) [m]
%         b      % Distance from center of mass of the car (tractor) to the front axle of the car (tractor) [m]
%         mF0    % Mass over the front axle [kg]
%         mR0    % Mass over the rear axle [kg]
%         lT     % Wheelbase [m]
%         nF     % Number of front tires
%         nR     % Number of rear tires
%         wT     % Track of the car (tractor)  [m]
%         muy    % Operational friction coefficient
%         tire   % Tire model
%         deltaf % Steering angle [rad]
%         Fxf    % Longitudinal force at F [rad]
%         Fxr    % Longitudinal force at R [rad]

% Choosing vehicle model
VehicleModel = VehicleDynamicsLateral.VehicleSimpleNonlinear();
% Defining vehicle parameters
VehicleModel.mF0 = 700;
VehicleModel.mR0 = 600;
VehicleModel.IT = 10000;
VehicleModel.lT = 3.5;
VehicleModel.nF = 2;
VehicleModel.nR = 2;
VehicleModel.wT = 2;
VehicleModel.muy = .8;
VehicleModel.tire = TireModel;

switch flag,

  %%%%%%%%%%%%%%%%%%
  % Initialization %
  %%%%%%%%%%%%%%%%%%
  case 0,
    [sys,x0,str,ts]=mdlInitializeSizes();

  %%%%%%%%%%%%%%%
  % Derivatives %
  %%%%%%%%%%%%%%%
  case 1,
    sys=mdlDerivatives(t,x,u,VehicleModel);

  %%%%%%%%%%%
  % Outputs %
  %%%%%%%%%%%
  case 3,
    sys=mdlOutputs(t,x,u,VehicleModel);

  %%%%%%%%%%%%%%%%%%%
  % Unhandled flags %
  %%%%%%%%%%%%%%%%%%%
  case { 2, 4, 9 },
    sys = [];

  %%%%%%%%%%%%%%%%%%%%
  % Unexpected flags %
  %%%%%%%%%%%%%%%%%%%%
  otherwise
    DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));

end
% end csfunc

%
%=============================================================================
% mdlInitializeSizes
% Return the sizes, initial conditions, and sample times for the S-function.
%=============================================================================
%
function [sys,x0,str,ts]=mdlInitializeSizes()

% Definitions
sizes = simsizes;
sizes.NumContStates  = 6;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 6;
sizes.NumInputs      = 3;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;

sys = simsizes(sizes);

% Setting initial conditions
x0  = [0 0 0 10 0 0];
str = [];
ts  = [0 0];

% end mdlInitializeSizes
%
%=============================================================================
% mdlDerivatives
% Return the derivatives for the continuous states.
%=============================================================================
%


function sys = mdlDerivatives(t,x,u,vehicle)

% Defining input
vehicle.deltaf = u(1);
vehicle.Fxf = u(2);
vehicle.Fxr = u(3);

% Getting the vehicle model function (state equations)
ModelFunction = @vehicle.Model;

sys = ModelFunction(t,x,0);

% end mdlDerivatives
%
%=============================================================================
% mdlOutputs
% Return the block outputs.
%=============================================================================
%
function sys=mdlOutputs(~,x,~,~)

% Output are all state variables
sys = real(x);

% end mdlOutputs

%% See Also
%
% <../index.html Home> | <TemplateSimpleSimulink.html Template Simple Simulink>
%
