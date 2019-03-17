#include <iostream>
#include <thread>
#include <random>
#include <cassert>
#include <tuple>
#include <algorithm>

using namespace  std;

class C
{
    int a_;
    int b_;
public:
    C(int a, int b) : a_(a), b_(b) {
        cout << "C()" << "a_=" << a_ << "," << "b_=" << b_ << endl;
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
        return a_==that.a_ && b_==that.b_;
    }
    bool operator!=(const C& that) const {
        return !(*this==that);
    }
    bool operator<(const C& that) const {
        if(checkmethod_==1)
            return a_ < that.a_ && b_ < that.b_;
        else if(checkmethod_==2)
        {
            if(a_ < that.a_)
                return true;

            if(a_ == that.a_)
                return b_ < that.b_;

            return false;
        }
        else if(checkmethod_==3)
        {
            return tie(a_,b_) < tie(that.a_, that.b_);
        }
        else if(checkmethod_==4)
        {
            return lexicographical_compare(&a_, (&b_)+1, &that.a_, (&that.b_)+1);
        }
        // invalid method
        assert(false);
    }

    static int checkmethod_;
};

//int C::checkmethod_ = 1;
//int C::checkmethod_ = 2;
//int C::checkmethod_ = 3;
int C::checkmethod_;

int checkit(C& c1, C& c2)
{

    // check operator< is valid
    if (c1 < c2)
    {
        assert(c1 != c2);
        assert(!(c2 < c1));
        return 1;
    }
    else if(c2 < c1)
    {
        assert(c1 != c2);
        assert(!(c1 < c2));
        return 2;
    }
    else
    {
        assert(c1==c2);
        return 3;
    }


}
int main()
{
    // https://stackoverflow.com/a/7560564
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(-10, 10); // define the range

    int resultis[4] = {0};

    for(int i=0 ; resultis[1]!=3; ++i)
    {
        cout << i << "th try..." << endl;

        C c1(distr(eng),distr(eng));
        C c2(distr(eng),distr(eng));

        for(int method=2 ; method <= 4 ;++method)
        {
            C::checkmethod_=method;
            resultis[method-1] = checkit(c1,c2);
        }
        assert(all_of(&resultis[1], &resultis[_countof(resultis)], [&](int i)
        {
            return i==resultis[1];
        }));
    }

}
