
#include "stdafx.h"

using namespace System;

delegate void VISDelegate(int, String^ s);

void myfunc(int i, String^ s)
{
	Console::WriteLine(s);
	System::Threading::Thread::Sleep(i);
}
void MyAsyncCallback(IAsyncResult^ ar)
{
	Console::WriteLine("CallBack called");
	Console::WriteLine(ar->AsyncState);
}
int main()
{
	VISDelegate^ dele = gcnew VISDelegate(&myfunc);
	AsyncCallback^ callback = gcnew AsyncCallback(&MyAsyncCallback);
	Console::WriteLine("Before BeginInvoke");
	IAsyncResult^ result = dele->BeginInvoke(1000, "Hello World!", callback, 12345);
	Console::WriteLine("After BeginInvoke");
	dele->EndInvoke(result);
	Console::WriteLine("After EndInvoke");

	return 0;
}

