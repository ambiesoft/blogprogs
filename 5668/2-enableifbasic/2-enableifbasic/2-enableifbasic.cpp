#include <utility>

// if (sizeof(T) > 4) is true, enable_if yields type 'void' (2nd parameter)
// if not, due to SFINAE, function is ignored
template<typename T>
typename std::enable_if<(sizeof(T) > 4)>::type
foo() {
}

// Same as above, C++14 version
template<typename T>
std::enable_if_t<(sizeof(T) > 4)>
foo14() {
}

// Same but not clumsy
template<typename T,
	typename = std::enable_if_t<(sizeof(T) > 4)>>
void bar() {
}
// which expands to
//template<typename T,
//	typename = void>
//	void bar() {
//}
// typename = void is typename V = void, and this is ignored

int main()
{
	// ERROR
	// invalid explicit template argument(s) for 'std::enable_if<sizeof(T)>4,void>::type foo(void)'
	// foo<int>();

	foo<double>();
	foo14<double>();
	bar<double>();
}