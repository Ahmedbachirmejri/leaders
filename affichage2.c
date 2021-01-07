#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>
#include "affichage.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

enum {NOM, PRENOM, CIN, CODE,DATE,SEX,TRAVAIL_PARMOIS, COLUMNS};

void afficher_employer(GtkWidget * liste)  
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[20];
char prenom[20];
char cin[20];
char code[20];
char date_naissance[20];
char sex[20];
char travail_parmois[20];

FILE *f7;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " nom", renderer, "text", NOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " prenom", renderer, "text", PRENOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " cin", renderer, "text", CIN, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " code", renderer, "text", CODE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " date_naissance", renderer, "text", DATE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " sex", renderer, "text", SEX, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " travail_parmois", renderer, "text", TRAVAIL_PARMOIS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f7 = fopen("ouvrier.txt","r");

if(f7==NULL)
{ 
return;
}
else

{ 
while(fscanf(f7,"%s %s %s %s %s %s %s \n",nom,prenom,cin,code,date_naissance,sex,travail_parmois)!=EOF)
{
gtk_list_store_append (store, &iter);
gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,CIN,cin,CODE,code,DATE,date_naissance,SEX,sex,TRAVAIL_PARMOIS,travail_parmois,-1);

}
fclose(f7);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}





