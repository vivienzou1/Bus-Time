#include "view_setup_helper.h"

void menu_layer_set_up(MenuLayer* menu_layer) {

    #ifdef PBL_COLOR
        menu_layer_set_normal_colors(menu_layer, COLOR_BACKGROUND, COLOR_TEXT);
        menu_layer_set_highlight_colors(menu_layer, COLOR_SECONDARY, COLOR_TEXT);
    #else
        
    #endif
}

void window_set_up(Window* window) {
    #ifdef PBL_COLOR
        window_set_background_color(window, COLOR_BACKGROUND);
    #else
        window_set_background_color(window, NO_COLOR_BACKGROUND);
    #endif
}

void text_layer_set_up(TextLayer *text_layer) {
    #ifdef PBL_COLOR
        text_layer_set_text_color(text_layer, COLOR_TEXT);
    #else
        text_layer_set_text_color(text_layer, NO_COLOR_TEXT);
    #endif

    text_layer_set_background_color(text_layer, GColorClear);
    text_layer_set_font(text_layer, fonts_get_system_font(FONT_BASIC_TEXT));
    text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
}

#ifdef PBL_SDK_3
    void status_bar_layer_set_up(StatusBarLayer *status_bar_layer) {
            status_bar_layer_set_separator_mode(status_bar_layer, StatusBarLayerSeparatorModeDotted);
            status_bar_layer_set_colors(status_bar_layer, GColorClear, COLOR_TEXT);
    }

    GRect window_with_status_bar_content_bounds(Layer *window_layer, StatusBarLayer *status_bar_layer) {
        GRect window_bounds = layer_get_bounds(window_layer);
        GRect status_bar_bounds = layer_get_bounds(status_bar_layer_get_layer(status_bar_layer));
        GRect menu_layer_bounds = GRect(0, status_bar_bounds.size.h, window_bounds.size.w, window_bounds.size.h - status_bar_bounds.size.h);
        return menu_layer_bounds;
    }
#endif

// helper method to get the height of a specific font
int16_t get_font_height(Window* window, GFont font) {
    
    // creates a text layer, gets the height, and destroys it
    TextLayer *text_layer = text_layer_create(layer_get_bounds(window_get_root_layer(window)));
    text_layer_set_font(text_layer, font);
    text_layer_set_text(text_layer, "Test");

    int16_t height = text_layer_get_content_size(text_layer).h;

    text_layer_destroy(text_layer);
    return height;
}
