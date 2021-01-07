#include <gtk/gtk.h>

typedef struct
{
char nom[20];
char prenom[20];
char CIN[20];
char CODE[20];
char date_naissance[20];
char sex[20];
char travail_parmois[20];
}ouvrier;

void ajouter_employer(char nom[],char prenom[],char CIN[],char CODE[],char date_naissance[],char sex[],char travail_parmois[]);
void supprimer_employer(char CIN[]);
void modifier_employer(char nom[],char prenom[],char CIN[],char CODE[],char date_naissance[],char sex[],char travail_parmois[]);
void affichage_employer(char nom[],char prenom[],char CIN[],char CODE[],char date_naissance[],char sex[],char travail_parmois[]);

