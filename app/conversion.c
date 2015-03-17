#include "conversion.h"

char * conversion(int s)
{
	char * number = malloc(sizeof (char) * 15);
	int decoup[4];
	decoup[0]	= s % 10;
	decoup[1] 	= s / 10 % 10;
	decoup[2] 	= s / 100 % 10;
	decoup[3] 	= s / 1000 % 10;
	printf("millier: %d centaine: %d dizaine: %d unit%C: %d", decoup[3], decoup[2], decoup[1], 130, decoup[0]);

	//char * test = "YOLOSWAG";
	strcpy( number, millier( 	decoup[3] ));
	//strcat( number, centaine( 	decoup[2] ));
	//strcat( number, dizaine( 	decoup[1] ));
	//strcat( number, unite( 		decoup[0] ));

	//printf("%s", number);

	return  number;
}
char * millier( int m ){

	char * str 	= malloc (sizeof (char) * 4);
	char * M	= "M";
	strcpy( str, "");

	for( int i=0; i< m && i<3; i++) {

		strcat(str, M);
	}
	return str;
}
char * centaine( int c){

	char * str;
	return str;
}
char * dizaine(	 int d){

	char * str;
	return str;
}
char * unite(	 int u){

	char * str;
	return str;
}
