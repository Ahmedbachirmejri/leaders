#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "capteur.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "affichage.h"
#include "troupeau.h"
#include "ouvrier.h"
#include "affichage2.h"
#include "affichage3.h"
#include "equipement.h"
#include"abs.h"

int x;
char ch2[5],ch3[5],ch4[7];
int t[4]={0,0,0,0};

void
on_buttonajouter_clicked               (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget*ajouter,*Interface;
ajouter= create_windowajouter();
gtk_widget_show(ajouter);

Interface = lookup_widget (button,"Interface");
gtk_widget_destroy(Interface);

}


void
on_bouttonafficher_clicked             (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget *windowafficher,*Interface;
GtkWidget*treeview1;
gchar* referance;
gchar* etat;
gchar* valeur;
gchar* type;
Interface = lookup_widget (button,"Interface");


windowafficher=create_windowafficher();
gtk_widget_show(windowafficher);

treeview1 = lookup_widget (windowafficher,"treeview1"); 
afficher_capteur(treeview1);

gtk_widget_destroy(Interface);

}


void
on_buttonmodifier_clicked              (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget*modifier,*Interface;
modifier= create_windowmodifier();
gtk_widget_show(modifier);

Interface = lookup_widget (button,"Interface");
gtk_widget_destroy(Interface);

}


void
on_buttonsupprimer_clicked             (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget*supprimer,*Interface;
supprimer= create_windowsupprimer();
gtk_widget_show(supprimer);

Interface = lookup_widget (button,"Interface");
gtk_widget_destroy(Interface);


}


void
on_okajouter_clicked                   (GtkWidget        *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
FILE *f2=NULL;
GtkWidget*referance;
GtkWidget*etat;
GtkWidget*valeur;
GtkWidget *Ajouter;
GtkWidget *type;
GtkWidget *marque;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget*windowajouter,*Interface6;
GtkWidget*objet_graphique;
char ref3[20];
char eta3 [20];
char val3[20];
char ty3[20];
char mq3[20];
int j2;
int m2;
int a2;
char j1[3];
char m1[3];
char a1[5];
char ch1[20],ch5[20];
referance = lookup_widget (button,"referanceajouter");
etat = lookup_widget (button,"etatajouter");
valeur = lookup_widget (button,"valeurajouter");
type = lookup_widget (button,"typeajouter");
marque = lookup_widget (button,"marqueajouter");

 
strcpy(ref3, gtk_entry_get_text(GTK_ENTRY(referance)));
strcpy(eta3, gtk_entry_get_text(GTK_ENTRY(etat)));
strcpy(val3, gtk_entry_get_text(GTK_ENTRY(valeur)));
strcpy(ty3, gtk_entry_get_text(GTK_ENTRY(type)));
strcpy(mq3, gtk_entry_get_text(GTK_ENTRY(marque)));

if (x==1) 
strcpy(ch1,"neuve");
else 
strcpy(ch1,"occasion");
f2=fopen("technicien2.txt","r");
if(f2!=NULL)
while(fscanf(f2,"%s \n",ch5)!=EOF)
f=fopen("technicien.txt","a");
if(f!=NULL)
{
fprintf(f," %s %s %s %s %s %s %s \n" ,ref3,eta3,val3,ty3,mq3,ch5,ch1);
remove("technicien2.txt");
fclose(f);
Interface6= create_Interface();
gtk_widget_show(Interface6);

windowajouter = lookup_widget (button,"windowajouter");
gtk_widget_destroy(windowajouter);
}
else printf("\n not found");



}


void
on_anullerajouter_clicked              (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget*windowajouter,*Interface3;
Interface3= create_Interface();
gtk_widget_show(Interface3);

windowajouter = lookup_widget (button,"windowajouter");
gtk_widget_destroy(windowajouter);

}


