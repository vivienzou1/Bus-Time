#include "notification_store.h"

#define NOTIFICATION_STORE_MAX_ELEMENTS 5

static char s_notification_store[NOTIFICATION_STORE_MAX_ELEMENTS][2][NOTIFICATION_STORE_STRING_SIZE];
static AppTimer *s_notification_app_timer_store[NOTIFICATION_STORE_MAX_ELEMENTS];
static int s_notifications_counter = -1;

void notification_store_add(char *stop_id, char *service_no, AppTimer *timer) {


    s_notifications_counter++; // counter starts at -1

    // Check for rolling back to the start of the list, and if so we want to 
    // cancel the timer already there
    if (s_notifications_counter >= NOTIFICATION_STORE_MAX_ELEMENTS) {
        s_notifications_counter = s_notifications_counter % NOTIFICATION_STORE_MAX_ELEMENTS;

        AppTimer *timer_to_override = s_notification_app_timer_store[s_notifications_counter];
        if (timer_to_override) {
            app_timer_cancel(timer_to_override);
            timer_to_override = NULL;
        }
    }

    snprintf(s_notification_store[s_notifications_counter][0], sizeof(s_notification_store[s_notifications_counter][0]), "%s", stop_id);
    snprintf(s_notification_store[s_notifications_counter][1], sizeof(s_notification_store[s_notifications_counter][1]), "%s", service_no);

    s_notification_app_timer_store[s_notifications_counter] = timer;
}


void notification_store_remove(char *stop_id, char *service_no) {
    for (int i = 0; i < NOTIFICATION_STORE_MAX_ELEMENTS; i++) {
        char *current_stop_id = s_notification_store[i][0];
        char *current_service_no = s_notification_store[i][1];

        if (strcmp(stop_id, current_stop_id) == 0 && strcmp(service_no, current_service_no) == 0) {

            // clear the stop id in the spot, so when get() is called the invariant is maintained
            snprintf(s_notification_store[i][0], sizeof(s_notification_store[i][0]), "111");
            snprintf(s_notification_store[i][1], sizeof(s_notification_store[i][1]), "aaa");
            app_timer_cancel(s_notification_app_timer_store[i]);
        }
    }
}



AppTimer *notification_store_get(char *stop_id, char *service_no) {
    for (int i = 0; i < NOTIFICATION_STORE_MAX_ELEMENTS; i++) {
        char *current_stop_id = s_notification_store[i][0];
        char *current_service_no = s_notification_store[i][1];

        // invariant: if the string matches, the app timer returned has to be valid
        if (strcmp(stop_id, current_stop_id) == 0 && strcmp(service_no, current_service_no) == 0) {
            return s_notification_app_timer_store[i];
        }
    }

    return NULL;
}

void print_notification_store() {
    for (int i = 0; i < NOTIFICATION_STORE_MAX_ELEMENTS; i++) {
        char *current_stop_id = s_notification_store[i][0];
        char *current_service_no = s_notification_store[i][1];

        APP_LOG(APP_LOG_LEVEL_DEBUG, "_%s_%s_", current_stop_id, current_service_no);
    }
}

