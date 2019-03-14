#include <iostream>
#include <thread>

using namespace  std;

// スレッドで実行される
void threadfunc(int i)
{
    cout << i << endl;
}

int main()
{
    // スレッドを作成して実行
    thread th(threadfunc, 123);

    // スレッド終了を待機
    th.join();
}
