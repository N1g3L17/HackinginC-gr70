#include <stdio.h>

void unknown_function() {
    int buffer[100];
    int a = 64;
    int b = 602;
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        buffer[i] = (i * a + b % 169);
        if (i % 3 == 0) {
            sum += buffer[i];
        }
    }
    printf("69th buffer value: %d\n", buffer[69]);
    printf("The unknown function is finished with sum: %d\n", sum);
}