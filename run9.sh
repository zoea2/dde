#!/bin/sh
rm output9.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output9.txt
	./bin/main9 < input.txt >> output9.txt
done
