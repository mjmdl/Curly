#include <gtk/gtk.h>

#include "curly_application.h"
#include "curly_application_window.h"

struct _CurlyApplicationWindow
{
	GtkApplicationWindow parent;
};

G_DEFINE_TYPE(CurlyApplicationWindow, curly_application_window, GTK_TYPE_APPLICATION_WINDOW)

static void curly_application_window_init(CurlyApplicationWindow *window)
{
}

static void curly_application_window_class_init(CurlyApplicationWindowClass *class)
{
}

GtkWidget *curly_application_window_new(CurlyApplication *application)
{
	return g_object_new(
		CURLY_TYPE_APPLICATION_WINDOW,
		"application", application,
		"title", "Curly",
		"default-width", 800,
		"default-height", 600,
		NULL);
}
