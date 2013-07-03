#include "prwindow.h"

static void prWindow_class_init(PRWindowClass *klass);
static void prWindow_init(PRWindow *window);

GtkType prWindow_get_type (void)
{
  static GtkType prWindow_type = 0;

  if (!prWindow_type) {
      static const GtkTypeInfo prWindow_info = {
          "PrWindow",
          sizeof(PRWindow),
          sizeof(PRWindowClass),
          (GtkClassInitFunc) prWindow_class_init,
          (GtkObjectInitFunc) prWindow_init,
          NULL,
          NULL,
          (GtkClassInitFunc) NULL
      };
      prWindow_type = gtk_type_unique(GTK_TYPE_WIDGET, &prWindow_info);
  }


  return prWindow_type;
}

static void prWindow_init(PRWindow *window) {};

static void prWindow_class_init(PRWindowClass *klass) {};