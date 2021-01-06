
#include "stdafx.h"

using namespace System;

delegate void VVDelegate(void);

void myfunc(void)
{
	System::Threading::Thread::Sleep(3000);
}

int main()
{
	VVDelegate^ dele = gcnew VVDelegate(&myfunc);
	IAsyncResult^ result = dele->BeginInvoke(nullptr, nullptr);
	dele->EndInvoke(result);
	return 0;
}

