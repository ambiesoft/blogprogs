
// https://cpprefjp.github.io/reference/type_traits/is_const.html
#include <type_traits>

static_assert(std::is_const<const int>::value == true, "value == true, const int is const-qualified");
static_assert(std::is_same<std::is_const<const int>::value_type, bool>::value, "value_type == bool");
static_assert(std::is_same<std::is_const<const int>::type, std::true_type>::value, "type == true_type");
static_assert(std::is_const<const int>() == true, "is_const<const int>() == true");

static_assert(std::is_const<int>::value == false, "value == false, int is not const-qualified");
static_assert(std::is_same<std::is_const<int>::value_type, bool>::value, "value_type == bool");
static_assert(std::is_same<std::is_const<int>::type, std::false_type>::value, "type == false_type");
static_assert(std::is_const<int>() == false, "is_const<int>() == false");

static_assert(std::is_const<const volatile int>::value == true, "value == true, const volatile int is const-qualified");
static_assert(std::is_const<const int&>::value == false, "value == true, const int& is not const-qualified");

int main() {}