#include<stdio.h>
#include<stdlib.h>

#include "equipement.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char modfier_equipement(char nom [],char type[],char n_serie[])
{
FILE *f2;
FILE *f3;
char nom4[20];
char type4 [20];
char n_serie4[20];

f2=fopen("equipement.txt","r");
f3=fopen("equipementtemp.txt","a");

if (f2!=NULL)
{
while(fscanf(f2," %s %s %s \n" ,nom4,type4,n_serie4)!=EOF)
{
if (strcmp(n_serie,n_serie4)!=0)
fprintf(f3," %s %s %s \n" ,nom4,type4,n_serie4);
else
fprintf(f3," %s %s %s \n" ,nom,type,n_serie);
}
remove("equipement.txt.txt");
rename("equipementtemp.txt","equipement.txt");
fclose(f2);
fclose(f3);
}
}

char supprimer_equipement(char n_serie[])
{
FILE *f4;
FILE *f5;
char nom7[20];
char type7 [20];
char n_serie7[20];

f4=fopen("equipement.txt","r");
f5=fopen("equipementtemp.txt","a");

if (f4!=NULL)
{
while(fscanf(f4," %s %s %s \n" ,nom7,type7,n_serie7)!=EOF)
{
if (strcmp(n_serie,n_serie7)!=0)
fprintf(f5," %s %s %s \n" ,nom7,type7,n_serie7);

}
remove("equipement.txt.txt");
rename("equipementtemp.txt","equipement.txt");
fclose(f4);
fclose(f5);
}
}

int donner(int val,int mois,int annee)
{
FILE *f;
fopen(f,"donner.txt");
fprintf("%d %d %d",val,mois,annee);
}








