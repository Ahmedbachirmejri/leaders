#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>
#include "capteur.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void supprimer_capteur(char ref[])
{
FILE *f5;
FILE *f6;
char ref2[20];
char etat2[20];
char valeur2[20];
char type2[20];
char mq2[20];
char dt2[20];
char ach2[20];
f5=fopen("technicien.txt","r");
f6=fopen("technicientemp.txt","a");

if (f5!=NULL)
{
while(fscanf(f5,"%s %s %s %s %s %s %s \n",ref2,etat2,valeur2,type2,mq2,dt2,ach2)!=EOF)
{
if (strcmp(ref,ref2)!=0)
fprintf(f6,"%s %s %s %s %s %s %s \n",ref2,etat2,valeur2,type2,mq2,dt2,ach2);
}
remove("technicien.txt");
rename("technicientemp.txt","technicien.txt");
fclose(f6);
}
return;
}

void modifier_capteur(char ref[],char etat[],char valeur[],char type[],char marque[],char date[],char achat[])

{
FILE *f2;
FILE *f3;
char ref1[20];
char etat1[20];
char valeur1[20];
char type1[20];
char marque1[20];
char dt1[20];
char ach1[20];
f2=fopen("technicien.txt","r");
f3=fopen("technicientemp.txt","a");

if (f2!=NULL)
{
while(fscanf(f2,"%s %s %s %s %s %s %s \n",ref1,etat1,valeur1,type1,marque1,dt1,ach1)!=EOF)
{
if (strcmp(ref,ref1)!=0)
fprintf(f3,"%s %s %s %s %s %s %s \n",ref1,etat1,valeur1,type1,marque1,dt1,ach1);
else
fprintf(f3,"%s %s %s %s %s %s %s \n",ref,etat,valeur,type,marque,date,achat);
}
remove("technicien.txt");
rename("technicientemp.txt","technicien.txt");
fclose(f2);
fclose(f3);
}
}
void capteurs_alarmentes(int val1)
{
FILE *f;
FILE *f1;
char ref2[20];
char etat2[20];
char valeur2[20];
char type2[20];
char mq2[20];
char dt2[20];
char ach2[20];
f=fopen("technicien.txt","r");
f1=fopen("capteuralarmtemp.txt","a");

if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s \n",ref2,etat2,valeur2,type2,mq2,dt2,ach2)!=EOF)
{
val1=atoi(valeur2);
if ((val1>60)||(val1<-10))
fprintf(f1,"%s %s %s %s %s %s %s \n",ref2,etat2,valeur2,type2,mq2,dt2,ach2);
}
remove("capteuralarm.txt");
rename("capteuralarmtemp.txt","capteuralarm.txt");
fclose(f);
fclose(f1);

}
return;
}

void capteurs_def(int val1)
{
FILE *f;
FILE *f1;
char ref2[20];
char etat2[20];
char valeur2[20];
char type2[20];
char mq2[20];
char dt2[20];
char ach2[20];
f=fopen("technicien.txt","r");
f1=fopen("capteurdeftemp.txt","a");

if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s \n",ref2,etat2,valeur2,type2,mq2,dt2,ach2)!=EOF)
{
val1=atoi(valeur2);
if ((val1>70)||(val1<-20))
fprintf(f1,"%s %s %s %s %s %s %s \n",ref2,etat2,valeur2,type2,mq2,dt2,ach2);
}
remove("capteurdef.txt");
rename("capteurdeftemp.txt","capteurdef.txt");


fclose(f);
fclose(f1);

}
return;
}

void marque_def (char marque[],char def[])

{
FILE *f10;
char ref2[20];
char etat2[20];
char valeur2[20];
char type2[20];
char mq2[20];
char dt2[20];
char ach2[20];
int bosch=0;
int young =0;
int semens=0;
int samsung=0;
int LG=0;
char ch1[20]="bosch";
char ch2[20]="young";
char ch3[20]="semens";
char ch4[20]="samsung";
char ch5[20]="LG";
f10=fopen("capteurdef.txt","r");

if (f10!=NULL)
{
while(fscanf(f10,"%s %s %s %s %s %s %s \n",ref2,etat2,valeur2,type2,mq2,dt2,ach2)!=EOF)
{
if (strcmp(mq2,ch1)==0)
   bosch=bosch+1;
else if (strcmp(mq2,ch2)==0)
   young=young+1;
else if (strcmp(mq2,ch3)==0)
   semens=semens+1;
else if (strcmp(mq2,ch4)==0)
   samsung=samsung+1;
else LG=LG+1;
}
if ((bosch>young)&&(bosch>semens)&&(bosch>samsung)&&(bosch>LG))
   strcpy (marque,ch1);
else if ((young>bosch)&&(young>semens)&&(young>samsung)&&(young>LG))
   strcpy (marque,ch2);
else if ((semens>bosch)&&(semens>young)&&(semens>samsung)&&(semens>LG))
   strcpy (marque,ch3);
else if ((samsung>bosch)&&(samsung>young)&&(samsung>semens)&&(samsung>LG))
   strcpy (marque,ch4);
else strcpy (marque,ch5);
strcpy(def,"la marque la plus mauvaise est ");
strcat(def,marque);
fclose(f10);
}
}    



