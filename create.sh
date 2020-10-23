#!/bin/bash
#In .bashrs file there must be alias:
#alias create='cd ~/WORK/cpp/; cd $(ls -td -- */ | head -n 1 | cut -d'/' -f1); ./create.sh; cd ..; cd $(ls -td -- */ | head -n 1 | cut -d'/' -f1)'
#alias go='cd ~/WORK/cpp/; cd $(ls -td -- */ | head -n 1 | cut -d'/' -f1);'
dir=`pwd`
echo $dir
cd ..;
dire=`ls -td -- */ | head -n 1 | cut -d'/' -f1`
num=${dire: -2}
newnum=$(($num + 1))
euler="euler"
cp -rf $dire $euler$newnum 
cd $dir
chmod 544 ./src/*
cd ..
cd $euler$newnum
vi Makefile
make clean
