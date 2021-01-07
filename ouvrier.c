#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>
#include "ouvrier.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void espace_ouvrier(char nom[],char prenom[],char CIN[],char CODE[])
{
FILE *f5;
FILE *f6;
char nom10[20];
char prenom10[20];
char CIN10[20];
char CODE10[20];


f5=fopen("ouvrier.txt","r");
f6=fopen("ouvriertemp.txt","a");
}


void supprimer_employer(char CIN[])
{
FILE *f5;
FILE *f6;
char nom3[20];
char prenom3[20];
char CIN3[20];
char CODE3[20];
char date_naissance3[20];
char sex3[20];
char travail_parmois3[20];
f5=fopen("ouvrier.txt","r");
f6=fopen("ouvriertemp.txt","a");

if (f5!=NULL)
{
while(fscanf(f5,"%s %s %s %s %s %s %s \n",nom3,prenom3,CIN3,CODE3,date_naissance3,sex3,travail_parmois3)!=EOF)
{
if (strcmp(CIN,CIN3)!=0)
fprintf(f6,"%s %s %s %s %s %s %s \n",nom3,prenom3,CIN3,CODE3,date_naissance3,sex3,travail_parmois3);
}
remove("ouvrier.txt");
rename("ouvriertemp.txt","ouvrier.txt");
fclose(f6);
}
return;
}


void modifier_employer(char nom[],char prenom[],char CIN[],char CODE[],char date_naissance[],char sex[],char travail_parmois[])

{
FILE *f2;
FILE *f3;
char nom5[20];
char prenom5[20];
char CIN5[20];
char CODE5[20];
char date_naissance5[20];
char sex5[20];
char travail_parmois5[20];
f2=fopen("ouvrier.txt","r");
f3=fopen("ouvriertemp.txt","a");

if (f2!=NULL)
{
while(fscanf(f2,"%s %s %s %s %s %s %s \n",nom5,prenom5,CIN5,CODE5,date_naissance5,sex5,travail_parmois5)!=EOF)
{
if (strcmp(CIN,CIN5)!=0)
fprintf(f3,"%s %s %s %s %s %s %s \n",nom5,prenom5,CIN5,CODE5,date_naissance5,sex5,travail_parmois5);
else
fprintf(f3,"%s %s %s %s %s %s %s \n",nom,prenom,CIN,CODE,date_naissance,sex,travail_parmois);
}
remove("ouvrier.txt");
rename("ouvriertemp.txt","ouvrier.txt");
fclose(f2);
fclose(f3);
}
}
