#include <iostream>
#include <typeinfo>

template<class T>
void a(T t)
{
    std::cout << typeid (T).name() << std::endl;
}

template<class T>
void b(T& t)
{
    std::cout << typeid (T).name() << std::endl;
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
