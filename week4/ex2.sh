#!/bin/sh

./ex2 &>/dev/null &

for var in 0 1 2 3 4 5 6 7 8 9 10 11 12 
do
    echo "=============="
    pstree
    sleep 2
done