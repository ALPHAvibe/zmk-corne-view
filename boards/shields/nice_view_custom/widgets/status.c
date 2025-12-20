#include <zephyr/kernel.h>
#include <zmk/display.h>

#include "peripheral_status.h"

static lv_obj_t *screen;

lv_obj_t *zmk_display_status_screen() {
    if (screen == NULL) {
        screen = lv_obj_create(NULL);
        lv_obj_set_size(screen, LV_PCT(100), LV_PCT(100));
        peripheral_status_init(screen);
    }

    return screen;
}
