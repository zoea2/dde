#!/bin/sh
rm output10.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output10.txt
	./bin/main10 < input.txt >> output10.txt
done
