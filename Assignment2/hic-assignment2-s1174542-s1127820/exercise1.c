// vim: shiftwidth=4 tabstop=4 softtabstop=4 noexpandtab
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int32_t a = 1;
	int16_t b = 2;
	unsigned char c = 3;
	int8_t d = 4;
	unsigned long long e = 5;
	short f[3] = {6, 6, 6};
	long g = 7;
	unsigned long int h = 8;
	uint8_t i = 9;
	char j[] = "Ten. Or A?";

	fprintf(stderr, "address\t\tvariable\tvalue\tsizeof\tnext_addr\n");

	printf("%p\t\ta\t%" PRId32 "\t%zu\t%p\n", (void*) &a, a, sizeof(a), (void*) (&a+1));
    printf("%p\t\tb\t%" PRId16 "\t%zu\t%p\n", (void*) &b, b, sizeof(b), (void*) (&b + 1));
    printf("%p\t\tc\t%u\t%zu\t%p\n", (void*) &c, c, sizeof(c), (void*) (&c + 1));
    printf("%p\t\td\t%" PRId8 "\t%zu\t%p\n", (void*) &d, d, sizeof(d), (void*) (&d + 1));
    printf("%p\t\te\t%llu\t%zu\t%p\n", (void*) &e, e, sizeof(e), (void*) (&e + 1));
    printf("%p\t\tf\t%hd %hd %hd\t%zu\t%p\n", (void*) &f, f[0], f[1], f[2], sizeof(f), (void*) (&f + 1));
    printf("%p\t\tg\t%ld\t%zu\t%p\n", (void*) &g, g, sizeof(g), (void*) (&g + 1));
    printf("%p\t\th\t%lu\t%zu\t%p\n", (void*) &h, h, sizeof(h), (void*) (&h + 1));
    printf("%p\t\ti\t%" PRIu8 "\t%zu\t%p\n", (void*) &i, i, sizeof(i), (void*) (&i + 1));
    printf("%p\t\tj\t%s\t%zu\t%p\n", (void*) &j, j, sizeof(j), (void*) (&j + 1));

	return 0;
}