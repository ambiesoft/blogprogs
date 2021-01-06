
#include "stdafx.h"

using namespace System;

delegate void VISDelegate(int, String^ s);

void myfunc(int i, String^ s)
{
	Console::WriteLine(s);
	System::Threading::Thread::Sleep(i);
}

int main()
{
	VISDelegate^ dele = gcnew VISDelegate(&myfunc);
	IAsyncResult^ result = dele->BeginInvoke(1000, "Hello World!", nullptr, nullptr);
	dele->EndInvoke(result);
	return 0;
}

