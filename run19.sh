#!/bin/sh
rm output19.txt evolution19.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output19.txt
	./bin/main19 < input.txt >> output19.txt 2>>evolution19.txt

done