void
on_okmodifier_clicked                  (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget*referance3;
GtkWidget*etat3;
GtkWidget*valeur3;
GtkWidget*type3;
GtkWidget *marque3;
GtkWidget *date3;
GtkWidget *achat3;
GtkWidget*windowmodifier,*Interface8;
char ref4[20];
char eta4 [20];
char val4[20];
char type4[20];
char mq4[20];
char dt4[20];
char ach4[20];

referance3 = lookup_widget (button,"referancemodifier");
etat3 = lookup_widget (button,"etatmodifier");
valeur3 = lookup_widget (button,"valeurmodifier");
type3 = lookup_widget (button,"typemodifier");
marque3 = lookup_widget (button,"marquemodifier");
date3 = lookup_widget (button,"entrydate");
achat3 = lookup_widget (button,"entryachat");
 
strcpy(ref4, gtk_entry_get_text(GTK_ENTRY(referance3)));
strcpy(eta4, gtk_entry_get_text(GTK_ENTRY(etat3)));
strcpy(val4, gtk_entry_get_text(GTK_ENTRY(valeur3)));
strcpy(type4, gtk_entry_get_text(GTK_ENTRY(type3)));
strcpy(mq4, gtk_entry_get_text(GTK_ENTRY(marque3)));
strcpy(dt4, gtk_entry_get_text(GTK_ENTRY(date3)));
strcpy(ach4, gtk_entry_get_text(GTK_ENTRY(achat3)));

modifier_capteur(ref4,eta4,val4,type4,mq4,dt4,ach4);
Interface8= create_Interface();
gtk_widget_show(Interface8);

windowmodifier = lookup_widget (button,"windowmodifier");
gtk_widget_destroy(windowmodifier);

}


void
on_annulermodifier_clicked             (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget*windowmodifier,*Interface4;
Interface4= create_Interface();
gtk_widget_show(Interface4);

windowmodifier = lookup_widget (button,"windowmodifier");
gtk_widget_destroy(windowmodifier);

}


void
on_oksupprimer_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*referance4;
GtkWidget*windowsupprimer,*Interface7;
char ref5[20];
referance4 = lookup_widget (button,"referancesupprimer");

strcpy(ref5, gtk_entry_get_text(GTK_ENTRY(referance4)));

supprimer_capteur(ref5);
Interface7= create_Interface();
gtk_widget_show(Interface7);

windowsupprimer = lookup_widget (button,"windowsupprimer");
gtk_widget_destroy(windowsupprimer);



}


void
on_annulersupprimer_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*windowsupprimer,*Interface5;
Interface5= create_Interface();
gtk_widget_show(Interface5);

windowsupprimer = lookup_widget (button,"windowsupprimer");
gtk_widget_destroy(windowsupprimer);

}


void
on_buttonretour_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*windowafficher,*Interface10;
Interface10= create_Interface();
gtk_widget_show(Interface10);

windowafficher = lookup_widget (button,"windowafficher");
gtk_widget_destroy(windowafficher);

}


void
on_alarm_clicked                       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *capteural,*Interface;
GtkWidget*treeview2;
gchar* referance;
gchar* etat;
gchar* valeur;
gchar* type;
int val1;
Interface = lookup_widget (button,"Interface");

capteurs_alarmentes(val1);


capteural=create_capteural();
gtk_widget_show(capteural);

treeview2 = lookup_widget (capteural,"treeview2"); 
afficher_capteur2(treeview2);

gtk_widget_destroy(Interface);

}


void
on_buttonretour2_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*capteural,*Interface11;
Interface11= create_Interface();
gtk_widget_show(Interface11);

capteural = lookup_widget (button,"capteural");
gtk_widget_destroy(capteural);


}


void
on_defect_clicked                      (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *defectueuse,*Interface;
GtkWidget*treeview3;
gchar* referance;
gchar* etat;
gchar* valeur;
gchar* type;
GtkWidget* input ;
GtkWidget* output;
GtkWidget *objet_graphique;
int val66;
char mq9[20];
char mq20[50];
Interface = lookup_widget (button,"Interface");

capteurs_def(val66);


defectueuse=create_defectueuse ();
gtk_widget_show(defectueuse);



treeview3 = lookup_widget (defectueuse,"treeview3"); 
afficher_capteur3(treeview3);

gtk_widget_destroy(Interface);

}


void
on_retourdefect_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*defectueuse,*Interface12;
Interface12= create_Interface();
gtk_widget_show(Interface12);

