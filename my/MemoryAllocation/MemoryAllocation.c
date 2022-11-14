#include <stdlib.h>
#include <stdio.h>

void MemoryAllocationFun(int value)
{
    int *a = malloc(value * sizeof(int)); // in a we have pointer to free allocated memory in size of value bytes
                                          // int *b = calloc(value, sizeof(int));  // in b we have pointer to free allocated memory in size of sizeof(INT_MAX) * value. same size as a
                                          // int *c = realloc(a, value * 2);       // in c we have pointer to copy of a but with changed size to value * 2

    free(a); // release control to OS of a memory
    // free(b); // release control to OS of b memory
    // free(c); // release control to OS of c memory
}