#ifndef CURLY_APPLICATION_H
#define CURLY_APPLICATION_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define CURLY_TYPE_APPLICATION (curly_application_get_type())

G_DECLARE_FINAL_TYPE(CurlyApplication, curly_application,
					 CURLY, APPLICATION, GtkApplication)

GApplication *curly_application_new(void);

G_END_DECLS

#endif // CURLY_APPLICATION_H
