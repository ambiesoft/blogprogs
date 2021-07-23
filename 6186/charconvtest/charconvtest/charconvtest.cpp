#include <iostream>
#include <cassert>

int main()
{
	char szA[32];
	wchar_t szW[32];
	{
		// 普通は日本語を直接こう書いてはいけない
		// 日本語環境のWindowsをつかっているとソースコードの文字コードに関わらず
		// pはcp932になる
		// 英語環境の場合はpには文字化けした文字しか入らない
		// char p[] = "あいうえお";
		// "あいうえお"のcp932での値列
		char p[] = { 0x82, 0xa0, 0x82, 0xa2, 0x82, 0xa4, 0x82, 0xa6, 0x82, 0xa8, 0x00 };
		
		// これを書かないと動かない
		// 第2引数""はユーザの環境でロケールを初期化することを意味する
		// setlocale(LC_ALL, "");  // 日本語Windowsの場合はこれでも大体動く
		setlocale(LC_ALL, ".932");  // 日本語じゃないWindowsの場合でも動く
		

		size_t converted = 0;
		int ret = mbstowcs_s(&converted, szW, p, _countof(szW) - 1);
		assert(ret == 0);
		
		// もとに戻す
		ret = wcstombs_s(&converted, szA, szW, _countof(szA) - 1);
		assert(ret == 0);
		assert(strcmp(p, szA) == 0);
	}

	{
		// こう書くのはセーフ
		// ただしソースコードをutf8で保存すること
		char p[] = u8"あいうえお";
		
		// これを書かないと動かない
		// 第2引数はUTF8でロケールを初期化することを意味する
		setlocale(LC_ALL, ".UTF8");
		
		size_t converted = 0;
		int ret = mbstowcs_s(&converted, szW, p, _countof(szW) - 1);
		assert(ret == 0);

		// もとに戻す
		ret = wcstombs_s(&converted, szA, szW, _countof(szA) - 1);
		assert(ret == 0);
		assert(strcmp(p, szA) == 0);
	}
}
