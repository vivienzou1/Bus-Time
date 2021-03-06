#pragma once

#define BUS_STOP_LIST_MAX_ELEMENTS 30
#define BUS_STOP_LIST_MESSAGE_PARTS 3

#define SERVICE_LIST_MAX_ELEMENTS 20
#define SERVICE_LIST_MESSAGE_PARTS 2

// service no, next bus time, next bus load, subsequent bus time, subsequent bus load
#define DETAILS_LIST_MESSAGE_PARTS 6

#define MESSAGE_DELIMITER '|'

#define STRING_SIZE 50


#include <pebble.h>

char bus_stop_list[BUS_STOP_LIST_MAX_ELEMENTS][BUS_STOP_LIST_MESSAGE_PARTS][STRING_SIZE];
char service_list[SERVICE_LIST_MAX_ELEMENTS][SERVICE_LIST_MESSAGE_PARTS][STRING_SIZE];
char details_list[DETAILS_LIST_MESSAGE_PARTS][STRING_SIZE];

void store_init();
void service_list_reset();
void bus_stop_list_reset();
void details_list_reset();

void bus_stop_list_add_string(char *string);
void service_list_add_string(char *string);
void details_list_add_string(char *string);

int get_bus_stop_list_count();
int get_service_list_count();

void split_bus_stop_data();
void split_service_list_data();

void save_last_app_alive_message_time();
time_t get_time_since_last_app_alive_message();