 function Frame(self, varargin)
            articulated = isa(self.Simulator.Vehicle, 'VehicleDynamicsLateral.VehicleArticulated');

            % States
            TOUT = self.Simulator.TSpan;
            XT = self.Simulator.XT;         % Horizontal position [m]
            YT = self.Simulator.YT;         % Vertical position [m]
            PSI = self.Simulator.PSI;       % Vehicle yaw angle [rad]
            VEL = self.Simulator.VEL;       % Vehicle CG velocity [m/s]
            ALPHAT = self.Simulator.ALPHAT; % Vehicle side slip angle [rad]
            dPSI = self.Simulator.dPSI;     % Yaw rate [rad/s]

            % Distances
            a = self.Simulator.Vehicle.a;        % Distance FT [m]
            b = self.Simulator.Vehicle.b;        % Distance TR [m]
            lT = self.Simulator.Vehicle.wT / 2;  % Half width of the vehicle [m]

            % Slip angle @ front axle [rad]
            ALPHAF = atan2((a * dPSI + VEL.*sin(ALPHAT)),(VEL.*cos(ALPHAT)));
            % OBS: No steering angle because it measures the angle between velocity vector and longitudinal axle of the vehicle
            % Slip angle @ rear axle [rad]
            ALPHAR = atan2((-b * dPSI + VEL.*sin(ALPHAT)),(VEL.*cos(ALPHAT)));
            % OBS: When using atan2 and the value reaches 180 degrees the vector becomes strange

            % Velocity
            VF = sqrt((VEL.*cos(ALPHAT)).^2 + (a * dPSI + VEL.*sin(ALPHAT)).^2);
            VR = sqrt((VEL.*cos(ALPHAT)).^2 + (-b * dPSI + VEL.*sin(ALPHAT)).^2);

            % Position of the corners and axles relative to the CG

            % Position vectors 1, 2, 3 e 4 relative to T base (T t1 t2 t3)
            rt1t = [a;lT];                  % Front left
            rt2t = [a;-lT];                 % Front right
            rt3t = [-b;-lT];                % Rear right
            rt4t = [-b;lT];                 % Rear left

            eif = [a;0];                    % Front axle
            eir = [-b;0];                   % Rear axle

            % Preallocating matrix
            rt1i = zeros(length(TOUT),2);
            rt2i = zeros(length(TOUT),2);
            rt3i = zeros(length(TOUT),2);
            rt4i = zeros(length(TOUT),2);

            eff = zeros(length(TOUT),2);
            err = zeros(length(TOUT),2);

            for j=1:length(TOUT)
                % Rotation matrix base (T t1 t2 t3) to (o i j k)
                RTI=[cos(PSI(j)) -sin(PSI(j));sin(PSI(j)) cos(PSI(j))];
                % Position vectors 1, 2, 3 e 4 relative to origin of the inertial reference base (T t1 t2 t3)
                rt1i(j, 1:2) = (RTI * rt1t)';
                rt2i(j, 1:2) = (RTI * rt2t)';
                rt3i(j, 1:2) = (RTI * rt3t)';
                rt4i(j, 1:2) = (RTI * rt4t)';
                % Position of front and rear axle
                eff(j, 1:2) = (RTI * eif);     % Front
                err(j, 1:2) = (RTI * eir);     % Rear
            end

            % Absolute position of corners and axles
            % Absolute position over time

            % Position vectors 1, 2, 3 e 4 relative to o base (o i j k)
            rc1t=[XT YT]+rt1i;
            rc2t=[XT YT]+rt2i;
            rc3t=[XT YT]+rt3i;
            rc4t=[XT YT]+rt4i;

            % Absolute position of the front and rear axle
            ef = [XT YT]+eff;
            er = [XT YT]+err;

            % Time adjustment
            % Exhibition has to be adjusted the number of frames is different from the resolution of the integrator (TSPAN)

            % The variable defines the instants the vehicle will be ploted
            TEMPO = 0:1:TOUT(end);

            % Preallocating matrix
            rc1 = zeros(length(TEMPO),2);
            rc2 = zeros(length(TEMPO),2);
            rc3 = zeros(length(TEMPO),2);
            rc4 = zeros(length(TEMPO),2);

            efrente = zeros(length(TEMPO),2);
            etras = zeros(length(TEMPO),2);

            xxx = zeros(length(TEMPO),2);
            yyy = zeros(length(TEMPO),2);
            alphat = zeros(length(TEMPO),2);
            psii = zeros(length(TEMPO),2);

            alphaf = zeros(length(TEMPO),2);
            alphar = zeros(length(TEMPO),2);

            velf = zeros(length(TEMPO),2);
            velr = zeros(length(TEMPO),2);
            velt = zeros(length(TEMPO),2);

            for i=1:length(TEMPO)
                % Position of corners and axles
                rc1(i, 1:2) = interp1(TOUT, rc1t, TEMPO(i));
                rc2(i, 1:2) = interp1(TOUT, rc2t, TEMPO(i));
                rc3(i, 1:2) = interp1(TOUT, rc3t, TEMPO(i));
                rc4(i, 1:2) = interp1(TOUT, rc4t, TEMPO(i));

                xxx(i, 1:2) = interp1(TOUT, XT, TEMPO(i));
                yyy(i, 1:2) = interp1(TOUT, YT, TEMPO(i));

                % States
                alphat(i, 1:2) = interp1(TOUT, ALPHAT, TEMPO(i));
                psii(i, 1:2) = interp1(TOUT, PSI, TEMPO(i));

                % Slip angles
                alphaf(i, 1:2) = interp1(TOUT, ALPHAF, TEMPO(i));
                alphar(i, 1:2) = interp1(TOUT, ALPHAR, TEMPO(i));

                % Velocity
                velf(i, 1:2) = interp1(TOUT, VF, TEMPO(i));
                velr(i, 1:2) = interp1(TOUT, VR, TEMPO(i));
                velt(i, 1:2) = interp1(TOUT, VEL, TEMPO(i));
            end

            figWidth = 20 ;                             % Defining the width of the figure [centimeters]
            Scale = 1; % Adjust the scale of y in relation to x
            % Margins added to Position to include text labels [left bottom right top] Property - TightInset (read only)
            tight = [1.3 1.3 0.2 0.2];
            PosAxX = figWidth - tight(1) - tight(3);     % Width of the axes (axes position x)
            XLim = [min(XT)-20 max(XT)+10];              % Limits of x
            rangeX = XLim(2) - XLim(1);                  % Range of x
            YLim = [min(YT)-10 max(YT)+10];              % Limits of y
            rangeY = YLim(2) - YLim(1);                  % Range of y
            PosAxY = Scale*PosAxX*rangeY/rangeX;         % Height of the axes (axes position y) - Equivalent to axis

            % Defining figure
            f999 = figure(999);
            % Defining axes
            ax999=gca;
            set(ax999,'NextPlot','add')                 % hold on

            xlabel('Distance [m]')
            ylabel('Distance [m]')

            TEMPOplot = 0:0.05:TOUT(end); % Time for the plots
            for i=1:length(TEMPOplot)
                efrente(i, 1:2) = interp1(TOUT, ef, TEMPOplot(i));
                etras(i, 1:2) = interp1(TOUT, er, TEMPOplot(i));
            end

            plot(ef(:,1),ef(:,2),'r')
            plot(er(:,1),er(:,2),'g')


            for j = 1:length(TEMPO)
                % Coordinates of the corners
                xc = [rc1(j, 1) rc2(j, 1) rc3(j, 1) rc4(j, 1)];
                yc = [rc1(j, 2) rc2(j, 2) rc3(j, 2) rc4(j, 2)];
                % Vehicle
                fill(xc, yc, self.TractorColor);
                p = plot(xxx(j),yyy(j),'ko');
                set(p,'MarkerFaceColor','k','MarkerEdgeColor','k','MarkerSize',6)
            end

            % Adding semitrailer
            if articulated
                PHI = self.Simulator.PHI;           % Relative yaw angle of the semitrailer [rad]
                dPHI = self.Simulator.dPHI;         % Relative yaw rate between the two units [rad/s]

                c = self.Simulator.Vehicle.c;       % Distance from  [m]
                d = self.Simulator.Vehicle.d;       % Distance from  [m]
                e = self.Simulator.Vehicle.e;       % Distance from  [m]
                lS = self.Simulator.Vehicle.wS / 2; % Half width of the vehicle [m]

                % Slip angle semitrailer axle [rad]
                ALPHAM = atan2(((d + e)*(dPHI - dPSI) + VEL.*sin(ALPHAT + PHI) - b * dPSI.*cos(PHI) - c * dPSI.*cos(PHI)),(VEL.*cos(ALPHAT + PHI) + b * dPSI.*sin(PHI) + c * dPSI.*sin(PHI)));
                % Velocity semitrailer axle [m/s]
                VM = sqrt((VEL.*cos(ALPHAT + PHI) + b * dPSI.*sin(PHI) + c * dPSI.*sin(PHI)).^2 + ((d + e)*(dPHI - dPSI) + VEL.*sin(ALPHAT + PHI) - b * dPSI.*cos(PHI) - c * dPSI.*cos(PHI)).^2);
                % CG position
                RS = [XT-(b+c)*cos(PSI)-d * cos(PSI-PHI) YT-(b+c)*sin(PSI)-d * sin(PSI-PHI)];
                % Position vectors 1, 2, 3 e 4 relative to S base (S s1 s2 s3)
                rs1s = [d;lS];              % Front left
                rs2s = [d;-lS];             % Front right
                rs3s = [-e;-lS];            % Rear right
                rs4s = [-e;lS];             % Rear left
                eim = [-e;0];               % Position of semitrailer axle

                rn1i = zeros(length(TOUT),2);
                rn2i = zeros(length(TOUT),2);
                rn3i = zeros(length(TOUT),2);
                rn4i = zeros(length(TOUT),2);
                emm = zeros(length(TOUT),2);

                for j=1:length(TOUT)
                    % Rotation matrix base (S s1 s2 s3) to (o i j k)
                    RSI=[cos(PSI(j)-PHI(j)) -sin(PSI(j)-PHI(j));sin(PSI(j)-PHI(j)) cos(PSI(j)-PHI(j))];
                    % Position vectors 1, 2, 3 e 4 relative to O base (c c1 c2 c3)
                    rn1i(j, 1:2) = (RSI * rs1s)';
                    rn2i(j, 1:2) = (RSI * rs2s)';
                    rn3i(j, 1:2) = (RSI * rs3s)';
                    rn4i(j, 1:2) = (RSI * rs4s)';

                    % Position of semitrailer axle
                    emm(j, 1:2) = (RSI * eim);
                end

                % Position vectors 1, 2, 3 e 4 relative to o base (o i j k)
                rn1t=RS+rn1i;
                rn2t=RS+rn2i;
                rn3t=RS+rn3i;
                rn4t=RS+rn4i;

                em = RS+emm;

                phii = zeros(length(TEMPO),2);
                alpham = zeros(length(TEMPO),2);
                velm = zeros(length(TEMPO),2);
                rn1 = zeros(length(TEMPO),2);
                rn2 = zeros(length(TEMPO),2);
                rn3 = zeros(length(TEMPO),2);
                rn4 = zeros(length(TEMPO),2);
                emsemi = zeros(length(TEMPO),2);

                for i=1:length(TEMPO)
                    phii(i, 1:2) = interp1(TOUT, PHI, TEMPO(i));
                    alpham(i, 1:2) = interp1(TOUT, ALPHAM, TEMPO(i));
                    velm(i, 1:2) = interp1(TOUT, VM, TEMPO(i));

                    rn1(i, 1:2) = interp1(TOUT, rn1t, TEMPO(i));
                    rn2(i, 1:2) = interp1(TOUT, rn2t, TEMPO(i));
                    rn3(i, 1:2) = interp1(TOUT, rn3t, TEMPO(i));
                    rn4(i, 1:2) = interp1(TOUT, rn4t, TEMPO(i));
                end
                for i=1:length(TEMPOplot)
                    emsemi(i, 1:2) = interp1(TOUT, em, TEMPOplot(i));
                end
                plot(em(:,1),em(:,2),'b')

                for j = 1:length(TEMPO)
                    xn = [rn1(j, 1) rn2(j, 1) rn3(j, 1) rn4(j, 1)];
                    yn = [rn1(j, 2) rn2(j, 2) rn3(j, 2) rn4(j, 2)];
                    fill(xn, yn, self.SemitrailerColor);
                end
            end

            % Setting figure
            set(f999,'Units','centimeters')         % Changing units of the figure to centimeters
            set(f999,'PaperUnits','centimeters')    % Changing units of the paper to centimeters
            % Position and size of the figure window
            set(f999,'Position',[0 0 PosAxX+tight(1)+tight(3) PosAxY+tight(2)+tight(4)])
            % Position and size of the figure on the printed page
            set(f999,'PaperPosition',[0 0 PosAxX+tight(1)+tight(3) PosAxY+tight(2)+tight(4)])
            % % Size of the paper
            set(f999,'PaperSize',[PosAxX+tight(1)+tight(3) PosAxY+tight(2)+tight(4)])

            % Setting axes
            set(ax999,'Units','centimeters')        % Changing units of the axes to centimeters
            set(ax999,'XLim',XLim)
            set(ax999,'YLim',YLim)
            set(ax999,'Position',[tight(1:2) PosAxX PosAxY])
            set(ax999,'Box','on','XGrid','on','YGrid','on','ZGrid','on')

            if nargin == 2
                [pathstr, name, ext] = fileparts(varargin{1});

                if not(exist(pathstr, 'file') == 7)
                    mkdir(pathstr);
                end

                print(f999, '-dpdf', strcat(strcat(pathstr, '/', name), '.pdf'))
            end
        end