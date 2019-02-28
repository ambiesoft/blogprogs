#include <Windows.h>

#include <iostream>
#include <memory>
#include <functional>

#pragma comment(lib, "Shell32.lib")
#pragma comment(lib, "user32.lib")

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
    // malloc and free
    {
        unique_ptr<char, std::function<void(void*)>> p(static_cast<char*>(malloc(100)), std::function<void(void*)>(free));
        strcpy(p.get(), "malloc world!");
        cout << p.get() << endl;
    }

    // C file
    {
        unique_ptr<FILE, std::function<int(FILE*)>> file(fopen("myfile.txt","r"),std::function<int(FILE*)>(fclose));
        // do something
    }

    // Win32
    {
        int argc;
        unique_ptr<LPWSTR, std::function<HLOCAL(HLOCAL)>>
            arg(::CommandLineToArgvW(L"aaa.exe a b \"c d e f\"", &argc), std::function<HLOCAL(HLOCAL)>(::LocalFree));
        for(int i=0 ; i < argc ;++i)
        {
            wcout << i << L":" << arg.get()[i] << endl;
        }
    }

    // lambda
    {
        // OpenClipboard returns BOOL
        // Treat BOOL as void*
        unique_ptr<void, std::function<void(void*)>>
            clip(reinterpret_cast<void*>(::OpenClipboard(nullptr)),
            std::function<void(void*)>([](void*p)
            {
                if(p)
                    CloseClipboard();
            }
            )
        );
    }
    return 0;
}
