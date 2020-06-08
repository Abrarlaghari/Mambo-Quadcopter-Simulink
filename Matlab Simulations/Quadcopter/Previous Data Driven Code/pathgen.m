function pathgen (TOUT, XT, YT, PSI, VEL, ALPHAT, dPSI)
            % States
%             TOUT = self.Simulator.TSpan;
%             XT = self.Simulator.XT;         % Horizontal position [m]
%             YT = self.Simulator.YT;         % Vertical position [m]
%             PSI = self.Simulator.PSI;       % Vehicle yaw angle [rad]
%             VEL = self.Simulator.VEL;         % Vehicle CG velocity [m/s]
%             ALPHAT = self.Simulator.ALPHAT; % Vehicle side slip angle [rad]
%             dPSI = self.Simulator.dPSI;     % Yaw rate [rad/s]

            % Distances
            a = 5.6154;        % Distance FT [m]    changed from 1.615
            b = 5.8846;        % Distance TR [m]    changed from 1.88
            lT = 2 / 2;  % Half width of the vehicle [m]

            % Slip angle @ front axle [rad]
            ALPHAF = atan2((a * dPSI + VEL.*sin(ALPHAT)),(VEL.*cos(ALPHAT)));
            % OBS: No steering angle because it measures the angle between velocity vector and longitudinal axle of the vehicle
            % Slip angle @ rear axle [rad]
            ALPHAR = atan2((-b * dPSI + VEL.*sin(ALPHAT)),(VEL.*cos(ALPHAT)));
            % OBS: When using atan2 and the value reaches 180 degrees the vector becomes strange

            % Velocity @ front axle [m/s]
            VF = sqrt((VEL.*cos(ALPHAT)).^2 + (a * dPSI + VEL.*sin(ALPHAT)).^2);
            % Velocity @ rear axle [m/s]
            VR = sqrt((VEL.*cos(ALPHAT)).^2 + (-b * dPSI + VEL.*sin(ALPHAT)).^2);

            % Position of the corners and axles relative to the CG

            % Position vectors 1, 2, 3 e 4 relative to T base (T t1 t2 t3)
            rt1t = [a;lT];                  % Front left
            rt2t = [a;-lT];                 % Front right
            rt3t = [-b;-lT];                % Rear right
            rt4t = [-b;lT];                 % Rear left

            eif = [a;0];                    % Front axle
            eir = [-b;0];                   % Rear axle

            % Absolute position of corners and axles
            % Movement of the points from change of orientation.

            % Preallocating matrix
            rt1i = zeros(length(TOUT),2);
            rt2i = zeros(length(TOUT),2);
            rt3i = zeros(length(TOUT),2);
            rt4i = zeros(length(TOUT),2);

            eff = zeros(length(TOUT),2);
            err = zeros(length(TOUT),2);

            % Loop start
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

            TEMPO = 0:0.05:TOUT(end);

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

%             rn1 = zeros(length(TEMPO),2);
%             rn2 = zeros(length(TEMPO),2);
%             rn3 = zeros(length(TEMPO),2);
%             rn4 = zeros(length(TEMPO),2);

            for i=1:length(TEMPO)
                % Position of corners and axles
                rc1(i, 1:2) = interp1(TOUT, rc1t, TEMPO(i));
                rc2(i, 1:2) = interp1(TOUT, rc2t, TEMPO(i));
                rc3(i, 1:2) = interp1(TOUT, rc3t, TEMPO(i));
                rc4(i, 1:2) = interp1(TOUT, rc4t, TEMPO(i));

                efrente(i, 1:2) = interp1(TOUT, ef, TEMPO(i));
                etras(i, 1:2) = interp1(TOUT, er, TEMPO(i));

                % Position of CG
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


            figWidth = 35 ;                             % Defining the width of the figure [centimeters]
            Scale = 5; % Adjust the scale of y in relation to x
            % Margins added to Position to include text labels [left bottom right top] Property - TightInset (read only)
            tight = [2 2 2 2];
            PosAxX = figWidth - tight(1) - tight(3) ;    % Width of the axes (axes position x)
            
            XLim = [min(XT)-20 max(XT)+10];              % Limits of x
            rangeX = XLim(2) - XLim(1);                  % Range of x
            YLim = [min(YT)-10 max(YT)+10];              % Limits of y
            % YLim = [min(YT)-10 max(YT)+10];              % Limits of y
            rangeY = YLim(2) - YLim(1);                  % Range of y
            PosAxY = Scale*PosAxX*rangeY/rangeX ;        % Height of the axes (axes position y) - Equivalent to axis
            
            % Defining figure
            f666 = figure(666);
            % Defining axes
            ax666=gca;
            set(ax666,'NextPlot','add')                 % hold on

            % Description
            xlabel('Distance [m]');
            ylabel('Distance [m]');

            % First frame

            % Velocity vectors - Script "vector.m"
            Vector(efrente(1,1:2),(alphaf(1)+psii(1)),velf(1),'r');
            Vector(etras(1,1:2),(alphar(1)+psii(1)),velr(1),'g');

            % Corner coordinates for the first frame
            xc = [rc1(1,1) rc2(1,1) rc3(1,1) rc4(1,1)];
            yc = [rc1(1,2) rc2(1,2) rc3(1,2) rc4(1,2)];

            % The vehicle
            fill(xc, yc, 'b')

            
