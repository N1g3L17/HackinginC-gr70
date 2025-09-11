#include "urandom_reading.h"

FILE* open_urandom() {
    return fopen("/dev/urandom", "rb");
}

int read_byte(FILE *fp) {
    if (!fp) {
        return -1;
    }
    return fgetc(fp);
}

uint16_t read_uint16(FILE *fp) {
    if (!fp) {
        return -1;
    }
    uint16_t byte1 = fgetc(fp);
    uint16_t byte2 = fgetc(fp);
    if (byte1 == EOF || byte2 == EOF) {
        return -1;
    }
    return byte1 | (byte2 << 8);
}
    
