
template<typename T> size_t GetStringLength(const T* p);

extern template size_t GetStringLength<char>(const char* p);
extern template size_t GetStringLength<wchar_t>(const wchar_t* p);