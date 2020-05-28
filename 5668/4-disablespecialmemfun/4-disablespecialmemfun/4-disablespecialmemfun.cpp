#include <iostream>

// template is unable to replace predefined constructor
class C {
public:
	template<typename T>
	C(T const&) {
		std::cout << "tmpl copy constructor\n";
	}
	C(){}
};

int main()
{
	C x;
	C y{ x }; // still uses the predefined copy constructor (not the member template)
}