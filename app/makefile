# youpi-control : main.o ihm.o calcul.o
# 	gcc -Wextra main.o ihm.o calcul.o -o ../release/youpi-project -L./lib -I./include -lmingw32 -lSDL2main -lSDL2

# ihm.o : ihm.c ihm.h
# 	gcc -c ihm.c -o ihm.o -std=c99
youpi : main.o calcul.o
	gcc main.o calcul.o -o youpi

main.o : main.c declaration.h
	gcc -c main.c -o main.o

calcul.o : calcul.c calcul.h
	gcc -c calcul.c -o calcul.o


clean:
	rm -f *.o a.exe
