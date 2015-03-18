youpi-control : main.o ihm.o calcul.o conversion.o lettres_xyz.o lettres_theta.o lettres_moteur.o ecriture_traj.o
	gcc -Wextra main.o ihm.o calcul.o conversion.o lettres_xyz.o lettres_theta.o lettres_moteur.o ecriture_traj.o -o ../release/youpi-project -L./lib -I./include -lmingw32 -lSDL2main -lSDL2

ihm.o : ihm.c ihm.h
	gcc -c ihm.c -o ihm.o -std=c99

main.o : main.c declaration.h
	gcc -c main.c -o main.o

calcul.o : calcul.c calcul.h
	gcc -c calcul.c -o calcul.o

conversion.o : conversion.c conversion.h
	gcc -c conversion.c -o conversion.o -std=c99

<<<<<<< HEAD
lettresXYZ.o : lettresXYZ.c lettres_xyz.h
	gcc -c lettresXYZ.c -o lettresXYZ.o -std=c99

lettresTheta.o : lettresTheta.c lettres_theta.h
	gcc -c lettresTheta.c -o lettresTheta.o -std=c99

lettresMoteur.o : lettresMoteur.c lettres_moteur.h
	gcc -c lettresMoteur.c -o lettresMoteur.o

ecritureTraj.o : ecritureTraj.c ecriture_traj.h
	gcc -c ecritureTraj.c -o ecritureTraj.o
=======
lettres_xyz.o : lettres_xyz.c lettres_xyz.h
	gcc -c lettres_xyz.c -o lettres_xyz.o -std=c99

lettres_theta.o : lettres_theta.c lettres_theta.h
	gcc -c lettres_theta.c -o lettres_theta.o -std=c99

lettres_moteur.o : lettres_moteur.c lettres_moteur.h
	gcc -c lettres_moteur.c -o lettres_moteur.o

ecriture_traj.o : ecriture_traj.c ecriture_traj.h
	gcc -c ecriture_traj.c -o ecriture_traj.o
>>>>>>> d03161e736ff6b808b08f8d46f98a8481c72d612

clean:
	rm -f *.o *.gch
