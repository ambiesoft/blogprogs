
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
	{
		VVDelegate^ dele = gcnew VVDelegate(&MyClass::mystaticfunc);
		IAsyncResult^ result = dele->BeginInvoke(nullptr, nullptr);
		dele->EndInvoke(result);
	}
	{
		MyClass^ myClass = gcnew MyClass();
		VVDelegate^ dele = gcnew VVDelegate(myClass, &MyClass::myinstfunc);
		IAsyncResult^ result = dele->BeginInvoke(nullptr, nullptr);
		dele->EndInvoke(result);
	}
	return 0;
}

