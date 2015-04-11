#!/bin/sh
rm output1.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output1.txt
	./bin/main1 < input.txt >> output1.txt
done
