#!/bin/bash
for ((i=2;i<51;i++))
do
  sync
  echo 3 > /proc/sys/vm/drop_caches
  VBoxManage  modifyvm  $i  --nic2 natnetwork
#  VBoxManage  modifyvm  $i  --nic2 nat
done
