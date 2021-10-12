#include <Windows.h>

#include "../../../../lsMisc/CreateSimpleWindow.h"

using namespace Ambiesoft;

HMENU ghPopup;
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	HWND hWnd = CreateSimpleWindow();
	ghPopup = CreatePopupMenu();
	InsertMenu(ghPopup, 0, MF_BYCOMMAND, 100, L"<DUMMY>");

	POINT curPos;
	GetCursorPos(&curPos);
	SetForegroundWindow(hWnd);
	UINT cmd = TrackPopupMenu(ghPopup,
		TPM_RETURNCMD,
		curPos.x, curPos.y,
		0,
		hWnd,
		NULL);

	return 0;
}