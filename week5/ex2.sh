#!/bin/sh

for i in {0..10000}
do
	if `ln nums.txt nums.txt.lock`;  then
		num=`tail -n 1 nums.txt`
		((num++))
		echo "$num" >> nums.txt
		rm nums.txt.lock
	fi
done