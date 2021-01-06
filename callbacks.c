#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "troupeau.h"

int x=1;

void
on_radiobutton_male_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_radiobutton_fem_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}

}




void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
int u;
char msg[50];
troupeau tr[100];
troupeau t;
GtkWidget *message;
GtkWidget *input1,*jj,*mm, *aa, *input4, *input5;
GtkWidget *pRadio1, pRadio2;
GtkWidget *fenetre_ajout;

message=lookup_widget(objet,"message");
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
input1=lookup_widget(objet,"id");

jj=lookup_widget(objet,"ddn_jj");
mm=lookup_widget(objet,"ddn_mm");
aa=lookup_widget(objet,"ddn_aa");
input4=lookup_widget(objet,"poids");
input5=lookup_widget(objet,"type");

strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(input1)));
if(x==1)
strcpy(t.sexe,"Male");
else
if(x==2)
strcpy(t.sexe,"Femelle");
strcpy(t.jour,gtk_entry_get_text(GTK_ENTRY(jj)));
strcpy(t.mois,gtk_entry_get_text(GTK_ENTRY(mm)));
strcpy(t.annee,gtk_entry_get_text(GTK_ENTRY(aa)));
strcpy(t.poids,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(input5)));
//ajout_troupeau(t);

u=controle_saisie_espece(tr,t.id);
if (u==-1)
{ajout_troupeau(t);
strcpy(msg,"Ajout Réussit!");
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(message,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(message),msg);}
else
{
strcpy(msg,"ID espèce déjà utilisé!");
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(message,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(message),msg);}

}


void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher(treeview1);
}


void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;

fenetre_afficher=lookup_widget(objet,"fenetre_afficher");

gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
	gchar* sexe;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* poids;
	gchar* type;
	troupeau s;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &sexe, 2, &jour, 3, &mois, 4, &annee, 5, &poids, 6, &type, -1);
		strcpy(s.id,id);
		strcpy(s.sexe,sexe);
		strcpy(s.jour,jour);
		strcpy(s.mois,mois);
		strcpy(s.annee,annee);
		strcpy(s.poids,poids);
		strcpy(s.type,type); 
		supprimer(s);
		afficher(treeview);
}
}



void
on_calcul_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Combobox1 ;
GtkWidget *output ;
GtkWidget *fenetre_ajout;
char rech[20];
char result[20];
int nb;

Combobox1=lookup_widget(objet,"combobox1");
output=lookup_widget(objet,"sortie");
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

strcpy(rech,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
nb=calcul(rech);
sprintf(result,"%d",nb);
GdkColor color;
gdk_color_parse("blue",&color);
gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output),result);


}




void
on_modif_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *fenetre_ajout, *fen_modif;


fen_modif=lookup_widget(objet,"fen_modif");

gtk_widget_destroy(fenetre_ajout);
fen_modif=lookup_widget(objet,"fen_modif");
fen_modif=create_fen_modif();
gtk_widget_show(fen_modif);
}



void
on_retour2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fen_modif;

fen_modif=lookup_widget(objet,"fen_modif");

gtk_widget_destroy(fen_modif);
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);
}


void
on_modif2_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{

troupeau m;
GtkWidget *input1, *input2, *jj, *mm, *aa, *input6, *Combobox2;
GtkWidget *fen_modif;

input1=lookup_widget(objet,"id_a_modif");
input2=lookup_widget(objet,"sexe_a_modif");
jj=lookup_widget(objet,"jj_a_modif");
mm=lookup_widget(objet,"mm_a_modif");
aa=lookup_widget(objet,"aa_a_modif");
input6=lookup_widget(objet,"poids_a_modif");
Combobox2=lookup_widget(objet,"combobox2");

strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(m.sexe,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(m.poids,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(m.jour,gtk_entry_get_text(GTK_ENTRY(jj)));
strcpy(m.mois,gtk_entry_get_text(GTK_ENTRY(jj)));
strcpy(m.annee,gtk_entry_get_text(GTK_ENTRY(aa)));
strcpy(m.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)));
modif_espece(m,m.id);

}


void
on_rechercher_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
FILE *f;
troupeau r;
GtkWidget *rech_id, *input;
GtkWidget *fen_rech_id, *fen_modif;
input=lookup_widget(objet,"rech_id");
fen_modif=lookup_widget(objet,"fen_modif");

strcpy(rech_id,gtk_entry_get_text(GTK_ENTRY(input)));
f=fopen("troupeau.txt","r");
if (f!=NULL)
{while (fscanf(f,"%s %s %s %s %s %s %s \n",r.id,r.sexe,r.jour,r.mois,r.annee,r.poids,r.type)!=EOF)
{if (strcmp(rech_id,r.id)==0)
fen_modif=create_fen_modif();
gtk_widget_show(fen_modif);
}
}
}


void
on_annul_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fen_rech_id;

fen_rech_id=lookup_widget(objet,"fen_rech_id");

gtk_widget_destroy(fen_rech_id);
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);
}

















void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher, *treeview1;
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");

gtk_widget_destroy(fenetre_afficher);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);

treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher(treeview1);


}






