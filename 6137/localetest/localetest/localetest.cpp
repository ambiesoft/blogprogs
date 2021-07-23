
#include <process.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <locale>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

#define BUFF_SIZE 100

// Retrieve the date in the current
// locale's format.
int get_date(unsigned char* str)
{
    __time64_t ltime;
    struct tm  thetime;

    // Retrieve the current time
    _time64(&ltime);
    _gmtime64_s(&thetime, &ltime);

    // Format the current time structure into a string
    // "%#x" is the long date representation in the
    // current locale
    if (!strftime((char*)str, BUFF_SIZE, "%#x",
        (const struct tm*)&thetime))
    {
        printf("strftime failed!\n");
        return -1;
    }
    return 0;
}

// This thread sets its locale to the argument
// and prints the date.
uintptr_t __stdcall SecondThreadFunc(void* pArguments)
{
    unsigned char str[BUFF_SIZE];
    char* locale = (char*)pArguments;

    // Set the thread locale
    printf("The thread locale is now set to %s.\n",
        setlocale(LC_ALL, locale));

    // Retrieve the date string from the helper function
    if (get_date(str) == 0)
    {
        printf("The date in %s locale is: '%s'\n", locale, str);
    }

    _endthreadex(0);
    return 0;
}

// The main thread sets the locale to English
// and then spawns a second thread (above) and prints the date.
int main()
{
    HANDLE          hThread;
    unsigned        threadID;
    unsigned char   str[BUFF_SIZE];

    long double mon = 123.45; // or std::string mon = "123.45";
    {
        std::stringstream ss;
        ss.imbue(std::locale("en_US"));
        ss << std::showbase
            << "en_US: " << std::put_money(mon)
            << " or " << std::put_money(mon, true) << '\n';
        // "en_US: $1.23 or USD1.23\n"
    }
    {
        std::wstringstream ss;
        ss.imbue(std::locale("ja_JP.UTF8"));
        ss << u8"あ";
    }

    {
        using codecvt_wchar = std::codecvt<wchar_t, char, std::mbstate_t>;

        std::locale loc("");
        std::wstring_convert<codecvt_wchar> cv(
            &std::use_facet<codecvt_wchar>(loc));

        std::string message = "あいうえお";

        std::wstring wcs = cv.from_bytes(message);
        std::string mbs = cv.to_bytes(wcs);

        std::cout << mbs << std::endl;
    }
    {
        std::locale("ja-JP");
        char path[] = "あああ";
        std::locale::global(std::locale(""));
        //struct wchar_codecvt : public std::codecvt<wchar_t, char, std::mbstate_t> {};
        //std::wstring_convert<wchar_codecvt> converter;
        std::wstring_convert<std::codecvt<wchar_t, char, std::mbstate_t>> converter;
        std::wstring wide_path = converter.from_bytes(path);
    }
    //// ss.precision(2);
    //ss << std::put_money(;

    printf("Current locale is '%s'\n", setlocale(LC_ALL, NULL));
    printf("Locale for empty is '%s'\b", setlocale(LC_ALL, ""));


    std::locale l("de-DE");
    wchar_t szW[32];
    {
        std::locale l(".1252");
        std::locale::global(l);
        char p[] = "あ";
        // 文字化け、コードページ1252(latin1)に'あ'はない
        // ここの"あ"はソースコードの文字コードがどうであろうとANSIと解釈されるはず
        // つまり英語環境のWindowsではpはそもそも文字化けしている。
        mbtowc(szW, p, strlen(p));
    }
    {
        std::locale l(".UTF8");
        std::locale::global(l);
        char p[] = u8"あ";
        // pはUTF8
        // ちゃんと変換できる。
        mbtowc(szW, p, strlen(p));
    }

    // Enable per-thread locale causes all subsequent locale
    // setting changes in this thread to only affect this thread.
    _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);

    // Set the locale of the main thread to US English.
    printf("The thread locale is now set to %s.\n",
        setlocale(LC_ALL, "ja-JP"));

    // Create the second thread with a German locale.
    // Our thread function takes an argument of the locale to use.
    hThread = (HANDLE)_beginthreadex(NULL, 0, &SecondThreadFunc,
        (void*)"de-DE", 0, &threadID);

    if (get_date(str) == 0)
    {
        // Retrieve the date string from the helper function
        printf("The date in en-US locale is: '%s'\n\n", str);
    }

    // Wait for the created thread to finish.
    WaitForSingleObject(hThread, INFINITE);

    // Destroy the thread object.
    CloseHandle(hThread);
}