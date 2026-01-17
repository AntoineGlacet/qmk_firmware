# antoine

Extended Miryoku layout with gaming optimization, custom OLED animation, and cross-platform support.

## Features

- **11 Custom Layers**: QWERTY, COLEMAK, Gaming variants, NAV, MOUSE, MEDIA, NUM, SYM, FUN, BUTTON
- **Caps Word**: Intelligent capitalization via double-shift trigger
- **Custom OLED Animation**: WPM-responsive spaceship animation
- **Cross-platform Clipboard**: Windows/Mac/Function key variants
- **Custom Tap Timing**: Per-key tapping term optimization
- **Gaming Optimization**: Dedicated gaming layers with repositioned modifiers

## Installation

1. Copy `users/antoine/` to your QMK `users/` directory
2. Add to your keyboard's keymap:
```c
#include "antoine.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_antoine(
        // Your keymap here
    )
};
```

3. Build with options:
```bash
qmk compile -kb [keyboard] -km antoine -e MIRYOKU_CLIPBOARD=WIN
```

## Layers

| Layer | Purpose |
|-------|---------|
| QWERTY | Base layer with home row mods |
| COLEMAK | Alternative base layout |
| GAMING_QWERTY | Gaming-optimized QWERTY (mods on bottom row) |
| GAMING_COLEMAK | Gaming-optimized COLEMAK |
| NAV | Navigation arrows, home/end, page controls |
| MOUSE | Mouse movement and clicks |
| MEDIA | Volume, playback, RGB controls |
| NUM | Numpad layer |
| SYM | Symbol layer |
| FUN | Function keys |
| BUTTON | Application shortcuts (PowerPoint) |
| NUM_G | Gaming numpad variant |
| SYM_G | Gaming symbol variant |
| FUN_G | Gaming function variant |

## Build Options

- `MIRYOKU_CLIPBOARD=WIN`: Windows clipboard shortcuts
- `MIRYOKU_CLIPBOARD=MAC`: Mac clipboard shortcuts  
- `MIRYOKU_CLIPBOARD=FUN`: Function key shortcuts (default)
- `MIRYOKU_ALPHAS=COLEMAK`: Use Colemak base instead of QWERTY

## Supported Keyboards

- Crkbd (Corne)
- Fortitude60

To add support for new keyboards:
1. Create keymap directory with `keymap.c` containing userspace include
2. Add keyboard-specific `config.h` and `rules.mk`
3. Ensure keyboard supports `LAYOUT_miryoku` or define custom mapping

## File Structure

```
users/antoine/
├── antoine.c  # Main implementation
├── antoine.h  # Layer definitions
├── config.h                         # Build configuration
├── rules.mk                         # Build rules
└── features/                        # Custom features
    ├── caps_word.c                   # Caps word implementation
    └── caps_word.h                   # Caps word header
```

## Key Functions

Each key supports maximum 4-5 functions:
- Base keycode
- Layer-tap (LT)
- Mod-tap (MT/LGUI_T/LCTL_T etc.)
- One-shot (OSM)
- Combo trigger

## Special Features

### Caps Word
Activate by pressing both shift keys simultaneously. Automatically capitalizes letters while maintaining shift state for numbers/symbols.

### OLED Animation
Custom spaceship animation that responds to typing speed. Animation velocity increases with WPM.

### Custom Tap Timing
- GUI-mod keys: 300ms
- FUN layer access: 150ms
- Default: `TAPPING_TERM`

## Dependencies

- OLED_ENABLE for animations
- Caps word feature
- QMK keys per scan: 4