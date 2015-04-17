#!/bin/sh
rm output14.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output14.txt
	./bin/main14 < input.txt >> output14.txt
done
