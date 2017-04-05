// ConsoleTest.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <windows.h>
#include <string>

int main()
{
	char buff[3];
	std::string s;
	for(;;)
	{
		DWORD dwRead=0;
		if(!ReadFile(GetStdHandle(STD_INPUT_HANDLE),
			buff,
			sizeof(buff)-1,
			&dwRead,
			NULL))
		{
			return 1;
		}

		if(dwRead==0)
			break;

		buff[dwRead]=0;
		s += buff;
	}
	return 0;
}

