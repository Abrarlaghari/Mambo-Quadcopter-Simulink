function y = customagA( x )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
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
AA=[-0.5 0.5 0 -1 1]';
for i=1:size(x,1)
A(i)=AA(i)*x(i,1);
end
cor=sum(A);

El=0;
EEl=[.06 0.06 .12 0.3 0.25]';
for i=1:size(x,1)
El(i)=EEl(i)*x(i,1);
end
epsilonl= sum(El);


Er=0;
EEr=[.01 0.1 .09 0.02 0.25]';
for i=1:size(x,1)
Er(i)=EEr(i)*x(i,1);
end
epsilonr= sum(Er);

nnul=0;
nuul=[0.9 0.9 0.9 0.5 0.9]';
for i=1:size(x,1)
nnul(i)=nuul(i)*x(i,1);
end
nul=sum(nnul);

nnur=0;
nuur=[0.5 0.5 0.6 0.03 0.6]';
for i=1:size(x,1)
nnur(i)=nuur(i)*x(i,1);
end
nur=sum(nnur);

lll=0;
ll=[5 5 25 2 5]';
for i=1:size(x,1)
lll(i)=ll(i)*x(i,1);
end
lambdal=sum(lll);

llr=0;
lr=[5 5 25 2 5]';
for i=1:size(x,1)
llr(i)=lr(i)*x(i,1);
end
lamdar=sum(llr);

 y(1,1)=nul;
 y(1,3)=lambdal;
 y(1,2)=epsilonl;
 y(1,4)=cor;
 y(1,5)=nul;
 y(1,7)=lambdal;
 y(1,6)=epsilonl;
 
end

