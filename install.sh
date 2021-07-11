#!/bin/bash

dotsurl=$1
dotsdir=$2
dotscommand=$3

git clone $dotsurl && cd $dotsdir && chmod +x $dotscommand && ./$dotscommand && cd .. && rm -rf $dotsdir
