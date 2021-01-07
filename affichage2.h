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
}affichageemployer;


void afficher_employer(GtkWidget* liste);

