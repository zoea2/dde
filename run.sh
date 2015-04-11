#!/bin/sh
rm output0.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output0.txt
	./bin/main < input.txt >> output0.txt
done
