// from C++ Templates The Complete Guide by David Vandevoorde

#include <utility>
#include <string>
#include <iostream>
class Person
{
private:
	std::string name;
public:
	// generic constructor for passed initial name:
	template<typename STR>
	explicit Person(STR&& n) : name(std::forward<STR>(n)) {
		std::cout << "TMPL-CONSTR for '" << name << "'\n";
	}
	// copy and move constructor:
	Person(Person const& p) : name(p.name) {
		std::cout << "COPY-CONSTR Person '" << name << "'\n";
	}
	Person(Person&& p) : name(std::move(p.name)) {
		std::cout << "MOVE-CONSTR Person '" << name << "'\n";
	}
};

int main()
{
	std::string s = "sname";
	Person p1(s); // init with string object => calls copying string-CONSTR
	Person p2("tmp"); // init with string literal => calls moving string-CONSTR
	
	// ERROR
	// nonconstant lvalue is a better match to the template
	// Person p3(p1); // copy Person => calls COPY-CONSTR

	// OK, const is better match to const
	const Person pc("const");
	Person pc2(pc);

	//Person p4(std::move(p1)); // move Person => calls MOVE-CONST
	// Person p5(std::string("ttt"));
}