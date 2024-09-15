#include <gtk/gtk.h>

#include "curly_application.h"
#include "curly_application_window.h"

struct _CurlyApplication {
	GtkApplication parent;
};

G_DEFINE_TYPE(CurlyApplication, curly_application, GTK_TYPE_APPLICATION)

static void curly_application_init(CurlyApplication *application)
{
}

static void curly_application_activate(GApplication *application)
{
	GtkWidget *window = curly_application_window_new(CURLY_APPLICATION(application));
	gtk_window_present(GTK_WINDOW(window));
}

static void curly_application_class_init(CurlyApplicationClass *class)
{
	G_APPLICATION_CLASS(class)->activate = curly_application_activate;
}

GApplication *curly_application_new(void)
{
	return g_object_new(CURLY_TYPE_APPLICATION,
						"application-id", "com.github.mjmdl.curly",
#ifdef G_APPLICATION_DEFAULT_FLAGS
						"flags", G_APPLICATION_DEFAULT_FLAGS,
#else
						"flags", G_APPLICATION_FLAGS_NONE,
#endif
						NULL);
}
