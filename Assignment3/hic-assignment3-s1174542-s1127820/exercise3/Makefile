target: exercise3 run

unknown: unknown_function.c
	gcc -c -o unknown_function.o unknown_function.c

exercise3: exercise3.c unknown_function.o
	gcc -fno-stack-protector -o exercise3 exercise3.c unknown_function.o

.PHONY: clean run

run: exercise3
	./exercise3

clean:
	rm -f exercise3 unknown_function.o


	