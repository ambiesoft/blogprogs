#include <Windows.h>

// https://docs.microsoft.com/en-us/cpp/preprocessor/section?view=vs-2019
#pragma section("shared",shared)

__declspec(allocate("shared"))
int i = 0;

int __stdcall WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
	)
{
	char szT[100];
	++i;
	++j;
	wsprintfA(szT, "i=%d, j=%d", i, j);
	MessageBoxA(NULL, szT, "sectiontest", MB_OK);
	return 0;
}