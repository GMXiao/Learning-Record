#/bin/bash
for ((i=1;i<51;i++))
do
  sync
  echo 3 > /proc/sys/vm/drop_caches
  ./gmtool admin start $i

done
