int externValue; // as in header file we must implement externed variable 

int Foo(int value) // function (not method - it's not oop)
{
    // all function parameters sended by value address
    // return value to sended by value
    // for reference cases replace types with pointers(*int instead of int)
    return value;
}

void SayHello(char name[])
{
    printf("Name=%s \t Age=%d \t Weight=%3.2f \n", name, 23, 6332.3456);
}