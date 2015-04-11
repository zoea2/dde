#!/bin/sh
rm output3.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output3.txt
	./bin/main3 < input.txt >> output3.txt
done
