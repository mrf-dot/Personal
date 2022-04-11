#!/bin/sh
i=1
while [ $i -lt 101 ]
do
	if $(($i%3==0)) then
	(($(($i%3==0)) && echo -n fizz);$(($i%5==0)) && echo -n buzz) || echo $i
	i=$(($i+1))
done
