#include<gtk/gtk.h>

typedef struct date 
{int jour;
 int mois;
 int annee;
}DATE; 
typedef struct client 
{  char carteid [50];
   char nom[50];
   char prenom[50];
   char login[50];
   char password[50];
   DATE d;
   char num[50];
   char adresse[60];
   char sexe[50];

}client;
typedef struct reclamation
{ char carteid[50];
  char sujet[50];
  DATE dr;
  char contenue[100];
}reclamation;
  int numbers(char n[30]);
  int alphanumb(char a[30]);
 int alphabet(char a[30]);
 int rechercher(char *carteid);
 void ajouter_reclamation(reclamation r);
 void ajouter_reclamation1(reclamation r);
void afficher_reclamation (GtkWidget *liste);
 void ajouter_client(client c);
 void supprimer_client(client c);
 void modifier_client(client c);
 int rechercher(char *carteid);
int rechercher1(char *carteid);
