
#include <type_traits>
#include <iostream>
#include <typeinfo>





template<typename T>
void printtypevalue(T t)
{
    std::cout << typeid(T).name() << std::endl;
    std::cout << typeid(t).name() << std::endl;
}
template<typename T>
void printtyperef(T& t)
{
    std::cout << typeid(T).name() << std::endl;
    std::cout << typeid(t).name() << std::endl;
}
template<typename T>
void printtypeconstref(const T& t)
{
    std::cout << typeid(T).name() << std::endl;
    std::cout << typeid(t).name() << std::endl;
}

void f1(){}
void f2(){}

template<class T>
void tf(const T& t)
{
    const T tmp(t);
    std::cout << tmp << std::endl;
}

template<class T>
void tf2(const T& t)
{
    typename std::decay<const T>::type tmp(t);
    std::cout << tmp << std::endl;
}

template<class T>
void tg(T& t)
{
    T tmp(t);
    tmp();
}
template<class T>
void tg2(T& t)
{
    typename std::decay<T>::type tmp(t);
    tmp();
}

int main()
{
    {
        int a[] = {1,2,3};
        int b[3];
        // compile error
        // b = a;

        // int a2[3](b);

        int* c;
        c = a;
        std::cout << c << std::endl;
        ++c;  // increment by 4 (sizeof(int))
        std::cout << c << std::endl;

        int (*d)[3];
        d = &a;
        std::cout << d << std::endl;
        ++d;  // increment by 12 (sizeof(int) * 3)
        std::cout << d << std::endl;

        int (&e)[3] = a;
        // cannot increment same as array
    }
    {
        // compile error
        // f2 = f1;

        void (*f3)();
        f3 = f1;
    }

    {
        tf(1);
        // compile error:
        // tf("aaa");

        tf2(1);
        tf2("aaa");
    }

    {
        // error
        // tg(f1);

        tg2(f1);
    }
    std::cout << "type of literal string is " << typeid("literal").name() << std::endl;
    char szT[] = "literal";
    std::cout << "type of szT[] is " << typeid(szT).name() << std::endl;
    const char* p = "literal";
    std::cout << "type of p is " << typeid(p).name() << std::endl;

    printtypevalue("literal");
    printtypevalue(szT);
    printtypevalue(&szT[0]);
    printtypevalue(p);

    printtyperef("literal");
    printtyperef(szT);
    // error C2664: 'void printtyperef<char*>(T &)': cannot convert argument 1 from 'char *' to 'char *&'
    // error: invalid initialization of non-const reference of type 'char*&' from an rvalue of type 'char*'
    // printtyperef(&szT[0]);
    printtyperef(p);

    printtypeconstref("literal");
    printtypeconstref(szT);
    printtypeconstref(&szT[0]);
    printtypeconstref(p);

}
