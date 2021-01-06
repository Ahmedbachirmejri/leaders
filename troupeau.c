
#include <stdio.h>
#include <stdlib.h>
#include "troupeau.h"
#include <string.h>
#include <gtk/gtk.h>

enum
{
	EID,
	ESEXE,
	EJJ,
	EMM,
	EAA,
	EPOIDS,
	ETYPE,
	COLUMNS
};


int tab_espece(troupeau t[100])
{ int n=0;
FILE *f;
f=fopen("troupeau.txt","r");
if(f!=NULL)
	{
while(
		fscanf(f,"%s %s %s %s %s %s %s \n",t[n].id,t[n].sexe,t[n].jour,t[n].mois,t[n].annee,t[n].poids,t[n].type)!=EOF)
		{n++;}
		fclose(f);
}
return n;}

int controle_saisie_espece(troupeau tab[100],char ide[20])
{int n=tab_espece(tab);
int i;
for (i=0; i<n;i++)
if (strcmp(tab[i].id,ide)==0)
return i;
return -1;}



void ajout_troupeau(troupeau t)
{
	FILE *f;
	f=fopen("troupeau.txt","a+");
	if(f!=NULL)
	{
		fprintf(f,"%s %s %s %s %s %s %s \n",t.id,t.sexe,t.jour,t.mois,t.annee,t.poids,t.type);
		fclose(f);
	}
}


void afficher(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[20];
	char sexe[20];
	char jour[20];
	char mois[20];
	char annee[20];
	char poids[20];
	char type[20];
	store=NULL;

	FILE *f;

	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJJ,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
		renderer = gtk_cell_renderer_text_new();
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EAA,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		column = gtk_tree_view_column_new_with_attributes("poids",renderer,"text",EPOIDS,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
		

		store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
		f=fopen("troupeau.txt","r");
		if (f==NULL)
		{
			return;
		}
		else
		{
			f=fopen("troupeau.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s \n",id,sexe,jour,mois,annee,poids,type)!=EOF)
			{
				
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,EID,id,ESEXE,sexe,EJJ,jour,EMM,mois,EAA,annee,EPOIDS,poids,ETYPE,type, -1);
			}
			fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
		}
}

}

void modif_espece(troupeau m,char id[20])
{
	troupeau m1;
	FILE *f,*g;
	f=fopen("troupeau.txt","r");
	g=fopen("troupeau1.txt","w");
	if(f!=NULL)
		{
		while(fscanf(f,"%s %s %s %s %s %s %s \n",m1.id,m1.sexe,m1.jour,m1.mois,m1.annee,m1.poids,m1.type)!=EOF)
			{
			if(strcmp(m1.id,id)==0)
				{fprintf(g,"%s %s %s %s %s %s %s \n",m.id,m.sexe,m.jour,m.mois,m.annee,m.poids,m.type);
				}
			else
				{
				fprintf(g,"%s %s %s %s %s %s %s \n",m1.id,m1.sexe,m1.jour,m1.mois,m1.annee,m1.poids,m1.type);
				}
			}
		}
	fclose(f);
	fclose(g);
	remove("troupeau.txt");
	rename("troupeau1.txt","troupeau.txt");
}




void supprimer(troupeau s)
{
	
	troupeau s2;
	FILE *f, *g;
	f = fopen("troupeau.txt","r");
	g = fopen("troupeau1.txt","w");
	if(f==NULL || g==NULL)
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s %s %s %s \n",s2.id,s2.sexe,s2.jour,s2.mois,s2.annee,s2.poids,s2.type)!=EOF)
		{
		if(strcmp(s.id,s2.id)!=0 || strcmp(s.sexe,s2.sexe)!=0 || strcmp(s.jour,s2.jour)!=0 || strcmp(s.mois,s2.mois)!=0 || strcmp(s.annee,s2.annee)!=0|| strcmp(s.poids,s2.poids)!=0 || strcmp(s.type,s2.type)!=0)
		fprintf(g,"%s %s %s %s %s %s %s \n",s2.id,s2.sexe,s2.jour,s2.mois,s2.annee,s2.poids,s2.type);
		}
	fclose(f);
	fclose(g);
	remove("troupeau.txt");
	rename("troupeau1.txt","troupeau.txt");
	}
}	



int calcul(char rtype[])
{
	troupeau c;
	int nb=0;
	FILE *f;
	f=fopen("troupeau.txt","r");
	if(f!=NULL)
		{
		while(fscanf(f,"%s %s %s %s %s %s %s \n",c.id,c.sexe,c.jour,c.mois,c.annee,c.poids,c.type)!=EOF)
			{
			if(strcmp(rtype,c.type)==0)
			nb++;
			}
		}
	fclose(f);
	return(nb);
	
}

int rechercher (char *rech_id[20])
{
FILE *f;
troupeau r;
int k=0;
f = fopen("troupeau.txt","r");
if (f!=NULL)
{while (fscanf(f,"%s %s %s %s %s %s %s \n",r.id,r.sexe,r.jour,r.mois,r.annee,r.poids,r.type)!=EOF)
{if (strcmp(rech_id,r.id)==0)
	k=1;
}
fclose(f);
}
return(k);

}




