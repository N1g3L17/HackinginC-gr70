# include <inttypes.h>
# include <stdio.h>

int main(void) {

    int32_t x[4];
    x[0] = 23;
    x[1] = 42;
    x[2] = 5;
    x[3] = (1<<7); //00000001 becomes --> 10000000 (128)

    //int* a = (int*) &x+1;

    printf("%p\n", (void*) x); // prints 0x7ffc0ffeef20 //Is being casted to a void pointer, and returns the address of x[0].
    printf("%p\n", (void*) &x); // (a) //Prints the same as above, the address of x, the same as x[0]
    printf("%p\n", (void*) (x+1)); // (b) //Print the address of x+1. which is x[1].
    printf("%p\n", (void*) (&x+1)); // (c) //Print the address of x+1. which is x[1]. Works the same as above.
    //printf("%p\n", a); //Test if it works the same.
    printf("%" PRId32 "\n", *x+1); // (d) //Prints 23
    printf("%" PRId32 "\n", *x+x[2]); // (e) //What I think is going to happen is it deference x and adds x[2], so 23 + 5 = 28. 
    printf("%" PRId32 "\n", *x+*(x+3)); // (f) //What I think is going to happen is it will first add 3 to x, so it will reference to the address of x[3]. Next up is deference x+3, which is 128 and add deference x, which is 23. So this will be 23 + 128 = 151. 

    return 0;
}
