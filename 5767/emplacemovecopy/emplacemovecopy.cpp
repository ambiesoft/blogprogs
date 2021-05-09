#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <iostream>

class MyKlass {
	int ii_;
	float ff_;
	std::string ss_;
public:
	MyKlass(int ii, float ff, const std::string& ss) :
		ii_(ii), ff_(ff), ss_(ss) {
		std::cout << "ctor" << std::endl;
	}
	MyKlass(const MyKlass& that) :
		ii_(that.ii_), ff_(that.ff_), ss_(that.ss_) {
		std::cout << "copy" << std::endl;
	}
	MyKlass(MyKlass&& that) :
		ii_(that.ii_), ff_(that.ff_), ss_(std::move(that.ss_)) {
		std::cout << "move" << std::endl;
	}

	~MyKlass() {
		std::cout << "dtor" << std::endl;
	}
};

// just add 'noexcept' to move ctor
class MyKlassWithNoExcept {
	int ii_;
	float ff_;
	std::string ss_;
public:
	MyKlassWithNoExcept(int ii, float ff, const std::string& ss) :
		ii_(ii), ff_(ff), ss_(ss) {
		std::cout << "ctor" << std::endl;
	}
	MyKlassWithNoExcept(const MyKlassWithNoExcept& that) :
		ii_(that.ii_), ff_(that.ff_), ss_(that.ss_) {
		std::cout << "copy" << std::endl;
	}
	MyKlassWithNoExcept(MyKlassWithNoExcept&& that) noexcept :
		ii_(that.ii_), ff_(that.ff_), ss_(std::move(that.ss_)) {
		std::cout << "move" << std::endl;
	}

	~MyKlassWithNoExcept() {
		std::cout << "dtor" << std::endl;
	}
};

int main()
{
	// without noexcept
	{
		{
			std::vector<MyKlass> v;
			v.emplace_back(2, 3.14f, "jio");  // ctor
			std::cout << "---" << std::endl;
			
			v.emplace_back(2, 3.14f, "jio");  // ctor, copy, dtor
			std::cout << "---" << std::endl;
			
			v.emplace_back(2, 3.14f, "jio");  // ctor, copy, copy, dtor, dtor
			std::cout << "---" << std::endl;
		}

		std::cout << "------------------" << std::endl;

		{
			std::vector<MyKlass> v;
			v.push_back(MyKlass(2, 3.14f, "jij"));  // ctor, move, dtor
			std::cout << "---" << std::endl;

			v.push_back(MyKlass(2, 3.14f, "jij"));  // ctor, move, copy, dtor, dtor
			std::cout << "---" << std::endl;
			
			v.push_back(MyKlass(2, 3.14f, "jij"));  // ctor, move, copy, copy, dtor, dtor, dtor
			std::cout << "---" << std::endl;
		}

		std::cout << "------------------" << std::endl;
	}

	// with noexcept
	{
		{
			std::vector<MyKlassWithNoExcept> v;
			v.emplace_back(2, 3.14f, "jio");  // ctor
			std::cout << "---" << std::endl;

			v.emplace_back(2, 3.14f, "jio");  // ctor, move, dtor
			std::cout << "---" << std::endl;

			v.emplace_back(2, 3.14f, "jio");  // ctor, move, move, dtor, dtor
			std::cout << "---" << std::endl;
		}

		std::cout << "------------------" << std::endl;

		{
			std::vector<MyKlassWithNoExcept> v;
			v.push_back(MyKlassWithNoExcept(2, 3.14f, "jij"));  // ctor, move, dtor
			std::cout << "---" << std::endl;

			v.push_back(MyKlassWithNoExcept(2, 3.14f, "jij"));  // ctor, move, move, dtor, dtor
			std::cout << "---" << std::endl;

			v.push_back(MyKlassWithNoExcept(2, 3.14f, "jij"));  // ctor, move, move, move, dtor, dtor, dtor
			std::cout << "---" << std::endl;
		}

		std::cout << "------------------" << std::endl;
	}

}