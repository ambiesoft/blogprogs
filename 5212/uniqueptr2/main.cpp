#include <Windows.h>

#include <iostream>
#include <memory>

#pragma comment(lib, "Shell32.lib")
using namespace std;

class MyClass
{
public:
    MyClass() {
        cout << "ctor" << endl;
    }
    ~MyClass() {
        cout << "dtor" << endl;
    }
};

int main()
{

    {
        unique_ptr<MyClass> p = make_unique<MyClass>();
        unique_ptr<MyClass> q(std::move(p));
        std::cout << "p = " << (p ? "not null" : "null") << std::endl;
    }

    std::cout << "======================" << std::endl;

    {
        unique_ptr<MyClass> p;
        p.reset(new MyClass);

        // OK, previous instance will be freed
        p.reset(new MyClass);
    }


    return 0;
}
