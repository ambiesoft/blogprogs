
#include "stdafx.h"

using namespace System;

delegate void VIDelegate(int);

void myfunc(int i)
{
	System::Threading::Thread::Sleep(i);
}

int main()
{
	VIDelegate^ dele = gcnew VIDelegate(&myfunc);
	IAsyncResult^ result = dele->BeginInvoke(1000,nullptr,nullptr);
	dele->EndInvoke(result);
	return 0;
}

