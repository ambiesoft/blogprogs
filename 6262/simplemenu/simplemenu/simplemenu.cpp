#include <Windows.h>
#include <string>
#include "../../../../lsMisc/CreateSimpleWindow.h"
#include "../../../../lsMisc/GetLastErrorString.h"

#define APPNAME L"simplemenu"

using namespace Ambiesoft;
using namespace std;


HMENU ghPopup;
WCHAR szT[512];
bool gbOwnerDraw = !false;

void ErrorExit(const wchar_t* pMessage, int ret = -1)
{
	MessageBox(nullptr,
		pMessage,
		APPNAME,
		MB_ICONERROR);
	ExitProcess(ret);
}
void ErrorExit(const wstring& message)
{
	ErrorExit(message.c_str());
}
void ErrorExit(DWORD le)
{
	ErrorExit(GetLastErrorString(le).c_str(), le);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_MEASUREITEM:
		{
			MEASUREITEMSTRUCT* mis = (MEASUREITEMSTRUCT*)lParam;
			GetMenuString(ghPopup, mis->itemID, szT, _countof(szT), MF_BYCOMMAND);
			mis->itemHeight = 16;
			mis->itemWidth = 64;
			return TRUE;
		}
		break;

		case WM_DRAWITEM:
		{
			DRAWITEMSTRUCT* dis = (DRAWITEMSTRUCT*)lParam;

			//GetMenuString(ghPopup, dis->itemID, szT, _countof(szT), MF_BYCOMMAND);
			//DrawText(dis->hDC, szT, lstrlen(szT), &dis->rcItem, 0);
			wstring scPath = L"C:\\Users\\hkIurwvKj\\AppData\\Roaming\\Microsoft\\Internet Explorer\\Quick Launch\\kocchiwork.lnk";
			SHFILEINFO sfi = { 0 };
			if (!SHGetFileInfo(scPath.c_str(),
				0,
				&sfi,
				sizeof(sfi),
				SHGFI_ICON | SHGFI_SMALLICON))
			{
				ErrorExit(GetLastError());
			}
			if (!DrawIconEx(dis->hDC, 0, 0, sfi.hIcon, 16,16,0,0, DI_MASK|DI_IMAGE))
				ErrorExit(GetLastError());

			return TRUE;
		}
		break;

		case WM_INITMENUPOPUP:
		{
			return TRUE;
		}
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	CoInitialize(NULL);

	HWND hWnd = CreateSimpleWindow(WndProc);
	ghPopup = CreatePopupMenu();
	InsertMenu(ghPopup, 0, MF_BYCOMMAND, 100, L"<DUMMY>");
	
	if (gbOwnerDraw)
	{
		// Enable OwnerDraw
		MENUITEMINFO mii;
		ZeroMemory(&mii, sizeof(mii));
		mii.cbSize = sizeof(mii);
		mii.fMask = MIIM_TYPE;
		GetMenuItemInfo(ghPopup, 100, FALSE, &mii);
		mii.cbSize = sizeof(mii);
		mii.fMask = MIIM_TYPE;
		mii.fType |= MFT_OWNERDRAW;
		SetMenuItemInfo(ghPopup, 100, FALSE, &mii);
	}

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