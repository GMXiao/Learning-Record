#!/bin/bash
for ((i=101;i<201;i++))
do
  sync
  echo 3 > /proc/sys/vm/drop_caches
  ./gmtool admin create "Google Pixel 3 - 9.0 - API 28 - 1080x2160" $i --density 120dpi --width 240 --height 540 --nbcpu 1 --ram 1024 --navbar on --virtualkeyboard off --network-mode nat

done
