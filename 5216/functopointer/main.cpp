#include <iostream>
#include <typeinfo>

void a(char(*func)())
{
    std::cout << typeid (func).name() << std::endl;
    std::cout << func() << std::endl;
}
void b(char func())
{
    std::cout << typeid (func).name() << std::endl;
    std::cout << func() << std::endl;
}

char func()
{
    return 'a';
}
int main()
{
    a(func);
    b(func);
}
