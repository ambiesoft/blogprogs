
using namespace System;
using namespace System::Collections::Generic;

int main()
{
	List<int> intlist;
	intlist.Add(2);
	intlist.Add(1);
	intlist.Add(7);
	intlist.Sort();

	// 1,2,7
	for each (int i in intlist)
		Console::WriteLine(i);

	intlist.Reverse();
	for each (int i in intlist)
		Console::WriteLine(i);

	return 0;
}