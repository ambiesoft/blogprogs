#include <iostream>
#include <ctime>

using namespace std;

bool isSomethigAvailable()
{
    static auto isAvailable = []() {
        if(time(nullptr)%2 == 0)
            return true;
        return false;
    }();
    return isAvailable;
}
int main()
{
    cout
            << "Something is "
            << (isSomethigAvailable()? "avaiable":"unavailable" )
            << endl;

    cout
            << "Something is "
            << (isSomethigAvailable()? "avaiable":"unavailable" )
            << endl;

    return 0;
}
