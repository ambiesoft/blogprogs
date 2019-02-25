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
        // basic
        unique_ptr<MyClass> p1(new MyClass);
        unique_ptr<MyClass> p2 = make_unique<MyClass>();
    }

    {
        int* pI = new int();
        unique_ptr<int> up(pI);
    }

    // array
    {
        unique_ptr<char[]> p(new char[100]);
        strcpy(p.get(), "Hello World!");
        cout << p << endl;
    }

    // malloc and free
    {
        unique_ptr<char, void (__cdecl*)(void*)> p(static_cast<char*>(malloc(100)), free);
        strcpy(p.get(), "malloc world!");
        cout << p << endl;
    }

    // C file
    {
        unique_ptr<FILE, int(__cdecl*)(FILE*)> file(fopen("myfile.txt","r"),fclose);
        // do something
    }

    // Win32
    {
        int argc;
        unique_ptr<LPWSTR, HLOCAL(WINAPI *)(HLOCAL)>
            arg(::CommandLineToArgvW(L"aaa.exe a b \"c d e f\"", &argc), ::LocalFree);
        for(int i=0 ; i < argc ;++i)
        {
            wcout << i << L":" << arg.get()[i] << endl;
        }
    }
    return 0;
}
