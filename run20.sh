#!/bin/sh
rm output20.txt evolution20.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output20.txt
	./bin/main20 < input.txt >> output20.txt 2>>evolution20.txt

done
