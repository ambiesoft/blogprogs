#include "header.h"
#include <string.h>
template<> size_t GetStringLength<char>(const char* p)
{
	return strlen(p);
}
template<> size_t GetStringLength<wchar_t>(const wchar_t* p)
{
	return wcslen(p);
}

template size_t GetStringLength<char>(const char* p);
template size_t GetStringLength<wchar_t>(const wchar_t* p);
