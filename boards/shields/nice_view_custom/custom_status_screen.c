/*
 *
 * Copyright (c) 2023 The ZMK Contributors
 * SPDX-License-Identifier: MIT
 *
 */

#include "widgets/status.h"
// Remove this include since we no longer need it
// #include "widgets/modifiers.h"

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#if IS_ENABLED(CONFIG_NICE_VIEW_WIDGET_STATUS)
static struct zmk_widget_status status_widget;
#endif

// Remove this since modifiers are now part of status widget
// #if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
// static struct zmk_widget_modifiers modifiers_widget;
// #endif

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;
    screen = lv_obj_create(NULL);

#if IS_ENABLED(CONFIG_NICE_VIEW_WIDGET_STATUS)
    zmk_widget_status_init(&status_widget, screen);
    // Position the entire status widget
    lv_obj_align(zmk_widget_status_obj(&status_widget), LV_ALIGN_TOP_LEFT, 0, 0);
#endif

    return screen;
}
