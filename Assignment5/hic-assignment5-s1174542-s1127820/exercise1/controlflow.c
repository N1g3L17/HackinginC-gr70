// vim: shiftwidth=4 tabstop=4 softtabstop=4 noexpandtab
#include <stdio.h>

void function_b(void) {
	char buffer[4];

	// ... insert code here
	
	fprintf(stdout, "Executing function_b\n");
}

void function_a(void) {
	int beacon = 0xa0b1c2d3;
	fprintf(stdout, "Executing function_a\n");
	function_b();
	fprintf(stdout, "Executed function_b\n");
}

int main(void) {
	function_a();
	fprintf(stdout, "Finished!\n");
	return 0;
}

