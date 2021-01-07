#include <gtk/gtk.h>

typedef struct
{
char id[20];
char sexe[20];
char jour[20];
char mois[20];
char annee[20];
char poids[20];
char type[20];
char rech_id[20];
}troupeau;

troupeau tr[100];

void ajout_troupeau(troupeau t);

int rechercher (char rech_id[]);
void modif_espece(troupeau m,char id[20]);

void supprimer(troupeau s);

void afficher(GtkWidget *liste);
int tab_espece(troupeau t[100]);
int controle_saisie_espece(troupeau tab[100],char ide[20]);
int calcul(char rtype[]);
