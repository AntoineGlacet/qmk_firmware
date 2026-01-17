# P60v2 (5×12 Ortho) with Vial - Implementation Plan

## Project Goal
Port the existing fortitude60 "antoine" keymap to an AliExpress ortho 5×12 keyboard with STM32F072VBT6 MCU and add Vial support for live configuration.

## Current Status
- **Existing Setup**: Fortitude60 split keyboard with custom "antoine" keymap
- **Target Hardware**: AliExpress ortho 5×12 keyboard, STM32F072VBT6 MCU, all 1u keys
- **Source**: https://ja.aliexpress.com/item/1005009476193701.html
- **Keymap Layers**: 11 layers (QWERTY, NAV, MOUSE, MEDIA, NUM, SYM, FUN, BUTTON, NUM_G, SYM_G, FUN_G, GAMING_QWERTY, GAMING_COLEMAK, COLEMAK)
- **Features**: Home row mods, layer-taps, custom macros

---

## CRITICAL: Information Needed Before Implementation

### 1. GPIO Pin Configuration ⚠️
**REQUIRED**: Need to identify the matrix pins for the p60v2 keyboard
- Row pins (5 pins)
- Column pins (12 pins)

**How to obtain:**
- Check seller documentation on AliExpress
- Look for existing firmware files (`.hex`, `.bin`, or source code)
- Check if there's a GitHub repository for this board
- Physical inspection/multimeter testing as last resort
- Common STM32F072 pins to check: A0-A15, B0-B15, C13-C15, F0-F1

### 2. Keyboard Naming Decision
Choose a name for the keyboard directory:
- Option A: `keyboards/handwired/p60v2_antoine`
- Option B: `keyboards/aliexpress/p60v2`
- Option C: Custom preference?

### 3. Layout Adaptation Strategy
The fortitude60 keymap has gaps (U_NP) in row 4 (thumb cluster area) - only 10 keys instead of 12.
For the full 5×12 board, decide:
- **Option A**: Keep gaps using KC_NO (preserve muscle memory)
- **Option B**: Fill with useful keys (e.g., extra layer switches, media controls)

### 4. USB Vendor/Product IDs
- Use QMK test IDs (default)
- Or provide custom IDs if you have preferences

---

## Implementation Phases

### Phase 1: Create Keyboard Definition
**Directory**: `keyboards/[chosen_name]/`

**Files to create:**
1. `keyboard.json` - Main keyboard configuration
   - Processor: `STM32F072`
   - Bootloader: `stm32-dfu`
   - Matrix pins: [TO BE DETERMINED]
   - USB VID/PID
   - 5×12 ortho layout (60 keys total)
   - Features: bootmagic, mousekey, extrakey, nkro
   - Board: `STM32_F072_xB` (for STM32F072VBT6)

2. `readme.md` - Documentation
   - Hardware description
   - Build instructions
   - Flash instructions

3. `rules.mk` (if needed for special features)

**Layout Structure:**
```
Row 0: 12 keys (KC_ESC, KC_1-KC_0, KC_BSPC)
Row 1: 12 keys (KC_TAB, Q-P, ...)
Row 2: 12 keys (KC_LSFT, A-QUOT, ...)
Row 3: 12 keys (KC_LCTL, Z-SLSH, ...)
Row 4: 12 keys (thumb cluster + mods)
```

### Phase 2: Port Keymap
**Directory**: `keyboards/[chosen_name]/keymaps/antoine/`

**Files to create:**
1. `keymap.c` - Main keymap file
   - Adapt `LAYOUT_antoine` from split to single board format
   - Port all 11 layers from `keyboards/fortitude60/keymaps/antoine/keymap.c`
   - Preserve custom keycodes (U_NP, U_NA, U_UND, U_CUT, U_CPY, U_PST, U_RDO)
   - Maintain home row mods configuration
   - Keep all layer-tap configurations

2. `config.h` - Keymap configuration
   - Copy relevant settings from fortitude60 antoine config
   - Add Vial-specific settings:
     - `VIAL_KEYBOARD_UID` (8 random bytes)
     - `VIAL_UNLOCK_COMBO_ROWS`/`VIAL_UNLOCK_COMBO_COLS`
     - `DYNAMIC_KEYMAP_LAYER_COUNT` (11 layers minimum)
   - Tap-hold settings for home row mods

3. `rules.mk` - Feature flags
   ```makefile
   VIA_ENABLE = yes
   VIAL_ENABLE = yes
   LTO_ENABLE = yes
   ```

