Important Sources

https://github.com/rafaelromao/keyboards
https://getreuer.info/posts/keyboards/non-english/index.html#us-international-layout

For the sofle_choc the rgb_matrix is enabled: https://docs.qmk.fm/#/feature_rgb_matrix

❯ qmk compile -kb sofle_choc -km triplem

twice - once for each side
start and unplug the keyboard (one half)
❯ qmk flash -kb sofle_choc -km triplem  
, press ESC or BKSP and replug
flashing will start
