#include <iostream>

struct S1 {
    static constexpr int A = 0;
};
struct S2 {
    template<int N>
    static void A(int) {}
};
struct S3 {
    template<int N>
    struct A {};
};

// Uncomment one of three
// #define SISS1
#define SISS2
// #define SISS3

#ifdef SISS1
template <class T>
void foo() {
    //// error C2903: 'A': symbol is neither a class template nor a function template 
    //typename T::template A<0>(x);
     
    //// error C7511: 'A': 'typename' keyword must be followed by a qualified name
    //typename A<0>(x);

    int x = 0;
    T::A<0>(x);
}

int main()
{
    foo<S1>();
}
#endif


#ifdef SISS2
template <class T>
void foo() {
    int x = 0;
    typename T::template A<0>(x);
    T::A<0>(x);

    //// error C7511: 'A': 'typename' keyword must be followed by a qualified name
    //typename A<0>(x);
}

int main()
{
    foo<S2>();
}
#endif


#ifdef SISS3
template <class T>
void foo() {
    typename T::template A<0>(x);

    //// error C7511: 'A': 'typename' keyword must be followed by a qualified name
    //typename A<0>(x);
    
    //int x = 0;
    //// error C2371: 'x': redefinition; different basic types
    //T::A<0>(x);

    //// error C3861: 'x': identifier not found
    //T::A<0>(x);
}

int main()
{
    foo<S3>();
}
#endif

