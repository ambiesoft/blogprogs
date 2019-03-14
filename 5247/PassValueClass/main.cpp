#include <iostream>
#include <thread>

using namespace  std;

class C
{
public:
    C() {
        cout << "C()" << endl;
    }
    C(const C& c)
    {
        cout << "C(const C&)" << endl;
    }
    C(C&& c)
    {
        cout << "C(const C&&)" << endl;
    }
    ~C() {
        cout << "~C()" << endl;
    }
};

// スレッドで実行される
void threadfunc(C c)
{
    cout << __FUNCTION__ << endl;
}

int main()
{
    // スレッドを作成して実行
    thread th(threadfunc, C());

    // スレッド終了を待機
    th.join();
}
