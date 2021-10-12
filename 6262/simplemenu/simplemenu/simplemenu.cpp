#include <Windows.h>

#include "../../../../lsMisc/CreateSimpleWindow.h"

using namespace Ambiesoft;

HMENU ghPopup;
WCHAR szT[512];
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

			GetMenuString(ghPopup, dis->itemID, szT, _countof(szT), MF_BYCOMMAND);
			DrawText(dis->hDC, szT, lstrlen(szT), &dis->rcItem, 0);
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
	HWND hWnd = CreateSimpleWindow(WndProc);
	ghPopup = CreatePopupMenu();
	InsertMenu(ghPopup, 0, MF_BYCOMMAND, 100, L"<DUMMY>");
	
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