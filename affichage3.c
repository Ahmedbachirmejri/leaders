#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>
#include "affichage.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

enum {NOM, TYPE, NSERIE, COLUMNS};

void afficher_equi(GtkWidget* liste)
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[20];
char type [20];
char nserie[20];

FILE *f7;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " nom", renderer, "text", NOM, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " type", renderer, "text", TYPE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes( " nserie", renderer, "text", NSERIE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f7 = fopen("equipement.txt","r");

if(f7==NULL)
{ 
return;
}
else

{ 
while(fscanf(f7,"%s %s %s \n",nom,type,nserie)!=EOF)
{
gtk_list_store_append (store, &iter);
gtk_list_store_set(store,&iter,NOM,nom,TYPE,type,NSERIE,nserie,-1);

}
fclose(f7);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}


