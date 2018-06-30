#include <new.h>

#include <iostream>
#include <limits>

#define NOMINMAX
#include <Windows.h>

using namespace std;

#define STATUS_INSUFFICIENT_MEM       0xE0000001

// https://msdn.microsoft.com/en-us/library/het71c37.aspx
int OnNoMemory(size_t size) {
	cout << "OnNoMemory:" << size << endl;
  //ULONG_PTR exception_args[] = {size};
  //::RaiseException(STATUS_INSUFFICIENT_MEM,
  //                 EXCEPTION_NONCONTINUABLE,
  //                 sizeof(exception_args)/sizeof(exception_args[0]),
  //                 exception_args);


	// non 0 means success
	static int ret = 5;
	return --ret;
}

int main()
{
    int64_t largesize = std::numeric_limits<int64_t>::max();
	void* vp = malloc(largesize);  // returns NULL;

	try
	{
		char* p = new char[largesize];  // case throw std::bad_alloc()
		delete[] p;
	}
	catch (std::bad_alloc&)
	{
		cout << "std::bad_alloc" << endl;
	}

    auto prevhandler = _set_new_handler(OnNoMemory);  // prevhander is NULL
	vp = malloc(largesize);  // returns NULL
	try
	{
		char* p = new char[largesize];
		delete[] p;
	}
	catch (std::bad_alloc&)
	{
		// if OnNoMemory returns 0, here it comes.
		cout << "std::bad_alloc" << endl;
	}

    cout << "Hello World!" << endl;
    return 0;
}
