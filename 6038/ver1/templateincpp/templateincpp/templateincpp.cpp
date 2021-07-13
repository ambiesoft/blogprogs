#include <iostream>
#include "header.h"
int main()
{
    const char* p = "aaa";
    const wchar_t* pw = L"bbb";
    std::cout << "Length of p is " << GetStringLength(p) << '\n';
    std::cout << "Length of pw is " << GetStringLength(pw) << '\n';

    int* pi;
    // GetStringLength(pi);  // static_assert
}

