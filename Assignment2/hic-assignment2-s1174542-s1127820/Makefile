CFLAGS = "-O3" "-Wall"

targets: 
	make exercise1
	make exercise2
	make exercise3

exercise1:
	gcc exercise1.c -o exercise1 -Wall -Wextra -pedantic

exercise2:
	gcc exercise2.c -o exercise2 -Wall -Wextra -pedantic

exercise3:
	gcc exercise3.c $(CFLAGS) -o exercise3

clean:
	rm exercise1 exercise2 exercise3