compileex3b:
	gcc urandom_loop_bytes.c -o urandom_loop_bytes

compileex3f:
	gcc urandom_loop_uint16.c -o urandom_loop_uint16

run: 
	./urandom_loop_bytes >> urandom-byte-output.txt

runex3h:
	for i in {1..10}; do ./urandom_loop_uint16 | wc -l >> urandom-uint16-output.txt; done

clean:
	rm urandom_loop_bytes urandom-byte-output.txt urandom_loop_uint16 urandom-uint16-output.txt
