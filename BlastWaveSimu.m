R = dataset('File','radius.dat');
R = double(R);

[x,y,z] = sphere;      %# Makes a 21-by-21 point unit sphere 
x = x(11:end,:);       %# Keep top 11 x points 
y = y(11:end,:);       %# Keep top 11 y points 
z = z(11:end,:);       %# Keep top 11 z points 



for i = 1:size(R)
Radius = R(i);  %# Define rx, ry, rz
surf(Radius*x,Radius*y,Radius*z);  %# Plot the surface, multiplying unit coordinates with radii 
axis([-100 100 -100 100 0 100]) ; 
drawnow ;
pause(0.1)
end

