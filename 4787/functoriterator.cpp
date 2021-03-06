// functoriterator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IntFunctor {
public:
	void operator()(int i) {
		cout << "Hello" << i << endl;
	}
};

int main()
{
	IntFunctor intFunctor;
	intFunctor(10);

	vector<int> vi;
	vi.push_back(123);
	vi.push_back(456);
	for_each(vi.begin(), vi.end(), intFunctor);

	return 0;
}
