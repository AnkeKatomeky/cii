#include "myMath.h"

double GetPow2(double number)
{
    return number * number;
}

double GetFactorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}