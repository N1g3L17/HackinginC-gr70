# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int main() {
    FILE* fp = fopen("/dev/urandom", "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    int ch;
    while (1) {
        ch = fgetc(fp);
        printf("%d %u %x\n", (signed char)ch, (unsigned char)ch, (unsigned char)ch);
        if ((unsigned char)ch == 42)
            break;
    }
    fclose(fp);
    return 0;
}