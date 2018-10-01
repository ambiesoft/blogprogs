#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cs = "aaa";
    string u8s = u8"aaa";
    wstring ws = L"aaa";
    u16string u16s = u"aaa";
    u32string u32s = U"aaa";

    cout << cs << endl;
    cout << u8s << endl;
    cout << ws << endl;
    cout << u16s << endl;
    cout << u32s << endl;

    cout << "Hello World!" << endl;
    return 0;
}
