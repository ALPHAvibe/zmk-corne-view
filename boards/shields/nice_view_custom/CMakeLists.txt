# Copyright (c) 2024 The ZMK Contributors
# SPDX-License-Identifier: MIT

if(CONFIG_SHIELD_NICE_VIEW_CUSTOM)
  target_sources(app PRIVATE custom_status_screen.c)
endif()
