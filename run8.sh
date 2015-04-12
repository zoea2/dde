#!/bin/sh
rm output8.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output8.txt
	./bin/main8 < input.txt >> output8.txt
done
