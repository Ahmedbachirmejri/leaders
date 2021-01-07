#include <gtk/gtk.h>

typedef struct
{
char ref[20];
char etat[20];
char valeur[20];
char type[20];
char marque[20];
char date[20];
char achat[20];
int val1;
char def[100];
}capteur;


void modifier_capteur(char ref[],char etat[],char valeur[],char type[],char marque[],char date[],char achat[]);
void supprimer_capteur(char ref[]);
void capteurs_alarmentes(int val1);
void capteurs_def(int val1);
void marque_def (char marque[],char def[]);

