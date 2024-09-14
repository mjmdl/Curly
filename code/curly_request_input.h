#ifndef CURLY_REQUEST_INPUT_H
#define CURLY_REQUEST_INPUT_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define CURLY_TYPE_REQUEST_INPUT (curly_request_input_get_type())

G_DECLARE_FINAL_TYPE(CurlyRequestInput, curly_request_input, CURLY, REQUEST_INPUT, GtkBox)

GtkWidget *curly_request_input_new(void);

G_END_DECLS

#endif // CURLY_REQUEST_INPUT_H
