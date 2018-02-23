#include <iostream>
#include <string>
#include <memory>

#if 1
#include <boost/any.hpp>
using boost::any;
using boost::any_cast;
using boost::bad_any_cast;
#else
#include <any>
using std::any;
using std::any_cast;
using std::bad_any_cast;
#endif

class C
{
public:
    C()
    {
        std::cout << "C" << std::endl;
    }
    ~C()
    {
        std::cout << "~C" << std::endl;
    }
    void myok()
    {
        std::cout << "ok" << std::endl;
    }
};

// Modified http://faithandbrave.hateblo.jp/entry/2016/07/29/181945
int main()
{
    {
        any ac = new C;
    }

    {
        std::shared_ptr<C> sp(new C);
        sp->myok();

        any sharedac = std::shared_ptr<C>(new C);

        // bad cast
        // C* cp = any_cast<C*>(sharedac);
        // cp->ok();

        std::shared_ptr<C> spc = any_cast<std::shared_ptr<C>>(sharedac);
        spc->myok();
    }
    any a = 3;
    a = std::string("hello");

    try
    {
        std::string s = any_cast<std::string>(a);
        std::cout << s << std::endl;
    }
    catch (bad_any_cast& e)
    {
        std::cout << "bad_any_cast: " << e.what() << std::endl;
    }

    if (std::string* s = any_cast<std::string>(&a))
    {
        std::cout << *s << std::endl;
    }
    else {
        std::cout << "null" << std::endl;
    }
}
