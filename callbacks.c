#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "client.h"

void
on_button1_clicked                     (GtkWidget    *objet,
                                        gpointer         user_data)
{GtkWidget *espaceC;
 GtkWidget *ajout;
espaceC=lookup_widget(objet,"espaceC");

gtk_widget_destroy(espaceC);
ajout=lookup_widget(objet,"ajout");
ajout=create_ajout();
gtk_widget_show(ajout);

}

void on_ok_clicked                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7;
 GtkWidget *JOUR;
 GtkWidget *MOIS;
 GtkWidget *ANNEE;
 GtkWidget *radio1;
  GtkWidget *radio2;
  GtkWidget *Fsortie_ajouter,*Fsortie_ajouter1,*Fsortie_ajouter2,*Fsortie_ajouter3,*Fsortie_ajouter4,*Fsortie_ajouter5,*Fsortie_ajouter6,*Fsortie_ajouter7;
int t1,t2,t3,t4,t5,t6,t7;

 client c;
 GtkWidget *ajout;
GSList *List;

GSList* gtk_radio_button_get_group(GtkRadioButton *radio_button);

 FILE *f=NULL;
 
ajout=lookup_widget(objet_graphique,"ajout");
input1=lookup_widget(objet_graphique,"carteid");
input2=lookup_widget(objet_graphique,"nom");
input3=lookup_widget(objet_graphique,"prenom");
input4=lookup_widget(objet_graphique,"login");
input5=lookup_widget(objet_graphique,"password");
JOUR=lookup_widget(objet_graphique,"jour");
MOIS=lookup_widget(objet_graphique,"mois");
ANNEE=lookup_widget(objet_graphique,"annee");
input6=lookup_widget(objet_graphique,"num");

input7=lookup_widget(objet_graphique,"adresse");
radio1=lookup_widget(GTK_WIDGET(objet_graphique),"radiobuttoncl1");
radio2=lookup_widget(GTK_WIDGET(objet_graphique),"radiobuttoncl2");
Fsortie_ajouter=lookup_widget(objet_graphique,"Fsortie_ajouter");
Fsortie_ajouter1=lookup_widget(objet_graphique,"Fsortie_ajouter1");
Fsortie_ajouter2=lookup_widget(objet_graphique,"Fsortie_ajouter2");
Fsortie_ajouter3=lookup_widget(objet_graphique,"Fsortie_ajouter3");
Fsortie_ajouter4=lookup_widget(objet_graphique,"Fsortie_ajouter4");
Fsortie_ajouter5=lookup_widget(objet_graphique,"Fsortie_ajouter5");
Fsortie_ajouter6=lookup_widget(objet_graphique,"Fsortie_ajouter6");
Fsortie_ajouter7=lookup_widget(objet_graphique,"Fsortie_ajouter7");


strcpy(c.carteid,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.login,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(input5)));
c.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JOUR));
c.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MOIS));
c.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ANNEE));
strcpy(c.num,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));
List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (radio1)); 

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data))) strcpy(c.sexe,gtk_button_get_label(GTK_BUTTON(List->data))); 
else{ List = g_slist_next(List); 
strcpy(c.sexe,gtk_button_get_label(GTK_BUTTON(List->data)));}

t1=numbers(c.carteid);
t2=alphabet(c.nom);
t3=alphabet(c.prenom);
t4=alphanumb(c.login);
t5=alphanumb(c.password);
t6=numbers(c.num);
t7=alphabet(c.adresse);

if(t1==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_ajouter),"carte identite ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_ajouter),"carte identite false.");

if(t2==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_ajouter1),"nom ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_ajouter1),"nom false.");
if(t3==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_ajouter2),"prenom ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_ajouter2),"prenom false.");
if(t4==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_ajouter3),"login ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_ajouter3),"login false.");
if(t5==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_ajouter4),"password ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_ajouter4),"password false.");
if(t6==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_ajouter5),"numero ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_ajouter5),"numero false.");
if(t7==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_ajouter6),"adresse ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_ajouter6),"adresse false.");
if ((t1==1)&&(t2==1)&&(t3==1)&&(t4==1)&&(t5==1)&&(t6==1)&&(t7==1))
	{  gtk_label_set_text(GTK_LABEL(Fsortie_ajouter7),"le client a été ajouté.");
	   ajouter_client(c);
	}