defectueuse = lookup_widget (button,"defectueuse");
gtk_widget_destroy(defectueuse);

}


void
on_marque_clicked                      (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input ;
GtkWidget* output ;
char mq99[20];
char def99[100];
output = lookup_widget(objet_graphique, "label10") ;
marque_def(mq99,def99);
gtk_label_set_text(GTK_LABEL(output),def99);

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* referance;
gchar* etat;
gchar* valeur;
gchar* type;
gchar*marque;
gchar*date;
gchar*achat;
GtkWidget*treeview1;
GtkWidget*windowafficher1;
char ref02 [20];
char et02[20];
char val02[20];
char ty02[20];
char mq02[20];
char dt02[20];
char ach02[20];

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter, path)) {

	gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&referance,1,&etat,2,&valeur,3,&type,4,&marque,5,&date,6,&achat,-1);

	strcpy(ref02,referance);
	strcpy(et02,etat);
	strcpy(val02,valeur);
	strcpy(ty02,type);
	strcpy(mq02,marque);
	strcpy(dt02,date);
	strcpy(ach02,achat);

	supprimer_capteur(ref02);
	 windowafficher1=create_windowafficher();
	treeview1 = lookup_widget (windowafficher1,"treeview1");
	afficher_capteur(treeview1);
	}


}


void
on_valider_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*Jour;
GtkWidget*Mois;
GtkWidget*Annee;
GtkWidget*Combobox1;
GtkWidget*combobox1;
FILE *f;
FILE *f9;
char fourn[10];
int w,y,z,i;


Jour = lookup_widget (objet_graphique,"jour");
Mois = lookup_widget (objet_graphique,"mois");
Annee = lookup_widget (objet_graphique,"annee");
Combobox1 = lookup_widget (objet_graphique,"combobox1");

w=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
z=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));

sprintf(ch2,"%d",w);
sprintf(ch3,"%d",y);
sprintf(ch4,"%d",z);
strcat(ch2,"/");
strcat(ch2,ch3);
strcat(ch2,"/");
strcat(ch2,ch4);

f=fopen("technicien2.txt","a");
fprintf(f," %s \n" ,ch2);
fclose(f);


}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_radiobutton_fem_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_radiobutton_male_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
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
GtkWidget *input2,*jj,*mm, *aa, *input4, *input5;
GtkWidget *pRadio1, pRadio2;
GtkWidget *fenetre_ajout;

message=lookup_widget(objet,"message");
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
input2=lookup_widget(objet,"id");

jj=lookup_widget(objet,"ddn_jj");
mm=lookup_widget(objet,"ddn_mm");
aa=lookup_widget(objet,"ddn_aa");
input4=lookup_widget(objet,"poids");
input5=lookup_widget(objet,"type");

strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(input2)));
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
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview4;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

treeview4=lookup_widget(fenetre_afficher,"treeview4");
afficher(treeview4);
}


void
on_calculer_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Combobox3 ;
GtkWidget *output ;
GtkWidget *fenetre_ajout;
char rech[20];
char result[20];
int nb;

Combobox3=lookup_widget(objet,"combobox3");
output=lookup_widget(objet,"sortie");
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

strcpy(rech,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox3)));
nb=calcul(rech);
sprintf(result,"%d",nb);
GdkColor color;
gdk_color_parse("blue",&color);
gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(output),result);
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
GtkWidget *input1, *input2, *jj, *mm, *aa, *input6, *Combobox4;
GtkWidget *fen_modif;

input1=lookup_widget(objet,"id_a_modif");
input2=lookup_widget(objet,"sexe_a_modif");
jj=lookup_widget(objet,"jj_a_modif");
mm=lookup_widget(objet,"mm_a_modif");
aa=lookup_widget(objet,"aa_a_modif");
input6=lookup_widget(objet,"poids_a_modif");
Combobox4=lookup_widget(objet,"combobox4");

strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(m.sexe,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(m.poids,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(m.jour,gtk_entry_get_text(GTK_ENTRY(jj)));
strcpy(m.mois,gtk_entry_get_text(GTK_ENTRY(mm)));
strcpy(m.annee,gtk_entry_get_text(GTK_ENTRY(aa)));
strcpy(m.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox4)));
modif_espece(m,m.id);

}


