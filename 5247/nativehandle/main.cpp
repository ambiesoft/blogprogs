#include <iostream>
#include <thread>

#include <Windows.h>

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
    // 無限ループ
    for(int i=0; ;++i)
        cout << __FUNCTION__ << i <<endl;
}

int main()
{
    // スレッドを作成して実行
    thread th(threadfunc, C());

    // 2秒スリープ
    std::this_thread::sleep_for(2s);

    // スレッドを強制終了
    if(TerminateThread(th.native_handle(), -1)) {
        // なぜかこれが動かない
        cout << "Thread Killed" << endl;
    } else {
        cerr << "Failed to kill thread" << endl;
        exit(1);
    }

    // スレッド終了を待機、本来すぐ処理が戻るはずだがなんかおかしい
    th.join();
}
