#!/bin/sh
rm output1.txt evolution1.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output1.txt
	./bin/main1 < input.txt >> output1.txt 2>> evolution1.txt
done
