#include <iostream>

using namespace std;

char* func1(char* p)
{
    return p;
}
char* func2(char p[])
{
    return p;
}
char* func3(char (&p)[13])
{
    return p;
}
template<typename T, size_t N>
T* func4(T (&p)[N])
{
    return p;
}
int main()
{
    char p[] = "Hello World!";
    cout << func1(p) << endl;
    cout << func2(p) << endl;
    cout << func3(p) << endl;
    cout << func4(p) << endl;
    return 0;
}
