#include <type_traits>
#include <cstdint>

static constexpr int64_t g = 1234;

double ddd()
{
    return 1.234;
}

int ccc(char c)
{
    return c + 3;
}
int main()
{
    auto val = false;
    
    // check val is bool
    static_assert(std::is_same<decltype(val), bool>::value, "retval must be bool");

    int i = 100;
    static_assert(std::is_same<decltype(i * g), int64_t>::value, "i * g must be int64_t");

    // invoke_result needs C++ 17
    static_assert(std::is_same<std::invoke_result<decltype(ddd)>::type, double>::value, "ddd must return double");

    // invoke_result needs C++ 17
    static_assert(std::is_same<std::invoke_result<decltype(ccc), char>::type, int>::value, "ccc must return int");
}
