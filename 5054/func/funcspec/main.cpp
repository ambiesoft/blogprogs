#include <iostream>
#include <string>
#include <cstring>

template <typename T>
inline std::size_t Length(const T* str)
{
    return str->length();
}

template <>
inline std::size_t Length<char>(const char* str)
{
    return std::strlen(str);
}


int main()
{
    const std::string s1("aaa");
    const char s2[] = "xxxx";

    std::cout << Length(&s1) << std::endl;
    std::cout << Length(s2) << std::endl;
}
