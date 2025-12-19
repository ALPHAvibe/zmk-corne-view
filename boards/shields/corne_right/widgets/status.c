/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/events/usb_conn_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/usb.h>
#include <zmk/ble.h>
#include <zmk/events/ble_active_profile_changed.h>

#include "status.h"

extern const lv_img_dsc_t custom_status_image;

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

struct status_state {
    bool connected;
};

static void set_status_symbol(lv_obj_t *label, struct status_state state) {
    // Custom implementation - just display the image
}

static void output_status(struct status_state state) {
    struct zmk_widget_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_status_symbol(widget->obj, state); }
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_status, struct status_state, output_status, NULL)
ZMK_SUBSCRIPTION(widget_status, zmk_battery_state_changed);

int zmk_widget_status_init(struct zmk_widget_status *widget, lv_obj_t *parent) {
    widget->obj = lv_img_create(parent);
    lv_img_set_src(widget->obj, &custom_status_image);
    lv_obj_align(widget->obj, LV_ALIGN_TOP_RIGHT, 0, 0);

    sys_slist_append(&widgets, &widget->node);

    return 0;
}

lv_obj_t *zmk_widget_status_obj(struct zmk_widget_status *widget) { return widget->obj; }
