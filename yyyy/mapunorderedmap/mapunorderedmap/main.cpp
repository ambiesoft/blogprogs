// mapunorderedmap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// map.cpp

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main(void)
{
	unordered_map<string, int> scores;

	scores["Teafv"] = 86;
	scores["fweijo3"] = 70;
	scores["Vaer3e"] = 62;
	scores["fewuoiur"] = 91;

	for (auto it = scores.begin(); it != scores.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}

	return 0;
}