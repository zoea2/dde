#!/bin/sh
rm output17.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output17.txt
	./bin/main17 < input.txt >> output17.txt
done
