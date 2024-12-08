Important Sources

https://github.com/rafaelromao/keyboards
https://getreuer.info/posts/keyboards/non-english/index.html#us-international-layout

❯ qmk compile -kb redox -km triplem

twice - once for each side
start and repeat for each half:
unplug connection cord between the two halfs
❯ qmk flash -kb redox -km triplem  
, press Reset-Button twice shortly after each other
flashing will start
after finished flashing on both sided, unplug usb again, reconnect the two halfs
after replugging, everything should work as expected.

