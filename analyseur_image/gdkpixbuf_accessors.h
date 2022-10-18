/*
 * gdkpixbuf_accessors.h
 *
 *  Created on: 22 juin 2021
 *      Author: a.pitra
 */

#ifndef GDKPIXBUF_ACCESSORS_H_
#define GDKPIXBUF_ACCESSORS_H_

#include <gtk/gtk.h>

/**
 * Fonction permettant de recuperer les composantes d'un pixel dans un GdkPixbuf
 *
 * @param GdkPixbuf : the structure to access
 * @param x         : the x coordinate of the pixel
 * @param y         : the y coordinate of the pixel
 * @param red       : the red component of the pixel (in range 0 to 255)
 * @param green     : the green component of the pixel (in range 0 to 255)
 * @param blue      : the blue component of the pixel (in range 0 to 255)
 * @return Will returns TRUE if successful, or FALSE if not
 */
gboolean gdkpixbuf_get_pixel_color (GdkPixbuf *pixbuf, gint x, gint y, guchar *red, guchar *green, guchar *blue) ;

/**
 * Fonction permettant de modifier les composantes d'un pixel dans un GdkPixbuf
 *
 * @param GdkPixbuf : the structure to access
 * @param x         : the x coordinate of the pixel
 * @param y         : the y coordinate of the pixel
 * @param red       : the new red component for the pixel (in range 0 to 255)
 * @param green     : the new green component for the pixel (in range 0 to 255)
 * @param blue      : the new blue component for the pixel (in range 0 to 255)
 * @return Will returns TRUE if successful, or FALSE if not
 */
gboolean gdkpixbuf_set_pixel_color (GdkPixbuf *pixbuf, gint x, gint y, guchar red, guchar green, guchar blue) ;


#endif /* GDKPIXBUF_ACCESSORS_H */

