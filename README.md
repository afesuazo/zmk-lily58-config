# zmk-lily58-config

Firmware for two Lily58-layout keyboards that share one layout. GitHub Actions builds both on every push.

| Keyboard | Firmware | Source | Actions workflow → artifact |
| --- | --- | --- | --- |
| Boardsource Wireless Lily58 SMT ("BLE Lulu") | ZMK | `config/blelulu.keymap`, `config/blelulu.conf` | *Build ZMK firmware* → `blelulu_left.uf2`, `blelulu_right.uf2` |
| Boardsource Lulu (wired, RP2040) | QMK | `keyboards/boardsource/lulu/keymaps/andy/` | *Build QMK firmware (Lulu)* → `boardsource_lulu_rp2040_andy.uf2` |

## Changing the layout

The layout lives in two files, one per firmware. Edit both together:

- `keyboards/boardsource/lulu/keymaps/andy/keymap.c` (QMK)
- `config/blelulu.keymap` (ZMK)

Differences the hardware forces (all on the settings layer):

- **Win/Mac:** The Lulu swaps Ctrl/GUI automatically on Windows/Linux. ZMK can't detect the OS, so the wireless board uses a `windows` layer instead. Settings + left inner key toggles it on both boards. The wireless board forgets the toggle after a restart or deep sleep.
- **Bluetooth (BT1, BT2, BT clear) and Studio unlock:** wireless board only.
- **RGB controls, OLED and encoders:** Lulu only.

## Flashing

**Wireless Lily58 (each half separately):** plug the half in over USB and double-tap its reset button (or use Settings + Boot). Drag `blelulu_left.uf2` or `blelulu_right.uf2` onto the drive that appears. The board also ships with ZMK Studio. Keymap changes saved in Studio take priority over this repo's keymap until you restore stock settings in Studio.

**Lulu:** press Boot (outer left thumb key, or Settings + Boot), then drag `boardsource_lulu_rp2040_andy.uf2` onto the `RPI-RP2` drive.

If the wireless halves stop pairing with each other, uncomment the `settings_reset` entries in `build.yaml`, flash those, then reflash the normal firmware.

## nice!view on the wireless Lily58

1. Uncomment `shield: nice_view` on both entries in `build.yaml`.
2. Uncomment `CONFIG_ZMK_DISPLAY=y` in `config/blelulu.conf`.

The display mounts rotated 180 degrees. That setting is already in the board files and needs the ZMK fork below.

## Versions

- **ZMK:** `config/west.yml` pins a commit on [invrtd/zmk](https://github.com/invrtd/zmk) `nice!view-180`. That's ZMK `main` (Zephyr 4.1) plus a nice!view rotation option, and Boardsource's official config uses the same fork. `.github/workflows/build.yml` must stay on `@main` to match.
- **QMK:** built as an [external userspace](https://docs.qmk.fm/newbs_external_userspace) against `qmk/qmk_firmware` `master`. Build targets are listed in `qmk.json`.
- `boards/boardsource/blelulu/` is copied unchanged from [boardsource/wireless-lily58_zmk_config](https://github.com/boardsource/wireless-lily58_zmk_config) at `aa5a771` (MIT).
