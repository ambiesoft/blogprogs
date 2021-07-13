#include "header.h"
#include <string.h>
template<typename T> size_t GetStringLength(const T* p)
{
	if (p == nullptr)
		return 0;
	size_t size = 0;
	for (; *p; ++p)
		++size;
	return size;
}

template size_t GetStringLength<char>(const char* p);
template size_t GetStringLength<wchar_t>(const wchar_t* p);
