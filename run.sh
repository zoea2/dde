#!/bin/sh
rm output.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output.txt
	./bin/main < input.txt >> output.txt
done
