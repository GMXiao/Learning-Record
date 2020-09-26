#!/bin/bash

num=0
ipwithport=$(adb devices|grep 5555|grep -v grep|awk '{print $1}')
for i in $ipwithport
  do

    echo "uninstall shareit app of $i"
  
    adb -s $i uninstall com.sjtuopennetwork.shareit
   # if [ -n $fileUseHash ];then
   
    #    num=$[$num+1]
      #  adb -s $i pull /mnt/sdcard/Android/data/com.sjtuopennetwork.shareit/files/repo/$fileUseHash/logs/textile.log /shareitlog/log_$i
   # fi
   # sleep 3
   # echo "bangding the $num cpu with player ${i}"
   # taskset -cp $num $i
   # num=`expr $num + 1`;
    #echo "${i}"
  done
echo "Delete  shareit app on all devices"
