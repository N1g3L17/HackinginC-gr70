# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

void heap_attack(void) {
    char* heapacc = malloc(11);
    strcpy(heapacc, "heapaccess");
    
    bool char_found = false;
    int heap_pos = 0;

    bool* char_found_ptr = &char_found;
    char* ptr_hold = heapacc;
    int* heap_pos_ptr = &heap_pos;

    *heap_pos_ptr = 1;

    //First loop
    while (!char_found)
    {
        ptr_hold = heapacc - *heap_pos_ptr;
        if (*ptr_hold == 's') {
            printf("%s %d\n", "HIT! Positions moved in heap: ", *heap_pos_ptr);
            printf("%s %p\n", "Pointer at address", ptr_hold);
            printf("%s\n", "Setting the zero to spaces...");
            while (!char_found) {
                ptr_hold = heapacc - *heap_pos_ptr - 1;
                if (*ptr_hold == 's') {
                    printf("%s %p\n", "NEXT STRING FOUND AT:", ptr_hold);
                    *char_found_ptr = true; 
                    break;
                } else if (*ptr_hold == 0)
                {
                    *ptr_hold = 32;
                }
                
                *heap_pos_ptr += 1;
            }  
        } else {
            *heap_pos_ptr += 1;
        } 
    }
}

int main(void) {
    char* s1 = malloc(9);
    if (s1 == NULL) { return 1; }
    char* s2 = malloc(9);
    if (s2 == NULL) { return 1; }

    strcpy(s1, "s1174542");
    strcpy(s2, "s1127820");

    heap_attack();

    printf("student 1: %s\n", s1);
    printf("student 2: %s\n", s2);

    return 0;
}