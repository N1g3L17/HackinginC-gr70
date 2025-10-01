// vim: shiftwidth=4 tabstop=4 softtabstop=4 noexpandtab
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// colour code magic
#define RED "\033[0;31m"
#define REDINV "\033[0;31;7m"
#define GREEN  "\033[0;32m"
#define NC  "\033[0m"

int check_passphrase(char* passphrase) {
	char buffer[100];
	strcpy(buffer, passphrase);
	if(strcmp(passphrase, "the magic words are squeamish ossifrage") == 0) {
		return 1;
	}
	return 0;
}

void launch_shell() {
	printf(GREEN "Launching shell." NC "\n");
	/* Ensure stack alignment to 16 bytes when system() is called.                *
	 * Any problems this would cause should only occur *after* the shell returns. */
	asm volatile ("shr $4, %rsp\n\t"
				  "shl $4, %rsp");
	system("/bin/bash");
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <passphrase>\n", argv[0]);
		exit(0);
	}

	printf("* [DEBUG] Your input: %s\n", argv[1]);
	printf("* [DEBUG] The function launch_shell is at %p\n", launch_shell);
	if (((intptr_t) launch_shell - 0x010101010101) &
		~((intptr_t) launch_shell) & 0x808080808080) {
		printf(REDINV"* [WARNING] Address issue preventing exercise completion.\n"
			         "*           Please ask for help from a student assistant."NC"\n");
	}

	if (check_passphrase(argv[1])) {
		launch_shell();
		exit(0);
	} else {
		fprintf(stderr,
				RED "Wrong password. This incident will be reported. "
				"https://xkcd.com/838/" NC "\n");
	}
	return 1;
}
