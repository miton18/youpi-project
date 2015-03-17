youpi-control : ihm.o main.o calcul.o
	gcc -Wall -Wextra main.o calcul.o -o ../release/youpi-project -L./lib -I./include -lmingw32 -lSDL2main -lSDL2

ihm.o : ihm.c ihm.h
	gcc –Wall -c ihm.c -o ihm.o

main.o : main.c main.h
	gcc –Wall -c main.c -o main.o

calcul.o: calcul.c calcul.h
	gcc -Wall -c calcul.c -o calcul.o


clean:
rm -f *.o a.exe
