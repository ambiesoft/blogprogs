
#include "stdafx.h"

using namespace System;

delegate void VVDelegate(void);

ref class MyClass
{
public:
	static void mystaticfunc(void)
	{
		System::Threading::Thread::Sleep(3000);
	}
	void myinstfunc(void)
	{
		System::Threading::Thread::Sleep(3000);
	}
};

int main()
{
	IAsyncResult^ result1;
	IAsyncResult^ result2;

	{
		VVDelegate^ dele = gcnew VVDelegate(&MyClass::mystaticfunc);
		result1 = dele->BeginInvoke(nullptr, nullptr);
	}
	{
		MyClass^ myClass = gcnew MyClass();
		VVDelegate^ dele = gcnew VVDelegate(myClass, &MyClass::myinstfunc);
		result2 = dele->BeginInvoke(nullptr, nullptr);
	}

	array<System::Threading::WaitHandle^>^ waitHandles = gcnew array<System::Threading::WaitHandle^>(2);
	waitHandles[0] = result1->AsyncWaitHandle;
	waitHandles[1] = result2->AsyncWaitHandle;
	System::Threading::WaitHandle::WaitAll(waitHandles);
	return 0;
}

