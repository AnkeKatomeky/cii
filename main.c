#include <stdio.h>
#include "my/Math/myMath.h"         //in .h(header files) are placed defenitions of somethings
#include "my/Hellower/myHellower.h" 
#include "my/PointerFeaver/PointerFeaver.h"
#include "my/MemoryAllocation/MemoryAllocation.h"
#include "my/StructsDefs/StructsDefs.h"
#include "my/FIlesFuns/FIlesFuns.h"

//#define _WIN32_WINNT 0x0A00
#include <windows.h>

int globalIntVar = 3;             // it is a global variable
const float constantValue = 3.14; // it is constant in global

int main()
{
    HWND handler = GetConsoleWindow();

    LPPOINT lpPointer = malloc(sizeof(*lpPointer));
    do
    {
        GetCursorPos(lpPointer);
        printf("Press escape to continue %d %d\n", lpPointer->x, lpPointer->y);
        Sleep(100);
    } while (GetKeyState(VK_ESCAPE) >= 0);

    HDC descriptor = GetDC(handler);
    SelectObject(descriptor, GetStockObject(DC_BRUSH));
    SetDCBrushColor(descriptor, RGB(255, 0, 255));
        Sleep(100);
    do
    {
        Rectangle(descriptor, 100, 100, 500, 500);
    } while (GetKeyState(VK_ESCAPE) >= 0);

    int number = 3;  // standard variable. it is local scoped
    externValue = 1; // its extern variable in myHellower

    // scopes
    auto int autoNumber;          // auto variable or local variable, same as previous line but explicit definition of scope
    int globalIntVar = 5;         // overlapped variable(it is not a global variable)
    static int staticVar = 1;     // static variable - value here is always stays in memory
    register int registerVar = 1; // register variable - value what putted in cpu registers for more speed(not always works)
    int *intPointer;              // reference type is calls pointer(point to memory location)

    // where are several common types
    char charVar;               // 1 byte size or ascii character
    short shortVar;             // 2 byte size
    long longVar;               // 4 byte size
    long long veryLongVar;      // 8 byte size
    int intVar;                 // where is trivia about int. Size is depend on system OS. It can be 2 byte(16 bit OS) size or 4 byte(32 bit or hight) long
    float floatVar;             // 4 byte long, single precision
    double doubleVar;           // 8 byte long, double precision
    long double longDoubleVar;  // 10 byte(but can be more, depends on OS)
    char stringVar[] = "Hello"; // is a string variable, it is a char array and equals to char stringVar[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    int arrayVar[5];            // array of integers whit size of 5
    // any array can be marked as "unsigned" to move range of values to positive side and extend it
    // by default all types marked as "signed" which is opposite of "unsigned" and dived values by negative and positive digits

    printf("%s World \n", stringVar); //%s specifier - string specifier
    SayHello("Anke");

    printf("Number to power 2 and factorial "); // printf - print in format
    scanf("%d", &number);                       // scanf - scan in format
    intPointer = &number;                       // get reference from variable to pointer(without & is will be a value and overwise is become a reference)

    // if we write intPointer = number it will reference to a memory location on address 0011(or what we send on input)
    printf("Number have %ld bits \n", sizeof(number) * 8);       // format specifier %d - digit(%ld - for long)
    printf("Power 2 of %d = %3.2f \n", number, GetPow2(number)); // format specifier %f - fraction(%<length>.<frac length>f - extra formatting)
    printf("Factorial of %d = %3.2f \n", number, GetFactorial(number));

    Foo(number); // function invocation
    PointerPlayground(number);
    MemoryAllocationFun(number);
    DoSomethingWhitStructs(number);
    FileFun(number);
    return 0;
}