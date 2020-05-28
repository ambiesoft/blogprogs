// 5-example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<typename T>
void myfunc(T t)
{
    std::cout << t << "\n";
}

template<typename T,
    typename = std::enable_if_t<std::is_convertible_v<T, int>>>
    void myintfunc(T t)
{

}
template<typename T,
    typename = std::enable_if<std::is_convertible<T, int>::value>::type>
    void myintfunc_old(T t)
{

}
int main()
{
    myfunc('a');
    myfunc(10);
    myfunc("hello");
    myfunc(std::string("hello2"));

    myintfunc('a');
    myintfunc(10);


    /*
        error C2672: 'myintfunc': no matching overloaded function found
        error C2783: 'void myintfunc(T)': could not deduce template argument for '<unnamed-symbol>'
        message : see declaration of 'myintfunc'
    */
    // myintfunc("hello");

    myintfunc_old('a');
    myintfunc_old(10);
    // myintfunc_old("hello");
}
