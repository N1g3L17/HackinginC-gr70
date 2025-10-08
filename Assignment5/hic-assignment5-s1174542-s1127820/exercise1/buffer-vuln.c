// vim: shiftwidth=4 tabstop=4 softtabstop=4 noexpandtab
#include <stdio.h>
#include <stdlib.h>

char *gets(char*);

void func(void) {
	char* ret;
	char buf[275];
	printf("Please enter your name: ");
	ret = gets(buf); // read the input
	printf("Your input was: ");
	printf(ret);
	printf("\n");
}

void indirect_func(void) {
	// This helps to demonstrate the usefulness of frame pointers.
	func();
}

int main(void) {
	indirect_func();
}