else {gtk_label_set_text(GTK_LABEL(Fsortie_ajouter7),"saisir les champs convenablement.");


}

}
void
on_supprimer1_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *espaceC;
 GtkWidget *suppression;
espaceC=lookup_widget(objet,"espaceC");

gtk_widget_destroy(espaceC);
suppression=lookup_widget(objet,"suppression");
suppression=create_suppression();
gtk_widget_show(suppression);


}


void
on_retour2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *espaceC;
 GtkWidget *suppression;
suppression=lookup_widget(objet,"suppression");

gtk_widget_destroy(suppression);
espaceC=lookup_widget(objet,"espaceC");
espaceC=create_espaceC();
gtk_widget_show(espaceC);


}


void
on_ok2_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *input;
 GtkWidget *Fsortie_supprimer;
 client c;
 FILE *f=NULL;
int t;

input=lookup_widget(objet_graphique,"carteid2");
strcpy(c.carteid,gtk_entry_get_text(GTK_ENTRY(input)));
Fsortie_supprimer=lookup_widget(objet_graphique,"Fsortie_supprimer");
t=numbers(c.carteid);
if (t==1)
	{  gtk_label_set_text(GTK_LABEL(Fsortie_supprimer),"le client a été suppimée.");
   supprimer_client(c);
	}
else {gtk_label_set_text(GTK_LABEL(Fsortie_supprimer),"resaisie correctement carte id.");


}




}


void
on_retour1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *espaceC;
 GtkWidget *ajout;
ajout=lookup_widget(objet,"ajout");

gtk_widget_destroy(ajout);
espaceC=lookup_widget(objet,"espaceC");
espaceC=create_espaceC();
gtk_widget_show(espaceC);


}


void
on_modifier1_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *espaceC;
 GtkWidget *modification;
espaceC=lookup_widget(objet,"espaceC");

gtk_widget_destroy(espaceC);
modification=lookup_widget(objet,"modification");
modification=create_modification();
gtk_widget_show(modification);


}


void
on_modifier2_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7;
 GtkWidget *JOUR;
 GtkWidget *MOIS;
 GtkWidget *ANNEE;
 GtkWidget *radio3;
  GtkWidget *radio4;
 client c;
 GtkWidget *modification;
 GtkWidget *sortiemodification,*sortiemodification1,*sortiemodification2,*sortiemodification3,*sortiemodification4,*sortiemodification5,*sortiemodification6,*sortiemodification7;
GSList *List;

GSList* gtk_radio_button_get_group(GtkRadioButton *radio_button);
 FILE *f=NULL;
 int t1,t2,t3,t4,t5,t6,t7;
modification=lookup_widget(objet_graphique,"modification1");
input1=lookup_widget(objet_graphique,"carteid1");
input2=lookup_widget(objet_graphique,"nom1");
input3=lookup_widget(objet_graphique,"prenom1");
input4=lookup_widget(objet_graphique,"login1");
input5=lookup_widget(objet_graphique,"password1");
JOUR=lookup_widget(objet_graphique,"jour1");
MOIS=lookup_widget(objet_graphique,"mois1");
ANNEE=lookup_widget(objet_graphique,"annee1");
input6=lookup_widget(objet_graphique,"num1");
input7=lookup_widget(objet_graphique,"adresse1");
radio3=lookup_widget(GTK_WIDGET(objet_graphique),"radiobuttoncl3");
radio4=lookup_widget(GTK_WIDGET(objet_graphique),"radiobuttoncl4");
sortiemodification=lookup_widget(objet_graphique,"sortiemodification");
sortiemodification1=lookup_widget(objet_graphique,"sortiemodification1");
sortiemodification2=lookup_widget(objet_graphique,"sortiemodification2");
sortiemodification3=lookup_widget(objet_graphique,"sortiemodification3");
sortiemodification4=lookup_widget(objet_graphique,"sortiemodification4");
sortiemodification5=lookup_widget(objet_graphique,"sortiemodification5");
sortiemodification6=lookup_widget(objet_graphique,"sortiemodification6");
sortiemodification7=lookup_widget(objet_graphique,"sortiemodification7");
strcpy(c.carteid,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.login,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(input5)));
c.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JOUR));
c.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MOIS));
c.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ANNEE));
strcpy(c.num,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));
List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (radio3)); 

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data))) strcpy(c.sexe,gtk_button_get_label(GTK_BUTTON(List->data))); 
else{ List = g_slist_next(List); 
strcpy(c.sexe,gtk_button_get_label(GTK_BUTTON(List->data)));}
t1=numbers(c.carteid);
t2=alphabet(c.nom);
t3=alphabet(c.prenom);
t4=alphanumb(c.login);
t5=alphanumb(c.password);
t6=numbers(c.num);
t7=alphabet(c.adresse);

