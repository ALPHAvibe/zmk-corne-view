#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include "peripheral_status.h"

LV_IMG_DECLARE(custom_art);

static lv_obj_t *widget_obj;

lv_obj_t *peripheral_status_get_widget(void) {
    return widget_obj;
}

void peripheral_status_init(lv_obj_t *parent) {
    widget_obj = lv_obj_create(parent);
    lv_obj_set_size(widget_obj, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_bg_color(widget_obj, lv_color_white(), LV_PART_MAIN);
    lv_obj_set_style_border_width(widget_obj, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(widget_obj, 0, LV_PART_MAIN);

    lv_obj_t *art = lv_img_create(widget_obj);
    lv_img_set_src(art, &custom_art);
    lv_obj_align(art, LV_ALIGN_CENTER, 0, 0);
}
