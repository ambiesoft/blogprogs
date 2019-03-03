#include <iostream>
#include <typeinfo>

void a(char *&p)
{
    std::cout << typeid (p).name() << std::endl;
}
void b(char (&p)[10])
{
    std::cout << typeid (p).name() << std::endl;
}


int main()
{
    char sz[10];

    // error C2664: 'void a(char *&)': cannot convert argument 1 from 'char [10]' to 'char *&' (vc)
    // error: cannot bind non-const lvalue reference of type 'char*&' to an rvalue of type 'char*' (gcc)
    // a(sz);

    b(sz);

    char* p = sz;
    a(p);

    // error C2664: 'void b(char (&)[10])': cannot convert argument 1 from 'char *' to 'char (&)[10]' (vc)
    // error: invalid initialization of reference of type 'char (&)[10]' from expression of type 'char*' (gcc)
    //b(p);
}
