#include "prwindow.h"

static void prWindow_class_init(PRWindowClass *klass);
static void prWindow_init(PRWindow *window);
static void prWindow_destroy(GtkObject *object);
static void prWindow_size_request(GtkWidget *widget, GtkRequisition *requisition);
static void prWindow_size_allocate(GtkWidget *widget, GtkAllocation *allocation);
static void prWindow_realize(GtkWidget *widget);
static gboolean prWindow_expose(GtkWidget *widget, GdkEventExpose *event);

GtkType prWindow_get_type(void)
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

GtkWidget * prWindow_new(void)
{
   return GTK_WIDGET(gtk_type_new(prWindow_get_type()));
}

static void prWindow_init(PRWindow *window) 
{

};

static void prWindow_class_init(PRWindowClass *klass) {};

static void prWindow_destroy(GtkObject *object)
{
  PRWindow *pr;
  PRWindowClass *klass;

  g_return_if_fail(object != NULL);
  g_return_if_fail(IS_PRWINDOW(object));

  pr = PR_WINDOW(object);

  //klass = gtk_type_class(gtk_widget_get_type());

  if (GTK_OBJECT_CLASS(klass)->destroy) {
     (* GTK_OBJECT_CLASS(klass)->destroy) (object);
  }
}

static void gtk_cpu_class_init(PRWindowClass *klass)
{
  GtkWidgetClass *widget_class;
  GtkObjectClass *object_class;


  widget_class = (GtkWidgetClass *) klass;
  object_class = (GtkObjectClass *) klass;

  widget_class->realize = prWindow_realize;
  widget_class->size_request = prWindow_size_request;
  widget_class->size_allocate = prWindow_size_allocate;
  widget_class->expose_event = prWindow_expose;

  object_class->destroy = prWindow_destroy;
}