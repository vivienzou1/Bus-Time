#pragma once

#include <pebble.h>


#define COLOR_BACKGROUND GColorBlack
#define COLOR_SECONDARY GColorDarkCandyAppleRed
#define COLOR_TEXT GColorWhite
#define FONT_BASIC_TEXT FONT_KEY_GOTHIC_24

#define CELL_H1_FONT FONT_KEY_GOTHIC_24_BOLD
#define CELL_TEXT_COLOR GColorWhite

void menu_layer_set_up(MenuLayer* menu);
void window_set_up(Window* window);
void text_layer_set_up(TextLayer* text_layer);

#ifdef PBL_PLATFORM_BASALT
    void status_bar_layer_set_up(StatusBarLayer *status_bar_layer);
    GRect window_with_status_bar_content_bounds(Layer *window_layer, StatusBarLayer *status_bar_layer);
#endif

int16_t get_font_height(Window* window, const char* font);
