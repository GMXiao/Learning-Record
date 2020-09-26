#!/bin/bash
for ((i=101;i<207;i++))
do
  sync
  echo 3 > /proc/sys/vm/drop_caches
  ./gmtool admin delete  $i

done
