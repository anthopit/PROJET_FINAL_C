/*
 * gdkpixbuf_accessors.c
 *
 *  Created on: 22 juin 2021
 *      Author: a.pitra
 */
#include "gdkpixbuf_accessors.h"

gboolean gdkpixbuf_get_pixel_color (GdkPixbuf *pixbuf, gint x, gint y, guchar *red, guchar *green, guchar *blue) {
  guchar *buffer = NULL ; /* Image applatie dans un tableau (lineaire) */
  gint row_size = 0 ;     /* Largeur d'une ligne de l'image en octets */
  gint pos = 0 ;          /* Position lineaire du pixel */

  /* Verifier que le GdkPixbuf existe */
  if (!pixbuf || !GDK_IS_PIXBUF(pixbuf))
    return FALSE ;

  /* Verifier que les coordonnees (x,y) du pixel sont positives */
  if (x<0 || y<0)
    return FALSE ;

  /* Verifier que les coordonnees (x,y) du pixel ne debordent pas de l'image */
  if (x >= gdk_pixbuf_get_width (pixbuf) || y >= gdk_pixbuf_get_height (pixbuf))
    return FALSE ;

  buffer = gdk_pixbuf_get_pixels(pixbuf) ;
  row_size = gdk_pixbuf_get_rowstride (pixbuf) ;

  /* Calculer la position du pixel */
  if (gdk_pixbuf_get_has_alpha (pixbuf))
    pos = (y * row_size ) + (x * 4) ; /* Quatres composantes pour chaque pixel : R,G,B et Alpha (transparence) */
  else
    pos = (y * row_size) + (x * 3) ; /* Trois composantes pour chaque pixel : R,G,B */

  /* Recuperer les composantes du pixel (x,y) */
  *red   = buffer[pos] ;
  *green = buffer[pos + 1] ;
  *blue  = buffer[pos + 2] ;

  return TRUE ;
}

gboolean gdkpixbuf_set_pixel_color (GdkPixbuf *pixbuf, gint x, gint y, guchar red, guchar green, guchar blue) {
  guchar *buffer = NULL ; /* Image applatie dans un tableau (lineaire) */
  gint row_size = 0 ;     /* Largeur d'une ligne de l'image en octets */
  gint pos = 0 ;          /* Position lineaire du pixel */

  /* Verifier que le GdkPixbuf existe */
  if (!pixbuf || !GDK_IS_PIXBUF(pixbuf))
    return FALSE ;

  /* Verifier que les coordonnees du pixel sont positives */
  if (x<0 || y<0)
    return FALSE ;

  /* Verifier que les coordonnees du pixel ne debordent pas de l'image */
  if (x >= gdk_pixbuf_get_width (pixbuf) || y >= gdk_pixbuf_get_height (pixbuf))
    return FALSE ;

  buffer = gdk_pixbuf_get_pixels (pixbuf) ;
  row_size = gdk_pixbuf_get_rowstride (pixbuf) ;

  /* Calculer la position du pixel */
  if (gdk_pixbuf_get_has_alpha (pixbuf))
    pos = (y * row_size ) + (x * 4) ; /* Quatres composantes pour chaque pixel : R,G,B et Alpha (transparence) */
  else
    pos = (y * row_size ) + (x * 3) ; /* Trois composantes pour chaque pixel : R,G,B */

  /* Modifier les composantes du pixel (x,y) */
  buffer[pos] = red ;
  buffer[pos + 1] = green ;
  buffer[pos + 2] = blue ;

  return TRUE ;
}


