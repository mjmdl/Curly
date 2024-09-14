#include <curl/curl.h>
#include <gtk/gtk.h>

#include "curly_request_input.h"

struct _CurlyRequestInput {
	GtkBox parent;
	GtkWidget *verbs;
	GtkWidget *url;
};

G_DEFINE_TYPE(CurlyRequestInput, curly_request_input, GTK_TYPE_BOX)

static void curly_request_input_sender_clicked(GtkButton *sender, CurlyRequestInput *input)
{
	guint selected = gtk_drop_down_get_selected(GTK_DROP_DOWN(input->verbs));
	GListModel *model = gtk_drop_down_get_model(GTK_DROP_DOWN(input->verbs));
	const gchar *verb = gtk_string_list_get_string(GTK_STRING_LIST(model), selected);
	if (!verb || verb[0] == '\0') {
		g_print("An invalid verb was selected!\n");
		return;
	}

	GtkEntryBuffer *buffer = gtk_text_get_buffer(GTK_TEXT(input->url));
	const gchar *path = gtk_entry_buffer_get_text(buffer);

	CURL *curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, path);

	switch (verb[0]) {
	case 'D':
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
		break;
	case 'G':
		curl_easy_setopt(curl, CURLOPT_HTTPGET, 0);
		break;
	case 'O':
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "OPTIONS");
		break;
	case 'P':
		switch (verb[1]) {
		case 'A':
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PATCH");
			break;
		case 'O':
			curl_easy_setopt(curl, CURLOPT_HTTPPOST, "PUT");
			break;
		case 'U':
			curl_easy_setopt(curl, CURLOPT_PUT, "PUT");
			break;
		case '\0':
		default:
			g_print("An invalid verb was selected!\n");
			return;
		}
		break;
	default:
		g_print("An invalid verb was selected!\n");
		return;
	}
	
	CURLcode result = curl_easy_perform(curl);
	if (result != CURLE_OK) {
		g_error("Request Error: %s\n", curl_easy_strerror(result));
	}
	curl_easy_cleanup(curl);
}

static void curly_request_input_init(CurlyRequestInput *input)
{
	GtkBuilder *builder = gtk_builder_new_from_file("gui/request_input.ui");
	if (!builder) {
		g_error("Could not create the builder.\n");
		return;
	}
	
	GObject *wrapper = gtk_builder_get_object(builder, "wrapper");
	if (!wrapper || !GTK_IS_WIDGET(wrapper)) {
		g_error("Could not load request input widget.\n");
		return;
	}
	gtk_box_append(GTK_BOX(input), GTK_WIDGET(wrapper));
	
	GObject *verbs = gtk_builder_get_object(builder, "verbs");
	if (!verbs) {
		g_error("Could not load the verbs dropdown widget.\n");
		return;
	}
	input->verbs = GTK_WIDGET(verbs);

	GObject *url = gtk_builder_get_object(builder, "url");
	if (!url) {
		g_error("Could not load the URL input widget.\n");
		return;
	}
	input->url = GTK_WIDGET(url);
	
	GObject *sender = gtk_builder_get_object(builder, "sender");
	if (!sender) {
		g_error("Could not load the sender button widget.\n");
		return;
	}
	g_signal_connect(sender, "clicked", G_CALLBACK(curly_request_input_sender_clicked), input);
}

static void curly_request_input_class_init(CurlyRequestInputClass *class)
{
}

GtkWidget *curly_request_input_new(void)
{
	return g_object_new(
		CURLY_TYPE_REQUEST_INPUT,
		"orientation", GTK_ORIENTATION_VERTICAL,
		"spacing", 0,
		NULL);
}
