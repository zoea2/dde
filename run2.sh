#!/bin/sh
rm output2.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output2.txt
	./bin/main2 < input.txt >> output2.txt
done
