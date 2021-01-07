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
}affichagecapteur;


void afficher_capteur(GtkWidget* liste);
void afficher_capteur2(GtkWidget* liste);
void afficher_capteur3(GtkWidget* liste);
