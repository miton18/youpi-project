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

lettres_xyz.o : lettres_xyz.c lettres_xyz.h
	gcc -c lettres_xyz.c -o lettres_xyz.o -std=c99

lettres_theta.o : lettres_theta.c lettres_theta.h
	gcc -c lettres_theta.c -o lettres_theta.o -std=c99

lettres_moteur.o : lettres_moteur.c lettres_moteur.h
	gcc -c lettres_moteur.c -o lettres_moteur.o

ecriture_traj.o : ecriture_traj.c ecriture_traj.h
	gcc -c ecriture_traj.c -o ecriture_traj.o

#CIBLE DE NETTOYAGE
clean:
	rm -f *.o *.gch


#CIBLES DE TEST

test-ihm : ihm.o test-ihm.o
	gcc ihm.o test-ihm.o -o ../release/test-ihm

test-ihm.o: test-ihm.c
	gcc -c test-ihm.c -o test-ihm.o



test-conversion : conversion.o test-conversion.o
	gcc conversion.o test-conversion.o -o ../release/test-conversion

test-conversion.o: test-conversion.c
	gcc -c test-conversion.c -o test-conversion.o



test-calcul : calcul.o test-calcul.o
	gcc calcul.o test-calcul.o -o ../release/test-calcul

test-calcul.o: test-calcul.c
	gcc -c test-calcul.c -o test-calcul.o



test-lettres_xyz : lettres_xyz.o test-lettres_xyz.o
	gcc lettres_xyz.o test-lettres_xyz.o -o ../release/test-lettres_xyz

test-lettres_xyz.o: test-lettres_xyz.c
	gcc -c test-lettres_xyz.c -o test-lettres_xyz.o -std=c99




test-lettres_theta : lettres_theta.o test-lettres_theta.o
	gcc lettres_theta.o test-lettres_theta.o -o ../release/test-lettres_theta

test-lettres_theta.o: test-lettres_theta.c
	gcc -c test-lettres_theta.c -o test-lettres_theta.o -std=c99

