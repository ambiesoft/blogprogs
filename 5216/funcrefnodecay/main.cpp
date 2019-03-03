#include <iostream>
#include <typeinfo>

typedef char (*FUNCP)();
void a(FUNCP &func)
{
    std::cout << typeid (func).name() << std::endl;
    std::cout << func() << std::endl;
}

typedef char FUNC();
void b(FUNC& func)
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
    // error C2664: 'void a(FUNCP &)': cannot convert argument 1 from 'char (__cdecl *)(void)' to 'FUNCP &' (vc)
    // error: cannot bind non-const lvalue reference of type 'char (*&)()' to an rvalue of type 'char (*)()' (gcc)
    // a(func);

    FUNCP myfuncp=func;
    a(myfuncp);
    b(func);

    // error C2072: 'myfunc': initialization of a function (vc)
    // error: function 'char myfunc()' is initialized like a variable (gcc)
    // FUNC myfunc=func;
}
