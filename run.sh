#!/bin/sh
rm output0.txt evolution0.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output0.txt
	./bin/main < input.txt >> output0.txt 2>>evolution0.txt
done
