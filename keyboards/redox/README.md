Important Sources

https://github.com/rafaelromao/keyboards
https://getreuer.info/posts/keyboards/non-english/index.html#us-international-layout

❯ qmk compile -kb redox/rev1/base -km triplem

twice - once for each side
start and repeat for each half:
unplug connection cord between the two halfs
❯ qmk flash -kb redox/rev1/base -km triplem  
, press Reset-Button twice shortly after each other
flashing will start
after finished flashing on both sided, unplug usb again, reconnect the two halfs
after replugging, everything should work as expected.

## Keymap

The keymap is generated using https://keymap-drawer.streamlit.app/ with the file redox-keymap.yaml.

<img src="https://raw.githubusercontent.com/triplem/qmk_userspace/refs/heads/main/keyboards/redox/redox-keymap.svg">
