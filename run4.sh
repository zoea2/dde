#!/bin/sh
rm output4.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output4.txt
	./bin/main4 < input.txt >> output4.txt
done
