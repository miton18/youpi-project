% plot_data.m : vizualization script for YOUPI project
%
% compatible with octave 3.6.4
%
% Copyright Pierre-Jean BOUVET / ISEN BREST - 2015
% 25/02/2015 : initial version (PJB)

function plot_data( filename="trajectoire.dat" );

close all;

% load input files
printf("Fichier en entree = %s \n",filename);
fid = fopen(filename,'r');
mat = fscanf(fid,'%f %f %f %f %f %d\n');
fclose(fid);
[N1 N2] = size(mat);
N = N1/6;
mat = reshape(mat,6,N)';
printf("Nombre commandes = %d \n",N);

% check limit
Theta1Lim = [ -163.58 176.41];
Theta2Lim = [ -37.61 172.39];
Theta3Lim = [ -136.76 93.2432];

test1 = sum((mat(:,1)<Theta1Lim(1) |  mat(:,1)>Theta1Lim(2)));
test2 = sum((mat(:,2)<Theta2Lim(1) |  mat(:,2)>Theta2Lim(2)));
test3 = sum((mat(:,3)<Theta3Lim(1) |  mat(:,3)>Theta3Lim(2)));

if(test1>0 || test2>0 || test3>0)
	disp('attention : valeur(s) angle(s) hors limite ! ');
end

% convert to (X,Y,Z)
L1=175;
L2=160;
L3=160;
Theta1 = mat(:,1)/180*pi;
Theta2 = mat(:,2)/180*pi;
Theta3 = mat(:,3)/180*pi;

flag = mat(:,6);
x=cos(Theta1).*(L2*cos(Theta2)+L3*cos(Theta2+Theta3));
y=L1+L2*sin(Theta2)+L3*sin(Theta2+Theta3);
z=-sin(Theta1).*(L2*cos(Theta2)+L3*cos(Theta2+Theta3));

% figures
figure(1)
plot(Theta1,'-k');
hold on;
plot(Theta2,'-r');
plot(Theta3,'-b');
plot(flag,'-m');
plot([1 N],Theta1Lim(1)/180*pi*[1 1],'-.k');
plot([1 N],Theta1Lim(2)/180*pi*[1 1],':k');
plot([1 N],Theta2Lim(1)/180*pi*[1 1],'-.r');
plot([1 N],Theta2Lim(2)/180*pi*[1 1],':r');
plot([1 N],Theta3Lim(1)/180*pi*[1 1],'-.b');
plot([1 N],Theta3Lim(2)/180*pi*[1 1],':b');
legend('theta 1 (radians)','theta 2 (radians)','theta 3 (radians)','trace');
title('Valeurs des commandes moteur')
axis([1 N -pi pi]);


figure(2)
plot(x,'-k');
hold on;
plot(y,'-r');
plot(z,'-b');
legend('x','y','z');
title('Valeurs des coordonnees cartesiennes')

figure(3)
plot3(z,x,y,'.')
hold on;
plot3([-148.5 148.5],[40 40],[50 50],'-g')
plot3([-148.5 -148.5],[40 250],[50 50],'-g')
plot3([-148.5 148.5],[250 250],[50 50],'-g')
plot3([148.5 148.5],[40 250],[50 50],'-g')
axis([-160 160 0 300 0 110]);
title('modelisation du robot virtuel en mode point');



figure(4);
traj = [x,y,z,flag];
seg = [];
hold on;
for k=2:length(traj)
    if(traj(k,4)==1)
        seg = [seg;traj(k-1,1:3)];
    end
    if(traj(k,4)==0)
        if(traj(k-1,4)==1)
            seg = [seg;traj(k-1,1:3)];
            plot3(seg(:,3),seg(:,1),seg(:,2),'-r','LineWidth',2.0)
        end
        seg=[];
    end
end
if(traj(k,4)==1)
   seg = [seg;traj(k,1:3)];
end
plot3(seg(:,3),seg(:,1),seg(:,2),'-r','LineWidth',2.0)
plot3([-148.5 148.5],[40 40],[50 50],'-g')
plot3([-148.5 -148.5],[40 250],[50 50],'-g')
plot3([-148.5 148.5],[250 250],[50 50],'-g')
plot3([148.5 148.5],[40 250],[50 50],'-g')
xlabel('z');
ylabel('x');
zlabel('y');
title('modelisation du robot virtuel en mode tracage');
grid on;
axis([-160 160 0 300 0 110]);
endfunction;
