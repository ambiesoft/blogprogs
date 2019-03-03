#include "main.h"


// ==========================================================

int __cdecl cdeclFunc(int i)
{
	return i + 1;
}
int __fastcall fastcallFunc(int i)
{
	return i + 1;
}

int main()
{
	cdeclFunc(1);
	fastcallFunc(1);

	std::function<int(int)> stdfunctioncdecl(cdeclFunc);
	stdfunctioncdecl(1);

	std::function<int(int)> stdfunctionfastcall(fastcallFunc);
	stdfunctioncdecl(1);

	return 0;
}



