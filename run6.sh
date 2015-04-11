#!/bin/sh
rm output6.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output6.txt
	./bin/main6 < input.txt >> output6.txt
done