%             if nargin == 2
%                 [pathstr, name, ext] = fileparts(varargin{1});
% 
%                 if not(exist(pathstr, 'file') == 7)
%                     mkdir(pathstr);
%                 end
% 
%                 % Setting figure
%                 set(f666,'Units','centimeters')         % Changing units of the figure to centimeters
%                 set(f666,'PaperUnits','centimeters')    % Changing units of the paper to centimeters
%                 % Position and size of the figure window
%                 set(f666,'Position',[0 0 PosAxX+tight(1)+tight(3) PosAxY+tight(2)+tight(4)])
%                 % Position and size of the figure on the printed page
%                 set(f666,'PaperPosition',[0 0 PosAxX+tight(1)+tight(3) PosAxY+tight(2)+tight(4)])
%                 % % Size of the paper
%                 set(f666,'PaperSize',[PosAxX+tight(1)+tight(3) PosAxY+tight(2)+tight(4)])
%                 set(ax666,'Units','centimeters')        % Changing units of the axes to centimeters
% 
%                 % Setting axes
%                 set(ax666,'XLim',XLim)
%                 set(ax666,'YLim',YLim)
%                 set(ax666,'Position',[tight(1:2) PosAxX PosAxY])
%                 set(ax666,'Box','on','XGrid','on','YGrid','on','ZGrid','on')
% 
%                 % Initializing gif
%                 frame = getframe(666);
%                 im = frame2im(frame);
%                 [A, map] = rgb2ind(im, 256, 'nodither');
%                 imwrite(A, map, strcat(pathstr, '/', name, '.gif'), 'LoopCount', Inf, 'DelayTime', 0.05);
%             end

            % Remaining frames
            %
            for j = 1:length(TEMPO)
                % Axles
                plot(efrente(:,1),efrente(:,2),'r')
                plot(etras(:,1),etras(:,2),'g')

                % Coordinates of the corners
                xc = [rc1(j, 1) rc2(j, 1) rc3(j, 1) rc4(j, 1)];
                yc = [rc1(j, 2) rc2(j, 2) rc3(j, 2) rc4(j, 2)];

                % Vehicle
                fill(xc, yc, 'b')

                % Velocity vectors
                % Different colors
                Vector(efrente(j, 1:2),(alphaf(j)+psii(j)),velf(j),'r');
                Vector(etras(j, 1:2),(alphar(j)+psii(j)),velr(j),'g');

%                 if articulated
%                     plot(emsemi(:,1),emsemi(:,2),'b')
%                     xn = [rn1(j, 1) rn2(j, 1) rn3(j, 1) rn4(j, 1)];
%                     yn = [rn1(j, 2) rn2(j, 2) rn3(j, 2) rn4(j, 2)];
%                     fill(xn, yn, self.SemitrailerColor)
%                     self.Vector(emsemi(j, 1:2),(alpham(j)+psii(j)-phii(j)),velm(j),'b');
%                 end

                % Setting figure
                 set(f666,'Units','centimeters')         % Changing units of the figure to centimeters
%                 set(f666,'PaperUnits','centimeters')    % Changing units of the paper to centimeters
                 % Position and size of the figure window
                 set(f666,'Position',[0 0 PosAxX+tight(1)+tight(3) PosAxY+tight(2)+tight(4)])
%                 % Position and size of the figure on the printed page
%                 set(f666,'PaperPosition',[0 0 PosAxX+tight(1)+tight(3) PosAxY+tight(2)+tight(4)])
%                 % % Size of the paper
%                 set(f666,'PaperSize',[PosAxX+tight(1)+tight(3) PosAxY+tight(2)+tight(4)])
                 set(ax666,'Units','centimeters')        % Changing units of the axes to centimeters

                % Setting axes
                set(ax666,'XLim',XLim)
                set(ax666,'YLim',YLim)
                set(ax666,'Position',[tight(1:2) PosAxX PosAxY])
                set(ax666,'Box','on','XGrid','on','YGrid','on','ZGrid','on')
%                 if nargin == 2
%                     [pathstr, name, ext] = fileparts(varargin{1});
% 
%                     % Adding the current frame to the initialized gif
%                     frame = getframe(666);
%                     im = frame2im(frame);
%                     [A, map] = rgb2ind(im, 256, 'nodither');
%                     imwrite(A, map, strcat(pathstr, '/', name, '.gif'), 'WriteMode', 'append', 'DelayTime', 0.05);
%                 end

                pause(1e-10)                 % OBS: It has to be the same value of the time adjustment

                cla(ax666);                    % Clearing axes
            end

            % Last frame
            % Last image seen when the animation is over

            % Axles
            plot(efrente(:,1),efrente(:,2),'r')
            plot(etras(:,1),etras(:,2),'g')

            % Coordinates of the corners of the last frame
            xc = [rc1(end, 1) rc2(end, 1) rc3(end, 1) rc4(end, 1)];
            yc = [rc1(end, 2) rc2(end, 2) rc3(end, 2) rc4(end, 2)];

            % Vehicle
            fill(xc, yc, 'b')

            Vector(efrente(end, 1:2),(alphaf(end)+psii(end)),velf(end),'r');
            Vector(etras(end, 1:2),(alphar(end)+psii(end)),velr(end),'g');

end   
 