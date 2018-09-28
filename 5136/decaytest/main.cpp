// https://cpprefjp.github.io/reference/type_traits/decay.html
#include <type_traits>
#include <iostream>
#include <typeinfo>

template <class T1, class T2>
struct my_pair {
    T1 first;
    T2 second;

    template <class U1, class U2>
    my_pair(const U1& a, const U2& b)
        : first(a), second(b) {}
};

template <class T1, class T2>
my_pair<T1, T2> my_bad_make_pair(const T1& a, const T2& b)
{
    return my_pair<T1, T2>(a, b);
}

template <class T1, class T2>
my_pair<
typename std::decay<const T1>::type,
typename std::decay<const T2>::type
> my_make_pair(const T1& a, const T2& b)
{
    return my_pair<
            typename std::decay<const T1>::type,
            typename std::decay<const T2>::type
            >(a, b);
}

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
int main()
{
    std::cout << "type of literal string is " << typeid("literal").name() << std::endl;
    char szT[] = "literal";
    std::cout << "type of szT[] is " << typeid(szT).name() << std::endl;
    const char* p = "literal";
    std::cout << "type of p is " << typeid(p).name() << std::endl;

    printtypevalue("literal");
    printtypevalue(szT);
    printtypevalue(p);

    printtyperef("literal");
    printtyperef(szT);
    printtyperef(p);

    // コンパイルエラー！
    // 配列をコンストラクタの初期化子で初期化できない
    // auto p1 = my_bad_make_pair("hello", "world");

    // OK
    // decltype(q) == my_pair<const char*, const char*>
    auto q = my_make_pair("hello", "world");

    // OK
    // decltype(a) == mu_pair<int, int>
    auto a = my_make_pair(3, 1);
    a.first = 2;
}
