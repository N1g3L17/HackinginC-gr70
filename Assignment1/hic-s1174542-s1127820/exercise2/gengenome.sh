#!/bin/bash

letters=()


while [ ${#letters[@]} -lt 100 ]
do
    number=$(($RANDOM%4))
    case $number in
        0) letters+=("A") ;;
        1) letters+=("C") ;;
        2) letters+=("G") ;;
        3) letters+=("T") ;;
    esac
done
echo ${letters[@]} | tr -d ' ' >> test.txt