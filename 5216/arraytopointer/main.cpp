#include <iostream>
#include <typeinfo>

void a(char *p)
{
    std::cout << typeid (p).name() << std::endl;
}
void b(char p[])
{
    std::cout << typeid (p).name() << std::endl;
}


int main()
{
    char sz[10];
    a(sz);
    b(sz);

    char* p = sz;
    a(p);
    b(p);
}
