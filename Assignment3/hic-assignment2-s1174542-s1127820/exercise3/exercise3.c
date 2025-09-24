#include <stdio.h>
extern void unknown_function();

int main(void){
    char marker1;
    char *before = (char *)&marker1;
    unknown_function();
    char marker2;
    char *after = (char *)&marker2;
    long stack_usage = before - after;
    printf("The stack usage of unknown_function is %ld bytes.\n", stack_usage);
    return 0;
}