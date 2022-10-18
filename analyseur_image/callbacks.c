/*
 * callbacks.c
 *
 *  Created on: 22 juin 2021
 *      Author: a.pitra
 */
#include <stdio.h>   /* sprintf */
#include <stdlib.h>  /* atoi */
#include <string.h>  /* strlen, strcmp */
#include <ctype.h>   /* isdigit */

#include "callbacks.h"
#include "gdkpixbuf_accessors.h"

extern GtkBuilder *builder;

void init_spin_button (GtkSpinButton *spb, double min_val, double max_val, double val, double step, int digits) {
  gtk_spin_button_set_digits (spb, digits) ;
  gtk_spin_button_set_range (spb, min_val, max_val) ;
  gtk_spin_button_set_value (spb, val) ;
  gtk_spin_button_set_increments (spb, step, step) ;
}
void on_window1_realize(){

	GtkSpinButton *spinbutton_n_R = GTK_SPIN_BUTTON (gtk_builder_get_object (builder, "spinbutton_n_R"));
	GtkSpinButton *spinbutton_n_G = GTK_SPIN_BUTTON (gtk_builder_get_object (builder, "spinbutton_n_G"));
	GtkSpinButton *spinbutton_n_B = GTK_SPIN_BUTTON (gtk_builder_get_object (builder, "spinbutton_n_B"));
	GtkSpinButton *spinbutton_a_R = GTK_SPIN_BUTTON (gtk_builder_get_object (builder, "spinbutton_a_R"));
	GtkSpinButton *spinbutton_a_G = GTK_SPIN_BUTTON (gtk_builder_get_object (builder, "spinbutton_a_G"));
	GtkSpinButton *spinbutton_a_B = GTK_SPIN_BUTTON (gtk_builder_get_object (builder, "spinbutton_a_B"));

	init_spin_button (spinbutton_n_R, 0.0, 255.0, 0.0, 1.0, 0.0);
	init_spin_button (spinbutton_n_G, 0.0, 255.0, 0.0, 1.0, 0.0);
	init_spin_button (spinbutton_n_B, 0.0, 255.0, 0.0, 1.0, 0.0);
	init_spin_button (spinbutton_a_R, 0.0, 255.0, 0.0, 1.0, 0.0);
	init_spin_button (spinbutton_a_G, 0.0, 255.0, 0.0, 1.0, 0.0);
	init_spin_button (spinbutton_a_B, 0.0, 255.0, 0.0, 1.0, 0.0);

}
void get_color_id_n(gint *valeurR, gint *valeurG, gint *valeurB){
	GtkSpinButton *spinbutton_n_R = GTK_SPIN_BUTTON (gtk_builder_get_object (builder, "spinbutton_n_R"));
	GtkSpinButton *spinbutton_n_G = GTK_SPIN_BUTTON (gtk_builder_get_object (builder, "spinbutton_n_G"));
	GtkSpinButton *spinbutton_n_B = GTK_SPIN_BUTTON (gtk_builder_get_object (builder, "spinbutton_n_B"));

	*valeurR = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_n_R));
	*valeurG = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_n_G));
	*valeurB = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_n_B));
}

void get_color_id_a(gint *valeurR, gint *valeurG, gint *valeurB){
	GtkSpinButton *spinbutton_a_R = GTK_SPIN_BUTTON (gtk_builder_get_object (builder, "spinbutton_a_R"));
	GtkSpinButton *spinbutton_a_G = GTK_SPIN_BUTTON (gtk_builder_get_object (builder, "spinbutton_a_G"));
	GtkSpinButton *spinbutton_a_B = GTK_SPIN_BUTTON (gtk_builder_get_object (builder, "spinbutton_a_B"));

	*valeurR = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_a_R));
	*valeurG = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_a_G));
	*valeurB = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton_a_B));
}
void on_filechooserbutton_image_file_set(){
	GdkPixbuf  *gdk_pixbuf = NULL ;
	GtkFileChooser *filechooserbutton_image = GTK_FILE_CHOOSER(gtk_builder_get_object(builder, "filechooserbutton_image"));
	GtkImage* image1 = GTK_IMAGE(gtk_builder_get_object(builder, "image1"));

	/* Récupère le chemin du fichier */
	const gchar *filename = gtk_file_chooser_get_filename(filechooserbutton_image);

	printf ("Fichier : %s\n", filename) ;

	/* Creer un GdkPixbuf depuis un fichier PNG */
	gdk_pixbuf = gdk_pixbuf_new_from_file (filename, NULL);

	 /* Afficher le pixbuf dans un GtkImage */
	gtk_image_set_from_pixbuf (image1, gdk_pixbuf) ;

}
void on_button2_clicked(){
	GtkLabel* label4 = GTK_LABEL(gtk_builder_get_object(builder, "label4"));
	GtkLabel* label5 = GTK_LABEL(gtk_builder_get_object(builder, "label5"));
	GdkPixbuf  *gdk_pixbuf = NULL ;
	GtkFileChooser *filechooserbutton_image = GTK_FILE_CHOOSER(gtk_builder_get_object(builder, "filechooserbutton_image"));

	const gchar *filename = gtk_file_chooser_get_filename(filechooserbutton_image);

	gdk_pixbuf = gdk_pixbuf_new_from_file (filename, NULL);

	int w, h;
	gint x, y = 0, nbn = 0, nba = 0;

	w = gdk_pixbuf_get_width (gdk_pixbuf) ;
	h = gdk_pixbuf_get_height (gdk_pixbuf) ;

	printf ("Width = %d \nHeight = %d\n", w, h);

	guchar R;
	guchar G;
	guchar B;

	gint R0 = 0;
	gint G0 = 0;
	gint B0 = 0;

	gint R1 = 0;
	gint G1 = 0;
	gint B1 = 0;

	get_color_id_n(&R0,&G0,&B0);
	get_color_id_a(&R1,&G1,&B1);

	for (y = 0; y <= h +1; y++){
			for (x = 0; x <= w +1; x++){
				if(gdkpixbuf_get_pixel_color(gdk_pixbuf, x, y, &R, &G, &B) == TRUE && R == R0 && G == G0 && B == B0){
					printf ("Pixels rouges (x = %d, y = %d) [%d %d %d]\n", x, y, R, G, B);
					nbn += 1;
				}
				else if(gdkpixbuf_get_pixel_color(gdk_pixbuf, x, y, &R, &G, &B) == TRUE && R == R1 && G == G1 && B == B1){
					printf ("Pixels verts (x = %d, y = %d) [%d %d %d]\n", x, y, R, G, B);
					nba += 1;
				}
			}
		}

	char msg1[128] = "";
	sprintf(msg1,"Nombre de pixels : %d", nbn);
	gtk_label_set_text(label4,msg1);

	char msg2[128] = "";
	sprintf(msg2,"Nombre de pixels : %d", nba);
	gtk_label_set_text(label5,msg2);

	GtkWidget  *window5;

	window5 = GTK_WIDGET (gtk_builder_get_object (builder, "window5"));

	gtk_widget_show (window5);

}

void on_window1_destroy (GtkObject *object, gpointer user_data){
      printf("Fermeture de la fenetre.\n");
  gtk_main_quit();
}


