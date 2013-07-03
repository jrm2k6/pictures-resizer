#ifndef __PR_WINDOW_H__
#define __PR_WINDOW_H__

#include <gtk/gtk.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define PR_WINDOW(obj)   GTK_CHECK_CAST (obj, prWindow_get_type (), PRWindow)
#define PR_WINDOW_CLASS(klass)  GTK_CHECK_CLASS_CAST (klass, prWindow_get_type (), PRWindowClass)
#define IS_PRWINDOW(obj)       GTK_CHECK_TYPE (obj, prWindow_get_type ())


typedef struct _PRWindow       PRWindow;
typedef struct _PRWindowClass  PRWindowClass;

struct _PRWindow
{
  GtkVBox vbox;
  
  GtkWidget button1;
};

struct _PRWindowClass
{
  GtkVBoxClass parent_class;
};

GtkType prWindow_get_type(void);
GtkWidget* prWindow_new(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PR_WINDOW_H__ */