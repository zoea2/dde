#!/bin/sh
rm output11.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output11.txt
	./bin/main11 < input.txt >> output11.txt
done