void
on_treeview4_row_activated             (GtkTreeView     *treeview,
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
on_rechercher_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
FILE *f;
troupeau r;
GtkWidget *rech_id, *input;
GtkWidget *fen_rech_id, *fen_modif;
char rech_id1[20];
input=lookup_widget(objet,"rech_id");
fen_modif=lookup_widget(objet,"fen_modif");

strcpy(rech_id1,gtk_entry_get_text(GTK_ENTRY(input)));
f=fopen("troupeau.txt","r");
if (f!=NULL)
{while (fscanf(f,"%s %s %s %s %s %s %s \n",r.id,r.sexe,r.jour,r.mois,r.annee,r.poids,r.type)!=EOF)
{if (strcmp(rech_id1,r.id)==0)
fen_modif=create_fen_modif();
gtk_widget_show(fen_modif);
}
}
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
on_radiobutton2_Mjr_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;}
}


void
on_radiobutton1_M_nuit_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;} 
}


void
on_checkbutton1_A_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton)) 

   {t[1]=1;}
}


void
on_checkbutton2_B_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 
  {t[0]=1;} 
}


void
on_button6_ok_clicked                  (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget* ouvrier1,*lb,*gestionouvrier5,*CIN10,*CODE10,*gestion_ouvrier;
char CIN1[20];
char CODE1[20];
ouvrier T ;
int x=-1;
CIN10 = lookup_widget (button,"entry3");
CODE10 = lookup_widget (button,"entry4");
lb = lookup_widget (button,"label34");
strcpy(CIN1, gtk_entry_get_text(GTK_ENTRY(CIN10)));
strcpy(CODE1, gtk_entry_get_text(GTK_ENTRY(CODE10)));
FILE *f=NULL;

f=fopen("ouvrier.txt","r");
if(f!=NULL)
{
 while(fscanf(f,"%s %s %s %s %s %s %s\n",T.nom,T.prenom,T.CIN,T.CODE,T.date_naissance,T.sex,T.travail_parmois)!=EOF)
{
if((strcmp(T.CIN,CIN1)==0)&&(strcmp(T.CODE,CODE1)==0))
{
x=1;

}

}
fclose(f);
}
if(x!=1)
{
gtk_label_set_text(GTK_LABEL(lb),"compte n'existe pas ");
}else
{

ouvrier1=lookup_widget(button,"ouvrier1");
gtk_widget_destroy(ouvrier1);
gestion_ouvrier = create_gestionouvrier ();
gtk_widget_show (gestion_ouvrier);
    
}
}

void
on_ajouter_ouv_clicked                 (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget* gestionouvrier,*ajouter;
ajouter=create_ajouter ();
gtk_widget_show(ajouter);

gestionouvrier=lookup_widget(button,"gestionouvrier");
gtk_widget_destroy(gestionouvrier);
}


void
on_modifier_ouv_clicked                (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget* gestionouvrier,*modification;
modification=create_modification ();
gtk_widget_show(modification);

gestionouvrier=lookup_widget(button,"gestionouvrier");
gtk_widget_destroy(gestionouvrier);
}


void
on_affichage_clicked                   (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget* gestionouvrier,*affichage;
GtkWidget*treeview5;

affichage=create_affichage ();
gtk_widget_show(affichage);

treeview5 = lookup_widget (affichage,"treeview5");
afficher_employer(treeview5);

gestionouvrier=lookup_widget(button,"gestionouvrier");
gtk_widget_destroy(gestionouvrier);
}


void
on_supprimer_ouv_clicked               (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget* gestionouvrier,*supprimer;
supprimer=create_supprimer ();
gtk_widget_show(supprimer);

gestionouvrier=lookup_widget(button,"gestionouvrier");
gtk_widget_destroy(gestionouvrier);
}


void
on_affi_abs_clicked                    (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *da;
GtkWidget *treeView2;
char s[20];
int annee;
da = lookup_widget (objet,"entry25");
strcpy(s,gtk_entry_get_text(GTK_ENTRY(da)));
annee=atoi(s);
taux_dab(annee);
treeView2=lookup_widget(objet,"treeview2");
affi_abs(treeView2,"Absent.txt");
}


