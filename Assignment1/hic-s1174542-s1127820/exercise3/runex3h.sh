#!/bin/bash

for i in {1..10}; 
	do ./urandom_loop_uint16 | wc -l >> urandom-uint16-output.txt;
done
