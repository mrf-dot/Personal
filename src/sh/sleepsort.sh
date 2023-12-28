#!/bin/sh
f() {
	sleep $(echo "$1 / 100" | bc -l)
	echo "$1"
}
while [ -n "$1" ]
do
	f "$1" &
	shift
done
wait
