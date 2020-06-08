 

 x = -1:2/200:1;
 y = -1:2/200:1;
 lambda = 4;
for j=1:length(y)
for i=1:length(x)
   
 deltal1(i,j) =  ((x(i)) / (1 + abs (.707*(2*x(i)-y(j))/0.1)^lambda));

end
end
  figure(200); 
  [xx, yy]= meshgrid(x,y);
  surface(xx,yy,deltal1)
%   plot3(deltal1');
  %axis([-10 10 0 1.2]);
%   hold on;