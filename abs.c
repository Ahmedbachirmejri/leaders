#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"abs.h"







void taux_dab(int annee)
{

FILE* f,*F1;


char id[20];
char jour[20];
int mois;
int valeur;
int x;
int T[12];
float L[12];
int j,i,k;
float taux;


for(i=0;i<12;i++)
{
  T[i]=0;
}

remove ("Absent.txt");
f=fopen("absenteisme.txt","r");

F1=fopen("Absent.txt","a");

if(f!=NULL && F1!=NULL)
{

    while(fscanf(f,"%s %s %d %d %d \n",id,jour,&mois,&x,&valeur)!=EOF)
    {
   if((annee==x) && (valeur==0))
	{
  
          T[mois-1]++;
      }
      

    }
   fclose(f);
     }

 for(k=0;k<12;k++)
    {
       taux= ((T[k]*100)/(float)270);
       L[k]=taux;
       
    }
/*fprintf(F1,"%s",annee);*/
for(j=0;j<12;j++)
    {
	
	fprintf(F1,"%.3f ",L[j]);

    }
fprintf(F1,"\n");

 fclose(F1);
 	

}





GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *F;



void affi_abs(GtkWidget* treeview1,char*l)
{ 

	char annee[20] ; 
	char janvier[20];
	char fevrier[20];
	char mars[20];
	char avril[20];
	char mai[20];
	char juin[20];
	char juillet[20];
        char aout[20];
        char septembre[20];
	char octobre[20];
	char novembre[20];
	char decembre[20];
	

	 /* Creation du modele */
        adstore = gtk_list_store_new(12,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,			
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        F=fopen(l,"r");
while(fscanf(F,"%s %s %s %s %s %s %s %s %s %s %s %s \n",janvier,fevrier,mars,avril,mai,juin,juillet,aout,septembre,octobre,novembre,decembre)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,janvier,
                            1,fevrier,
			    2,mars,	
                            3,avril,
                            4,mai,
                            5,juin,
                            6,juillet,
                            7,aout,
                            8,septembre,
                            9,octobre,
		            10,novembre,
	   	            11,decembre,
                            -1);}
        fclose(F);

	/* Creation de la 1ere colonne */
if(i==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("janvier",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("fevrier",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("mars",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
       

       /* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("avril",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


            /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("mai",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



           /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("juin",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("juillet",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("aout",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        /* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("septembre",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        /* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("octobre",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);
	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	 /* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("novembre",
                                                            cellad,
                                                            "text", 10,
                                                            NULL);
	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
   



    /* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("decembre",
                                                            cellad,
                                                            "text", 11,
                                                            NULL);
	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);








	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
	
		

}


