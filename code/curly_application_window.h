#ifndef CURLY_APPLICATION_WINDOW_H
#define CURLY_APPLICATION_WINDOW_H

#include <gtk/gtk.h>

#include "curly_application.h"

G_BEGIN_DECLS

#define CURLY_TYPE_APPLICATION_WINDOW (curly_application_window_get_type())

G_DECLARE_FINAL_TYPE(CurlyApplicationWindow, curly_application_window, CURLY, APPLICATION_WINDOW, GtkApplicationWindow)

GtkWidget *curly_application_window_new(CurlyApplication *app);

G_END_DECLS

#endif // CURLY_APPLICATION_WINDOW_H
