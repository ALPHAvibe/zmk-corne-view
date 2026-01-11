#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include "peripheral_status.h"
#include "custom_art.h"

static lv_obj_t *widget_obj;

lv_obj_t *peripheral_status_get_widget(void) {
    return widget_obj;
}

void draw_custom_art(lv_obj_t *canvas, int x_offset, int y_offset) {
    lv_color_t black = lv_color_black();

    for (int y = 0; y < custom_art_height; y++) {
        for (int x = 0; x < custom_art_width; x++) {
            int byte_idx = y * custom_art_stride + (x / 8);
            int bit_idx = 7 - (x % 8);

            if (custom_art_map[byte_idx] & (1 << bit_idx)) {
                lv_canvas_set_px_color(canvas, x + x_offset, y + y_offset, black);
            }
        }
    }
}

void peripheral_status_init(lv_obj_t *parent) {
    widget_obj = lv_obj_create(parent);
    lv_obj_set_size(widget_obj, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_bg_color(widget_obj, lv_color_white(), LV_PART_MAIN);
    lv_obj_set_style_border_width(widget_obj, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(widget_obj, 0, LV_PART_MAIN);

    static lv_color_t cbuf[70 * 140];
    lv_obj_t *canvas = lv_canvas_create(widget_obj);
    lv_canvas_set_buffer(canvas, cbuf, 70, 140, LV_IMG_CF_TRUE_COLOR);
    lv_canvas_fill_bg(canvas, lv_color_white(), LV_OPA_COVER);

    draw_custom_art(canvas, 0, 0);

    lv_obj_align(canvas, LV_ALIGN_CENTER, 0, 0);
}
