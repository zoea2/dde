#!/bin/sh
rm output16.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output16.txt
	./bin/main16 < input.txt >> output16.txt
done
