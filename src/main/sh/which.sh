#!/bin/sh
[ -z $1 ] && return 1
IFS=':' p=$PATH
for e in $p; do
	d=$(find $e -name $1)
done
