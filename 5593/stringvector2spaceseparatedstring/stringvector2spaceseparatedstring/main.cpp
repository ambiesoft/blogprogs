// stringvector2spaceseparatedstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

void osstest()
{
	ostringstream oss;
	oss << 1 << "\n";
	oss << 10 << "\n";
	oss << 100 << "\n";

	oss << "xxx" << "\n";
	oss << "yyy" << "\n";
	oss << "zzz" << "\n";

	cout << oss.str() << endl;
}
void ositest()
{
	{
		ostream_iterator<int> osi(cout, "\n");
		osi = 1;
		osi = 2;
		osi = 3;
	}
	{
		ostream_iterator<string> osi(cout, "\n");
		osi = "osstest1";
		osi = "osstest2";
		osi = "osstest3";
	}
}


int main()
{
	cout << "Hello World!\n";

	osstest();
	ositest();

	vector<string> vs = { "aaa", "bbb", "ccc" };

	ostringstream oss;
	std::copy(vs.begin(), vs.end(),
		ostream_iterator<string>(oss, ","));

	cout << oss.str() << endl;
}