void
on_appliquer_les_modification_clicked  (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget* modification,*gestionouv3;
GtkWidget*nom6;
GtkWidget*prenom6;
GtkWidget*CIN6;
GtkWidget *CODE6;
GtkWidget *Ajouter6;
GtkWidget *sex6;
GtkWidget *date_naissance6;
GtkWidget *travail_parmois6;
GtkWidget*ajouter,*gestionouvrier1;
char nom7[20];
char prenom7 [20];
char CIN7[20];
char CODE7[20];
char date_naissance7[20];
char sex7[20];
char travail_parmois7[20];
nom6 = lookup_widget (button,"entry12");
prenom6 = lookup_widget (button,"entry13");
CIN6 = lookup_widget (button,"entry14");
CODE6 = lookup_widget (button,"entry17");
date_naissance6 = lookup_widget (button,"entry16");
sex6 = lookup_widget (button,"entry24");
travail_parmois6 = lookup_widget (button,"entry19");

 
strcpy(nom7, gtk_entry_get_text(GTK_ENTRY(nom6)));
strcpy(prenom7, gtk_entry_get_text(GTK_ENTRY(prenom6)));
strcpy(CIN7, gtk_entry_get_text(GTK_ENTRY(CIN6)));
strcpy(CODE7, gtk_entry_get_text(GTK_ENTRY(CODE6)));
strcpy(date_naissance7, gtk_entry_get_text(GTK_ENTRY(date_naissance6)));
strcpy(sex7, gtk_entry_get_text(GTK_ENTRY(sex6)));
strcpy(travail_parmois7, gtk_entry_get_text(GTK_ENTRY(travail_parmois6)));
modifier_employer(nom7,prenom7,CIN7,CODE7,date_naissance7,sex7,travail_parmois7);

gestionouv3=create_gestionouvrier ();
gtk_widget_show(gestionouv3);

modification=lookup_widget(button,"modification");
gtk_widget_destroy(modification);
}


void
on_button3_retour_M_clicked            (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget* gestionouv,*modification;
modification = lookup_widget (button,"modification");
gtk_widget_destroy(modification);

gestionouv = create_gestionouvrier ();
gtk_widget_show(gestionouv);
}


void
on_button5_ajouter_clicked             (GtkWidget        *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget*nom;
GtkWidget*prenom;
GtkWidget*CIN;
GtkWidget *CODE;
GtkWidget *Ajouter;
GtkWidget *sex;
GtkWidget *date_naissance;
GtkWidget *travail_parmois;
GtkWidget*ajouter,*gestionouvrier1;
char nom2[20];
char prenom2 [20];
char CIN2[20];
char CODE2[20];
char date_naissance2[20];
char sex2[20];
int travail_parmois2;
nom = lookup_widget (button,"entry5_nom");
prenom = lookup_widget (button,"entry6_prenom");
CIN = lookup_widget (button,"entry7_CIN");
CODE = lookup_widget (button,"entry8_CODE");
date_naissance = lookup_widget (button,"entry9_naissance");

travail_parmois = lookup_widget (button,"spinbutton1");
travail_parmois2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(travail_parmois));
sex = lookup_widget (button,"combobox5");
strcpy(sex2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sex)));

 
strcpy(nom2, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(prenom2, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(CIN2, gtk_entry_get_text(GTK_ENTRY(CIN)));
strcpy(CODE2, gtk_entry_get_text(GTK_ENTRY(CODE)));
strcpy(date_naissance2, gtk_entry_get_text(GTK_ENTRY(date_naissance)));


f=fopen("ouvrier.txt","a");
if(f!=NULL)
{
fprintf(f," %s %s %s %s %s %s %d \n" ,nom2,prenom2,CIN2,CODE2,date_naissance2,sex2,travail_parmois2);
fclose(f);
gestionouvrier1= create_gestionouvrier();
gtk_widget_show(gestionouvrier1);

ajouter = lookup_widget (button,"ajouter");
gtk_widget_destroy(ajouter);
}
else printf("\n not found");
}


void
on_button1_retour_Aj_clicked           (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget* gestionouv,*ajouter;
ajouter = lookup_widget (button,"ajouter");
gtk_widget_destroy(ajouter);

gestionouv = create_gestionouvrier ();
gtk_widget_show(gestionouv);
}


void
on_button4_supp_clicked                (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget* gestionouv,*supprimer;
supprimer = lookup_widget (button,"supprimer");
gtk_widget_destroy(supprimer);

gestionouv = create_gestionouvrier ();
gtk_widget_show(gestionouv);
}


void
on_buttonmodif_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*windowediter2,*interfaceprincipale;
windowediter2= create_windowediter();
gtk_widget_show(windowediter2);

interfaceprincipale = lookup_widget (button,"interfaceprincipale");
gtk_widget_destroy(interfaceprincipale);
}


