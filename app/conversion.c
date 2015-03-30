#include "conversion.h"

char * conversion(int s)
{
	if( s <= 0) {
		return NULL;
	}

	char * number = malloc(sizeof (char) * 15);
	int decoup[4];
	decoup[0]	= s % 10;
	decoup[1] 	= s / 10 % 10;
	decoup[2] 	= s / 100 % 10;
	decoup[3] 	= s / 1000 % 10;
	printf("millier: %d centaine: %d dizaine: %d unit%C: %d", decoup[3], decoup[2], decoup[1], 130, decoup[0]);

	strcpy( number, "");

	while(s - M >= 0){
		s -= M;
		strcat( number, "M");
	}
	while(s - CM >= 0){
		s -= CM;
		strcat( number, "CM");
	}
	while(s - D >= 0){
		s -= D;
		strcat( number, "D");
	}
	while(s - CD >= 0){
		s -= CD;
		strcat( number, "CD");
	}
	while(s - C >= 0){
		s -= C;
		strcat( number, "C");
	}
	while(s - XC >= 0){
		s -= XC;
		strcat( number, "XC");
	}
	while(s - L >= 0){
		s -= L;
		strcat( number, "L");
	}
	while(s - XL >= 0){
		s -= XL;
		strcat( number, "XL");
	}
	while(s - X >= 0){
		s -= X;
		strcat( number, "X");
	}
	while(s - IX >= 0){
		s -= IX;
		strcat( number, "IX");
	}
	while(s - V >= 0){
		s -= V;
		strcat( number, "V");
	}
	while(s - IV >= 0){
		s -= IV;
		strcat( number, "IV");
	}
	while(s - I >= 0){
		s -= I;
		strcat( number, "I");
	}

	return  number;
}