**Keymap Adaptation Notes:**
- Remove split keyboard-specific code (no serial, OLED, etc.)
- Update U_NP (no position) mappings for single board
- Adjust row 4 based on decision from Phase 0

### Phase 3: Add Vial Support
**Files to create:**

1. `keyboards/[chosen_name]/keymaps/antoine/vial.json`
   - Define keyboard layout for Vial UI
   - 5 rows × 12 columns grid
   - Physical key positions (x, y coordinates)
   - All 11 layers configured
   - Metadata: name, vendor, lighting options

**Vial.json Structure:**
```json
{
  "name": "P60v2 Antoine",
  "vendorId": "0x????",
  "productId": "0x????",
  "matrix": {"rows": 5, "cols": 12},
  "layouts": {
    "keymap": [
      // Row definitions with x,y coordinates
    ]
  }
}
```

2. Update `config.h` with Vial settings
   - Enable secure unlock combo
   - Set layer count to 11+
   - Configure EEPROM for dynamic keymaps

### Phase 4: Build System Integration

**MCU-specific requirements for STM32F072:**
- Ensure `halconf.h` and `mcuconf.h` if needed (usually auto-generated)
- Verify bootloader configuration for `stm32-dfu`
- Check if any STM32-specific drivers needed

### Phase 5: Testing & Validation

**Build Test:**
```bash
qmk compile -kb [keyboard_name] -km antoine
```

**Flash Test:**
```bash
qmk flash -kb [keyboard_name] -km antoine
```

**Validation Checklist:**
- [ ] Firmware compiles without errors
- [ ] All 60 keys register correctly
- [ ] All 11 layers function properly
- [ ] Home row mods work (tap vs hold)
- [ ] Layer switching works
- [ ] Vial connects and recognizes keyboard
- [ ] Dynamic keymap changes work in Vial
- [ ] All custom macros function (cut, copy, paste, etc.)
- [ ] Bootmagic works for entering bootloader
- [ ] RGB/Backlight (if applicable)

---

## Technical Reference

### Existing Keymap Structure
**Source**: `keyboards/fortitude60/keymaps/antoine/`
- `keymap.c`: 106 lines, 11 layers
- `config.h`: Custom layout macro
- Uses userspace: `users/antoine/antoine.{c,h}` for custom keycodes

### Custom Keycodes (from antoine.h)
- `U_NP`: No position (for split layout gaps)
- `U_NA`: Not available
- `U_NU`: Not used
- `U_UND`, `U_CUT`, `U_CPY`, `U_PST`, `U_RDO`: Editing shortcuts

### Home Row Mods Pattern
```c
LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F)  // Left hand
RSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_QUOT)  // Right hand
```

### Reference Keyboards
- **5×12 Layout**: `keyboards/ortho5by12/`
- **STM32F072**: `keyboards/keebio/bdn9/rev2/`
- **Handwired ortho**: `keyboards/handwired/ortho5x13/`

---

## Resources

### QMK Documentation
- [Hand wiring guide](https://docs.qmk.fm/hand_wire)
- [STM32 setup](https://docs.qmk.fm/platformdev_stm32)
- [Configurator](https://config.qmk.fm/)

### Vial Documentation
- [Vial porting guide](https://get.vial.today/docs/porting-to-via.html)
- [vial.json reference](https://get.vial.today/docs/vial-json.html)

### Tools
- QMK Configurator: https://config.qmk.fm/
- Vial: https://get.vial.today/
- QMK Toolbox: For flashing firmware
- STM32 DFU: Enter bootloader (usually BOOT0 button or RESET combo)

---

## Next Steps

1. **PRIORITY**: Obtain GPIO pin configuration for the p60v2
2. Decide on keyboard name and directory structure
3. Decide on layout adaptation strategy (gaps or filled)
4. Create keyboard definition files
5. Port keymap
6. Add Vial configuration
7. Build and test
8. Document any hardware-specific quirks

---

## Notes
- The STM32F072VBT6 has plenty of GPIO pins for a 5×12 matrix (17 pins needed)
- Vial allows real-time keymap editing without reflashing
- Consider keeping a backup of the original firmware if provided
- Test matrix pins one by one if documentation is unavailable
- The fortitude60 keymap is well-organized and should port cleanly

---

**Last Updated**: 2026-01-18
**Status**: Awaiting pin configuration information
