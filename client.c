


#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include <gtk/gtk.h>





void ajouter_client(client c)
{FILE *f ;
f=fopen("client.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s %d %d %d %s %s %s \n ",c.carteid,c.nom,c.prenom,c.login,c.password,c.d.jour,c.d.mois,c.d.annee,c.num,c.adresse,c.sexe);
fclose(f);
}
}
void ajouter_reclamation(reclamation r)
{FILE *f ;
f=fopen("reponsereclamation.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %d %d %d %s \n ",r.carteid,r.sujet,r.dr.jour,r.dr.mois,r.dr.annee,r.contenue);
fclose(f);
}
}
void ajouter_reclamation1(reclamation r)
{FILE *f ;
f=fopen("envoireclamation.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %d %d %d %s \n ",r.carteid,r.sujet,r.dr.jour,r.dr.mois,r.dr.annee,r.contenue);
fclose(f);
}
}
void supprimer_client(client c)

{
client c2;
FILE *f,*g;
    f=fopen("client.txt","r");
    g=fopen("client2.txt","w");

if (f==NULL || g==NULL ) 
      return;
else 
{
     while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s		 ",c2.carteid,c2.nom,c2.prenom,c2.login,c2.password,&c2.d.jour,&c2.d.mois,&c2.d.annee,c2.num,c2.adresse,c2.sexe)!=EOF)
       { if (strcmp(c.carteid,c2.carteid)!=0 )
fprintf(g,"%s %s %s %s %s %d %d %d %s %s %s  \n ",c2.carteid,c2.nom,c2.prenom,c2.login,c2.password,c2.d.jour,c2.d.mois,c2.d.annee,c2.num,c2.adresse,c2.sexe);
}

fclose(f);
fclose(g);
remove("client.txt");
rename("client2.txt","client.txt");
}
}
void modifier_client(client c)

{
client c3;
FILE *f,*k;
    f=fopen("client.txt","r");
    k=fopen("client3.txt","w");

if (f!=NULL) 
{
     while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s ",c3.carteid,c3.nom,c3.prenom,c3.login,c3.password,&c3.d.jour,&c3.d.mois,&c3.d.annee,c3.num,c3.adresse,c3.sexe)!=EOF)
       { if (strcmp(c.carteid,c3.carteid)!=0  )
fprintf(k,"%s %s %s %s %s %d %d %d %s %s %s  \n ",c3.carteid,c3.nom,c3.prenom,c3.login,c3.password,c3.d.jour,c3.d.mois,c3.d.annee,c3.num,c3.adresse,c3.sexe);
else {fprintf(k,"%s %s %s %s %s %d %d %d %s %s %s  \n ",c.carteid,c.nom,c.prenom,c.login,c.password,c.d.jour,c.d.mois,c.d.annee,c.num,c.adresse,c.sexe);
}
}

fclose(f);
fclose(k);
remove("client.txt");
rename("client3.txt","client.txt");
}
}
int rechercher(char *carteid)
{
FILE *f;
client c;
int k=0;
f=fopen("client.txt","r");
if (f!=NULL) 
{ while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s ",c.carteid,c.nom,c.prenom,c.login,c.password,&c.d.jour,&c.d.mois,&c.d.annee,c.num,c.adresse,c.sexe)!=EOF)
       { if (strcmp(carteid,c.carteid)==0  )
        k=1;
     

}
fclose(f);
return(k);
}
}



enum{
	ECARTEID,
	ENOM,
	EPRENOM,
ELOGIN,
	EPASSWORD,
	ENUM,
	EDATE,
EADRESSE,
ESEXE,
COLUMNS
};



void afficher_client (GtkWidget *liste) {

GtkCellRenderer *renderer;  
	GtkTreeViewColumn *column;
	GtkTreeIter   iter;    
	GtkListStore  *store;    

        char carteid[50];
        char nom[50];
        char prenom[50];
        char login[50];
        char password[50];
        char num[50];
        char date[50];
        char adresse[50];

        char sexe[50];
	char j[20],m[50],a[50];
	 store=NULL;
	 FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
        renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("carte d'identité",renderer,"text",ECARTEID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);  

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Login",renderer,"text",ELOGIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Password",renderer,"text",EPASSWORD,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

        renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Date",renderer,"text",EDATE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
        

        
        renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Num",renderer,"text",ENUM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	

        
        renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Adresse",renderer,"text",EADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

 renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


}
	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("client.txt","r");
	if(f==NULL)
	{
	return;
	}
	else 
{
	f=fopen("client.txt","r");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",carteid,nom,prenom,login,password,j,m,a,num,adresse,sexe)!=EOF)
{	strcpy(date,"");
	strcat(date,j);
	strcat(date,"/");
	strcat(date,m);
	strcat(date,"/");
        strcat(date,a);
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,ECARTEID,carteid,ENOM,nom,EPRENOM,prenom,ELOGIN,login,EPASSWORD,password,EDATE,date,ENUM,num,EADRESSE,adresse,ESEXE,sexe,-1);
}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);

}
}
void afficher_reclamation (GtkWidget *liste) {

GtkCellRenderer *renderer;  
	GtkTreeViewColumn *column;
	GtkTreeIter   iter;    
	GtkListStore  *store;    

        char carteid[50];
        char sujet[50];
        char date[50];
        char contenue[50];
        

        
	char j[20],m[50],a[50];
	 store=NULL;
	 FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
        renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",0,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);  

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("sujet",renderer,"text",1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("date reclamation",renderer,"text",2,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("contenue",renderer,"text",3,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	
	

}
	store=gtk_list_store_new(4, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("envoireclamation.txt","r");
	if(f==NULL)
	{
	return;
	}
	else 
{
	f=fopen("envoireclamation.txt","r");
	while(fscanf(f,"%s %s %s %s %s %s\n",carteid,sujet,j,m,a,contenue)!=EOF)
{	strcpy(date,"");
	strcat(date,j);
	strcat(date,"/");
	strcat(date,m);
	strcat(date,"/");
        strcat(date,a);
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,ECARTEID,carteid,ENOM,nom,EPRENOM,prenom,ELOGIN,login,EPASSWORD,password,EDATE,date,ENUM,num,EADRESSE,adresse,ESEXE,sexe,-1);
}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);

}
}



int alphabet(char a[30])
{int i=0,test=1;
 if (strlen(a)==0) {return(0);}
 else{  
	do
	{
	if (isalpha(a[i])==0||a[i]==" "){test=0;}
	i++;
	}while((test==1)&& (i<strlen(a)));
        return(test);
     }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int numbers(char n[30])
{int i=0,test=1;
 if (strlen(n)!=8) return(0);
 else{
	do
	{
	if (isdigit(n[i])==0){test=0;}
	i++;         
	}while((test==1)&& (i<strlen(n)));
        return(test);
      }
}

int alphanumb(char a[30])
{int i=0,test=1;
 if (strlen(a)==0) {return(0);}
 else{  
	do
	{
	if (a[i]==" "){test=0;}
	i++;
	}while((test==1)&& (i<strlen(a)));
        return(test);
     }
}
int rechercher1(char *carteid)
{
FILE *f;
reclamation r;
int m=0;
f=fopen("reponsereclamation.txt","r");
if (f!=NULL) 
{ while(fscanf(f,"%s %s %d %d %d %s  ",r.carteid,r.carteid,r.sujet,r.dr.jour,r.dr.mois,r.dr.annee,r.contenue)!=EOF)
       { if (strcmp(carteid,r.carteid)==0  )
        m=1;
     

}
fclose(f);
return(m);
}
}



