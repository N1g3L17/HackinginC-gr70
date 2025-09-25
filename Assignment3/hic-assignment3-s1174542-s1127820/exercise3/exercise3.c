#include <stdio.h>
#include <string.h>
extern void unknown_function();

int main(void){
    // char marker1;
    // char *before = (char *)&marker1;
    char buffer[4194304];
    for (int i = 0; i < 4194304; i++) {
        buffer[i] = 0;
    }
    unknown_function();
    int it = 0;
    for (int i = 0; i < 4194304; i++) {
        if (buffer[i] != 0) {
            it++;
        }
    }
    printf("The unknown function used %d bytes of the heap.\n", it);
    // char marker2;
    // char *after = (char *)&marker2;
    // long stack_usage = before - after;
    // printf("The stack usage of unknown_function is %ld bytes.\n", stack_usage);
    return 0;
}

//We have tried multiple options (marker before and after, array before and after, checking how many items were altered in a buffer) 
//and spent a few hours to measure the stack usage, 
//but none of them worked like they should. All of them only gave us a stack usage of 0-8 bytes,
//even though we know that the stack usage should be higher.
//So we have to give up unfortunately. Looking forward to seeing the solutions. 