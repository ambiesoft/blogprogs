#include <windows.h>
#include <stdio.h>
#include <stlsoft/smartptr/scoped_handle.hpp>
 
void myHeapFree(void* p)
{
	HeapFree(GetProcessHeap(), 0, p);
}
 
int main()
{
	// クリップボード
	{
		if(!OpenClipboard(NULL))
			return -1;
 
		stlsoft::scoped_handle<void> clipboard(CloseClipboard);
	}
 
	// カーネルオブジェクト
	{
		HANDLE h = CreateMutex(NULL, FALSE, NULL);
		if ( h==NULL )
			return -1;
 
		stlsoft::scoped_handle<HANDLE> ko(h, CloseHandle);
 
 
		if(WAIT_OBJECT_0 != WaitForSingleObject(h, INFINITE))
			return -1;
 
		stlsoft::scoped_handle<HANDLE> wf(h, ReleaseMutex);
	}
 
	// Win32ヒープ
	{
		void* p = HeapAlloc(GetProcessHeap(), 0, 100);
		if ( p == NULL )
			return -1;
 
		stlsoft::scoped_handle<void*> ha(p, myHeapFree);
	}
 
	// Win32クリティカルセクション
	{
		CRITICAL_SECTION cs;
		InitializeCriticalSection(&cs);
		stlsoft::scoped_handle<LPCRITICAL_SECTION> ics(&cs,DeleteCriticalSection);
 
		EnterCriticalSection(&cs);
		stlsoft::scoped_handle<LPCRITICAL_SECTION> lcs(&cs, LeaveCriticalSection);
	}
 
	// Cヒープ
	{
		void* mem = malloc(100);
		if(!mem)
			return -1;
 
		stlsoft::scoped_handle<void*> ma(mem, free);
	}
 
 
	// Cファイル
	{
		FILE* f = fopen("C:\\T\\Test.txt", "w");
		if (!f)
			return -1;
 
		stlsoft::scoped_handle<FILE*> fo(f, fclose);
	}
 
 
	// win32ファイル
	{
		HANDLE hFile = CreateFileA("C:\\T\\Test.txt",
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		if(hFile==INVALID_HANDLE_VALUE)
			return -1;

		stlsoft::scoped_handle<HANDLE> fo(hFile, CloseHandle, INVALID_HANDLE_VALUE);
	}
	return 0;
}
