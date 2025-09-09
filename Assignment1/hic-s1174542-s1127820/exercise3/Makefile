target: compileex3

compileex3:
	gcc urandom_loop_bytes.c -o urandom_loop_bytes

run: 
	./urandom_loop_bytes >> urandom-byte-output.txt

clean:
	rm urandom_loop_bytes urandom-byte-output.txt
