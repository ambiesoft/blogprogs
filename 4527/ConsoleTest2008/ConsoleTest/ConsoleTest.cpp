// ConsoleTest.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <windows.h>
#include <string>

int main()
{
	WCHAR buff[30];
	// fgets(buff, sizeof(buff)-1, stdin);


	std::wstring s;
	if(!SetConsoleCP(CP_UTF8))
		return 1;
	for(;;)
	{
		DWORD dwRead=0;
		//if(!ReadFile(GetStdHandle(STD_INPUT_HANDLE),
		//	buff,
		//	sizeof(buff)-1,
		//	&dwRead,
		//	NULL))
		//{
		//	DWORD dwLE = GetLastError();
		//	return 1;
		//}

		if(!ReadConsoleW(GetStdHandle(STD_INPUT_HANDLE),
			buff,
			(sizeof(buff)-1)/sizeof(buff[0]),
			&dwRead,
			NULL))
		{
			DWORD dwLE = GetLastError();
			return 1;
		}

		if(dwRead==0)
			break;

		buff[dwRead]=0;
		s += buff;
	}
	return 0;
}

