#include <iostream>
#include "mymacros.h"

int main()
{
    int a = 5;
    int b = -3;

    std::cout << "MY_MAX(a,b) = " << MY_MAX(a,b) << std::endl;
    std::cout << "MY_MIN(a,b) = " << MY_MIN(a,b) << std::endl;
    std::cout << "MY_ABS(b)   = " << MY_ABS(b)   << std::endl;
    std::cout << "MY_CLAMP(a,-2,3) = " << MY_CLAMP(a,-2,3) << std::endl;

    return 0;
}
