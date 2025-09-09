# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <inttypes.h>

int main() {
    FILE* fp = fopen("/dev/urandom", "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    uint16_t ch;
    while (1) {
        ch = fgetc(fp);
        printf("%04x\n", ch);
        if ((unsigned char)ch == 42)
            break;
    }
    fclose(fp);
    return 0;
}