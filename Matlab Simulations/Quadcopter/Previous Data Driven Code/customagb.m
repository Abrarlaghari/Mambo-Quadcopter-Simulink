function y = customagb(x)

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


sum1=sum(x(:,1));
for i=1:size(x,1)
x(i,1)=x(i,1)./sum1;
end

% Extract the weights at particular instant


%-3.058 -2.093 -1.039 0.7594 1.452 2.31 4.196
%%%extracting Points Tank Fis%% 4.196 2.31 1.452 0.7594 -1.039 -2.093 -3.058
A=0;
AA=[4.196 2.31 1.452 0.7594 -1.039 -2.093 -3.058]';
for i=1:size(x,1)
A(i)=AA(i)*x(i,1);
end
cor=sum(A);

E=0;
EE=[.1 0.01 .03 0.03 0.03 0.03 0.03]';
for i=1:size(x,1)
E(i)=EE(i)*x(i,1);
end
epsilon= sum(E);

nnu=0;
nuu=[0.5 0.1 0.5 0.5 0.5 0.03 0.03]';
for i=1:size(x,1)
nnu(i)=nuu(i)*x(i,1);
end
nu=sum(nnu);

ll=[5 5 5 2 2 2 2]';
for i=1:size(x,1)
ll(i)=ll(i)*x(i,1);
end
lm=sum(ll);
lambda=lm;

 y(1,1)=nu;
 y(1,3)=lambda;
 y(1,2)=epsilon;
 y(1,4)=cor;

% y= [nu epsilon lambda cor 0]';