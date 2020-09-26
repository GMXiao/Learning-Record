#!/bin/bash
for ((i=30;i<81;i++))
do
  sync
  echo 3 > /proc/sys/vm/drop_caches
  ./gmtool device -n $i install /opt/apks/app-debug.apk
done
