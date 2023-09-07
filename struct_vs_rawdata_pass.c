#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Define a packed struct with four fields
typedef struct __attribute__((__packed__)) struct1{
    uint32_t a; // 4 bytes
    uint8_t b;  // 1 byte
    uint16_t c;  // 2 bytes
    uint8_t d;  // 1 byte
}struct1_t;


// A function that assigns values to the fields of a struct1_t pointer
void foo(struct1_t *a)
{
    a->a=1;
    a->b=2;
    a->c=3;
    a->d=4;
}

// A function that copies 8 bytes from a temporary array to a uint8_t pointer
void foo2(uint8_t *a)
{
    uint8_t tmp[] = {0,1,2,3,4,5,6,7,8};
    memcpy(a, tmp, 8); // Use memcpy to copy 8 bytes from tmp to a
}

int main()
{
    // Definition of the struct and the pass as a parameter directy, we can easily access the set values.
    struct1_t a; // Declare a struct1_t variable
    foo(&a); // Call foo with the address of a
    printf("a.a: %d \n", a.a); // Print the value of a.a
    printf("a.b: %d \n", a.b); // Print the value of a.b
    printf("a.c: %d \n", a.c); // Print the value of a.c
    
    
    // Instead of using the struct, we can use the raw_data solution and store the data without labelling it.
    uint8_t *b = malloc(100); // Allocate 100 bytes of memory and assign the pointer to b
    
    foo2(b); // Call foo2 with b
    printf("2: %d \n", b[1]); // Print the second element of b
    
    // The third way, you sometimes can face, the mixed solution. Our function accepts raw_data uint8_t pointer
    // but we are passing another pointer that pointing our struct instead an array.
    struct1_t c; // Declare another struct1_t variable
    // The important point is we need to cast the parameter before passing it.
    foo2((uint8_t *)&c); // Call foo2 with the address of c casted to uint8_t pointer
    
    // Also, the size of elements are different than the size of elements in foo2(uint8*)
    printf("sizeof struct: %lu\n", sizeof(c)); // Print the size of c in bytes
    printf("c.a: %d \n", c.a); // Print the value of c.a
    // If the sizes are equal, you can see that understandable results will display.
    // the c.b will print the 4th element of the array because first 4 element is allocated by uint32_t a.
    printf("c.b: %d \n", c.b); // Print the value of c.b
    // Otherwise, the printed value is totally messed up.
    // because c.c is uint16_t and allocating 2bytes, instead the foo2 filling its parameter with uint8_t. which 1byte.
    printf("c.c: %d \n", c.c); // Print the value of c.c
    
    return 0; // Return 0 to indicate successful execution
}