if(t1==1) {
   gtk_label_set_text(GTK_LABEL(sortiemodification),"carte identite ok.");
}else 
gtk_label_set_text(GTK_LABEL(sortiemodification),"carte identite false.");

if(t2==1) {
   gtk_label_set_text(GTK_LABEL(sortiemodification1),"nom ok.");
}else 
gtk_label_set_text(GTK_LABEL(sortiemodification1),"nom false.");
if(t3==1) {
   gtk_label_set_text(GTK_LABEL(sortiemodification2),"prenom ok.");
}else 
gtk_label_set_text(GTK_LABEL(sortiemodification2),"prenom false.");
if(t4==1) {
   gtk_label_set_text(GTK_LABEL(sortiemodification3),"login ok.");
}else 
gtk_label_set_text(GTK_LABEL(sortiemodification3),"login false.");
if(t5==1) {
   gtk_label_set_text(GTK_LABEL(sortiemodification4),"password ok.");
}else 
gtk_label_set_text(GTK_LABEL(sortiemodification4),"password false.");
if(t6==1) {
   gtk_label_set_text(GTK_LABEL(sortiemodification5),"numero ok.");
}else 
gtk_label_set_text(GTK_LABEL(sortiemodification5),"numero false.");
if(t7==1) {
   gtk_label_set_text(GTK_LABEL(sortiemodification6),"adresse ok.");
}else 
gtk_label_set_text(GTK_LABEL(sortiemodification6),"adresse false.");
if ((t1==1)&&(t2==1)&&(t3==1)&&(t4==1)&&(t5==1)&&(t6==1)&&(t7==1))
	{  gtk_label_set_text(GTK_LABEL(sortiemodification7),"le client a été modifie.");
	   modifier_client(c);
	}
else {gtk_label_set_text(GTK_LABEL(sortiemodification7),"saisir les champs convenablement.");


}

}


void
on_rechercher1_clicked                 (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{FILE *f;
client c;
char ch[50];


GtkWidget *output;
char carteid[50];
char ch1[50],ch2[50],ch3[50],ch4[50],ch5[50],ch6[50],ch7[50],ch8[50];
char j[50],m[50],a[50];
GtkWidget *input1;
GtkWidget  *output1,*output2,*output3,*output4,*output5,*output6,*output7,*output8,*output9,*output10;
input1=lookup_widget(objet_graphique,"carteid1");
strcpy(carteid,gtk_entry_get_text(GTK_ENTRY(input1)));
output = lookup_widget(objet_graphique, "label41") ;
output1=lookup_widget(objet_graphique,"label33");

output2 =lookup_widget(objet_graphique, "label34");
output3 =lookup_widget(objet_graphique, "label35");
output4 =lookup_widget(objet_graphique, "label36");
output5 =lookup_widget(objet_graphique, "label37");
output9 =lookup_widget(objet_graphique, "label63");
output10 =lookup_widget(objet_graphique, "label64");
output6 =lookup_widget(objet_graphique, "label38");
output7 =lookup_widget(objet_graphique, "label39");
output8 =lookup_widget(objet_graphique, "label40");
f=fopen("client.txt","r");
if (f!=NULL) 
{ while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s ",ch1,ch2,ch3,ch4,ch5,j,m,a,ch6,ch7,ch8)!=EOF)
       { if (strcmp(carteid,ch1)==0  )

{


sprintf(ch,"client trouvable");
gtk_label_set_text(GTK_LABEL(output),ch);

   gtk_label_set_text(GTK_LABEL(output1),ch2);

   gtk_label_set_text(GTK_LABEL(output2),ch3);
   gtk_label_set_text(GTK_LABEL(output3),ch4);
   gtk_label_set_text(GTK_LABEL(output4),ch5);
   
   gtk_label_set_text(GTK_LABEL(output5),j);
   gtk_label_set_text(GTK_LABEL(output9),m);
   gtk_label_set_text(GTK_LABEL(output10),a); 
   gtk_label_set_text(GTK_LABEL(output6),ch6);
   gtk_label_set_text(GTK_LABEL(output7),ch7);
   gtk_label_set_text(GTK_LABEL(output8),ch8);
}
else
{
sprintf(ch,"client non trouvable");
gtk_label_set_text(GTK_LABEL(output),ch);
}
}
}
}


void
on_retour3modif_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *espaceC;
 GtkWidget *modification;
modification=lookup_widget(objet,"modification");

gtk_widget_destroy(modification);
espaceC=lookup_widget(objet,"espaceC");
espaceC=create_espaceC();
gtk_widget_show(espaceC);


}


