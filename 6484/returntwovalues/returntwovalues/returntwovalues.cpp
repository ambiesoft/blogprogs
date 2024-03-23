#include <string>
#include <tuple>
#include <iostream>

std::pair<int, std::string> getValues()
{
	return std::make_pair(100, "abc");
}

int main()
{
	int i;
	std::string s;

	std::tie(i, s) = getValues();

	// outputs '100 abc'
	std::cout << i << " " << s << std::endl;
	return 0;
}