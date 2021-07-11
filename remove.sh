#!/bin/bash

dotsurl=$1
dotsdir=$2
dotsremove=$3

git clone $dotsurl && cd $dotsdir && chmod +x $dotsremove && ./$dotsremove && cd .. && rm -rf $dotsdir
