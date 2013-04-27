#!/bin/bash

GIMP=/Applications/GIMP.app/Contents/MacOS/GIMP

for d in 0 1 2 3 4 5 6 7 8 9; do mkdir -p train/$d; done

$GIMP -b - < generatedigits.scm

