#include <sstream>
#include <iostream>
#include <vector>

template<typename T>
std::string to_string_impl(const T& t)
{
	std::stringstream ss;
	ss << t;
	return ss.str();
}

std::vector<std::string> to_string()
{
	return {};
}

template<typename ... Param>
std::vector<std::string> to_string(const Param& ... param)
{
	return { to_string_impl(param)... };
}


template<typename ... Param>
std::vector<std::string> to_string_lambda(const Param& ... param)
{
	const auto to_string_lambda_imple = [](const auto & t) {
		std::stringstream ss;
		ss << t;
		return ss.str();
	};

	return { to_string_lambda_imple(param)... };
}



int main()
{
	const auto vec = to_string("hello", 1, 5.3, "world");
	for (const auto& o : vec) {
		std::cout << o << std::endl;
	}

	const auto veclambda = to_string_lambda("hello", 1, 5.3, "world");
	for (const auto& o : veclambda) {
		std::cout << o << std::endl;
	}
}



