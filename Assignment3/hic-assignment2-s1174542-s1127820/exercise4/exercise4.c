#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int main(void) {
    size_t min_val = 0;
    size_t max_val = SIZE_MAX;
    // We are using binary search:
    while (min_val <= max_val) {
        size_t mid = (min_val + max_val) / 2;
        // void *p = calloc(1, mid);
        void *p = malloc(mid);
        if (p) {
            free(p);
            min_val = mid + 1;
        } else {
            max_val = mid - 1;
        }
    }
    printf("One malloc can allocate at most %ld bytes.\n", max_val);
    return 0;
}
