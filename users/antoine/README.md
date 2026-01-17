# Antoine's QMK Userspace

Modern QMK userspace setup for Corne (crkbd) and Fortitude60 keyboards.

**Last Updated:** January 2025  
**QMK Version:** 0.27.0+ compatible  
**Status:** ✅ Fully modernized for 2024-2025 QMK

## Overview

Extended Miryoku-inspired layout with gaming optimization, custom OLED animation, and cross-platform support.

This userspace provides shared functionality across multiple split keyboards:
- **Corne (crkbd)**: 3x6 + 3 thumb keys with OLED displays
- **Fortitude60**: 5x6 + 5 thumb keys (includes number row)

## Structure

```
users/antoine/
├── antoine.c          # Shared OLED animations and tapping term config
├── antoine.h          # Layer definitions, macros, function declarations
├── config.h           # User configuration overrides
└── rules.mk           # Shared feature flags

keyboards/crkbd/keymaps/antoine/
├── keymap.c           # Corne-specific keymaps
├── config.h           # LAYOUT_antoine wrapper for Corne
└── rules.mk           # Corne-specific features (OLED, WPM)

keyboards/fortitude60/keymaps/antoine/
├── keymap.c           # Fortitude60-specific keymaps
├── config.h           # LAYOUT_antoine wrapper for Fortitude60
└── rules.mk           # Fortitude60-specific features
```

## Features

### ✨ Modern QMK Features (2025)
- **Built-in Caps Word** - Use `CW_TOGG` keycode (QMK native, replaces custom implementation)
- **QK_BOOT** - Modern bootloader entry (replaces deprecated `RESET`)
- **QUICK_TAP_TERM** - Updated tapping configuration (replaces `TAPPING_FORCE_HOLD`)
- **Auto OLED Detection** - No need to specify driver type
- **WPM-based OLED Animation** - Cool spaceship that moves faster as you type

### 🎯 Layout Features
- **14 Layers** including:
  - Base: QWERTY, Colemak
  - Navigation, Mouse, Media
  - Numbers, Symbols, Function keys
  - Gaming variants with bottom-row mods
  - Button layer for Ctrl+key shortcuts (PowerPoint optimization)
- **Home Row Mods** - Miryoku-style modifier placement
- **Per-key tapping term** - GUI keys have longer tapping term (300ms), FUN layer 150ms
- **OS-specific clipboard macros** - Configurable for Mac/Win/Linux

### 🖥️ OLED Animations
Custom WPM-reactive spaceship animation that:
- Animates based on typing speed
- Scrolls through space background
- Renders on both halves of split keyboard
- Speed increases with WPM

## Building

### Compile for Corne
```bash
qmk compile -kb crkbd -km antoine
```

### Compile for Fortitude60
```bash
qmk compile -kb fortitude60 -km antoine
```

### Flash to keyboard
```bash
qmk flash -kb crkbd -km antoine
# or
qmk flash -kb fortitude60 -km antoine
```

### Build with Options
```bash
# For Mac clipboard shortcuts
qmk compile -kb crkbd -km antoine -e MIRYOKU_CLIPBOARD=MAC

# For Windows clipboard shortcuts
qmk compile -kb crkbd -km antoine -e MIRYOKU_CLIPBOARD=WIN

# For Linux (default)
qmk compile -kb crkbd -km antoine
```

## Layers

| Layer | Purpose |
|-------|---------|
| QWERTY | Base QWERTY layout with home row mods |
| COLEMAK | Base Colemak layout with home row mods |
| NAV | Navigation (arrows, home/end, page up/down) + layer switching + QK_BOOT |
| MOUSE | Mouse movement, scroll wheel + QK_BOOT |
| MEDIA | Media controls (play/pause, volume) + RGB controls + QK_BOOT |
| NUM | Number pad on right hand + QK_BOOT |
| SYM | Symbols on right hand + QK_BOOT |
| FUN | Function keys (F1-F12) + QK_BOOT |
| BUTTON | Ctrl+key shortcuts for one-handed use (PowerPoint optimization) |
| GAMING_QWERTY | QWERTY with mods on bottom row for gaming |
| GAMING_COLEMAK | Colemak with mods on bottom row for gaming |
| NUM_G, SYM_G, FUN_G | Gaming layer variants (symmetric on both hands) |

## Key Features & Special Keys

### Bootloader Access
- **QK_BOOT**: Enter bootloader mode (available on NAV, MOUSE, MEDIA, NUM, SYM, FUN layers)

### Layer Switching
- **DF(layer)**: Switch default layer (on NAV layer)
  - DF(QWERTY), DF(COLEMAK), DF(GAMING_QWERTY), DF(GAMING_COLEMAK)

### Caps Word
- **CW_TOGG**: Toggle Caps Word (add to your preferred layer if needed)
- Built-in QMK feature - automatically capitalizes letters
- Numbers and symbols work normally while active