void
on_affichetree_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1; 
treeview1=lookup_widget(objet,"treeview1");
afficher_client(treeview1);
}


void
on_Afficheliste_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espaceC;
 GtkWidget *treeclient;
espaceC=lookup_widget(objet,"espaceC");

gtk_widget_destroy(espaceC);
treeclient=lookup_widget(objet,"treeclient");
treeclient=create_treeclient();
gtk_widget_show(treeclient);
}


void
on_Retrourdetree_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espaceC;
 GtkWidget *treeclient;
treeclient=lookup_widget(objet,"treeclient");

gtk_widget_destroy(treeclient);
espaceC=lookup_widget(objet,"espaceC");
espaceC=create_espaceC();
gtk_widget_show(espaceC);
}





void
on_afficherec_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview2; 
treeview2=lookup_widget(button,"treeview2");
afficher_client(treeview2);
}


void
on_voirrec_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *recladmin;
reclamation r;
char carteid[50];
char ch1[50],ch2[50],ch6[50],ch[50];
int j,m,a;
GtkWidget *output1,*output2,*output3,*output,*input1,*jour,*mois,*annee;
FILE *f=NULL;
recladmin=lookup_widget(button,"recladmin");
output=lookup_widget(button,"contenue1");
output1=lookup_widget(button,"carteidrec1");
jour=lookup_widget(button,"recljour1");
mois=lookup_widget(button,"reclmois1");
annee=lookup_widget(button,"reclannee1");
strcpy(carteid,gtk_entry_get_text(GTK_ENTRY(input1)));
r.dr.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
r.dr.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
r.dr.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
f=fopen("envoireclamation.txt","r");
if (f!=NULL) 
{ while(fscanf(f,"%s %s %d %d %d %s  ",ch1,ch2,j,m,a,ch6)!=EOF)
       { if (strcmp(carteid,ch1)==0 &&(r.dr.jour==j)&&(r.dr.mois==m)&&(r.dr.annee==a) )






   gtk_label_set_text(GTK_LABEL(output),ch6);

   
else
{
sprintf(ch,"client non trouvable");
gtk_label_set_text(GTK_LABEL(output),ch);
}
}
}
}




void
on_envoyerrecl_clicked                 (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *input1,*input2,*input3;
 GtkWidget *JOUR;
 GtkWidget *MOIS;
 GtkWidget *ANNEE;
 
  GtkWidget *Fsortie_reclamation,*Fsortie_reclamation1,*Fsortie_reclamation2,*Fsortie_reclamation3;
int t1,t2,t3;

 reclamation r;
 GtkWidget *recladmin;

 FILE *f=NULL;
 client c;
recladmin=lookup_widget(objet_graphique,"recladmin");
input1=lookup_widget(objet_graphique,"carteidrec");
input2=lookup_widget(objet_graphique,"sujetrec");
JOUR=lookup_widget(objet_graphique,"recljour");
MOIS=lookup_widget(objet_graphique,"reclmois");
ANNEE=lookup_widget(objet_graphique,"reclannee");
input3=lookup_widget(objet_graphique,"contenuerec");


Fsortie_reclamation=lookup_widget(objet_graphique,"sortiereclamation");
Fsortie_reclamation1=lookup_widget(objet_graphique,"sortiereclamation1");
Fsortie_reclamation2=lookup_widget(objet_graphique,"sortiereclamation2");
Fsortie_reclamation3=lookup_widget(objet_graphique,"sortiereclamation3");

strcpy(r.carteid,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.sujet,gtk_entry_get_text(GTK_ENTRY(input2)));



r.dr.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JOUR));
r.dr.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MOIS));
r.dr.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ANNEE));
strcpy(r.contenue,gtk_entry_get_text(GTK_ENTRY(input3)));

