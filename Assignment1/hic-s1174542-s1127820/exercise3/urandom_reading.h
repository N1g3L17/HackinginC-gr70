#ifndef URANDOM_READING_H
#define URANDOM_READING_H

#include <stdio.h>
#include <stdint.h>

FILE* open_urandom();
int read_byte(FILE *fp);
uint16_t read_uint16(FILE *fp);

#endif