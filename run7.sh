#!/bin/sh
rm output7.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output7.txt
	./bin/main7 < input.txt >> output7.txt
done