t1=numbers(r.carteid);
t2=alphabet(r.sujet);
t3=alphabet(r.contenue);
if(t1==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_reclamation)," ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_reclamation)," false.");
if(t2==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_reclamation2)," ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_reclamation2)," false.");
if(t3==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_reclamation3)," ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_reclamation3)," false.");


if ((t1==1)&&(rechercher(r.carteid)==1)&&(t2==1)&&(t3==1))
	{  gtk_label_set_text(GTK_LABEL(Fsortie_reclamation1),"reclamation repondue.");
	   ajouter_reclamation(r);
	}
else {gtk_label_set_text(GTK_LABEL(Fsortie_reclamation1),"mal saisie .");


}



}

void
on_reclamationadmin_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *espaceC;
 GtkWidget *recladmin;
espaceC=lookup_widget(objet,"espaceC");

gtk_widget_destroy(espaceC);
recladmin=lookup_widget(objet,"recladmin");
recladmin=create_recladmin();
gtk_widget_show(recladmin);

}




void
on_reclam_clicked                      (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *input1,*input2,*input3;
 GtkWidget *JOUR;
 GtkWidget *MOIS;
 GtkWidget *ANNEE;
 
  GtkWidget *Fsortie_reclamation,*Fsortie_reclamation1,*Fsortie_reclamation2,*Fsortie_reclamation3;
int t1,t2,t3;

 reclamation r;
 GtkWidget *reclclient;

 FILE *f=NULL;
 
reclclient=lookup_widget(objet_graphique,"reclclient");
input1=lookup_widget(objet_graphique,"entry5recclient");
input2=lookup_widget(objet_graphique,"entry7recclient");
JOUR=lookup_widget(objet_graphique,"recljour");
MOIS=lookup_widget(objet_graphique,"reclmois");
ANNEE=lookup_widget(objet_graphique,"reclannee");
input3=lookup_widget(objet_graphique,"entry6recclient");


Fsortie_reclamation=lookup_widget(objet_graphique,"label98rec");
Fsortie_reclamation3=lookup_widget(objet_graphique,"label99rec");
Fsortie_reclamation2=lookup_widget(objet_graphique,"label100rec");
Fsortie_reclamation1=lookup_widget(objet_graphique,"label101rec");

strcpy(r.carteid,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.sujet,gtk_entry_get_text(GTK_ENTRY(input2)));



r.dr.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JOUR));
r.dr.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MOIS));
r.dr.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ANNEE));
strcpy(r.contenue,gtk_entry_get_text(GTK_ENTRY(input3)));

t1=numbers(r.carteid);
t2=alphabet(r.sujet);
t3=alphabet(r.contenue);
if(t1==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_reclamation)," ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_reclamation)," false.");
if(t2==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_reclamation2)," ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_reclamation2)," false.");
if(t3==1) {
   gtk_label_set_text(GTK_LABEL(Fsortie_reclamation3)," ok.");
}else 
gtk_label_set_text(GTK_LABEL(Fsortie_reclamation3)," false.");


if ((t1==1)&&(rechercher(r.carteid)==1)&&(t2==1)&&(t3==1))
	{  gtk_label_set_text(GTK_LABEL(Fsortie_reclamation1),"reclamation envoyee.");
	   ajouter_reclamation1(r);
	}
else {gtk_label_set_text(GTK_LABEL(Fsortie_reclamation1),"mal saisie .");


}



}


void
on_quiitter_clicked                    (GtkWidget     *objet,
                                        gpointer         user_data)
{
 GtkWidget *reclclient;
reclclient=lookup_widget(objet,"reclclient");

gtk_widget_destroy(reclclient);


}


void
on_retourrec_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *espaceC;
 GtkWidget *recladmin;
recladmin=lookup_widget(objet,"recladmin");

gtk_widget_destroy(espaceC);
espaceC=lookup_widget(objet,"espaceC");
espaceC=create_espaceC();
gtk_widget_show(espaceC);


}


void
on_retour3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espaceC;
 GtkWidget *modification;
modification=lookup_widget(objet,"modification");

gtk_widget_destroy(modification);
espaceC=lookup_widget(objet,"espaceC");
espaceC=create_espaceC();
gtk_widget_show(espaceC);
}

