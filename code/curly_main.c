#include <gtk/gtk.h>

#include "curly_application.h"

int main(int argc, char *argv[])
{
	GApplication *application = curly_application_new();
	return g_application_run(application, argc, argv);
}
