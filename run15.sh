#!/bin/sh
rm output15.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output15.txt
	./bin/main15 < input.txt >> output15.txt
done
