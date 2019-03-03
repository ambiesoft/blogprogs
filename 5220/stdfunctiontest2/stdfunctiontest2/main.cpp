#include <iostream>

int __cdecl cdeclFunc(int i)
{
	return i + 1;
}
int __fastcall fastcallFunc(int i)
{
	return i + 1;
}

typedef int (__cdecl *CDECLFUNC)(int);
typedef int (__fastcall *FASTCALLFUNC)(int);
class MyFunction
{
public:
	CDECLFUNC cdeclfunc_ = nullptr;
	FASTCALLFUNC fastcallfunc_ = nullptr;

	MyFunction(CDECLFUNC func)
	{
		cdeclfunc_ = func;
	}

	MyFunction(FASTCALLFUNC func)
	{
		fastcallfunc_ = func;
	}
	int operator()(int i)
	{
		if (cdeclfunc_)
			return cdeclfunc_(i);
		if (fastcallfunc_)
			return fastcallfunc_(i);

		return 0;
	}
};

int main()
{
	MyFunction mycdeclFunction(cdeclFunc);
	std::cout << mycdeclFunction(1) << std::endl;

	MyFunction myFastcallFunction(fastcallFunc);
	std::cout << myFastcallFunction(1) << std::endl;
}