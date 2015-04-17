#!/bin/sh
rm output12.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output12.txt
	./bin/main12 < input.txt >> output12.txt
done
