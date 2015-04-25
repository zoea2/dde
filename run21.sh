#!/bin/sh
rm output21.txt evolution21.txt
for i in `seq 13`
do
	echo $i > input.txt
	echo "function $i:" >> output21.txt
	./bin/main21 < input.txt >> output21.txt 2>>evolution21.txt

done
