// IsPipeInherited.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;
int main()
{
	HANDLE hRead = nullptr;
	HANDLE hWrite = nullptr;

	if (!CreatePipe(&hRead, &hWrite, nullptr, 0))
		return 1;

	DWORD dwFlags = 0;
	if (!GetHandleInformation(hRead, &dwFlags))
		return 1;
	cout << "hRead is " << ((dwFlags & HANDLE_FLAG_INHERIT) != 0) << endl;

	dwFlags = 0;
	if (!GetHandleInformation(hWrite, &dwFlags))
		return 1;
	cout << "hWrite is " << ((dwFlags & HANDLE_FLAG_INHERIT) != 0) << endl;

	CloseHandle(hRead);
	CloseHandle(hWrite);
    return 0;
}

