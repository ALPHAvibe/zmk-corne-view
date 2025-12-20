#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>

struct peripheral_status_state {
    bool connected;
};

void peripheral_status_init(lv_obj_t *parent);
lv_obj_t *peripheral_status_get_widget(void);
