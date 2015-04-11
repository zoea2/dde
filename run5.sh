#!/bin/sh
rm output5.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output5.txt
	./bin/main5 < input.txt >> output5.txt
done
