# include <stdio.h>

void print_bytes(char* address, size_t size) {

    for (size_t i = 0; i < size; i++)
    {
        printf("%p\t" "0x%02x\t\t" "%d\n", (void*)&address[i], (unsigned char)address[i], (int)address[i]);
    }   
}

int main(void) {
    short i = 0x1234;
    char x = -127;
    long sn1 = 1174542;
    char sn2[] = "S1127820";
    int y[2] = {0x11223344, 0x44332211};

    fprintf(stderr, "address\t\tcontent (hex)\tcontent (dec)\n");
    print_bytes((char*)&i, sizeof(i));
    print_bytes((char*)&x, sizeof(x));
    print_bytes((char*)&sn1, sizeof(sn1));
    print_bytes((char*)&sn2, sizeof(sn2));
    print_bytes((char*)&y, sizeof(y));

    return 0;
}