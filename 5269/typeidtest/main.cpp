#include <iostream>
#include <thread>
#include <random>
#include <cassert>
#include <tuple>
#include <algorithm>

#include <boost/type_index.hpp>

using namespace std;
using namespace boost::typeindex;

template<typename T>
void f(const T& param)
{
    // std
    cout << "T = " << typeid(T).name() << '\n'; // show T
    cout << "param = " << typeid(param).name() << '\n'; // show

    cout << "---------------------" << endl;

    // boost
    cout << "T = "
        << type_id_with_cvr<T>().pretty_name()
        << endl;

    // show param's type
    cout << "param = "
        << type_id_with_cvr<decltype(param)>().pretty_name()
        << endl;
}

int main()
{
    const int x = 10;
    const double y = 0;

    f(x);
    cout << "==================" << endl;
    f(y);
    cout << "==================" << endl;

    vector<string> vs;
    f(vs);
}
