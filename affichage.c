#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>
#include "affichage.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

enum {REFERANCE, ETAT, VALEUR, TYPE, MARQUE,DATE,ACHAT, COLUMNS};

void afficher_capteur(GtkWidget * liste)  // modifie le type aussi dans affichage .h GtkWidget et non pas GTkTreeView )
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Referance[20];
char Etat[20];
char Valeur[20];
char Type[20];
char Marque[20];
char Date[10];
char Achat[20];

FILE *f7;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Referance", renderer, "text", REFERANCE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Etat", renderer, "text", ETAT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Valeur", renderer, "text", VALEUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Type", renderer, "text", TYPE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Marque", renderer, "text", MARQUE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Date", renderer, "text", DATE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Achat", renderer, "text", ACHAT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f7 = fopen("technicien.txt","r");

if(f7==NULL)
{ 
return;
}
else

{ 
while(fscanf(f7,"%s %s %s %s %s %s %s \n",Referance,Etat,Valeur,Type,Marque,Date,Achat)!=EOF)
{
gtk_list_store_append (store, &iter);
gtk_list_store_set(store,&iter,REFERANCE,Referance,ETAT,Etat,VALEUR,Valeur,TYPE,Type,MARQUE,Marque,DATE,Date,ACHAT,Achat,-1);

}
fclose(f7);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

void afficher_capteur2(GtkWidget * liste)  
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Referance[20];
char Etat[20];
char Valeur[20];
char Type[20];
char Marque[20];
char Date[10];
char Achat[20];
FILE *f7;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Referance", renderer, "text", REFERANCE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Etat", renderer, "text", ETAT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Valeur", renderer, "text", VALEUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Type", renderer, "text", TYPE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Marque", renderer, "text", MARQUE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Date", renderer, "text", DATE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Achat", renderer, "text", ACHAT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f7 = fopen("capteuralarm.txt","r");

if(f7==NULL)
{ 
return;
}
else

{ 
while(fscanf(f7,"%s %s %s %s %s %s %s \n",Referance,Etat,Valeur,Type,Marque,Date,Achat)!=EOF)
{
gtk_list_store_append (store, &iter);
gtk_list_store_set(store,&iter,REFERANCE,Referance,ETAT,Etat,VALEUR,Valeur,TYPE,Type,MARQUE,Marque,DATE,Date,ACHAT,Achat,-1);

}
fclose(f7);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}


void afficher_capteur3(GtkWidget * liste)  
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Referance[20];
char Etat[20];
char Valeur[20];
char Type[20];
char Marque[20];
char Date[10];
char Achat[20];
FILE *f7;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Referance", renderer, "text", REFERANCE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Etat", renderer, "text", ETAT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Valeur", renderer, "text", VALEUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Type", renderer, "text", TYPE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Marque", renderer, "text", MARQUE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Date", renderer, "text", DATE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " Achat", renderer, "text", ACHAT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f7 = fopen("capteurdef.txt","r");

if(f7==NULL)
{ 
return;
}
else

{ 
while(fscanf(f7,"%s %s %s %s %s %s %s \n",Referance,Etat,Valeur,Type,Marque,Date,Achat)!=EOF)
{
gtk_list_store_append (store, &iter);
gtk_list_store_set(store,&iter,REFERANCE,Referance,ETAT,Etat,VALEUR,Valeur,TYPE,Type,MARQUE,Marque,DATE,Date,ACHAT,Achat,-1);

}
fclose(f7);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}