void
on_supprimer1_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*window5supprimer1,*interfaceprincipale;
window5supprimer1= create_window5supprimer();
gtk_widget_show(window5supprimer1);

interfaceprincipale = lookup_widget (button,"interfaceprincipale");
gtk_widget_destroy(interfaceprincipale);
}


void
on_calendrier_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*calendrier2,*interfaceprincipale;
calendrier2= create_calendrier();
gtk_widget_show(calendrier2);

interfaceprincipale = lookup_widget (button,"interfaceprincipale");
gtk_widget_destroy(interfaceprincipale);
}


void
on_button5ajouter_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget*nom2;
GtkWidget*type2;
GtkWidget*n_serie2;
GtkWidget*windowajout1,*interfaceprincipale5;

char nom1[20];
char type1 [20];
char n_serie1[20];

nom2 = lookup_widget (button,"entry2");
type2 = lookup_widget (button,"entry3");
n_serie2 = lookup_widget (button,"entry4");

 
strcpy(nom1, gtk_entry_get_text(GTK_ENTRY(nom2)));
strcpy(type1, gtk_entry_get_text(GTK_ENTRY(type2)));
strcpy(n_serie1, gtk_entry_get_text(GTK_ENTRY(n_serie2)));

f=fopen("equipement.txt","a");
if(f!=NULL)
{
fprintf(f," %s %s %s \n" ,nom1,type1,n_serie1);
fclose(f);

}
else printf("\n not found");


interfaceprincipale5= create_interfaceprincipale();
gtk_widget_show(interfaceprincipale5);

windowajout1 = lookup_widget (button,"windowajout1");
gtk_widget_destroy(windowajout1);
}


void
on_annulerajouter_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*windowajout1,*interfaceprincipale1;
interfaceprincipale1= create_interfaceprincipale();
gtk_widget_show(interfaceprincipale1);

windowajout1 = lookup_widget (button,"windowajout1");
gtk_widget_destroy(windowajout1);
}


void
on_annulerediter_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*windowediter,*interfaceprincipale2;
interfaceprincipale2= create_interfaceprincipale();
gtk_widget_show(interfaceprincipale2);

windowediter = lookup_widget (button,"windowediter");
gtk_widget_destroy(windowediter);
}


void
on_buttonediter_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*nom5;
GtkWidget*type5;
GtkWidget*nserie5;
GtkWidget*windowediter,*interfaceprincipale7;
char nom6[20];
char type6 [20];
char nserie6[20];

nom5 = lookup_widget (button,"entry5");
type5 = lookup_widget (button,"entry6");
nserie5 = lookup_widget (button,"entry7");

 
strcpy(nom6, gtk_entry_get_text(GTK_ENTRY(nom5)));
strcpy(type6, gtk_entry_get_text(GTK_ENTRY(type5)));
strcpy(nserie6, gtk_entry_get_text(GTK_ENTRY(nserie5)));

modfier_equipement(nom6,type6,nserie6);


interfaceprincipale7= create_interfaceprincipale();
gtk_widget_show(interfaceprincipale7);

windowediter = lookup_widget (button,"windowediter");
gtk_widget_destroy(windowediter);
}


void
on_button7retour_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*windowafficher1,*interfaceprincipale4;
interfaceprincipale4= create_interfaceprincipale();
gtk_widget_show(interfaceprincipale4);

