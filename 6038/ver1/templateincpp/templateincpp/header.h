
template<typename T> size_t GetStringLength(const T* p)
{
	// should never come here
	static_assert(sizeof(T) == 0, "only char* or wchar_t*");
}
template<> size_t GetStringLength<char>(const char* p);
template<> size_t GetStringLength<wchar_t>(const wchar_t* p);

extern template size_t GetStringLength<char>(const char* p);
extern template size_t GetStringLength<wchar_t>(const wchar_t* p);