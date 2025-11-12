# Sofle Choc

The Sofle Choc is 6×4+5 keys column-staggered split keyboard. Based on Lily58, Corne and Helix keyboards. 

QMK details can be found in: https://github.com/qmk/qmk_firmware/tree/master/keyboards/sofle_choc

I bought mine at keebart (https://keebart.com/).

For the sofle_choc the rgb_matrix is enabled: https://docs.qmk.fm/#/feature_rgb_matrix.

Compile the qmk-firmware:

``` 
❯ qmk compile -kb sofle_choc -km triplem
```

The firmware needs to get flashed twice, once for each side. Unplug the Keyboard and start the Flash-Process:

```
❯ qmk flash -kb sofle_choc -km triplem
```

While replugging the corresponding side, press ESC (for the left side) or BKSP (for the right side). The Flashing should start.

## Keymap

The keymap is generated using https://keymap-drawer.streamlit.app/ with the file sofle-choc_keyboard-layout.yaml.

![Alt text](Sofle Choc Keymap)
<img src="https://raw.github.com/triplem/qmk_userspace/keyboards/sofle_choc/keymaps/sofle-choc-keymap.svg?sanitize=true">

