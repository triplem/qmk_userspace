# Sofle Choc

The Sofle Choc is 6×4+5 keys column-staggered split keyboard. Based on Lily58, Corne and Helix keyboards. 

QMK details can be found in: https://github.com/qmk/qmk_firmware/tree/master/keyboards/sofle_choc

I bought mine at keebart (https://keIebart.com/).

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

My personal layout for this keyboard is documented on http://www.keyboard-layout-editor.com/#/gists/14e2a9d6e6b7c1152ef19ea2cc0a8783.
