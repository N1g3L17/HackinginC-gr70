#!/bin/bash

rm gengenome.txt

for i in {1..500}
do
    line=""
    for j in {1..100}
    do
        case $((RANDOM % 4)) in
            0) letter="A" ;;
            1) letter="C" ;;
            2) letter="G" ;;
            3) letter="T" ;;
        esac
        line+="$letter"
    done
    echo "$line" >> gengenome.txt
done