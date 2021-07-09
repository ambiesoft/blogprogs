// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T>
void func(T t)
{
	static_assert(!std::is_pointer_v<T>, "T must not a pointer");
}

static void CheckKata(){}
template<typename T, typename... ARGS>
static void CheckKata(T firstArg, ARGS... args)
{
	using NoConstT = typename std::add_pointer<std::remove_cv<std::remove_pointer<T>::type>::type>::type;
	static_assert(
		std::is_same_v<std::remove_cv_t<T>, wchar_t> ||
		!std::is_same_v<NoConstT, wchar_t*>, 
		"argument must not wchar_t*");
	
	std::cout << typeid(T).name() << '\n';
	std::cout << typeid(std::decay_t<T>).name() << '\n';
	std::cout << typeid(std::remove_cv_t<T>).name() << '\n';
	std::cout << typeid(std::remove_const_t<T>).name() << '\n';
	std::cout << typeid(std::remove_pointer_t<T>).name() << '\n';
	std::cout << typeid(NoConstT).name() << '\n';
	CheckKata(args...);
}


int main()
{
	func(1);
	// func("");  // error
	int a = 1;
	func(a);
	// func(&a);  // error
	int* pa = &a;
	func(*pa);

	const wchar_t* pW = L"pW";
	CheckKata("");
	CheckKata(1);
	CheckKata("a");
	CheckKata(0.1);
	CheckKata(L'a');
	CheckKata(*pW);
	// CheckKata(pW);
}
