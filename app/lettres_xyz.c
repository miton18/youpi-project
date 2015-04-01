/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Fonction lettresXYZ
   	Création des trajectoires en x,y,z 
   	-----------------------------------------------------*/

#include "lettres_xyz.h"

      /*Fonction lettresXYZ
      paramètre : char* str:chaine contenant les chiffres romains
                  float* tx: tableau de float contenant les coordonnées x
                  float* ty: tableau de float contenant les coordonnées y
                  float* tz: tableau de float contenant les coordonnées z
                  int* ttr : tableau de int contenant l'information de tracage
                  int* np : pointeur vers le nombre de points
      retour : void
      */
   	void lettresXYZ(char* str, float* tx, float* ty,float* tz,int* ttr,int* np){
         char temp;
         int nptemp=0;
         int indiceTableau=0;
         int i;
         for (i = 0; i < strlen(str); ++i)
         {
            temp = str[i];
            switch (temp)
            {
               case 'I':
   				nptemp=lettreI(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'V':
   				nptemp=lettreV(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'X':
   				nptemp=lettreX(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'L':
   				nptemp=lettreL(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'C':
   				nptemp=lettreC(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'D':
   				nptemp=lettreD(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'M':
   				nptemp=lettreM(tx,ty,tz,ttr,i,&indiceTableau);
   				break;
				default:
					return ;
				break;

   			}
   			*np +=nptemp;
   		}
   	}

      /*Fonction lettresX
      paramètre : float* x, tableau de float contenant les coordonnées x
                  float* y, tableau de float contenant les coordonnées y
                  float* z, tableau de float contenant les coordonnées z
                  int* tr , tableau de int contenant l'information de tracage
                  int i, indice dans la chaine de caractère str
                  int* indice, indice dans les tableaux 
      retour : int nbp , pointeur vers le nombre de points
      Genère des coordonnées de points pour former un X 
      */
   	int lettreX(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=202;
         float pas = 9*2/((float) nbp-2);
         float j;
         int trace = 1;
         //tracé points deuxieme diagonale
         for (j = 0; j < 9+pas; j=j+pas)
         {
            x[*indice]=(11*j/9) +145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            if (trace==1){
               tr[*indice]=0;
               trace =0;
            }else
            {
               tr[*indice]=1;
            }
            *indice=*indice+1;
         }
         x[*indice]=(11*9/9)+145;
         y[*indice]=50;
         z[*indice]=9+(i*18)-139.5;
         tr[*indice]=1;
         *indice=*indice+1;
         trace =1;
         //tracé points première diagonale
         for (j = 0; j < 9+pas;j=j+pas )
         {
            x[*indice]=((-11*(j-9))/9)+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            if (trace==1){
               tr[*indice]=0;
               trace =0;
            }else
            {
               tr[*indice]=1;
            }
            *indice=*indice+1;
         }
         x[*indice]=((-11*(9-9))/9)+145;
         y[*indice]=50;
         z[*indice]=9+(i*18)-139.5;
         tr[*indice]=1;
         *indice=*indice+1;
         return nbp;

   	}

      /*Fonction lettresI
      paramètre : float* x: tableau de float contenant les coordonnées x
                  float* y: tableau de float contenant les coordonnées y
                  float* z: tableau de float contenant les coordonnées z
                  int* tr : tableau de int contenant l'information de tracage
                  int i: indice dans la chaine de caractère str
                  int* indice: indice dans les tableaux 
      retour : int nbp : pointeur vers le nombre de points
      Genère des coordonnées de points pour former un I
      */
      int lettreI(float* x, float* y,float* z,int* tr,int i,int* indiceTableau){
         int nbp=150;
         float pas = (11+9*2)/((float)nbp);
         float pas2 = (0);
         float j;
         int trace = 1;
         //tracé points du trait du haut
         for (j = 0; j < 9; j=j+pas)
         {
            x[*indiceTableau]=11+145;
            y[*indiceTableau]=50;
            z[*indiceTableau]=j+(i*18)-139.5;
            if (trace == 1){
               tr[*indiceTableau]=0;
               trace=0;
            }
            else{
               tr[*indiceTableau]=1;
            }
            *indiceTableau=*indiceTableau+1;
         }
         trace =1;
         //tracé points du trait du milieu
         for (j = 0; j < 11; j+=pas)
         {
            x[*indiceTableau]=j+145;
            y[*indiceTableau]=50;
            z[*indiceTableau]=4.5+(i*18)-139.5;
            if (trace == 1){
               tr[*indiceTableau]=0; 
               trace = 0;
            }
            else{
               tr[*indiceTableau]=1;
            }
            *indiceTableau=*indiceTableau+1;
         }
         trace =1;
         //tracé points du trait du bas
         for (j = 0; j < 9; j+=pas)
         {
            x[*indiceTableau]=0+145;
            y[*indiceTableau]=50;
            z[*indiceTableau]=j+(i*18)-139.5;
            if (trace == 1){
               tr[*indiceTableau]=0; 
               trace = 0;
            }
            else{
               tr[*indiceTableau]=1;
            }
            *indiceTableau=*indiceTableau+1;
         }
         return nbp;
      }

      /*Fonction lettresM
      paramètre : float* x: tableau de float contenant les coordonnées x
                  float* y: tableau de float contenant les coordonnées y
                  float* z: tableau de float contenant les coordonnées z
                  int* tr : tableau de int contenant l'information de tracage
                  int i: indice dans la chaine de caractère str
                  int* indice: indice dans les tableaux 
      retour : int nbp : pointeur vers le nombre de points
      Genère des coordonnées de points pour former un M
      */
      int lettreM(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=200;
/*         float hypo = sqrt(pow(11,2)+pow(4.5,2));
         float pas = (hypo*2+11*2)/((float)nbp);*/
         float pas = (9+11*2)/(float)nbp;
         float j;
         int trace =1;
         //tracé points du 1er trait vertical
         for (j = 0; j < 11; j=j+pas)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=0+(i*18)-139.5;
            if (trace == 1){
               tr[*indice]=0; 
               trace = 0;
            }
            else{
               tr[*indice]=1;
            }
            *indice=*indice+1;
         }
         //tracé points du 1er trait diagonal
         for (j = 0; j < 4.5; j=j+pas)
         {
            x[*indice]=(-2*11*j/9)+11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         //tracé points du 2eme trait diagonal
         for (j = 4.5; j < 9; j=j+pas)
         {
            x[*indice]=(2*11*j/9)-11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         //tracé points du 2em trait vertical
         for (j = 0; j < 11; j=j+pas)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=9+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         tr[*indice-1]=0;
         return nbp;
      }

      /*Fonction lettresV
      paramètre : float* x: tableau de float contenant les coordonnées x
                  float* y: tableau de float contenant les coordonnées y
                  float* z: tableau de float contenant les coordonnées z
                  int* tr : tableau de int contenant l'information de tracage
                  int i: indice dans la chaine de caractère str
                  int* indice: indice dans les tableaux 
      retour : int nbp : pointeur vers le nombre de points
      Genère des coordonnées de points pour former un V
      */
      int lettreV(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=200;
/*         float hypo = sqrt(pow(11,2)+pow(4.5,2));
         float pas = (hypo*2)/((float)nbp);*/
         float pas = 9/(float)nbp;
         float j;
         int trace = 1 ;
         //tracé points du 1er trait diagonal
         for (j = 0; j < 4.5; j=j+pas)
         {
            x[*indice]=(-2*11*j/9)+11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            if (trace == 1){
               tr[*indice]=0; 
               trace = 0;
            }
            else{
               tr[*indice]=1;
            }
            *indice=*indice+1;
         }
         //tracé points du 2eme trait diagonal
         for (j = 4.5; j < 9; j=j+pas)
         {
            x[*indice]=(2*11*j/9)-11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         tr[*indice-1]=0;
         printf("indice = %d\n",*indice );
         return nbp;
      }

      /*Fonction lettresC
      paramètre : float* x: tableau de float contenant les coordonnées x
                  float* y: tableau de float contenant les coordonnées y
                  float* z: tableau de float contenant les coordonnées z
                  int* tr : tableau de int contenant l'information de tracage
                  int i: indice dans la chaine de caractère str
                  int* indice: indice dans les tableaux 
      retour : int nbp : pointeur vers le nombre de points

      Genère des coordonnées de points pour former un C
      */
      int lettreC(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=200;
         float j;
         float pas = M_PI*220/((float)nbp*180);
         int trace =1;
         //tracé point de l'ellipse
         for ( j = 2.7925268; j < 6.63225116 ; j=j+pas)
         {
            x[*indice]=5.5*cos(j)+150.5;
            y[*indice]=50;
            z[*indice]=4.5*sin(j)+(i*18)-135;
            if (trace == 1){
               tr[*indice]=0; 
               trace = 0;
            }
            else{
               tr[*indice]=1;
            }
            *indice=*indice+1;
         }
         return nbp;
      }

      /*Fonction lettreD
      paramètre : float* x: tableau de float contenant les coordonnées x
                  float* y: tableau de float contenant les coordonnées y
                  float* z: tableau de float contenant les coordonnées z
                  int* tr : tableau de int contenant l'information de tracage
                  int i: indice dans la chaine de caractère str
                  int* indice: indice dans les tableaux 
      retour : int nbp : pointeur vers le nombre de points
      Genère des coordonnées de points pour former un D
      */
      int lettreD(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=200;
         float j;
         float pas1 = 11/(0.25*(float)nbp);
         float pas2 = 180/(0.75*(float)nbp);
         int trace =1;
         // tracé points de l'ellipse
         for ( j = 0; j < 180; j=j+pas2)
         {
            x[*indice]=5.5*cos(M_PI*j/180)+150.5;
            y[*indice]=50;
            z[*indice]=9*sin(M_PI*j/180)+(i*18)-139.5;
            if (trace == 1){
               tr[*indice]=0; 
               trace = 0;
            }
            else{
               tr[*indice]=1;
            }
            *indice=*indice+1;
         }
         //tracé points du trait vertical
         for (j = 0; j < 11+pas1; j=j+pas1)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=0+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;    
         }    

         return nbp;
      }


      /*Fonction lettresL
      paramètre : float* x: tableau de float contenant les coordonnées x
                  float* y: tableau de float contenant les coordonnées y
                  float* z: tableau de float contenant les coordonnées z
                  int* tr : tableau de int contenant l'information de tracage
                  int i: indice dans la chaine de caractère str
                  int* indice: indice dans les tableaux 
      retour : int nbp : pointeur vers le nombre de points
      Genère des coordonnées de points pour former un L
      */
      int lettreL(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=202;
         float pas = (9+11)/((float)nbp);
         float j;
         int trace = 1;
         //tracé points du trait vertical
         for (j = 0; j < 11; j=j+pas)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=0+(i*18)-139.5;
            if(trace == 1){
               tr[*indice]=0;
               trace = 0;
            }else{
               tr[*indice]=1;
            }
            *indice=*indice+1;
         }
         //tracé points du trait orizontal
         for (j = 0; j < 9; j=j+pas)
         {
            x[*indice]=0+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         return nbp;
      }