windowafficher1 = lookup_widget (button,"windowafficher1");
gtk_widget_destroy(windowafficher1);
}


void
on_buttonnon_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*window5supprimer,*interfaceprincipale3;
interfaceprincipale3= create_interfaceprincipale();
gtk_widget_show(interfaceprincipale3);

window5supprimer = lookup_widget (button,"window5supprimer");
gtk_widget_destroy(window5supprimer);
}

void
on_buttonValider_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*calendrier,*interfaceprincipale6;
interfaceprincipale6= create_interfaceprincipale();
gtk_widget_show(interfaceprincipale6);

calendrier = lookup_widget (button,"calendrier");
gtk_widget_destroy(calendrier);
}


void
on_ajouter1_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*windowajouter2,*interfaceprincipale;
windowajouter2= create_windowajout1();
gtk_widget_show(windowajouter2);

interfaceprincipale = lookup_widget (button,"interfaceprincipale");
gtk_widget_destroy(interfaceprincipale);
}


void
on_buttonoui_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*nom9;
GtkWidget*type9;
GtkWidget*nserie9;
GtkWidget*window5supprimer,*interfaceprincipale6;
char nom10[20];
char type10 [20];
char nserie10[20];


nserie9 = lookup_widget (button,"entrysupprimer");

strcpy(nserie10, gtk_entry_get_text(GTK_ENTRY(nserie9)));

supprimer_equipement(nserie10);


interfaceprincipale6= create_interfaceprincipale();
gtk_widget_show(interfaceprincipale6);

window5supprimer = lookup_widget (button,"window5supprimer");
gtk_widget_destroy(window5supprimer);
}


void
on_afficher1_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowafficher,*interfaceprincipale;
GtkWidget*treeview7;
gchar* nom;
gchar* type;
gchar* nserie;
interfaceprincipale = lookup_widget (button,"interfaceprincipale");


windowafficher=create_windowafficher1();
gtk_widget_show(windowafficher);

treeview7 = lookup_widget (windowafficher,"treeview7"); 

afficher_equi(treeview7);

gtk_widget_destroy(interfaceprincipale);
}


void
on_buttonlogin_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget*login1;
GtkWidget*motdepasse1;
GtkWidget*login,*interfaceadmin1,*erreur1;
char login2[20],log[20];
char motdepasse2 [20],mp[20];
FILE *f;


login1 = lookup_widget (button,"entrylogin");
motdepasse1 = lookup_widget (button,"entrymotdepasse");

 
strcpy(login2, gtk_entry_get_text(GTK_ENTRY(login1)));
strcpy(motdepasse2, gtk_entry_get_text(GTK_ENTRY(motdepasse1)));
f=fopen("ut.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s \n",log,mp)!=EOF)
{
if ((strcmp(log,login2)==0)&&(strcmp(motdepasse2,mp)==0))
{
interfaceadmin1=create_interfaceadmin();
gtk_widget_show(interfaceadmin1);
login = lookup_widget (button,"login");
gtk_widget_destroy(login);
}
else {
erreur1=create_Erreur();
gtk_widget_show(erreur1);
login = lookup_widget (button,"login");
gtk_widget_destroy(login);

}
}
}
fclose(f);
}

void
on_buttonresseyer_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget*login2,*Erreur;

login2=create_login();
gtk_widget_show(login2);
Erreur = lookup_widget (button,"Erreur");
gtk_widget_destroy(Erreur);
}


void
on_ajoutercompte_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttontechnicien_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget*interfaceadmin,*interface50;

interface50=create_Interface();
gtk_widget_show(interface50);

}


void
on_buttontroupeau_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget*interfaceadmin,*interface50;

interface50=create_Interface();
gtk_widget_show(interface50);

}


void
on_buttonouvrier_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget*interfaceadmin,*gestionouvrier50;

gestionouvrier50=create_gestionouvrier();
gtk_widget_show(gestionouvrier50);

}


void
on_buttonequipement_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget*interfaceadmin,*interfaceprincipale50;

interfaceprincipale50=create_interfaceprincipale();
gtk_widget_show(interfaceprincipale50);

}


void
on_buttonclient_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonajoutlogin_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonannuleraj_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}

