#include <gtk/gtk.h>

                               
void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_calcul_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_radiobutton_fem_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_male_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modif_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modif2_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_rechercher_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_annul_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);
