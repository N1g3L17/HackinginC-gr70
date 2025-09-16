#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int main(void) {
    bool t = true;
    bool f = false;

    printf("Size of bool: %zu bytes\n", sizeof(bool));
    printf("true in hex representation: 0x%02X\n", *((unsigned char*)&t));
    printf("false in hex representation: 0x%02X\n", *((unsigned char*)&f));

    unsigned char *p = (unsigned char*)&t;
    unsigned char ucs[] = {0x59, 0x00, 0x80, 0xFF}; 
    for (size_t i = 0; i < sizeof(ucs); i++) {
        *p = ucs[i];
        if (t) {
            printf("Assigned 0x%02x -> bool is interpreted as: true\n", *p);
        } else {
            printf("Assigned 0x%02x -> bool is interpreted as: false\n", *p);
        }
    }
    return 0;

    //every value other than 0x00 is interpreted as true
}