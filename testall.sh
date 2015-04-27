#!/bin/sh

for i in tests/*.pas; do
	echo "testing $i"
	./parser <  $i
done
