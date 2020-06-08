function y = customagT(x)

maxVal = ones(1,size(x,2));
y = zeros(1,size(x,2));
for i = 1:size(x,1)
    y = min(maxVal,sum([y;x(i,:)]));
end
% 
% counter1=evalin('base','counter');
% counter1 = counter1 + 1;
% assignin('base','counter',counter1);
% if (counter1 == 1850)
% assignin('base','extweights',x(:,1));
% end
sum1 = sum(x(:,1));
for i = 1:size(x,1)
x(i,1) = x(i,1)./sum1;
end

% Extract the weights at particular instant
%%%extracting Points Tank Fis%%  -0.9255 -0.6034 0.0614 0.0614 0.0614
%%%-0.0186 -0.2091 0.2493 0.9264        %.05
A=0;
% AA=[-0.3291 -0.01253 -0.01253 -0.01253 -0.01253 -0.01253 -0.1083 -0.01253 0.8023]';   % .5
%  AA = centre_f();

AA = evalin('base','ModCentre(:,3)');

for i=1:size(x,1)
A(i)=AA(i)*x(i,1);
end

cor=sum(A);

% E=0;
% EE=[.1 0.01 .03 0.03 0.03 0.01 .03 0.03 0.03 0.03 0.03]';
% for i=1:size(x,1)
% E(i)=EE(i)*x(i,1);
% end
% epsilon= sum(E);
% 
% nnu=0;
% nuu=[0.5 0.1 0.5 0.5 0.5 0.01 .03 0.03 0.03 0.03 0.03]';
% for i=1:size(x,1)
% nnu(i)=nuu(i)*x(i,1);
% end
% nu=sum(nnu);
% 
% ll=[5 5 5 2 2 0.01 .03 0.03 0.03 0.03 0.03]';
% for i=1:size(x,1)
% ll(i)=ll(i)*x(i,1);
% end
% lm=sum(ll);
% lambda=lm;

 y(1,1)=0;%nu;
 y(1,3)=0;%lambda;
 y(1,2)=0;%epsilon;
 y(1,4)=cor;

% y= [nu epsilon lambda cor 0]';