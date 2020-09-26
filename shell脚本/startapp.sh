#!/bin/bash
ipwithport=$(adb devices|grep 5555|grep -v grep|awk '{print $1}')
for i in $ipwithport
  do
    adb -s $i shell am start com.sjtuopennetwork.shareit/.login.MainActivity


  done
