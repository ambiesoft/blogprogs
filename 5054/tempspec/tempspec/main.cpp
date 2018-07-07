#include <iostream>
#include <cstring>

template <typename T>
class DataStore {
public:
    explicit DataStore(const T& value) :
        mValue(value)
    {}

    inline bool operator==(const DataStore& rhs) const
    {
        return mValue == rhs.mValue;
    }

private:
    T    mValue;
};

template <>
class DataStore<const char*> {
public:
    explicit DataStore(const char* value) :
        mValue(value)
    {}

    inline bool operator==(const DataStore& rhs) const
    {
        return std::strcmp(mValue, rhs.mValue) == 0;
    }

private:
    const char*    mValue;
};


int main()
{
    const char s1[] = "abc";
    const char s2[] = "abc";

    DataStore<const char*> ds1(s1);
    DataStore<const char*> ds2(s2);

    std::cout << std::boolalpha
              << (ds1 == ds2)
              << std::endl;
}
