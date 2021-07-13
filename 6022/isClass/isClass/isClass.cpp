
#include <iostream>

template<typename T>
void func(T t)
{
    // Tはclassでは駄目。（以下structも駄目）
    static_assert(!std::is_class<T>::value, 
        "T must not a class");
    // Tはclassへのポインターじゃ駄目
    static_assert(!std::is_class< std::remove_pointer<T>::type >::value, 
        "T must not a ptr to class");
    // Tはclassへのポインターのポインターじゃ駄目
    static_assert(!std::is_class< std::remove_pointer< std::remove_pointer<T>::type >::type >::value,
        "T must not a ptr to ptr to class");
}

class C {};
struct S {};
enum E {};
enum class EC {};
int main()
{
    int i;

    func(1);
    func(&i);
    func(false);

    C c;
    // func(c); // error
    // func(&c);  // error
    C** ppc;
    // func(ppc); // error
    func(&ppc);

    S s;
    // func(s); // error
    // func(&s);  // error

    E e;
    func(e);
    func(&e);

    EC ec;
    func(ec);
    func(&ec);
}
