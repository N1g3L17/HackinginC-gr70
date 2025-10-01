// vim: shiftwidth=4 tabstop=4 softtabstop=4 noexpandtab
#include <regex.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main(int argc, char *argv[]) {
	regex_t regex;
	int returncode = 0;
	if ((returncode =
				regcomp(&regex, "^0x[a-f0-9]{1,}$", REG_ICASE | REG_EXTENDED))) {
		char errorbuf[100];
		regerror(returncode, &regex, errorbuf, sizeof(errorbuf));
		fprintf(stderr, "Compiling regex failed: %s!\n", errorbuf);
		return 255;
	}

	char *addr_string = argv[1];
	if (argc < 2) {
		fprintf(stderr, "Usage: %s 0xADDRESS\n", argv[0]);
		fprintf(stderr,
				"Prints the address as the actual bytes in little-endian order\n");
		fprintf(stderr,
				"Don't be surprised when it appears there is no output, it "
				"might just be unreadable. Try piping the output to `xxd`.\n");
		returncode = 1;
		// skip to cleanup code
		goto end;
	}

	returncode = regexec(&regex, addr_string, 0, NULL, 0);
	if (returncode != 0) {
		char errorbuf[100];
		regerror(returncode, &regex, errorbuf, sizeof(errorbuf));
		fprintf(stderr, "Regex match failed: %s\n", errorbuf);
		// skip to cleanup code
		goto end;
	}

	uintptr_t address = strtoull(addr_string, NULL, 16);
	print_address_little_endian(address);

	// gotos are pretty much the only clean way to handle errors if you need
	// to do cleanup like free().
end:
	regfree(&regex);

	return returncode;
}
