// functorcurry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <functional>
using namespace std;
void testfunc(int i1, int i2, int i3, int i4, int i5)
{
	cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5 << endl;
}

int main()
{
	auto f1 = bind(testfunc, 
		1,
		placeholders::_1,
		placeholders::_2,
		placeholders::_3,
		placeholders::_4);

	auto f2 = bind(f1,
		2,
		placeholders::_1,
		placeholders::_2,
		placeholders::_3);

	auto f3 = bind(f2,
		3,
		placeholders::_1,
		placeholders::_2);

	auto f4 = bind(f3,
		4,
		placeholders::_1);


	f4(5);  // prints "1 2 3 4 5"
    return 0;
}

