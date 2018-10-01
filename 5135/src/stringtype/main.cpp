#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

void f1()
{
    string cs = "aaa";
    string u8s = u8"aaa";
    wstring ws = L"aaa";
    u16string u16s = u"aaa";
    u32string u32s = U"aaa";

    cout << cs << endl;
    cout << u8s << endl;
    wcout << ws << endl;
}

void f2()
{
    const wchar_t* pwc = L"あいうえお";
    char u8web[] =  {0xE3,0x81,0x82,0xE3,0x81,0x84,0xE3,0x81,0x86,0xE3,0x81,0x88,0xE3,0x81,0x8A,0x0};
    const char* p8c = u8"あいうえお";
    const char* pc = "あいうえお";

    if(memcmp(u8web, p8c, strlen(u8web))==0)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    const char16_t* p16c = u"あいうえお";

    if(memcmp(pwc, p16c, wcslen(pwc)*sizeof(wchar_t))==0)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
}

int main()
{
    f1();
    f2();
    return 0;
}
