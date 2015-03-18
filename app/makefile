youpi-control : main.o ihm.o calcul.o conversion.o lettresXYZ.o lettresTheta.o lettresMoteur.o ecritureTraj.o
	gcc -Wextra main.o ihm.o calcul.o conversion.o lettresXYZ.o lettresTheta.o lettresMoteur.o ecritureTraj.o -o ../release/youpi-project -L./lib -I./include -lmingw32 -lSDL2main -lSDL2

ihm.o : ihm.c ihm.h
	gcc -c ihm.c -o ihm.o -std=c99

main.o : main.c declaration.h
	gcc -c main.c -o main.o

calcul.o : calcul.c calcul.h
	gcc -c calcul.c -o calcul.o

conversion.o : conversion.c conversion.h
	gcc -c conversion.c -o conversion.o -std=c99

lettresXYZ.o : lettresXYZ.c lettres_xyz.h
	gcc -c lettresXYZ.c -o lettresXYZ.o -std=c99

lettresTheta.o : lettresTheta.c lettres_theta.h
	gcc -c lettresTheta.c -o lettresTheta.o -std=c99

lettresMoteur.o : lettresMoteur.c lettres_moteur.h
	gcc -c lettresMoteur.c -o lettresMoteur.o

ecritureTraj.o : ecritureTraj.c ecriture_traj.h
	gcc -c ecritureTraj.c -o ecritureTraj.o

clean:
	rm -f *.o *.gch
