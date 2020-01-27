#include <iostream>

#if defined(__GNUC__)
    // Some variables must be shared so that CallWndProc hooks can access them
    #define shareattr __attribute__((section ("shared"), shared))
#else
    #pragma section("shared",shared)
    #define shareattr __declspec(allocate("shared"))
#endif

shareattr int i=0 ;
using namespace std;

int main()
{
    i++;
    cout << "i=" << i << endl;
    getchar();
    return 0;
}
