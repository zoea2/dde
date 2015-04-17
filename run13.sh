#!/bin/sh
rm output13.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output13.txt
	./bin/main13 < input.txt >> output13.txt
done
