youpi-control : main.o ihm.o calcul.o conversion.o
	gcc -Wextra main.o ihm.o calcul.o conversion.o -o ../release/youpi-project -L./lib -I./include -lmingw32 -lSDL2main -lSDL2

ihm.o : ihm.c ihm.h
	gcc -c ihm.c -o ihm.o -std=c99

main.o : main.c declaration.h
	gcc -c main.c -o main.o

calcul.o : calcul.c calcul.h
	gcc -c calcul.c -o calcul.o

conversion.o : conversion.c conversion.h
	gcc -c conversion.c -o conversion.o -std=c99



clean:
	rm -f *.o *.gch
