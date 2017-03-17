#include <iostream>
using namespace std;
int main()
{
#ifdef _MSC_BUILD
	cout << "_MSC_BUILD" << "\t" << _MSC_BUILD << endl;
#endif

	cout << "_MSC_EXTENSIONS" << "\t" << _MSC_EXTENSIONS << endl;
	cout << "_MSC_FULL_VER" << "\t" << _MSC_FULL_VER << endl;
	cout << "_MSC_VER" << "\t" << _MSC_VER << endl;


	getchar();

	return 0;
}
