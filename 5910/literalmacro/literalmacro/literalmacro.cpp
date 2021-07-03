
#if 0
#define TO_LSTRINNER(x) L##x
#define TO_LSTR(x) TO_LSTRINNER(x)

#define ABC "abc"
#define XYZ "xyz"
#define LABC xxxxxxxxxxxxxxxxxxx
#define SUM(a,b) a ## b
SUM(x, y)
SUM("x", y"a")

#define TOS(s) #s
TOS(t)
TOS("u")
TOS(333 333)

TO_LSTRINNER("vvv")
TO_LSTR("vvv")
#else
#define ABC abc
#define XYZ xyz

#define TO_STRINNER(x) #x
#define TO_STR(x) TO_STRINNER(x)

#define TO_LSTRINNERINNER(x) L ## x
#define TO_LSTRINNER(x) TO_LSTRINNERINNER(#x)
#define TO_LSTR(x) TO_LSTRINNER(x)

#endif

int main()
{
	const char* q = TO_STR(ABC) TO_STR(XYZ);
	// q is "abcxyz"

	const wchar_t* wp = TO_LSTR(ABC) TO_LSTR(XYZ);
	// wp is L"abc" L"xyz";
}