### Layer-Tap Keys
- **LT(layer, key)**: Tap for key, hold for layer
  - Example: `LT(NAV, KC_SPC)` = tap for space, hold for NAV layer

## Customization

### Adding a New Keyboard

1. Create keymap directory: `keyboards/YOUR_KEYBOARD/keymaps/antoine/`
2. Create `config.h` with `LAYOUT_antoine` wrapper macro:
```c
#pragma once

#define LAYOUT_antoine(\
    K00, K01, ..., \
    ...\
)\
LAYOUT_your_keyboard(\
    K00, K01, ..., \
    ...\
)
```
3. Create `keymap.c`:
```c
#include "antoine.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_antoine(
        // Your keymap here - use same layout as other keyboards
    ),
    // ... all other layers
};
```
4. Create `rules.mk` with keyboard-specific features
5. Build and flash!

## Recent Changes (January 2025 Migration)

### What Changed
1. ✅ **Removed deprecated `RESET`** → Now using `QK_BOOT`
2. ✅ **Removed deprecated `IGNORE_MOD_TAP_INTERRUPT`** (now default behavior)
3. ✅ **Updated `TAPPING_FORCE_HOLD`** → `QUICK_TAP_TERM 0`
4. ✅ **Removed `OLED_DRIVER = SSD1306`** (auto-detected)
5. ✅ **Replaced custom caps_word** with QMK built-in `CAPS_WORD_ENABLE`
6. ✅ **Reorganized structure**: Keymaps now in keyboard folders, not userspace
7. ✅ **Userspace cleanup**: Now only contains shared code (OLED, tapping terms, functions)

### Why These Changes?
- **Better maintainability**: Following QMK best practices
- **Future-proof**: Compatible with latest QMK versions
- **Less custom code**: Using QMK built-in features reduces bugs
- **Easier to extend**: Clear separation makes adding keyboards simple

### Migration from Old Setup
If you're updating from the old structure where keymaps were in `users/antoine/antoine.c`:
- ✅ All keymaps moved to `keyboards/*/keymaps/antoine/keymap.c`
- ✅ Shared code (OLED, functions) stays in `users/antoine/antoine.c`
- ✅ No functionality lost - everything still works the same!
- ✅ Custom caps_word deleted - using QMK's version now

## Troubleshooting

### Compilation Errors
```bash
# Update QMK
qmk git-submodule
qmk setup

# Verify installation
qmk doctor

# Clean build
qmk clean -a
qmk compile -kb crkbd -km antoine
```

### OLED Not Working
- Check that `OLED_ENABLE = yes` is in your keyboard's `rules.mk`
- Make sure `WPM_ENABLE = yes` is enabled for the animation
- Verify OLED is physically connected
- Try reflashing the firmware

### Key Behavior Issues
- Review tapping term settings in `users/antoine/config.h`
- Check per-key tapping term in `users/antoine/antoine.c:get_tapping_term()`
- Adjust `TAPPING_TERM` value (default 150ms)
- Try `QUICK_TAP_TERM` adjustment for hold behavior

### Caps Word Not Working
- The keycode is `CW_TOGG` - make sure you add it to a layer
- Built-in caps word is enabled via `CAPS_WORD_ENABLE = yes` in rules.mk
- Old double-shift trigger is gone - now uses explicit keycode

## Build Options

Available compile-time options:

| Option | Values | Description |
|--------|--------|-------------|
| `MIRYOKU_CLIPBOARD` | `WIN`, `MAC`, `FUN` | Clipboard shortcut style |
| `MIRYOKU_ALPHAS` | `COLEMAK` | Alternative base layout |
| `MIRYOKU_NAV` | Various | Navigation layout variant |
| `MIRYOKU_LAYERS` | Various | Layer configuration |

Example:
```bash
qmk compile -kb crkbd -km antoine -e MIRYOKU_CLIPBOARD=MAC -e MIRYOKU_ALPHAS=COLEMAK
```

## Custom Tap Timing

Per-key tapping term configuration in `antoine.c`:
- **GUI keys (A, O)**: 300ms - Longer to prevent accidental GUI triggers
- **FUN layer (ESC)**: 150ms - Faster for quick layer access
- **Default**: `TAPPING_TERM` (150ms) - Standard for all other keys

## Credits

- Original layout inspiration from [Miryoku](https://github.com/manna-harbour/miryoku) by Manna Harbour
- OLED spaceship animation: Custom implementation
- Modernization: January 2025 update for QMK 0.27.0+
- Built with ❤️ for split ergo keyboards

## License

GPL-2.0-or-later (consistent with QMK Firmware)

---

**Need help?** Check the [QMK Documentation](https://docs.qmk.fm/) or open an issue!
