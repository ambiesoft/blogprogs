#include <iostream>
#include <thread>
#include <random>
#include <cassert>
#include <tuple>

using namespace  std;


class C
{
    static int checkmethod_;

    vector<int> v_;

public:
    C(std::initializer_list<int> list) : v_(list) {
        cout << "C(init)";
        for(auto&& e : v_)
            cout << e << ",";
        cout << endl;
    }
    C(const C& c)
    {
        cout << "C(const C&)" << endl;
    }
    C(C&& c)
    {
        cout << "C(const C&&)" << endl;
    }
    ~C() {
        cout << "~C()" << endl;
    }

    bool operator==(const C& that) const {
        return v_ == that.v_;
    }
    bool operator!=(const C& that) const {
        return !(*this==that);
    }
    bool operator<(const C& that) const {
        return v_ < that.v_;
    }
};

//int C::checkmethod_ = 1;
//int C::checkmethod_ = 2;
int C::checkmethod_ = 3;

int main()
{
    // https://stackoverflow.com/a/7560564
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 9); // define the range
    bool check1=false;
    bool check2=false;
    bool check3=false;
    for(int i=0 ; !(check1 && check2 && check3); ++i)
    {
        cout << i << "th try..." << endl;

        C c1{distr(eng),distr(eng),distr(eng)};
        C c2{distr(eng),distr(eng),distr(eng)};

        // check operator< is valid
        if (c1 < c2)
        {
            assert(c1 != c2);
            assert(!(c2 < c1));
            check1=true;
        }
        else if(c2 < c1)
        {
            assert(c1 != c2);
            assert(!(c1 < c2));
            check2=true;
        }
        else
        {
            assert(c1==c2);
            check3=true;
        }
    }
}
