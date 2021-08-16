// https://cpprefjp.github.io/reference/mutex/unique_lock.html

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// std::coutへのアクセスを排他的にする
std::mutex print_mtx_;
void safe_print(int x)
{
    std::lock_guard<std::mutex> lock(print_mtx_);
    std::cout << x << std::endl;
}

class X {
    std::mutex mtx_;
    std::vector<int> data_;
public:
    std::unique_lock<std::mutex> get_lock()
    {
        return std::unique_lock<std::mutex>(mtx_); // ロックを取得する
    }

    // vectorオブジェクトへのアクセスを排他的にする
    void add_value(int value)
    {
        std::unique_lock<std::mutex> lk = get_lock(); // ロックされたunique_lockを受け取る

        data_.push_back(value);
    } // ロックを手放す(unique_lockのデストラクタ)

    void print()
    {
        std::unique_lock<std::mutex> lk = get_lock();

        for (int x : data_) {
            safe_print(x);
        }
    }
};

int main()
{
    X x;

    std::thread t1([&x] { x.add_value(1); });
    std::thread t2([&x] { x.add_value(2); });

    t1.join();
    t2.join();

    x.print();
}