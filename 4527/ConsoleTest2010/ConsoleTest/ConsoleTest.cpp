// ConsoleTest.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <Windows.h>
#include <locale.h> 
#include <io.h>
#include <fcntl.h> 
int _tmain(int argc, _TCHAR* argv[])
{
	//setlocale(LC_ALL,"zh_CN");
	_setmode( _fileno( stdin ), _O_U8TEXT );  

	wchar_t buff[30];
	fgetws(buff, 29, stdin);

	MessageBox(NULL,buff,NULL,0);
	return 0;
}

