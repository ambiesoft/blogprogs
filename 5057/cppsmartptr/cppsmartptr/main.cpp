#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<char> p(new char);
    p.reset(new char);
    return 0;
}
