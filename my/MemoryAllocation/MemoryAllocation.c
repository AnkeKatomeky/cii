#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void MemoryAllocationFun(int value)
{
    PrintInts(4, 8, 12, 6, 3);

    int *(*adder)(int *first, int *second); // variable pointer to function. Names of parameters can be omitted
    adder = SumIntArrays;                   // setting pointer to function to array adder function

    printf("Memory fun. It's all in heap memory \n");
    printf("*a malloc \n");
    int *a = malloc(value * sizeof(int)); // in a we have pointer to free allocated memory in size of value bytes
    for (int i = 0; i < value; i++)       // general cycle through all elements
    {
        *(a + i) = (i + 1) * 2; // putting value in pointer
    }
    PrintIntMemory(a);

    printf("*b calloc. Values two timse lagrer as previous \n");
    int *b = calloc(value, sizeof(int)); // in b we have pointer to free allocated memory in size of sizeof(INT_MAX) * value. same size as a
    for (int i = 0; i < value; i++)      // general cycle through all elements
    {
        b[i] = (i + 1) * 4; // same as previous line
    }
    PrintIntMemory(b);

    printf("*sum - sum of *a and *b \n");
    int *sum = SumIntArrays(a, b);
    PrintIntMemory(sum);
    printf("*added - sum of *sum and *b. Invoked via pointer to function \n");
    int *added = adder(sum, b);
    PrintIntMemory(added);

    printf("*c realloc. Two times larger then *a \n");
    int *c = realloc(a, value * sizeof(int) * 2); // in c we have pointer to copy of a but with changed size to value * 2
    for (int i = value; i < value * 2; i++)       // general cycle through all elements
    {
        *(c + i) = (i + 1) * 2; // putting value in pointer
        c[i] = (i + 1) * 3;     // same as previous line
    }
    PrintIntMemory(c);

    printf("Free all memory \n");
    //free(a); // there are no need to freeing *a heap because it's already freed by realloc function
    free(b); // release control to OS of b memory
    free(c); // release control to OS of c memory
    free(sum); // release control to OS of c memory
    free(added); // release control to OS of c memory
    printf("Complete \n");

    printf("Multidimensional array on memory allocation staff \n");
    int **table = calloc(value, sizeof(int *)); // allocating memory to table itself
    int *rows = calloc(value, sizeof(int));     // allocations memory to row size(columns per row)

    for (int i = 0; i < value; i++)
    {
        rows[i] = value - i + 4;                 // explicit size of row
        table[i] = calloc(rows[i], sizeof(int)); // allocation memory to row

        for (int j = 0; j < rows[i]; j++)
        {
            table[i][j] = i + (j * 2) + 1; // putting value in table itself
        }
    }

    printf("Print multidimensional array \n"); // self explanatory
    for (int i = 0; i < value; i++)
    {
        for (int j = 0; j < rows[i]; j++)
        {
            printf("%d \t", table[i][j]);
        }
        printf("\n");
    }

    printf("Free all memory \n");   // about freeing memory there is a small trivial
    for (int i = 0; i < value; i++) // we must free memory manually per row
    {
        free(table[i]);
    }
    free(rows); // and then free table itself
    free(table);
    printf("Complete \n");
}

void PrintIntMemory(int *values) // printing function
{
    int size = _msize(values) / sizeof(int); // getting size of allocated memory
    printf("Addres\t\t\t\tPtr manner\tArray manner\n");
    for (int i = 0; i < size; i++)
    {
        printf("Address:[%p] \t", (values + i));
        printf("%d \t\t", *(values + i)); // we just temporary shifting pointer
        printf("%d \n", values[i]);       // works in a same manner like previous line
    }
}

// there is small trivia about returning pointer
// returning pointer on inner variable is wrong practice because after leaving block all inners will be free and became a garbage
// all allocation stuff happens in heap memory but all block vars stored in stack memory
int *SumIntArrays(int *first, int *second) // sum of two arrays. Must be a same size or NULL
{
    int firstSize = _msize(first) / sizeof(first[0]); // get size of the first array(size of array itself in bytes divided on size of cell)
    int secondSize = _msize(second) / sizeof(second[0]);
    if (firstSize != secondSize)
    {
        return NULL;
    }

    int *summedArray = calloc(firstSize, sizeof(int)); // allocating new array

    for (int i = 0; i < firstSize; i++)
    {
        summedArray[i] = first[i] + second[i];
    }

    return summedArray;
}
// function whit variable param count
void PrintInts(int count, ...) // at least one explicit parameter
{
    va_list factor;          // #include <stdarg.h> must be imported
    va_start(factor, count); // factor tracker for variable parameter reader
    for (int i = 0; i < count; i++)
    {
        printf("%d ", va_arg(factor, int)); // va_arg we read param where second param it what type are that parameter
    }

    va_end(factor); // at the end we must close tracer
}