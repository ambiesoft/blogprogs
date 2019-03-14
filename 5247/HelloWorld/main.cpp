#include <iostream>
#include <thread>

using namespace  std;

// スレッドで実行される
void threadfunc()
{
    cout << "Hello World!" << endl;
}

int main()
{
    // スレッドを作成して実行
    thread th(threadfunc);

    // スレッド終了を待機
    th.join();
}
