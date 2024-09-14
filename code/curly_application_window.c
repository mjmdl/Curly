#include <gtk/gtk.h>

#include "curly_application.h"
#include "curly_application_window.h"
#include "curly_request_input.h"

struct _CurlyApplicationWindow {
	GtkApplicationWindow parent;
};

G_DEFINE_TYPE(CurlyApplicationWindow, curly_application_window, GTK_TYPE_APPLICATION_WINDOW)

static void curly_application_window_init(CurlyApplicationWindow *window)
{
	GtkWidget *request_input = curly_request_input_new();
	gtk_window_set_child(GTK_WINDOW(window), request_input);
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
