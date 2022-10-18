/*
 * callbacks.h
 *
 *  Created on: 22 juin 2021
 *      Author: a.pitra
 */

#ifndef CALLBACKS_H_
#define CALLBACKS_H_

#include <gtk/gtk.h>

G_MODULE_EXPORT void on_filechooserbutton_image_file_set() ;
G_MODULE_EXPORT void on_window1_destroy () ;
G_MODULE_EXPORT void on_button1_clicked();
G_MODULE_EXPORT void on_button2_clicked();
G_MODULE_EXPORT void on_window1_realize() ;


#endif /* CALLBACKS_H_ */
