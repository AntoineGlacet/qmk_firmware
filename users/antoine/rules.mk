# Copyright 2019 Manna Harbour
# https://github.com/manna-harbour/miryoku
# Modified 2025 for modern QMK

MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
AUTO_SHIFT_ENABLE = no # Auto Shift

SRC += antoine.c # shared functions and OLED code
CAPS_WORD_ENABLE = yes # Use built-in caps word feature

# Build option: Clipboard shortcuts (WIN, MAC, or FUN/default)
# Usage: make crkbd:antoine MIRYOKU_CLIPBOARD=WIN
ifneq ($(strip $(MIRYOKU_CLIPBOARD)),)
  OPT_DEFS += -DMIRYOKU_CLIPBOARD_$(MIRYOKU_CLIPBOARD)
endif
