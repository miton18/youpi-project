youpi-control : main.o ihm.o calcul.o convertion.o
	gcc -Wextra main.o ihm.o calcul.o convertion.o -o ../release/youpi-project -L./lib -I./include -lmingw32 -lSDL2main -lSDL2

ihm.o : ihm.c ihm.h
	gcc -c ihm.c -o ihm.o -std=c99

main.o : main.c declaration.h
	gcc -c main.c -o main.o

calcul.o : calcul.c calcul.h
	gcc -c calcul.c -o calcul.o

convertion.o : convertion.c convertion.h
	gcc -c convertion.c -o convertion.o



clean:
	rm -f *.o *.gch
