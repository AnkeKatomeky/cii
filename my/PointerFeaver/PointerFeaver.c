#include <stdio.h>
#include "PointerFeaver.h"

int PointerPlayground(int value)
{
    printf("\n");
    printf("Pointer feaver \n");

    //* - dereferencing operator
    //* - to pointers to get value; & - to anything to get pointer; otherwise pointer will be a address
    // standard workflow of pointers
    int someValue = value;       // definition of variable and putting value in it
    int *pointer = &someValue;   // definition of pointer and putting a reference in it
    int someNewValue = *pointer; // definition of newVariable and putting value what referenced in pointer(e.g. someNewValue equals someValue)
    *pointer = value + 2;        // changing the value referenced in pointer to new one(e.g. someValue equals someValue + 2)

    printf("1) value of number is %d (same as (5)) \n", someValue);    // format specifier %p - point in memory
    printf("2) address of number is %p (same as (4)) \n", &someValue); // format specifier %p - point in memory
    printf("3) address of pointer is %p \n", &pointer);                // in front place ampersand to get memory address
    printf("4) reference in pointer is %p (same as (2))\n", pointer);  // format specifier %x - hexadecimal
    printf("5) value in pointer is %d (same as (1)) \n", *pointer);    // in front place asterisk to get value

    pointer = NULL; // clearing the pointer NULL is a emptiness

    // dont forget when comparing pointer1 >= pointer1 we get a comparing of address of that pointes, not values
    // to compare values we must *pointer1 >= *pointer2

    char someChar = 'a';
    pointer = (int *)&someChar; // here how we cast pointers <pointer> = (type *)<address of variable(&var)>
    char someNewChar = (char)*pointer;

    //* operator and ++,-- have the same priority and in that case it is executes from right to left
    pointer++; // increase address by one step(step equals size of type and its mean + 4 byte to address)
    pointer--;

    int a = *pointer++; // it is still wrong cause first will be ++ and second will be *(here in a will be garbage)
    a = *pointer--;     // because postfix operators done first(right to left)
    a = (*pointer)++;   // this will work but in a will be not incremented value
    a = ++*pointer;     // this totally works fine as we want

    // constants and pointers
    const int c = 10; // general constant
    // c = 11; constants are immutable
    int b = 10;
    // constant OF pointer(WARNING - it constant OF!!! pointer)
    const int *constantOfPointer = &c; // it can reference a const variable
    constantOfPointer = &b;            // it can reference a general variable
    constantOfPointer = &a;            // it can change reference itself
    a = 11;                            // and we can still change it. but still immutable ("*constantOfPointer = 11;" - wrong)
    b = *constantOfPointer;            // b became 11 because constantOfPointer reference a and we change a

    // constant pointer(WARNING - is just constant pointer)
    int *const constantPointer = &a; // it like constant of pointer
    *constantPointer = 12;           // it can change referenced value
    // constantPointer = &b; but can't change the reference

    // constant of constant pointer - may be naming is wrong
    const int *const constantOfConstantPointer = &a; // mix of two previous pointers
    //*constantOfConstantPointer = 13 it can't change value
    // constantOfConstantPointer = &b it can't change reference

    printf("\n");
    // arrays and pointers
    int d[] = {1, 2, 3, 4, 5};   // general array of ints
    int d1[5] = {1, 2, 3, 4, 5}; // size can be explicitly written
    int d2[value];               // size can be defined by variable length but it will contain garbage if not defined
    d2[value / 2] = 2;           // setting the value
    a = *d;                      // pointer magic. Dereferencing gether first value in array because address of array is address of firs element
    for (int i = 0; i < 5; i++)  // in that cycle adders are incremented by 4 bytes because int size if 4 byte here
    {
        printf("a[%d]: address=%p \t value=%d \n", i, d + i, *(d + i));
    }
    int *arrayPointer = d;   // equals to d[0]
    a = *(arrayPointer + 2); // equals to d[2]
    printf("\n");
    for (*arrayPointer; arrayPointer <= &d[4]; arrayPointer++) // this cycle equal to previous cycle but without indexer aka low level iterator
    {
        printf("address=%p \t value=%d \n", arrayPointer, *arrayPointer);
    }

    int e[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}; // multidimensional array
    int n = sizeof(e) / sizeof(e[0]);                            // rows
    int m = sizeof(e[0]) / sizeof(e[0][0]);                      // columns
    for (int *multiArrayPointer = e[0], i = 0; i < m * n;)       // in that cycle we move linearly from [0][0] to [3][4] aka low level iterator
    {
        printf("%d \t", *multiArrayPointer++); // value
        if (++i % m == 0)                      // end of one line
        {
            printf("\n");
        }
    }

    // strings and pointers
    int *d3[5] = {&d[0], &d[1], &d[2], &d[3], &d[4]}; // array of pointers
    *d3[1] = 4;                                       // equals to d[1] = 4 because *d3[1] is referencing to d[1]
    char name[] = "Keks";                             // default string representation equal as belows
    char *otherName = "Keks";                         // pointer string representations equal as above
    printf("%s \n", name);                            // getting the string
    printf("%s \n", otherName);                       // getting the string py pointer
    // difference between "name" and "otherName" is that
    //"name" places "Keks" to readOnly memory and copy it into stack to make name[0] posable
    //"otherName" places "Keks" to readOnly memory and place reference on first letter in it to pointer variable

    return someValue;
}