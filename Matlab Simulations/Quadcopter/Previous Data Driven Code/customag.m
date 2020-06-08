function y = customag(x)

maxVal = ones(1,size(x,2));
y = zeros(1,size(x,2));

for i = 1:size(x,1)
    y = min(maxVal,sum([y;x(i,:)]));
end

sum1=sum(x(:,1));
for i=1:size(x,1)
x(i,1)=x(i,1)./sum1;
end

%%%extracting Points Tank Fis%%
A=0;
AA=[0 .42 -.42 -.3 .3]';
for i=1:size(x,1)
A(i)=AA(i)*x(i,1);
end
cor=sum(A);

E=0;
EE=[.1 0.01 .03 0.03 0.03]';
for i=1:size(x,1)
E(i)=EE(i)*x(i,1);
end
epsilon= sum(E);

nnu=0;
nuu=[0.5 0.1 0.5 0.5 0.5]';
for i=1:size(x,1)
nnu(i)=nuu(i)*x(i,1);
end
nu=sum(nnu);

ll=[5 5 5 2 2]';
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