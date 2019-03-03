

#pragma once

#pragma once

#pragma once

#pragma once

#pragma once

#pragma once

#pragma once

#pragma region Input Buffer SAL 1 compatibility macros

#pragma endregion Input Buffer SAL 1 compatibility macros

extern "C" {

}

#pragma once

extern "C" {

}

#pragma once

#pragma pack(push, 8)

extern "C" {

	typedef unsigned int uintptr_t;

	typedef char* va_list;

}

extern "C++"
{
	template <typename _Ty>
	struct __vcrt_va_list_is_reference
	{
		enum : bool { __the_value = false };
	};

	template <typename _Ty>
	struct __vcrt_va_list_is_reference<_Ty&>
	{
		enum : bool { __the_value = true };
	};

	template <typename _Ty>
	struct __vcrt_va_list_is_reference<_Ty&&>
	{
		enum : bool { __the_value = true };
	};

	template <typename _Ty>
	struct __vcrt_assert_va_start_is_not_reference
	{
		static_assert(!__vcrt_va_list_is_reference<_Ty>::__the_value,
			"va_start argument must not have reference type and must not be parenthesized");
	};
}

#pragma pack(pop)

__pragma(pack(push, 8)) extern "C" {

	typedef unsigned int     size_t;
	typedef int              ptrdiff_t;
	typedef int              intptr_t;

	typedef bool  __vcrt_bool;

	extern "C++"
	{
		template <typename _CountofType, size_t _SizeOfArray>
		char(*__countof_helper(_CountofType(&_Array)[_SizeOfArray]))[_SizeOfArray];

	}

	void __cdecl __security_init_cookie(void);

	void __fastcall __security_check_cookie(uintptr_t _StackCookie);
	__declspec(noreturn) void __cdecl __report_gsfailure(void);

	extern uintptr_t __security_cookie;

} __pragma(pack(pop))

#pragma once

__pragma(pack(push, 8)) extern "C" {

	extern "C++"
	{
		template<bool _Enable, typename _Ty>
		struct _CrtEnableIf;

		template<typename _Ty>
		struct _CrtEnableIf<true, _Ty>
		{
			typedef _Ty _Type;
		};
	}

	typedef bool  __crt_bool;

	__declspec(dllimport) void __cdecl _invalid_parameter(
		wchar_t const*,
		wchar_t const*,
		wchar_t const*,
		unsigned int,
		uintptr_t
	);

	__declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);
	__declspec(dllimport) __declspec(noreturn) void __cdecl _invalid_parameter_noinfo_noreturn(void);

	__declspec(noreturn)
		__declspec(dllimport) void __cdecl _invoke_watson(
			wchar_t const* _Expression,
			wchar_t const* _FunctionName,
			wchar_t const* _FileName,
			unsigned int _LineNo,
			uintptr_t _Reserved);

	typedef int                           errno_t;
	typedef unsigned short                wint_t;
	typedef unsigned short                wctype_t;
	typedef long                          __time32_t;
	typedef __int64                       __time64_t;

	typedef struct __crt_locale_data_public
	{
		unsigned short const* _locale_pctype;
		int _locale_mb_cur_max;
		unsigned int _locale_lc_codepage;
	} __crt_locale_data_public;

	typedef struct __crt_locale_pointers
	{
		struct __crt_locale_data*    locinfo;
		struct __crt_multibyte_data* mbcinfo;
	} __crt_locale_pointers;

	typedef __crt_locale_pointers* _locale_t;

	typedef struct _Mbstatet
	{
		unsigned long _Wchar;
		unsigned short _Byte, _State;
	} _Mbstatet;

	typedef _Mbstatet mbstate_t;

	typedef __time64_t time_t;

	typedef size_t rsize_t;

} __pragma(pack(pop))

#pragma once

#pragma once

#pragma once

extern "C++" {

#pragma pack(push, 8)

#pragma warning(push)
#pragma warning(disable: 4985) 

	namespace std
	{
		struct nothrow_t {

			explicit nothrow_t() = default;

		};

		extern nothrow_t const nothrow;

	}

	__declspec(allocator) void* __cdecl operator new(
		size_t _Size
		);

	__declspec(allocator) void* __cdecl operator new(
		size_t _Size,
		std::nothrow_t const&
		) noexcept;

	__declspec(allocator) void* __cdecl operator new[](
		size_t _Size
		);

	__declspec(allocator) void* __cdecl operator new[](
		size_t _Size,
		std::nothrow_t const&
		) noexcept;

	void __cdecl operator delete(
		void* _Block
		) noexcept;

	void __cdecl operator delete(
		void* _Block,
		std::nothrow_t const&
		) noexcept;

	void __cdecl operator delete[](
		void* _Block
		) noexcept;

	void __cdecl operator delete[](
		void* _Block,
		std::nothrow_t const&
		) noexcept;

	void __cdecl operator delete(
		void*  _Block,
		size_t _Size
		) noexcept;

	void __cdecl operator delete[](
		void* _Block,
		size_t _Size
		) noexcept;

#pragma warning(push)
#pragma warning(disable: 4577) 
#pragma warning(disable: 4514) 

	inline void* __cdecl operator new(size_t _Size, void* _Where) noexcept
	{
		(void)_Size;
		return _Where;
	}

	inline void __cdecl operator delete(void*, void*) noexcept
	{
		return;
	}

	inline void* __cdecl operator new[](size_t _Size,
		void* _Where) noexcept
	{
		(void)_Size;
		return _Where;
	}

		inline void __cdecl operator delete[](void*, void*) noexcept
	{
	}

#pragma warning(pop)

#pragma warning(pop)
#pragma pack(pop)

}

extern "C++" {

#pragma pack(push, 8)

	__declspec(allocator) void* __cdecl operator new(
		size_t      _Size,
		int         _BlockUse,
		char const* _FileName,
		int         _LineNumber
		);

	__declspec(allocator) void* __cdecl operator new[](
		size_t      _Size,
		int         _BlockUse,
		char const* _FileName,
		int         _LineNumber
		);

	void __cdecl operator delete(
		void*       _Block,
		int         _BlockUse,
		char const* _FileName,
		int         _LineNumber
		) noexcept;

	void __cdecl operator delete[](
		void*       _Block,
		int         _BlockUse,
		char const* _FileName,
		int         _LineNumber
		) noexcept;

#pragma pack(pop)

}

__pragma(pack(push, 8)) extern "C" {

	typedef void* _HFILE;

	typedef int(__cdecl* _CRT_REPORT_HOOK)(int, char*, int*);
	typedef int(__cdecl* _CRT_REPORT_HOOKW)(int, wchar_t*, int*);

	typedef int(__cdecl* _CRT_ALLOC_HOOK)(int, void*, size_t, int, long, unsigned char const*, int);

	typedef void(__cdecl* _CRT_DUMP_CLIENT)(void*, size_t);

	struct _CrtMemBlockHeader;

	typedef struct _CrtMemState
	{
		struct _CrtMemBlockHeader* pBlockHeader;
		size_t lCounts[5];
		size_t lSizes[5];
		size_t lHighWaterCount;
		size_t lTotalCount;
	} _CrtMemState;

	__declspec(dllimport) int*  __cdecl __p__crtDbgFlag(void);
	__declspec(dllimport) long* __cdecl __p__crtBreakAlloc(void);

	__declspec(dllimport) _CRT_ALLOC_HOOK __cdecl _CrtGetAllocHook(void);

	__declspec(dllimport) _CRT_ALLOC_HOOK __cdecl _CrtSetAllocHook(
		_CRT_ALLOC_HOOK _PfnNewHook
	);

	__declspec(dllimport) _CRT_DUMP_CLIENT __cdecl _CrtGetDumpClient(void);

	__declspec(dllimport) _CRT_DUMP_CLIENT __cdecl _CrtSetDumpClient(
		_CRT_DUMP_CLIENT _PFnNewDump
	);

	__declspec(dllimport) int __cdecl _CrtCheckMemory(void);

	typedef void(__cdecl* _CrtDoForAllClientObjectsCallback)(void*, void*);

	__declspec(dllimport) void __cdecl _CrtDoForAllClientObjects(
		_CrtDoForAllClientObjectsCallback _Callback,
		void*                             _Context
	);

	__declspec(dllimport) int __cdecl _CrtDumpMemoryLeaks(void);

	__declspec(dllimport) int __cdecl _CrtIsMemoryBlock(
		void const*  _Block,
		unsigned int _Size,
		long*        _RequestNumber,
		char**       _FileName,
		int*         _LineNumber
	);

	__declspec(dllimport) int __cdecl _CrtIsValidHeapPointer(
		void const* _Pointer
	);

	__declspec(dllimport) int __cdecl _CrtIsValidPointer(
		void const*  _Pointer,
		unsigned int _Size,
		int          _ReadWrite
	);

	__declspec(dllimport) void __cdecl _CrtMemCheckpoint(
		_CrtMemState* _State
	);

	__declspec(dllimport) int __cdecl _CrtMemDifference(
		_CrtMemState*       _State,
		_CrtMemState const* _OldState,
		_CrtMemState const* _NewState
	);

	__declspec(dllimport) void __cdecl _CrtMemDumpAllObjectsSince(
		_CrtMemState const* _State
	);

	__declspec(dllimport) void __cdecl _CrtMemDumpStatistics(
		_CrtMemState const* _State
	);

	__declspec(dllimport) int __cdecl _CrtReportBlockType(
		void const* _Block
	);

	__declspec(dllimport) long __cdecl _CrtSetBreakAlloc(
		long _NewValue
	);

	__declspec(dllimport) int __cdecl _CrtSetDbgFlag(
		int _NewFlag
	);

	__declspec(dllimport) void __cdecl _aligned_free_dbg(
		void* _Block
	);

	__declspec(dllimport) __declspec(allocator) void* __cdecl _aligned_malloc_dbg(
		size_t      _Size,
		size_t      _Alignment,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) size_t __cdecl _aligned_msize_dbg(
		void*  _Block,
		size_t _Alignment,
		size_t _Offset
	);

	__declspec(dllimport) __declspec(allocator) void* __cdecl _aligned_offset_malloc_dbg(
		size_t      _Size,
		size_t      _Alignment,
		size_t      _Offset,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) void* __cdecl _aligned_offset_realloc_dbg(
		void*       _Block,
		size_t      _Size,
		size_t      _Alignment,
		size_t      _Offset,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) void* __cdecl _aligned_offset_recalloc_dbg(
		void*       _Block,
		size_t      _Count,
		size_t      _Size,
		size_t      _Alignment,
		size_t      _Offset,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) void* __cdecl _aligned_realloc_dbg(
		void*       _Block,
		size_t      _Size,
		size_t      _Alignment,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) void* __cdecl _aligned_recalloc_dbg(
		void*       _Block,
		size_t      _Count,
		size_t      _Size,
		size_t      _Alignment,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) void* __cdecl _calloc_dbg(
		size_t      _Count,
		size_t      _Size,
		int         _BlockUse,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) void* __cdecl _expand_dbg(
		void*       _Block,
		size_t      _Size,
		int         _BlockUse,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) void __cdecl _free_dbg(
		void* _Block,
		int   _BlockUse
	);

	__declspec(dllimport) __declspec(allocator) void* __cdecl _malloc_dbg(
		size_t      _Size,
		int         _BlockUse,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) size_t __cdecl _msize_dbg(
		void* _Block,
		int   _BlockUse
	);

	__declspec(dllimport) __declspec(allocator) void* __cdecl _realloc_dbg(
		void*       _Block,
		size_t      _Size,
		int         _BlockUse,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) void* __cdecl _recalloc_dbg(
		void*       _Block,
		size_t      _Count,
		size_t      _Size,
		int         _BlockUse,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) errno_t __cdecl _dupenv_s_dbg(
		char** _PBuffer,
		size_t*     _PBufferSizeInBytes,
		char const* _VarName,
		int          _BlockType,
		char const* _FileName,
		int          _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) char* __cdecl _fullpath_dbg(
		char*       _FullPath,
		char const* _Path,
		size_t      _SizeInBytes,
		int         _BlockType,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) char* __cdecl _getcwd_dbg(
		char*       _DstBuf,
		int         _SizeInBytes,
		int         _BlockType,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) char* __cdecl _getdcwd_dbg(
		int         _Drive,
		char*       _DstBuf,
		int         _SizeInBytes,
		int         _BlockType,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) char* __cdecl _strdup_dbg(
		char const* _String,
		int         _BlockUse,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) char* __cdecl _tempnam_dbg(
		char const* _DirName,
		char const* _FilePrefix,
		int         _BlockType,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) wchar_t* __cdecl _wcsdup_dbg(
		wchar_t const* _String,
		int            _BlockUse,
		char const*    _FileName,
		int            _LineNumber
	);

	__declspec(dllimport) errno_t __cdecl _wdupenv_s_dbg(
		wchar_t** _PBuffer,
		size_t*         _PBufferSizeInWords,
		wchar_t const* _VarName,
		int             _BlockType,
		char const*    _FileName,
		int             _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) wchar_t* __cdecl _wfullpath_dbg(
		wchar_t*       _FullPath,
		wchar_t const* _Path,
		size_t         _SizeInWords,
		int            _BlockType,
		char const*    _FileName,
		int            _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) wchar_t* __cdecl _wgetcwd_dbg(
		wchar_t*    _DstBuf,
		int         _SizeInWords,
		int         _BlockType,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) wchar_t* __cdecl _wgetdcwd_dbg(
		int         _Drive,
		wchar_t*    _DstBuf,
		int         _SizeInWords,
		int         _BlockType,
		char const* _FileName,
		int         _LineNumber
	);

	__declspec(dllimport) __declspec(allocator) wchar_t* __cdecl _wtempnam_dbg(
		wchar_t const* _DirName,
		wchar_t const* _FilePrefix,
		int            _BlockType,
		char const*    _FileName,
		int            _LineNumber
	);

	__declspec(dllimport) int __cdecl _CrtDbgReport(
		int         _ReportType,
		char const* _FileName,
		int         _Linenumber,
		char const* _ModuleName,
		char const* _Format,
		...);

	__declspec(dllimport) int __cdecl _CrtDbgReportW(
		int            _ReportType,
		wchar_t const* _FileName,
		int            _LineNumber,
		wchar_t const* _ModuleName,
		wchar_t const* _Format,
		...);

	__declspec(dllimport) int __cdecl _VCrtDbgReportA(
		int         _ReportType,
		void*       _ReturnAddress,
		char const* _FileName,
		int         _LineNumber,
		char const* _ModuleName,
		char const* _Format,
		va_list     _ArgList
	);

	__declspec(dllimport) int __cdecl _VCrtDbgReportW(
		int            _ReportType,
		void*          _ReturnAddress,
		wchar_t const* _FileName,
		int            _LineNumber,
		wchar_t const* _ModuleName,
		wchar_t const* _Format,
		va_list        _ArgList
	);

	__declspec(dllimport) size_t __cdecl _CrtSetDebugFillThreshold(
		size_t _NewDebugFillThreshold
	);

	__declspec(dllimport) size_t __cdecl _CrtGetDebugFillThreshold(void);

	__declspec(dllimport) _HFILE __cdecl _CrtSetReportFile(
		int    _ReportType,
		_HFILE _ReportFile
	);

	__declspec(dllimport) int __cdecl _CrtSetReportMode(
		int _ReportType,
		int _ReportMode
	);

	extern long _crtAssertBusy;

	__declspec(dllimport) _CRT_REPORT_HOOK __cdecl _CrtGetReportHook(void);

	__declspec(dllimport) _CRT_REPORT_HOOK __cdecl _CrtSetReportHook(
		_CRT_REPORT_HOOK _PFnNewHook
	);

	__declspec(dllimport) int __cdecl _CrtSetReportHook2(
		int              _Mode,
		_CRT_REPORT_HOOK _PFnNewHook
	);

	__declspec(dllimport) int __cdecl _CrtSetReportHookW2(
		int               _Mode,
		_CRT_REPORT_HOOKW _PFnNewHook
	);

} __pragma(pack(pop))

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

#pragma detect_mismatch("_MSC_VER", "1900")

#pragma detect_mismatch("_ITERATOR_DEBUG_LEVEL", "2")

#pragma detect_mismatch("RuntimeLibrary", "MDd_DynamicDebug")

#pragma once

#pragma comment(lib, "msvcprt" "d" "")

namespace std {
	enum _Uninitialized
	{
		_Noinit
	};

	class __declspec(dllimport) _Lockit
	{
	public:

		__thiscall _Lockit();
		explicit __thiscall _Lockit(int);
		__thiscall ~_Lockit() noexcept;

		static  void __cdecl _Lockit_ctor(int);
		static  void __cdecl _Lockit_dtor(int);

	private:
		static  void __cdecl _Lockit_ctor(_Lockit *);
		static  void __cdecl _Lockit_ctor(_Lockit *, int);
		static  void __cdecl _Lockit_dtor(_Lockit *);

	public:
		_Lockit(const _Lockit&) = delete;
		_Lockit&  operator=(const _Lockit&) = delete;

	private:
		int _Locktype;
	};

	class __declspec(dllimport) _Init_locks
	{
	public:

		__thiscall _Init_locks();
		__thiscall ~_Init_locks() noexcept;

	private:
		static  void __cdecl _Init_locks_ctor(_Init_locks *);
		static  void __cdecl _Init_locks_dtor(_Init_locks *);
	};

}

#pragma warning(pop)
#pragma pack(pop)

#pragma once

#pragma once

#pragma once

#pragma once

__pragma(pack(push, 8)) extern "C" {

	namespace std
	{
		typedef decltype(__nullptr) nullptr_t;
	}

	using ::std::nullptr_t;

	__declspec(dllimport) int* __cdecl _errno(void);

	__declspec(dllimport) errno_t __cdecl _set_errno(int _Value);
	__declspec(dllimport) errno_t __cdecl _get_errno(int* _Value);

	__declspec(dllimport) extern unsigned long  __cdecl __threadid(void);

	__declspec(dllimport) extern uintptr_t __cdecl __threadhandle(void);

} __pragma(pack(pop))

#pragma once

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {

	template<class _Ty,
		_Ty _Val>
		struct integral_constant
	{
		static constexpr _Ty value = _Val;

		using value_type = _Ty;
		using type = integral_constant;

		constexpr operator value_type() const noexcept
		{
			return (value);
		}

		constexpr value_type operator()() const noexcept
		{
			return (value);
		}
	};

	template<bool _Val>
	using bool_constant = integral_constant<bool, _Val>;

	using true_type = bool_constant<true>;
	using false_type = bool_constant<false>;

	template<bool _Test,
		class _Ty = void>
		struct enable_if
	{
	};

	template<class _Ty>
	struct enable_if<true, _Ty>
	{
		using type = _Ty;
	};

	template<bool _Test,
		class _Ty = void>
		using enable_if_t = typename enable_if<_Test, _Ty>::type;

	template<bool _Test,
		class _Ty1,
		class _Ty2>
		struct conditional
	{
		using type = _Ty2;
	};

	template<class _Ty1,
		class _Ty2>
		struct conditional<true, _Ty1, _Ty2>
	{
		using type = _Ty1;
	};

	template<bool _Test,
		class _Ty1,
		class _Ty2>
		using conditional_t = typename conditional<_Test, _Ty1, _Ty2>::type;

	template<class _Ty1,
		class _Ty2>
		struct is_same
		: false_type
	{
	};

	template<class _Ty1>
	struct is_same<_Ty1, _Ty1>
		: true_type
	{
	};

	template<class _Ty,
		class _Uty>
		constexpr bool is_same_v = is_same<_Ty, _Uty>::value;

	template<class _Ty>
	struct remove_const
	{
		using type = _Ty;
	};

	template<class _Ty>
	struct remove_const<const _Ty>
	{
		using type = _Ty;
	};

	template<class _Ty>
	using remove_const_t = typename remove_const<_Ty>::type;

	template<class _Ty>
	struct remove_volatile
	{
		using type = _Ty;
	};

	template<class _Ty>
	struct remove_volatile<volatile _Ty>
	{
		using type = _Ty;
	};

	template<class _Ty>
	using remove_volatile_t = typename remove_volatile<_Ty>::type;

	template<class _Ty>
	struct remove_cv
	{
		using type = _Ty;
	};

	template<class _Ty>
	struct remove_cv<const _Ty>
	{
		using type = _Ty;
	};

	template<class _Ty>
	struct remove_cv<volatile _Ty>
	{
		using type = _Ty;
	};

	template<class _Ty>
	struct remove_cv<const volatile _Ty>
	{
		using type = _Ty;
	};

	template<class _Ty>
	using remove_cv_t = typename remove_cv<_Ty>::type;

	template<class _Ty>
	struct _Is_integral
		: false_type
	{
	};

	template<>
	struct _Is_integral<bool>
		: true_type
	{
	};

	template<>
	struct _Is_integral<char>
		: true_type
	{
	};

	template<>
	struct _Is_integral<unsigned char>
		: true_type
	{
	};

	template<>
	struct _Is_integral<signed char>
		: true_type
	{
	};

	template<>
	struct _Is_integral<wchar_t>
		: true_type
	{
	};

	template<>
	struct _Is_integral<char16_t>
		: true_type
	{
	};

	template<>
	struct _Is_integral<char32_t>
		: true_type
	{
	};

	template<>
	struct _Is_integral<unsigned short>
		: true_type
	{
	};

	template<>
	struct _Is_integral<short>
		: true_type
	{
	};

	template<>
	struct _Is_integral<unsigned int>
		: true_type
	{
	};

	template<>
	struct _Is_integral<int>
		: true_type
	{
	};

	template<>
	struct _Is_integral<unsigned long>
		: true_type
	{
	};

	template<>
	struct _Is_integral<long>
		: true_type
	{
	};

	template<>
	struct _Is_integral<unsigned long long>
		: true_type
	{
	};

	template<>
	struct _Is_integral<long long>
		: true_type
	{
	};

	template<class _Ty>
	struct is_integral
		: _Is_integral<remove_cv_t<_Ty>>::type
	{
	};

	template<class _Ty>
	constexpr bool is_integral_v = is_integral<_Ty>::value;

	template<class _Ty>
	struct _Is_floating_point
		: false_type
	{
	};

	template<>
	struct _Is_floating_point<float>
		: true_type
	{
	};

	template<>
	struct _Is_floating_point<double>
		: true_type
	{
	};

	template<>
	struct _Is_floating_point<long double>
		: true_type
	{
	};

	template<class _Ty>
	struct is_floating_point
		: _Is_floating_point<remove_cv_t<_Ty>>::type
	{
	};

	template<class _Ty>
	constexpr bool is_floating_point_v = is_floating_point<_Ty>::value;

	template<class _Ty>
	struct is_arithmetic
		: bool_constant<is_integral_v<_Ty>
		|| is_floating_point_v<_Ty>>
	{
	};

	template<class _Ty>
	constexpr bool is_arithmetic_v = is_arithmetic<_Ty>::value;

	template<class _Ty>
	struct remove_reference
	{
		using type = _Ty;
	};

	template<class _Ty>
	struct remove_reference<_Ty&>
	{
		using type = _Ty;
	};

	template<class _Ty>
	struct remove_reference<_Ty&&>
	{
		using type = _Ty;
	};

	template<class _Ty>
	using remove_reference_t = typename remove_reference<_Ty>::type;

}

#pragma warning(pop)
#pragma pack(pop)

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {
	using ::ptrdiff_t; using ::size_t;
	typedef double max_align_t;

}

using ::std::max_align_t;

#pragma warning(pop)
#pragma pack(pop)

#pragma once

#pragma once

#pragma once

__pragma(pack(push, 8)) extern "C" {

	__declspec(dllimport) __declspec(allocator) __declspec(restrict)
		void* __cdecl _calloc_base(
			size_t _Count,
			size_t _Size
		);

	__declspec(dllimport)  __declspec(allocator) __declspec(restrict)
		void* __cdecl calloc(
			size_t _Count,
			size_t _Size
		);

	__declspec(dllimport) int __cdecl _callnewh(
		size_t _Size
	);

	__declspec(dllimport) __declspec(allocator)
		void* __cdecl _expand(
			void*  _Block,
			size_t _Size
		);

	__declspec(dllimport)
		void __cdecl _free_base(
			void* _Block
		);

	__declspec(dllimport)
		void __cdecl free(
			void* _Block
		);

	__declspec(dllimport) __declspec(allocator) __declspec(restrict)
		void* __cdecl _malloc_base(
			size_t _Size
		);

	__declspec(dllimport) __declspec(allocator)  __declspec(restrict)
		void* __cdecl malloc(
			size_t _Size
		);

	__declspec(dllimport)
		size_t __cdecl _msize_base(
			void* _Block
		);

	__declspec(dllimport)
		size_t __cdecl _msize(
			void* _Block
		);

	__declspec(dllimport) __declspec(allocator) __declspec(restrict)
		void* __cdecl _realloc_base(
			void*  _Block,
			size_t _Size
		);

	__declspec(dllimport) __declspec(allocator) __declspec(restrict)
		void* __cdecl realloc(
			void*  _Block,
			size_t _Size
		);

	__declspec(dllimport) __declspec(allocator) __declspec(restrict)
		void* __cdecl _recalloc_base(
			void*  _Block,
			size_t _Count,
			size_t _Size
		);

	__declspec(dllimport) __declspec(allocator) __declspec(restrict)
		void* __cdecl _recalloc(
			void*  _Block,
			size_t _Count,
			size_t _Size
		);

	__declspec(dllimport)
		void __cdecl _aligned_free(
			void* _Block
		);

	__declspec(dllimport) __declspec(allocator) __declspec(restrict)
		void* __cdecl _aligned_malloc(
			size_t _Size,
			size_t _Alignment
		);

	__declspec(dllimport) __declspec(allocator) __declspec(restrict)
		void* __cdecl _aligned_offset_malloc(
			size_t _Size,
			size_t _Alignment,
			size_t _Offset
		);

	__declspec(dllimport)
		size_t __cdecl _aligned_msize(
			void*  _Block,
			size_t _Alignment,
			size_t _Offset
		);

	__declspec(dllimport) __declspec(allocator) __declspec(restrict)
		void* __cdecl _aligned_offset_realloc(
			void*  _Block,
			size_t _Size,
			size_t _Alignment,
			size_t _Offset
		);

	__declspec(dllimport) __declspec(allocator) __declspec(restrict)
		void* __cdecl _aligned_offset_recalloc(
			void*  _Block,
			size_t _Count,
			size_t _Size,
			size_t _Alignment,
			size_t _Offset
		);

	__declspec(dllimport) __declspec(allocator) __declspec(restrict)
		void* __cdecl _aligned_realloc(
			void*  _Block,
			size_t _Size,
			size_t _Alignment
		);

	__declspec(dllimport) __declspec(allocator) __declspec(restrict)
		void* __cdecl _aligned_recalloc(
			void*  _Block,
			size_t _Count,
			size_t _Size,
			size_t _Alignment
		);

} __pragma(pack(pop))

#pragma once

__pragma(pack(push, 8)) extern "C" {

	typedef int(__cdecl* _CoreCrtSecureSearchSortCompareFunction)(void*, void const*, void const*);
	typedef int(__cdecl* _CoreCrtNonSecureSearchSortCompareFunction)(void const*, void const*);

	__declspec(dllimport) void* __cdecl bsearch_s(
		void const* _Key,
		void const* _Base,
		rsize_t     _NumOfElements,
		rsize_t     _SizeOfElements,
		_CoreCrtSecureSearchSortCompareFunction _CompareFunction,
		void*       _Context
	);

	__declspec(dllimport) void __cdecl qsort_s(
		void*   _Base,
		rsize_t _NumOfElements,
		rsize_t _SizeOfElements,
		_CoreCrtSecureSearchSortCompareFunction _CompareFunction,
		void*   _Context
	);

	__declspec(dllimport) void* __cdecl bsearch(
		void const* _Key,
		void const* _Base,
		size_t      _NumOfElements,
		size_t      _SizeOfElements,
		_CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
	);

	__declspec(dllimport) void __cdecl qsort(
		void*  _Base,
		size_t _NumOfElements,
		size_t _SizeOfElements,
		_CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
	);

	__declspec(dllimport) void* __cdecl _lfind_s(
		void const*   _Key,
		void const*   _Base,
		unsigned int* _NumOfElements,
		size_t        _SizeOfElements,
		_CoreCrtSecureSearchSortCompareFunction _CompareFunction,
		void*         _Context
	);

	__declspec(dllimport) void* __cdecl _lfind(
		void const*   _Key,
		void const*   _Base,
		unsigned int* _NumOfElements,
		unsigned int  _SizeOfElements,
		_CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
	);

	__declspec(dllimport) void* __cdecl _lsearch_s(
		void const*   _Key,
		void*         _Base,
		unsigned int* _NumOfElements,
		size_t        _SizeOfElements,
		_CoreCrtSecureSearchSortCompareFunction _CompareFunction,
		void*         _Context
	);

	__declspec(dllimport) void* __cdecl _lsearch(
		void const*   _Key,
		void*         _Base,
		unsigned int* _NumOfElements,
		unsigned int  _SizeOfElements,
		_CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
	);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_lfind" ". See online help for details."))
		__declspec(dllimport) void* __cdecl lfind(
			void const*   _Key,
			void const*   _Base,
			unsigned int* _NumOfElements,
			unsigned int  _SizeOfElements,
			_CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_lsearch" ". See online help for details."))
		__declspec(dllimport) void* __cdecl lsearch(
			void const*   _Key,
			void*         _Base,
			unsigned int* _NumOfElements,
			unsigned int  _SizeOfElements,
			_CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
		);

} __pragma(pack(pop))

#pragma once

__pragma(pack(push, 8)) extern "C" {

	__declspec(dllimport) errno_t __cdecl _itow_s(
		int      _Value,
		wchar_t* _Buffer,
		size_t   _BufferCount,
		int      _Radix
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _itow_s(int _Value, wchar_t(&_Buffer)[_Size], int _Radix) throw() { return _itow_s(_Value, _Buffer, _Size, _Radix); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_itow_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl _itow(int _Value, wchar_t *_Buffer, int _Radix);

	__declspec(dllimport) errno_t __cdecl _ltow_s(
		long     _Value,
		wchar_t* _Buffer,
		size_t   _BufferCount,
		int      _Radix
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _ltow_s(long _Value, wchar_t(&_Buffer)[_Size], int _Radix) throw() { return _ltow_s(_Value, _Buffer, _Size, _Radix); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_ltow_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl _ltow(long _Value, wchar_t *_Buffer, int _Radix);

	__declspec(dllimport) errno_t __cdecl _ultow_s(
		unsigned long _Value,
		wchar_t*      _Buffer,
		size_t        _BufferCount,
		int           _Radix
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _ultow_s(unsigned long _Value, wchar_t(&_Buffer)[_Size], int _Radix) throw() { return _ultow_s(_Value, _Buffer, _Size, _Radix); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_ultow_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl _ultow(unsigned long _Value, wchar_t *_Buffer, int _Radix);

	__declspec(dllimport) double __cdecl wcstod(
		wchar_t const* _String,
		wchar_t**      _EndPtr
	);

	__declspec(dllimport) double __cdecl _wcstod_l(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		_locale_t      _Locale
	);

	__declspec(dllimport) long __cdecl wcstol(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		int            _Radix
	);

	__declspec(dllimport) long __cdecl _wcstol_l(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		int            _Radix,
		_locale_t      _Locale
	);

	__declspec(dllimport) long long __cdecl wcstoll(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		int            _Radix
	);

	__declspec(dllimport) long long __cdecl _wcstoll_l(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		int            _Radix,
		_locale_t      _Locale
	);

	__declspec(dllimport) unsigned long __cdecl wcstoul(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		int            _Radix
	);

	__declspec(dllimport) unsigned long __cdecl _wcstoul_l(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		int            _Radix,
		_locale_t      _Locale
	);

	__declspec(dllimport) unsigned long long __cdecl wcstoull(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		int            _Radix
	);

	__declspec(dllimport) unsigned long long __cdecl _wcstoull_l(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		int            _Radix,
		_locale_t      _Locale
	);

	__declspec(dllimport) long double __cdecl wcstold(
		wchar_t const* _String,
		wchar_t**      _EndPtr
	);

	__declspec(dllimport) long double __cdecl _wcstold_l(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		_locale_t      _Locale
	);

	__declspec(dllimport) float __cdecl wcstof(
		wchar_t const* _String,
		wchar_t**      _EndPtr
	);

	__declspec(dllimport) float __cdecl _wcstof_l(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		_locale_t      _Locale
	);

	__declspec(dllimport) double __cdecl _wtof(
		wchar_t const* _String
	);

	__declspec(dllimport) double __cdecl _wtof_l(
		wchar_t const* _String,
		_locale_t      _Locale
	);

	__declspec(dllimport) int __cdecl _wtoi(
		wchar_t const* _String
	);

	__declspec(dllimport) int __cdecl _wtoi_l(
		wchar_t const* _String,
		_locale_t      _Locale
	);

	__declspec(dllimport) long __cdecl _wtol(
		wchar_t const* _String
	);

	__declspec(dllimport) long __cdecl _wtol_l(
		wchar_t const* _String,
		_locale_t      _Locale
	);

	__declspec(dllimport) long long __cdecl _wtoll(
		wchar_t const* _String
	);

	__declspec(dllimport) long long __cdecl _wtoll_l(
		wchar_t const* _String,
		_locale_t      _Locale
	);

	__declspec(dllimport) errno_t __cdecl _i64tow_s(
		__int64  _Value,
		wchar_t* _Buffer,
		size_t   _BufferCount,
		int      _Radix
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_i64tow_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) wchar_t* __cdecl _i64tow(
			__int64  _Value,
			wchar_t* _Buffer,
			int      _Radix
		);

	__declspec(dllimport) errno_t __cdecl _ui64tow_s(
		unsigned __int64 _Value,
		wchar_t*         _Buffer,
		size_t           _BufferCount,
		int              _Radix
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_ui64tow_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) wchar_t* __cdecl _ui64tow(
			unsigned __int64 _Value,
			wchar_t*         _Buffer,
			int              _Radix
		);

	__declspec(dllimport) __int64 __cdecl _wtoi64(
		wchar_t const* _String
	);

	__declspec(dllimport) __int64 __cdecl _wtoi64_l(
		wchar_t const* _String,
		_locale_t      _Locale
	);

	__declspec(dllimport) __int64 __cdecl _wcstoi64(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		int            _Radix
	);

	__declspec(dllimport) __int64 __cdecl _wcstoi64_l(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		int            _Radix,
		_locale_t      _Locale
	);

	__declspec(dllimport) unsigned __int64 __cdecl _wcstoui64(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		int            _Radix
	);

	__declspec(dllimport) unsigned __int64 __cdecl _wcstoui64_l(
		wchar_t const* _String,
		wchar_t**      _EndPtr,
		int            _Radix,
		_locale_t      _Locale
	);

	__declspec(dllimport) __declspec(allocator) wchar_t* __cdecl _wfullpath(
		wchar_t*       _Buffer,
		wchar_t const* _Path,
		size_t         _BufferCount
	);

	__declspec(dllimport) errno_t __cdecl _wmakepath_s(
		wchar_t*       _Buffer,
		size_t         _BufferCount,
		wchar_t const* _Drive,
		wchar_t const* _Dir,
		wchar_t const* _Filename,
		wchar_t const* _Ext
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wmakepath_s(wchar_t(&_Buffer)[_Size], wchar_t const* _Drive, wchar_t const* _Dir, wchar_t const* _Filename, wchar_t const* _Ext) throw() { return _wmakepath_s(_Buffer, _Size, _Drive, _Dir, _Filename, _Ext); } }

#pragma warning(push)
#pragma warning(disable: 28719) 
#pragma warning(disable: 28726) 
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wmakepath_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) void __cdecl _wmakepath(wchar_t *_Buffer, wchar_t const* _Drive, wchar_t const* _Dir, wchar_t const* _Filename, wchar_t const* _Ext);

#pragma warning(pop)

	__declspec(dllimport) void __cdecl _wperror(
		wchar_t const* _ErrorMessage
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wsplitpath_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) void __cdecl _wsplitpath(
			wchar_t const* _FullPath,
			wchar_t*       _Drive,
			wchar_t*       _Dir,
			wchar_t*       _Filename,
			wchar_t*       _Ext
		);

	__declspec(dllimport) errno_t __cdecl _wsplitpath_s(
		wchar_t const* _FullPath,
		wchar_t*       _Drive,
		size_t         _DriveCount,
		wchar_t*       _Dir,
		size_t         _DirCount,
		wchar_t*       _Filename,
		size_t         _FilenameCount,
		wchar_t*       _Ext,
		size_t         _ExtCount
	);

	extern "C++" { template <size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize> inline errno_t __cdecl _wsplitpath_s(wchar_t const* _Path, wchar_t(&_Drive)[_DriveSize], wchar_t(&_Dir)[_DirSize], wchar_t(&_Name)[_NameSize], wchar_t(&_Ext)[_ExtSize]) throw() { return _wsplitpath_s(_Path, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize); } }

	__declspec(dllimport) errno_t __cdecl _wdupenv_s(
		wchar_t**      _Buffer,
		size_t*        _BufferCount,
		wchar_t const* _VarName
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wdupenv_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) wchar_t* __cdecl _wgetenv(
			wchar_t const* _VarName
		);

	__declspec(dllimport) errno_t __cdecl _wgetenv_s(
		size_t*        _RequiredCount,
		wchar_t*       _Buffer,
		size_t         _BufferCount,
		wchar_t const* _VarName
	);

	extern "C++" { template <size_t _Size> inline   errno_t __cdecl _wgetenv_s(size_t* _RequiredCount, wchar_t(&_Buffer)[_Size], wchar_t const* _VarName) throw() { return _wgetenv_s(_RequiredCount, _Buffer, _Size, _VarName); } }

	__declspec(dllimport) int __cdecl _wputenv(
		wchar_t const* _EnvString
	);

	__declspec(dllimport) errno_t __cdecl _wputenv_s(
		wchar_t const* _Name,
		wchar_t const* _Value
	);

	__declspec(dllimport) errno_t __cdecl _wsearchenv_s(
		wchar_t const* _Filename,
		wchar_t const* _VarName,
		wchar_t*       _Buffer,
		size_t         _BufferCount
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wsearchenv_s(wchar_t const* _Filename, wchar_t const* _VarName, wchar_t(&_ResultPath)[_Size]) throw() { return _wsearchenv_s(_Filename, _VarName, _ResultPath, _Size); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wsearchenv_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) void __cdecl _wsearchenv(wchar_t const* _Filename, wchar_t const* _VarName, wchar_t *_ResultPath);

	__declspec(dllimport) int __cdecl _wsystem(
		wchar_t const* _Command
	);

} __pragma(pack(pop))

#pragma once

__pragma(pack(push, 8)) extern "C" {

} __pragma(pack(pop))

__pragma(pack(push, 8)) extern "C" {

	__declspec(dllimport) void __cdecl _swab(
		char* _Buf1,
		char* _Buf2,
		int   _SizeInBytes
	);

	__declspec(dllimport) __declspec(noreturn) void __cdecl exit(int _Code);
	__declspec(dllimport) __declspec(noreturn) void __cdecl _exit(int _Code);
	__declspec(dllimport) __declspec(noreturn) void __cdecl _Exit(int _Code);
	__declspec(dllimport) __declspec(noreturn) void __cdecl quick_exit(int _Code);
	__declspec(dllimport) __declspec(noreturn) void __cdecl abort(void);

	__declspec(dllimport) unsigned int __cdecl _set_abort_behavior(
		unsigned int _Flags,
		unsigned int _Mask
	);

	typedef int(__cdecl* _onexit_t)(void);

	int       __cdecl atexit(void(__cdecl*)(void));
	_onexit_t __cdecl _onexit(_onexit_t _Func);

	int __cdecl at_quick_exit(void(__cdecl*)(void));

	typedef void(__cdecl* _purecall_handler)(void);

	typedef void(__cdecl* _invalid_parameter_handler)(
		wchar_t const*,
		wchar_t const*,
		wchar_t const*,
		unsigned int,
		uintptr_t
		);

	_purecall_handler __cdecl _set_purecall_handler(
		_purecall_handler _Handler
	);

	_purecall_handler __cdecl _get_purecall_handler(void);

	__declspec(dllimport) _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(
		_invalid_parameter_handler _Handler
	);

	__declspec(dllimport) _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);

	__declspec(dllimport) _invalid_parameter_handler __cdecl _set_thread_local_invalid_parameter_handler(
		_invalid_parameter_handler _Handler
	);

	__declspec(dllimport) _invalid_parameter_handler __cdecl _get_thread_local_invalid_parameter_handler(void);

	__declspec(dllimport) int __cdecl _set_error_mode(int _Mode);

	__declspec(dllimport) int* __cdecl _errno(void);

	__declspec(dllimport) errno_t __cdecl _set_errno(int _Value);
	__declspec(dllimport) errno_t __cdecl _get_errno(int* _Value);

	__declspec(dllimport) unsigned long* __cdecl __doserrno(void);

	__declspec(dllimport) errno_t __cdecl _set_doserrno(unsigned long _Value);
	__declspec(dllimport) errno_t __cdecl _get_doserrno(unsigned long * _Value);

	__declspec(dllimport) __declspec(deprecated("This function or variable may be unsafe. Consider using " "strerror" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) char** __cdecl __sys_errlist(void);

	__declspec(dllimport) __declspec(deprecated("This function or variable may be unsafe. Consider using " "strerror" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) int * __cdecl __sys_nerr(void);

	__declspec(dllimport) void __cdecl perror(char const* _ErrMsg);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_get_pgmptr" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) char**    __cdecl __p__pgmptr(void);
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_get_wpgmptr" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t** __cdecl __p__wpgmptr(void);
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_get_fmode" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) int*      __cdecl __p__fmode(void);

	__declspec(dllimport) errno_t __cdecl _get_pgmptr(char**    _Value);

	__declspec(dllimport) errno_t __cdecl _get_wpgmptr(wchar_t** _Value);

	__declspec(dllimport) errno_t __cdecl _set_fmode(int       _Mode);

	__declspec(dllimport) errno_t __cdecl _get_fmode(int*      _PMode);

	typedef struct _div_t
	{
		int quot;
		int rem;
	} div_t;

	typedef struct _ldiv_t
	{
		long quot;
		long rem;
	} ldiv_t;

	typedef struct _lldiv_t
	{
		long long quot;
		long long rem;
	} lldiv_t;

	int       __cdecl abs(int       _Number);
	long      __cdecl labs(long      _Number);
	long long __cdecl llabs(long long _Number);
	__int64   __cdecl _abs64(__int64   _Number);

	unsigned short   __cdecl _byteswap_ushort(unsigned short   _Number);
	unsigned long    __cdecl _byteswap_ulong(unsigned long    _Number);
	unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Number);

	__declspec(dllimport) div_t   __cdecl div(int       _Numerator, int       _Denominator);
	__declspec(dllimport) ldiv_t  __cdecl ldiv(long      _Numerator, long      _Denominator);
	__declspec(dllimport) lldiv_t __cdecl lldiv(long long _Numerator, long long _Denominator);

#pragma warning (push)
#pragma warning (disable:6540)

	unsigned int __cdecl _rotl(
		unsigned int _Value,
		int          _Shift
	);

	unsigned long __cdecl _lrotl(
		unsigned long _Value,
		int           _Shift
	);

	unsigned __int64 __cdecl _rotl64(
		unsigned __int64 _Value,
		int              _Shift
	);

	unsigned int __cdecl _rotr(
		unsigned int _Value,
		int          _Shift
	);

	unsigned long __cdecl _lrotr(
		unsigned long _Value,
		int           _Shift
	);

	unsigned __int64 __cdecl _rotr64(
		unsigned __int64 _Value,
		int              _Shift
	);

#pragma warning (pop)

	__declspec(dllimport) void __cdecl srand(unsigned int _Seed);

	__declspec(dllimport) int __cdecl rand(void);

	extern "C++"
	{
		inline long abs(long const _X) throw()
		{
			return labs(_X);
		}

		inline long long abs(long long const _X) throw()
		{
			return llabs(_X);
		}

		inline ldiv_t div(long const _A1, long const _A2) throw()
		{
			return ldiv(_A1, _A2);
		}

		inline lldiv_t div(long long const _A1, long long const _A2) throw()
		{
			return lldiv(_A1, _A2);
		}
	}

#pragma pack(push, 4)
	typedef struct
	{
		unsigned char ld[10];
	} _LDOUBLE;
#pragma pack(pop)

	typedef struct
	{
		double x;
	} _CRT_DOUBLE;

	typedef struct
	{
		float f;
	} _CRT_FLOAT;

	typedef struct
	{
		long double x;
	} _LONGDOUBLE;

#pragma pack(push, 4)
	typedef struct
	{
		unsigned char ld12[12];
	} _LDBL12;
#pragma pack(pop)

	__declspec(dllimport) double    __cdecl atof(char const* _String);
	__declspec(dllimport) int       __cdecl atoi(char const* _String);
	__declspec(dllimport) long      __cdecl atol(char const* _String);
	__declspec(dllimport) long long __cdecl atoll(char const* _String);
	__declspec(dllimport) __int64   __cdecl _atoi64(char const* _String);

	__declspec(dllimport) double    __cdecl _atof_l(char const* _String, _locale_t _Locale);
	__declspec(dllimport) int       __cdecl _atoi_l(char const* _String, _locale_t _Locale);
	__declspec(dllimport) long      __cdecl _atol_l(char const* _String, _locale_t _Locale);
	__declspec(dllimport) long long __cdecl _atoll_l(char const* _String, _locale_t _Locale);
	__declspec(dllimport) __int64   __cdecl _atoi64_l(char const* _String, _locale_t _Locale);

	__declspec(dllimport) int __cdecl _atoflt(_CRT_FLOAT*  _Result, char const* _String);
	__declspec(dllimport) int __cdecl _atodbl(_CRT_DOUBLE* _Result, char*       _String);
	__declspec(dllimport) int __cdecl _atoldbl(_LDOUBLE*    _Result, char*       _String);

	__declspec(dllimport) int __cdecl _atoflt_l(
		_CRT_FLOAT* _Result,
		char const* _String,
		_locale_t   _Locale
	);

	__declspec(dllimport) int __cdecl _atodbl_l(
		_CRT_DOUBLE* _Result,
		char*        _String,
		_locale_t    _Locale
	);

	__declspec(dllimport) int __cdecl _atoldbl_l(
		_LDOUBLE* _Result,
		char*     _String,
		_locale_t _Locale
	);

	__declspec(dllimport) float __cdecl strtof(
		char const* _String,
		char**      _EndPtr
	);

	__declspec(dllimport) float __cdecl _strtof_l(
		char const* _String,
		char**      _EndPtr,
		_locale_t   _Locale
	);

	__declspec(dllimport) double __cdecl strtod(
		char const* _String,
		char**      _EndPtr
	);

	__declspec(dllimport) double __cdecl _strtod_l(
		char const* _String,
		char**      _EndPtr,
		_locale_t   _Locale
	);

	__declspec(dllimport) long double __cdecl strtold(
		char const* _String,
		char**      _EndPtr
	);

	__declspec(dllimport) long double __cdecl _strtold_l(
		char const* _String,
		char**      _EndPtr,
		_locale_t   _Locale
	);

	__declspec(dllimport) long __cdecl strtol(
		char const* _String,
		char**      _EndPtr,
		int         _Radix
	);

	__declspec(dllimport) long __cdecl _strtol_l(
		char const* _String,
		char**      _EndPtr,
		int         _Radix,
		_locale_t   _Locale
	);

	__declspec(dllimport) long long __cdecl strtoll(
		char const* _String,
		char**      _EndPtr,
		int         _Radix
	);

	__declspec(dllimport) long long __cdecl _strtoll_l(
		char const* _String,
		char**      _EndPtr,
		int         _Radix,
		_locale_t   _Locale
	);

	__declspec(dllimport) unsigned long __cdecl strtoul(
		char const* _String,
		char**      _EndPtr,
		int         _Radix
	);

	__declspec(dllimport) unsigned long __cdecl _strtoul_l(
		char const* _String,
		char**      _EndPtr,
		int         _Radix,
		_locale_t   _Locale
	);

	__declspec(dllimport) unsigned long long __cdecl strtoull(
		char const* _String,
		char**      _EndPtr,
		int         _Radix
	);

	__declspec(dllimport) unsigned long long __cdecl _strtoull_l(
		char const* _String,
		char**      _EndPtr,
		int         _Radix,
		_locale_t   _Locale
	);

	__declspec(dllimport) __int64 __cdecl _strtoi64(
		char const* _String,
		char**      _EndPtr,
		int         _Radix
	);

	__declspec(dllimport) __int64 __cdecl _strtoi64_l(
		char const* _String,
		char**      _EndPtr,
		int         _Radix,
		_locale_t   _Locale
	);

	__declspec(dllimport) unsigned __int64 __cdecl _strtoui64(
		char const* _String,
		char**      _EndPtr,
		int         _Radix
	);

	__declspec(dllimport) unsigned __int64 __cdecl _strtoui64_l(
		char const* _String,
		char**      _EndPtr,
		int         _Radix,
		_locale_t   _Locale
	);

	__declspec(dllimport) errno_t __cdecl _itoa_s(
		int    _Value,
		char*  _Buffer,
		size_t _BufferCount,
		int    _Radix
	);

	extern "C++" { template <size_t _Size> inline   errno_t __cdecl _itoa_s(int _Value, char(&_Buffer)[_Size], int _Radix) throw() { return _itoa_s(_Value, _Buffer, _Size, _Radix); } }

#pragma warning(push)
#pragma warning(disable: 28719) 
#pragma warning(disable: 28726) 
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_itoa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) char* __cdecl _itoa(int _Value, char *_Buffer, int _Radix);

#pragma warning(pop)

	__declspec(dllimport) errno_t __cdecl _ltoa_s(
		long   _Value,
		char*  _Buffer,
		size_t _BufferCount,
		int    _Radix
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _ltoa_s(long _Value, char(&_Buffer)[_Size], int _Radix) throw() { return _ltoa_s(_Value, _Buffer, _Size, _Radix); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_ltoa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) char* __cdecl _ltoa(long _Value, char *_Buffer, int _Radix);

	__declspec(dllimport) errno_t __cdecl _ultoa_s(
		unsigned long _Value,
		char*         _Buffer,
		size_t        _BufferCount,
		int           _Radix
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _ultoa_s(unsigned long _Value, char(&_Buffer)[_Size], int _Radix) throw() { return _ultoa_s(_Value, _Buffer, _Size, _Radix); } }

#pragma warning(push)
#pragma warning(disable: 28726) 
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_ultoa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) char* __cdecl _ultoa(unsigned long _Value, char *_Buffer, int _Radix);

#pragma warning(pop)

	__declspec(dllimport) errno_t __cdecl _i64toa_s(
		__int64 _Value,
		char*   _Buffer,
		size_t  _BufferCount,
		int     _Radix
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_i64toa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl _i64toa(
			__int64 _Value,
			char*   _Buffer,
			int     _Radix
		);

	__declspec(dllimport) errno_t __cdecl _ui64toa_s(
		unsigned __int64 _Value,
		char*            _Buffer,
		size_t           _BufferCount,
		int              _Radix
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_ui64toa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl _ui64toa(
			unsigned __int64 _Value,
			char*            _Buffer,
			int              _Radix
		);

	__declspec(dllimport) errno_t __cdecl _ecvt_s(
		char* _Buffer,
		size_t                       _BufferCount,
		double                       _Value,
		int                          _DigitCount,
		int*                         _PtDec,
		int*                         _PtSign
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _ecvt_s(char(&_Buffer)[_Size], double _Value, int _DigitCount, int* _PtDec, int* _PtSign) throw() { return _ecvt_s(_Buffer, _Size, _Value, _DigitCount, _PtDec, _PtSign); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_ecvt_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl _ecvt(
			double _Value,
			int    _DigitCount,
			int*   _PtDec,
			int*   _PtSign
		);

	__declspec(dllimport) errno_t __cdecl _fcvt_s(
		char*  _Buffer,
		size_t _BufferCount,
		double _Value,
		int    _FractionalDigitCount,
		int*   _PtDec,
		int*   _PtSign
	);

	extern "C++" { template <size_t _Size> inline   errno_t __cdecl _fcvt_s(char(&_Buffer)[_Size], double _Value, int _FractionalDigitCount, int* _PtDec, int* _PtSign) throw() { return _fcvt_s(_Buffer, _Size, _Value, _FractionalDigitCount, _PtDec, _PtSign); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_fcvt_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl _fcvt(
			double _Value,
			int    _FractionalDigitCount,
			int*   _PtDec,
			int*   _PtSign
		);

	__declspec(dllimport) errno_t __cdecl _gcvt_s(
		char*  _Buffer,
		size_t _BufferCount,
		double _Value,
		int    _DigitCount
	);

	extern "C++" { template <size_t _Size> inline   errno_t __cdecl _gcvt_s(char(&_Buffer)[_Size], double _Value, int _DigitCount) throw() { return _gcvt_s(_Buffer, _Size, _Value, _DigitCount); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_gcvt_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl _gcvt(
			double _Value,
			int    _DigitCount,
			char*  _Buffer
		);

	__declspec(dllimport) int __cdecl ___mb_cur_max_func(void);

	__declspec(dllimport) int __cdecl ___mb_cur_max_l_func(_locale_t _Locale);

	__declspec(dllimport) int __cdecl mblen(
		char const* _Ch,
		size_t      _MaxCount
	);

	__declspec(dllimport) int __cdecl _mblen_l(
		char const* _Ch,
		size_t      _MaxCount,
		_locale_t   _Locale
	);

	__declspec(dllimport) size_t __cdecl _mbstrlen(
		char const* _String
	);

	__declspec(dllimport) size_t __cdecl _mbstrlen_l(
		char const* _String,
		_locale_t   _Locale
	);

	__declspec(dllimport) size_t __cdecl _mbstrnlen(
		char const* _String,
		size_t      _MaxCount
	);

	__declspec(dllimport) size_t __cdecl _mbstrnlen_l(
		char const* _String,
		size_t      _MaxCount,
		_locale_t   _Locale
	);

	__declspec(dllimport) int __cdecl mbtowc(
		wchar_t*    _DstCh,
		char const* _SrcCh,
		size_t      _SrcSizeInBytes
	);

	__declspec(dllimport) int __cdecl _mbtowc_l(
		wchar_t*    _DstCh,
		char const* _SrcCh,
		size_t      _SrcSizeInBytes,
		_locale_t   _Locale
	);

	__declspec(dllimport) errno_t __cdecl mbstowcs_s(
		size_t*     _PtNumOfCharConverted,
		wchar_t*    _DstBuf,
		size_t      _SizeInWords,
		char const* _SrcBuf,
		size_t      _MaxCount
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl mbstowcs_s(size_t* _PtNumOfCharConverted, wchar_t(&_Dest)[_Size], char const* _Source, size_t _MaxCount) throw() { return mbstowcs_s(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "mbstowcs_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) size_t __cdecl mbstowcs(wchar_t *_Dest, char const* _Source, size_t _MaxCount);

	__declspec(dllimport) errno_t __cdecl _mbstowcs_s_l(
		size_t*     _PtNumOfCharConverted,
		wchar_t*    _DstBuf,
		size_t      _SizeInWords,
		char const* _SrcBuf,
		size_t      _MaxCount,
		_locale_t   _Locale
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _mbstowcs_s_l(size_t* _PtNumOfCharConverted, wchar_t(&_Dest)[_Size], char const* _Source, size_t _MaxCount, _locale_t _Locale) throw() { return _mbstowcs_s_l(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_mbstowcs_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) size_t __cdecl _mbstowcs_l(wchar_t *_Dest, char const* _Source, size_t _MaxCount, _locale_t _Locale);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "wctomb_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) int __cdecl wctomb(
			char*   _MbCh,
			wchar_t _WCh
		);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wctomb_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) int __cdecl _wctomb_l(
			char*     _MbCh,
			wchar_t   _WCh,
			_locale_t _Locale
		);

	__declspec(dllimport) errno_t __cdecl wctomb_s(
		int*    _SizeConverted,
		char*   _MbCh,
		rsize_t _SizeInBytes,
		wchar_t _WCh
	);

	__declspec(dllimport) errno_t __cdecl _wctomb_s_l(
		int*     _SizeConverted,
		char*     _MbCh,
		size_t    _SizeInBytes,
		wchar_t   _WCh,
		_locale_t _Locale);

	__declspec(dllimport) errno_t __cdecl wcstombs_s(
		size_t*        _PtNumOfCharConverted,
		char*          _Dst,
		size_t         _DstSizeInBytes,
		wchar_t const* _Src,
		size_t         _MaxCountInBytes
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl wcstombs_s(size_t* _PtNumOfCharConverted, char(&_Dest)[_Size], wchar_t const* _Source, size_t _MaxCount) throw() { return wcstombs_s(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcstombs_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) size_t __cdecl wcstombs(char *_Dest, wchar_t const* _Source, size_t _MaxCount);

	__declspec(dllimport) errno_t __cdecl _wcstombs_s_l(
		size_t*        _PtNumOfCharConverted,
		char*          _Dst,
		size_t         _DstSizeInBytes,
		wchar_t const* _Src,
		size_t         _MaxCountInBytes,
		_locale_t      _Locale
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcstombs_s_l(size_t* _PtNumOfCharConverted, char(&_Dest)[_Size], wchar_t const* _Source, size_t _MaxCount, _locale_t _Locale) throw() { return _wcstombs_s_l(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcstombs_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) size_t __cdecl _wcstombs_l(char *_Dest, wchar_t const* _Source, size_t _MaxCount, _locale_t _Locale);

	__declspec(dllimport) __declspec(allocator) char* __cdecl _fullpath(
		char*       _Buffer,
		char const* _Path,
		size_t      _BufferCount
	);

	__declspec(dllimport) errno_t __cdecl _makepath_s(
		char*       _Buffer,
		size_t      _BufferCount,
		char const* _Drive,
		char const* _Dir,
		char const* _Filename,
		char const* _Ext
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _makepath_s(char(&_Buffer)[_Size], char const* _Drive, char const* _Dir, char const* _Filename, char const* _Ext) throw() { return _makepath_s(_Buffer, _Size, _Drive, _Dir, _Filename, _Ext); } }

#pragma warning(push)
#pragma warning(disable: 28719) 
#pragma warning(disable: 28726) 
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_makepath_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) void __cdecl _makepath(char *_Buffer, char const* _Drive, char const* _Dir, char const* _Filename, char const* _Ext);

#pragma warning(pop)

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_splitpath_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) void __cdecl _splitpath(
			char const* _FullPath,
			char*       _Drive,
			char*       _Dir,
			char*       _Filename,
			char*       _Ext
		);

	__declspec(dllimport) errno_t __cdecl _splitpath_s(
		char const* _FullPath,
		char*       _Drive,
		size_t      _DriveCount,
		char*       _Dir,
		size_t      _DirCount,
		char*       _Filename,
		size_t      _FilenameCount,
		char*       _Ext,
		size_t      _ExtCount
	);

	extern "C++" { template <size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize> inline errno_t __cdecl _splitpath_s(char const* _Dest, char(&_Drive)[_DriveSize], char(&_Dir)[_DirSize], char(&_Name)[_NameSize], char(&_Ext)[_ExtSize]) throw() { return _splitpath_s(_Dest, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize); } }

	__declspec(dllimport) errno_t __cdecl getenv_s(
		size_t*     _RequiredCount,
		char*       _Buffer,
		rsize_t     _BufferCount,
		char const* _VarName
	);

	__declspec(dllimport) int*       __cdecl __p___argc(void);
	__declspec(dllimport) char***    __cdecl __p___argv(void);
	__declspec(dllimport) wchar_t*** __cdecl __p___wargv(void);

	__declspec(dllimport) char***    __cdecl __p__environ(void);
	__declspec(dllimport) wchar_t*** __cdecl __p__wenviron(void);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_dupenv_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl getenv(
			char const* _VarName
		);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl getenv_s(size_t* _RequiredCount, char(&_Buffer)[_Size], char const* _VarName) throw() { return getenv_s(_RequiredCount, _Buffer, _Size, _VarName); } }

	__declspec(dllimport) errno_t __cdecl _dupenv_s(
		char**      _Buffer,
		size_t*     _BufferCount,
		char const* _VarName
	);

	__declspec(dllimport) int __cdecl system(
		char const* _Command
	);

#pragma warning (push)
#pragma warning (disable:6540)

	__declspec(dllimport) int __cdecl _putenv(
		char const* _EnvString
	);

	__declspec(dllimport) errno_t __cdecl _putenv_s(
		char const* _Name,
		char const* _Value
	);

#pragma warning (pop)

	__declspec(dllimport) errno_t __cdecl _searchenv_s(
		char const* _Filename,
		char const* _VarName,
		char*       _Buffer,
		size_t      _BufferCount
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _searchenv_s(char const* _Filename, char const* _VarName, char(&_Buffer)[_Size]) throw() { return _searchenv_s(_Filename, _VarName, _Buffer, _Size); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_searchenv_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) void __cdecl _searchenv(char const* _Filename, char const* _VarName, char *_Buffer);

	__declspec(deprecated("This function or variable has been superceded by newer library " "or operating system functionality. Consider using " "SetErrorMode" " " "instead. See online help for details."))
		__declspec(dllimport) void __cdecl _seterrormode(
			int _Mode
		);

	__declspec(deprecated("This function or variable has been superceded by newer library " "or operating system functionality. Consider using " "Beep" " " "instead. See online help for details."))
		__declspec(dllimport) void __cdecl _beep(
			unsigned _Frequency,
			unsigned _Duration
		);

	__declspec(deprecated("This function or variable has been superceded by newer library " "or operating system functionality. Consider using " "Sleep" " " "instead. See online help for details."))
		__declspec(dllimport) void __cdecl _sleep(
			unsigned long _Duration
		);

#pragma warning(push)
#pragma warning(disable: 4141) 

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_ecvt" ". See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_ecvt_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl ecvt(
			double _Value,
			int    _DigitCount,
			int*   _PtDec,
			int*   _PtSign
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_fcvt" ". See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_fcvt_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl fcvt(
			double _Value,
			int    _FractionalDigitCount,
			int*   _PtDec,
			int*   _PtSign
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_gcvt" ". See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_fcvt_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl gcvt(
			double _Value,
			int    _DigitCount,
			char*  _DstBuf
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_itoa" ". See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_itoa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl itoa(
			int   _Value,
			char* _Buffer,
			int   _Radix
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_ltoa" ". See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_ltoa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl ltoa(
			long  _Value,
			char* _Buffer,
			int   _Radix
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_swab" ". See online help for details."))
		__declspec(dllimport) void __cdecl swab(
			char* _Buf1,
			char* _Buf2,
			int   _SizeInBytes
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_ultoa" ". See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_ultoa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl ultoa(
			unsigned long _Value,
			char*         _Buffer,
			int           _Radix
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_putenv" ". See online help for details."))
		__declspec(dllimport) int __cdecl putenv(
			char const* _EnvString
		);

#pragma warning(pop)

	_onexit_t __cdecl onexit(_onexit_t _Func);

} __pragma(pack(pop))

#pragma once

__pragma(pack(push, 8)) extern "C" {

#pragma warning(push)
#pragma warning(disable:4738) 
#pragma warning(disable:4820) 

	struct _exception
	{
		int    type;
		char*  name;
		double arg1;
		double arg2;
		double retval;
	};

	struct _complex
	{
		double x, y;
	};

	typedef float  float_t;
	typedef double double_t;

	extern double const _HUGE;

	void __cdecl _fperrraise(int _Except);

	__declspec(dllimport) short __cdecl _dclass(double _X);
	__declspec(dllimport) short __cdecl _ldclass(long double _X);
	__declspec(dllimport) short __cdecl _fdclass(float _X);

	__declspec(dllimport) int __cdecl _dsign(double _X);
	__declspec(dllimport) int __cdecl _ldsign(long double _X);
	__declspec(dllimport) int __cdecl _fdsign(float _X);

	__declspec(dllimport) int __cdecl _dpcomp(double _X, double _Y);
	__declspec(dllimport) int __cdecl _ldpcomp(long double _X, long double _Y);
	__declspec(dllimport) int __cdecl _fdpcomp(float _X, float _Y);

	__declspec(dllimport) short __cdecl _dtest(double* _Px);
	__declspec(dllimport) short __cdecl _ldtest(long double* _Px);
	__declspec(dllimport) short __cdecl _fdtest(float* _Px);

	__declspec(dllimport) short __cdecl _d_int(double* _Px, short _Xexp);
	__declspec(dllimport) short __cdecl _ld_int(long double* _Px, short _Xexp);
	__declspec(dllimport) short __cdecl _fd_int(float* _Px, short _Xexp);

	__declspec(dllimport) short __cdecl _dscale(double* _Px, long _Lexp);
	__declspec(dllimport) short __cdecl _ldscale(long double* _Px, long _Lexp);
	__declspec(dllimport) short __cdecl _fdscale(float* _Px, long _Lexp);

	__declspec(dllimport) short __cdecl _dunscale(short* _Pex, double* _Px);
	__declspec(dllimport) short __cdecl _ldunscale(short* _Pex, long double* _Px);
	__declspec(dllimport) short __cdecl _fdunscale(short* _Pex, float* _Px);

	__declspec(dllimport) short __cdecl _dexp(double* _Px, double _Y, long _Eoff);
	__declspec(dllimport) short __cdecl _ldexp(long double* _Px, long double _Y, long _Eoff);
	__declspec(dllimport) short __cdecl _fdexp(float* _Px, float _Y, long _Eoff);

	__declspec(dllimport) short __cdecl _dnorm(unsigned short* _Ps);
	__declspec(dllimport) short __cdecl _fdnorm(unsigned short* _Ps);

	__declspec(dllimport) double __cdecl _dpoly(double _X, double const* _Tab, int _N);
	__declspec(dllimport) long double __cdecl _ldpoly(long double _X, long double const* _Tab, int _N);
	__declspec(dllimport) float __cdecl _fdpoly(float _X, float const* _Tab, int _N);

	__declspec(dllimport) double __cdecl _dlog(double _X, int _Baseflag);
	__declspec(dllimport) long double __cdecl _ldlog(long double _X, int _Baseflag);
	__declspec(dllimport) float __cdecl _fdlog(float _X, int _Baseflag);

	__declspec(dllimport) double __cdecl _dsin(double _X, unsigned int _Qoff);
	__declspec(dllimport) long double __cdecl _ldsin(long double _X, unsigned int _Qoff);
	__declspec(dllimport) float __cdecl _fdsin(float _X, unsigned int _Qoff);

	typedef union
	{
		unsigned short _Sh[4];
		double _Val;
	} _double_val;

	typedef union
	{
		unsigned short _Sh[2];
		float _Val;
	} _float_val;

	typedef union
	{
		unsigned short _Sh[4];
		long double _Val;
	} _ldouble_val;

	typedef union
	{
		unsigned short _Word[4];
		float _Float;
		double _Double;
		long double _Long_double;
	} _float_const;

	extern const _float_const _Denorm_C, _Inf_C, _Nan_C, _Snan_C, _Hugeval_C;
	extern const _float_const _FDenorm_C, _FInf_C, _FNan_C, _FSnan_C;
	extern const _float_const _LDenorm_C, _LInf_C, _LNan_C, _LSnan_C;

	extern const _float_const _Eps_C, _Rteps_C;
	extern const _float_const _FEps_C, _FRteps_C;
	extern const _float_const _LEps_C, _LRteps_C;

	extern const double      _Zero_C, _Xbig_C;
	extern const float       _FZero_C, _FXbig_C;
	extern const long double _LZero_C, _LXbig_C;

	extern "C++"
	{
		inline int fpclassify(float _X) throw()
		{
			return _fdtest(&_X);
		}

		inline int fpclassify(double _X) throw()
		{
			return _dtest(&_X);
		}

		inline int fpclassify(long double _X) throw()
		{
			return _ldtest(&_X);
		}

		inline bool signbit(float _X) throw()
		{
			return _fdsign(_X) != 0;
		}

		inline bool signbit(double _X) throw()
		{
			return _dsign(_X) != 0;
		}

		inline bool signbit(long double _X) throw()
		{
			return _ldsign(_X) != 0;
		}

		inline int _fpcomp(float _X, float _Y) throw()
		{
			return _fdpcomp(_X, _Y);
		}

		inline int _fpcomp(double _X, double _Y) throw()
		{
			return _dpcomp(_X, _Y);
		}

		inline int _fpcomp(long double _X, long double _Y) throw()
		{
			return _ldpcomp(_X, _Y);
		}

		template <class _Trc, class _Tre> struct _Combined_type
		{
			typedef float _Type;
		};

		template <> struct _Combined_type<float, double>
		{
			typedef double _Type;
		};

		template <> struct _Combined_type<float, long double>
		{
			typedef long double _Type;
		};

		template <class _Ty, class _T2> struct _Real_widened
		{
			typedef long double _Type;
		};

		template <> struct _Real_widened<float, float>
		{
			typedef float _Type;
		};

		template <> struct _Real_widened<float, double>
		{
			typedef double _Type;
		};

		template <> struct _Real_widened<double, float>
		{
			typedef double _Type;
		};

		template <> struct _Real_widened<double, double>
		{
			typedef double _Type;
		};

		template <class _Ty> struct _Real_type
		{
			typedef double _Type;
		};

		template <> struct _Real_type<float>
		{
			typedef float _Type;
		};

		template <> struct _Real_type<long double>
		{
			typedef long double _Type;
		};

		template <class _T1, class _T2>
		inline int _fpcomp(_T1 _X, _T2 _Y) throw()
		{
			typedef typename _Combined_type<float,
				typename _Real_widened<
				typename _Real_type<_T1>::_Type,
				typename _Real_type<_T2>::_Type>::_Type>::_Type _Tw;
			return _fpcomp((_Tw)_X, (_Tw)_Y);
		}

		template <class _Ty>
		inline bool isfinite(_Ty _X) throw()
		{
			return fpclassify(_X) <= 0;
		}

		template <class _Ty>
		inline bool isinf(_Ty _X) throw()
		{
			return fpclassify(_X) == 1;
		}

		template <class _Ty>
		inline bool isnan(_Ty _X) throw()
		{
			return fpclassify(_X) == 2;
		}

		template <class _Ty>
		inline bool isnormal(_Ty _X) throw()
		{
			return fpclassify(_X) == (-1);
		}

		template <class _Ty1, class _Ty2>
		inline bool isgreater(_Ty1 _X, _Ty2 _Y) throw()
		{
			return (_fpcomp(_X, _Y) & 4) != 0;
		}

		template <class _Ty1, class _Ty2>
		inline bool isgreaterequal(_Ty1 _X, _Ty2 _Y) throw()
		{
			return (_fpcomp(_X, _Y) & (2 | 4)) != 0;
		}

		template <class _Ty1, class _Ty2>
		inline bool isless(_Ty1 _X, _Ty2 _Y) throw()
		{
			return (_fpcomp(_X, _Y) & 1) != 0;
		}

		template <class _Ty1, class _Ty2>
		inline bool islessequal(_Ty1 _X, _Ty2 _Y) throw()
		{
			return (_fpcomp(_X, _Y) & (1 | 2)) != 0;
		}

		template <class _Ty1, class _Ty2>
		inline bool islessgreater(_Ty1 _X, _Ty2 _Y) throw()
		{
			return (_fpcomp(_X, _Y) & (1 | 4)) != 0;
		}

		template <class _Ty1, class _Ty2>
		inline bool isunordered(_Ty1 _X, _Ty2 _Y) throw()
		{
			return _fpcomp(_X, _Y) == 0;
		}
	}

	int       __cdecl abs(int _X);
	long      __cdecl labs(long _X);
	long long __cdecl llabs(long long _X);

	double __cdecl acos(double _X);
	double __cdecl asin(double _X);
	double __cdecl atan(double _X);
	double __cdecl atan2(double _Y, double _X);

	double __cdecl cos(double _X);
	double __cdecl cosh(double _X);
	double __cdecl exp(double _X);
	double __cdecl fabs(double _X);
	double __cdecl fmod(double _X, double _Y);
	double __cdecl log(double _X);
	double __cdecl log10(double _X);
	double __cdecl pow(double _X, double _Y);
	double __cdecl sin(double _X);
	double __cdecl sinh(double _X);
	double __cdecl sqrt(double _X);
	double __cdecl tan(double _X);
	double __cdecl tanh(double _X);

	__declspec(dllimport) double    __cdecl acosh(double _X);
	__declspec(dllimport) double    __cdecl asinh(double _X);
	__declspec(dllimport) double    __cdecl atanh(double _X);
	__declspec(dllimport)  double    __cdecl atof(char const* _String);
	__declspec(dllimport)  double    __cdecl _atof_l(char const* _String, _locale_t _Locale);
	__declspec(dllimport) double    __cdecl _cabs(struct _complex _Complex_value);
	__declspec(dllimport) double    __cdecl cbrt(double _X);
	__declspec(dllimport) double    __cdecl ceil(double _X);
	__declspec(dllimport) double    __cdecl _chgsign(double _X);
	__declspec(dllimport) double    __cdecl copysign(double _Number, double _Sign);
	__declspec(dllimport) double    __cdecl _copysign(double _Number, double _Sign);
	__declspec(dllimport) double    __cdecl erf(double _X);
	__declspec(dllimport) double    __cdecl erfc(double _X);
	__declspec(dllimport) double    __cdecl exp2(double _X);
	__declspec(dllimport) double    __cdecl expm1(double _X);
	__declspec(dllimport) double    __cdecl fdim(double _X, double _Y);
	__declspec(dllimport) double    __cdecl floor(double _X);
	__declspec(dllimport) double    __cdecl fma(double _X, double _Y, double _Z);
	__declspec(dllimport) double    __cdecl fmax(double _X, double _Y);
	__declspec(dllimport) double    __cdecl fmin(double _X, double _Y);
	__declspec(dllimport) double    __cdecl frexp(double _X, int* _Y);
	__declspec(dllimport) double    __cdecl hypot(double _X, double _Y);
	__declspec(dllimport) double    __cdecl _hypot(double _X, double _Y);
	__declspec(dllimport) int       __cdecl ilogb(double _X);
	__declspec(dllimport) double    __cdecl ldexp(double _X, int _Y);
	__declspec(dllimport) double    __cdecl lgamma(double _X);
	__declspec(dllimport) long long __cdecl llrint(double _X);
	__declspec(dllimport) long long __cdecl llround(double _X);
	__declspec(dllimport) double    __cdecl log1p(double _X);
	__declspec(dllimport) double    __cdecl log2(double _X);
	__declspec(dllimport) double    __cdecl logb(double _X);
	__declspec(dllimport) long      __cdecl lrint(double _X);
	__declspec(dllimport) long      __cdecl lround(double _X);

	int __cdecl _matherr(struct _exception* _Except);

	__declspec(dllimport) double __cdecl modf(double _X, double* _Y);
	__declspec(dllimport) double __cdecl nan(char const* _X);
	__declspec(dllimport) double __cdecl nearbyint(double _X);
	__declspec(dllimport) double __cdecl nextafter(double _X, double _Y);
	__declspec(dllimport) double __cdecl nexttoward(double _X, long double _Y);
	__declspec(dllimport) double __cdecl remainder(double _X, double _Y);
	__declspec(dllimport) double __cdecl remquo(double _X, double _Y, int* _Z);
	__declspec(dllimport) double __cdecl rint(double _X);
	__declspec(dllimport) double __cdecl round(double _X);
	__declspec(dllimport) double __cdecl scalbln(double _X, long _Y);
	__declspec(dllimport) double __cdecl scalbn(double _X, int _Y);
	__declspec(dllimport) double __cdecl tgamma(double _X);
	__declspec(dllimport) double __cdecl trunc(double _X);
	__declspec(dllimport) double __cdecl _j0(double _X);
	__declspec(dllimport) double __cdecl _j1(double _X);
	__declspec(dllimport) double __cdecl _jn(int _X, double _Y);
	__declspec(dllimport) double __cdecl _y0(double _X);
	__declspec(dllimport) double __cdecl _y1(double _X);
	__declspec(dllimport) double __cdecl _yn(int _X, double _Y);

	__declspec(dllimport) float     __cdecl acoshf(float _X);
	__declspec(dllimport) float     __cdecl asinhf(float _X);
	__declspec(dllimport) float     __cdecl atanhf(float _X);
	__declspec(dllimport) float     __cdecl cbrtf(float _X);
	__declspec(dllimport) float     __cdecl _chgsignf(float _X);
	__declspec(dllimport) float     __cdecl copysignf(float _Number, float _Sign);
	__declspec(dllimport) float     __cdecl _copysignf(float _Number, float _Sign);
	__declspec(dllimport) float     __cdecl erff(float _X);
	__declspec(dllimport) float     __cdecl erfcf(float _X);
	__declspec(dllimport) float     __cdecl expm1f(float _X);
	__declspec(dllimport) float     __cdecl exp2f(float _X);
	__declspec(dllimport) float     __cdecl fdimf(float _X, float _Y);
	__declspec(dllimport) float     __cdecl fmaf(float _X, float _Y, float _Z);
	__declspec(dllimport) float     __cdecl fmaxf(float _X, float _Y);
	__declspec(dllimport) float     __cdecl fminf(float _X, float _Y);
	__declspec(dllimport) float     __cdecl _hypotf(float _X, float _Y);
	__declspec(dllimport) int       __cdecl ilogbf(float _X);
	__declspec(dllimport) float     __cdecl lgammaf(float _X);
	__declspec(dllimport) long long __cdecl llrintf(float _X);
	__declspec(dllimport) long long __cdecl llroundf(float _X);
	__declspec(dllimport) float     __cdecl log1pf(float _X);
	__declspec(dllimport) float     __cdecl log2f(float _X);
	__declspec(dllimport) float     __cdecl logbf(float _X);
	__declspec(dllimport) long      __cdecl lrintf(float _X);
	__declspec(dllimport) long      __cdecl lroundf(float _X);
	__declspec(dllimport) float     __cdecl nanf(char const* _X);
	__declspec(dllimport) float     __cdecl nearbyintf(float _X);
	__declspec(dllimport) float     __cdecl nextafterf(float _X, float _Y);
	__declspec(dllimport) float     __cdecl nexttowardf(float _X, long double _Y);
	__declspec(dllimport) float     __cdecl remainderf(float _X, float _Y);
	__declspec(dllimport) float     __cdecl remquof(float _X, float _Y, int* _Z);
	__declspec(dllimport) float     __cdecl rintf(float _X);
	__declspec(dllimport) float     __cdecl roundf(float _X);
	__declspec(dllimport) float     __cdecl scalblnf(float _X, long _Y);
	__declspec(dllimport) float     __cdecl scalbnf(float _X, int _Y);
	__declspec(dllimport) float     __cdecl tgammaf(float _X);
	__declspec(dllimport) float     __cdecl truncf(float _X);

	__declspec(dllimport) int  __cdecl _set_SSE2_enable(int _Flag);

	__inline float __cdecl acosf(float _X)
	{
		return (float)acos(_X);
	}

	__inline float __cdecl asinf(float _X)
	{
		return (float)asin(_X);
	}

	__inline float __cdecl atan2f(float _Y, float _X)
	{
		return (float)atan2(_Y, _X);
	}

	__inline float __cdecl atanf(float _X)
	{
		return (float)atan(_X);
	}

	__inline float __cdecl ceilf(float _X)
	{
		return (float)ceil(_X);
	}

	__inline float __cdecl cosf(float _X)
	{
		return (float)cos(_X);
	}

	__inline float __cdecl coshf(float _X)
	{
		return (float)cosh(_X);
	}

	__inline float __cdecl expf(float _X)
	{
		return (float)exp(_X);
	}

	__inline float __cdecl fabsf(float _X)
	{
		return (float)fabs(_X);
	}

	__inline float __cdecl floorf(float _X)
	{
		return (float)floor(_X);
	}

	__inline float __cdecl fmodf(float _X, float _Y)
	{
		return (float)fmod(_X, _Y);
	}

	__inline float __cdecl frexpf(float _X, int *_Y)
	{
		return (float)frexp(_X, _Y);
	}

	__inline float __cdecl hypotf(float _X, float _Y)
	{
		return _hypotf(_X, _Y);
	}

	__inline float __cdecl ldexpf(float _X, int _Y)
	{
		return (float)ldexp(_X, _Y);
	}

	__inline float __cdecl log10f(float _X)
	{
		return (float)log10(_X);
	}

	__inline float __cdecl logf(float _X)
	{
		return (float)log(_X);
	}

	__inline float __cdecl modff(float _X, float* _Y)
	{
		double _F, _I;
		_F = modf(_X, &_I);
		*_Y = (float)_I;
		return (float)_F;
	}

	__inline float __cdecl powf(float _X, float _Y)
	{
		return (float)pow(_X, _Y);
	}

	__inline float __cdecl sinf(float _X)
	{
		return (float)sin(_X);
	}

	__inline float __cdecl sinhf(float _X)
	{
		return (float)sinh(_X);
	}

	__inline float __cdecl sqrtf(float _X)
	{
		return (float)sqrt(_X);
	}

	__inline float __cdecl tanf(float _X)
	{
		return (float)tan(_X);
	}

	__inline float __cdecl tanhf(float _X)
	{
		return (float)tanh(_X);
	}

	__declspec(dllimport) long double __cdecl acoshl(long double _X);

	__inline long double __cdecl acosl(long double _X)
	{
		return acos((double)_X);
	}

	__declspec(dllimport) long double __cdecl asinhl(long double _X);

	__inline long double __cdecl asinl(long double _X)
	{
		return asin((double)_X);
	}

	__inline long double __cdecl atan2l(long double _Y, long double _X)
	{
		return atan2((double)_Y, (double)_X);
	}

	__declspec(dllimport) long double __cdecl atanhl(long double _X);

	__inline long double __cdecl atanl(long double _X)
	{
		return atan((double)_X);
	}

	__declspec(dllimport) long double __cdecl cbrtl(long double _X);

	__inline long double __cdecl ceill(long double _X)
	{
		return ceil((double)_X);
	}

	__inline long double __cdecl _chgsignl(long double _X)
	{
		return _chgsign((double)_X);
	}

	__declspec(dllimport) long double __cdecl copysignl(long double _Number, long double _Sign);

	__inline long double __cdecl _copysignl(long double _Number, long double _Sign)
	{
		return _copysign((double)_Number, (double)_Sign);
	}

	__inline long double __cdecl coshl(long double _X)
	{
		return cosh((double)_X);
	}

	__inline long double __cdecl cosl(long double _X)
	{
		return cos((double)_X);
	}

	__declspec(dllimport) long double __cdecl erfl(long double _X);
	__declspec(dllimport) long double __cdecl erfcl(long double _X);

	__inline long double __cdecl expl(long double _X)
	{
		return exp((double)_X);
	}

	__declspec(dllimport) long double __cdecl exp2l(long double _X);
	__declspec(dllimport) long double __cdecl expm1l(long double _X);

	__inline long double __cdecl fabsl(long double _X)
	{
		return fabs((double)_X);
	}

	__declspec(dllimport) long double __cdecl fdiml(long double _X, long double _Y);

	__inline long double __cdecl floorl(long double _X)
	{
		return floor((double)_X);
	}

	__declspec(dllimport) long double __cdecl fmal(long double _X, long double _Y, long double _Z);
	__declspec(dllimport) long double __cdecl fmaxl(long double _X, long double _Y);
	__declspec(dllimport) long double __cdecl fminl(long double _X, long double _Y);

	__inline long double __cdecl fmodl(long double _X, long double _Y)
	{
		return fmod((double)_X, (double)_Y);
	}

	__inline long double __cdecl frexpl(long double _X, int *_Y)
	{
		return frexp((double)_X, _Y);
	}

	__declspec(dllimport) int __cdecl ilogbl(long double _X);

	__inline long double __cdecl _hypotl(long double _X, long double _Y)
	{
		return _hypot((double)_X, (double)_Y);
	}

	__inline long double __cdecl hypotl(long double _X, long double _Y)
	{
		return _hypot((double)_X, (double)_Y);
	}

	__inline long double __cdecl ldexpl(long double _X, int _Y)
	{
		return ldexp((double)_X, _Y);
	}

	__declspec(dllimport) long double __cdecl lgammal(long double _X);
	__declspec(dllimport) long long __cdecl llrintl(long double _X);
	__declspec(dllimport) long long __cdecl llroundl(long double _X);

	__inline long double __cdecl logl(long double _X)
	{
		return log((double)_X);
	}

	__inline long double __cdecl log10l(long double _X)
	{
		return log10((double)_X);
	}

	__declspec(dllimport) long double __cdecl log1pl(long double _X);
	__declspec(dllimport) long double __cdecl log2l(long double _X);
	__declspec(dllimport) long double __cdecl logbl(long double _X);
	__declspec(dllimport) long __cdecl lrintl(long double _X);
	__declspec(dllimport) long __cdecl lroundl(long double _X);

	__inline long double __cdecl modfl(long double _X, long double* _Y)
	{
		double _F, _I;
		_F = modf((double)_X, &_I);
		*_Y = _I;
		return _F;
	}

	__declspec(dllimport) long double __cdecl nanl(char const* _X);
	__declspec(dllimport) long double __cdecl nearbyintl(long double _X);
	__declspec(dllimport) long double __cdecl nextafterl(long double _X, long double _Y);
	__declspec(dllimport) long double __cdecl nexttowardl(long double _X, long double _Y);

	__inline long double __cdecl powl(long double _X, long double _Y)
	{
		return pow((double)_X, (double)_Y);
	}

	__declspec(dllimport) long double __cdecl remainderl(long double _X, long double _Y);
	__declspec(dllimport) long double __cdecl remquol(long double _X, long double _Y, int* _Z);
	__declspec(dllimport) long double __cdecl rintl(long double _X);
	__declspec(dllimport) long double __cdecl roundl(long double _X);
	__declspec(dllimport) long double __cdecl scalblnl(long double _X, long _Y);
	__declspec(dllimport) long double __cdecl scalbnl(long double _X, int _Y);

	__inline long double __cdecl sinhl(long double _X)
	{
		return sinh((double)_X);
	}

	__inline long double __cdecl sinl(long double _X)
	{
		return sin((double)_X);
	}

	__inline long double __cdecl sqrtl(long double _X)
	{
		return sqrt((double)_X);
	}

	__inline long double __cdecl tanhl(long double _X)
	{
		return tanh((double)_X);
	}

	__inline long double __cdecl tanl(long double _X)
	{
		return tan((double)_X);
	}

	__declspec(dllimport) long double __cdecl tgammal(long double _X);
	__declspec(dllimport) long double __cdecl truncl(long double _X);

	extern double HUGE;

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_j0" ". See online help for details."))   __declspec(dllimport) double __cdecl j0(double _X);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_j1" ". See online help for details."))   __declspec(dllimport) double __cdecl j1(double _X);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_jn" ". See online help for details."))   __declspec(dllimport) double __cdecl jn(int _X, double _Y);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_y0" ". See online help for details."))   __declspec(dllimport) double __cdecl y0(double _X);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_y1" ". See online help for details."))   __declspec(dllimport) double __cdecl y1(double _X);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_yn" ". See online help for details."))   __declspec(dllimport) double __cdecl yn(int _X, double _Y);

#pragma warning(pop)

} __pragma(pack(pop))

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

inline double abs(double _Xx) noexcept
{
	return (::fabs(_Xx));
}

inline float abs(float _Xx) noexcept
{
	return (::fabsf(_Xx));
}

inline long double abs(long double _Xx) noexcept
{
	return (::fabsl(_Xx));
}

namespace std {
	using ::size_t; using ::div_t; using ::ldiv_t;
	using ::abort; using ::abs; using ::atexit;
	using ::atof; using ::atoi; using ::atol;
	using ::bsearch; using ::calloc; using ::div;
	using ::exit; using ::free;
	using ::labs; using ::ldiv; using ::malloc;
	using ::mblen; using ::mbstowcs; using ::mbtowc;
	using ::qsort; using ::rand; using ::realloc;
	using ::srand; using ::strtod; using ::strtol;
	using ::strtoul;
	using ::wcstombs; using ::wctomb;

	using ::lldiv_t;

	using ::getenv;
	using ::system;

	using ::atoll; using ::llabs; using ::lldiv;
	using ::strtof; using ::strtold;
	using ::strtoll; using ::strtoull;

	using ::_Exit; using ::at_quick_exit; using ::quick_exit;
}

#pragma warning(pop)
#pragma pack(pop)

#pragma once

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {

	template<class _Elem>
	class initializer_list
	{
	public:
		typedef _Elem value_type;
		typedef const _Elem& reference;
		typedef const _Elem& const_reference;
		typedef size_t size_type;

		typedef const _Elem* iterator;
		typedef const _Elem* const_iterator;

		constexpr initializer_list() noexcept
			: _First(nullptr), _Last(nullptr)
		{
		}

		constexpr initializer_list(const _Elem *_First_arg,
			const _Elem *_Last_arg) noexcept
			: _First(_First_arg), _Last(_Last_arg)
		{
		}

		constexpr const _Elem * begin() const noexcept
		{
			return (_First);
		}

		constexpr const _Elem * end() const noexcept
		{
			return (_Last);
		}

		constexpr size_t size() const noexcept
		{
			return (static_cast<size_t>(_Last - _First));
		}

	private:
		const _Elem *_First;
		const _Elem *_Last;
	};

	template<class _Elem>
	constexpr const _Elem * begin(initializer_list<_Elem> _Ilist) noexcept
	{
		return (_Ilist.begin());
	}

	template<class _Elem>
	constexpr const _Elem * end(initializer_list<_Elem> _Ilist) noexcept
	{
		return (_Ilist.end());
	}
}

#pragma warning(pop)
#pragma pack(pop)

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {

	template<class>

	constexpr bool _Always_false = false;

	template<class _Arg,
		class _Result>
		struct unary_function
	{
		typedef _Arg argument_type;
		typedef _Result result_type;
	};

	template<class _Arg1,
		class _Arg2,
		class _Result>
		struct binary_function
	{
		typedef _Arg1 first_argument_type;
		typedef _Arg2 second_argument_type;
		typedef _Result result_type;
	};

	template<class _Ty = void>
	struct plus
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef _Ty result_type;

		constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left + _Right);
		}
	};

	template<class _Ty = void>
	struct minus
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef _Ty result_type;

		constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left - _Right);
		}
	};

	template<class _Ty = void>
	struct multiplies
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef _Ty result_type;

		constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left * _Right);
		}
	};

	template<class _Ty = void>
	struct equal_to
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left == _Right);
		}
	};

	template<class _Ty = void>
	struct not_equal_to
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left != _Right);
		}
	};

	template<class _Ty = void>
	struct greater
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left > _Right);
		}
	};

	template<class _Ty = void>
	struct less
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left < _Right);
		}
	};

	template<class _Ty = void>
	struct greater_equal
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left >= _Right);
		}
	};

	template<class _Ty = void>
	struct less_equal
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left <= _Right);
		}
	};

	template<>
	struct plus<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(static_cast<_Ty1&&>(_Left)
				+ static_cast<_Ty2&&>(_Right))
		{
			return (static_cast<_Ty1&&>(_Left)
				+ static_cast<_Ty2&&>(_Right));
		}
	};

	template<>
	struct minus<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(static_cast<_Ty1&&>(_Left)
				- static_cast<_Ty2&&>(_Right))
		{
			return (static_cast<_Ty1&&>(_Left)
				- static_cast<_Ty2&&>(_Right));
		}
	};

	template<>
	struct multiplies<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(static_cast<_Ty1&&>(_Left)
				* static_cast<_Ty2&&>(_Right))
		{
			return (static_cast<_Ty1&&>(_Left)
				* static_cast<_Ty2&&>(_Right));
		}
	};

	template<>
	struct equal_to<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(static_cast<_Ty1&&>(_Left)
				== static_cast<_Ty2&&>(_Right))
		{
			return (static_cast<_Ty1&&>(_Left)
				== static_cast<_Ty2&&>(_Right));
		}
	};

	template<>
	struct not_equal_to<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(static_cast<_Ty1&&>(_Left)
				!= static_cast<_Ty2&&>(_Right))
		{
			return (static_cast<_Ty1&&>(_Left)
				!= static_cast<_Ty2&&>(_Right));
		}
	};

	template<>
	struct greater<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(static_cast<_Ty1&&>(_Left)
			> static_cast<_Ty2&&>(_Right))
		{
			return (static_cast<_Ty1&&>(_Left)
		> static_cast<_Ty2&&>(_Right));
		}
	};

	template<>
	struct less<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(static_cast<_Ty1&&>(_Left)
				< static_cast<_Ty2&&>(_Right))
		{
			return (static_cast<_Ty1&&>(_Left)
				< static_cast<_Ty2&&>(_Right));
		}
	};

	template<>
	struct greater_equal<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(static_cast<_Ty1&&>(_Left)
				>= static_cast<_Ty2&&>(_Right))
		{
			return (static_cast<_Ty1&&>(_Left)
				>= static_cast<_Ty2&&>(_Right));
		}
	};

	template<>
	struct less_equal<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(static_cast<_Ty1&&>(_Left)
				<= static_cast<_Ty2&&>(_Right))
		{
			return (static_cast<_Ty1&&>(_Left)
				<= static_cast<_Ty2&&>(_Right));
		}
	};

	template<class _Ty>
	constexpr _Ty * addressof(_Ty& _Val) noexcept
	{
		return (__builtin_addressof(_Val));
	}

	template<class _Ty>
	const _Ty * addressof(const _Ty&&) = delete;

	template<class _Ptrty> inline
		auto _Unfancy(_Ptrty _Ptr)
	{
		return (::std::addressof(*_Ptr));
	}

	template<class _Ty> inline
		_Ty * _Unfancy(_Ty * _Ptr)
	{
		return (_Ptr);
	}
}

#pragma warning(pop)
#pragma pack(pop)

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

#pragma warning(disable: 4180)	

namespace std {

	template<class _Ty,
		_Ty... _Vals>
		struct integer_sequence
	{
		static_assert(is_integral_v<_Ty>,
			"integer_sequence<T, I...> requires T to be an integral type.");

		using value_type = _Ty;

		static constexpr size_t size() noexcept
		{
			return (sizeof...(_Vals));
		}
	};

	template<class _Ty,
		_Ty _Size>
		using make_integer_sequence = __make_integer_seq<integer_sequence, _Ty, _Size>;

	template<size_t... _Vals>
	using index_sequence = integer_sequence<size_t, _Vals...>;

	template<size_t _Size>
	using make_index_sequence = make_integer_sequence<size_t, _Size>;

	template<class... _Types>
	using index_sequence_for = make_index_sequence<sizeof...(_Types)>;

	template<bool _First_value,
		class _First,
		class... _Rest>
		struct _Conjunction
	{
		using type = _First;
	};

	template<class _True,
		class _Next,
		class... _Rest>
		struct _Conjunction<true, _True, _Next, _Rest...>
	{
		using type = typename _Conjunction<_Next::value, _Next, _Rest...>::type;
	};

	template<class... _Traits>
	struct conjunction
		: true_type
	{
	};

	template<class _First,
		class... _Rest>
		struct conjunction<_First, _Rest...>
		: _Conjunction<_First::value, _First, _Rest...>::type
	{

	};

	template<class... _Traits>
	constexpr bool conjunction_v = conjunction<_Traits...>::value;

	template<bool _First_value,
		class _First,
		class... _Rest>
		struct _Disjunction
	{
		using type = _First;
	};

	template<class _False,
		class _Next,
		class... _Rest>
		struct _Disjunction<false, _False, _Next, _Rest...>
	{
		using type = typename _Disjunction<_Next::value, _Next, _Rest...>::type;
	};

	template<class... _Traits>
	struct disjunction
		: false_type
	{
	};

	template<class _First,
		class... _Rest>
		struct disjunction<_First, _Rest...>
		: _Disjunction<_First::value, _First, _Rest...>::type
	{

	};

	template<class... _Traits>
	constexpr bool disjunction_v = disjunction<_Traits...>::value;

	template<class _Trait>
	struct negation
		: bool_constant<!static_cast<bool>(_Trait::value)>
	{
	};

	template<class _Trait>
	constexpr bool negation_v = negation<_Trait>::value;

	template<class _Ty,
		class... _Types>
		constexpr bool _Is_any_of_v = disjunction_v<is_same<_Ty, _Types>...>;

	template<class... _Types>
	struct _Arg_types
	{
	};

	template<class _Ty1>
	struct _Arg_types<_Ty1>
	{
		typedef _Ty1 argument_type;
	};

	template<class _Ty1,
		class _Ty2>
		struct _Arg_types<_Ty1, _Ty2>
	{
		typedef _Ty1 first_argument_type;
		typedef _Ty2 second_argument_type;
	};

	template<class _Ty>
	struct _Is_function
	{
		using _Bool_type = false_type;
	};

	template<class _Ret, class... _Types> struct _Is_function<_Ret __cdecl (_Types...)   > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };  template<class _Ret, class... _Types> struct _Is_function<_Ret __fastcall (_Types...)   > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __stdcall (_Types...)   > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __vectorcall (_Types...)   > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __cdecl (_Types...) const  > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };  template<class _Ret, class... _Types> struct _Is_function<_Ret __fastcall (_Types...) const  > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __stdcall (_Types...) const  > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __vectorcall (_Types...) const  > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __cdecl (_Types...) volatile  > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };  template<class _Ret, class... _Types> struct _Is_function<_Ret __fastcall (_Types...) volatile  > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __stdcall (_Types...) volatile  > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __vectorcall (_Types...) volatile  > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __cdecl (_Types...) const volatile  > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };  template<class _Ret, class... _Types> struct _Is_function<_Ret __fastcall (_Types...) const volatile  > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __stdcall (_Types...) const volatile  > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __vectorcall (_Types...) const volatile  > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __cdecl (_Types...)  & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };  template<class _Ret, class... _Types> struct _Is_function<_Ret __fastcall (_Types...)  & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __stdcall (_Types...)  & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __vectorcall (_Types...)  & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __cdecl (_Types...) const & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };  template<class _Ret, class... _Types> struct _Is_function<_Ret __fastcall (_Types...) const & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __stdcall (_Types...) const & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __vectorcall (_Types...) const & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __cdecl (_Types...) volatile & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };  template<class _Ret, class... _Types> struct _Is_function<_Ret __fastcall (_Types...) volatile & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __stdcall (_Types...) volatile & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __vectorcall (_Types...) volatile & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __cdecl (_Types...) const volatile & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };  template<class _Ret, class... _Types> struct _Is_function<_Ret __fastcall (_Types...) const volatile & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __stdcall (_Types...) const volatile & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __vectorcall (_Types...) const volatile & > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __cdecl (_Types...) && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };  template<class _Ret, class... _Types> struct _Is_function<_Ret __fastcall (_Types...) && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __stdcall (_Types...) && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __vectorcall (_Types...) && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __cdecl (_Types...) const && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };  template<class _Ret, class... _Types> struct _Is_function<_Ret __fastcall (_Types...) const && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __stdcall (_Types...) const && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __vectorcall (_Types...) const && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __cdecl (_Types...) volatile && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };  template<class _Ret, class... _Types> struct _Is_function<_Ret __fastcall (_Types...) volatile && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __stdcall (_Types...) volatile && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __vectorcall (_Types...) volatile && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __cdecl (_Types...) const volatile && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };  template<class _Ret, class... _Types> struct _Is_function<_Ret __fastcall (_Types...) const volatile && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __stdcall (_Types...) const volatile && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret __vectorcall (_Types...) const volatile && > : _Arg_types<_Types...> { using _Bool_type = true_type;  typedef _Ret result_type; };

	template<class _Ret, class... _Types> struct _Is_function<_Ret(_Types..., ...) > { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret(_Types..., ...) const> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret(_Types..., ...) volatile> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret(_Types..., ...) const volatile> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret(_Types..., ...) &> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret(_Types..., ...) const &> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret(_Types..., ...) volatile &> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret(_Types..., ...) const volatile &> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret(_Types..., ...) && > { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret(_Types..., ...) const &&> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret(_Types..., ...) volatile &&> { using _Bool_type = true_type;  typedef _Ret result_type; }; template<class _Ret, class... _Types> struct _Is_function<_Ret(_Types..., ...) const volatile &&> { using _Bool_type = true_type;  typedef _Ret result_type; };

	template<class _Ty>
	struct is_function
		: _Is_function<_Ty>::_Bool_type
	{
	};

	template<class _Ty>
	constexpr bool is_function_v = is_function<_Ty>::value;

	template<class _Ty>
	struct _Is_memfunptr
	{
		using _Bool_type = false_type;
	};

	template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__cdecl _Arg0::*)(_Types...)   > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; };  template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__fastcall _Arg0::*)(_Types...)   > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__stdcall _Arg0::*)(_Types...)   > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__thiscall _Arg0::*)(_Types...)   > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__vectorcall _Arg0::*)(_Types...)   > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__cdecl _Arg0::*)(_Types...) const  > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; };  template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__fastcall _Arg0::*)(_Types...) const  > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__stdcall _Arg0::*)(_Types...) const  > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__thiscall _Arg0::*)(_Types...) const  > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__vectorcall _Arg0::*)(_Types...) const  > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__cdecl _Arg0::*)(_Types...) volatile  > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; };  template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__fastcall _Arg0::*)(_Types...) volatile  > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__stdcall _Arg0::*)(_Types...) volatile  > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__thiscall _Arg0::*)(_Types...) volatile  > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__vectorcall _Arg0::*)(_Types...) volatile  > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__cdecl _Arg0::*)(_Types...) const volatile  > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; };  template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__fastcall _Arg0::*)(_Types...) const volatile  > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__stdcall _Arg0::*)(_Types...) const volatile  > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__thiscall _Arg0::*)(_Types...) const volatile  > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__vectorcall _Arg0::*)(_Types...) const volatile  > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__cdecl _Arg0::*)(_Types...)  & > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; };  template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__fastcall _Arg0::*)(_Types...)  & > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__stdcall _Arg0::*)(_Types...)  & > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__thiscall _Arg0::*)(_Types...)  & > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__vectorcall _Arg0::*)(_Types...)  & > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__cdecl _Arg0::*)(_Types...) const & > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; };  template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__fastcall _Arg0::*)(_Types...) const & > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__stdcall _Arg0::*)(_Types...) const & > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__thiscall _Arg0::*)(_Types...) const & > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__vectorcall _Arg0::*)(_Types...) const & > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__cdecl _Arg0::*)(_Types...) volatile & > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; };  template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__fastcall _Arg0::*)(_Types...) volatile & > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__stdcall _Arg0::*)(_Types...) volatile & > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__thiscall _Arg0::*)(_Types...) volatile & > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__vectorcall _Arg0::*)(_Types...) volatile & > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__cdecl _Arg0::*)(_Types...) const volatile & > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; };  template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__fastcall _Arg0::*)(_Types...) const volatile & > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__stdcall _Arg0::*)(_Types...) const volatile & > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__thiscall _Arg0::*)(_Types...) const volatile & > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__vectorcall _Arg0::*)(_Types...) const volatile & > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__cdecl _Arg0::*)(_Types...) && > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; };  template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__fastcall _Arg0::*)(_Types...) && > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__stdcall _Arg0::*)(_Types...) && > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__thiscall _Arg0::*)(_Types...) && > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__vectorcall _Arg0::*)(_Types...) && > : _Arg_types< _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__cdecl _Arg0::*)(_Types...) const && > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; };  template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__fastcall _Arg0::*)(_Types...) const && > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__stdcall _Arg0::*)(_Types...) const && > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__thiscall _Arg0::*)(_Types...) const && > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__vectorcall _Arg0::*)(_Types...) const && > : _Arg_types<const _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__cdecl _Arg0::*)(_Types...) volatile && > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; };  template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__fastcall _Arg0::*)(_Types...) volatile && > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__stdcall _Arg0::*)(_Types...) volatile && > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__thiscall _Arg0::*)(_Types...) volatile && > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__vectorcall _Arg0::*)(_Types...) volatile && > : _Arg_types<volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__cdecl _Arg0::*)(_Types...) const volatile && > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; };  template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__fastcall _Arg0::*)(_Types...) const volatile && > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__stdcall _Arg0::*)(_Types...) const volatile && > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__thiscall _Arg0::*)(_Types...) const volatile && > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(__vectorcall _Arg0::*)(_Types...) const volatile && > : _Arg_types<const volatile _Arg0 *, _Types...> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<!is_same_v<int &&, int&&>, _Ret(_Types...)>; };

	template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(_Arg0::*)(_Types..., ...) > { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<false>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(_Arg0::*)(_Types..., ...) const> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<false>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(_Arg0::*)(_Types..., ...) volatile> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<false>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(_Arg0::*)(_Types..., ...) const volatile> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<false>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(_Arg0::*)(_Types..., ...) &> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<false>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(_Arg0::*)(_Types..., ...) const &> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<false>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(_Arg0::*)(_Types..., ...) volatile &> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<false>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(_Arg0::*)(_Types..., ...) const volatile &> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<false>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(_Arg0::*)(_Types..., ...) && > { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<false>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(_Arg0::*)(_Types..., ...) const &&> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<false>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(_Arg0::*)(_Types..., ...) volatile &&> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<false>; }; template<class _Ret, class _Arg0, class... _Types> struct _Is_memfunptr<_Ret(_Arg0::*)(_Types..., ...) const volatile &&> { using _Bool_type = true_type;  typedef _Ret result_type; using _Class_type = _Arg0; using _Guide_type = enable_if<false>; };

	template<class _Ty>
	struct is_void
		: false_type
	{
	};

	template<> struct is_void< void> : true_type { }; template<> struct is_void<const void> : true_type { }; template<> struct is_void<volatile void> : true_type { }; template<> struct is_void<const volatile void> : true_type { };

	template<class _Ty>
	constexpr bool is_void_v = is_void<_Ty>::value;

	template<class... _Types>
	using void_t = void;

	template<class _Ty>
	struct add_const
	{
		using type = const _Ty;
	};

	template<class _Ty>
	using add_const_t = const _Ty;

	template<class _Ty>
	struct add_volatile
	{
		using type = volatile _Ty;
	};

	template<class _Ty>
	using add_volatile_t = volatile _Ty;

	template<class _Ty>
	struct add_cv
	{
		using type = const volatile _Ty;
	};

	template<class _Ty>
	using add_cv_t = const volatile _Ty;

	template<class _Ty,
		class = void>
		struct _Add_reference
	{
		using _Lvalue = _Ty;
		using _Rvalue = _Ty;
	};

	template<class _Ty>
	struct _Add_reference<_Ty, void_t<_Ty&>>
	{
		using _Lvalue = _Ty & ;
		using _Rvalue = _Ty && ;
	};

	template<class _Ty>
	struct add_lvalue_reference
	{
		using type = typename _Add_reference<_Ty>::_Lvalue;
	};

	template<class _Ty>
	using add_lvalue_reference_t = typename _Add_reference<_Ty>::_Lvalue;

	template<class _Ty>
	struct add_rvalue_reference
	{
		using type = typename _Add_reference<_Ty>::_Rvalue;
	};

	template<class _Ty>
	using add_rvalue_reference_t = typename _Add_reference<_Ty>::_Rvalue;

	template<class _Ty>
	add_rvalue_reference_t<_Ty> declval() noexcept;

	template<class _Ty>
	struct remove_extent
	{
		using type = _Ty;
	};

	template<class _Ty, size_t _Ix>
	struct remove_extent<_Ty[_Ix]>
	{
		using type = _Ty;
	};

	template<class _Ty>
	struct remove_extent<_Ty[]>
	{
		using type = _Ty;
	};

	template<class _Ty>
	using remove_extent_t = typename remove_extent<_Ty>::type;

	template<class _Ty>
	struct remove_all_extents
	{
		using type = _Ty;
	};

	template<class _Ty, size_t _Ix>
	struct remove_all_extents<_Ty[_Ix]>
	{
		using type = typename remove_all_extents<_Ty>::type;
	};

	template<class _Ty>
	struct remove_all_extents<_Ty[]>
	{
		using type = typename remove_all_extents<_Ty>::type;
	};

	template<class _Ty>
	using remove_all_extents_t = typename remove_all_extents<_Ty>::type;

	template<class _Ty>
	struct remove_pointer
	{
		using type = _Ty;
	};

	template<class _Ty> struct remove_pointer<_Ty * > { using type = _Ty; }; template<class _Ty> struct remove_pointer<_Ty * const> { using type = _Ty; }; template<class _Ty> struct remove_pointer<_Ty * volatile> { using type = _Ty; }; template<class _Ty> struct remove_pointer<_Ty * const volatile> { using type = _Ty; };

	template<class _Ty>
	using remove_pointer_t = typename remove_pointer<_Ty>::type;

	template<class _Ty,
		class = void>
		struct _Add_pointer
	{
		using type = _Ty;
	};

	template<class _Ty>
	struct _Add_pointer<_Ty, void_t<remove_reference_t<_Ty> *>>
	{
		using type = remove_reference_t<_Ty> *;
	};

	template<class _Ty>
	struct add_pointer
	{
		using type = typename _Add_pointer<_Ty>::type;
	};

	template<class _Ty>
	using add_pointer_t = typename _Add_pointer<_Ty>::type;

	template<class _Ty>
	struct is_array
		: false_type
	{
	};

	template<class _Ty, size_t _Nx>
	struct is_array<_Ty[_Nx]>
		: true_type
	{
	};

	template<class _Ty>
	struct is_array<_Ty[]>
		: true_type
	{
	};

	template<class _Ty>
	constexpr bool is_array_v = is_array<_Ty>::value;

	template<class _Ty>
	struct is_lvalue_reference
		: false_type
	{
	};

	template<class _Ty>
	struct is_lvalue_reference<_Ty&>
		: true_type
	{
	};

	template<class _Ty>
	constexpr bool is_lvalue_reference_v = is_lvalue_reference<_Ty>::value;

	template<class _Ty>
	struct is_rvalue_reference
		: false_type
	{
	};

	template<class _Ty>
	struct is_rvalue_reference<_Ty&&>
		: true_type
	{
	};

	template<class _Ty>
	constexpr bool is_rvalue_reference_v = is_rvalue_reference<_Ty>::value;

	template<class _Ty>
	struct is_reference
		: false_type
	{
	};

	template<class _Ty>
	struct is_reference<_Ty&>
		: true_type
	{
	};

	template<class _Ty>
	struct is_reference<_Ty&&>
		: true_type
	{
	};

	template<class _Ty>
	constexpr bool is_reference_v = is_reference<_Ty>::value;

	template<class _Ty,
		bool _Pmf = _Is_memfunptr<_Ty>::_Bool_type::value>
		struct _Is_member_object_pointer
		: false_type
	{
	};

	template<class _Ty1,
		class _Ty2>
		struct _Is_member_object_pointer<_Ty1 _Ty2::*, false>
		: true_type
	{
		using _Class_type = _Ty2;
	};

	template<class _Ty>
	struct is_member_object_pointer
		: _Is_member_object_pointer<remove_cv_t<_Ty>>::type
	{
	};

	template<class _Ty>
	constexpr bool is_member_object_pointer_v = is_member_object_pointer<_Ty>::value;

	template<class _Ty>
	struct is_member_function_pointer
		: _Is_memfunptr<remove_cv_t<_Ty>>::_Bool_type
	{
	};

	template<class _Ty>
	constexpr bool is_member_function_pointer_v = is_member_function_pointer<_Ty>::value;

	template<class _Ty>
	struct is_pointer
		: false_type
	{
	};

	template<class _Ty>
	struct is_pointer<_Ty *>
		: true_type
	{
	};

	template<class _Ty>
	struct is_pointer<_Ty * const>
		: true_type
	{
	};

	template<class _Ty>
	struct is_pointer<_Ty * volatile>
		: true_type
	{
	};

	template<class _Ty>
	struct is_pointer<_Ty * const volatile>
		: true_type
	{
	};

	template<class _Ty>
	constexpr bool is_pointer_v = is_pointer<_Ty>::value;

	template<class _Ty>
	struct is_null_pointer
		: bool_constant<is_same_v<remove_cv_t<_Ty>, nullptr_t>>
	{
	};

	template<class _Ty>
	constexpr bool is_null_pointer_v = is_same_v<remove_cv_t<_Ty>, nullptr_t>;

	template<class _Ty>
	struct is_union
		: bool_constant<__is_union(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_union_v = __is_union(_Ty);

	template<class _Ty>
	struct is_class
		: bool_constant<__is_class(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_class_v = __is_class(_Ty);

	template<class _Ty>
	struct is_fundamental
		: bool_constant<is_arithmetic_v<_Ty>
		|| is_void_v<_Ty>
		|| is_null_pointer_v<_Ty>>
	{
	};

	template<class _Ty>
	constexpr bool is_fundamental_v = is_fundamental<_Ty>::value;

	template<class _Ty>
	struct is_object
		: bool_constant<!is_function_v<_Ty>
		&& !is_reference_v<_Ty>
		&& !is_void_v<_Ty>>
	{
	};

	template<class _Ty>
	constexpr bool is_object_v = is_object<_Ty>::value;

	template<class _From,
		class _To>
		struct is_convertible
		: bool_constant<__is_convertible_to(_From, _To)>
	{
	};

	template<class _From,
		class _To>
		constexpr bool is_convertible_v = __is_convertible_to(_From, _To);

	template<class _Ty>
	struct is_enum
		: bool_constant<__is_enum(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_enum_v = __is_enum(_Ty);

	template<class _Ty>
	struct is_compound
		: bool_constant<!is_fundamental_v<_Ty>>
	{
	};

	template<class _Ty>
	constexpr bool is_compound_v = is_compound<_Ty>::value;

	template<class _Ty>
	struct is_member_pointer
		: bool_constant<is_member_object_pointer_v<_Ty>
		|| is_member_function_pointer_v<_Ty>>
	{
	};

	template<class _Ty>
	constexpr bool is_member_pointer_v = is_member_pointer<_Ty>::value;

	template<class _Ty>
	struct is_scalar
		: bool_constant<is_arithmetic_v<_Ty>
		|| is_enum_v<_Ty>
		|| is_pointer_v<_Ty>
		|| is_member_pointer_v<_Ty>
		|| is_null_pointer_v<_Ty>>
	{
	};

	template<class _Ty>
	constexpr bool is_scalar_v = is_scalar<_Ty>::value;

	template<class _Ty>
	struct is_const
		: false_type
	{
	};

	template<class _Ty>
	struct is_const<const _Ty>
		: true_type
	{
	};

	template<class _Ty>
	constexpr bool is_const_v = is_const<_Ty>::value;

	template<class _Ty>
	struct is_volatile
		: false_type
	{
	};

	template<class _Ty>
	struct is_volatile<volatile _Ty>
		: true_type
	{
	};

	template<class _Ty>
	constexpr bool is_volatile_v = is_volatile<_Ty>::value;

	template<class _Ty>
	struct is_pod
		: bool_constant<__is_pod(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_pod_v = __is_pod(_Ty);

	template<class _Ty>
	struct is_empty
		: bool_constant<__is_empty(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_empty_v = __is_empty(_Ty);

	template<class _Ty>
	struct is_polymorphic
		: bool_constant<__is_polymorphic(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_polymorphic_v = __is_polymorphic(_Ty);

	template<class _Ty>
	struct is_abstract
		: bool_constant<__is_abstract(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_abstract_v = __is_abstract(_Ty);

	template<class _Ty>
	struct is_final
		: bool_constant<__is_final(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_final_v = __is_final(_Ty);

	template<class _Ty>
	struct is_standard_layout
		: bool_constant<__is_standard_layout(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_standard_layout_v = __is_standard_layout(_Ty);

	template<class _Ty>
	struct  is_literal_type
		: bool_constant<__is_literal_type(_Ty)>
	{
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Ty>
	constexpr bool is_literal_type_v = __is_literal_type(_Ty);
#pragma warning(pop)

	template<class _Ty>
	struct is_trivial
		: bool_constant<__is_trivial(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_trivial_v = __is_trivial(_Ty);

	template<class _Ty>
	struct is_trivially_copyable
		: bool_constant<__is_trivially_copyable(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_trivially_copyable_v = __is_trivially_copyable(_Ty);

	template<class _Ty>
	struct has_virtual_destructor
		: bool_constant<__has_virtual_destructor(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool has_virtual_destructor_v = __has_virtual_destructor(_Ty);

	template<class _Ty,
		class... _Args>
		struct is_constructible
		: bool_constant<__is_constructible(_Ty, _Args...)>
	{
	};

	template<class _Ty,
		class... _Args>
		constexpr bool is_constructible_v = __is_constructible(_Ty, _Args...);

	template<class _Ty>
	struct is_copy_constructible
		: bool_constant<__is_constructible(_Ty, add_lvalue_reference_t<const _Ty>)>
	{
	};

	template<class _Ty>
	constexpr bool is_copy_constructible_v = __is_constructible(_Ty, add_lvalue_reference_t<const _Ty>);

	template<class _Ty>
	struct is_default_constructible
		: bool_constant<__is_constructible(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_default_constructible_v = __is_constructible(_Ty);

	template<class _Ty,
		class = void>
		struct _Is_implicitly_default_constructible
		: false_type
	{
	};

	template<class _Ty>
	void _Implicitly_default_construct(const _Ty&);

	template<class _Ty>
	struct _Is_implicitly_default_constructible < _Ty, void_t<decltype(_Implicitly_default_construct<_Ty>({})) >>
		: true_type
	{
	};

	template<class _Ty>
	struct is_move_constructible
		: bool_constant<__is_constructible(_Ty, _Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_move_constructible_v = __is_constructible(_Ty, _Ty);

	template<class _To,
		class _From>
		struct is_assignable
		: bool_constant<__is_assignable(_To, _From)>
	{
	};

	template<class _To,
		class _From>
		constexpr bool is_assignable_v = __is_assignable(_To, _From);

	template<class _Ty>
	struct is_copy_assignable
		: bool_constant<__is_assignable(add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>)>
	{
	};

	template<class _Ty>
	constexpr bool is_copy_assignable_v =
		__is_assignable(add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>);

	template<class _Ty>
	struct is_move_assignable
		: bool_constant<__is_assignable(add_lvalue_reference_t<_Ty>, _Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_move_assignable_v = __is_assignable(add_lvalue_reference_t<_Ty>, _Ty);

	template<class _Ty>
	struct is_destructible
		: bool_constant<__is_destructible(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_destructible_v = __is_destructible(_Ty);

	template<class _Ty,
		class... _Args>
		struct is_trivially_constructible
		: bool_constant<__is_trivially_constructible(_Ty, _Args...)>
	{
	};

	template<class _Ty,
		class... _Args>
		constexpr bool is_trivially_constructible_v = __is_trivially_constructible(_Ty, _Args...);

	template<class _Ty>
	struct is_trivially_copy_constructible
		: bool_constant<__is_trivially_constructible(_Ty, add_lvalue_reference_t<const _Ty>)>
	{
	};

	template<class _Ty>
	constexpr bool is_trivially_copy_constructible_v =
		__is_trivially_constructible(_Ty, add_lvalue_reference_t<const _Ty>);

	template<class _Ty>
	struct is_trivially_default_constructible
		: bool_constant<__is_trivially_constructible(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_trivially_default_constructible_v = __is_trivially_constructible(_Ty);

	template<class _Ty>
	struct is_trivially_move_constructible
		: bool_constant<__is_trivially_constructible(_Ty, _Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_trivially_move_constructible_v = __is_trivially_constructible(_Ty, _Ty);

	template<class _To,
		class _From>
		struct is_trivially_assignable
		: bool_constant<__is_trivially_assignable(_To, _From)>
	{
	};

	template<class _To,
		class _From>
		constexpr bool is_trivially_assignable_v = __is_trivially_assignable(_To, _From);

	template<class _Ty>
	struct is_trivially_copy_assignable
		: bool_constant<__is_trivially_assignable(add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>)>
	{
	};

	template<class _Ty>
	constexpr bool is_trivially_copy_assignable_v =
		__is_trivially_assignable(add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>);

	template<class _Ty>
	struct is_trivially_move_assignable
		: bool_constant<__is_trivially_assignable(add_lvalue_reference_t<_Ty>, _Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_trivially_move_assignable_v =
		__is_trivially_assignable(add_lvalue_reference_t<_Ty>, _Ty);

	template<class _Ty>
	struct is_trivially_destructible
		: bool_constant<__is_trivially_destructible(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_trivially_destructible_v = __is_trivially_destructible(_Ty);

	template<class _Ty,
		class... _Args>
		struct is_nothrow_constructible
		: bool_constant<__is_nothrow_constructible(_Ty, _Args...)>
	{
	};

	template<class _Ty,
		class... _Args>
		constexpr bool is_nothrow_constructible_v = __is_nothrow_constructible(_Ty, _Args...);

	template<class _Ty>
	struct is_nothrow_copy_constructible
		: bool_constant<__is_nothrow_constructible(_Ty, add_lvalue_reference_t<const _Ty>)>
	{
	};

	template<class _Ty>
	constexpr bool is_nothrow_copy_constructible_v =
		__is_nothrow_constructible(_Ty, add_lvalue_reference_t<const _Ty>);

	template<class _Ty>
	struct is_nothrow_default_constructible
		: bool_constant<__is_nothrow_constructible(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_nothrow_default_constructible_v = __is_nothrow_constructible(_Ty);

	template<class _Ty>
	struct is_nothrow_move_constructible
		: bool_constant<__is_nothrow_constructible(_Ty, _Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_nothrow_move_constructible_v = __is_nothrow_constructible(_Ty, _Ty);

	template<class _To,
		class _From>
		struct is_nothrow_assignable
		: bool_constant<__is_nothrow_assignable(_To, _From)>
	{
	};

	template<class _To,
		class _From>
		constexpr bool is_nothrow_assignable_v = __is_nothrow_assignable(_To, _From);

	template<class _Ty>
	struct is_nothrow_copy_assignable
		: bool_constant<__is_nothrow_assignable(add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>)>
	{
	};

	template<class _Ty>
	constexpr bool is_nothrow_copy_assignable_v =
		__is_nothrow_assignable(add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>);

	template<class _Ty>
	struct is_nothrow_move_assignable
		: bool_constant<__is_nothrow_assignable(add_lvalue_reference_t<_Ty>, _Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_nothrow_move_assignable_v = __is_nothrow_assignable(add_lvalue_reference_t<_Ty>, _Ty);

	template<class _Ty>
	struct is_nothrow_destructible
		: bool_constant<__is_nothrow_destructible(_Ty)>
	{
	};

	template<class _Ty>
	constexpr bool is_nothrow_destructible_v = __is_nothrow_destructible(_Ty);

#pragma warning(push)
#pragma warning(disable: 4296)	
	template<class _Ty,
		bool = is_integral_v<_Ty>>
		struct _Sign_base
	{
		using _Uty = remove_cv_t<_Ty>;
		using _Signed = bool_constant < _Uty(-1) < _Uty(0) > ;
		using _Unsigned = bool_constant < _Uty(0) < _Uty(-1) > ;
	};
#pragma warning(pop)

	template<class _Ty>
	struct _Sign_base<_Ty, false>
	{

		using _Signed = typename is_floating_point<_Ty>::type;
		using _Unsigned = false_type;
	};

	template<class _Ty>
	struct is_signed
		: _Sign_base<_Ty>::_Signed
	{
	};

	template<class _Ty>
	constexpr bool is_signed_v = is_signed<_Ty>::value;

	template<class _Ty>
	struct is_unsigned
		: _Sign_base<_Ty>::_Unsigned
	{
	};

	template<class _Ty>
	constexpr bool is_unsigned_v = is_unsigned<_Ty>::value;

	template<class _Ty>
	using _Is_nonbool_integral =
		bool_constant<is_integral_v<_Ty>
		&& !is_same_v<remove_cv_t<_Ty>, bool>>;

	template<class _Ty>
	struct _Change_sign
	{
		static_assert(_Is_nonbool_integral<_Ty>::value || is_enum_v<_Ty>,
			"make_signed<T>/make_unsigned<T> require that T shall be a (possibly "
			"cv-qualified) integral type or enumeration but not a bool type.");

		using _Signed =
			conditional_t<_Is_any_of_v<_Ty, long, unsigned long>, long,
			conditional_t<sizeof(_Ty) == 1, signed char,
			conditional_t<sizeof(_Ty) == 2, short,
			conditional_t<sizeof(_Ty) == 4, int,
			long long
			>>>>;

		using _Unsigned =
			conditional_t<_Is_any_of_v<_Ty, long, unsigned long>, unsigned long,
			conditional_t<sizeof(_Ty) == 1, unsigned char,
			conditional_t<sizeof(_Ty) == 2, unsigned short,
			conditional_t<sizeof(_Ty) == 4, unsigned int,
			unsigned long long
			>>>>;
	};

	template<class _Ty>
	struct _Change_sign<const _Ty>
	{
		using _Signed = const typename _Change_sign<_Ty>::_Signed;
		using _Unsigned = const typename _Change_sign<_Ty>::_Unsigned;
	};

	template<class _Ty>
	struct _Change_sign<volatile _Ty>
	{
		using _Signed = volatile typename _Change_sign<_Ty>::_Signed;
		using _Unsigned = volatile typename _Change_sign<_Ty>::_Unsigned;
	};

	template<class _Ty>
	struct _Change_sign<const volatile _Ty>
	{
		using _Signed = const volatile typename _Change_sign<_Ty>::_Signed;
		using _Unsigned = const volatile typename _Change_sign<_Ty>::_Unsigned;
	};

	template<class _Ty>
	struct make_signed
	{
		using type = typename _Change_sign<_Ty>::_Signed;
	};

	template<class _Ty>
	using make_signed_t = typename make_signed<_Ty>::type;

	template<class _Ty>
	struct make_unsigned
	{
		using type = typename _Change_sign<_Ty>::_Unsigned;
	};

	template<class _Ty>
	using make_unsigned_t = typename make_unsigned<_Ty>::type;

	template<class _Rep>
	constexpr make_unsigned_t<_Rep> _Unsigned_value(_Rep _Val)
	{
		return (static_cast<make_unsigned_t<_Rep>>(_Val));
	}

	template<class _Ty>
	struct alignment_of
		: integral_constant<size_t, alignof(_Ty)>
	{
	};

	template<class _Ty>
	constexpr size_t alignment_of_v = alignof(_Ty);

	template<class _Ty,
		size_t _Len>
		union _Align_type
	{
		_Ty _Val;
		char _Pad[_Len];
	};

	template<size_t _Len,
		size_t _Align,
		class _Ty,
		bool _Ok>
		struct _Aligned;

	template<size_t _Len,
		size_t _Align,
		class _Ty>
		struct _Aligned<_Len, _Align, _Ty, true>
	{
		using type = _Align_type<_Ty, _Len>;
	};

	template<size_t _Len,
		size_t _Align>
		struct _Aligned<_Len, _Align, double, false>
	{

		static_assert(_Always_false<_Aligned>,
			"You've instantiated std::aligned_storage<Len, Align> with an extended alignment (in other "
			"words, Align > alignof(max_align_t)). Before VS 2017 15.8, the member type would "
			"non-conformingly have an alignment of only alignof(max_align_t). VS 2017 15.8 was fixed to "
			"handle this correctly, but the fix inherently changes layout and breaks binary compatibility "
			"(*only* for uses of aligned_storage with extended alignments). "
			"Please define either "
			"(1) _ENABLE_EXTENDED_ALIGNED_STORAGE to acknowledge that you understand this message and "
			"that you actually want a type with an extended alignment, or "
			"(2) _DISABLE_EXTENDED_ALIGNED_STORAGE to silence this message and get the old non-conformant "
			"behavior.");

		using type = _Align_type<max_align_t, _Len>;

	};

	template<size_t _Len,
		size_t _Align>
		struct _Aligned<_Len, _Align, int, false>
	{
		using type = typename _Aligned<_Len, _Align, double, _Align <= alignof(double)>::type;
	};

	template<size_t _Len,
		size_t _Align>
		struct _Aligned<_Len, _Align, short, false>
	{
		using type = typename _Aligned<_Len, _Align, int, _Align <= alignof(int)>::type;
	};

	template<size_t _Len,
		size_t _Align>
		struct _Aligned<_Len, _Align, char, false>
	{
		using type = typename _Aligned<_Len, _Align, short, _Align <= alignof(short)>::type;
	};

	template<size_t _Len,
		size_t _Align = alignof(max_align_t)>
		struct aligned_storage
	{
		using type = typename _Aligned<_Len, _Align, char, _Align <= alignof(char)>::type;
	};

	template<size_t _Len,
		size_t _Align = alignof(max_align_t)>
		using aligned_storage_t = typename aligned_storage<_Len, _Align>::type;

	template<size_t... _Vals>
	struct _Maximum;

	template<>
	struct _Maximum<>
		: integral_constant<size_t, 0>
	{
	};

	template<size_t _Val>
	struct _Maximum<_Val>
		: integral_constant<size_t, _Val>
	{
	};

	template<size_t _First,
		size_t _Second,
		size_t... _Rest>
		struct _Maximum<_First, _Second, _Rest...>
		: _Maximum<(_First < _Second ? _Second : _First), _Rest...>::type
	{
	};

	template<size_t _Len,
		class... _Types>
		struct aligned_union
	{
		static constexpr size_t _Max_len = _Maximum<_Len, sizeof(_Types)...>::value;
		static constexpr size_t alignment_value = _Maximum<alignof(_Types)...>::value;
		using type = aligned_storage_t<_Max_len, alignment_value>;
	};

	template<size_t _Len,
		class... _Types>
		using aligned_union_t = typename aligned_union<_Len, _Types...>::type;

	template<class _Ty>
	struct underlying_type
	{
		using type = __underlying_type(_Ty);
	};

	template<class _Ty>
	using underlying_type_t = typename underlying_type<_Ty>::type;

	template<class _Ty>
	struct rank
		: integral_constant<size_t, 0>
	{
	};

	template<class _Ty, size_t _Ix>
	struct rank<_Ty[_Ix]>
		: integral_constant<size_t, rank<_Ty>::value + 1>
	{
	};

	template<class _Ty>
	struct rank<_Ty[]>
		: integral_constant<size_t, rank<_Ty>::value + 1>
	{
	};

	template<class _Ty>
	constexpr size_t rank_v = rank<_Ty>::value;

	template<class _Ty, unsigned int _Nx>
	struct _Extent
		: integral_constant<size_t, 0>
	{
	};

	template<class _Ty, size_t _Ix>
	struct _Extent<_Ty[_Ix], 0>
		: integral_constant<size_t, _Ix>
	{
	};

	template<class _Ty, unsigned int _Nx, size_t _Ix>
	struct _Extent<_Ty[_Ix], _Nx>
		: _Extent<_Ty, _Nx - 1>
	{
	};

	template<class _Ty, unsigned int _Nx>
	struct _Extent<_Ty[], _Nx>
		: _Extent<_Ty, _Nx - 1>
	{
	};

	template<class _Ty, unsigned int _Nx = 0>
	struct extent
		: _Extent<_Ty, _Nx>
	{
	};

	template<class _Ty,
		unsigned int _Ix = 0>
		constexpr size_t extent_v = extent<_Ty, _Ix>::value;

	template<class _Base,
		class _Derived>
		struct is_base_of
		: bool_constant<__is_base_of(_Base, _Derived)>
	{
	};

	template<class _Base,
		class _Derived>
		constexpr bool is_base_of_v = __is_base_of(_Base, _Derived);

	template<class _Ty>
	struct decay
	{
		using _Ty1 = remove_reference_t<_Ty>;

		using type = conditional_t<is_array_v<_Ty1>,
			add_pointer_t<remove_extent_t<_Ty1>>,
			conditional_t<is_function_v<_Ty1>,
			add_pointer_t<_Ty1>,
			remove_cv_t<_Ty1>>>;
	};

	template<class _Ty>
	using decay_t = typename decay<_Ty>::type;

	template<class _Ty1,
		class _Ty2,
		class = void>
		struct _Decayed_cond_oper
	{
	};

	template<class _Ty1,
		class _Ty2>
		struct _Decayed_cond_oper<_Ty1, _Ty2, void_t<decltype(false ? ::std::declval<_Ty1>() : ::std::declval<_Ty2>())>>
	{
		using type = decay_t<decltype(false ? ::std::declval<_Ty1>() : ::std::declval<_Ty2>())>;
	};

	template<class... _Ty>
	struct common_type;

	template<class... _Ty>
	using common_type_t = typename common_type<_Ty...>::type;

	template<>
	struct common_type<>
	{
	};

	template<class _Ty1>
	struct common_type<_Ty1>
		: common_type<_Ty1, _Ty1>
	{
	};

	template<class _Ty1,
		class _Ty2,
		class _Decayed1 = decay_t<_Ty1>,
		class _Decayed2 = decay_t<_Ty2>>
		struct _Common_type2
		: common_type<_Decayed1, _Decayed2>
	{
	};

	template<class _Ty1,
		class _Ty2>
		struct _Common_type2<_Ty1, _Ty2, _Ty1, _Ty2>
		: _Decayed_cond_oper<_Ty1, _Ty2>
	{
	};

	template<class _Ty1,
		class _Ty2>
		struct common_type<_Ty1, _Ty2>
		: _Common_type2<_Ty1, _Ty2>
	{
	};

	template<class _Void,
		class _Ty1,
		class _Ty2,
		class... _Rest>
		struct _Common_type3
	{
	};

	template<class _Ty1,
		class _Ty2,
		class... _Rest>
		struct _Common_type3<void_t<common_type_t<_Ty1, _Ty2>>, _Ty1, _Ty2, _Rest...>
		: common_type<common_type_t<_Ty1, _Ty2>, _Rest...>
	{
	};

	template<class _Ty1,
		class _Ty2,
		class... _Rest>
		struct common_type<_Ty1, _Ty2, _Rest...>
		: _Common_type3<void, _Ty1, _Ty2, _Rest...>
	{
	};

	template<class _Ty>
	struct[[deprecated("warning STL4003: " "The non-Standard std::identity struct is deprecated and will be REMOVED. You can " "define _SILENCE_IDENTITY_STRUCT_DEPRECATION_WARNING to acknowledge that you have received this warning.")]] identity
	{
	using type = _Ty;

	const _Ty& operator()(const _Ty& _Left) const
		{
		return (_Left);
		}
	};

	template<class _Ty>
	struct _Identity
	{
		using type = _Ty;
	};
	template<class _Ty>
	using _Identity_t = typename _Identity<_Ty>::type;

	template<class _Type,
		template <class...> class _Template>
	constexpr bool _Is_specialization_v = false;
	template<template <class...> class _Template,
		class... _Types>
		constexpr bool _Is_specialization_v<_Template<_Types...>, _Template> = true;

	template<class _Type,
		template <class...> class _Template>
	struct _Is_specialization
		: bool_constant<_Is_specialization_v<_Type, _Template>>
	{};

	template<class _Ty>
	constexpr _Ty&& forward(remove_reference_t<_Ty>& _Arg) noexcept
	{
		return (static_cast<_Ty&&>(_Arg));
	}

	template<class _Ty>
	constexpr _Ty&& forward(remove_reference_t<_Ty>&& _Arg) noexcept
	{
		static_assert(!is_lvalue_reference_v<_Ty>, "bad forward call");
		return (static_cast<_Ty&&>(_Arg));
	}

	template<class _Ty>
	constexpr remove_reference_t<_Ty>&&
		move(_Ty&& _Arg) noexcept
	{
		return (static_cast<remove_reference_t<_Ty>&&>(_Arg));
	}

	template<class _Ty>
	constexpr conditional_t<!is_nothrow_move_constructible_v<_Ty> && is_copy_constructible_v<_Ty>,
		const _Ty&, _Ty&&>
		move_if_noexcept(_Ty& _Arg) noexcept
	{
		return (::std::move(_Arg));
	}

	template<class _Ty>
	class reference_wrapper;

	template<class _Callable,
		class... _Types>
		struct _Invoker;

	template<class _Callable,
		class... _Types> inline
		auto invoke(_Callable&& _Obj, _Types&&... _Args)
		noexcept(noexcept(_Invoker<_Callable, _Types...>::_Call(::std::forward<_Callable>(_Obj), ::std::forward<_Types>(_Args)...)))

		-> decltype(_Invoker<_Callable, _Types...>::_Call(
			::std::forward<_Callable>(_Obj), ::std::forward<_Types>(_Args)...));

	struct _Unforced
	{
	};

	template<class _To>
	void _Implicitly_convert_to(_To) noexcept;

	template<class _From,
		class _To,
		bool = is_convertible_v<_From, _To>>
		struct _Is_nothrow_convertible
		: bool_constant<noexcept(_Implicitly_convert_to<_To>(::std::declval<_From>()))>
	{
	};

	template<class _From,
		class _To>
		struct _Is_nothrow_convertible<_From, _To, false>
		: false_type
	{
	};

	template<class _Void,
		class... _Types>
		struct _Invoke_traits
	{
		using _Is_invocable = false_type;
		using _Is_nothrow_invocable = false_type;
		template<class _Rx>
		using _Is_invocable_r = false_type;
		template<class _Rx>
		using _Is_nothrow_invocable_r = false_type;
	};

	template<class... _Types>
	struct _Invoke_traits<void_t<decltype(::std::invoke(::std::declval<_Types>()...))>, _Types...>
	{
		using type = decltype(::std::invoke(::std::declval<_Types>()...));
		using _Is_invocable = true_type;
		using _Is_nothrow_invocable = bool_constant<noexcept(::std::invoke(::std::declval<_Types>()...))>;
		template<class _Rx>
		using _Is_invocable_r = bool_constant<disjunction_v<is_void<_Rx>, is_convertible<type, _Rx>>>;
		template<class _Rx>
		using _Is_nothrow_invocable_r = bool_constant<conjunction_v<
			_Is_nothrow_invocable,
			disjunction<is_void<_Rx>, _Is_nothrow_convertible<type, _Rx>>>>;
	};

	template<class _Fty>
	struct  result_of
	{
		static_assert(_Always_false<_Fty>,
			"result_of<CallableType> is invalid; use "
			"result_of<CallableType(zero or more argument types)> instead.");
	};

	template<class _Callable, class... _Args> struct  result_of<_Callable __cdecl (_Args...)> : _Invoke_traits<void, _Callable, _Args...> { };  template<class _Callable, class... _Args> struct  result_of<_Callable __fastcall (_Args...)> : _Invoke_traits<void, _Callable, _Args...> { }; template<class _Callable, class... _Args> struct  result_of<_Callable __stdcall (_Args...)> : _Invoke_traits<void, _Callable, _Args...> { }; template<class _Callable, class... _Args> struct  result_of<_Callable __vectorcall (_Args...)> : _Invoke_traits<void, _Callable, _Args...> { };

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Ty>
	using result_of_t = typename result_of<_Ty>::type;
#pragma warning(pop)

	template<class _Callable,
		class... _Args>
		using _Invoke_result_t = typename _Invoke_traits<void, _Callable, _Args...>::type;

	template<class _Rx,
		class _Callable,
		class... _Args>
		using _Is_invocable_r_ = typename _Invoke_traits<void, _Callable, _Args...>::template _Is_invocable_r<_Rx>;

	template<class _Rx,
		class _Callable,
		class... _Args>
		struct _Is_invocable_r
		: _Is_invocable_r_<_Rx, _Callable, _Args...>
	{
	};

	template<class _Ty,
		class = void>
		struct _Weak_result_type
	{
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Ty>
	struct _Weak_result_type<_Ty, void_t<
		typename _Ty::result_type>>
	{
		typedef typename _Ty::result_type result_type;
	};
#pragma warning(pop)

	template<class _Ty,
		class = void>
		struct _Weak_argument_type
		: _Weak_result_type<_Ty>
	{
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Ty>
	struct _Weak_argument_type<_Ty, void_t<
		typename _Ty::argument_type>>
		: _Weak_result_type<_Ty>
	{
		typedef typename _Ty::argument_type argument_type;
	};
#pragma warning(pop)

	template<class _Ty,
		class = void>
		struct _Weak_binary_args
		: _Weak_argument_type<_Ty>
	{
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Ty>
	struct _Weak_binary_args<_Ty, void_t<
		typename _Ty::first_argument_type,
		typename _Ty::second_argument_type>>
		: _Weak_argument_type<_Ty>
	{
		typedef typename _Ty::first_argument_type first_argument_type;
		typedef typename _Ty::second_argument_type second_argument_type;
	};
#pragma warning(pop)

	template<class _Ty>
	struct _Weak_types
	{
		using _Is_f_or_pf = _Is_function<remove_pointer_t<_Ty>>;
		using _Is_pmf = _Is_memfunptr<remove_cv_t<_Ty>>;
		using type = conditional_t<_Is_f_or_pf::_Bool_type::value, _Is_f_or_pf,
			conditional_t<_Is_pmf::_Bool_type::value, _Is_pmf,
			_Weak_binary_args<_Ty>>>;
	};

	template<class _Ty>
	void _Refwrap_ctor_fun(_Identity_t<_Ty&>) noexcept;
	template<class _Ty>
	void _Refwrap_ctor_fun(_Identity_t<_Ty&&>) = delete;

	struct _Unique_tag_refwrap_has_ctor_from
	{
	};

	template<class _Ty,
		class _Uty,
		class = void>
		struct _Refwrap_has_ctor_from
		: false_type
	{
	};

	template<class _Ty,
		class _Uty>
		struct _Refwrap_has_ctor_from<_Ty, _Uty, void_t<
		_Unique_tag_refwrap_has_ctor_from,
		decltype(_Refwrap_ctor_fun<_Ty>(::std::declval<_Uty>()))>>
		: true_type
	{
	};

	template<class _Ty>
	class reference_wrapper
		: public _Weak_types<_Ty>::type
	{
	public:
		static_assert(is_object_v<_Ty> || is_function_v<_Ty>,
			"reference_wrapper<T> requires T to be an object type or a function type.");

		using type = _Ty;

		template<class _Uty,
			enable_if_t<conjunction_v<
			negation<is_same<remove_cv_t<remove_reference_t<_Uty>>, reference_wrapper>>,
			_Refwrap_has_ctor_from<_Ty, _Uty>>, int> = 0>
			reference_wrapper(_Uty&& _Val)
			noexcept(noexcept(_Refwrap_ctor_fun<_Ty>(::std::declval<_Uty>())))
		{
			_Ty& _Ref = ::std::forward<_Uty>(_Val);
			_Ptr = ::std::addressof(_Ref);
		}

		operator _Ty&() const noexcept
		{
			return (*_Ptr);
		}

		_Ty& get() const noexcept
		{
			return (*_Ptr);
		}

		template<class... _Types>
		auto operator()(_Types&&... _Args) const
			-> decltype(::std::invoke(get(), ::std::forward<_Types>(_Args)...))
		{
			return (::std::invoke(get(), ::std::forward<_Types>(_Args)...));
		}

	private:
		_Ty * _Ptr;
	};

	template<class _Ty>
	inline reference_wrapper<_Ty> ref(_Ty& _Val) noexcept
	{
		return (reference_wrapper<_Ty>(_Val));
	}

	template<class _Ty>
	void ref(const _Ty&&) = delete;

	template<class _Ty>
	inline reference_wrapper<_Ty> ref(reference_wrapper<_Ty> _Val) noexcept
	{
		return (::std::ref(_Val.get()));
	}

	template<class _Ty>
	inline reference_wrapper<const _Ty> cref(const _Ty& _Val) noexcept
	{
		return (reference_wrapper<const _Ty>(_Val));
	}

	template<class _Ty>
	void cref(const _Ty&&) = delete;

	template<class _Ty>
	inline reference_wrapper<const _Ty> cref(reference_wrapper<_Ty> _Val) noexcept
	{
		return (::std::cref(_Val.get()));
	}

	template<class _Ty>
	struct _Is_swappable;

	template<class _Ty>
	struct _Is_nothrow_swappable;

	template<class _Ty,
		class = void> inline

		void swap(_Ty&, _Ty&)
		noexcept(is_nothrow_move_constructible_v<_Ty> && is_nothrow_move_assignable_v<_Ty>);

	template<class _Ty,
		size_t _Size,
		class = enable_if_t<_Is_swappable<_Ty>::value>> inline
		void swap(_Ty(&)[_Size], _Ty(&)[_Size])
		noexcept(_Is_nothrow_swappable<_Ty>::value);

	template<class _Ty1,
		class _Ty2,
		class = void>
		struct _Swappable_with_helper
		: false_type
	{
	};

	template<class _Ty1,
		class _Ty2>
		struct _Swappable_with_helper<_Ty1, _Ty2, void_t<decltype(swap(::std::declval<_Ty1>(), ::std::declval<_Ty2>()))>>
		: true_type
	{
	};

	template<class _Ty1,
		class _Ty2>
		struct _Is_swappable_with
		: bool_constant<conjunction_v<
		_Swappable_with_helper<_Ty1, _Ty2>,
		_Swappable_with_helper<_Ty2, _Ty1>>>
	{

	};

	template<class _Ty>
	struct _Is_swappable
		: _Is_swappable_with<
		add_lvalue_reference_t<_Ty>,
		add_lvalue_reference_t<_Ty>>::type
	{
	};

	template<class _Ty1,
		class _Ty2>
		struct _Swap_cannot_throw
		: bool_constant<noexcept(swap(::std::declval<_Ty1>(), ::std::declval<_Ty2>()))
		&& noexcept(swap(::std::declval<_Ty2>(), ::std::declval<_Ty1>()))>
	{

	};

	template<class _Ty1,
		class _Ty2>
		struct _Is_nothrow_swappable_with
		: bool_constant<conjunction_v<
		_Is_swappable_with<_Ty1, _Ty2>,
		_Swap_cannot_throw<_Ty1, _Ty2>>>
	{

	};

	template<class _Ty>
	struct _Is_nothrow_swappable
		: _Is_nothrow_swappable_with<
		add_lvalue_reference_t<_Ty>,
		add_lvalue_reference_t<_Ty>>::type
	{
	};

	namespace _Has_ADL_swap_detail {
		void swap();

		template<class,
			class = void>
			struct _Has_ADL_swap
			: false_type
		{};
		template<class _Ty>
		struct _Has_ADL_swap<_Ty, void_t<decltype(swap(::std::declval<_Ty&>(), ::std::declval<_Ty&>()))>>
			: true_type
		{};
	}
	using _Has_ADL_swap_detail::_Has_ADL_swap;

	template<class _Ty>
	struct _Is_trivially_swappable
		: bool_constant<conjunction_v<
		is_trivially_destructible<_Ty>,
		is_trivially_move_constructible<_Ty>,
		is_trivially_move_assignable<_Ty>,
		negation<_Has_ADL_swap<_Ty>>>>
	{

	};

	template<class _Ty>
	constexpr bool _Is_trivially_swappable_v = _Is_trivially_swappable<_Ty>::value;

	constexpr size_t _FNV_offset_basis = 2166136261U;
	constexpr size_t _FNV_prime = 16777619U;

	inline size_t _Fnv1a_append_bytes(size_t _Val,
		const unsigned char * const _First, const size_t _Count) noexcept
	{
		for (size_t _Idx = 0; _Idx < _Count; ++_Idx)
		{
			_Val ^= static_cast<size_t>(_First[_Idx]);
			_Val *= _FNV_prime;
		}

		return (_Val);
	}

	template<class _Ty>
	inline size_t _Fnv1a_append_range(const size_t _Val,
		const _Ty * const _First, const _Ty * const _Last) noexcept
	{
		static_assert(is_trivial_v<_Ty>, "Only trivial types can be directly hashed.");
		const auto _Firstb = reinterpret_cast<const unsigned char *>(_First);
		const auto _Lastb = reinterpret_cast<const unsigned char *>(_Last);
		return (_Fnv1a_append_bytes(_Val, _Firstb, static_cast<size_t>(_Lastb - _Firstb)));
	}

	template<class _Kty>
	inline size_t _Fnv1a_append_value(const size_t _Val, const _Kty& _Keyval) noexcept
	{
		static_assert(is_trivial_v<_Kty>, "Only trivial types can be directly hashed.");
		return (_Fnv1a_append_bytes(_Val,
			&reinterpret_cast<const unsigned char&>(_Keyval), sizeof(_Kty)));
	}

	template<class _Kty>
	inline size_t _Hash_representation(const _Kty& _Keyval) noexcept
	{
		return (_Fnv1a_append_value(_FNV_offset_basis, _Keyval));
	}

	template<class _Kty>
	inline size_t _Hash_array_representation(
		const _Kty * const _First, const size_t _Count) noexcept
	{
		static_assert(is_trivial_v<_Kty>, "Only trivial types can be directly hashed.");
		return (_Fnv1a_append_bytes(_FNV_offset_basis,
			reinterpret_cast<const unsigned char *>(_First), _Count * sizeof(_Kty)));
	}

	template<class _Kty>
	struct hash;

	template<class _Kty,
		bool _Enabled>
		struct _Conditionally_enabled_hash
	{
		typedef _Kty argument_type;
		typedef size_t result_type;

		size_t operator()(const _Kty& _Keyval) const
			noexcept(noexcept(hash<_Kty>::_Do_hash(_Keyval)))
		{
			return (hash<_Kty>::_Do_hash(_Keyval));
		}
	};

	template<class _Kty>
	struct _Conditionally_enabled_hash<_Kty, false>
	{
		_Conditionally_enabled_hash() = delete;
		_Conditionally_enabled_hash(const _Conditionally_enabled_hash&) = delete;
		_Conditionally_enabled_hash(_Conditionally_enabled_hash&&) = delete;
		_Conditionally_enabled_hash& operator=(const _Conditionally_enabled_hash&) = delete;
		_Conditionally_enabled_hash& operator=(_Conditionally_enabled_hash&&) = delete;
	};

	template<class _Kty>
	struct hash
		: _Conditionally_enabled_hash<_Kty, !is_const_v<_Kty> && !is_volatile_v<_Kty>
		&& (is_enum_v<_Kty> || is_integral_v<_Kty> || is_pointer_v<_Kty>)>
	{
		static size_t _Do_hash(const _Kty& _Keyval) noexcept
		{
			return (_Hash_representation(_Keyval));
		}
	};

	template<>
	struct hash<float>
	{
		typedef float argument_type;
		typedef size_t result_type;
		size_t operator()(const float _Keyval) const noexcept
		{
			return (_Hash_representation(_Keyval == 0.0F ? 0.0F : _Keyval));
		}
	};

	template<>
	struct hash<double>
	{
		typedef double argument_type;
		typedef size_t result_type;
		size_t operator()(const double _Keyval) const noexcept
		{
			return (_Hash_representation(_Keyval == 0.0 ? 0.0 : _Keyval));
		}
	};

	template<>
	struct hash<long double>
	{
		typedef long double argument_type;
		typedef size_t result_type;
		size_t operator()(const long double _Keyval) const noexcept
		{
			return (_Hash_representation(_Keyval == 0.0L ? 0.0L : _Keyval));
		}
	};

	template<>
	struct hash<nullptr_t>
	{
		typedef nullptr_t argument_type;
		typedef size_t result_type;
		size_t operator()(nullptr_t) const noexcept
		{
			void * _Null{};
			return (_Hash_representation(_Null));
		}
	};

	template<class _Kty,
		class = void>
		struct _Is_nothrow_hashable
		: false_type
	{
	};

	template<class _Kty>
	struct _Is_nothrow_hashable < _Kty, void_t<decltype(hash<_Kty>{}(::std::declval<const _Kty&>())) >>
		: bool_constant < noexcept(hash<_Kty>{}(::std::declval<const _Kty&>())) >
	{
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	namespace[[deprecated("warning STL4002: " "The non-Standard std::tr1 namespace and TR1-only machinery are deprecated and will be REMOVED. You can " "define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING to acknowledge that you have received this warning.")]] tr1{
	using ::std::add_const;
	using ::std::add_cv;
	using ::std::add_pointer;
	using ::std::add_volatile;
	using ::std::aligned_storage;
	using ::std::alignment_of;
	using ::std::conditional;
	using ::std::decay;
	using ::std::enable_if;
	using ::std::extent;
	using ::std::false_type;
	using ::std::has_virtual_destructor;
	using ::std::integral_constant;
	using ::std::is_abstract;
	using ::std::is_arithmetic;
	using ::std::is_array;
	using ::std::is_base_of;
	using ::std::is_class;
	using ::std::is_compound;
	using ::std::is_const;
	using ::std::is_convertible;
	using ::std::is_empty;
	using ::std::is_enum;
	using ::std::is_floating_point;
	using ::std::is_function;
	using ::std::is_fundamental;
	using ::std::is_integral;
	using ::std::is_member_function_pointer;
	using ::std::is_member_object_pointer;
	using ::std::is_member_pointer;
	using ::std::is_object;
	using ::std::is_pod;
	using ::std::is_pointer;
	using ::std::is_polymorphic;
	using ::std::is_reference;
	using ::std::is_same;
	using ::std::is_scalar;
	using ::std::is_signed;
	using ::std::is_union;
	using ::std::is_unsigned;
	using ::std::is_void;
	using ::std::is_volatile;
	using ::std::make_signed;
	using ::std::make_unsigned;
	using ::std::rank;
	using ::std::remove_all_extents;
	using ::std::remove_const;
	using ::std::remove_cv;
	using ::std::remove_extent;
	using ::std::remove_pointer;
	using ::std::remove_reference;
	using ::std::remove_volatile;
	using ::std::true_type;
	using ::std::cref;
	using ::std::ref;
	using ::std::reference_wrapper;
	using ::std::result_of;
	using ::std::hash;
	}
#pragma warning(pop)

		struct _Invoker_pmf_object
	{
		template<class _Decayed, class _Ty1, class... _Types2>
		static inline auto _Call(_Decayed _Pmf, _Ty1&& _Arg1, _Types2&&... _Args2)
			noexcept(noexcept((::std::forward<_Ty1>(_Arg1).*_Pmf)(::std::forward<_Types2>(_Args2)...)))
			-> decltype((::std::forward<_Ty1>(_Arg1).*_Pmf)(::std::forward<_Types2>(_Args2)...))
		{
			return ((::std::forward<_Ty1>(_Arg1).*_Pmf)(::std::forward<_Types2>(_Args2)...));
		}
	};
	struct _Invoker_pmf_refwrap
	{
		template<class _Decayed, class _Ty1, class... _Types2>
		static inline auto _Call(_Decayed _Pmf, _Ty1&& _Arg1, _Types2&&... _Args2)
			noexcept(noexcept((::std::forward<_Ty1>(_Arg1).get().*_Pmf)(::std::forward<_Types2>(_Args2)...)))
			-> decltype((::std::forward<_Ty1>(_Arg1).get().*_Pmf)(::std::forward<_Types2>(_Args2)...))
		{
			return ((::std::forward<_Ty1>(_Arg1).get().*_Pmf)(::std::forward<_Types2>(_Args2)...));
		}
	};
	struct _Invoker_pmf_pointer
	{
		template<class _Decayed, class _Ty1, class... _Types2>
		static inline auto _Call(_Decayed _Pmf, _Ty1&& _Arg1, _Types2&&... _Args2)
			noexcept(noexcept(((*::std::forward<_Ty1>(_Arg1)).*_Pmf)(::std::forward<_Types2>(_Args2)...))) ->
			decltype(((*::std::forward<_Ty1>(_Arg1)).*_Pmf)(::std::forward<_Types2>(_Args2)...))
		{
			return (((*::std::forward<_Ty1>(_Arg1)).*_Pmf)(::std::forward<_Types2>(_Args2)...));
		}
	};
	struct _Invoker_pmd_object
	{
		template<class _Decayed, class _Ty1>
		static inline auto _Call(_Decayed _Pmd, _Ty1&& _Arg1)
			noexcept(noexcept(::std::forward<_Ty1>(_Arg1).*_Pmd))
			-> decltype(::std::forward<_Ty1>(_Arg1).*_Pmd)
		{
			return (::std::forward<_Ty1>(_Arg1).*_Pmd);
		}
	};
	struct _Invoker_pmd_refwrap
	{
		template<class _Decayed, class _Ty1>
		static inline auto _Call(_Decayed _Pmd, _Ty1&& _Arg1)
			noexcept(noexcept(::std::forward<_Ty1>(_Arg1).get().*_Pmd))
			-> decltype(::std::forward<_Ty1>(_Arg1).get().*_Pmd)
		{
			return (::std::forward<_Ty1>(_Arg1).get().*_Pmd);
		}
	};
	struct _Invoker_pmd_pointer
	{
		template<class _Decayed, class _Ty1>
		static inline auto _Call(_Decayed _Pmd, _Ty1&& _Arg1)
			noexcept(noexcept((*::std::forward<_Ty1>(_Arg1)).*_Pmd))
			-> decltype((*::std::forward<_Ty1>(_Arg1)).*_Pmd)
		{
			return ((*::std::forward<_Ty1>(_Arg1)).*_Pmd);
		}
	};
	struct _Invoker_functor
	{
		template<class _Callable, class... _Types>
		static inline auto _Call(_Callable&& _Obj, _Types&&... _Args)
			noexcept(noexcept(::std::forward<_Callable>(_Obj)(::std::forward<_Types>(_Args)...)))
			-> decltype(::std::forward<_Callable>(_Obj)(::std::forward<_Types>(_Args)...))
		{
			return (::std::forward<_Callable>(_Obj)(::std::forward<_Types>(_Args)...));
		}
	};
	template<class _Callable,
		class _Ty1,
		class _Removed_cvref = remove_cv_t<remove_reference_t<_Callable>>,
		bool _Is_pmf = is_member_function_pointer_v<_Removed_cvref>,
		bool _Is_pmd = is_member_object_pointer_v<_Removed_cvref>>
		struct _Invoker1;
	template<class _Callable,
		class _Ty1,
		class _Removed_cvref>
		struct _Invoker1<_Callable, _Ty1, _Removed_cvref, true, false>
		: conditional_t<is_base_of_v< typename _Is_memfunptr<_Removed_cvref>::_Class_type, remove_reference_t<_Ty1>>,
		_Invoker_pmf_object, conditional_t<_Is_specialization_v<remove_cv_t<remove_reference_t<_Ty1>>, reference_wrapper>,
		_Invoker_pmf_refwrap, _Invoker_pmf_pointer >> { };

	template<class _Callable, class _Ty1, class _Removed_cvref> struct _Invoker1<_Callable, _Ty1, _Removed_cvref, false, true> : conditional_t<is_base_of_v< typename _Is_member_object_pointer<_Removed_cvref>::_Class_type, remove_reference_t<_Ty1>>, _Invoker_pmd_object, conditional_t<_Is_specialization_v<remove_cv_t<remove_reference_t<_Ty1>>, reference_wrapper>, _Invoker_pmd_refwrap, _Invoker_pmd_pointer >> { }; template<class _Callable, class _Ty1, class _Removed_cvref> struct _Invoker1<_Callable, _Ty1, _Removed_cvref, false, false> : _Invoker_functor { }; template<class _Callable, class... _Types> struct _Invoker; template<class _Callable> struct _Invoker<_Callable> : _Invoker_functor { }; template<class _Callable, class _Ty1, class... _Types2> struct _Invoker<_Callable, _Ty1, _Types2...> : _Invoker1<_Callable, _Ty1> { }; template<class _Callable, class... _Types> inline auto invoke(_Callable&& _Obj, _Types&&... _Args) noexcept(noexcept(_Invoker<_Callable, _Types...>::_Call(::std::forward<_Callable>(_Obj), ::std::forward<_Types>(_Args)...))) -> decltype(_Invoker<_Callable, _Types...>::_Call(::std::forward<_Callable>(_Obj), ::std::forward<_Types>(_Args)...)) { return (_Invoker<_Callable, _Types...>::_Call(::std::forward<_Callable>(_Obj), ::std::forward<_Types>(_Args)...)); }

	template<class _Rx,
		bool = is_void_v<_Rx>>
		struct _Invoker_ret
	{
	};

	template<class _Cv_void>
	struct _Invoker_ret<_Cv_void, true>
	{
		template<class... _Valtys>
		static void _Call(_Valtys&&... _Vals)

		{

			::std::invoke(::std::forward<_Valtys>(_Vals)...);

		}
	};

	template<class _Rx>
	struct _Invoker_ret<_Rx, false>
	{
		template<class... _Valtys>
		static _Rx _Call(_Valtys&&... _Vals)

		{

			return (::std::invoke(::std::forward<_Valtys>(_Vals)...));

		}
	};

	template<>
	struct _Invoker_ret<_Unforced, false>
	{
		template<class... _Valtys>
		static auto _Call(_Valtys&&... _Vals)
			-> decltype(::std::invoke(::std::forward<_Valtys>(_Vals)...))

		{

			return (::std::invoke(::std::forward<_Valtys>(_Vals)...));

		}
	};

}

#pragma warning(pop)
#pragma pack(pop)

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {

	bool __cdecl uncaught_exception() noexcept;
	int __cdecl uncaught_exceptions() noexcept;

}

#pragma once

__pragma(pack(push, 8)) extern "C" {

	typedef struct _heapinfo
	{
		int* _pentry;
		size_t _size;
		int _useflag;
	} _HEAPINFO;

	void* __cdecl _alloca(size_t _Size);

	__declspec(dllimport) intptr_t __cdecl _get_heap_handle(void);

	__declspec(dllimport) int __cdecl _heapmin(void);

	__declspec(dllimport) int __cdecl _heapwalk(_HEAPINFO* _EntryInfo);

	__declspec(dllimport) int __cdecl _heapchk(void);

	__declspec(dllimport) int __cdecl _resetstkoflw(void);

	typedef char __static_assert_t[(sizeof(unsigned int) <= 8) != 0];

#pragma warning(push)
#pragma warning(disable:6540)

	__inline void* _MarkAllocaS(void* _Ptr, unsigned int _Marker)
	{
		if (_Ptr)
		{
			*((unsigned int*)_Ptr) = _Marker;
			_Ptr = (char*)_Ptr + 8;
		}
		return _Ptr;
	}

	__inline size_t _MallocaComputeSize(size_t _Size)
	{
		size_t _MarkedSize = _Size + 8;
		return _MarkedSize > _Size ? _MarkedSize : 0;
	}

#pragma warning(pop)

#pragma warning(push)
#pragma warning(disable: 6014)
	__inline void __cdecl _freea(void* _Memory)
	{
		unsigned int _Marker;
		if (_Memory)
		{
			_Memory = (char*)_Memory - 8;
			_Marker = *(unsigned int*)_Memory;
			if (_Marker == 0xDDDD)
			{
				free(_Memory);
			}

			else if (_Marker != 0xCCCC)
			{
				(void)((!!((("Corrupted pointer passed to _freea" && 0)))) || (1 != _CrtDbgReportW(2, L"c:\\program files\\windows kits\\10\\include\\10.0.17763.0\\ucrt\\malloc.h", 162, 0, L"%ls", L"(\"Corrupted pointer passed to _freea\" && 0)")) || (__debugbreak(), 0));
			}

		}
	}
#pragma warning(pop)

} __pragma(pack(pop))

#pragma once

#pragma once

#pragma once

__pragma(pack(push, 8)) extern "C" {

	typedef void(__cdecl* terminate_handler)();
	typedef void(__cdecl* terminate_function)();

	__declspec(dllimport) __declspec(noreturn) void __cdecl abort();
	__declspec(dllimport) __declspec(noreturn) void __cdecl terminate() throw();

	__declspec(dllimport) terminate_handler __cdecl set_terminate(
		terminate_handler _NewTerminateHandler
	) throw();

	__declspec(dllimport) terminate_handler __cdecl _get_terminate();

} __pragma(pack(pop))

__pragma(pack(push, 8)) extern "C" {

	typedef void(__cdecl* unexpected_handler)();
	typedef void(__cdecl* unexpected_function)();

	struct _EXCEPTION_POINTERS;

	__declspec(noreturn) void __cdecl unexpected() noexcept(false);

	unexpected_handler __cdecl set_unexpected(
		unexpected_handler _NewUnexpectedHandler
	) noexcept;

	unexpected_handler __cdecl _get_unexpected() noexcept;

	typedef void(__cdecl* _se_translator_function)(unsigned int, struct _EXCEPTION_POINTERS*);

	_se_translator_function __cdecl _set_se_translator(
		_se_translator_function _NewSETranslator
	);

	class type_info;

	int __cdecl _is_exception_typeof(
		type_info const&     _Type,
		_EXCEPTION_POINTERS* _ExceptionPtr
	);

	bool __cdecl __uncaught_exception();
	int  __cdecl __uncaught_exceptions();

} __pragma(pack(pop))

#pragma pack(push, 8)

__pragma(pack(push, 8)) extern "C" {

	struct __std_exception_data
	{
		char const* _What;
		bool        _DoFree;
	};

	void __cdecl __std_exception_copy(
		__std_exception_data const* _From,
		__std_exception_data*       _To
	);

	void __cdecl __std_exception_destroy(
		__std_exception_data* _Data
	);

} __pragma(pack(pop))

namespace std {

#pragma warning(push)
#pragma warning(disable: 4577) 
	class exception
	{
	public:

		exception() noexcept
			: _Data()
		{
		}

		explicit exception(char const* const _Message) noexcept
			: _Data()
		{
			__std_exception_data _InitData = { _Message, true };
			__std_exception_copy(&_InitData, &_Data);
		}

		exception(char const* const _Message, int) noexcept
			: _Data()
		{
			_Data._What = _Message;
		}

		exception(exception const& _Other) noexcept
			: _Data()
		{
			__std_exception_copy(&_Other._Data, &_Data);
		}

		exception& operator=(exception const& _Other) noexcept
		{
			if (this == &_Other)
			{
				return *this;
			}

			__std_exception_destroy(&_Data);
			__std_exception_copy(&_Other._Data, &_Data);
			return *this;
		}

		virtual ~exception() noexcept
		{
			__std_exception_destroy(&_Data);
		}

		virtual char const* what() const
		{
			return _Data._What ? _Data._What : "Unknown exception";
		}

	private:

		__std_exception_data _Data;
	};

	class bad_exception
		: public exception
	{
	public:

		bad_exception() noexcept
			: exception("bad exception", 1)
		{
		}
	};

	class bad_alloc
		: public exception
	{
	public:

		bad_alloc() noexcept
			: exception("bad allocation", 1)
		{
		}

	private:

		friend class bad_array_new_length;

		bad_alloc(char const* const _Message) noexcept
			: exception(_Message, 1)
		{
		}
	};

	class bad_array_new_length
		: public bad_alloc
	{
	public:

		bad_array_new_length() noexcept
			: bad_alloc("bad array new length")
		{
		}
	};

#pragma warning(pop)

}

#pragma pack(pop)

namespace std {

	using ::terminate;

	using ::set_terminate;
	using ::terminate_handler;

	inline terminate_handler __cdecl get_terminate() noexcept
	{
		return (_get_terminate());
	}

	using ::unexpected;

	using ::set_unexpected;
	using ::unexpected_handler;

	inline unexpected_handler __cdecl get_unexpected() noexcept
	{
		return (_get_unexpected());
	}

}

void __cdecl __ExceptionPtrCreate(void*);
void __cdecl __ExceptionPtrDestroy(void*);
void __cdecl __ExceptionPtrCopy(void*, const void*);
void __cdecl __ExceptionPtrAssign(void*, const void*);
bool __cdecl __ExceptionPtrCompare(const void*, const void*);
bool __cdecl __ExceptionPtrToBool(const void*);
void __cdecl __ExceptionPtrSwap(void*, void*);
void __cdecl __ExceptionPtrCurrentException(void*);
[[noreturn]]  void __cdecl __ExceptionPtrRethrow(const void*);
void __cdecl __ExceptionPtrCopyException(
	void*, const void*, const void*);

namespace std {

	class exception_ptr
	{
	public:
		exception_ptr() noexcept
		{
			__ExceptionPtrCreate(this);
		}

		exception_ptr(nullptr_t) noexcept
		{
			__ExceptionPtrCreate(this);
		}

		~exception_ptr() noexcept
		{
			__ExceptionPtrDestroy(this);
		}

		exception_ptr(const exception_ptr& _Rhs) noexcept
		{
			__ExceptionPtrCopy(this, &_Rhs);
		}

		exception_ptr& operator=(const exception_ptr& _Rhs) noexcept
		{
			__ExceptionPtrAssign(this, &_Rhs);
			return *this;
		}

		exception_ptr& operator=(nullptr_t) noexcept
		{
			exception_ptr _Ptr;
			__ExceptionPtrAssign(this, &_Ptr);
			return *this;
		}

		explicit operator bool() const noexcept
		{
			return __ExceptionPtrToBool(this);
		}

		[[noreturn]] void _RethrowException() const
		{
			__ExceptionPtrRethrow(this);
		}

		static exception_ptr _Current_exception() noexcept
		{
			exception_ptr _Retval;
			__ExceptionPtrCurrentException(&_Retval);
			return _Retval;
		}

		static exception_ptr _Copy_exception(void* _Except, const void* _Ptr)
		{
			exception_ptr _Retval;
			if (!_Ptr)
			{

				return _Retval;
			}
			__ExceptionPtrCopyException(&_Retval, _Except, _Ptr);
			return _Retval;
		}

	private:

		void* _Data1;
		void* _Data2;

	};

	inline void swap(exception_ptr& _Lhs, exception_ptr& _Rhs) noexcept
	{
		__ExceptionPtrSwap(&_Lhs, &_Rhs);
	}

	inline bool operator==(const exception_ptr& _Lhs, const exception_ptr& _Rhs) noexcept
	{
		return __ExceptionPtrCompare(&_Lhs, &_Rhs);
	}

	inline bool operator==(nullptr_t, const exception_ptr& _Rhs) noexcept
	{
		return !_Rhs;
	}

	inline bool operator==(const exception_ptr& _Lhs, nullptr_t) noexcept
	{
		return !_Lhs;
	}

	inline bool operator!=(const exception_ptr& _Lhs, const exception_ptr& _Rhs) noexcept
	{
		return !(_Lhs == _Rhs);
	}

	inline bool operator!=(nullptr_t _Lhs, const exception_ptr& _Rhs) noexcept
	{
		return !(_Lhs == _Rhs);
	}

	inline bool operator!=(const exception_ptr& _Lhs, nullptr_t _Rhs) noexcept
	{
		return !(_Lhs == _Rhs);
	}

	inline exception_ptr current_exception() noexcept
	{
		return exception_ptr::_Current_exception();
	}

	[[noreturn]] inline void rethrow_exception(exception_ptr _Ptr)
	{
		_Ptr._RethrowException();
	}

	template<class _Ex> void *__GetExceptionInfo(_Ex);

	template<class _Ex>  exception_ptr make_exception_ptr(_Ex _Except) noexcept
	{
		return exception_ptr::_Copy_exception(::std::addressof(_Except), __GetExceptionInfo(_Except));
	}

	class nested_exception
	{
	public:
		nested_exception() noexcept
			: _Exc(::std::current_exception())
		{
		}

		nested_exception(const nested_exception&) noexcept = default;
		nested_exception& operator=(const nested_exception&) noexcept = default;
		virtual ~nested_exception() noexcept
		{
		}

		[[noreturn]] void rethrow_nested() const
		{
			if (_Exc)
				::std::rethrow_exception(_Exc);
			else
				::std::terminate();
		}

		exception_ptr nested_ptr() const noexcept
		{
			return (_Exc);
		}

	private:
		exception_ptr _Exc;
	};

	template<class _Ty,
		class _Uty>
		struct _With_nested
		: _Uty, nested_exception
	{
		explicit _With_nested(_Ty&& _Arg)
			: _Uty(::std::forward<_Ty>(_Arg)), nested_exception()
		{
		}
	};

	template<class _Ty>
	[[noreturn]] inline void _Throw_with_nested(_Ty&& _Arg, true_type)
	{
		using _Uty = decay_t<_Ty>;
		using _Glued = _With_nested<_Ty, _Uty>;

		throw _Glued(::std::forward<_Ty>(_Arg));
	}

	template<class _Ty>
	[[noreturn]] inline void _Throw_with_nested(_Ty&& _Arg, false_type)
	{
		throw ::std::forward<_Ty>(_Arg);
	}

	template<class _Ty>
	[[noreturn]] inline void throw_with_nested(_Ty&& _Arg)
	{
		typedef decay_t<_Ty> _Uty;

		bool_constant<
			is_class_v<_Uty>
			&& !is_base_of_v<nested_exception, _Uty>
			&& !is_final_v<_Uty>> _Tag;

		_Throw_with_nested(::std::forward<_Ty>(_Arg), _Tag);
	}

	template<class _Ty> inline
		void _Rethrow_if_nested(const _Ty *_Ptr, true_type)
	{
		const auto _Nested = dynamic_cast<const nested_exception *>(_Ptr);

		if (_Nested)
			_Nested->rethrow_nested();
	}

	template<class _Ty> inline
		void _Rethrow_if_nested(const _Ty *, false_type)
	{
	}

	template<class _Ty> inline
		void rethrow_if_nested(const _Ty& _Arg)
	{
		bool_constant<is_polymorphic_v<_Ty> && (!is_base_of_v<nested_exception, _Ty>
			|| is_convertible_v<_Ty *, nested_exception *>)> _Tag;

		_Rethrow_if_nested(::std::addressof(_Arg), _Tag);
	}

}

#pragma warning(pop)
#pragma pack(pop)

#pragma once

#pragma once

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {

	typedef void(__cdecl * new_handler) ();

	new_handler __cdecl set_new_handler(new_handler) noexcept;
	new_handler __cdecl get_new_handler() noexcept;
}

#pragma warning(pop)
#pragma pack(pop)

#pragma once

#pragma once

#pragma once

#pragma once

#pragma once

#pragma once

#pragma once

#pragma once

__pragma(pack(push, 8)) extern "C" {

#pragma detect_mismatch("_CRT_STDIO_ISO_WIDE_SPECIFIERS", "0")

	__declspec(noinline) __inline unsigned __int64* __cdecl __local_stdio_printf_options(void)
	{
		static unsigned __int64 _OptionsStorage;
		return &_OptionsStorage;
	}

	__declspec(noinline) __inline unsigned __int64* __cdecl __local_stdio_scanf_options(void)
	{
		static unsigned __int64 _OptionsStorage;
		return &_OptionsStorage;
	}

} __pragma(pack(pop))

__pragma(pack(push, 8)) extern "C" {

	typedef struct _iobuf
	{
		void* _Placeholder;
	} FILE;

	__declspec(dllimport) FILE* __cdecl __acrt_iob_func(unsigned _Ix);

	__declspec(dllimport) wint_t __cdecl fgetwc(
		FILE* _Stream
	);

	__declspec(dllimport) wint_t __cdecl _fgetwchar(void);

	__declspec(dllimport) wint_t __cdecl fputwc(
		wchar_t _Character,
		FILE*   _Stream);

	__declspec(dllimport) wint_t __cdecl _fputwchar(
		wchar_t _Character
	);

	__declspec(dllimport) wint_t __cdecl getwc(
		FILE* _Stream
	);

	__declspec(dllimport) wint_t __cdecl getwchar(void);

	__declspec(dllimport) wchar_t* __cdecl fgetws(
		wchar_t* _Buffer,
		int      _BufferCount,
		FILE*    _Stream
	);

	__declspec(dllimport) int __cdecl fputws(
		wchar_t const* _Buffer,
		FILE*          _Stream
	);

	__declspec(dllimport) wchar_t* __cdecl _getws_s(
		wchar_t* _Buffer,
		size_t   _BufferCount
	);

	extern "C++" { template <size_t _Size> inline   wchar_t* __cdecl _getws_s(wchar_t(&_Buffer)[_Size]) throw() { return _getws_s(_Buffer, _Size); } }

	__declspec(dllimport) wint_t __cdecl putwc(
		wchar_t _Character,
		FILE*   _Stream
	);

	__declspec(dllimport) wint_t __cdecl putwchar(
		wchar_t _Character
	);

	__declspec(dllimport) int __cdecl _putws(
		wchar_t const* _Buffer
	);

	__declspec(dllimport) wint_t __cdecl ungetwc(
		wint_t _Character,
		FILE*  _Stream
	);

	__declspec(dllimport) FILE * __cdecl _wfdopen(
		int            _FileHandle,
		wchar_t const* _Mode
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wfopen_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) FILE* __cdecl _wfopen(
			wchar_t const* _FileName,
			wchar_t const* _Mode
		);

	__declspec(dllimport) errno_t __cdecl _wfopen_s(
		FILE**         _Stream,
		wchar_t const* _FileName,
		wchar_t const* _Mode
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wfreopen_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) FILE* __cdecl _wfreopen(
			wchar_t const* _FileName,
			wchar_t const* _Mode,
			FILE*          _OldStream
		);

	__declspec(dllimport) errno_t __cdecl _wfreopen_s(
		FILE**         _Stream,
		wchar_t const* _FileName,
		wchar_t const* _Mode,
		FILE*          _OldStream
	);

	__declspec(dllimport) FILE* __cdecl _wfsopen(
		wchar_t const* _FileName,
		wchar_t const* _Mode,
		int            _ShFlag
	);

	__declspec(dllimport) void __cdecl _wperror(
		wchar_t const* _ErrorMessage
	);

	__declspec(dllimport) FILE* __cdecl _wpopen(
		wchar_t const* _Command,
		wchar_t const* _Mode
	);

	__declspec(dllimport) int __cdecl _wremove(
		wchar_t const* _FileName
	);

	__declspec(dllimport) __declspec(allocator) wchar_t* __cdecl _wtempnam(
		wchar_t const* _Directory,
		wchar_t const* _FilePrefix
	);

	__declspec(dllimport) errno_t __cdecl _wtmpnam_s(
		wchar_t* _Buffer,
		size_t   _BufferCount
	);

	extern "C++" { template <size_t _Size> inline   errno_t __cdecl _wtmpnam_s(wchar_t(&_Buffer)[_Size]) throw() { return _wtmpnam_s(_Buffer, _Size); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wtmpnam_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport)  wchar_t* __cdecl _wtmpnam(wchar_t *_Buffer);

	__declspec(dllimport) wint_t __cdecl _fgetwc_nolock(
		FILE* _Stream
	);

	__declspec(dllimport) wint_t __cdecl _fputwc_nolock(
		wchar_t _Character,
		FILE*   _Stream
	);

	__declspec(dllimport) wint_t __cdecl _getwc_nolock(
		FILE* _Stream
	);

	__declspec(dllimport) wint_t __cdecl _putwc_nolock(
		wchar_t _Character,
		FILE*   _Stream
	);

	__declspec(dllimport) wint_t __cdecl _ungetwc_nolock(
		wint_t _Character,
		FILE*  _Stream
	);

	__declspec(dllimport) int __cdecl __stdio_common_vfwprintf(
		unsigned __int64 _Options,
		FILE*            _Stream,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(dllimport) int __cdecl __stdio_common_vfwprintf_s(
		unsigned __int64 _Options,
		FILE*            _Stream,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(dllimport) int __cdecl __stdio_common_vfwprintf_p(
		unsigned __int64 _Options,
		FILE*            _Stream,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__inline int __cdecl _vfwprintf_l(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return __stdio_common_vfwprintf((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vfwprintf(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vfwprintf_l(_Stream, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vfwprintf_s_l(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return __stdio_common_vfwprintf_s((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vfwprintf_s(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vfwprintf_s_l(_Stream, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vfwprintf_p_l(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return __stdio_common_vfwprintf_p((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl _vfwprintf_p(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vfwprintf_p_l(_Stream, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vwprintf_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return _vfwprintf_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vwprintf(
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vfwprintf_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
	}

	__inline int __cdecl _vwprintf_s_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return _vfwprintf_s_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vwprintf_s(
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vfwprintf_s_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
	}

	__inline int __cdecl _vwprintf_p_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return _vfwprintf_p_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl _vwprintf_p(
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vfwprintf_p_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
	}

	__inline int __cdecl _fwprintf_l(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwprintf_l(_Stream, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl fwprintf(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwprintf_l(_Stream, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _fwprintf_s_l(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwprintf_s_l(_Stream, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl fwprintf_s(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwprintf_s_l(_Stream, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _fwprintf_p_l(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwprintf_p_l(_Stream, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _fwprintf_p(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwprintf_p_l(_Stream, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _wprintf_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwprintf_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl wprintf(
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwprintf_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _wprintf_s_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwprintf_s_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl wprintf_s(
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwprintf_s_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _wprintf_p_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwprintf_p_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _wprintf_p(
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwprintf_p_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(dllimport) int __cdecl __stdio_common_vfwscanf(
		unsigned __int64 _Options,
		FILE*            _Stream,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__inline int __cdecl _vfwscanf_l(
		FILE*                                const _Stream,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return __stdio_common_vfwscanf(
			(*__local_stdio_scanf_options()),
			_Stream, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vfwscanf(
		FILE*                                const _Stream,
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vfwscanf_l(_Stream, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vfwscanf_s_l(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return __stdio_common_vfwscanf(
			(*__local_stdio_scanf_options()) | (1ULL << 0),
			_Stream, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vfwscanf_s(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vfwscanf_s_l(_Stream, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vwscanf_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return _vfwscanf_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vwscanf(
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vfwscanf_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
	}

	__inline int __cdecl _vwscanf_s_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return _vfwscanf_s_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vwscanf_s(
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vfwscanf_s_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_fwscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _fwscanf_l(
			FILE*          const _Stream,
			wchar_t const* const _Format,
			_locale_t      const _Locale,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwscanf_l(_Stream, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "fwscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl fwscanf(
			FILE*          const _Stream,
			wchar_t const* const _Format,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwscanf_l(_Stream, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _fwscanf_s_l(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwscanf_s_l(_Stream, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl fwscanf_s(
		FILE*          const _Stream,
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwscanf_s_l(_Stream, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _wscanf_l(
			wchar_t const* const _Format,
			_locale_t      const _Locale,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwscanf_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "wscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl wscanf(
			wchar_t const* const _Format,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwscanf_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _wscanf_s_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwscanf_s_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl wscanf_s(
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfwscanf_s_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(dllimport) int __cdecl __stdio_common_vswprintf(
		unsigned __int64 _Options,
		wchar_t*         _Buffer,
		size_t           _BufferCount,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(dllimport) int __cdecl __stdio_common_vswprintf_s(
		unsigned __int64 _Options,
		wchar_t*         _Buffer,
		size_t           _BufferCount,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(dllimport) int __cdecl __stdio_common_vsnwprintf_s(
		unsigned __int64 _Options,
		wchar_t*         _Buffer,
		size_t           _BufferCount,
		size_t           _MaxCount,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(dllimport) int __cdecl __stdio_common_vswprintf_p(
		unsigned __int64 _Options,
		wchar_t*         _Buffer,
		size_t           _BufferCount,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_vsnwprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _vsnwprintf_l(
			wchar_t*       const _Buffer,
			size_t         const _BufferCount,
			wchar_t const* const _Format,
			_locale_t      const _Locale,
			va_list              _ArgList
		)

	{
		int const _Result = __stdio_common_vswprintf(
			(*__local_stdio_printf_options()) | (1ULL << 0),
			_Buffer, _BufferCount, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

#pragma warning(push)
#pragma warning(disable: 4793)

	__inline int __cdecl _vsnwprintf_s_l(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		size_t         const _MaxCount,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		int const _Result = __stdio_common_vsnwprintf_s(
			(*__local_stdio_printf_options()),
			_Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl _vsnwprintf_s(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		size_t         const _MaxCount,
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vsnwprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, 0, _ArgList);
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_snwprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __inline   int __cdecl _snwprintf(wchar_t *_Buffer, size_t _BufferCount, wchar_t const* _Format, ...); __declspec(deprecated("This function or variable may be unsafe. Consider using " "_vsnwprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __inline   int __cdecl _vsnwprintf(wchar_t *_Buffer, size_t _BufferCount, wchar_t const* _Format, va_list _Args);

#pragma warning(pop)

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_vsnwprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _vsnwprintf(
			wchar_t*       _Buffer,
			size_t         _BufferCount,
			wchar_t const* _Format,
			va_list        _ArgList
		)

	{
#pragma warning(push)
#pragma warning(disable: 4996) 
		return _vsnwprintf_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
#pragma warning(pop)
	}

	extern "C++" { template <size_t _Size> inline   int __cdecl _vsnwprintf_s(wchar_t(&_Buffer)[_Size], size_t _BufferCount, wchar_t const* _Format, va_list _ArgList) throw() { return _vsnwprintf_s(_Buffer, _Size, _BufferCount, _Format, _ArgList); } }

	__inline int __cdecl _vswprintf_c_l(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		int const _Result = __stdio_common_vswprintf(
			(*__local_stdio_printf_options()),
			_Buffer, _BufferCount, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl _vswprintf_c(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vswprintf_c_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vswprintf_l(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
#pragma warning(push)
#pragma warning(disable: 4996) 
		return _vswprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
#pragma warning(pop)
	}

	__inline int __cdecl __vswprintf_l(
		wchar_t*       const _Buffer,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return _vswprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl _vswprintf(
		wchar_t*       const _Buffer,
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vswprintf_l(_Buffer, (size_t)-1, _Format, 0, _ArgList);
	}

	__inline int __cdecl vswprintf(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vswprintf_c_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vswprintf_s_l(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		int const _Result = __stdio_common_vswprintf_s(
			(*__local_stdio_printf_options()),
			_Buffer, _BufferCount, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl vswprintf_s(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vswprintf_s_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
	}

	extern "C++" { template <size_t _Size> inline   int __cdecl vswprintf_s(wchar_t(&_Buffer)[_Size], wchar_t const* _Format, va_list _ArgList) throw() { return vswprintf_s(_Buffer, _Size, _Format, _ArgList); } }

	__inline int __cdecl _vswprintf_p_l(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		int const _Result = __stdio_common_vswprintf_p(
			(*__local_stdio_printf_options()),
			_Buffer, _BufferCount, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl _vswprintf_p(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vswprintf_p_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vscwprintf_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		int const _Result = __stdio_common_vswprintf(
			(*__local_stdio_printf_options()) | (1ULL << 1),
			0, 0, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl _vscwprintf(
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vscwprintf_l(_Format, 0, _ArgList);
	}

	__inline int __cdecl _vscwprintf_p_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		int const _Result = __stdio_common_vswprintf_p(
			(*__local_stdio_printf_options()) | (1ULL << 1),
			0, 0, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl _vscwprintf_p(
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vscwprintf_p_l(_Format, 0, _ArgList);
	}

	__inline int __cdecl __swprintf_l(
		wchar_t*       const _Buffer,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = __vswprintf_l(_Buffer, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _swprintf_l(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _swprintf(
		wchar_t*       const _Buffer,
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = __vswprintf_l(_Buffer, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl swprintf(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

#pragma warning(push)

#pragma warning(disable:4793 4996)

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "__swprintf_l_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __inline   int __cdecl __swprintf_l(wchar_t *_Buffer, wchar_t const* _Format, _locale_t _Locale, ...); __declspec(deprecated("This function or variable may be unsafe. Consider using " "_vswprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __inline   int __cdecl __vswprintf_l(wchar_t *_Buffer, wchar_t const* _Format, _locale_t _Locale, va_list _Args);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "swprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __inline   int __cdecl _swprintf(wchar_t *_Buffer, wchar_t const* _Format, ...); __declspec(deprecated("This function or variable may be unsafe. Consider using " "vswprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __inline   int __cdecl _vswprintf(wchar_t *_Buffer, wchar_t const* _Format, va_list _Args);

#pragma warning(pop)

	__inline int __cdecl _swprintf_s_l(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswprintf_s_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl swprintf_s(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswprintf_s_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	extern "C++" { __pragma(warning(push)); __pragma(warning(disable: 4793)); template <size_t _Size> inline   int __cdecl swprintf_s(wchar_t(&_Buffer)[_Size], wchar_t const* _Format, ...) throw() { va_list _ArgList; ((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1)))))); return vswprintf_s(_Buffer, _Size, _Format, _ArgList); } __pragma(warning(pop)); }

	__inline int __cdecl _swprintf_p_l(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswprintf_p_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _swprintf_p(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswprintf_p_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _swprintf_c_l(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _swprintf_c(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_snwprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _snwprintf_l(
			wchar_t*       const _Buffer,
			size_t         const _BufferCount,
			wchar_t const* const _Format,
			_locale_t      const _Locale,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

#pragma warning(push)
#pragma warning(disable: 4996) 
		_Result = _vsnwprintf_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
#pragma warning(pop)

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _snwprintf(
		wchar_t*       _Buffer,
		size_t         _BufferCount,
		wchar_t const* _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

#pragma warning(push)
#pragma warning(disable: 4996) 
		_Result = _vsnwprintf_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
#pragma warning(pop)

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _snwprintf_s_l(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		size_t         const _MaxCount,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsnwprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _snwprintf_s(
		wchar_t*       const _Buffer,
		size_t         const _BufferCount,
		size_t         const _MaxCount,
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsnwprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	extern "C++" { __pragma(warning(push)); __pragma(warning(disable: 4793)); template <size_t _Size> inline   int __cdecl _snwprintf_s(wchar_t(&_Buffer)[_Size], size_t _BufferCount, wchar_t const* _Format, ...) throw() { va_list _ArgList; ((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1)))))); return _vsnwprintf_s(_Buffer, _Size, _BufferCount, _Format, _ArgList); } __pragma(warning(pop)); }

	__inline int __cdecl _scwprintf_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vscwprintf_l(_Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _scwprintf(
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vscwprintf_l(_Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _scwprintf_p_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vscwprintf_p_l(_Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _scwprintf_p(
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vscwprintf_p_l(_Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

#pragma warning(push)
#pragma warning(disable: 4141 4412 4793 4996 6054)

	extern "C++" __declspec(deprecated("function has been changed to conform with the ISO C standard, " "adding an extra character count parameter. To use the traditional " "Microsoft version, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "swprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		inline int swprintf(
			wchar_t*       const _Buffer,
			wchar_t const* const _Format,
			...) throw()
	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
#pragma warning(suppress: 28719)
		_Result = vswprintf(_Buffer, 2147483647, _Format, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	extern "C++" __declspec(deprecated("function has been changed to conform with the ISO C standard, " "adding an extra character count parameter. To use the traditional " "Microsoft version, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "vswprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		inline int __cdecl vswprintf(
			wchar_t*       const _Buffer,
			wchar_t const* const _Format,
			va_list              _ArgList
		) throw()
	{
#pragma warning(suppress: 28719)
		return vswprintf(_Buffer, 2147483647, _Format, _ArgList);
	}

	extern "C++" __declspec(deprecated("function has been changed to conform with the ISO C standard, " "adding an extra character count parameter. To use the traditional " "Microsoft version, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_swprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		inline int _swprintf_l(
			wchar_t*       const _Buffer,
			wchar_t const* const _Format,
			_locale_t      const _Locale,
			...) throw()
	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	extern "C++" __declspec(deprecated("function has been changed to conform with the ISO C standard, " "adding an extra character count parameter. To use the traditional " "Microsoft version, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_vswprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		inline int __cdecl _vswprintf_l(
			wchar_t*       const _Buffer,
			wchar_t const* const _Format,
			_locale_t      const _Locale,
			va_list              _ArgList
		) throw()
	{
		return _vswprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
	}

#pragma warning(pop)

	__declspec(dllimport) int __cdecl __stdio_common_vswscanf(
		unsigned __int64 _Options,
		wchar_t const*   _Buffer,
		size_t           _BufferCount,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__inline int __cdecl _vswscanf_l(
		wchar_t const* const _Buffer,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return __stdio_common_vswscanf(
			(*__local_stdio_scanf_options()),
			_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vswscanf(
		wchar_t const* _Buffer,
		wchar_t const* _Format,
		va_list        _ArgList
	)

	{
		return _vswscanf_l(_Buffer, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vswscanf_s_l(
		wchar_t const* const _Buffer,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return __stdio_common_vswscanf(
			(*__local_stdio_scanf_options()) | (1ULL << 0),
			_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vswscanf_s(
		wchar_t const* const _Buffer,
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vswscanf_s_l(_Buffer, _Format, 0, _ArgList);
	}

	extern "C++" { template <size_t _Size> inline   int __cdecl vswscanf_s(wchar_t(&_Buffer)[_Size], wchar_t const* _Format, va_list _ArgList) throw() { return vswscanf_s(_Buffer, _Size, _Format, _ArgList); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_vsnwscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _vsnwscanf_l(
			wchar_t const* const _Buffer,
			size_t         const _BufferCount,
			wchar_t const* const _Format,
			_locale_t      const _Locale,
			va_list              _ArgList
		)

	{
		return __stdio_common_vswscanf(
			(*__local_stdio_scanf_options()),
			_Buffer, _BufferCount, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl _vsnwscanf_s_l(
		wchar_t const* const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return __stdio_common_vswscanf(
			(*__local_stdio_scanf_options()) | (1ULL << 0),
			_Buffer, _BufferCount, _Format, _Locale, _ArgList);
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_swscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _swscanf_l(
			wchar_t const* const _Buffer,
			wchar_t const* const _Format,
			_locale_t            _Locale,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswscanf_l(_Buffer, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "swscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl swscanf(
			wchar_t const* const _Buffer,
			wchar_t const* const _Format,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswscanf_l(_Buffer, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _swscanf_s_l(
		wchar_t const* const _Buffer,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswscanf_s_l(_Buffer, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl swscanf_s(
		wchar_t const* const _Buffer,
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vswscanf_s_l(_Buffer, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_snwscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _snwscanf_l(
			wchar_t const* const _Buffer,
			size_t         const _BufferCount,
			wchar_t const* const _Format,
			_locale_t      const _Locale,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

#pragma warning(push)
#pragma warning(disable: 4996) 
		_Result = _vsnwscanf_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
#pragma warning(pop)

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_snwscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _snwscanf(
			wchar_t const* const _Buffer,
			size_t         const _BufferCount,
			wchar_t const* const _Format,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

#pragma warning(push)
#pragma warning(disable: 4996) 
		_Result = _vsnwscanf_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
#pragma warning(pop)

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _snwscanf_s_l(
		wchar_t const* const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsnwscanf_s_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _snwscanf_s(
		wchar_t const* const _Buffer,
		size_t         const _BufferCount,
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsnwscanf_s_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

} __pragma(pack(pop))

__pragma(pack(push, 8)) extern "C" {

	typedef __int64 fpos_t;

	__declspec(dllimport) errno_t __cdecl _get_stream_buffer_pointers(
		FILE*   _Stream,
		char*** _Base,
		char*** _Pointer,
		int**   _Count
	);

	__declspec(dllimport) errno_t __cdecl clearerr_s(
		FILE* _Stream
	);

	__declspec(dllimport) errno_t __cdecl fopen_s(
		FILE**      _Stream,
		char const* _FileName,
		char const* _Mode
	);

	__declspec(dllimport) size_t __cdecl fread_s(
		void*  _Buffer,
		size_t _BufferSize,
		size_t _ElementSize,
		size_t _ElementCount,
		FILE*  _Stream
	);

	__declspec(dllimport) errno_t __cdecl freopen_s(
		FILE**      _Stream,
		char const* _FileName,
		char const* _Mode,
		FILE*       _OldStream
	);

	__declspec(dllimport) char* __cdecl gets_s(
		char*   _Buffer,
		rsize_t _Size
	);

	__declspec(dllimport) errno_t __cdecl tmpfile_s(
		FILE** _Stream
	);

	__declspec(dllimport) errno_t __cdecl tmpnam_s(
		char*   _Buffer,
		rsize_t _Size
	);

	__declspec(dllimport) void __cdecl clearerr(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl fclose(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl _fcloseall(void);

	__declspec(dllimport) FILE* __cdecl _fdopen(
		int         _FileHandle,
		char const* _Mode
	);

	__declspec(dllimport) int __cdecl feof(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl ferror(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl fflush(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl fgetc(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl _fgetchar(void);

	__declspec(dllimport) int __cdecl fgetpos(
		FILE*   _Stream,
		fpos_t* _Position
	);

	__declspec(dllimport) char* __cdecl fgets(
		char* _Buffer,
		int   _MaxCount,
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl _fileno(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl _flushall(void);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "fopen_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) FILE* __cdecl fopen(
			char const* _FileName,
			char const* _Mode
		);

	__declspec(dllimport) int __cdecl fputc(
		int   _Character,
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl _fputchar(
		int _Character
	);

	__declspec(dllimport) int __cdecl fputs(
		char const* _Buffer,
		FILE*       _Stream
	);

	__declspec(dllimport) size_t __cdecl fread(
		void*  _Buffer,
		size_t _ElementSize,
		size_t _ElementCount,
		FILE*  _Stream
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "freopen_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) FILE* __cdecl freopen(
			char const* _FileName,
			char const* _Mode,
			FILE*       _Stream
		);

	__declspec(dllimport) FILE* __cdecl _fsopen(
		char const* _FileName,
		char const* _Mode,
		int         _ShFlag
	);

	__declspec(dllimport) int __cdecl fsetpos(
		FILE*         _Stream,
		fpos_t const* _Position
	);

	__declspec(dllimport) int __cdecl fseek(
		FILE* _Stream,
		long  _Offset,
		int   _Origin
	);

	__declspec(dllimport) int __cdecl _fseeki64(
		FILE*   _Stream,
		__int64 _Offset,
		int     _Origin
	);

	__declspec(dllimport) long __cdecl ftell(
		FILE* _Stream
	);

	__declspec(dllimport) __int64 __cdecl _ftelli64(
		FILE* _Stream
	);

	__declspec(dllimport) size_t __cdecl fwrite(
		void const* _Buffer,
		size_t      _ElementSize,
		size_t      _ElementCount,
		FILE*       _Stream
	);

	__declspec(dllimport) int __cdecl getc(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl getchar(void);

	__declspec(dllimport) int __cdecl _getmaxstdio(void);

	extern "C++" { template <size_t _Size> inline char* __cdecl gets_s(char(&_Buffer)[_Size]) throw() { return gets_s(_Buffer, _Size); } }

	__declspec(dllimport) int __cdecl _getw(
		FILE* _Stream
	);

	__declspec(dllimport) void __cdecl perror(
		char const* _ErrorMessage
	);

	__declspec(dllimport) int __cdecl _pclose(
		FILE* _Stream
	);

	__declspec(dllimport) FILE* __cdecl _popen(
		char const* _Command,
		char const* _Mode
	);

	__declspec(dllimport) int __cdecl putc(
		int   _Character,
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl putchar(
		int _Character
	);

	__declspec(dllimport) int __cdecl puts(
		char const* _Buffer
	);

	__declspec(dllimport) int __cdecl _putw(
		int   _Word,
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl remove(
		char const* _FileName
	);

	__declspec(dllimport) int __cdecl rename(
		char const* _OldFileName,
		char const* _NewFileName
	);

	__declspec(dllimport) int __cdecl _unlink(
		char const* _FileName
	);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_unlink" ". See online help for details."))
		__declspec(dllimport) int __cdecl unlink(
			char const* _FileName
		);

	__declspec(dllimport) void __cdecl rewind(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl _rmtmp(void);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "setvbuf" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) void __cdecl setbuf(
			FILE* _Stream,
			char* _Buffer
		);

	__declspec(dllimport) int __cdecl _setmaxstdio(
		int _Maximum
	);

	__declspec(dllimport) int __cdecl setvbuf(
		FILE*  _Stream,
		char*  _Buffer,
		int    _Mode,
		size_t _Size
	);

	__declspec(dllimport) __declspec(allocator) char* __cdecl _tempnam(
		char const* _DirectoryName,
		char const* _FilePrefix
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "tmpfile_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) FILE* __cdecl tmpfile(void);

	extern "C++" { template <size_t _Size> inline   errno_t __cdecl tmpnam_s(char(&_Buffer)[_Size]) throw() { return tmpnam_s(_Buffer, _Size); } }

#pragma warning(push)
#pragma warning(disable: 28726) 
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "tmpnam_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport)  char* __cdecl tmpnam(char *_Buffer);

#pragma warning(pop)

	__declspec(dllimport) int __cdecl ungetc(
		int   _Character,
		FILE* _Stream
	);

	__declspec(dllimport) void __cdecl _lock_file(
		FILE* _Stream
	);

	__declspec(dllimport) void __cdecl _unlock_file(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl _fclose_nolock(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl _fflush_nolock(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl _fgetc_nolock(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl _fputc_nolock(
		int   _Character,
		FILE* _Stream
	);

	__declspec(dllimport) size_t __cdecl _fread_nolock(
		void*  _Buffer,
		size_t _ElementSize,
		size_t _ElementCount,
		FILE*  _Stream
	);

	__declspec(dllimport) size_t __cdecl _fread_nolock_s(
		void*  _Buffer,
		size_t _BufferSize,
		size_t _ElementSize,
		size_t _ElementCount,
		FILE*  _Stream
	);

	__declspec(dllimport) int __cdecl _fseek_nolock(
		FILE* _Stream,
		long  _Offset,
		int   _Origin
	);

	__declspec(dllimport) int __cdecl _fseeki64_nolock(
		FILE*   _Stream,
		__int64 _Offset,
		int     _Origin
	);

	__declspec(dllimport) long __cdecl _ftell_nolock(
		FILE* _Stream
	);

	__declspec(dllimport) __int64 __cdecl _ftelli64_nolock(
		FILE* _Stream
	);

	__declspec(dllimport) size_t __cdecl _fwrite_nolock(
		void const* _Buffer,
		size_t      _ElementSize,
		size_t      _ElementCount,
		FILE*       _Stream
	);

	__declspec(dllimport) int __cdecl _getc_nolock(
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl _putc_nolock(
		int   _Character,
		FILE* _Stream
	);

	__declspec(dllimport) int __cdecl _ungetc_nolock(
		int   _Character,
		FILE* _Stream
	);

	__declspec(dllimport) int* __cdecl __p__commode(void);

	__declspec(dllimport) int __cdecl __stdio_common_vfprintf(
		unsigned __int64 _Options,
		FILE*            _Stream,
		char const*      _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(dllimport) int __cdecl __stdio_common_vfprintf_s(
		unsigned __int64 _Options,
		FILE*            _Stream,
		char const*      _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(dllimport) int __cdecl __stdio_common_vfprintf_p(
		unsigned __int64 _Options,
		FILE*            _Stream,
		char const*      _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__inline int __cdecl _vfprintf_l(
		FILE*       const _Stream,
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		return __stdio_common_vfprintf((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vfprintf(
		FILE*       const _Stream,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vfprintf_l(_Stream, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vfprintf_s_l(
		FILE*       const _Stream,
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		return __stdio_common_vfprintf_s((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vfprintf_s(
		FILE*       const _Stream,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vfprintf_s_l(_Stream, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vfprintf_p_l(
		FILE*       const _Stream,
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		return __stdio_common_vfprintf_p((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl _vfprintf_p(
		FILE*       const _Stream,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vfprintf_p_l(_Stream, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vprintf_l(
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		return _vfprintf_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vprintf(
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vfprintf_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
	}

	__inline int __cdecl _vprintf_s_l(
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		return _vfprintf_s_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vprintf_s(
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vfprintf_s_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
	}

	__inline int __cdecl _vprintf_p_l(
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		return _vfprintf_p_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl _vprintf_p(
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vfprintf_p_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
	}

	__inline int __cdecl _fprintf_l(
		FILE*       const _Stream,
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfprintf_l(_Stream, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl fprintf(
		FILE*       const _Stream,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfprintf_l(_Stream, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(dllimport) int __cdecl _set_printf_count_output(
		int _Value
	);

	__declspec(dllimport) int __cdecl _get_printf_count_output(void);

	__inline int __cdecl _fprintf_s_l(
		FILE*       const _Stream,
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfprintf_s_l(_Stream, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl fprintf_s(
		FILE*       const _Stream,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfprintf_s_l(_Stream, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _fprintf_p_l(
		FILE*       const _Stream,
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfprintf_p_l(_Stream, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _fprintf_p(
		FILE*       const _Stream,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfprintf_p_l(_Stream, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _printf_l(
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfprintf_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl printf(
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfprintf_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _printf_s_l(
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfprintf_s_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl printf_s(
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfprintf_s_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _printf_p_l(
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfprintf_p_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _printf_p(
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfprintf_p_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(dllimport) int __cdecl __stdio_common_vfscanf(
		unsigned __int64 _Options,
		FILE*            _Stream,
		char const*      _Format,
		_locale_t        _Locale,
		va_list          _Arglist
	);

	__inline int __cdecl _vfscanf_l(
		FILE*       const _Stream,
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		return __stdio_common_vfscanf(
			(*__local_stdio_scanf_options()),
			_Stream, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vfscanf(
		FILE*       const _Stream,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vfscanf_l(_Stream, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vfscanf_s_l(
		FILE*       const _Stream,
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		return __stdio_common_vfscanf(
			(*__local_stdio_scanf_options()) | (1ULL << 0),
			_Stream, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vfscanf_s(
		FILE*       const _Stream,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vfscanf_s_l(_Stream, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vscanf_l(
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		return _vfscanf_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vscanf(
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vfscanf_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
	}

	__inline int __cdecl _vscanf_s_l(
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		return _vfscanf_s_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vscanf_s(
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vfscanf_s_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_fscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _fscanf_l(
			FILE*       const _Stream,
			char const* const _Format,
			_locale_t   const _Locale,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfscanf_l(_Stream, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "fscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl fscanf(
			FILE*       const _Stream,
			char const* const _Format,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfscanf_l(_Stream, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _fscanf_s_l(
		FILE*       const _Stream,
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfscanf_s_l(_Stream, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl fscanf_s(
		FILE*       const _Stream,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfscanf_s_l(_Stream, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_scanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _scanf_l(
			char const* const _Format,
			_locale_t   const _Locale,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfscanf_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "scanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl scanf(
			char const* const _Format,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfscanf_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _scanf_s_l(
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfscanf_s_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl scanf_s(
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vfscanf_s_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(dllimport) int __cdecl __stdio_common_vsprintf(
		unsigned __int64 _Options,
		char*            _Buffer,
		size_t           _BufferCount,
		char const*      _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(dllimport) int __cdecl __stdio_common_vsprintf_s(
		unsigned __int64 _Options,
		char*            _Buffer,
		size_t           _BufferCount,
		char const*      _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(dllimport) int __cdecl __stdio_common_vsnprintf_s(
		unsigned __int64 _Options,
		char*            _Buffer,
		size_t           _BufferCount,
		size_t           _MaxCount,
		char const*      _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(dllimport) int __cdecl __stdio_common_vsprintf_p(
		unsigned __int64 _Options,
		char*            _Buffer,
		size_t           _BufferCount,
		char const*      _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_vsnprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _vsnprintf_l(
			char*       const _Buffer,
			size_t      const _BufferCount,
			char const* const _Format,
			_locale_t   const _Locale,
			va_list           _ArgList
		)

	{
		int const _Result = __stdio_common_vsprintf(
			(*__local_stdio_printf_options()) | (1ULL << 0),
			_Buffer, _BufferCount, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl _vsnprintf(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		va_list           _ArgList
	)

	{
#pragma warning(push)
#pragma warning(disable: 4996) 
		return _vsnprintf_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
#pragma warning(pop)
	}

	__inline int __cdecl vsnprintf(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		int const _Result = __stdio_common_vsprintf(
			(*__local_stdio_printf_options()) | (1ULL << 1),
			_Buffer, _BufferCount, _Format, 0, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_vsprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _vsprintf_l(
			char*       const _Buffer,
			char const* const _Format,
			_locale_t   const _Locale,
			va_list           _ArgList
		)

	{
#pragma warning(push)
#pragma warning(disable: 4996) 
		return _vsnprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
#pragma warning(pop)
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "vsprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl vsprintf(
			char*       const _Buffer,
			char const* const _Format,
			va_list           _ArgList
		)

	{
#pragma warning(push)
#pragma warning(disable: 4996) 
		return _vsnprintf_l(_Buffer, (size_t)-1, _Format, 0, _ArgList);
#pragma warning(pop)
	}

	__inline int __cdecl _vsprintf_s_l(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		int const _Result = __stdio_common_vsprintf_s(
			(*__local_stdio_printf_options()),
			_Buffer, _BufferCount, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl vsprintf_s(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vsprintf_s_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
	}

	extern "C++" { template <size_t _Size> inline   int __cdecl vsprintf_s(char(&_Buffer)[_Size], char const* _Format, va_list _ArgList) throw() { return vsprintf_s(_Buffer, _Size, _Format, _ArgList); } }

	__inline int __cdecl _vsprintf_p_l(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		int const _Result = __stdio_common_vsprintf_p(
			(*__local_stdio_printf_options()),
			_Buffer, _BufferCount, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl _vsprintf_p(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vsprintf_p_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vsnprintf_s_l(
		char*       const _Buffer,
		size_t      const _BufferCount,
		size_t      const _MaxCount,
		char const* const _Format,
		_locale_t   const _Locale,
		va_list          _ArgList
	)

	{
		int const _Result = __stdio_common_vsnprintf_s(
			(*__local_stdio_printf_options()),
			_Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl _vsnprintf_s(
		char*       const _Buffer,
		size_t      const _BufferCount,
		size_t      const _MaxCount,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, 0, _ArgList);
	}

	extern "C++" { template <size_t _Size> inline   int __cdecl _vsnprintf_s(char(&_Buffer)[_Size], size_t _BufferCount, char const* _Format, va_list _ArgList) throw() { return _vsnprintf_s(_Buffer, _Size, _BufferCount, _Format, _ArgList); } }

	__inline int __cdecl vsnprintf_s(
		char*       const _Buffer,
		size_t      const _BufferCount,
		size_t      const _MaxCount,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, 0, _ArgList);
	}

	extern "C++" { template <size_t _Size> inline   int __cdecl vsnprintf_s(char(&_Buffer)[_Size], size_t _BufferCount, char const* _Format, va_list _ArgList) throw() { return vsnprintf_s(_Buffer, _Size, _BufferCount, _Format, _ArgList); } }

	__inline int __cdecl _vscprintf_l(
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		int const _Result = __stdio_common_vsprintf(
			(*__local_stdio_printf_options()) | (1ULL << 1),
			0, 0, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl _vscprintf(
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vscprintf_l(_Format, 0, _ArgList);
	}

	__inline int __cdecl _vscprintf_p_l(
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		int const _Result = __stdio_common_vsprintf_p(
			(*__local_stdio_printf_options()) | (1ULL << 1),
			0, 0, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl _vscprintf_p(
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vscprintf_p_l(_Format, 0, _ArgList);
	}

	__inline int __cdecl _vsnprintf_c_l(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		int const _Result = __stdio_common_vsprintf(
			(*__local_stdio_printf_options()),
			_Buffer, _BufferCount, _Format, _Locale, _ArgList);

		return _Result < 0 ? -1 : _Result;
	}

	__inline int __cdecl _vsnprintf_c(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vsnprintf_c_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_sprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _sprintf_l(
			char*       const _Buffer,
			char const* const _Format,
			_locale_t   const _Locale,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

#pragma warning(push)
#pragma warning(disable: 4996) 
		_Result = _vsprintf_l(_Buffer, _Format, _Locale, _ArgList);
#pragma warning(pop)

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl sprintf(
		char*       const _Buffer,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

#pragma warning(push)
#pragma warning(disable: 4996) 
		_Result = _vsprintf_l(_Buffer, _Format, 0, _ArgList);
#pragma warning(pop)

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

#pragma warning(push)
#pragma warning(disable: 4996)
#pragma warning(disable: 28719) 
#pragma warning(disable: 28726) 
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "sprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))   int __cdecl sprintf(char *_Buffer, char const* _Format, ...); __declspec(deprecated("This function or variable may be unsafe. Consider using " "vsprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))   int __cdecl vsprintf(char *_Buffer, char const* _Format, va_list _Args);

#pragma warning(pop)

	__inline int __cdecl _sprintf_s_l(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsprintf_s_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl sprintf_s(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsprintf_s_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	extern "C++" { __pragma(warning(push)); __pragma(warning(disable: 4793)); template <size_t _Size> inline   int __cdecl sprintf_s(char(&_Buffer)[_Size], char const* _Format, ...) throw() { va_list _ArgList; ((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1)))))); return vsprintf_s(_Buffer, _Size, _Format, _ArgList); } __pragma(warning(pop)); }

	__inline int __cdecl _sprintf_p_l(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsprintf_p_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _sprintf_p(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsprintf_p_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_snprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _snprintf_l(
			char*       const _Buffer,
			size_t      const _BufferCount,
			char const* const _Format,
			_locale_t   const _Locale,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

#pragma warning(push)
#pragma warning(disable: 4996) 
		_Result = _vsnprintf_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
#pragma warning(pop)

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl snprintf(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
#pragma warning(suppress:28719)    
		_Result = vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _snprintf(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
#pragma warning(suppress:28719)    
		_Result = _vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_snprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))    int __cdecl _snprintf(char *_Buffer, size_t _BufferCount, char const* _Format, ...); __declspec(deprecated("This function or variable may be unsafe. Consider using " "_vsnprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))    int __cdecl _vsnprintf(char *_Buffer, size_t _BufferCount, char const* _Format, va_list _Args);

	__inline int __cdecl _snprintf_c_l(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsnprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _snprintf_c(
		char*       const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsnprintf_c_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _snprintf_s_l(
		char*       const _Buffer,
		size_t      const _BufferCount,
		size_t      const _MaxCount,
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _snprintf_s(
		char*       const _Buffer,
		size_t      const _BufferCount,
		size_t      const _MaxCount,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	extern "C++" { __pragma(warning(push)); __pragma(warning(disable: 4793)); template <size_t _Size> inline   int __cdecl _snprintf_s(char(&_Buffer)[_Size], size_t _BufferCount, char const* _Format, ...) throw() { va_list _ArgList; ((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1)))))); return _vsnprintf_s(_Buffer, _Size, _BufferCount, _Format, _ArgList); } __pragma(warning(pop)); }

	__inline int __cdecl _scprintf_l(
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vscprintf_l(_Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _scprintf(
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vscprintf_l(_Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _scprintf_p_l(
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vscprintf_p_l(_Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _scprintf_p(
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vscprintf_p(_Format, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(dllimport) int __cdecl __stdio_common_vsscanf(
		unsigned __int64 _Options,
		char const*      _Buffer,
		size_t           _BufferCount,
		char const*      _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__inline int __cdecl _vsscanf_l(
		char const* const _Buffer,
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		return __stdio_common_vsscanf(
			(*__local_stdio_scanf_options()),
			_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
	}

	__inline int __cdecl vsscanf(
		char const* const _Buffer,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vsscanf_l(_Buffer, _Format, 0, _ArgList);
	}

	__inline int __cdecl _vsscanf_s_l(
		char const* const _Buffer,
		char const* const _Format,
		_locale_t   const _Locale,
		va_list           _ArgList
	)

	{
		return __stdio_common_vsscanf(
			(*__local_stdio_scanf_options()) | (1ULL << 0),
			_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
	}

#pragma warning(push)
#pragma warning(disable:6530)

	__inline int __cdecl vsscanf_s(
		char const* const _Buffer,
		char const* const _Format,
		va_list           _ArgList
	)

	{
		return _vsscanf_s_l(_Buffer, _Format, 0, _ArgList);
	}

	extern "C++" { template <size_t _Size> inline int __cdecl vsscanf_s(char const (&_Buffer)[_Size], char const* _Format, va_list _ArgList) throw() { return vsscanf_s(_Buffer, _Size, _Format, _ArgList); } }

#pragma warning(pop)

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_sscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _sscanf_l(
			char const* const _Buffer,
			char const* const _Format,
			_locale_t   const _Locale,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsscanf_l(_Buffer, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "sscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl sscanf(
			char const* const _Buffer,
			char const* const _Format,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsscanf_l(_Buffer, _Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _sscanf_s_l(
		char const* const _Buffer,
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vsscanf_s_l(_Buffer, _Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl sscanf_s(
		char const* const _Buffer,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

#pragma warning(push)
#pragma warning(disable: 4996) 
		_Result = vsscanf_s(_Buffer, _Format, _ArgList);
#pragma warning(pop)

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

#pragma warning(push)
#pragma warning(disable:6530)

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_snscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _snscanf_l(
			char const* const _Buffer,
			size_t      const _BufferCount,
			char const* const _Format,
			_locale_t   const _Locale,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

		_Result = __stdio_common_vsscanf(
			(*__local_stdio_scanf_options()),
			_Buffer, _BufferCount, _Format, _Locale, _ArgList);

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_snscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _snscanf(
			char const* const _Buffer,
			size_t      const _BufferCount,
			char const* const _Format,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

		_Result = __stdio_common_vsscanf(
			(*__local_stdio_scanf_options()),
			_Buffer, _BufferCount, _Format, 0, _ArgList);

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _snscanf_s_l(
		char const* const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		_locale_t   const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

		_Result = __stdio_common_vsscanf(
			(*__local_stdio_scanf_options()) | (1ULL << 0),
			_Buffer, _BufferCount, _Format, _Locale, _ArgList);

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _snscanf_s(
		char const* const _Buffer,
		size_t      const _BufferCount,
		char const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

		_Result = __stdio_common_vsscanf(
			(*__local_stdio_scanf_options()) | (1ULL << 0),
			_Buffer, _BufferCount, _Format, 0, _ArgList);

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

#pragma warning(pop)

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_tempnam" ". See online help for details."))
		__declspec(dllimport) char* __cdecl tempnam(
			char const* _Directory,
			char const* _FilePrefix
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_fcloseall" ". See online help for details.")) __declspec(dllimport) int   __cdecl fcloseall(void);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_fdopen" ". See online help for details."))    __declspec(dllimport) FILE* __cdecl fdopen(int _FileHandle, char const* _Format);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_fgetchar" ". See online help for details."))  __declspec(dllimport) int   __cdecl fgetchar(void);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_fileno" ". See online help for details."))    __declspec(dllimport) int   __cdecl fileno(FILE* _Stream);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_flushall" ". See online help for details."))  __declspec(dllimport) int   __cdecl flushall(void);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_fputchar" ". See online help for details."))  __declspec(dllimport) int   __cdecl fputchar(int _Ch);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_getw" ". See online help for details."))      __declspec(dllimport) int   __cdecl getw(FILE* _Stream);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_putw" ". See online help for details."))      __declspec(dllimport) int   __cdecl putw(int _Ch, FILE* _Stream);
	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_rmtmp" ". See online help for details."))     __declspec(dllimport) int   __cdecl rmtmp(void);

} __pragma(pack(pop))

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {
#pragma warning(push)
#pragma warning(disable: 4995) 

	using ::FILE; using ::_Mbstatet;

	using ::size_t; using ::fpos_t; using ::FILE;
	using ::clearerr; using ::fclose; using ::feof;
	using ::ferror; using ::fflush; using ::fgetc;
	using ::fgetpos; using ::fgets; using ::fopen;
	using ::fprintf; using ::fputc; using ::fputs;
	using ::fread; using ::freopen; using ::fscanf;
	using ::fseek; using ::fsetpos; using ::ftell;
	using ::fwrite; using ::getc; using ::getchar;
	using ::perror;
	using ::putc; using ::putchar;
	using ::printf; using ::puts; using ::remove;
	using ::rename; using ::rewind; using ::scanf;
	using ::setbuf; using ::setvbuf; using ::sprintf;
	using ::sscanf; using ::tmpfile; using ::tmpnam;
	using ::ungetc; using ::vfprintf; using ::vprintf;
	using ::vsprintf;

	using ::snprintf; using ::vsnprintf;
	using ::vfscanf; using ::vscanf; using ::vsscanf;

#pragma warning(pop)
}

#pragma warning(pop)
#pragma pack(pop)

#pragma once

#pragma once

#pragma once

#pragma once

#pragma once

__pragma(pack(push, 8)) extern "C" {

	__declspec(dllimport) int* __cdecl _errno(void);

	__declspec(dllimport) errno_t __cdecl _set_errno(int _Value);
	__declspec(dllimport) errno_t __cdecl _get_errno(int* _Value);

	__declspec(dllimport) unsigned long* __cdecl __doserrno(void);

	__declspec(dllimport) errno_t __cdecl _set_doserrno(unsigned long _Value);
	__declspec(dllimport) errno_t __cdecl _get_doserrno(unsigned long * _Value);

} __pragma(pack(pop))

#pragma once

__pragma(pack(push, 8)) extern "C" {

	void const* __cdecl memchr(
		void const* _Buf,
		int         _Val,
		size_t      _MaxCount
	);

	int __cdecl memcmp(
		void const* _Buf1,
		void const* _Buf2,
		size_t      _Size
	);

	void* __cdecl memcpy(
		void* _Dst,
		void const* _Src,
		size_t      _Size
	);

	void* __cdecl memmove(
		void*       _Dst,
		void const* _Src,
		size_t      _Size
	);

	void* __cdecl memset(
		void*  _Dst,
		int    _Val,
		size_t _Size
	);

	char const* __cdecl strchr(
		char const* _Str,
		int         _Val
	);

	char const* __cdecl strrchr(
		char const* _Str,
		int         _Ch
	);

	char const* __cdecl strstr(
		char const* _Str,
		char const* _SubStr
	);

	wchar_t const* __cdecl wcschr(
		wchar_t const* _Str,
		wchar_t        _Ch
	);

	wchar_t const* __cdecl wcsrchr(
		wchar_t const* _Str,
		wchar_t        _Ch
	);

	wchar_t const* __cdecl wcsstr(
		wchar_t const* _Str,
		wchar_t const* _SubStr
	);

} __pragma(pack(pop))

__pragma(pack(push, 8)) extern "C" {

	static __inline errno_t __cdecl memcpy_s(
		void*       const _Destination,
		rsize_t     const _DestinationSize,
		void const* const _Source,
		rsize_t     const _SourceSize
	)
	{
		if (_SourceSize == 0)
		{
			return 0;
		}

		{ int _Expr_val = !!(_Destination != 0); if (!(_Expr_val)) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; } };
		if (_Source == 0 || _DestinationSize < _SourceSize)
		{
			memset(_Destination, 0, _DestinationSize);

			{ int _Expr_val = !!(_Source != 0); if (!(_Expr_val)) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; } };
			{ int _Expr_val = !!(_DestinationSize >= _SourceSize); if (!(_Expr_val)) { (*_errno()) = 34; _invalid_parameter_noinfo(); return 34; } };

			return 22;
		}
#pragma warning(suppress:4996) 
		memcpy(_Destination, _Source, _SourceSize);
		return 0;
	}

	static __inline errno_t __cdecl memmove_s(
		void*       const _Destination,
		rsize_t     const _DestinationSize,
		void const* const _Source,
		rsize_t     const _SourceSize
	)
	{
		if (_SourceSize == 0)
		{
			return 0;
		}

		{ int _Expr_val = !!(_Destination != 0); if (!(_Expr_val)) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; } };
		{ int _Expr_val = !!(_Source != 0); if (!(_Expr_val)) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; } };
		{ int _Expr_val = !!(_DestinationSize >= _SourceSize); if (!(_Expr_val)) { (*_errno()) = 34; _invalid_parameter_noinfo(); return 34; } };

#pragma warning(suppress:4996) 
		memmove(_Destination, _Source, _SourceSize);
		return 0;
	}

} __pragma(pack(pop))

__pragma(pack(push, 8)) extern "C" {

	__declspec(dllimport) int __cdecl _memicmp(
		void const* _Buf1,
		void const* _Buf2,
		size_t      _Size
	);

	__declspec(dllimport) int __cdecl _memicmp_l(
		void const* _Buf1,
		void const* _Buf2,
		size_t      _Size,
		_locale_t   _Locale
	);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_memccpy" ". See online help for details."))
		__declspec(dllimport) void* __cdecl memccpy(
			void*       _Dst,
			void const* _Src,
			int         _Val,
			size_t      _Size
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_memicmp" ". See online help for details."))
		__declspec(dllimport) int __cdecl memicmp(
			void const* _Buf1,
			void const* _Buf2,
			size_t      _Size
		);

	extern "C++"
		inline void* __cdecl memchr(
			void*  _Pv,
			int    _C,
			size_t _N
		)
	{
		void const* const _Pvc = _Pv;
		return const_cast<void*>(memchr(_Pvc, _C, _N));
	}

} __pragma(pack(pop))

#pragma once

__pragma(pack(push, 8)) extern "C" {

	__declspec(dllimport) errno_t __cdecl wcscat_s(
		wchar_t* _Destination,
		rsize_t _SizeInWords,
		wchar_t const* _Source
	);

	__declspec(dllimport) errno_t __cdecl wcscpy_s(
		wchar_t* _Destination,
		rsize_t _SizeInWords,
		wchar_t const* _Source
	);

	__declspec(dllimport) errno_t __cdecl wcsncat_s(
		wchar_t*       _Destination,
		rsize_t        _SizeInWords,
		wchar_t const* _Source,
		rsize_t        _MaxCount
	);

	__declspec(dllimport) errno_t __cdecl wcsncpy_s(
		wchar_t*       _Destination,
		rsize_t        _SizeInWords,
		wchar_t const* _Source,
		rsize_t        _MaxCount
	);

	__declspec(dllimport) wchar_t* __cdecl wcstok_s(
		wchar_t*       _String,
		wchar_t const* _Delimiter,
		wchar_t**      _Context
	);

	__declspec(dllimport) __declspec(allocator) wchar_t* __cdecl _wcsdup(
		wchar_t const* _String
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl wcscat_s(wchar_t(&_Destination)[_Size], wchar_t const* _Source) throw() { return wcscat_s(_Destination, _Size, _Source); } }

#pragma warning(push)
#pragma warning(disable: 28719) 
#pragma warning(disable: 28726) 
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcscat_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl wcscat(wchar_t *_Destination, wchar_t const* _Source);

#pragma warning(pop)

	__declspec(dllimport) int __cdecl wcscmp(
		wchar_t const* _String1,
		wchar_t const* _String2
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl wcscpy_s(wchar_t(&_Destination)[_Size], wchar_t const* _Source) throw() { return wcscpy_s(_Destination, _Size, _Source); } }

#pragma warning(push)
#pragma warning(disable: 28719) 
#pragma warning(disable: 28726) 
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcscpy_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl wcscpy(wchar_t *_Destination, wchar_t const* _Source);

#pragma warning(pop)

	__declspec(dllimport) size_t __cdecl wcscspn(
		wchar_t const* _String,
		wchar_t const* _Control
	);

	__declspec(dllimport) size_t __cdecl wcslen(
		wchar_t const* _String
	);

	__declspec(dllimport) size_t __cdecl wcsnlen(
		wchar_t const* _Source,
		size_t         _MaxCount
	);

	static __inline size_t __cdecl wcsnlen_s(
		wchar_t const* _Source,
		size_t         _MaxCount
	)
	{
		return (_Source == 0) ? 0 : wcsnlen(_Source, _MaxCount);
	}

	extern "C++" { template <size_t _Size> inline errno_t __cdecl wcsncat_s(wchar_t(&_Destination)[_Size], wchar_t const* _Source, size_t _Count) throw() { return wcsncat_s(_Destination, _Size, _Source, _Count); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcsncat_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl wcsncat(wchar_t *_Destination, wchar_t const* _Source, size_t _Count);

	__declspec(dllimport) int __cdecl wcsncmp(
		wchar_t const* _String1,
		wchar_t const* _String2,
		size_t         _MaxCount
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl wcsncpy_s(wchar_t(&_Destination)[_Size], wchar_t const* _Source, size_t _Count) throw() { return wcsncpy_s(_Destination, _Size, _Source, _Count); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcsncpy_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl wcsncpy(wchar_t *_Destination, wchar_t const* _Source, size_t _Count);

	__declspec(dllimport) wchar_t const* __cdecl wcspbrk(
		wchar_t const* _String,
		wchar_t const* _Control
	);

	__declspec(dllimport) size_t __cdecl wcsspn(
		wchar_t const* _String,
		wchar_t const* _Control
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcstok_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) wchar_t* __cdecl wcstok(
			wchar_t*       _String,
			wchar_t const* _Delimiter,
			wchar_t**      _Context
		);

#pragma warning(push)
#pragma warning(disable: 4141 4996) 
#pragma warning(disable: 28719 28726 28727) 
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcstok_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		static __inline wchar_t* __cdecl _wcstok(
			wchar_t*       const _String,
			wchar_t const* const _Delimiter
		)
	{
		return wcstok(_String, _Delimiter, 0);
	}

	extern "C++"   __declspec(deprecated("wcstok has been changed to conform with the ISO C standard, " "adding an extra context parameter. To use the legacy Microsoft " "wcstok, define _CRT_NON_CONFORMING_WCSTOK."))
		inline wchar_t* __cdecl wcstok(
			wchar_t*       _String,
			wchar_t const* _Delimiter
		) throw()
	{
		return wcstok(_String, _Delimiter, 0);
	}

#pragma warning(pop)

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcserror_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) wchar_t* __cdecl _wcserror(
			int _ErrorNumber
		);

	__declspec(dllimport) errno_t __cdecl _wcserror_s(
		wchar_t* _Buffer,
		size_t   _SizeInWords,
		int      _ErrorNumber
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcserror_s(wchar_t(&_Buffer)[_Size], int _Error) throw() { return _wcserror_s(_Buffer, _Size, _Error); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "__wcserror_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) wchar_t* __cdecl __wcserror(
			wchar_t const* _String
		);

	__declspec(dllimport) errno_t __cdecl __wcserror_s(
		wchar_t*       _Buffer,
		size_t         _SizeInWords,
		wchar_t const* _ErrorMessage
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl __wcserror_s(wchar_t(&_Buffer)[_Size], wchar_t const* _ErrorMessage) throw() { return __wcserror_s(_Buffer, _Size, _ErrorMessage); } }

	__declspec(dllimport) int __cdecl _wcsicmp(
		wchar_t const* _String1,
		wchar_t const* _String2
	);

	__declspec(dllimport) int __cdecl _wcsicmp_l(
		wchar_t const* _String1,
		wchar_t const* _String2,
		_locale_t      _Locale
	);

	__declspec(dllimport) int __cdecl _wcsnicmp(
		wchar_t const* _String1,
		wchar_t const* _String2,
		size_t         _MaxCount
	);

	__declspec(dllimport) int __cdecl _wcsnicmp_l(
		wchar_t const* _String1,
		wchar_t const* _String2,
		size_t         _MaxCount,
		_locale_t      _Locale
	);

	__declspec(dllimport) errno_t __cdecl _wcsnset_s(
		wchar_t* _Destination,
		size_t   _SizeInWords,
		wchar_t  _Value,
		size_t   _MaxCount
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcsnset_s(wchar_t(&_Destination)[_Size], wchar_t _Value, size_t _MaxCount) throw() { return _wcsnset_s(_Destination, _Size, _Value, _MaxCount); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcsnset_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl _wcsnset(wchar_t *_String, wchar_t _Value, size_t _MaxCount);

	__declspec(dllimport) wchar_t* __cdecl _wcsrev(
		wchar_t* _String
	);

	__declspec(dllimport) errno_t __cdecl _wcsset_s(
		wchar_t* _Destination,
		size_t   _SizeInWords,
		wchar_t  _Value
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcsset_s(wchar_t(&_String)[_Size], wchar_t _Value) throw() { return _wcsset_s(_String, _Size, _Value); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcsset_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl _wcsset(wchar_t *_String, wchar_t _Value);

	__declspec(dllimport) errno_t __cdecl _wcslwr_s(
		wchar_t* _String,
		size_t   _SizeInWords
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcslwr_s(wchar_t(&_String)[_Size]) throw() { return _wcslwr_s(_String, _Size); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcslwr_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl _wcslwr(wchar_t *_String);

	__declspec(dllimport) errno_t __cdecl _wcslwr_s_l(
		wchar_t*  _String,
		size_t    _SizeInWords,
		_locale_t _Locale
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcslwr_s_l(wchar_t(&_String)[_Size], _locale_t _Locale) throw() { return _wcslwr_s_l(_String, _Size, _Locale); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcslwr_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl _wcslwr_l(wchar_t *_String, _locale_t _Locale);

	__declspec(dllimport) errno_t __cdecl _wcsupr_s(
		wchar_t* _String,
		size_t   _Size
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcsupr_s(wchar_t(&_String)[_Size]) throw() { return _wcsupr_s(_String, _Size); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcsupr_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl _wcsupr(wchar_t *_String);

	__declspec(dllimport) errno_t __cdecl _wcsupr_s_l(
		wchar_t*  _String,
		size_t    _Size,
		_locale_t _Locale
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcsupr_s_l(wchar_t(&_String)[_Size], _locale_t _Locale) throw() { return _wcsupr_s_l(_String, _Size, _Locale); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcsupr_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl _wcsupr_l(wchar_t *_String, _locale_t _Locale);

	__declspec(dllimport) size_t __cdecl wcsxfrm(
		wchar_t*       _Destination,
		wchar_t const* _Source,
		size_t         _MaxCount
	);

	__declspec(dllimport) size_t __cdecl _wcsxfrm_l(
		wchar_t*       _Destination,
		wchar_t const* _Source,
		size_t         _MaxCount,
		_locale_t      _Locale
	);

	__declspec(dllimport) int __cdecl wcscoll(
		wchar_t const* _String1,
		wchar_t const* _String2
	);

	__declspec(dllimport) int __cdecl _wcscoll_l(
		wchar_t const* _String1,
		wchar_t const* _String2,
		_locale_t      _Locale
	);

	__declspec(dllimport) int __cdecl _wcsicoll(
		wchar_t const* _String1,
		wchar_t const* _String2
	);

	__declspec(dllimport) int __cdecl _wcsicoll_l(
		wchar_t const* _String1,
		wchar_t const* _String2,
		_locale_t      _Locale
	);

	__declspec(dllimport) int __cdecl _wcsncoll(
		wchar_t const* _String1,
		wchar_t const* _String2,
		size_t         _MaxCount
	);

	__declspec(dllimport) int __cdecl _wcsncoll_l(
		wchar_t const* _String1,
		wchar_t const* _String2,
		size_t         _MaxCount,
		_locale_t      _Locale
	);

	__declspec(dllimport) int __cdecl _wcsnicoll(
		wchar_t const* _String1,
		wchar_t const* _String2,
		size_t         _MaxCount
	);

	__declspec(dllimport) int __cdecl _wcsnicoll_l(
		wchar_t const* _String1,
		wchar_t const* _String2,
		size_t         _MaxCount,
		_locale_t      _Locale
	);

	extern "C++" {

		inline wchar_t* __cdecl wcschr(wchar_t* _String, wchar_t _C)
		{
			return const_cast<wchar_t*>(wcschr(static_cast<wchar_t const*>(_String), _C));
		}

		inline wchar_t* __cdecl wcspbrk(wchar_t* _String, wchar_t const* _Control)
		{
			return const_cast<wchar_t*>(wcspbrk(static_cast<wchar_t const*>(_String), _Control));
		}

		inline wchar_t* __cdecl wcsrchr(wchar_t* _String, wchar_t _C)
		{
			return const_cast<wchar_t*>(wcsrchr(static_cast<wchar_t const*>(_String), _C));
		}

		inline wchar_t* __cdecl wcsstr(wchar_t* _String, wchar_t const*_SubStr)
		{
			return const_cast<wchar_t*>(wcsstr(static_cast<wchar_t const*>(_String), _SubStr));
		}

	}

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsdup" ". See online help for details."))
		__declspec(dllimport) wchar_t* __cdecl wcsdup(
			wchar_t const* _String
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsicmp" ". See online help for details."))
		__declspec(dllimport) int __cdecl wcsicmp(
			wchar_t const* _String1,
			wchar_t const* _String2
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsnicmp" ". See online help for details."))
		__declspec(dllimport) int __cdecl wcsnicmp(
			wchar_t const* _String1,
			wchar_t const* _String2,
			size_t         _MaxCount
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsnset" ". See online help for details."))

		__declspec(dllimport) wchar_t* __cdecl wcsnset(
			wchar_t* _String,
			wchar_t  _Value,
			size_t   _MaxCount
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsrev" ". See online help for details."))

		__declspec(dllimport) wchar_t* __cdecl wcsrev(
			wchar_t* _String
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsset" ". See online help for details."))

		__declspec(dllimport) wchar_t* __cdecl wcsset(
			wchar_t* _String,
			wchar_t  _Value
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcslwr" ". See online help for details."))

		__declspec(dllimport) wchar_t* __cdecl wcslwr(
			wchar_t* _String
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsupr" ". See online help for details."))

		__declspec(dllimport) wchar_t* __cdecl wcsupr(
			wchar_t* _String
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsicoll" ". See online help for details."))
		__declspec(dllimport) int __cdecl wcsicoll(
			wchar_t const* _String1,
			wchar_t const* _String2
		);

} __pragma(pack(pop))

__pragma(pack(push, 8)) extern "C" {

	__declspec(dllimport) errno_t __cdecl strcpy_s(
		char*       _Destination,
		rsize_t     _SizeInBytes,
		char const* _Source
	);

	__declspec(dllimport) errno_t __cdecl strcat_s(
		char*       _Destination,
		rsize_t     _SizeInBytes,
		char const* _Source
	);

	__declspec(dllimport) errno_t __cdecl strerror_s(
		char*  _Buffer,
		size_t _SizeInBytes,
		int    _ErrorNumber);

	__declspec(dllimport) errno_t __cdecl strncat_s(
		char*       _Destination,
		rsize_t     _SizeInBytes,
		char const* _Source,
		rsize_t     _MaxCount
	);

	__declspec(dllimport) errno_t __cdecl strncpy_s(
		char*       _Destination,
		rsize_t     _SizeInBytes,
		char const* _Source,
		rsize_t     _MaxCount
	);

	__declspec(dllimport) char*  __cdecl strtok_s(
		char*       _String,
		char const* _Delimiter,
		char**      _Context
	);

	__declspec(dllimport) void* __cdecl _memccpy(
		void*       _Dst,
		void const* _Src,
		int         _Val,
		size_t      _MaxCount
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl strcat_s(char(&_Destination)[_Size], char const* _Source) throw() { return strcat_s(_Destination, _Size, _Source); } }

#pragma warning(push)
#pragma warning(disable: 28719) 
#pragma warning(disable: 28726) 
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "strcat_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))  char* __cdecl strcat(char *_Destination, char const* _Source);

#pragma warning(pop)

	int __cdecl strcmp(
		char const* _Str1,
		char const* _Str2
	);

	__declspec(dllimport) int __cdecl _strcmpi(
		char const* _String1,
		char const* _String2
	);

	__declspec(dllimport) int __cdecl strcoll(
		char const* _String1,
		char const* _String2
	);

	__declspec(dllimport) int __cdecl _strcoll_l(
		char const* _String1,
		char const* _String2,
		_locale_t   _Locale
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl strcpy_s(char(&_Destination)[_Size], char const* _Source) throw() { return strcpy_s(_Destination, _Size, _Source); } }

#pragma warning(push)
#pragma warning(disable: 28719) 
#pragma warning(disable: 28726) 
	__declspec(deprecated("This function or variable may be unsafe. Consider using " "strcpy_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))  char* __cdecl strcpy(char *_Destination, char const* _Source);

#pragma warning(pop)

	__declspec(dllimport) size_t __cdecl strcspn(
		char const* _Str,
		char const* _Control
	);

	__declspec(dllimport) __declspec(allocator) char* __cdecl _strdup(
		char const* _Source
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strerror_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char*  __cdecl _strerror(
			char const* _ErrorMessage
		);

	__declspec(dllimport) errno_t __cdecl _strerror_s(
		char*       _Buffer,
		size_t      _SizeInBytes,
		char const* _ErrorMessage
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _strerror_s(char(&_Buffer)[_Size], char const* _ErrorMessage) throw() { return _strerror_s(_Buffer, _Size, _ErrorMessage); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "strerror_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl strerror(
			int _ErrorMessage
		);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl strerror_s(char(&_Buffer)[_Size], int _ErrorMessage) throw() { return strerror_s(_Buffer, _Size, _ErrorMessage); } }

	__declspec(dllimport) int __cdecl _stricmp(
		char const* _String1,
		char const* _String2
	);

	__declspec(dllimport) int __cdecl _stricoll(
		char const* _String1,
		char const* _String2
	);

	__declspec(dllimport) int __cdecl _stricoll_l(
		char const* _String1,
		char const* _String2,
		_locale_t   _Locale
	);

	__declspec(dllimport) int __cdecl _stricmp_l(
		char const* _String1,
		char const* _String2,
		_locale_t   _Locale
	);

	size_t __cdecl strlen(
		char const* _Str
	);

	__declspec(dllimport) errno_t __cdecl _strlwr_s(
		char*  _String,
		size_t _Size
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _strlwr_s(char(&_String)[_Size]) throw() { return _strlwr_s(_String, _Size); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strlwr_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) char* __cdecl _strlwr(char *_String);

	__declspec(dllimport) errno_t __cdecl _strlwr_s_l(
		char*     _String,
		size_t    _Size,
		_locale_t _Locale
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _strlwr_s_l(char(&_String)[_Size], _locale_t _Locale) throw() { return _strlwr_s_l(_String, _Size, _Locale); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strlwr_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) char* __cdecl _strlwr_l(char *_String, _locale_t _Locale);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl strncat_s(char(&_Destination)[_Size], char const* _Source, size_t _Count) throw() { return strncat_s(_Destination, _Size, _Source, _Count); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "strncat_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) char* __cdecl strncat(char *_Destination, char const* _Source, size_t _Count);

	__declspec(dllimport) int __cdecl strncmp(
		char const* _Str1,
		char const* _Str2,
		size_t      _MaxCount
	);

	__declspec(dllimport) int __cdecl _strnicmp(
		char const* _String1,
		char const* _String2,
		size_t      _MaxCount
	);

	__declspec(dllimport) int __cdecl _strnicmp_l(
		char const* _String1,
		char const* _String2,
		size_t      _MaxCount,
		_locale_t   _Locale
	);

	__declspec(dllimport) int __cdecl _strnicoll(
		char const* _String1,
		char const* _String2,
		size_t      _MaxCount
	);

	__declspec(dllimport) int __cdecl _strnicoll_l(
		char const* _String1,
		char const* _String2,
		size_t      _MaxCount,
		_locale_t   _Locale
	);

	__declspec(dllimport) int __cdecl _strncoll(
		char const* _String1,
		char const* _String2,
		size_t      _MaxCount
	);

	__declspec(dllimport) int __cdecl _strncoll_l(
		char const* _String1,
		char const* _String2,
		size_t      _MaxCount,
		_locale_t   _Locale
	);

	__declspec(dllimport) size_t __cdecl __strncnt(
		char const* _String,
		size_t      _Count
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl strncpy_s(char(&_Destination)[_Size], char const* _Source, size_t _Count) throw() { return strncpy_s(_Destination, _Size, _Source, _Count); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "strncpy_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) char* __cdecl strncpy(char *_Destination, char const* _Source, size_t _Count);

	__declspec(dllimport) size_t __cdecl strnlen(
		char const* _String,
		size_t      _MaxCount
	);

	static __inline size_t __cdecl strnlen_s(
		char const* _String,
		size_t      _MaxCount
	)
	{
		return _String == 0 ? 0 : strnlen(_String, _MaxCount);
	}

	__declspec(dllimport) errno_t __cdecl _strnset_s(
		char*  _String,
		size_t _SizeInBytes,
		int    _Value,
		size_t _MaxCount
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _strnset_s(char(&_Destination)[_Size], int _Value, size_t _Count) throw() { return _strnset_s(_Destination, _Size, _Value, _Count); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strnset_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) char* __cdecl _strnset(char *_Destination, int _Value, size_t _Count);

	__declspec(dllimport) char const* __cdecl strpbrk(
		char const* _Str,
		char const* _Control
	);

	__declspec(dllimport) char* __cdecl _strrev(
		char* _Str
	);

	__declspec(dllimport) errno_t __cdecl _strset_s(
		char*  _Destination,
		size_t _DestinationSize,
		int    _Value
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _strset_s(char(&_Destination)[_Size], int _Value) throw() { return _strset_s(_Destination, _Size, _Value); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strset_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))  char* __cdecl _strset(char *_Destination, int _Value);

	__declspec(dllimport) size_t __cdecl strspn(
		char const* _Str,
		char const* _Control
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "strtok_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) char* __cdecl strtok(
			char*       _String,
			char const* _Delimiter
		);

	__declspec(dllimport) errno_t __cdecl _strupr_s(
		char*  _String,
		size_t _Size
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _strupr_s(char(&_String)[_Size]) throw() { return _strupr_s(_String, _Size); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strupr_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) char* __cdecl _strupr(char *_String);

	__declspec(dllimport) errno_t __cdecl _strupr_s_l(
		char*     _String,
		size_t    _Size,
		_locale_t _Locale
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _strupr_s_l(char(&_String)[_Size], _locale_t _Locale) throw() { return _strupr_s_l(_String, _Size, _Locale); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strupr_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) char* __cdecl _strupr_l(char *_String, _locale_t _Locale);

	__declspec(dllimport) size_t __cdecl strxfrm(
		char*       _Destination,
		char const* _Source,
		size_t      _MaxCount
	);

	__declspec(dllimport) size_t __cdecl _strxfrm_l(
		char*       _Destination,
		char const* _Source,
		size_t      _MaxCount,
		_locale_t   _Locale
	);

	extern "C++"
	{

		inline char* __cdecl strchr(char* const _String, int const _Ch)
		{
			return const_cast<char*>(strchr(static_cast<char const*>(_String), _Ch));
		}

		inline char* __cdecl strpbrk(char* const _String, char const* const _Control)
		{
			return const_cast<char*>(strpbrk(static_cast<char const*>(_String), _Control));
		}

		inline char* __cdecl strrchr(char* const _String, int const _Ch)
		{
			return const_cast<char*>(strrchr(static_cast<char const*>(_String), _Ch));
		}

		inline char* __cdecl strstr(char* const _String, char const* const _SubString)
		{
			return const_cast<char*>(strstr(static_cast<char const*>(_String), _SubString));
		}
	}

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strdup" ". See online help for details."))
		__declspec(dllimport) char* __cdecl strdup(
			char const* _String
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strcmpi" ". See online help for details."))
		__declspec(dllimport) int __cdecl strcmpi(
			char const* _String1,
			char const* _String2
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_stricmp" ". See online help for details."))
		__declspec(dllimport) int __cdecl stricmp(
			char const* _String1,
			char const* _String2
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strlwr" ". See online help for details."))
		__declspec(dllimport) char* __cdecl strlwr(
			char* _String
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strnicmp" ". See online help for details."))
		__declspec(dllimport) int __cdecl strnicmp(
			char const* _String1,
			char const* _String2,
			size_t      _MaxCount
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strnset" ". See online help for details."))
		__declspec(dllimport) char* __cdecl strnset(
			char*  _String,
			int    _Value,
			size_t _MaxCount
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strrev" ". See online help for details."))
		__declspec(dllimport) char* __cdecl strrev(
			char* _String
		);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strset" ". See online help for details."))
		char* __cdecl strset(
			char* _String,
			int   _Value);

	__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strupr" ". See online help for details."))
		__declspec(dllimport) char* __cdecl strupr(
			char* _String
		);

} __pragma(pack(pop))

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {
#pragma warning(push)
#pragma warning(disable: 4995) 

	using ::size_t; using ::memchr; using ::memcmp;
	using ::memcpy; using ::memmove; using ::memset;
	using ::strcat; using ::strchr; using ::strcmp;
	using ::strcoll; using ::strcpy; using ::strcspn;
	using ::strerror; using ::strlen; using ::strncat;
	using ::strncmp; using ::strncpy; using ::strpbrk;
	using ::strrchr; using ::strspn; using ::strstr;
	using ::strtok; using ::strxfrm;

#pragma warning(pop)
}

#pragma warning(pop)
#pragma pack(pop)

#pragma once

#pragma once

#pragma once

__pragma(pack(push, 8)) extern "C" {

	__declspec(dllimport) errno_t __cdecl _cgetws_s(
		wchar_t* _Buffer,
		size_t   _BufferCount,
		size_t*  _SizeRead
	);

	extern "C++" { template <size_t _Size> inline   errno_t __cdecl _cgetws_s(wchar_t(&_Buffer)[_Size], size_t* _SizeRead) throw() { return _cgetws_s(_Buffer, _Size, _SizeRead); } }

	__declspec(dllimport) int __cdecl _cputws(
		wchar_t const* _Buffer
	);

	__declspec(dllimport) wint_t __cdecl _getwch(void);
	__declspec(dllimport) wint_t __cdecl _getwche(void);
	__declspec(dllimport) wint_t __cdecl _putwch(wchar_t _Character);
	__declspec(dllimport) wint_t __cdecl _ungetwch(wint_t  _Character);

	__declspec(dllimport) wint_t __cdecl _getwch_nolock(void);
	__declspec(dllimport) wint_t __cdecl _getwche_nolock(void);
	__declspec(dllimport) wint_t __cdecl _putwch_nolock(wchar_t _Character);
	__declspec(dllimport) wint_t __cdecl _ungetwch_nolock(wint_t  _Character);

	__declspec(dllimport) int __cdecl __conio_common_vcwprintf(
		unsigned __int64 _Options,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(dllimport) int __cdecl __conio_common_vcwprintf_s(
		unsigned __int64 _Options,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(dllimport) int __cdecl __conio_common_vcwprintf_p(
		unsigned __int64 _Options,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__inline int __cdecl _vcwprintf_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return __conio_common_vcwprintf((*__local_stdio_printf_options()), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl _vcwprintf(
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vcwprintf_l(_Format, 0, _ArgList);
	}

	__inline int __cdecl _vcwprintf_s_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return __conio_common_vcwprintf_s((*__local_stdio_printf_options()), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl _vcwprintf_s(
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vcwprintf_s_l(_Format, 0, _ArgList);
	}

	__inline int __cdecl _vcwprintf_p_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return __conio_common_vcwprintf_p((*__local_stdio_printf_options()), _Format, _Locale, _ArgList);
	}

	__inline int __cdecl _vcwprintf_p(
		const wchar_t* const _Format,
		va_list              _ArgList
	)

	{
		return _vcwprintf_p_l(_Format, 0, _ArgList);
	}

	__inline int __cdecl _cwprintf_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vcwprintf_l(_Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _cwprintf(
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vcwprintf_l(_Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _cwprintf_s_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vcwprintf_s_l(_Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _cwprintf_s(
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vcwprintf_s_l(_Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _cwprintf_p_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vcwprintf_p_l(_Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _cwprintf_p(
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vcwprintf_p_l(_Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(dllimport) int __cdecl __conio_common_vcwscanf(
		unsigned __int64 _Options,
		wchar_t const*   _Format,
		_locale_t        _Locale,
		va_list          _ArgList
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_vcwscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _vcwscanf_l(
			wchar_t const* const _Format,
			_locale_t      const _Locale,
			va_list              _ArgList
		)

	{
		return __conio_common_vcwscanf(
			(*__local_stdio_scanf_options()),
			_Format, _Locale, _ArgList);
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_vcwscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _vcwscanf(
			wchar_t const* const _Format,
			va_list              _ArgList
		)

	{
#pragma warning(push)
#pragma warning(disable: 4996) 
		return _vcwscanf_l(_Format, 0, _ArgList);
#pragma warning(pop)
	}

	__inline int __cdecl _vcwscanf_s_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		va_list              _ArgList
	)

	{
		return __conio_common_vcwscanf(
			(*__local_stdio_scanf_options()) | (1ULL << 0),
			_Format, _Locale, _ArgList);
	}

	__inline int __cdecl _vcwscanf_s(
		wchar_t const* const _Format,
		va_list              _ArgList
	)

	{
		return _vcwscanf_s_l(_Format, 0, _ArgList);
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_cwscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _cwscanf_l(
			wchar_t const* const _Format,
			_locale_t      const _Locale,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

#pragma warning(push)
#pragma warning(disable: 4996) 
		_Result = _vcwscanf_l(_Format, _Locale, _ArgList);
#pragma warning(pop)

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_cwscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__inline int __cdecl _cwscanf(
			wchar_t const* const _Format,
			...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));

#pragma warning(push)
#pragma warning(disable: 4996) 
		_Result = _vcwscanf_l(_Format, 0, _ArgList);
#pragma warning(pop)

		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _cwscanf_s_l(
		wchar_t const* const _Format,
		_locale_t      const _Locale,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Locale)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Locale))) + ((sizeof(_Locale) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vcwscanf_s_l(_Format, _Locale, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

	__inline int __cdecl _cwscanf_s(
		wchar_t const* const _Format,
		...)

	{
		int _Result;
		va_list _ArgList;
		((void)(__vcrt_assert_va_start_is_not_reference<decltype(_Format)>(), ((void)(_ArgList = (va_list)(&const_cast<char&>(reinterpret_cast<const volatile char&>(_Format))) + ((sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1))))));
		_Result = _vcwscanf_s_l(_Format, 0, _ArgList);
		((void)(_ArgList = (va_list)0));
		return _Result;
	}

} __pragma(pack(pop))

#pragma once

__pragma(pack(push, 8)) extern "C" {

	__declspec(dllimport) const unsigned short* __cdecl __pctype_func(void);
	__declspec(dllimport) const wctype_t*       __cdecl __pwctype_func(void);

	__declspec(dllimport) int __cdecl iswalnum(wint_t _C);
	__declspec(dllimport) int __cdecl iswalpha(wint_t _C);
	__declspec(dllimport) int __cdecl iswascii(wint_t _C);
	__declspec(dllimport) int __cdecl iswblank(wint_t _C);
	__declspec(dllimport) int __cdecl iswcntrl(wint_t _C);

	__declspec(dllimport) int __cdecl iswdigit(wint_t _C);

	__declspec(dllimport) int __cdecl iswgraph(wint_t _C);
	__declspec(dllimport) int __cdecl iswlower(wint_t _C);
	__declspec(dllimport) int __cdecl iswprint(wint_t _C);
	__declspec(dllimport) int __cdecl iswpunct(wint_t _C);
	__declspec(dllimport) int __cdecl iswspace(wint_t _C);
	__declspec(dllimport) int __cdecl iswupper(wint_t _C);
	__declspec(dllimport) int __cdecl iswxdigit(wint_t _C);
	__declspec(dllimport) int __cdecl __iswcsymf(wint_t _C);
	__declspec(dllimport) int __cdecl __iswcsym(wint_t _C);

	__declspec(dllimport) int __cdecl _iswalnum_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswalpha_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswblank_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswcntrl_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswdigit_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswgraph_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswlower_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswprint_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswpunct_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswspace_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswupper_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswxdigit_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswcsymf_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int __cdecl _iswcsym_l(wint_t _C, _locale_t _Locale);

	__declspec(dllimport) wint_t __cdecl towupper(wint_t _C);
	__declspec(dllimport) wint_t __cdecl towlower(wint_t _C);
	__declspec(dllimport) int    __cdecl iswctype(wint_t _C, wctype_t _Type);

	__declspec(dllimport) wint_t __cdecl _towupper_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) wint_t __cdecl _towlower_l(wint_t _C, _locale_t _Locale);
	__declspec(dllimport) int    __cdecl _iswctype_l(wint_t _C, wctype_t _Type, _locale_t _Locale);

	__declspec(dllimport) int __cdecl isleadbyte(int _C);
	__declspec(dllimport) int __cdecl _isleadbyte_l(int _C, _locale_t _Locale);

	__declspec(deprecated("This function or variable has been superceded by newer library " "or operating system functionality. Consider using " "iswctype" " " "instead. See online help for details.")) __declspec(dllimport) int __cdecl is_wctype(wint_t _C, wctype_t _Type);

} __pragma(pack(pop))

#pragma once

__pragma(pack(push, 8)) extern "C" {

	__declspec(dllimport) __declspec(allocator) wchar_t* __cdecl _wgetcwd(
		wchar_t* _DstBuf,
		int      _SizeInWords
	);

	__declspec(dllimport) __declspec(allocator) wchar_t* __cdecl _wgetdcwd(
		int      _Drive,
		wchar_t* _DstBuf,
		int      _SizeInWords
	);

	__declspec(dllimport) int __cdecl _wchdir(
		wchar_t const* _Path
	);

	__declspec(dllimport) int __cdecl _wmkdir(
		wchar_t const* _Path
	);

	__declspec(dllimport) int __cdecl _wrmdir(
		wchar_t const* _Path
	);

} __pragma(pack(pop))

#pragma once

#pragma once

__pragma(pack(push, 8)) extern "C" {

#pragma warning(push)
#pragma warning(disable:4820) 

	typedef unsigned long _fsize_t;

	struct _wfinddata32_t
	{
		unsigned   attrib;
		__time32_t time_create;
		__time32_t time_access;
		__time32_t time_write;
		_fsize_t   size;
		wchar_t    name[260];
	};

	struct _wfinddata32i64_t
	{
		unsigned   attrib;
		__time32_t time_create;
		__time32_t time_access;
		__time32_t time_write;
		__int64    size;
		wchar_t    name[260];
	};

	struct _wfinddata64i32_t
	{
		unsigned   attrib;
		__time64_t time_create;
		__time64_t time_access;
		__time64_t time_write;
		_fsize_t   size;
		wchar_t    name[260];
	};

	struct _wfinddata64_t
	{
		unsigned   attrib;
		__time64_t time_create;
		__time64_t time_access;
		__time64_t time_write;
		__int64    size;
		wchar_t    name[260];
	};

	__declspec(dllimport) int __cdecl _waccess(
		wchar_t const* _FileName,
		int            _AccessMode
	);

	__declspec(dllimport) errno_t __cdecl _waccess_s(
		wchar_t const* _FileName,
		int            _AccessMode
	);

	__declspec(dllimport) int __cdecl _wchmod(
		wchar_t const* _FileName,
		int            _Mode
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wsopen_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) int __cdecl _wcreat(
			wchar_t const* _FileName,
			int            _PermissionMode
		);

	__declspec(dllimport) intptr_t __cdecl _wfindfirst32(
		wchar_t const*         _FileName,
		struct _wfinddata32_t* _FindData
	);

	__declspec(dllimport) int __cdecl _wfindnext32(
		intptr_t               _FindHandle,
		struct _wfinddata32_t* _FindData
	);

	__declspec(dllimport) int __cdecl _wunlink(
		wchar_t const* _FileName
	);

	__declspec(dllimport) int __cdecl _wrename(
		wchar_t const* _OldFileName,
		wchar_t const* _NewFileName
	);

	__declspec(dllimport) errno_t __cdecl _wmktemp_s(
		wchar_t* _TemplateName,
		size_t   _SizeInWords
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wmktemp_s(wchar_t(&_TemplateName)[_Size]) throw() { return _wmktemp_s(_TemplateName, _Size); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wmktemp_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) wchar_t* __cdecl _wmktemp(wchar_t *_TemplateName);

	__declspec(dllimport) intptr_t __cdecl _wfindfirst32i64(
		wchar_t const*            _FileName,
		struct _wfinddata32i64_t* _FindData
	);

	__declspec(dllimport) intptr_t __cdecl _wfindfirst64i32(
		wchar_t const*            _FileName,
		struct _wfinddata64i32_t* _FindData
	);

	__declspec(dllimport) intptr_t __cdecl _wfindfirst64(
		wchar_t const*         _FileName,
		struct _wfinddata64_t* _FindData
	);

	__declspec(dllimport) int __cdecl _wfindnext32i64(
		intptr_t                  _FindHandle,
		struct _wfinddata32i64_t* _FindData
	);

	__declspec(dllimport) int __cdecl _wfindnext64i32(
		intptr_t                  _FindHandle,
		struct _wfinddata64i32_t* _FindData
	);

	__declspec(dllimport) int __cdecl _wfindnext64(
		intptr_t               _FindHandle,
		struct _wfinddata64_t* _FindData
	);

	__declspec(dllimport) errno_t __cdecl _wsopen_s(
		int*           _FileHandle,
		wchar_t const* _FileName,
		int            _OpenFlag,
		int            _ShareFlag,
		int            _PermissionFlag
	);

	__declspec(dllimport) errno_t __cdecl _wsopen_dispatch(
		wchar_t const* _FileName,
		int            _OFlag,
		int            _ShFlag,
		int            _PMode,
		int*           _PFileHandle,
		int            _BSecure
	);

	extern "C++"   __declspec(deprecated("This function or variable may be unsafe. Consider using " "_wsopen_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		inline int __cdecl _wopen(
			wchar_t const* _FileName,
			int            _OFlag,
			int            _PMode = 0
		)
	{
		int _FileHandle;

		errno_t const _Result = _wsopen_dispatch(_FileName, _OFlag, 0x40, _PMode, &_FileHandle, 0);
		return _Result ? -1 : _FileHandle;
	}

	extern "C++"   __declspec(deprecated("This function or variable may be unsafe. Consider using " "_wsopen_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		inline int __cdecl _wsopen(
			wchar_t const* _FileName,
			int            _OFlag,
			int            _ShFlag,
			int            _PMode = 0
		)
	{
		int _FileHandle;

		errno_t const _Result = _wsopen_dispatch(_FileName, _OFlag, _ShFlag, _PMode, &_FileHandle, 0);
		return _Result ? -1 : _FileHandle;
	}

#pragma warning(pop)

} __pragma(pack(pop))

#pragma once

__pragma(pack(push, 8)) extern "C" {

	__declspec(dllimport) intptr_t __cdecl _wexecl(
		wchar_t const* _FileName,
		wchar_t const* _ArgList,
		...);

	__declspec(dllimport) intptr_t __cdecl _wexecle(
		wchar_t const* _FileName,
		wchar_t const* _ArgList,
		...);

	__declspec(dllimport) intptr_t __cdecl _wexeclp(
		wchar_t const* _FileName,
		wchar_t const* _ArgList,
		...);

	__declspec(dllimport) intptr_t __cdecl _wexeclpe(
		wchar_t const* _FileName,
		wchar_t const* _ArgList,
		...);

	__declspec(dllimport) intptr_t __cdecl _wexecv(
		wchar_t const*        _FileName,
		wchar_t const* const* _ArgList
	);

	__declspec(dllimport) intptr_t __cdecl _wexecve(
		wchar_t const*        _FileName,
		wchar_t const* const* _ArgList,
		wchar_t const* const* _Env
	);

	__declspec(dllimport) intptr_t __cdecl _wexecvp(
		wchar_t const*        _FileName,
		wchar_t const* const* _ArgList
	);

	__declspec(dllimport) intptr_t __cdecl _wexecvpe(
		wchar_t const*        _FileName,
		wchar_t const* const* _ArgList,
		wchar_t const* const* _Env
	);

	__declspec(dllimport) intptr_t __cdecl _wspawnl(
		int            _Mode,
		wchar_t const* _FileName,
		wchar_t const* _ArgList,
		...);

	__declspec(dllimport) intptr_t __cdecl _wspawnle(
		int            _Mode,
		wchar_t const* _FileName,
		wchar_t const* _ArgList,
		...);

	__declspec(dllimport) intptr_t __cdecl _wspawnlp(
		int            _Mode,
		wchar_t const* _FileName,
		wchar_t const* _ArgList,
		...);

	__declspec(dllimport) intptr_t __cdecl _wspawnlpe(
		int            _Mode,
		wchar_t const* _FileName,
		wchar_t const* _ArgList,
		...);

	__declspec(dllimport) intptr_t __cdecl _wspawnv(
		int                   _Mode,
		wchar_t const*        _FileName,
		wchar_t const* const* _ArgList
	);

	__declspec(dllimport) intptr_t __cdecl _wspawnve(
		int                   _Mode,
		wchar_t const*        _FileName,
		wchar_t const* const* _ArgList,
		wchar_t const* const* _Env
	);

	__declspec(dllimport) intptr_t __cdecl _wspawnvp(
		int                   _Mode,
		wchar_t const*        _FileName,
		wchar_t const* const* _ArgList
	);

	__declspec(dllimport) intptr_t __cdecl _wspawnvpe(
		int                   _Mode,
		wchar_t const*        _FileName,
		wchar_t const* const* _ArgList,
		wchar_t const* const* _Env
	);

	__declspec(dllimport) int __cdecl _wsystem(
		wchar_t const* _Command
	);

} __pragma(pack(pop))

#pragma once

__pragma(pack(push, 8)) extern "C" {

	struct tm
	{
		int tm_sec;
		int tm_min;
		int tm_hour;
		int tm_mday;
		int tm_mon;
		int tm_year;
		int tm_wday;
		int tm_yday;
		int tm_isdst;
	};

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wasctime_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))

		__declspec(dllimport) wchar_t* __cdecl _wasctime(
			struct tm const* _Tm
		);

	__declspec(dllimport) errno_t __cdecl _wasctime_s(
		wchar_t*         _Buffer,
		size_t           _SizeInWords,
		struct tm const* _Tm
	);

	extern "C++" { template <size_t _Size> inline   errno_t __cdecl _wasctime_s(wchar_t(&_Buffer)[_Size], struct tm const* _Time) throw() { return _wasctime_s(_Buffer, _Size, _Time); } }

	__declspec(dllimport) size_t __cdecl wcsftime(
		wchar_t*         _Buffer,
		size_t           _SizeInWords,
		wchar_t const*   _Format,
		struct tm const* _Tm
	);

	__declspec(dllimport) size_t __cdecl _wcsftime_l(
		wchar_t*         _Buffer,
		size_t           _SizeInWords,
		wchar_t const*   _Format,
		struct tm const* _Tm,
		_locale_t        _Locale
	);

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wctime32_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) wchar_t* __cdecl _wctime32(
			__time32_t const* _Time
		);

	__declspec(dllimport) errno_t __cdecl _wctime32_s(
		wchar_t*          _Buffer,
		size_t            _SizeInWords,
		__time32_t const* _Time
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wctime32_s(wchar_t(&_Buffer)[_Size], __time32_t const* _Time) throw() { return _wctime32_s(_Buffer, _Size, _Time); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wctime64_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) wchar_t* __cdecl _wctime64(
			__time64_t const* _Time
		);

	__declspec(dllimport) errno_t __cdecl _wctime64_s(
		wchar_t*          _Buffer,
		size_t            _SizeInWords,
		__time64_t const* _Time);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wctime64_s(wchar_t(&_Buffer)[_Size], __time64_t const* _Time) throw() { return _wctime64_s(_Buffer, _Size, _Time); } }

	__declspec(dllimport) errno_t __cdecl _wstrdate_s(
		wchar_t* _Buffer,
		size_t   _SizeInWords
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wstrdate_s(wchar_t(&_Buffer)[_Size]) throw() { return _wstrdate_s(_Buffer, _Size); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wstrdate_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport)  wchar_t* __cdecl _wstrdate(wchar_t *_Buffer);

	__declspec(dllimport) errno_t __cdecl _wstrtime_s(
		wchar_t* _Buffer,
		size_t   _SizeInWords
	);

	extern "C++" { template <size_t _Size> inline errno_t __cdecl _wstrtime_s(wchar_t(&_Buffer)[_Size]) throw() { return _wstrtime_s(_Buffer, _Size); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wstrtime_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport)  wchar_t* __cdecl _wstrtime(wchar_t *_Buffer);

#pragma warning(push)
#pragma warning(disable: 4996)

	static __inline wchar_t * __cdecl _wctime(
		time_t const* const _Time)
	{
		return _wctime64(_Time);
	}

	static __inline errno_t __cdecl _wctime_s(
		wchar_t*      const _Buffer,
		size_t        const _SizeInWords,
		time_t const* const _Time
	)
	{
		return _wctime64_s(_Buffer, _SizeInWords, _Time);
	}

#pragma warning(pop)

} __pragma(pack(pop))

#pragma once

#pragma once

typedef unsigned short _ino_t;

typedef _ino_t ino_t;

typedef unsigned int _dev_t;

typedef _dev_t dev_t;

typedef long _off_t;

typedef _off_t off_t;

__pragma(pack(push, 8)) extern "C" {

#pragma warning(push)
#pragma warning(disable: 4820) 

	struct _stat32
	{
		_dev_t         st_dev;
		_ino_t         st_ino;
		unsigned short st_mode;
		short          st_nlink;
		short          st_uid;
		short          st_gid;
		_dev_t         st_rdev;
		_off_t         st_size;
		__time32_t     st_atime;
		__time32_t     st_mtime;
		__time32_t     st_ctime;
	};

	struct _stat32i64
	{
		_dev_t         st_dev;
		_ino_t         st_ino;
		unsigned short st_mode;
		short          st_nlink;
		short          st_uid;
		short          st_gid;
		_dev_t         st_rdev;
		__int64        st_size;
		__time32_t     st_atime;
		__time32_t     st_mtime;
		__time32_t     st_ctime;
	};

	struct _stat64i32
	{
		_dev_t         st_dev;
		_ino_t         st_ino;
		unsigned short st_mode;
		short          st_nlink;
		short          st_uid;
		short          st_gid;
		_dev_t         st_rdev;
		_off_t         st_size;
		__time64_t     st_atime;
		__time64_t     st_mtime;
		__time64_t     st_ctime;
	};

	struct _stat64
	{
		_dev_t         st_dev;
		_ino_t         st_ino;
		unsigned short st_mode;
		short          st_nlink;
		short          st_uid;
		short          st_gid;
		_dev_t         st_rdev;
		__int64        st_size;
		__time64_t     st_atime;
		__time64_t     st_mtime;
		__time64_t     st_ctime;
	};

	struct stat
	{
		_dev_t         st_dev;
		_ino_t         st_ino;
		unsigned short st_mode;
		short          st_nlink;
		short          st_uid;
		short          st_gid;
		_dev_t         st_rdev;
		_off_t         st_size;
		time_t         st_atime;
		time_t         st_mtime;
		time_t         st_ctime;
	};

	__declspec(dllimport) int __cdecl _fstat32(
		int             _FileHandle,
		struct _stat32* _Stat
	);

	__declspec(dllimport) int __cdecl _fstat32i64(
		int                _FileHandle,
		struct _stat32i64* _Stat
	);

	__declspec(dllimport) int __cdecl _fstat64i32(
		int                _FileHandle,
		struct _stat64i32* _Stat
	);

	__declspec(dllimport) int __cdecl _fstat64(
		int             _FileHandle,
		struct _stat64* _Stat
	);

	__declspec(dllimport) int __cdecl _stat32(
		char const*     _FileName,
		struct _stat32* _Stat
	);

	__declspec(dllimport) int __cdecl _stat32i64(
		char const*        _FileName,
		struct _stat32i64* _Stat
	);

	__declspec(dllimport) int __cdecl _stat64i32(
		char const*        _FileName,
		struct _stat64i32* _Stat
	);

	__declspec(dllimport) int __cdecl _stat64(
		char const*     _FileName,
		struct _stat64* _Stat
	);

	__declspec(dllimport) int __cdecl _wstat32(
		wchar_t const*  _FileName,
		struct _stat32* _Stat
	);

	__declspec(dllimport) int __cdecl _wstat32i64(
		wchar_t const*     _FileName,
		struct _stat32i64* _Stat
	);

	__declspec(dllimport) int __cdecl _wstat64i32(
		wchar_t const*     _FileName,
		struct _stat64i32* _Stat
	);

	__declspec(dllimport) int __cdecl _wstat64(
		wchar_t const*  _FileName,
		struct _stat64* _Stat
	);

	static __inline int __cdecl fstat(int const _FileHandle, struct stat* const _Stat)
	{
		typedef char __static_assert_t[(sizeof(struct stat) == sizeof(struct _stat64i32)) != 0];
		return _fstat64i32(_FileHandle, (struct _stat64i32*)_Stat);
	}
	static __inline int __cdecl stat(char const* const _FileName, struct stat* const _Stat)
	{
		typedef char __static_assert_t[(sizeof(struct stat) == sizeof(struct _stat64i32)) != 0];
		return _stat64i32(_FileName, (struct _stat64i32*)_Stat);
	}

#pragma warning(pop)

} __pragma(pack(pop))

__pragma(pack(push, 8)) extern "C" {

	typedef wchar_t _Wint_t;

	__declspec(dllimport) wchar_t* __cdecl _wsetlocale(
		int            _Category,
		wchar_t const* _Locale
	);

	__declspec(dllimport) _locale_t __cdecl _wcreate_locale(
		int            _Category,
		wchar_t const* _Locale
	);

	__declspec(dllimport) wint_t __cdecl btowc(
		int _Ch
	);

	__declspec(dllimport) size_t __cdecl mbrlen(
		char const* _Ch,
		size_t      _SizeInBytes,
		mbstate_t*  _State
	);

	__declspec(dllimport) size_t __cdecl mbrtowc(
		wchar_t*    _DstCh,
		char const* _SrcCh,
		size_t      _SizeInBytes,
		mbstate_t*  _State
	);

	__declspec(dllimport) errno_t __cdecl mbsrtowcs_s(
		size_t*      _Retval,
		wchar_t*     _Dst,
		size_t       _Size,
		char const** _PSrc,
		size_t       _N,
		mbstate_t*   _State
	);

	extern "C++" { template <size_t _Size> inline   errno_t __cdecl mbsrtowcs_s(size_t* _Retval, wchar_t(&_Dest)[_Size], char const** _PSource, size_t _Count, mbstate_t* _State) throw() { return mbsrtowcs_s(_Retval, _Dest, _Size, _PSource, _Count, _State); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "mbsrtowcs_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))  __declspec(dllimport) size_t __cdecl mbsrtowcs(wchar_t *_Dest, char const** _PSrc, size_t _Count, mbstate_t* _State);

	__declspec(dllimport) errno_t __cdecl wcrtomb_s(
		size_t*    _Retval,
		char*      _Dst,
		size_t     _SizeInBytes,
		wchar_t    _Ch,
		mbstate_t* _State
	);

	extern "C++" { template <size_t _Size> inline   errno_t __cdecl wcrtomb_s(size_t* _Retval, char(&_Dest)[_Size], wchar_t _Source, mbstate_t* _State) throw() { return wcrtomb_s(_Retval, _Dest, _Size, _Source, _State); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcrtomb_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) size_t __cdecl wcrtomb(char *_Dest, wchar_t _Source, mbstate_t* _State);

	__declspec(dllimport) errno_t __cdecl wcsrtombs_s(
		size_t*         _Retval,
		char*           _Dst,
		size_t          _SizeInBytes,
		wchar_t const** _Src,
		size_t          _Size,
		mbstate_t*      _State
	);

	extern "C++" { template <size_t _Size> inline   errno_t __cdecl wcsrtombs_s(size_t* _Retval, char(&_Dest)[_Size], wchar_t const** _PSrc, size_t _Count, mbstate_t* _State) throw() { return wcsrtombs_s(_Retval, _Dest, _Size, _PSrc, _Count, _State); } }

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcsrtombs_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details.")) __declspec(dllimport) size_t __cdecl wcsrtombs(char *_Dest, wchar_t const** _PSource, size_t _Count, mbstate_t* _State);

	__declspec(dllimport) int __cdecl wctob(
		wint_t _WCh
	);

	errno_t __cdecl wmemcpy_s(
		wchar_t*       _S1,
		rsize_t        _N1,
		wchar_t const* _S2,
		rsize_t        _N
	);

	errno_t __cdecl wmemmove_s(
		wchar_t*       _S1,
		rsize_t        _N1,
		wchar_t const* _S2,
		rsize_t        _N
	);

	__inline int __cdecl fwide(
		FILE* _F,
		int   _M
	)
	{
		(void)_F;
		return (_M);
	}

	__inline int __cdecl mbsinit(
		mbstate_t const* _P
	)
	{
		return _P == 0 || _P->_Wchar == 0;
	}

	__inline wchar_t const* __cdecl wmemchr(
		wchar_t const* _S,
		wchar_t        _C,
		size_t         _N
	)
	{
		for (; 0 < _N; ++_S, --_N)
			if (*_S == _C)
				return (wchar_t const*)_S;

		return 0;
	}

	__inline int __cdecl wmemcmp(
		wchar_t const* _S1,
		wchar_t const* _S2,
		size_t         _N
	)
	{
		for (; 0 < _N; ++_S1, ++_S2, --_N)
			if (*_S1 != *_S2)
				return *_S1 < *_S2 ? -1 : 1;

		return 0;
	}

	__inline
		wchar_t* __cdecl wmemcpy(
			wchar_t*       _S1,
			wchar_t const* _S2,
			size_t         _N
		)
	{
#pragma warning(push)
#pragma warning(disable : 4995 4996 6386)
		return (wchar_t*)memcpy(_S1, _S2, _N * sizeof(wchar_t));
#pragma warning(pop)
	}

	__inline
		wchar_t* __cdecl wmemmove(
			wchar_t*       _S1,
			wchar_t const* _S2,
			size_t         _N
		)
	{
#pragma warning(push)
#pragma warning(disable : 4996 6386)
		return (wchar_t*)memmove(_S1, _S2, _N * sizeof(wchar_t));
#pragma warning(pop)
	}

	__inline wchar_t* __cdecl wmemset(
		wchar_t* _S,
		wchar_t  _C,
		size_t   _N
	)
	{
		wchar_t *_Su = _S;
		for (; 0 < _N; ++_Su, --_N)
		{
			*_Su = _C;
		}
		return _S;
	}

	extern "C++" inline wchar_t* __cdecl wmemchr(
		wchar_t* _S,
		wchar_t  _C,
		size_t   _N
	)
	{
		wchar_t const* const _SC = _S;
		return const_cast<wchar_t*>(wmemchr(_SC, _C, _N));
	}

} __pragma(pack(pop))

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

typedef mbstate_t _Mbstatet;

namespace std {
#pragma warning(push)
#pragma warning(disable: 4995) 

	using ::_Mbstatet;

	using ::mbstate_t; using ::size_t; using ::tm; using ::wint_t;

	using ::btowc; using ::fgetwc; using ::fgetws; using ::fputwc;
	using ::fputws; using ::fwide; using ::fwprintf;
	using ::fwscanf; using ::getwc; using ::getwchar;
	using ::mbrlen; using ::mbrtowc; using ::mbsrtowcs;
	using ::mbsinit; using ::putwc; using ::putwchar;
	using ::swprintf; using ::swscanf; using ::ungetwc;
	using ::vfwprintf; using ::vswprintf; using ::vwprintf;
	using ::wcrtomb; using ::wprintf; using ::wscanf;
	using ::wcsrtombs; using ::wcstol; using ::wcscat;
	using ::wcschr; using ::wcscmp; using ::wcscoll;
	using ::wcscpy; using ::wcscspn; using ::wcslen;
	using ::wcsncat; using ::wcsncmp; using ::wcsncpy;
	using ::wcspbrk; using ::wcsrchr; using ::wcsspn;
	using ::wcstod; using ::wcstoul; using ::wcsstr;
	using ::wcstok; using ::wcsxfrm; using ::wctob;
	using ::wmemchr; using ::wmemcmp; using ::wmemcpy;
	using ::wmemmove; using ::wmemset; using ::wcsftime;

	using ::vfwscanf; using ::vswscanf; using ::vwscanf;
	using ::wcstof; using ::wcstold;
	using ::wcstoll; using ::wcstoull;

#pragma warning(pop)
}

#pragma warning(pop)
#pragma pack(pop)

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {

	using streamoff = long long;
	using streamsize = long long;

	template<class _Statetype>
	class fpos
	{
	public:
		fpos(streamoff _Off = 0)
			: _Myoff(_Off), _Fpos(0), _Mystate()
		{
		}

		fpos(_Statetype _State, fpos_t _Fileposition)
			: _Myoff(_Fileposition), _Fpos(0), _Mystate(_State)
		{
		}

		_Statetype state() const
		{
			return (_Mystate);
		}

		void state(_Statetype _State)
		{
			_Mystate = _State;
		}

		operator streamoff() const
		{

			return (_Myoff + _Fpos);
		}

		[[deprecated("warning STL4019: " "The member std::fpos::seekpos() is non-Standard, and is preserved only for compatibility with " "workarounds for old versions of Visual C++. It will be removed in a future release, and in this " "release always returns 0. Please use standards-conforming mechanisms to manipulate fpos, such as " "conversions to and from streamoff, or an integral type, instead. If you are receiving this message " "while compiling Boost.IOStreams, a fix has been submitted upstream to make Boost use " "standards-conforming mechanisms, as it does for other compilers. You can define " "_SILENCE_FPOS_SEEKPOS_DEPRECATION_WARNING to acknowledge that you have received this warning, " "or define _REMOVE_FPOS_SEEKPOS to remove std::fpos::seekpos entirely.")]] fpos_t seekpos() const noexcept
		{
			return {};
		}

		streamoff operator-(const fpos& _Right) const
		{
			return (static_cast<streamoff>(*this) - static_cast<streamoff>(_Right));
		}

		fpos& operator+=(streamoff _Off)
		{
			_Myoff += _Off;
			return (*this);
		}

		fpos& operator-=(streamoff _Off)
		{
			_Myoff -= _Off;
			return (*this);
		}

		fpos operator+(streamoff _Off) const
		{
			fpos _Tmp = *this;
			_Tmp += _Off;
			return (_Tmp);
		}

		fpos operator-(streamoff _Off) const
		{
			fpos _Tmp = *this;
			_Tmp -= _Off;
			return (_Tmp);
		}

		bool operator==(const fpos& _Right) const
		{
			return (static_cast<streamoff>(*this) == static_cast<streamoff>(_Right));
		}

		template<class _Int,
			enable_if_t<is_integral_v<_Int>, int> = 0>
			friend bool operator==(const fpos& _Left, const _Int _Right)
		{
			return (static_cast<streamoff>(_Left) == _Right);
		}

		template<class _Int,
			enable_if_t<is_integral_v<_Int>, int> = 0>
			friend bool operator==(const _Int _Left, const fpos& _Right)
		{
			return (_Left == static_cast<streamoff>(_Right));
		}

		bool operator!=(const fpos& _Right) const
		{
			return (static_cast<streamoff>(*this) != static_cast<streamoff>(_Right));
		}

		template<class _Int,
			enable_if_t<is_integral_v<_Int>, int> = 0>
			friend bool operator!=(const fpos& _Left, const _Int _Right)
		{
			return (static_cast<streamoff>(_Left) != _Right);
		}

		template<class _Int,
			enable_if_t<is_integral_v<_Int>, int> = 0>
			friend bool operator!=(const _Int _Left, const fpos& _Right)
		{
			return (_Left != static_cast<streamoff>(_Right));
		}

	private:
		streamoff _Myoff;
		fpos_t _Fpos;
		_Statetype _Mystate;
	};

	using streampos = fpos<_Mbstatet>;
	using wstreampos = streampos;

	template<class _Elem,
		class _Int_type>
		struct _Char_traits
	{
		using char_type = _Elem;
		using int_type = _Int_type;
		using pos_type = streampos;
		using off_type = streamoff;
		using state_type = _Mbstatet;

		static inline int compare(const _Elem * _First1,
			const _Elem * _First2, size_t _Count) noexcept
		{
			for (; 0 < _Count; --_Count, ++_First1, ++_First2)
			{
				if (*_First1 != *_First2)
				{
					return (*_First1 < *_First2 ? -1 : +1);
				}
			}

			return (0);
		}

		static inline size_t length(const _Elem * _First) noexcept
		{
			size_t _Count = 0;
			while (*_First != _Elem())
			{
				++_Count;
				++_First;
			}

			return (_Count);
		}

		static _Elem * copy(_Elem * const _First1,
			const _Elem * _First2, size_t _Count) noexcept
		{
			return (static_cast<_Elem *>(::memcpy(_First1, _First2, _Count * sizeof(_Elem))));
		}

		static _Elem * _Copy_s(
			_Elem * const _First1, const size_t _Dest_size,
			const _Elem * const _First2, const size_t _Count) noexcept
		{
			do { if (_Count <= _Dest_size) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\iosfwd", 190, 0, "%s", "invalid argument")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"invalid argument\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\iosfwd", 190, 0); } while (false); }; } while (false);
			return (copy(_First1, _First2, _Count));
		}

		static inline const _Elem * find(const _Elem * _First,
			size_t _Count, const _Elem& _Ch) noexcept
		{
			for (; 0 < _Count; --_Count, ++_First)
			{
				if (*_First == _Ch)
				{
					return (_First);
				}
			}

			return (nullptr);
		}

		static _Elem * move(_Elem * const _First1,
			const _Elem * _First2, size_t _Count) noexcept
		{
			return (static_cast<_Elem *>(::memmove(_First1, _First2, _Count * sizeof(_Elem))));
		}

		static _Elem * assign(_Elem * const _First,
			size_t _Count, const _Elem _Ch) noexcept
		{
			_Elem * _Next = _First;
			for (; 0 < _Count; --_Count, ++_Next)
			{
				*_Next = _Ch;
			}

			return (_First);
		}

		static inline void assign(_Elem& _Left, const _Elem& _Right) noexcept
		{
			_Left = _Right;
		}

		static constexpr bool eq(const _Elem& _Left, const _Elem& _Right) noexcept
		{
			return (_Left == _Right);
		}

		static constexpr bool lt(const _Elem& _Left, const _Elem& _Right) noexcept
		{
			return (_Left < _Right);
		}

		static constexpr _Elem to_char_type(const int_type& _Meta) noexcept
		{
			return (static_cast<_Elem>(_Meta));
		}

		static constexpr int_type to_int_type(const _Elem& _Ch) noexcept
		{
			return (static_cast<int_type>(_Ch));
		}

		static constexpr bool eq_int_type(const int_type& _Left, const int_type& _Right) noexcept
		{
			return (_Left == _Right);
		}

		static constexpr int_type not_eof(const int_type& _Meta) noexcept
		{
			return (_Meta != eof() ? _Meta : !eof());
		}

		static constexpr int_type eof() noexcept
		{
			return (static_cast<int_type>((-1)));
		}
	};

	template<class _Elem>
	struct _WChar_traits
	{
		using char_type = _Elem;
		using int_type = unsigned short;
		using pos_type = streampos;
		using off_type = streamoff;
		using state_type = _Mbstatet;

		static inline int compare(const _Elem * const _First1,
			const _Elem * const _First2, const size_t _Count) noexcept
		{

			return (::wmemcmp(reinterpret_cast<const wchar_t *>(_First1),
				reinterpret_cast<const wchar_t *>(_First2), _Count));

		}

		static inline size_t length(const _Elem * _First) noexcept
		{

			return (::wcslen(reinterpret_cast<const wchar_t *>(_First)));

		}

		static _Elem * copy(_Elem * const _First1,
			const _Elem * const _First2, const size_t _Count) noexcept
		{
			return (reinterpret_cast<_Elem *>(::wmemcpy(reinterpret_cast<wchar_t *>(_First1),
				reinterpret_cast<const wchar_t *>(_First2), _Count)));
		}

		static _Elem * _Copy_s(
			_Elem * const _First1, const size_t _Size_in_words,
			const _Elem * const _First2, const size_t _Count) noexcept
		{
			do { if (_Count <= _Size_in_words) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\iosfwd", 322, 0, "%s", "invalid argument")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"invalid argument\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\iosfwd", 322, 0); } while (false); }; } while (false);
			return (copy(_First1, _First2, _Count));
		}

		static inline const _Elem * find(const _Elem * _First,
			const size_t _Count, const _Elem& _Ch) noexcept
		{

			return (reinterpret_cast<const _Elem *>(::wmemchr(
				reinterpret_cast<const wchar_t *>(_First), _Ch, _Count)));

		}

		static _Elem * move(_Elem * const _First1,
			const _Elem * const _First2, const size_t _Count) noexcept
		{
			return (reinterpret_cast<_Elem *>(::wmemmove(reinterpret_cast<wchar_t *>(_First1),
				reinterpret_cast<const wchar_t *>(_First2), _Count)));
		}

		static _Elem * assign(_Elem * const _First, size_t _Count, _Elem _Ch)
			noexcept
		{
			return (reinterpret_cast<_Elem *>(::wmemset(reinterpret_cast<wchar_t *>(_First), _Ch, _Count)));
		}

		static inline void assign(_Elem& _Left, const _Elem& _Right) noexcept
		{
			_Left = _Right;
		}

		static constexpr bool eq(const _Elem& _Left, const _Elem& _Right) noexcept
		{
			return (_Left == _Right);
		}

		static constexpr bool lt(const _Elem& _Left, const _Elem& _Right) noexcept
		{
			return (_Left < _Right);
		}

		static constexpr _Elem to_char_type(const int_type& _Meta) noexcept
		{
			return (_Meta);
		}

		static constexpr int_type to_int_type(const _Elem& _Ch) noexcept
		{
			return (_Ch);
		}

		static constexpr bool eq_int_type(const int_type& _Left, const int_type& _Right) noexcept
		{
			return (_Left == _Right);
		}

		static constexpr int_type not_eof(const int_type& _Meta) noexcept
		{
			return (_Meta != eof() ? _Meta : static_cast<int_type>(!eof()));
		}

		static constexpr int_type eof() noexcept
		{
			return (((wint_t)(0xFFFF)));
		}
	};

	template<class _Elem>
	struct char_traits
		: _Char_traits<_Elem, long>
	{
	};

	template<>
	struct char_traits<char16_t>
		: _WChar_traits<char16_t>
	{
	};

	using u16streampos = streampos;

	template<>
	struct char_traits<char32_t>
		: _Char_traits<char32_t, unsigned int>
	{
	};

	using u32streampos = streampos;

	template<>
	struct char_traits<wchar_t>
		: _WChar_traits<wchar_t>
	{
	};

	template<>
	struct char_traits<unsigned short>
		: _WChar_traits<unsigned short>
	{
	};

	template<>
	struct char_traits<char>
	{
		using char_type = char;
		using int_type = int;
		using pos_type = streampos;
		using off_type = streamoff;
		using state_type = _Mbstatet;

		static inline int compare(const char * const _First1,
			const char * const _First2, const size_t _Count) noexcept
		{

			return (::memcmp(_First1, _First2, _Count));

		}

		static inline size_t length(const char * const _First) noexcept
		{

			return (::strlen(_First));

		}

		static char * copy(char * const _First1,
			const char * const _First2, const size_t _Count) noexcept
		{
			return (static_cast<char *>(::memcpy(_First1, _First2, _Count)));
		}

		static char * _Copy_s(
			char * const _First1, const size_t _Size_in_bytes,
			const char * const _First2, const size_t _Count) noexcept
		{
			do { if (_Count <= _Size_in_bytes) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\iosfwd", 478, 0, "%s", "invalid argument")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"invalid argument\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\iosfwd", 478, 0); } while (false); }; } while (false);
			return (copy(_First1, _First2, _Count));
		}

		static inline const char * find(const char * const _First,
			const size_t _Count, const char& _Ch) noexcept
		{

			return (static_cast<const char *>(::memchr(_First, _Ch, _Count)));

		}

		static char * move(char * const _First1,
			const char * const _First2, const size_t _Count) noexcept
		{
			return (static_cast<char *>(::memmove(_First1, _First2, _Count)));
		}

		static char * assign(char * const _First,
			const size_t _Count, const char _Ch) noexcept
		{
			return (static_cast<char *>(::memset(_First, _Ch, _Count)));
		}

		static inline void assign(char& _Left, const char& _Right) noexcept
		{
			_Left = _Right;
		}

		static constexpr bool eq(const char& _Left, const char& _Right) noexcept
		{
			return (_Left == _Right);
		}

		static constexpr bool lt(const char& _Left, const char& _Right) noexcept
		{
			return (static_cast<unsigned char>(_Left) < static_cast<unsigned char>(_Right));
		}

		static constexpr char to_char_type(const int_type& _Meta) noexcept
		{
			return (static_cast<char>(_Meta));
		}

		static constexpr int_type to_int_type(const char& _Ch) noexcept
		{
			return (static_cast<unsigned char>(_Ch));
		}

		static constexpr bool eq_int_type(const int_type& _Left, const int_type& _Right) noexcept
		{
			return (_Left == _Right);
		}

		static constexpr int_type not_eof(const int_type& _Meta) noexcept
		{
			return (_Meta != eof() ? _Meta : !eof());
		}

		static constexpr int_type eof() noexcept
		{
			return ((-1));
		}
	};

	template<class _Ty>
	class allocator;
	class ios_base;
	template<class _Elem,
		class _Traits = char_traits<_Elem>>
		class basic_ios;
	template<class _Elem,
		class _Traits = char_traits<_Elem>>
		class istreambuf_iterator;
	template<class _Elem,
		class _Traits = char_traits<_Elem>>
		class ostreambuf_iterator;
	template<class _Elem,
		class _Traits = char_traits<_Elem>>
		class basic_streambuf;

#pragma vtordisp(push, 2)	
	template<class _Elem,
		class _Traits = char_traits<_Elem>>
		class basic_istream;
	template<class _Elem,
		class _Traits = char_traits<_Elem>>
		class basic_ostream;
#pragma vtordisp(pop)	

	template<class _Elem,
		class _Traits = char_traits<_Elem>>
		class basic_iostream;
	template<class _Elem,
		class _Traits = char_traits<_Elem>,
		class _Alloc = allocator<_Elem>>
		class basic_stringbuf;
	template<class _Elem,
		class _Traits = char_traits<_Elem>,
		class _Alloc = allocator<_Elem>>
		class basic_istringstream;
	template<class _Elem,
		class _Traits = char_traits<_Elem>,
		class _Alloc = allocator<_Elem>>
		class basic_ostringstream;
	template<class _Elem,
		class _Traits = char_traits<_Elem>,
		class _Alloc = allocator<_Elem>>
		class basic_stringstream;
	template<class _Elem,
		class _Traits = char_traits<_Elem>>
		class basic_filebuf;
	template<class _Elem,
		class _Traits = char_traits<_Elem>>
		class basic_ifstream;
	template<class _Elem,
		class _Traits = char_traits<_Elem>>
		class basic_ofstream;
	template<class _Elem,
		class _Traits = char_traits<_Elem>>
		class basic_fstream;

	template<class _Elem,
		class _InIt >
		class num_get;
	template<class _Elem,
		class _OutIt >
		class num_put;
	template<class _Elem>
	class collate;

	using ios = basic_ios<char, char_traits<char>>;
	using streambuf = basic_streambuf<char, char_traits<char>>;
	using istream = basic_istream<char, char_traits<char>>;
	using ostream = basic_ostream<char, char_traits<char>>;
	using iostream = basic_iostream<char, char_traits<char>>;
	using stringbuf = basic_stringbuf<char, char_traits<char>, allocator<char>>;
	using istringstream = basic_istringstream<char, char_traits<char>, allocator<char>>;
	using ostringstream = basic_ostringstream<char, char_traits<char>, allocator<char>>;
	using stringstream = basic_stringstream<char, char_traits<char>, allocator<char>>;
	using filebuf = basic_filebuf<char, char_traits<char>>;
	using ifstream = basic_ifstream<char, char_traits<char>>;
	using ofstream = basic_ofstream<char, char_traits<char>>;
	using fstream = basic_fstream<char, char_traits<char>>;

	using wios = basic_ios<wchar_t, char_traits<wchar_t>>;
	using wstreambuf = basic_streambuf<wchar_t, char_traits<wchar_t>>;
	using wistream = basic_istream<wchar_t, char_traits<wchar_t>>;
	using wostream = basic_ostream<wchar_t, char_traits<wchar_t>>;
	using wiostream = basic_iostream<wchar_t, char_traits<wchar_t>>;
	using wstringbuf = basic_stringbuf<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>;
	using wistringstream = basic_istringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>;
	using wostringstream = basic_ostringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>;
	using wstringstream = basic_stringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>;
	using wfilebuf = basic_filebuf<wchar_t, char_traits<wchar_t>>;
	using wifstream = basic_ifstream<wchar_t, char_traits<wchar_t>>;
	using wofstream = basic_ofstream<wchar_t, char_traits<wchar_t>>;
	using wfstream = basic_fstream<wchar_t, char_traits<wchar_t>>;

}

#pragma warning(pop)
#pragma pack(pop)

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {

	template<class _Ty>

	constexpr const _Ty& _Min_value(const _Ty& _Left, const _Ty& _Right)
		noexcept(noexcept(_Right < _Left))
	{
		return (_Right < _Left ? _Right : _Left);
	}

	template<class _Ty>

	constexpr const _Ty& _Max_value(const _Ty& _Left, const _Ty& _Right)
		noexcept(noexcept(_Left < _Right))
	{
		return (_Left < _Right ? _Right : _Left);
	}

	template<class _FwdIt1,
		class _FwdIt2> inline
		void iter_swap(_FwdIt1 _Left, _FwdIt2 _Right)
	{
		swap(*_Left, *_Right);
	}

	template<class _Ty,
		size_t _Size,
		class> inline
		void swap(_Ty(&_Left)[_Size], _Ty(&_Right)[_Size])
		noexcept(_Is_nothrow_swappable<_Ty>::value)
	{
		if (&_Left != &_Right)
		{
			_Ty *_First1 = _Left;
			_Ty *_Last1 = _First1 + _Size;
			_Ty *_First2 = _Right;
			for (; _First1 != _Last1; ++_First1, ++_First2)
				::std::iter_swap(_First1, _First2);
		}
	}

	template<class _Ty,
		class> inline
		void swap(_Ty& _Left, _Ty& _Right)
		noexcept(is_nothrow_move_constructible_v<_Ty> && is_nothrow_move_assignable_v<_Ty>)

	{
		_Ty _Tmp = ::std::move(_Left);
		_Left = ::std::move(_Right);
		_Right = ::std::move(_Tmp);
	}

	template<class _Ty> inline
		void _Swap_adl(_Ty& _Left, _Ty& _Right)
		noexcept(_Is_nothrow_swappable<_Ty>::value)
	{
		swap(_Left, _Right);
	}

	struct piecewise_construct_t
	{
		explicit piecewise_construct_t() = default;
	};

	constexpr piecewise_construct_t piecewise_construct{};

	template<class...>
	class tuple;

	template<class _Ty1,
		class _Ty2>
		struct pair
	{
		using first_type = _Ty1;
		using second_type = _Ty2;

		template<class _Uty1 = _Ty1,
			class _Uty2 = _Ty2,
			enable_if_t<conjunction_v<
			is_default_constructible<_Uty1>,
			is_default_constructible<_Uty2>,
			_Is_implicitly_default_constructible<_Uty1>,
			_Is_implicitly_default_constructible<_Uty2>
		>, int> = 0>
			constexpr pair()
			noexcept(is_nothrow_default_constructible_v<_Uty1> && is_nothrow_default_constructible_v<_Uty2>)

			: first(), second()
		{
		}

		template<class _Uty1 = _Ty1,
			class _Uty2 = _Ty2,
			enable_if_t<conjunction_v<
			is_default_constructible<_Uty1>,
			is_default_constructible<_Uty2>,
			negation<conjunction<
			_Is_implicitly_default_constructible<_Uty1>,
			_Is_implicitly_default_constructible<_Uty2>>>
			>, int> = 0>
			constexpr explicit pair()
			noexcept(is_nothrow_default_constructible_v<_Uty1> && is_nothrow_default_constructible_v<_Uty2>)

			: first(), second()
		{
		}

		template<class _Uty1 = _Ty1,
			class _Uty2 = _Ty2,
			enable_if_t<conjunction_v<
			is_copy_constructible<_Uty1>,
			is_copy_constructible<_Uty2>,
			is_convertible<const _Uty1&, _Uty1>,
			is_convertible<const _Uty2&, _Uty2>
		>, int> = 0>
			constexpr pair(const _Ty1& _Val1, const _Ty2& _Val2)
			noexcept(is_nothrow_copy_constructible_v<_Uty1> && is_nothrow_copy_constructible_v<_Uty2>)

			: first(_Val1), second(_Val2)
		{
		}

		template<class _Uty1 = _Ty1,
			class _Uty2 = _Ty2,
			enable_if_t<conjunction_v<
			is_copy_constructible<_Uty1>,
			is_copy_constructible<_Uty2>,
			negation<conjunction<
			is_convertible<const _Uty1&, _Uty1>,
			is_convertible<const _Uty2&, _Uty2>>>
			>, int> = 0>
			constexpr explicit pair(const _Ty1& _Val1, const _Ty2& _Val2)
			noexcept(is_nothrow_copy_constructible_v<_Uty1> && is_nothrow_copy_constructible_v<_Uty2>)

			: first(_Val1), second(_Val2)
		{
		}

		template<class _Other1,
			class _Other2,
			enable_if_t<conjunction_v<
			is_constructible<_Ty1, _Other1>,
			is_constructible<_Ty2, _Other2>,
			is_convertible<_Other1, _Ty1>,
			is_convertible<_Other2, _Ty2>
		>, int> = 0>
			constexpr pair(_Other1&& _Val1, _Other2&& _Val2)
			noexcept(is_nothrow_constructible_v<_Ty1, _Other1> && is_nothrow_constructible_v<_Ty2, _Other2>)

			: first(::std::forward<_Other1>(_Val1)),
			second(::std::forward<_Other2>(_Val2))
		{
		}

		template<class _Other1,
			class _Other2,
			enable_if_t<conjunction_v<
			is_constructible<_Ty1, _Other1>,
			is_constructible<_Ty2, _Other2>,
			negation<conjunction<
			is_convertible<_Other1, _Ty1>,
			is_convertible<_Other2, _Ty2>>>
			>, int> = 0>
			constexpr explicit pair(_Other1&& _Val1, _Other2&& _Val2)
			noexcept(is_nothrow_constructible_v<_Ty1, _Other1> && is_nothrow_constructible_v<_Ty2, _Other2>)

			: first(::std::forward<_Other1>(_Val1)),
			second(::std::forward<_Other2>(_Val2))
		{
		}

		pair(const pair&) = default;
		pair(pair&&) = default;

		template<class _Other1,
			class _Other2,
			enable_if_t<conjunction_v<
			is_constructible<_Ty1, const _Other1&>,
			is_constructible<_Ty2, const _Other2&>,
			is_convertible<const _Other1&, _Ty1>,
			is_convertible<const _Other2&, _Ty2>
		>, int> = 0>
			constexpr pair(const pair<_Other1, _Other2>& _Right)
			noexcept(is_nothrow_constructible_v<_Ty1, const _Other1&> && is_nothrow_constructible_v<_Ty2, const _Other2&>)

			: first(_Right.first), second(_Right.second)
		{
		}

		template<class _Other1,
			class _Other2,
			enable_if_t<conjunction_v<
			is_constructible<_Ty1, const _Other1&>,
			is_constructible<_Ty2, const _Other2&>,
			negation<conjunction<
			is_convertible<const _Other1&, _Ty1>,
			is_convertible<const _Other2&, _Ty2>>>
			>, int> = 0>
			constexpr explicit pair(const pair<_Other1, _Other2>& _Right)
			noexcept(is_nothrow_constructible_v<_Ty1, const _Other1&> && is_nothrow_constructible_v<_Ty2, const _Other2&>)

			: first(_Right.first), second(_Right.second)
		{
		}

		template<class _Other1,
			class _Other2,
			enable_if_t<conjunction_v<
			is_constructible<_Ty1, _Other1>,
			is_constructible<_Ty2, _Other2>,
			is_convertible<_Other1, _Ty1>,
			is_convertible<_Other2, _Ty2>
		>, int> = 0>
			constexpr pair(pair<_Other1, _Other2>&& _Right)
			noexcept(is_nothrow_constructible_v<_Ty1, _Other1> && is_nothrow_constructible_v<_Ty2, _Other2>)

			: first(::std::forward<_Other1>(_Right.first)),
			second(::std::forward<_Other2>(_Right.second))
		{
		}

		template<class _Other1,
			class _Other2,
			enable_if_t<conjunction_v<
			is_constructible<_Ty1, _Other1>,
			is_constructible<_Ty2, _Other2>,
			negation<conjunction<
			is_convertible<_Other1, _Ty1>,
			is_convertible<_Other2, _Ty2>>>
			>, int> = 0>
			constexpr explicit pair(pair<_Other1, _Other2>&& _Right)
			noexcept(is_nothrow_constructible_v<_Ty1, _Other1> && is_nothrow_constructible_v<_Ty2, _Other2>)

			: first(::std::forward<_Other1>(_Right.first)),
			second(::std::forward<_Other2>(_Right.second))
		{
		}

		template<class _Tuple1,
			class _Tuple2,
			size_t... _Indexes1,
			size_t... _Indexes2> inline
			pair(_Tuple1& _Val1,
				_Tuple2& _Val2,
				index_sequence<_Indexes1...>,
				index_sequence<_Indexes2...>);

		template<class... _Types1,
			class... _Types2> inline
			pair(piecewise_construct_t,
				tuple<_Types1...> _Val1,
				tuple<_Types2...> _Val2);

		pair& operator=(const volatile pair&) = delete;

		template<class _Other1 = _Ty1,
			class _Other2 = _Ty2,
			enable_if_t<conjunction_v<
			is_assignable<_Ty1&, const _Other1&>,
			is_assignable<_Ty2&, const _Other2&>
		>, int> = 0>
			pair& operator=(const pair<_Other1, _Other2>& _Right)
			noexcept(is_nothrow_assignable_v<_Ty1&, const _Other1&> && is_nothrow_assignable_v<_Ty2&, const _Other2&>)

		{
			first = _Right.first;
			second = _Right.second;
			return (*this);
		}

		template<class _Other1 = _Ty1,
			class _Other2 = _Ty2,
			enable_if_t<conjunction_v<
			is_assignable<_Ty1&, _Other1>,
			is_assignable<_Ty2&, _Other2>
		>, int> = 0>
			pair& operator=(pair<_Other1, _Other2>&& _Right)
			noexcept(is_nothrow_assignable_v<_Ty1&, _Other1> && is_nothrow_assignable_v<_Ty2&, _Other2>)

		{
			first = ::std::forward<_Other1>(_Right.first);
			second = ::std::forward<_Other2>(_Right.second);
			return (*this);
		}

		void swap(pair& _Right)
			noexcept(_Is_nothrow_swappable<_Ty1>::value && _Is_nothrow_swappable<_Ty2>::value)

		{
			if (this != ::std::addressof(_Right))
			{
				_Swap_adl(first, _Right.first);
				_Swap_adl(second, _Right.second);
			}
		}

		_Ty1 first;
		_Ty2 second;
	};

	template<class _Ty1,
		class _Ty2,
		class = enable_if_t<_Is_swappable<_Ty1>::value && _Is_swappable<_Ty2>::value>> inline
		void swap(pair<_Ty1, _Ty2>& _Left, pair<_Ty1, _Ty2>& _Right)
		noexcept(noexcept(_Left.swap(_Right)))
	{
		_Left.swap(_Right);
	}

	template<class _Ty1,
		class _Ty2>
		constexpr bool operator==(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right)
	{
		return (_Left.first == _Right.first && _Left.second == _Right.second);
	}

	template<class _Ty1,
		class _Ty2>
		constexpr bool operator!=(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right)
	{
		return (!(_Left == _Right));
	}

	template<class _Ty1,
		class _Ty2>
		constexpr bool operator<(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right)
	{
		return (_Left.first < _Right.first ||
			(!(_Right.first < _Left.first) && _Left.second < _Right.second));
	}

	template<class _Ty1,
		class _Ty2>
		constexpr bool operator>(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right)
	{
		return (_Right < _Left);
	}

	template<class _Ty1,
		class _Ty2>
		constexpr bool operator<=(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right)
	{
		return (!(_Right < _Left));
	}

	template<class _Ty1,
		class _Ty2>
		constexpr bool operator>=(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right)
	{
		return (!(_Left < _Right));
	}

	template<class _Ty>
	struct _Unrefwrap_helper
	{
		using type = _Ty;
	};

	template<class _Ty>
	struct _Unrefwrap_helper<reference_wrapper<_Ty>>
	{
		using type = _Ty & ;
	};

	template<class _Ty>
	using _Unrefwrap_t = typename _Unrefwrap_helper<decay_t<_Ty>>::type;

	template<class _Ty1,
		class _Ty2>
		constexpr pair<_Unrefwrap_t<_Ty1>, _Unrefwrap_t<_Ty2>>
		make_pair(_Ty1&& _Val1, _Ty2&& _Val2)
	{
		using _Mypair = pair<_Unrefwrap_t<_Ty1>, _Unrefwrap_t<_Ty2>>;
		return (_Mypair(::std::forward<_Ty1>(_Val1), ::std::forward<_Ty2>(_Val2)));
	}

	namespace rel_ops
	{
		template<class _Ty>
		inline bool operator!=(const _Ty& _Left, const _Ty& _Right)
		{
			return (!(_Left == _Right));
		}

		template<class _Ty>
		inline bool operator>(const _Ty& _Left, const _Ty& _Right)
		{
			return (_Right < _Left);
		}

		template<class _Ty>
		inline bool operator<=(const _Ty& _Left, const _Ty& _Right)
		{
			return (!(_Right < _Left));
		}

		template<class _Ty>
		inline bool operator>=(const _Ty& _Left, const _Ty& _Right)
		{
			return (!(_Left < _Right));
		}
	}
}

namespace std {

	template<class _Tuple>
	struct tuple_size;

	template<class _Tuple,
		class = void>
		struct _Tuple_size_sfinae
	{
	};

	template<class _Tuple>
	struct _Tuple_size_sfinae<_Tuple, void_t<decltype(tuple_size<_Tuple>::value)>>
		: integral_constant<size_t, tuple_size<_Tuple>::value>
	{
	};

	template<class _Tuple>
	struct tuple_size<const _Tuple>
		: _Tuple_size_sfinae<_Tuple>
	{
	};

	template<class _Tuple>
	struct tuple_size<volatile _Tuple>
		: _Tuple_size_sfinae<_Tuple>
	{
	};

	template<class _Tuple>
	struct tuple_size<const volatile _Tuple>
		: _Tuple_size_sfinae<_Tuple>
	{
	};

	template<class _Ty>
	constexpr size_t tuple_size_v = tuple_size<_Ty>::value;

	template<size_t _Index,
		class _Tuple>
		struct tuple_element;

	template<size_t _Index,
		class _Tuple>
		struct tuple_element<_Index, const _Tuple>
		: public tuple_element<_Index, _Tuple>
	{
		using _Mybase = tuple_element<_Index, _Tuple>;
		using type = add_const_t<typename _Mybase::type>;
	};

	template<size_t _Index,
		class _Tuple>
		struct tuple_element<_Index, volatile _Tuple>
		: public tuple_element<_Index, _Tuple>
	{
		using _Mybase = tuple_element<_Index, _Tuple>;
		using type = add_volatile_t<typename _Mybase::type>;
	};

	template<size_t _Index,
		class _Tuple>
		struct tuple_element<_Index, const volatile _Tuple>
		: public tuple_element<_Index, _Tuple>
	{
		using _Mybase = tuple_element<_Index, _Tuple>;
		using type = add_cv_t<typename _Mybase::type>;
	};

	template<size_t _Index,
		class _Tuple>
		using tuple_element_t = typename tuple_element<_Index, _Tuple>::type;

	template<class _Ty,
		size_t _Size>
		class array;

	template<class _Ty,
		size_t _Size>
		struct tuple_size<array<_Ty, _Size> >
		: integral_constant<size_t, _Size>
	{
	};

	template<size_t _Idx,
		class _Ty,
		size_t _Size>
		struct tuple_element<_Idx, array<_Ty, _Size>>
	{
		static_assert(_Idx < _Size, "array index out of bounds");

		using type = _Ty;
	};

	template<class... _Types>
	struct tuple_size<tuple<_Types...>>
		: integral_constant<size_t, sizeof...(_Types)>
	{
	};

	template<size_t _Index>
	struct tuple_element<_Index, tuple<>>
	{
		static_assert(_Always_false<integral_constant<size_t, _Index>>,
			"tuple index out of bounds");
	};

	template<class _This,
		class... _Rest>
		struct tuple_element<0, tuple<_This, _Rest...>>
	{
		using type = _This;
		using _Ttype = tuple<_This, _Rest...>;
	};

	template<size_t _Index,
		class _This,
		class... _Rest>
		struct tuple_element<_Index, tuple<_This, _Rest...>>
		: public tuple_element<_Index - 1, tuple<_Rest...>>
	{
	};

	template<class _Ty1,
		class _Ty2>
		struct tuple_size<pair<_Ty1, _Ty2>>
		: integral_constant<size_t, 2>
	{
	};

	template<size_t _Idx,
		class _Ty1,
		class _Ty2>
		struct tuple_element<_Idx, pair<_Ty1, _Ty2>>
	{
		static_assert(_Idx < 2, "pair index out of bounds");

		using type = conditional_t<_Idx == 0, _Ty1, _Ty2>;
	};

	template<class _Ret,
		class _Pair>
		constexpr _Ret _Pair_get(_Pair& _Pr,
			integral_constant<size_t, 0>) noexcept
	{
		return (_Pr.first);
	}

	template<class _Ret,
		class _Pair>
		constexpr _Ret _Pair_get(_Pair& _Pr,
			integral_constant<size_t, 1>) noexcept
	{
		return (_Pr.second);
	}

	template<size_t _Idx,
		class _Ty1,
		class _Ty2>
		constexpr tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&
		get(pair<_Ty1, _Ty2>& _Pr) noexcept
	{
		using _Rtype = tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&;
		return (_Pair_get<_Rtype>(_Pr, integral_constant<size_t, _Idx>()));
	}

	template<class _Ty1,
		class _Ty2>
		constexpr _Ty1& get(pair<_Ty1, _Ty2>& _Pr) noexcept
	{
		return (::std::get<0>(_Pr));
	}

	template<class _Ty2,
		class _Ty1>
		constexpr _Ty2& get(pair<_Ty1, _Ty2>& _Pr) noexcept
	{
		return (::std::get<1>(_Pr));
	}

	template<size_t _Idx,
		class _Ty1,
		class _Ty2>
		constexpr const tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&
		get(const pair<_Ty1, _Ty2>& _Pr) noexcept
	{
		using _Ctype = const tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&;
		return (_Pair_get<_Ctype>(_Pr, integral_constant<size_t, _Idx>()));
	}

	template<class _Ty1,
		class _Ty2>
		constexpr const _Ty1& get(const pair<_Ty1, _Ty2>& _Pr) noexcept
	{
		return (::std::get<0>(_Pr));
	}

	template<class _Ty2,
		class _Ty1>
		constexpr const _Ty2& get(const pair<_Ty1, _Ty2>& _Pr) noexcept
	{
		return (::std::get<1>(_Pr));
	}

	template<size_t _Idx,
		class _Ty1,
		class _Ty2>
		constexpr tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&&
		get(pair<_Ty1, _Ty2>&& _Pr) noexcept
	{
		using _RRtype = tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&&;
		return (::std::forward<_RRtype>(::std::get<_Idx>(_Pr)));
	}

	template<class _Ty1,
		class _Ty2>
		constexpr _Ty1&& get(pair<_Ty1, _Ty2>&& _Pr) noexcept
	{
		return (::std::get<0>(::std::move(_Pr)));
	}

	template<class _Ty2,
		class _Ty1>
		constexpr _Ty2&& get(pair<_Ty1, _Ty2>&& _Pr) noexcept
	{
		return (::std::get<1>(::std::move(_Pr)));
	}

	template<size_t _Idx,
		class _Ty1,
		class _Ty2>
		constexpr const tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&&
		get(const pair<_Ty1, _Ty2>&& _Pr) noexcept
	{
		using _RRtype = const tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&&;
		return (::std::forward<_RRtype>(::std::get<_Idx>(_Pr)));
	}

	template<class _Ty1,
		class _Ty2>
		constexpr const _Ty1&& get(const pair<_Ty1, _Ty2>&& _Pr) noexcept
	{
		return (::std::get<0>(::std::move(_Pr)));
	}

	template<class _Ty2,
		class _Ty1>
		constexpr const _Ty2&& get(const pair<_Ty1, _Ty2>&& _Pr) noexcept
	{
		return (::std::get<1>(::std::move(_Pr)));
	}

	template<class _Ty,
		class _Other = _Ty> inline
		_Ty exchange(_Ty& _Val, _Other&& _New_val)
	{
		_Ty _Old_val = ::std::move(_Val);
		_Val = ::std::forward<_Other>(_New_val);
		return (_Old_val);
	}

	template<class _Ty>
	constexpr add_const_t<_Ty>& as_const(_Ty& _Val) noexcept
	{
		return (_Val);
	}

	template<class _Ty>
	void as_const(const _Ty&&) = delete;

	namespace[[deprecated("warning STL4002: " "The non-Standard std::tr1 namespace and TR1-only machinery are deprecated and will be REMOVED. You can " "define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING to acknowledge that you have received this warning.")]] tr1{
	using ::std::get;
	using ::std::tuple_element;
	using ::std::tuple_size;
	}

}

#pragma warning(pop)
#pragma pack(pop)

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

extern "C" {

	__declspec(noalias) void __cdecl __std_reverse_trivially_swappable_1(void * _First, void * _Last) noexcept;
	__declspec(noalias) void __cdecl __std_reverse_trivially_swappable_2(void * _First, void * _Last) noexcept;
	__declspec(noalias) void __cdecl __std_reverse_trivially_swappable_4(void * _First, void * _Last) noexcept;
	__declspec(noalias) void __cdecl __std_reverse_trivially_swappable_8(void * _First, void * _Last) noexcept;
}

namespace std {

	struct _Container_proxy;
	struct _Container_base12;
	struct _Iterator_base12;

	struct _Container_base0
	{
		void _Orphan_all() noexcept
		{
		}

		void _Swap_all(_Container_base0&) noexcept
		{
		}
	};

	struct _Iterator_base0
	{
		void _Adopt(const void *) noexcept
		{
		}

		const _Container_base0 *_Getcont() const noexcept
		{
			return (nullptr);
		}

		static constexpr bool _Unwrap_when_unverified = true;
	};

	struct _Container_proxy
	{
		_Container_proxy() noexcept
			: _Mycont(nullptr), _Myfirstiter(nullptr)
		{
		}

		const _Container_base12 *_Mycont;
		_Iterator_base12 *_Myfirstiter;
	};

	struct _Container_base12
	{
	public:
		_Container_base12()
			: _Myproxy(nullptr)
		{
		}

		_Container_base12(const _Container_base12&) noexcept
			: _Myproxy(nullptr)
		{
		}

		_Container_base12& operator=(const _Container_base12&) noexcept
		{
			return (*this);
		}

		_Iterator_base12 **_Getpfirst() const noexcept
		{
			return (_Myproxy == nullptr ? nullptr : &_Myproxy->_Myfirstiter);
		}

		void _Orphan_all() noexcept;
		void _Swap_all(_Container_base12&) noexcept;

		_Container_proxy *_Myproxy;
	};

	struct _Iterator_base12
	{
		_Iterator_base12() noexcept
			: _Myproxy(nullptr), _Mynextiter(nullptr)
		{
		}

		_Iterator_base12(const _Iterator_base12& _Right) noexcept
			: _Myproxy(nullptr), _Mynextiter(nullptr)
		{
			*this = _Right;
		}

		_Iterator_base12& operator=(const _Iterator_base12& _Right) noexcept
		{
			if (_Myproxy != _Right._Myproxy)
			{
				if (_Right._Myproxy == nullptr)
				{

					_Lockit _Lock(3);
					_Orphan_me();

				}
				else
				{
					_Adopt(_Right._Myproxy->_Mycont);
				}
			}

			return (*this);
		}

		~_Iterator_base12() noexcept
		{

			_Lockit _Lock(3);
			_Orphan_me();

		}

		void _Adopt(const _Container_base12 *_Parent) noexcept
		{
			if (_Parent == nullptr)
			{

				_Lockit _Lock(3);
				_Orphan_me();

			}
			else
			{
				_Container_proxy *_Parent_proxy = _Parent->_Myproxy;

				if (_Myproxy != _Parent_proxy)
				{
					_Lockit _Lock(3);
					_Orphan_me();
					_Mynextiter = _Parent_proxy->_Myfirstiter;
					_Parent_proxy->_Myfirstiter = this;
					_Myproxy = _Parent_proxy;
				}

			}
		}

		void _Clrcont() noexcept
		{
			_Myproxy = nullptr;
		}

		const _Container_base12 *_Getcont() const noexcept
		{
			return (_Myproxy == nullptr ? nullptr : _Myproxy->_Mycont);
		}

		_Iterator_base12 **_Getpnext() noexcept
		{
			return (&_Mynextiter);
		}

		void _Orphan_me() noexcept
		{

			if (_Myproxy != nullptr)
			{
				_Iterator_base12 **_Pnext = &_Myproxy->_Myfirstiter;
				while (*_Pnext != nullptr && *_Pnext != this)
					_Pnext = &(*_Pnext)->_Mynextiter;

				do { if (*_Pnext) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 199, 0, "%s", "ITERATOR LIST CORRUPTED!")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"ITERATOR LIST CORRUPTED!\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 199, 0); } while (false); }; } while (false);
				*_Pnext = _Mynextiter;
				_Myproxy = nullptr;
			}

		}

		static constexpr bool _Unwrap_when_unverified = 2 == 0;

		_Container_proxy *_Myproxy;
		_Iterator_base12 *_Mynextiter;
	};

	inline void _Container_base12::_Orphan_all() noexcept
	{

		if (_Myproxy != nullptr)
		{
			_Lockit _Lock(3);

			for (_Iterator_base12 **_Pnext = &_Myproxy->_Myfirstiter;
				*_Pnext != nullptr; *_Pnext = (*_Pnext)->_Mynextiter)
				(*_Pnext)->_Myproxy = nullptr;
			_Myproxy->_Myfirstiter = nullptr;
		}

	}

	inline void _Container_base12::_Swap_all(_Container_base12& _Right) noexcept
	{

		_Lockit _Lock(3);

		_Container_proxy *_Temp = _Myproxy;
		_Myproxy = _Right._Myproxy;
		_Right._Myproxy = _Temp;

		if (_Myproxy != nullptr)
			_Myproxy->_Mycont = (_Container_base12 *)this;
		if (_Right._Myproxy != nullptr)
			_Right._Myproxy->_Mycont = (_Container_base12 *)&_Right;
	}

	using _Container_base = _Container_base12;
	using _Iterator_base = _Iterator_base12;

	struct _Zero_then_variadic_args_t
	{
	};

	struct _One_then_variadic_args_t
	{
	};

	template<class _Ty1,
		class _Ty2,
		bool = is_empty_v<_Ty1> && !is_final_v<_Ty1>>
		class _Compressed_pair final
		: private _Ty1
	{
	private:
		_Ty2 _Myval2;

		using _Mybase = _Ty1;

	public:
		template<class... _Other2>
		constexpr explicit _Compressed_pair(_Zero_then_variadic_args_t,
			_Other2&&... _Val2)
			: _Ty1(), _Myval2(::std::forward<_Other2>(_Val2)...)
		{
		}

		template<class _Other1,
			class... _Other2>
			_Compressed_pair(_One_then_variadic_args_t,
				_Other1&& _Val1, _Other2&&... _Val2)
			: _Ty1(::std::forward<_Other1>(_Val1)),
			_Myval2(::std::forward<_Other2>(_Val2)...)
		{
		}

		_Ty1& _Get_first() noexcept
		{
			return (*this);
		}

		const _Ty1& _Get_first() const noexcept
		{
			return (*this);
		}

		_Ty2& _Get_second() noexcept
		{
			return (_Myval2);
		}

		const _Ty2& _Get_second() const noexcept
		{
			return (_Myval2);
		}
	};

	template<class _Ty1,
		class _Ty2>
		class _Compressed_pair<_Ty1, _Ty2, false> final
	{
	private:
		_Ty1 _Myval1;
		_Ty2 _Myval2;

	public:
		template<class... _Other2>
		constexpr explicit _Compressed_pair(_Zero_then_variadic_args_t,
			_Other2&&... _Val2)
			: _Myval1(), _Myval2(::std::forward<_Other2>(_Val2)...)
		{
		}

		template<class _Other1,
			class... _Other2>
			_Compressed_pair(_One_then_variadic_args_t,
				_Other1&& _Val1, _Other2&&... _Val2)
			: _Myval1(::std::forward<_Other1>(_Val1)),
			_Myval2(::std::forward<_Other2>(_Val2)...)
		{
		}

		_Ty1& _Get_first() noexcept
		{
			return (_Myval1);
		}

		const _Ty1& _Get_first() const noexcept
		{
			return (_Myval1);
		}

		_Ty2& _Get_second() noexcept
		{
			return (_Myval2);
		}

		const _Ty2& _Get_second() const noexcept
		{
			return (_Myval2);
		}
	};

	template<class _Fx>
	struct _Ref_fn
	{
		template<class... _Args>
		constexpr decltype(auto) operator()(_Args&&... _Vals)
		{
			return (_Fn(::std::forward<_Args>(_Vals)...));
		}

		_Fx& _Fn;
	};

	template<class _Fn>
	constexpr bool _Pass_functor_by_value_v = sizeof(_Fn) <= sizeof(void *)
		&& conjunction_v<
		is_trivially_copy_constructible<_Fn>,
		is_trivially_destructible<_Fn>>;

	template<class _Fn,
		enable_if_t<_Pass_functor_by_value_v<_Fn>, int> = 0>
		constexpr _Fn _Pass_fn(_Fn _Val)
	{
		return (_Val);
	}

	template<class _Fn,
		enable_if_t<!_Pass_functor_by_value_v<_Fn>, int> = 0>
		constexpr _Ref_fn<_Fn> _Pass_fn(_Fn& _Val)
	{
		return { _Val };
	}

	struct input_iterator_tag
	{
	};

	struct output_iterator_tag
	{
	};

	struct forward_iterator_tag
		: input_iterator_tag
	{
	};

	struct bidirectional_iterator_tag
		: forward_iterator_tag
	{
	};

	struct random_access_iterator_tag
		: bidirectional_iterator_tag
	{
	};

	struct _General_ptr_iterator_tag
	{
	};

	struct _Trivially_copyable_ptr_iterator_tag
		: _General_ptr_iterator_tag
	{
	};

	struct _Really_trivial_ptr_iterator_tag
		: _Trivially_copyable_ptr_iterator_tag
	{
	};

	struct _Unused_parameter
	{
		constexpr _Unused_parameter() noexcept = default;
		template<class _Ty>
		constexpr _Unused_parameter(_Ty&&) noexcept {}
	};

	using _Any_tag = _Unused_parameter;

	template<class _Ty>
	using _Algorithm_int_t = conditional_t<is_integral_v<_Ty>, _Ty, ptrdiff_t>;

	template<class,
		class = void>
		struct _Iterator_traits_base
	{
	};

	template<class _Iter>
	struct _Iterator_traits_base<_Iter, void_t<
		typename _Iter::iterator_category,
		typename _Iter::value_type,
		typename _Iter::difference_type,
		typename _Iter::pointer,
		typename _Iter::reference
		>>
	{
		using iterator_category = typename _Iter::iterator_category;
		using value_type = typename _Iter::value_type;
		using difference_type = typename _Iter::difference_type;

		using pointer = typename _Iter::pointer;
		using reference = typename _Iter::reference;
	};

	template<class _Ty,
		bool = is_object_v<_Ty>>
		struct _Iterator_traits_pointer_base
	{
		using iterator_category = random_access_iterator_tag;
		using value_type = remove_cv_t<_Ty>;
		using difference_type = ptrdiff_t;

		using pointer = _Ty * ;
		using reference = _Ty & ;
	};

	template<class _Ty>
	struct _Iterator_traits_pointer_base<_Ty, false>
	{

	};

	template<class _Iter>
	struct iterator_traits
		: _Iterator_traits_base<_Iter>
	{
	};

	template<class _Ty>
	struct iterator_traits<_Ty *>
		: _Iterator_traits_pointer_base<_Ty>
	{
	};

	template<class _Iter>
	using _Iter_value_t = typename iterator_traits<_Iter>::value_type;

	template<class _Iter>
	using _Iter_diff_t = typename iterator_traits<_Iter>::difference_type;

	template<class... _Iters>
	using _Common_diff_t = common_type_t<_Iter_diff_t<_Iters>...>;

	template<class _Iter>
	using _Iter_cat_t = typename iterator_traits<_Iter>::iterator_category;

	template<class _Ty,
		class = void>
		constexpr bool _Is_iterator_v = false;

	template<class _Ty>
	constexpr bool _Is_iterator_v<_Ty, void_t<_Iter_cat_t<_Ty>>> = true;

	template<class _Ty>
	struct _Is_iterator
		: bool_constant<_Is_iterator_v<_Ty>>
	{
	};

	template<class _Iter>
	constexpr bool _Is_input_iter_v = is_convertible_v<_Iter_cat_t<_Iter>, input_iterator_tag>;

	template<class _Iter>
	constexpr bool _Is_fwd_iter_v = is_convertible_v<_Iter_cat_t<_Iter>, forward_iterator_tag>;

	template<class _Iter>
	constexpr bool _Is_bidi_iter_v = is_convertible_v<_Iter_cat_t<_Iter>, bidirectional_iterator_tag>;

	template<class _Iter>
	constexpr bool _Is_random_iter_v = is_convertible_v<_Iter_cat_t<_Iter>, random_access_iterator_tag>;

	template<class,
		class = void>
		struct _Is_checked_helper
	{
	};

	template<class _Ty>
	constexpr void _Verify_range(const _Ty * const _First, const _Ty * const _Last) noexcept
	{
		do { if (_First <= _Last) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 559, 0, "%s", "transposed pointer range")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"transposed pointer range\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 559, 0); } while (false); }; } while (false);
	}

	template<class _Iter,
		class _Sentinel = _Iter,
		class = void>
		struct _Range_verifiable
		: false_type
	{
	};

	template<class _Iter,
		class _Sentinel>
		struct _Range_verifiable<_Iter, _Sentinel, void_t<
		decltype(_Verify_range(::std::declval<const _Iter&>(), ::std::declval<const _Sentinel&>()))>>
		: true_type
	{
	};

	template<class _Iter,
		class _Sentinel = _Iter>
		constexpr bool _Range_verifiable_v = _Range_verifiable<_Iter, _Sentinel>::value;

	template<class _Iter,
		class _Sentinel>
		constexpr void _Adl_verify_range1(const _Iter& _First, const _Sentinel& _Last, true_type)
	{
		_Verify_range(_First, _Last);
	}

	template<class _Iter,
		class _Sentinel>
		constexpr void _Adl_verify_range1(const _Iter&, const _Sentinel&, false_type)
	{
	}

	template<class _Iter,
		class _Sentinel>
		constexpr void _Adl_verify_range(const _Iter& _First, const _Sentinel& _Last)
	{
		_Adl_verify_range1(_First, _Last, bool_constant<_Range_verifiable_v<_Iter, _Sentinel>>{});
	}

	template<class _Iter,
		class = void>
		struct _Unwrappable
		: false_type
	{
	};

	template<class _Iter>
	struct _Unwrappable<_Iter, void_t<
		decltype(::std::declval<_Iter&>()._Seek_to(::std::declval<const _Iter&>()._Unwrapped()))>>
		: true_type
	{
	};

	template<class _Iter>
	constexpr bool _Unwrappable_v = _Unwrappable<_Iter>::value;

	template<class _Iter,
		enable_if_t<_Unwrappable_v<_Iter>, int> = 0>
		constexpr auto _Get_unwrapped(const _Iter& _It)
	{
		return (_It._Unwrapped());
	}

	template<class _Iter,
		enable_if_t<!_Unwrappable_v<_Iter>, int> = 0>
		constexpr const _Iter& _Get_unwrapped(const _Iter& _It)
	{
		return (_It);
	}

	template<class _Iter,
		enable_if_t<!_Unwrappable_v<_Iter>, int> = 0>
		constexpr const _Iter&& _Get_unwrapped(const _Iter&& _It)
	{
		return (static_cast<const _Iter&&>(_It));
	}

	template<class _Ty>
	constexpr _Ty * _Get_unwrapped(_Ty * const _Ptr)
	{
		return (_Ptr);
	}

	template<class _Iter>
	using _Unwrapped_t = remove_cv_t<remove_reference_t<decltype(_Get_unwrapped(::std::declval<const _Iter&>()))>>;

	template<class _Iter,
		class = bool>
		struct _Do_unwrap_when_unverified
		: false_type
	{
	};

	template<class _Iter>
	struct _Do_unwrap_when_unverified<_Iter, decltype(static_cast<bool>(_Iter::_Unwrap_when_unverified))>
		: bool_constant<static_cast<bool>(_Iter::_Unwrap_when_unverified)>
	{
	};

	template<class _Iter>
	constexpr bool _Do_unwrap_when_unverified_v = _Do_unwrap_when_unverified<_Iter>::value;

	template<class _Iter>
	constexpr bool _Unwrappable_for_unverified_v = _Unwrappable_v<_Iter>
		&& _Do_unwrap_when_unverified_v<_Iter>;

	template<class _Iter,
		enable_if_t<_Unwrappable_for_unverified_v<_Iter>, int> = 0>
		constexpr auto _Get_unwrapped_unverified(const _Iter& _It)
	{
		return (_It._Unwrapped());
	}

	template<class _Iter,
		enable_if_t<!_Unwrappable_for_unverified_v<_Iter>, int> = 0>
		constexpr const _Iter& _Get_unwrapped_unverified(const _Iter& _It)
	{
		return (_It);
	}

	template<class _Iter,
		enable_if_t<!_Unwrappable_for_unverified_v<_Iter>, int> = 0>
		constexpr const _Iter&& _Get_unwrapped_unverified(const _Iter&& _It)
	{
		return (static_cast<const _Iter&&>(_It));
	}

	template<class _Ty>
	constexpr _Ty * _Get_unwrapped_unverified(_Ty * const _Ptr)
	{
		return (_Ptr);
	}

	template<class _Iter>
	using _Unwrapped_unverified_t = remove_cv_t<remove_reference_t<
		decltype(_Get_unwrapped_unverified(::std::declval<const _Iter&>()))>>;

	struct _Distance_unknown
	{
		constexpr _Distance_unknown operator-() const noexcept
		{
			return {};
		}
	};

	template<class _Diff>
	constexpr _Diff _Max_possible_v = static_cast<_Diff>(static_cast<make_unsigned_t<_Diff>>(-1) >> 1);

	template<class _Diff>
	constexpr _Diff _Min_possible_v = -_Max_possible_v<_Diff> -1;

	template<class _Iter,
		class = void>
		struct _Offset_verifiable
		: false_type
	{
	};

	template<class _Iter>
	struct _Offset_verifiable < _Iter, void_t<decltype(
		::std::declval<const _Iter&>()._Verify_offset(_Iter_diff_t<_Iter>{})) >>
		: true_type
	{
	};

	template<class _Iter>
	constexpr bool _Offset_verifiable_v = _Offset_verifiable<_Iter>::value;

	template<class _Iter>
	constexpr bool _Unwrappable_for_offset_v = _Unwrappable_v<_Iter> && _Offset_verifiable_v<_Iter>;

	template<class _Iter,
		class _Diff,
		enable_if_t<_Unwrappable_for_offset_v<_Iter> && is_integral_v<_Diff>, int> = 0>
		constexpr auto _Get_unwrapped_n(const _Iter& _It, const _Diff _Off)
	{
		using _IDiff = _Iter_diff_t<_Iter>;
		using _CDiff = common_type_t<_Diff, _IDiff>;
		const auto _COff = static_cast<_CDiff>(_Off);

		do { if (_COff <= static_cast<_CDiff>(_Max_possible_v<_IDiff>) && (is_unsigned_v<_Diff> || static_cast<_CDiff>(_Min_possible_v<_IDiff>) <= _COff)) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 767, 0, "%s", "integer overflow")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"integer overflow\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 767, 0); } while (false); }; } while (false);

		(void)_COff;

		_It._Verify_offset(static_cast<_IDiff>(_Off));
		return (_It._Unwrapped());
	}

	template<class _Iter,
		class _Diff,
		enable_if_t<_Unwrappable_for_unverified_v<_Iter>
		&& ((!_Unwrappable_for_offset_v<_Iter> && is_integral_v<_Diff>)
			|| is_same_v<_Diff, _Distance_unknown>), int> = 0>
		constexpr auto _Get_unwrapped_n(const _Iter& _It, _Diff)
	{
		return (_It._Unwrapped());
	}

	template<class _Iter,
		class _Diff,
		enable_if_t<!_Unwrappable_for_unverified_v<_Iter>
		&& ((!_Unwrappable_for_offset_v<_Iter> && is_integral_v<_Diff>)
			|| is_same_v<_Diff, _Distance_unknown>), int> = 0>
		constexpr const _Iter& _Get_unwrapped_n(const _Iter& _It, _Diff)
	{
		return (_It);
	}

	template<class _Iter,
		class _Diff,
		enable_if_t<!_Unwrappable_for_unverified_v<_Iter>
		&& ((!_Unwrappable_for_offset_v<_Iter> && is_integral_v<_Diff>)
			|| is_same_v<_Diff, _Distance_unknown>), int> = 0>
		constexpr const _Iter&& _Get_unwrapped_n(const _Iter&& _It, _Diff)
	{
		return (static_cast<const _Iter&&>(_It));
	}

	template<class _Ty,
		class _Diff,
		enable_if_t<is_same_v<_Diff, _Distance_unknown> || is_integral_v<_Diff>, int> = 0>
		constexpr _Ty * _Get_unwrapped_n(_Ty * const _Src, _Diff)
	{
		return (_Src);
	}

	template<class _Iter>
	using _Unwrapped_n_t = remove_cv_t < remove_reference_t<
		decltype(_Get_unwrapped_n(::std::declval<const _Iter&>(), _Iter_diff_t<_Iter>{})) >> ;

	template<class _Iter,
		class _UIter,
		class = void>
		struct _Wrapped_seekable
		: false_type
	{
	};

	template<class _Iter,
		class _UIter>
		struct _Wrapped_seekable<_Iter, _UIter, void_t<
		decltype(::std::declval<_Iter&>()._Seek_to(::std::declval<const _UIter&>()))>>
		: true_type
	{
	};

	template<class _Iter,
		class _UIter>
		constexpr bool _Wrapped_seekable_v = _Wrapped_seekable<_Iter, _UIter>::value;

	template<class _Iter,
		class _UIter,
		enable_if_t<_Wrapped_seekable_v<_Iter, _UIter>, int> = 0>
		constexpr void _Seek_wrapped(_Iter& _It, const _UIter& _UIt)
	{
		_It._Seek_to(_UIt);
	}

	template<class _Iter,
		class _UIter,
		enable_if_t<!_Wrapped_seekable_v<_Iter, _UIter>, int> = 0>
		constexpr void _Seek_wrapped(_Iter& _It, const _UIter& _UIt)
	{
		_It = _UIt;
	}

	template<class _Ty>
	constexpr void _Seek_wrapped(_Ty *& _It, _Ty * const _UIt)
	{
		_It = _UIt;
	}

	template<size_t _Value>
	struct _Priority_tag
		: _Priority_tag<_Value - 1>
	{
	};

	template<>
	struct _Priority_tag<0>
	{
	};

	template<class _Checked,
		class _Iter> inline
		_Distance_unknown _Idl_distance1(const _Iter&, const _Iter&, input_iterator_tag)
	{
		return {};
	}

	template<class _Checked,
		class _Iter> inline
		_Iter_diff_t<_Checked> _Idl_distance1(const _Iter& _First, const _Iter& _Last, random_access_iterator_tag)
	{
		return (static_cast<_Iter_diff_t<_Checked>>(_Last - _First));
	}

	template<class _Checked,
		class _Iter> inline
		auto _Idl_distance(const _Iter& _First, const _Iter& _Last)
	{
		return (_Idl_distance1<_Checked>(_First, _Last, _Iter_cat_t<_Iter>()));
	}

	template<class _Ty1,
		class _Ty2>
		struct _Is_same_size
		: bool_constant<sizeof(_Ty1) == sizeof(_Ty2)>
	{
	};

	template<class _Elem,
		bool _Is_enum = is_enum_v<_Elem>>
		struct _Unwrap_enum
	{
		using type = underlying_type_t<_Elem>;
	};

	template<class _Elem>
	struct _Unwrap_enum<_Elem, false>
	{
		using type = _Elem;
	};

	template<class _Elem>
	using _Unwrap_enum_t = typename _Unwrap_enum<_Elem>::type;

	template<class _Ty1,
		class _Ty2>
		struct _Both_or_neither_bool
		: bool_constant<is_same_v<bool, _Ty1> == is_same_v<bool, _Ty2>>
	{
	};

	template<class _Source,
		class _Dest>
		struct _Ptr_cat_helper
	{
		using _USource = _Unwrap_enum_t<_Source>;
		using _UDest = _Unwrap_enum_t<_Dest>;
		using type = conditional_t<conjunction_v<
			_Is_same_size<_USource, _UDest>,
			is_integral<_USource>,
			is_integral<_UDest>,
			_Both_or_neither_bool<_USource, _UDest>
		>, _Really_trivial_ptr_iterator_tag, _General_ptr_iterator_tag>;
	};

	template<class _Elem>
	struct _Ptr_cat_helper<_Elem, _Elem>
	{
		using type = conditional_t<
			is_trivially_copyable_v<_Elem>,
			conditional_t<is_trivial_v<_Elem>,
			_Really_trivial_ptr_iterator_tag,
			_Trivially_copyable_ptr_iterator_tag>,
			_General_ptr_iterator_tag>;
	};

	template<class _Anything>
	struct _Ptr_cat_helper<_Anything *, const _Anything *>
	{
		using type = _Really_trivial_ptr_iterator_tag;
	};

	template<class _Anything>
	struct _Ptr_cat_helper<_Anything *, volatile _Anything *>
	{
		using type = _Really_trivial_ptr_iterator_tag;
	};

	template<class _Anything>
	struct _Ptr_cat_helper<_Anything *, const volatile _Anything *>
	{
		using type = _Really_trivial_ptr_iterator_tag;
	};

	template<class _Source,
		class _Dest> inline
		_General_ptr_iterator_tag _Ptr_copy_cat(const _Source&, const _Dest&)
	{
		return {};
	}

	template<class _Source,
		class _Dest> inline
		conditional_t<is_trivially_assignable_v<_Dest&, _Source&>,
		typename _Ptr_cat_helper<remove_cv_t<_Source>, remove_cv_t<_Dest>>::type,
		_General_ptr_iterator_tag>
		_Ptr_copy_cat(_Source * const&, _Dest * const&)
	{
		return {};
	}

	template<class _Source,
		class _Dest> inline
		_General_ptr_iterator_tag _Ptr_move_cat(const _Source&, const _Dest&)
	{
		return {};
	}

	template<class _Source,
		class _Dest> inline
		conditional_t<is_trivially_assignable_v<_Dest&, _Source>,
		typename _Ptr_cat_helper<remove_cv_t<_Source>, remove_cv_t<_Dest>>::type,
		_General_ptr_iterator_tag>
		_Ptr_move_cat(_Source * const&, _Dest * const&)
	{
		return {};
	}

	template<class _Pr,
		class _Ty1,
		class _Ty2>
		constexpr bool _Debug_lt_pred(_Pr&& _Pred, _Ty1&& _Left, _Ty2&& _Right)
		noexcept(noexcept(_Pred(_Left, _Right)) && noexcept(_Pred(_Right, _Left)))
	{
		const auto _Result = static_cast<bool>(_Pred(_Left, _Right));
		if (_Result)
		{
			do { if (!_Pred(_Right, _Left)) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1113, 0, "%s", "invalid comparator")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"invalid comparator\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1113, 0); } while (false); }; } while (false);
		}

		return (_Result);
	}

	template<class _InIt,
		class _Sentinel,
		class _Pr> inline
		void _Debug_order_unchecked2(_InIt, _Sentinel, _Pr&, input_iterator_tag)
	{
	}

	template<class _FwdIt,
		class _Sentinel,
		class _Pr> inline
		void _Debug_order_unchecked2(_FwdIt _First, _Sentinel _Last, _Pr& _Pred, forward_iterator_tag)
	{
		if (_First != _Last)
		{
			for (_FwdIt _Next = _First; ++_Next != _Last; _First = _Next)
			{
				do { if (!_Debug_lt_pred(_Pred, *_Next, *_First)) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1136, 0, "%s", "sequence not ordered")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"sequence not ordered\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1136, 0); } while (false); }; } while (false);
			}
		}
	}

	template<class _InIt,
		class _Sentinel,
		class _Pr> inline
		void _Debug_order_unchecked(_InIt _First, _Sentinel _Last, _Pr&& _Pred)
	{
		_Debug_order_unchecked2(_First, _Last, _Pred, _Iter_cat_t<_InIt>());
	}

	template<class _InIt,
		class _Pr> inline
		void _Debug_order_set_unchecked2(_InIt, _InIt, _Pr&, input_iterator_tag, _Priority_tag<0>)
	{
	}

	template<class _FwdIt,
		class _Pr> inline
		void _Debug_order_set_unchecked2(_FwdIt _First, _FwdIt _Last, _Pr& _Pred, forward_iterator_tag, _Priority_tag<1>)
	{
		_Debug_order_unchecked2(_First, _Last, _Pred, forward_iterator_tag{});
	}

	template<class _OtherIt,
		class _InIt,
		class _Pr> inline
		void _Debug_order_set_unchecked(_InIt _First, _InIt _Last, _Pr&& _Pred)
	{
		_Debug_order_set_unchecked2(_First, _Last, _Pred, _Iter_cat_t<_InIt>(),
			_Priority_tag<is_same<_Iter_value_t<_OtherIt>, _Iter_value_t<_InIt>>::value>());
	}

	template<class _InIt,
		class _Diff>
		inline void _Advance1(_InIt& _Where, _Diff _Off, input_iterator_tag)
	{
		do { if (_Off >= 0) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1179, 0, "%s", "negative advance of non-bidirectional iterator")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"negative advance of non-bidirectional iterator\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1179, 0); } while (false); }; } while (false);
		for (; 0 < _Off; --_Off)
		{
			++_Where;
		}
	}

	template<class _BidIt,
		class _Diff>
		inline void _Advance1(_BidIt& _Where, _Diff _Off, bidirectional_iterator_tag)
	{
		for (; 0 < _Off; --_Off)
		{
			++_Where;
		}

#pragma warning(suppress: 6294)	

		for (; _Off < 0; ++_Off)
		{
			--_Where;
		}
	}

	template<class _RanIt,
		class _Diff>
		inline void _Advance1(_RanIt& _Where, _Diff _Off, random_access_iterator_tag)
	{
		_Where += _Off;
	}

	template<class _InIt,
		class _Diff>
		inline void advance(_InIt& _Where, _Diff _Off)
	{

		_Advance1(_Where, _Off, _Iter_cat_t<remove_const_t<_InIt>>());
	}

	template<class _InIt>
	inline _Iter_diff_t<_InIt> _Distance1(_InIt _First, _InIt _Last, input_iterator_tag)
	{
		_Iter_diff_t<_InIt> _Off = 0;
		for (; _First != _Last; ++_First)
		{
			++_Off;
		}

		return (_Off);
	}

	template<class _RanIt>
	inline _Iter_diff_t<_RanIt> _Distance1(_RanIt _First, _RanIt _Last, random_access_iterator_tag)
	{
		return (_Last - _First);
	}

	template<class _InIt>
	inline _Iter_diff_t<_InIt> distance(_InIt _First, _InIt _Last)
	{
		return (_Distance1(_First, _Last, _Iter_cat_t<_InIt>()));
	}

	template<class _InIt>
	constexpr _InIt _Next_iter(_InIt _First)
	{
		return (++_First);
	}

	template<class _InIt>
	inline _InIt next(_InIt _First, _Iter_diff_t<_InIt> _Off = 1)
	{
		static_assert(_Is_input_iter_v<_InIt>, "next requires input iterator");

		::std::advance(_First, _Off);
		return (_First);
	}

	template<class _BidIt>
	constexpr _BidIt _Prev_iter(_BidIt _First)
	{
		return (--_First);
	}

	template<class _BidIt>
	inline _BidIt prev(_BidIt _First, _Iter_diff_t<_BidIt> _Off = 1)
	{
		static_assert(_Is_bidi_iter_v<_BidIt>, "prev requires bidirectional iterator");

		::std::advance(_First, -_Off);
		return (_First);
	}

	template<class _Ty>
	struct pointer_traits;

	template<class _Iterator>
	constexpr _Iterator _Operator_arrow(_Iterator _Target, true_type)
	{
		return (_Target);
	}

	template<class _Iterator>
	constexpr decltype(auto) _Operator_arrow(_Iterator&& _Target, false_type)
	{
		return (::std::forward<_Iterator>(_Target).operator->());
	}

	template<class _BidIt>
	class reverse_iterator
	{
	public:
		using iterator_category = typename iterator_traits<_BidIt>::iterator_category;
		using value_type = typename iterator_traits<_BidIt>::value_type;
		using difference_type = typename iterator_traits<_BidIt>::difference_type;
		using pointer = typename iterator_traits<_BidIt>::pointer;
		using reference = typename iterator_traits<_BidIt>::reference;

		using iterator_type = _BidIt;

		inline reverse_iterator()
			: current()
		{
		}

		inline explicit reverse_iterator(_BidIt _Right)
			: current(_Right)
		{
		}

		template<class _Other>
		inline reverse_iterator(const reverse_iterator<_Other>& _Right)
			: current(_Right.base())
		{
		}

		template<class _Other>
		inline reverse_iterator& operator=(const reverse_iterator<_Other>& _Right)
		{
			current = _Right.base();
			return (*this);
		}

		inline _BidIt base() const
		{
			return (current);
		}

		inline reference operator*() const
		{
			_BidIt _Tmp = current;
			return (*--_Tmp);
		}

		inline pointer operator->() const
		{
			_BidIt _Tmp = current;
			--_Tmp;
			return (_Operator_arrow(_Tmp, is_pointer<_BidIt>()));
		}

		inline reverse_iterator& operator++()
		{
			--current;
			return (*this);
		}

		inline reverse_iterator operator++(int)
		{
			reverse_iterator _Tmp = *this;
			--current;
			return (_Tmp);
		}

		inline reverse_iterator& operator--()
		{
			++current;
			return (*this);
		}

		inline reverse_iterator operator--(int)
		{
			reverse_iterator _Tmp = *this;
			++current;
			return (_Tmp);
		}

		inline reverse_iterator& operator+=(const difference_type _Off)
		{
			current -= _Off;
			return (*this);
		}

		inline reverse_iterator operator+(const difference_type _Off) const
		{
			return (reverse_iterator(current - _Off));
		}

		inline reverse_iterator& operator-=(const difference_type _Off)
		{
			current += _Off;
			return (*this);
		}

		inline reverse_iterator operator-(const difference_type _Off) const
		{
			return (reverse_iterator(current + _Off));
		}

		inline reference operator[](const difference_type _Off) const
		{
			return (*(*this + _Off));
		}

		template<class _BidIt2 = _BidIt,
			enable_if_t<_Offset_verifiable_v<_BidIt2>, int> = 0>
			constexpr void _Verify_offset(const difference_type _Off) const
		{
			do { if (_Off != _Min_possible_v<difference_type>) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1406, 0, "%s", "integer overflow")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"integer overflow\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1406, 0); } while (false); }; } while (false);
			current._Verify_offset(-_Off);
		}

		template<class _BidIt2 = _BidIt,
			enable_if_t<_Unwrappable_v<_BidIt2>, int> = 0>
			constexpr reverse_iterator<_Unwrapped_t<_BidIt2>> _Unwrapped() const
		{
			return (static_cast<reverse_iterator<_Unwrapped_t<_BidIt2>>>(current._Unwrapped()));
		}

		static constexpr bool _Unwrap_when_unverified = _Do_unwrap_when_unverified_v<_BidIt>;

		template<class _Src,
			enable_if_t<_Wrapped_seekable_v<_BidIt, _Src>, int> = 0>
			constexpr void _Seek_to(const reverse_iterator<_Src>& _It)
		{
			current._Seek_to(_It.base());
		}
	protected:
		_BidIt current;
	};

	template<class _BidIt,
		class _BidIt2,
		enable_if_t<_Range_verifiable_v<_BidIt, _BidIt2>, int> = 0>
		constexpr void _Verify_range(const reverse_iterator<_BidIt>& _First, const reverse_iterator<_BidIt2>& _Last)
	{

		_Verify_range(_Last.base(), _First.base());
	}

	template<class _BidIt>
	inline reverse_iterator<_BidIt> operator+(
		typename reverse_iterator<_BidIt>::difference_type _Off,
		const reverse_iterator<_BidIt>& _Right)
	{
		return (_Right + _Off);
	}

	template<class _BidIt1,
		class _BidIt2>
		inline auto operator-(const reverse_iterator<_BidIt1>& _Left,
			const reverse_iterator<_BidIt2>& _Right)
		-> decltype(_Right.base() - _Left.base())
	{
		return (_Right.base() - _Left.base());
	}

	template<class _BidIt1,
		class _BidIt2>
		inline bool operator==(const reverse_iterator<_BidIt1>& _Left,
			const reverse_iterator<_BidIt2>& _Right)
	{
		return (_Left.base() == _Right.base());
	}

	template<class _BidIt1,
		class _BidIt2>
		inline bool operator!=(const reverse_iterator<_BidIt1>& _Left,
			const reverse_iterator<_BidIt2>& _Right)
	{
		return (!(_Left == _Right));
	}

	template<class _BidIt1,
		class _BidIt2>
		inline bool operator<(const reverse_iterator<_BidIt1>& _Left,
			const reverse_iterator<_BidIt2>& _Right)
	{
		return (_Right.base() < _Left.base());
	}

	template<class _BidIt1,
		class _BidIt2>
		inline bool operator>(const reverse_iterator<_BidIt1>& _Left,
			const reverse_iterator<_BidIt2>& _Right)
	{
		return (_Right < _Left);
	}

	template<class _BidIt1,
		class _BidIt2>
		inline bool operator<=(const reverse_iterator<_BidIt1>& _Left,
			const reverse_iterator<_BidIt2>& _Right)
	{
		return (!(_Right < _Left));
	}

	template<class _BidIt1,
		class _BidIt2>
		inline bool operator>=(const reverse_iterator<_BidIt1>& _Left,
			const reverse_iterator<_BidIt2>& _Right)
	{
		return (!(_Left < _Right));
	}

	template<class _BidIt>
	inline reverse_iterator<_BidIt> make_reverse_iterator(_BidIt _Iter)
	{
		return (reverse_iterator<_BidIt>(_Iter));
	}

	template<class _Container>
	inline auto begin(_Container& _Cont) -> decltype(_Cont.begin())
	{
		return (_Cont.begin());
	}

	template<class _Container>
	inline auto begin(const _Container& _Cont) -> decltype(_Cont.begin())
	{
		return (_Cont.begin());
	}

	template<class _Container>
	inline auto end(_Container& _Cont) -> decltype(_Cont.end())
	{
		return (_Cont.end());
	}

	template<class _Container>
	inline auto end(const _Container& _Cont) -> decltype(_Cont.end())
	{
		return (_Cont.end());
	}

	template<class _Ty,
		size_t _Size>
		constexpr _Ty *begin(_Ty(&_Array)[_Size]) noexcept
	{
		return (_Array);
	}

	template<class _Ty,
		size_t _Size>
		constexpr _Ty *end(_Ty(&_Array)[_Size]) noexcept
	{
		return (_Array + _Size);
	}

	template<class _Container>
	constexpr auto cbegin(const _Container& _Cont)
		noexcept(noexcept(::std::begin(_Cont)))
		-> decltype(::std::begin(_Cont))
	{
		return (::std::begin(_Cont));
	}

	template<class _Container>
	constexpr auto cend(const _Container& _Cont)
		noexcept(noexcept(::std::end(_Cont)))
		-> decltype(::std::end(_Cont))
	{
		return (::std::end(_Cont));
	}

	template<class _Container>
	inline auto rbegin(_Container& _Cont) -> decltype(_Cont.rbegin())
	{
		return (_Cont.rbegin());
	}

	template<class _Container>
	inline auto rbegin(const _Container& _Cont) -> decltype(_Cont.rbegin())
	{
		return (_Cont.rbegin());
	}

	template<class _Container>
	inline auto rend(_Container& _Cont) -> decltype(_Cont.rend())
	{
		return (_Cont.rend());
	}

	template<class _Container>
	inline auto rend(const _Container& _Cont) -> decltype(_Cont.rend())
	{
		return (_Cont.rend());
	}

	template<class _Ty,
		size_t _Size>
		inline reverse_iterator<_Ty *> rbegin(_Ty(&_Array)[_Size])
	{
		return (reverse_iterator<_Ty *>(_Array + _Size));
	}

	template<class _Ty,
		size_t _Size>
		inline reverse_iterator<_Ty *> rend(_Ty(&_Array)[_Size])
	{
		return (reverse_iterator<_Ty *>(_Array));
	}

	template<class _Elem>
	inline reverse_iterator<const _Elem *>
		rbegin(initializer_list<_Elem> _Ilist)
	{
		return (reverse_iterator<const _Elem *>(_Ilist.end()));
	}

	template<class _Elem>
	inline reverse_iterator<const _Elem *>
		rend(initializer_list<_Elem> _Ilist)
	{
		return (reverse_iterator<const _Elem *>(_Ilist.begin()));
	}

	template<class _Container>
	inline auto crbegin(const _Container& _Cont)
		-> decltype(::std::rbegin(_Cont))
	{
		return (::std::rbegin(_Cont));
	}

	template<class _Container>
	inline auto crend(const _Container& _Cont)
		-> decltype(::std::rend(_Cont))
	{
		return (::std::rend(_Cont));
	}

	template<class _Container>
	constexpr auto size(const _Container& _Cont)
		-> decltype(_Cont.size())
	{
		return (_Cont.size());
	}

	template<class _Ty,
		size_t _Size>
		constexpr size_t size(const _Ty(&)[_Size]) noexcept
	{
		return (_Size);
	}

	template<class _Container>
	constexpr auto empty(const _Container& _Cont)
		-> decltype(_Cont.empty())
	{
		return (_Cont.empty());
	}

	template<class _Ty,
		size_t _Size>
		constexpr bool empty(const _Ty(&)[_Size]) noexcept
	{
		return (false);
	}

	template<class _Elem>
	constexpr bool empty(
		initializer_list<_Elem> _Ilist) noexcept
	{
		return (_Ilist.size() == 0);
	}

	template<class _Container>
	constexpr auto data(_Container& _Cont)
		-> decltype(_Cont.data())
	{
		return (_Cont.data());
	}

	template<class _Container>
	constexpr auto data(const _Container& _Cont)
		-> decltype(_Cont.data())
	{
		return (_Cont.data());
	}

	template<class _Ty,
		size_t _Size>
		constexpr _Ty *data(_Ty(&_Array)[_Size]) noexcept
	{
		return (_Array);
	}

	template<class _Elem>
	constexpr const _Elem *data(
		initializer_list<_Elem> _Ilist) noexcept
	{
		return (_Ilist.begin());
	}

	struct _Iterator_base12_compatible
	{
		_Container_proxy * _Myproxy{};
		_Iterator_base12 * _Mynextiter{};
	};

	template<class _Ty,
		size_t _Size>
		class _Array_const_iterator

		: private _Iterator_base12_compatible

	{
	public:
		using iterator_category = random_access_iterator_tag;

		using value_type = _Ty;
		using difference_type = ptrdiff_t;
		using pointer = const _Ty *;
		using reference = const _Ty&;
		enum { _EEN_SIZE = _Size };

		inline _Array_const_iterator()
			: _Ptr(),
			_Idx(0)
		{
		}

		inline explicit _Array_const_iterator(pointer _Parg, size_t _Off = 0)
			: _Ptr(_Parg),
			_Idx(_Off)
		{
		}

		inline reference operator*() const
		{
			return (*operator->());
		}

		inline pointer operator->() const
		{
			do { if (_Ptr) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1872, 0, "%s", "cannot dereference value-initialized array iterator")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot dereference value-initialized array iterator\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1872, 0); } while (false); }; } while (false);
			do { if (_Idx < _Size) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1873, 0, "%s", "cannot dereference out of range array iterator")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot dereference out of range array iterator\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1873, 0); } while (false); }; } while (false);
			return (_Ptr + _Idx);
		}

		inline _Array_const_iterator& operator++()
		{
			do { if (_Ptr) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1879, 0, "%s", "cannot increment value-initialized array iterator")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot increment value-initialized array iterator\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1879, 0); } while (false); }; } while (false);
			do { if (_Idx < _Size) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1880, 0, "%s", "cannot increment array iterator past end")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot increment array iterator past end\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1880, 0); } while (false); }; } while (false);
			++_Idx;
			return (*this);
		}

		inline _Array_const_iterator operator++(int)
		{
			_Array_const_iterator _Tmp = *this;
			++*this;
			return (_Tmp);
		}

		inline _Array_const_iterator& operator--()
		{
			do { if (_Ptr) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1894, 0, "%s", "cannot decrement value-initialized array iterator")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot decrement value-initialized array iterator\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1894, 0); } while (false); }; } while (false);
			do { if (_Idx != 0) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1895, 0, "%s", "cannot decrement array iterator before begin")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot decrement array iterator before begin\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1895, 0); } while (false); }; } while (false);
			--_Idx;
			return (*this);
		}

		inline _Array_const_iterator operator--(int)
		{
			_Array_const_iterator _Tmp = *this;
			--*this;
			return (_Tmp);
		}

		constexpr void _Verify_offset(const ptrdiff_t _Off) const noexcept
		{
			if (_Off != 0)
			{
				do { if (_Ptr) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1911, 0, "%s", "cannot seek value-initialized array iterator")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot seek value-initialized array iterator\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1911, 0); } while (false); }; } while (false);
			}

			if (_Off < 0)
			{
#pragma warning(suppress: 4146)	
				do { if (_Idx >= -static_cast<size_t>(_Off)) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1918, 0, "%s", "cannot seek array iterator before begin")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot seek array iterator before begin\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1918, 0); } while (false); }; } while (false);

			}

			if (_Off > 0)
			{
				do { if (_Size - _Idx >= static_cast<size_t>(_Off)) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1924, 0, "%s", "cannot seek array iterator after end")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot seek array iterator after end\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1924, 0); } while (false); }; } while (false);

			}
		}

		inline _Array_const_iterator& operator+=(const ptrdiff_t _Off)
		{
			_Verify_offset(_Off);
			_Idx += _Off;
			return (*this);
		}

		inline _Array_const_iterator operator+(const ptrdiff_t _Off) const
		{
			_Array_const_iterator _Tmp = *this;
			return (_Tmp += _Off);
		}

		inline _Array_const_iterator& operator-=(const ptrdiff_t _Off)
		{
			return (*this += -_Off);
		}

		inline _Array_const_iterator operator-(const ptrdiff_t _Off) const
		{
			_Array_const_iterator _Tmp = *this;
			return (_Tmp -= _Off);
		}

		inline ptrdiff_t operator-(const _Array_const_iterator& _Right) const
		{
			_Compat(_Right);
			return (static_cast<ptrdiff_t>(_Idx - _Right._Idx));
		}

		inline reference operator[](const ptrdiff_t _Off) const
		{
			return (*(*this + _Off));
		}

		inline bool operator==(const _Array_const_iterator& _Right) const
		{
			_Compat(_Right);
			return (_Idx == _Right._Idx);
		}

		inline bool operator!=(const _Array_const_iterator& _Right) const
		{
			return (!(*this == _Right));
		}

		inline bool operator<(const _Array_const_iterator& _Right) const
		{
			_Compat(_Right);
			return (_Idx < _Right._Idx);
		}

		inline bool operator>(const _Array_const_iterator& _Right) const
		{
			return (_Right < *this);
		}

		inline bool operator<=(const _Array_const_iterator& _Right) const
		{
			return (!(_Right < *this));
		}

		inline bool operator>=(const _Array_const_iterator& _Right) const
		{
			return (!(*this < _Right));
		}

		inline void _Compat(const _Array_const_iterator& _Right) const
		{
			do { if (_Ptr == _Right._Ptr) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1997, 0, "%s", "array iterators incompatible")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"array iterators incompatible\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 1997, 0); } while (false); }; } while (false);
		}

		constexpr pointer _Unwrapped() const
		{
			return (_Ptr + _Idx);
		}

		constexpr void _Verify_with(const _Array_const_iterator& _Last) const noexcept
		{

			do { if (*this <= _Last) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 2008, 0, "%s", "array iterator range transposed")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"array iterator range transposed\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 2008, 0); } while (false); }; } while (false);
		}

		constexpr void _Seek_to(pointer _It)
		{
			_Idx = static_cast<size_t>(_It - _Ptr);
		}

	private:
		pointer _Ptr;
		size_t _Idx;

	};

	template<class _Ty,
		size_t _Size>
		constexpr void _Verify_range(const _Array_const_iterator<_Ty, _Size>& _First,
			const _Array_const_iterator<_Ty, _Size>& _Last) noexcept
	{

		_First._Verify_with(_Last);
	}

	template<class _Ty,
		size_t _Size>
		inline _Array_const_iterator<_Ty, _Size> operator+(
			ptrdiff_t _Off,
			_Array_const_iterator<_Ty, _Size> _Next)
	{
		return (_Next += _Off);
	}

	template<class _Ty,
		size_t _Size>
		class _Array_iterator
		: public _Array_const_iterator<_Ty, _Size>
	{
	public:
		using _Mybase = _Array_const_iterator<_Ty, _Size>;
		using iterator_category = random_access_iterator_tag;

		using value_type = _Ty;
		using difference_type = ptrdiff_t;
		using pointer = _Ty * ;
		using reference = _Ty & ;

		inline _Array_iterator()
		{
		}

		inline explicit _Array_iterator(pointer _Parg, size_t _Off = 0)
			: _Mybase(_Parg, _Off)
		{
		}

		enum { _EEN_SIZE = _Size };

		inline reference operator*() const
		{
			return (const_cast<reference>(_Mybase::operator*()));
		}

		inline pointer operator->() const
		{
			return (const_cast<pointer>(_Mybase::operator->()));
		}

		inline _Array_iterator& operator++()
		{
			++*static_cast<_Mybase *>(this);
			return (*this);
		}

		inline _Array_iterator operator++(int)
		{
			_Array_iterator _Tmp = *this;
			++*this;
			return (_Tmp);
		}

		inline _Array_iterator& operator--()
		{
			--*static_cast<_Mybase *>(this);
			return (*this);
		}

		inline _Array_iterator operator--(int)
		{
			_Array_iterator _Tmp = *this;
			--*this;
			return (_Tmp);
		}

		inline _Array_iterator& operator+=(const ptrdiff_t _Off)
		{
			*static_cast<_Mybase *>(this) += _Off;
			return (*this);
		}

		inline _Array_iterator operator+(const ptrdiff_t _Off) const
		{
			_Array_iterator _Tmp = *this;
			return (_Tmp += _Off);
		}

		inline _Array_iterator& operator-=(const ptrdiff_t _Off)
		{
			return (*this += -_Off);
		}

		inline _Array_iterator operator-(const ptrdiff_t _Off) const
		{
			_Array_iterator _Tmp = *this;
			return (_Tmp -= _Off);
		}

		inline ptrdiff_t operator-(const _Mybase& _Right) const
		{
			return (*static_cast<const _Mybase *>(this) - _Right);
		}

		inline reference operator[](const ptrdiff_t _Off) const
		{
			return (*(*this + _Off));
		}

		constexpr pointer _Unwrapped() const
		{
			return (const_cast<pointer>(_Mybase::_Unwrapped()));
		}
	};

	template<class _Ty,
		size_t _Size>
		inline _Array_iterator<_Ty, _Size> operator+(
			ptrdiff_t _Off,
			_Array_iterator<_Ty, _Size> _Next)
	{
		return (_Next += _Off);
	}

	template<class _Iter>
	class move_iterator
	{
	public:
		using iterator_category = typename iterator_traits<_Iter>::iterator_category;
		using value_type = typename iterator_traits<_Iter>::value_type;
		using difference_type = typename iterator_traits<_Iter>::difference_type;
		using pointer = _Iter;
		using _Ref0 = typename iterator_traits<_Iter>::reference;
		using reference = conditional_t<is_reference_v<_Ref0>, remove_reference_t<_Ref0>&&, _Ref0>;
		using iterator_type = _Iter;

		inline move_iterator()
			: current()
		{
		}

		inline explicit move_iterator(iterator_type _Right)
			: current(_Right)
		{
		}

		template<class _Iter2>
		inline move_iterator(const move_iterator<_Iter2>& _Right)
			: current(_Right.base())
		{
		}

		template<class _Iter2>
		inline move_iterator& operator=(const move_iterator<_Iter2>& _Right)
		{
			current = _Right.base();
			return (*this);
		}

		inline _Iter base() const
		{
			return (current);
		}

		inline reference operator*() const
		{
			return (static_cast<reference>(*current));
		}

		inline pointer operator->() const
		{
			return (current);
		}

		inline move_iterator& operator++()
		{
			++current;
			return (*this);
		}

		inline move_iterator operator++(int)
		{
			move_iterator _Tmp = *this;
			++current;
			return (_Tmp);
		}

		inline move_iterator& operator--()
		{
			--current;
			return (*this);
		}

		inline move_iterator operator--(int)
		{
			move_iterator _Tmp = *this;
			--current;
			return (_Tmp);
		}

		inline move_iterator& operator+=(const difference_type _Off)
		{
			current += _Off;
			return (*this);
		}

		inline move_iterator operator+(const difference_type _Off) const
		{
			return (move_iterator(current + _Off));
		}

		inline move_iterator& operator-=(const difference_type _Off)
		{
			current -= _Off;
			return (*this);
		}

		inline move_iterator operator-(const difference_type _Off) const
		{
			return (move_iterator(current - _Off));
		}

		inline reference operator[](const difference_type _Off) const
		{
			return (::std::move(current[_Off]));
		}

		template<class _Iter2,
			enable_if_t<_Range_verifiable_v<_Iter, _Iter2>, int> = 0>
			friend constexpr void _Verify_range(const move_iterator& _First, const move_iterator<_Iter2>& _Last)
		{
			_Verify_range(_First.base(), _Last.base());
		}

		template<class _Iter2 = iterator_type,
			enable_if_t<_Offset_verifiable_v<_Iter2>, int> = 0>
			constexpr void _Verify_offset(const difference_type _Off) const
		{
			current._Verify_offset(_Off);
		}

		template<class _Iter2 = iterator_type,
			enable_if_t<_Unwrappable_v<_Iter2>, int> = 0>
			constexpr move_iterator<_Unwrapped_t<_Iter2>> _Unwrapped() const
		{
			return (static_cast<move_iterator<_Unwrapped_t<_Iter2>>>(current._Unwrapped()));
		}

		static constexpr bool _Unwrap_when_unverified = _Do_unwrap_when_unverified_v<iterator_type>;

		template<class _Src,
			enable_if_t<_Wrapped_seekable_v<iterator_type, _Src>, int> = 0>
			constexpr void _Seek_to(const move_iterator<_Src>& _It)
		{
			current._Seek_to(_It.base());
		}
	protected:
		iterator_type current;
	};

	template<class _Iter>
	inline move_iterator<_Iter> operator+(
		typename move_iterator<_Iter>::difference_type _Off,
		const move_iterator<_Iter>& _Right)
	{
		return (_Right + _Off);
	}

	template<class _Iter1,
		class _Iter2>
		inline auto operator-(
			const move_iterator<_Iter1>& _Left,
			const move_iterator<_Iter2>& _Right)
		-> decltype(_Left.base() - _Right.base())
	{
		return (_Left.base() - _Right.base());
	}

	template<class _Iter1,
		class _Iter2>
		inline bool operator==(
			const move_iterator<_Iter1>& _Left,
			const move_iterator<_Iter2>& _Right)
	{
		return (_Left.base() == _Right.base());
	}

	template<class _Iter1,
		class _Iter2>
		inline bool operator!=(
			const move_iterator<_Iter1>& _Left,
			const move_iterator<_Iter2>& _Right)
	{
		return (!(_Left == _Right));
	}

	template<class _Iter1,
		class _Iter2>
		inline bool operator<(
			const move_iterator<_Iter1>& _Left,
			const move_iterator<_Iter2>& _Right)
	{
		return (_Left.base() < _Right.base());
	}

	template<class _Iter1,
		class _Iter2>
		inline bool operator>(
			const move_iterator<_Iter1>& _Left,
			const move_iterator<_Iter2>& _Right)
	{
		return (_Right < _Left);
	}

	template<class _Iter1,
		class _Iter2>
		inline bool operator<=(
			const move_iterator<_Iter1>& _Left,
			const move_iterator<_Iter2>& _Right)
	{
		return (!(_Right < _Left));
	}

	template<class _Iter1,
		class _Iter2>
		inline bool operator>=(
			const move_iterator<_Iter1>& _Left,
			const move_iterator<_Iter2>& _Right)
	{
		return (!(_Left < _Right));
	}

	template<class _Iter>
	inline move_iterator<_Iter> make_move_iterator(_Iter _It)
	{
		return (move_iterator<_Iter>(_It));
	}

	template<class _Traits>
	struct _Char_traits_eq
	{
		using _Elem = typename _Traits::char_type;

		bool operator()(_Elem _Left, _Elem _Right) const
		{
			return (_Traits::eq(_Left, _Right));
		}
	};

	template<class _Traits>
	struct _Char_traits_lt
	{
		using _Elem = typename _Traits::char_type;

		bool operator()(_Elem _Left, _Elem _Right) const
		{
			return (_Traits::lt(_Left, _Right));
		}
	};

	template<class _InIt,
		class _OutIt> inline
		_OutIt _Copy_memmove(_InIt _First, _InIt _Last, _OutIt _Dest)
	{
		const char * const _First_ch = const_cast<const char *>(reinterpret_cast<const volatile char *>(_First));
		const char * const _Last_ch = const_cast<const char *>(reinterpret_cast<const volatile char *>(_Last));
		char * const _Dest_ch = const_cast<char *>(reinterpret_cast<volatile char *>(_Dest));
		const auto _Count = static_cast<size_t>(_Last_ch - _First_ch);
		::memmove(_Dest_ch, _First_ch, _Count);
		return (reinterpret_cast<_OutIt>(_Dest_ch + _Count));
	}

	template<class _InIt,
		class _OutIt> inline
		_OutIt _Copy_unchecked1(_InIt _First, _InIt _Last,
			_OutIt _Dest, _General_ptr_iterator_tag)
	{
		for (; _First != _Last; ++_Dest, (void)++_First)
		{
			*_Dest = *_First;
		}

		return (_Dest);
	}

	template<class _InIt,
		class _OutIt> inline
		_OutIt _Copy_unchecked1(_InIt _First, _InIt _Last,
			_OutIt _Dest, _Trivially_copyable_ptr_iterator_tag)
	{
		return (_Copy_memmove(_First, _Last, _Dest));
	}

	template<class _InIt,
		class _OutIt> inline
		_OutIt _Copy_unchecked(_InIt _First, _InIt _Last,
			_OutIt _Dest)
	{

		return (_Copy_unchecked1(_First, _Last, _Dest, _Ptr_copy_cat(_First, _Dest)));
	}

	template<class _InIt,
		class _OutIt> inline
		_OutIt copy(_InIt _First, _InIt _Last, _OutIt _Dest)
	{
		_Adl_verify_range(_First, _Last);
		const auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		const auto _UDest = _Get_unwrapped_n(_Dest, _Idl_distance<_InIt>(_UFirst, _ULast));
		_Seek_wrapped(_Dest, _Copy_unchecked(_UFirst, _ULast, _UDest));
		return (_Dest);
	}

	template<class _InIt,
		class _DestTy,
		size_t _DestSize> inline
		_DestTy *copy(_InIt _First, _InIt _Last, _DestTy(&_Dest)[_DestSize])
	{
		return (::std::copy(_First, _Last, _Array_iterator<_DestTy, _DestSize>(_Dest))._Unwrapped());
	}

	template<class _InIt,
		class _Diff,
		class _OutIt> inline
		_OutIt _Copy_n_unchecked4(_InIt _First, _Diff _Count,
			_OutIt _Dest, _General_ptr_iterator_tag)
	{

		for (;;)
		{
			*_Dest = *_First;
			++_Dest;
			--_Count;
			if (_Count == 0)
			{

				return (_Dest);
			}

			++_First;
		}
	}

	template<class _InIt,
		class _Diff,
		class _OutIt> inline
		_OutIt _Copy_n_unchecked4(_InIt _First, _Diff _Count,
			_OutIt _Dest, _Trivially_copyable_ptr_iterator_tag)
	{

		return (_Copy_memmove(_First, _First + _Count, _Dest));
	}

	template<class _InIt,
		class _Diff,
		class _OutIt> inline
		_OutIt _Copy_n_unchecked3(_InIt _First, _Diff _Count,
			_OutIt _Dest)
	{

		return (_Copy_n_unchecked4(_First, _Count,
			_Dest, _Ptr_copy_cat(_First, _Dest)));
	}

	template<class _InIt,
		class _Diff,
		class _OutIt> inline
		_OutIt copy_n(_InIt _First, _Diff _Count_raw, _OutIt _Dest)
	{
		const _Algorithm_int_t<_Diff> _Count = _Count_raw;
		if (0 < _Count)
		{
			_Seek_wrapped(_Dest,
				_Copy_n_unchecked3(_Get_unwrapped_n(_First, _Count), _Count, _Get_unwrapped_n(_Dest, _Count)));
		}

		return (_Dest);
	}

	template<class _SourceTy,
		size_t _SourceSize,
		class _Diff,
		class _OutIt> inline
		_OutIt copy_n(_SourceTy(&_First)[_SourceSize], _Diff _Count_raw, _OutIt _Dest)
	{
		const _Algorithm_int_t<_Diff> _Count = _Count_raw;
		if (0 < _Count)
		{
			do { if ((::std::size(_First) >= static_cast<common_type_t<size_t, decltype(_Count)>>(_Count))) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 2557, 0, "%s", "array too small")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"array too small\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 2557, 0); } while (false); }; } while (false);
			_Seek_wrapped(_Dest, _Copy_n_unchecked3(_First, _Count, _Get_unwrapped_n(_Dest, _Count)));
		}

		return (_Dest);
	}

	template<class _InIt,
		class _Diff,
		class _DestTy,
		size_t _DestSize> inline
		_DestTy *copy_n(_InIt _First, _Diff _Count_raw, _DestTy(&_Dest)[_DestSize])
	{
		const _Algorithm_int_t<_Diff> _Count = _Count_raw;
		if (0 < _Count)
		{
			do { if ((::std::size(_Dest) >= static_cast<common_type_t<size_t, decltype(_Count)>>(_Count))) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 2573, 0, "%s", "array too small")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"array too small\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 2573, 0); } while (false); }; } while (false);
			return (_Copy_n_unchecked3(_Get_unwrapped_n(_First, _Count), _Count, _Dest));
		}

		return (_Dest);
	}

	template<class _SourceTy,
		size_t _SourceSize,
		class _Diff,
		class _DestTy,
		size_t _DestSize> inline
		_DestTy *copy_n(_SourceTy(&_First)[_SourceSize], _Diff _Count_raw, _DestTy(&_Dest)[_DestSize])
	{
		const _Algorithm_int_t<_Diff> _Count = _Count_raw;
		if (0 < _Count)
		{
			do { if ((::std::size(_First) >= static_cast<common_type_t<size_t, decltype(_Count)>>(_Count))) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 2590, 0, "%s", "array too small")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"array too small\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 2590, 0); } while (false); }; } while (false);
			do { if ((::std::size(_Dest) >= static_cast<common_type_t<size_t, decltype(_Count)>>(_Count))) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 2591, 0, "%s", "array too small")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"array too small\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 2591, 0); } while (false); }; } while (false);
			return (_Copy_n_unchecked3(_First, _Count, _Dest));
		}

		return (_Dest);
	}

	template<class _BidIt1,
		class _BidIt2> inline
		_BidIt2 _Copy_backward_memmove(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest)
	{
		const char * const _First_ch = const_cast<const char *>(reinterpret_cast<const volatile char *>(_First));
		const char * const _Last_ch = const_cast<const char *>(reinterpret_cast<const volatile char *>(_Last));
		char * const _Dest_ch = const_cast<char *>(reinterpret_cast<volatile char *>(_Dest));
		const auto _Count = static_cast<size_t>(_Last_ch - _First_ch);
		return (static_cast<_BidIt2>(
			::memmove(_Dest_ch - _Count, _First_ch, _Count)));
	}

	template<class _BidIt1,
		class _BidIt2> inline
		_BidIt2 _Copy_backward_unchecked(_BidIt1 _First, _BidIt1 _Last,
			_BidIt2 _Dest, _General_ptr_iterator_tag)
	{
		while (_First != _Last)
			*--_Dest = *--_Last;
		return (_Dest);
	}

	template<class _BidIt1,
		class _BidIt2> inline
		_BidIt2 _Copy_backward_unchecked(_BidIt1 _First, _BidIt1 _Last,
			_BidIt2 _Dest, _Trivially_copyable_ptr_iterator_tag)
	{
		return (_Copy_backward_memmove(_First, _Last, _Dest));
	}

	template<class _BidIt1,
		class _BidIt2> inline
		_BidIt2 copy_backward(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest)
	{
		_Adl_verify_range(_First, _Last);
		const auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		const auto _UDest = _Get_unwrapped_n(_Dest, -_Idl_distance<_BidIt1>(_UFirst, _ULast));
		_Seek_wrapped(_Dest,
			_Copy_backward_unchecked(_UFirst, _ULast, _UDest, _Ptr_copy_cat(_UFirst, _UDest)));
		return (_Dest);
	}

	template<class _InIt,
		class _OutIt> inline
		_OutIt _Move_unchecked1(_InIt _First, _InIt _Last,
			_OutIt _Dest, _General_ptr_iterator_tag)
	{
		for (; _First != _Last; ++_Dest, (void)++_First)
			*_Dest = ::std::move(*_First);
		return (_Dest);
	}

	template<class _InIt,
		class _OutIt> inline
		_OutIt _Move_unchecked1(_InIt _First, _InIt _Last,
			_OutIt _Dest, _Trivially_copyable_ptr_iterator_tag)
	{
		return (_Copy_memmove(_First, _Last, _Dest));
	}

	template<class _InIt,
		class _OutIt> inline
		_OutIt _Move_unchecked(_InIt _First, _InIt _Last,
			_OutIt _Dest)
	{

		return (_Move_unchecked1(_First, _Last,
			_Dest, _Ptr_move_cat(_First, _Dest)));
	}

	template<class _InIt,
		class _OutIt> inline
		_OutIt move(_InIt _First, _InIt _Last,
			_OutIt _Dest)
	{
		_Adl_verify_range(_First, _Last);
		const auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		const auto _UDest = _Get_unwrapped_n(_Dest, _Idl_distance<_InIt>(_UFirst, _ULast));
		_Seek_wrapped(_Dest,
			_Move_unchecked(_UFirst, _ULast, _UDest));
		return (_Dest);
	}

	template<class _InIt,
		class _DestTy,
		size_t _DestSize> inline
		_DestTy *move(_InIt _First, _InIt _Last, _DestTy(&_Dest)[_DestSize])
	{
		return (::std::move(_First, _Last, _Array_iterator<_DestTy, _DestSize>(_Dest))._Unwrapped());
	}

	template<class _BidIt1,
		class _BidIt2> inline
		_BidIt2 _Move_backward_unchecked1(_BidIt1 _First, _BidIt1 _Last,
			_BidIt2 _Dest, _General_ptr_iterator_tag)
	{
		while (_First != _Last)
			*--_Dest = ::std::move(*--_Last);
		return (_Dest);
	}

	template<class _BidIt1,
		class _BidIt2> inline
		_BidIt2 _Move_backward_unchecked1(_BidIt1 _First, _BidIt1 _Last,
			_BidIt2 _Dest, _Trivially_copyable_ptr_iterator_tag)
	{
		return (_Copy_backward_memmove(_First, _Last, _Dest));
	}

	template<class _BidIt1,
		class _BidIt2> inline
		_BidIt2 _Move_backward_unchecked(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest)
	{

		return (_Move_backward_unchecked1(_First, _Last,
			_Dest, _Ptr_move_cat(_First, _Dest)));
	}

	template<class _BidIt1,
		class _BidIt2> inline
		_BidIt2 move_backward(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest)
	{
		_Adl_verify_range(_First, _Last);
		const auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		const auto _UDest = _Get_unwrapped_n(_Dest, -_Idl_distance<_BidIt1>(_UFirst, _ULast));
		_Seek_wrapped(_Dest, _Move_backward_unchecked(_UFirst, _ULast, _UDest));
		return (_Dest);
	}

	template<class _Ty>
	struct _Is_character
		: false_type
	{
	};

	template<>
	struct _Is_character<char>
		: true_type
	{
	};

	template<>
	struct _Is_character<signed char>
		: true_type
	{
	};

	template<>
	struct _Is_character<unsigned char>
		: true_type
	{
	};

	template<class _FwdIt,
		class _Ty>
		struct _Fill_memset_is_safe_helper
	{
		using _Value_type = _Iter_value_t<_FwdIt>;

		using _Raw_ty = _Unwrap_enum_t<_Ty>;
		using _Raw_value_type = _Unwrap_enum_t<_Value_type>;

		using type = bool_constant<conjunction_v<
			is_pointer<_FwdIt>,
			disjunction<
			conjunction<
			_Is_character<_Raw_ty>,
			_Is_character<_Raw_value_type>>,
			conjunction<
			is_same<bool, _Raw_ty>,
			is_same<bool, _Raw_value_type>>>,
			is_convertible<_Ty, _Value_type>>>;
	};

	template<class _FwdIt,
		class _Ty> inline
		typename _Fill_memset_is_safe_helper<_FwdIt, _Ty>::type
		_Fill_memset_is_safe(const _FwdIt&, const _Ty&)
	{
		return {};
	}

	template<class _FwdIt,
		class _Ty> inline
		void _Fill_unchecked1(_FwdIt _First, _FwdIt _Last, const _Ty& _Val, false_type)
	{
		for (; _First != _Last; ++_First)
			*_First = _Val;
	}

	template<class _FwdIt,
		class _Ty> inline
		void _Fill_unchecked1(_FwdIt _First, _FwdIt _Last, const _Ty& _Val, true_type)
	{
		::memset(_First, static_cast<unsigned char>(_Val), static_cast<size_t>(_Last - _First));
	}

	template<class _FwdIt,
		class _Ty> inline
		void _Fill_unchecked(_FwdIt _First, _FwdIt _Last, const _Ty& _Val)
	{
		_Fill_unchecked1(_First, _Last, _Val, _Fill_memset_is_safe(_First, _Val));
	}

	template<class _FwdIt,
		class _Ty> inline
		void fill(_FwdIt _First, _FwdIt _Last, const _Ty& _Val)
	{
		_Adl_verify_range(_First, _Last);
		_Fill_unchecked(_Get_unwrapped(_First), _Get_unwrapped(_Last), _Val);
	}

	template<class _OutIt,
		class _Diff,
		class _Ty> inline
		_OutIt _Fill_n_unchecked2(_OutIt _Dest, _Diff _Count, const _Ty& _Val, false_type)
	{
		for (; 0 < _Count; --_Count, (void)++_Dest)
			*_Dest = _Val;
		return (_Dest);
	}

	template<class _OutIt,
		class _Diff,
		class _Ty> inline
		_OutIt _Fill_n_unchecked2(_OutIt _Dest, _Diff _Count, const _Ty& _Val, true_type)
	{
		::memset(_Dest, static_cast<unsigned char>(_Val), static_cast<size_t>(_Count));
		return (_Dest + _Count);
	}

	template<class _OutIt,
		class _Diff,
		class _Ty> inline
		_OutIt fill_n(_OutIt _Dest, _Diff _Count_raw, const _Ty& _Val)
	{
		const _Algorithm_int_t<_Diff> _Count = _Count_raw;
		if (0 < _Count)
		{
			const auto _UDest = _Get_unwrapped_n(_Dest, _Count);
			_Seek_wrapped(_Dest,
				_Fill_n_unchecked2(_UDest, _Count, _Val, _Fill_memset_is_safe(_UDest, _Val)));
		}

		return (_Dest);
	}

	template<class _Elem1,
		class _Elem2>
		struct _Value_equality_is_bitwise_equality
		: bool_constant<static_cast<_Elem1>(-1) == static_cast<_Elem2>(-1)>
	{

	};

	template<class _Elem1,
		class _Elem2,
		class _Pr>
		struct _Equal_memcmp_is_safe_helper
		: false_type
	{

	};

	template<class _Elem1,
		class _Elem2>
		struct _Equal_memcmp_is_safe_helper<_Elem1, _Elem2, equal_to<>>
		: bool_constant<conjunction_v<
		_Is_same_size<_Elem1, _Elem2>,
		_Is_nonbool_integral<_Elem1>,
		_Is_nonbool_integral<_Elem2>,
		negation<is_volatile<_Elem1>>,
		negation<is_volatile<_Elem2>>,

		_Value_equality_is_bitwise_equality<_Elem1, _Elem2>
		>>
	{
	};

	template<class _Elem1,
		class _Elem2>
		struct _Equal_memcmp_is_safe_helper<_Elem1 *, _Elem2 *, equal_to<>>
		: is_same<remove_cv_t<_Elem1>, remove_cv_t<_Elem2>>::type
	{
	};

	template<class _Elem>
	struct _Equal_memcmp_is_safe_helper<_Elem, _Elem, _Char_traits_eq<char_traits<_Elem>>>
		: _Equal_memcmp_is_safe_helper<_Elem, _Elem, equal_to<>>::type
	{
	};

	template<class _Elem>
	struct _Equal_memcmp_is_safe_helper<_Elem, _Elem, equal_to<_Elem>>
		: _Equal_memcmp_is_safe_helper<_Elem, _Elem, equal_to<>>::type
	{

	};

	template<class _Iter1,
		class _Iter2,
		class _Pr> inline
		false_type _Equal_memcmp_is_safe(const _Iter1&, const _Iter2&, const _Pr&)
	{
		return {};
	}

	template<class _Obj1,
		class _Obj2,
		class _Pr> inline
		typename _Equal_memcmp_is_safe_helper<
		remove_const_t<_Obj1>,
		remove_const_t<_Obj2>,
		_Pr>::type
		_Equal_memcmp_is_safe(_Obj1 * const&, _Obj2 * const&, const _Pr&)
	{
		return {};
	}

	template<class _InIt1,
		class _InIt2,
		class _Pr> inline
		bool _Equal_unchecked1(_InIt1 _First1, const _InIt1 _Last1,
			_InIt2 _First2, _Pr _Pred, false_type)
	{
		for (; _First1 != _Last1; ++_First1, (void)++_First2)
		{
			if (!_Pred(*_First1, *_First2))
			{
				return (false);
			}
		}

		return (true);
	}

	template<class _InIt1,
		class _InIt2,
		class _Pr> inline
		bool _Equal_unchecked1(const _InIt1 _First1, const _InIt1 _Last1,
			const _InIt2 _First2, _Pr, true_type)
	{
		const auto _First1_ch = reinterpret_cast<const char *>(_First1);
		const auto _First2_ch = reinterpret_cast<const char *>(_First2);
		const auto _Count = static_cast<size_t>(reinterpret_cast<const char *>(_Last1) - _First1_ch);
		return (::memcmp(_First1_ch, _First2_ch, _Count) == 0);
	}

	template<class _InIt1,
		class _InIt2,
		class _Pr> inline
		bool _Equal_unchecked(const _InIt1 _First1, const _InIt1 _Last1,
			const _InIt2 _First2, _Pr _Pred)
	{
		return (_Equal_unchecked1(_First1, _Last1, _First2, _Pred,
			_Equal_memcmp_is_safe(_First1, _First2, _Pred)));
	}

	template<class _InIt1,
		class _InIt2,
		class _Pr>
		inline bool equal(const _InIt1 _First1, const _InIt1 _Last1,
			const _InIt2 _First2, _Pr _Pred)
	{
		_Adl_verify_range(_First1, _Last1);
		const auto _UFirst1 = _Get_unwrapped(_First1);
		const auto _ULast1 = _Get_unwrapped(_Last1);
		const auto _UFirst2 = _Get_unwrapped_n(_First2, _Idl_distance<_InIt1>(_UFirst1, _ULast1));
		return (_Equal_unchecked(_UFirst1, _ULast1, _UFirst2, _Pass_fn(_Pred)));
	}

	template<class _InIt1,
		class _RightTy,
		size_t _RightSize,
		class _Pr,
		enable_if_t<!is_same_v<_RightTy *, _Pr>, int> = 0>
		inline bool equal(const _InIt1 _First1, const _InIt1 _Last1, _RightTy(&_First2)[_RightSize], _Pr _Pred)
	{
		return (::std::equal(_First1, _Last1,
			_Array_iterator<_RightTy, _RightSize>(_First2), _Pass_fn(_Pred)));
	}

	template<class _InIt1,
		class _InIt2>
		inline bool equal(const _InIt1 _First1, const _InIt1 _Last1, const _InIt2 _First2)
	{
		return (::std::equal(_First1, _Last1, _First2, equal_to<>()));
	}

	template<class _InIt1,
		class _RightTy,
		size_t _RightSize>
		inline bool equal(const _InIt1 _First1, const _InIt1 _Last1, _RightTy(&_First2)[_RightSize])
	{
		return (::std::equal(_First1, _Last1, _First2, equal_to<>()));
	}

	template<class _InIt1,
		class _InIt2,
		class _Pr> inline
		bool _Equal_unchecked(_InIt1 _First1, const _InIt1 _Last1,
			_InIt2 _First2, const _InIt2 _Last2, _Pr _Pred,
			input_iterator_tag, input_iterator_tag)
	{

		for (;;)
		{
			if (_First1 == _Last1)
			{
				return (_First2 == _Last2);
			}

			if (_First2 == _Last2)
			{
				return (false);
			}

			if (!_Pred(*_First1, *_First2))
			{
				return (false);
			}

			++_First1;
			++_First2;
		}
	}

	template<class _InIt1,
		class _InIt2,
		class _Pr> inline
		bool _Equal_unchecked(const _InIt1 _First1, const _InIt1 _Last1,
			const _InIt2 _First2, const _InIt2 _Last2, _Pr _Pred,
			random_access_iterator_tag, random_access_iterator_tag)
	{

		if (_Last1 - _First1 != _Last2 - _First2)
		{
			return (false);
		}

		return (_Equal_unchecked(_First1, _Last1, _First2, _Pred));
	}

	template<class _InIt1,
		class _InIt2,
		class _Pr>
		inline bool equal(const _InIt1 _First1, const _InIt1 _Last1,
			const _InIt2 _First2, const _InIt2 _Last2, _Pr _Pred)
	{
		_Adl_verify_range(_First1, _Last1);
		_Adl_verify_range(_First2, _Last2);
		return (_Equal_unchecked(_Get_unwrapped(_First1), _Get_unwrapped(_Last1),
			_Get_unwrapped(_First2), _Get_unwrapped(_Last2), _Pass_fn(_Pred),
			_Iter_cat_t<_InIt1>(), _Iter_cat_t<_InIt2>()));
	}

	template<class _InIt1,
		class _InIt2>
		inline bool equal(const _InIt1 _First1, const _InIt1 _Last1, const _InIt2 _First2, const _InIt2 _Last2)
	{
		return (::std::equal(_First1, _Last1, _First2, _Last2, equal_to<>()));
	}

	template<class _Elem1,
		class _Elem2,
		class _FTy>
		struct _Lex_compare_check_element_types_helper
		: bool_constant<conjunction_v<
		_Is_character<_Elem1>,
		_Is_character<_Elem2>,
		_Is_character<_FTy>,
		is_unsigned<_FTy>
		>>
	{
	};

	template<class _Elem1,
		class _Elem2>
		struct _Lex_compare_check_element_types_helper<_Elem1, _Elem2, void>
		: bool_constant<conjunction_v<
		_Is_character<_Elem1>,
		_Is_character<_Elem2>,
		is_unsigned<_Elem1>,
		is_unsigned<_Elem2>
		>>
	{
	};

	template<class _Memcmp_pr>
	struct _Lex_compare_optimize
	{
	};

	template<class _Memcmp_pr,
		class _Obj1,
		class _Obj2,
		class _FTy>
		using _Lex_compare_check_element_types = _Lex_compare_optimize<conditional_t<
		_Lex_compare_check_element_types_helper<remove_const_t<_Obj1>, remove_const_t<_Obj2>, _FTy>::value,
		_Memcmp_pr, void>>;

	template<class _InIt1,
		class _InIt2,
		class _Pr> inline
		_Lex_compare_optimize<void> _Lex_compare_memcmp_classify(const _InIt1&, const _InIt2&, const _Pr&)
	{
		return {};
	}

	template<class _Obj1,
		class _Obj2,
		class _FTy> inline
		_Lex_compare_check_element_types<less<int>, _Obj1, _Obj2, _FTy>
		_Lex_compare_memcmp_classify(_Obj1 * const&, _Obj2 * const&, const less<_FTy>&)
	{
		return {};
	}

	template<class _Obj1,
		class _Obj2,
		class _FTy> inline
		_Lex_compare_check_element_types<greater<int>, _Obj1, _Obj2, _FTy>
		_Lex_compare_memcmp_classify(_Obj1 * const&, _Obj2 * const&, const greater<_FTy>&)
	{
		return {};
	}

	template<class _InIt1,
		class _InIt2,
		class _Pr> inline
		bool _Lex_compare_unchecked(_InIt1 _First1, _InIt1 _Last1,
			_InIt2 _First2, _InIt2 _Last2, _Pr _Pred, _Lex_compare_optimize<void>)
	{
		for (; _First1 != _Last1 && _First2 != _Last2; ++_First1, (void)++_First2)
		{
			if (_Debug_lt_pred(_Pred, *_First1, *_First2))
				return (true);
			else if (_Pred(*_First2, *_First1))
				return (false);
		}

		return (_First1 == _Last1 && _First2 != _Last2);
	}

	template<class _InIt1,
		class _InIt2,
		class _Pr,
		class _Memcmp_pr> inline
		bool _Lex_compare_unchecked(_InIt1 _First1, _InIt1 _Last1,
			_InIt2 _First2, _InIt2 _Last2, _Pr, _Lex_compare_optimize<_Memcmp_pr>)
	{
		const auto _Num1 = static_cast<size_t>(_Last1 - _First1);
		const auto _Num2 = static_cast<size_t>(_Last2 - _First2);
		const int _Ans = ::memcmp(_First1, _First2, _Num1 < _Num2 ? _Num1 : _Num2);
		return (_Memcmp_pr{}(_Ans, 0) || (_Ans == 0 && _Num1 < _Num2));
	}

	template<class _InIt1,
		class _InIt2,
		class _Pr>
		inline bool lexicographical_compare(_InIt1 _First1, _InIt1 _Last1,
			_InIt2 _First2, _InIt2 _Last2, _Pr _Pred)
	{
		_Adl_verify_range(_First1, _Last1);
		_Adl_verify_range(_First2, _Last2);
		const auto _UFirst1 = _Get_unwrapped(_First1);
		const auto _ULast1 = _Get_unwrapped(_Last1);
		const auto _UFirst2 = _Get_unwrapped(_First2);
		const auto _ULast2 = _Get_unwrapped(_Last2);
		return (_Lex_compare_unchecked(_UFirst1, _ULast1, _UFirst2, _ULast2, _Pass_fn(_Pred),
			_Lex_compare_memcmp_classify(_UFirst1, _UFirst2, _Pred)));
	}

	template<class _InIt1,
		class _InIt2>
		inline bool lexicographical_compare(_InIt1 _First1, _InIt1 _Last1,
			_InIt2 _First2, _InIt2 _Last2)
	{
		return (::std::lexicographical_compare(_First1, _Last1,
			_First2, _Last2, less<>()));
	}

	template<class _Ty> inline
		bool _Within_limits(const _Ty& _Val, true_type, true_type, _Any_tag)
	{
		return ((-128) <= _Val && _Val <= 127);
	}

	template<class _Ty> inline
		bool _Within_limits(const _Ty& _Val, true_type, false_type, true_type)
	{
		return (_Val <= 127 || static_cast<_Ty>((-128)) <= _Val);
	}

	template<class _Ty> inline
		bool _Within_limits(const _Ty& _Val, true_type, false_type, false_type)
	{
		return (_Val <= 127);
	}

	template<class _Ty> inline
		bool _Within_limits(const _Ty& _Val, false_type, true_type, _Any_tag)
	{
		return (0 <= _Val && _Val <= 0xff);
	}

	template<class _Ty> inline
		bool _Within_limits(const _Ty& _Val, false_type, false_type, _Any_tag)
	{
		return (_Val <= 0xff);
	}

	template<class _InIt,
		class _Ty> inline
		bool _Within_limits(_InIt, const _Ty& _Val)
	{
		using _Elem = remove_pointer_t<_InIt>;
		return (_Within_limits(_Val, is_signed<_Elem>{}, is_signed<_Ty>{},
			bool_constant<-1 == static_cast<_Ty>(-1)>{}));
	}

	template<class _InIt> inline
		bool _Within_limits(_InIt, const bool&)
	{
		return (true);
	}

	template<class _InIt,
		class _Ty> inline
		_InIt _Find_unchecked1(_InIt _First, const _InIt _Last, const _Ty& _Val, true_type)
	{
		if (!_Within_limits(_First, _Val))
		{
			return (_Last);
		}

		_First = static_cast<_InIt>(::memchr(
			_First, static_cast<unsigned char>(_Val), static_cast<size_t>(_Last - _First)));
		return (_First ? _First : _Last);
	}

	template<class _InIt,
		class _Ty> inline
		_InIt _Find_unchecked1(_InIt _First, const _InIt _Last, const _Ty& _Val, false_type)
	{
		for (; _First != _Last; ++_First)
			if (*_First == _Val)
				break;
		return (_First);
	}

	template<class _InIt,
		class _Ty> inline
		_InIt _Find_unchecked(const _InIt _First, const _InIt _Last, const _Ty& _Val)
	{

		using _Memchr_opt = bool_constant<is_integral_v<_Ty> && _Is_any_of_v<_InIt,
			char *, signed char *, unsigned char *, const char *, const signed char *, const unsigned char *>>;

		return (_Find_unchecked1(_First, _Last, _Val, _Memchr_opt{}));
	}

	template<class _InIt,
		class _Ty>
		inline _InIt find(_InIt _First, const _InIt _Last, const _Ty& _Val)
	{
		_Adl_verify_range(_First, _Last);
		_Seek_wrapped(_First,
			_Find_unchecked(_Get_unwrapped(_First), _Get_unwrapped(_Last), _Val));
		return (_First);
	}

	template<class _InIt,
		class _Ty,
		class _Pr> inline
		_InIt _Find_pr(_InIt _First, _InIt _Last, const _Ty& _Val, _Pr _Pred)
	{
		for (; _First != _Last; ++_First)
		{
			if (_Pred(*_First, _Val))
			{
				break;
			}
		}

		return (_First);
	}

	template<class _InIt,
		class _Ty>
		inline _Iter_diff_t<_InIt> count(const _InIt _First, const _InIt _Last, const _Ty& _Val)
	{
		_Adl_verify_range(_First, _Last);
		auto _UFirst = _Get_unwrapped(_First);
		const auto _ULast = _Get_unwrapped(_Last);
		_Iter_diff_t<_InIt> _Count = 0;

		for (; _UFirst != _ULast; ++_UFirst)
		{
			if (*_UFirst == _Val)
			{
				++_Count;
			}
		}

		return (_Count);
	}

	template<class _InIt,
		class _Ty,
		class _Pr> inline
		_Iter_diff_t<_InIt> _Count_pr(_InIt _First, _InIt _Last, const _Ty& _Val, _Pr _Pred)
	{
		_Iter_diff_t<_InIt> _Count = 0;

		for (; _First != _Last; ++_First)
		{
			if (_Pred(*_First, _Val))
			{
				++_Count;
			}
		}

		return (_Count);
	}

	template<class _FwdIt1,
		class _FwdIt2,
		class _Pr> inline
		void _Trim_matching_suffixes(_FwdIt1&, _FwdIt2&, _Pr,
			forward_iterator_tag, forward_iterator_tag)
	{
	}

	template<class _FwdIt1,
		class _FwdIt2,
		class _Pr> inline
		void _Trim_matching_suffixes(_FwdIt1& _Last1, _FwdIt2& _Last2, _Pr _Pred,
			bidirectional_iterator_tag, bidirectional_iterator_tag)
	{

		do
		{
			--_Last1;
			--_Last2;
		} while (_Pred(*_Last1, *_Last2));
		++_Last1;
		++_Last2;
	}

	template<class _FwdIt1,
		class _FwdIt2,
		class _Pr> inline
		bool _Check_match_counts(_FwdIt1 _First1, _FwdIt1 _Last1,
			_FwdIt2 _First2, _FwdIt2 _Last2, _Pr _Pred)
	{
		_Trim_matching_suffixes(_Last1, _Last2, _Pred,
			_Iter_cat_t<_FwdIt1>(), _Iter_cat_t<_FwdIt2>());
		for (_FwdIt1 _Next1 = _First1; _Next1 != _Last1; ++_Next1)
		{
			if (_Next1 == _Find_pr(_First1, _Next1, *_Next1, _Pred))
			{
				_Iter_diff_t<_FwdIt2> _Count2 = _Count_pr(_First2, _Last2, *_Next1, _Pred);
				if (_Count2 == 0)
				{
					return (false);
				}

				_FwdIt1 _Skip1 = _Next_iter(_Next1);
				_Iter_diff_t<_FwdIt1> _Count1 = _Count_pr(_Skip1, _Last1, *_Next1, _Pred) + 1;
				if (_Count2 != _Count1)
				{
					return (false);
				}
			}
		}

		return (true);
	}

	template<class _FwdIt1,
		class _FwdIt2,
		class _Pr> inline
		bool _Is_permutation_unchecked(_FwdIt1 _First1, _FwdIt1 _Last1, _FwdIt2 _First2, _Pr _Pred)
	{
		for (; _First1 != _Last1; ++_First1, (void)++_First2)
		{
			if (!_Pred(*_First1, *_First2))
			{

				auto _Last2 = ::std::next(_First2, static_cast<_Iter_diff_t<_FwdIt2>>(::std::distance(_First1, _Last1)));
				return (_Check_match_counts(_First1, _Last1, _First2, _Last2, _Pred));
			}
		}

		return (true);
	}

	template<class _FwdIt1,
		class _FwdIt2,
		class _Pr>
		inline bool is_permutation(_FwdIt1 _First1, _FwdIt1 _Last1,
			_FwdIt2 _First2, _Pr _Pred)
	{
		_Adl_verify_range(_First1, _Last1);
		const auto _UFirst1 = _Get_unwrapped(_First1);
		const auto _ULast1 = _Get_unwrapped(_Last1);
		const auto _UFirst2 = _Get_unwrapped_n(_First2, _Idl_distance<_FwdIt1>(_UFirst1, _ULast1));
		return (_Is_permutation_unchecked(_UFirst1, _ULast1, _UFirst2, _Pass_fn(_Pred)));
	}

	template<class _FwdIt1,
		class _RightTy,
		size_t _RightSize,
		class _Pr,
		class = enable_if_t<!is_same_v<_RightTy *, _Pr>>>
		inline bool is_permutation(_FwdIt1 _First1, _FwdIt1 _Last1,
			_RightTy(&_First2)[_RightSize], _Pr _Pred)
	{
		return (::std::is_permutation(_First1, _Last1,
			_Array_iterator<_RightTy, _RightSize>(_First2), _Pass_fn(_Pred)));
	}

	template<class _FwdIt1,
		class _FwdIt2> inline
		bool is_permutation(_FwdIt1 _First1, _FwdIt1 _Last1,
			_FwdIt2 _First2)
	{
		return (::std::is_permutation(_First1, _Last1,
			_First2, equal_to<>()));
	}

	template<class _FwdIt1,
		class _RightTy,
		size_t _RightSize>
		inline bool is_permutation(_FwdIt1 _First1, _FwdIt1 _Last1, _RightTy(&_First2)[_RightSize])
	{
		return (::std::is_permutation(_First1, _Last1, _First2, equal_to<>()));
	}

	template<class _FwdIt1,
		class _FwdIt2,
		class _Pr> inline
		bool _Is_permutation_unchecked(_FwdIt1 _First1, _FwdIt1 _Last1,
			_FwdIt2 _First2, _FwdIt2 _Last2, _Pr _Pred,
			forward_iterator_tag, forward_iterator_tag)
	{

		for (; _First1 != _Last1 && _First2 != _Last2; ++_First1, (void)++_First2)
		{
			if (!_Pred(*_First1, *_First2))
			{
				if (::std::distance(_First1, _Last1) == ::std::distance(_First2, _Last2))
				{
					return (_Check_match_counts(_First1, _Last1, _First2, _Last2, _Pred));
				}
				else
				{
					return (false);
				}
			}
		}

		return (_First1 == _Last1 && _First2 == _Last2);
	}

	template<class _FwdIt1,
		class _FwdIt2,
		class _Pr> inline
		bool _Is_permutation_unchecked(_FwdIt1 _First1, _FwdIt1 _Last1,
			_FwdIt2 _First2, _FwdIt2 _Last2, _Pr _Pred,
			random_access_iterator_tag, random_access_iterator_tag)
	{

		if (_Last1 - _First1 != _Last2 - _First2)
		{
			return (false);
		}

		return (_Is_permutation_unchecked(_First1, _Last1, _First2, _Pred));
	}

	template<class _FwdIt1,
		class _FwdIt2,
		class _Pr>
		inline bool is_permutation(_FwdIt1 _First1, _FwdIt1 _Last1,
			_FwdIt2 _First2, _FwdIt2 _Last2, _Pr _Pred)
	{

		_Adl_verify_range(_First1, _Last1);
		_Adl_verify_range(_First2, _Last2);
		return (_Is_permutation_unchecked(_Get_unwrapped(_First1), _Get_unwrapped(_Last1),
			_Get_unwrapped(_First2), _Get_unwrapped(_Last2), _Pass_fn(_Pred),
			_Iter_cat_t<_FwdIt1>(), _Iter_cat_t<_FwdIt2>()));
	}

	template<class _FwdIt1,
		class _FwdIt2>
		inline bool is_permutation(_FwdIt1 _First1, _FwdIt1 _Last1,
			_FwdIt2 _First2, _FwdIt2 _Last2)
	{
		return (::std::is_permutation(_First1, _Last1, _First2, _Last2, equal_to<>()));
	}

	template<class _BidIt> inline
		void _Reverse_unchecked1(_BidIt _First, _BidIt _Last, integral_constant<size_t, 0>)
	{
		for (; _First != _Last && _First != --_Last; ++_First)
		{
			::std::iter_swap(_First, _Last);
		}
	}

	template<class _BidIt> inline
		void _Reverse_unchecked1(const _BidIt _First, const _BidIt _Last, integral_constant<size_t, 1>)
	{
		__std_reverse_trivially_swappable_1(_First, _Last);
	}

	template<class _BidIt> inline
		void _Reverse_unchecked1(const _BidIt _First, const _BidIt _Last, integral_constant<size_t, 2>)
	{
		__std_reverse_trivially_swappable_2(_First, _Last);
	}

	template<class _BidIt> inline
		void _Reverse_unchecked1(const _BidIt _First, const _BidIt _Last, integral_constant<size_t, 4>)
	{
		__std_reverse_trivially_swappable_4(_First, _Last);
	}

	template<class _BidIt> inline
		void _Reverse_unchecked1(const _BidIt _First, const _BidIt _Last, integral_constant<size_t, 8>)
	{
		__std_reverse_trivially_swappable_8(_First, _Last);
	}

	template<class _BidIt> inline
		void _Reverse_unchecked(const _BidIt _First, const _BidIt _Last)
	{

		using _Elem = remove_pointer_t<_BidIt>;
		constexpr size_t _Opt = is_pointer_v<_BidIt>
			&& _Is_trivially_swappable_v<_Elem>
			&& !is_volatile_v<_Elem>
			&& (sizeof(_Elem) == 1
				|| sizeof(_Elem) == 2
				|| sizeof(_Elem) == 4
				|| sizeof(_Elem) == 8) ? sizeof(_Elem) : 0;

		_Reverse_unchecked1(_First, _Last, integral_constant<size_t, _Opt>{});
	}

	template<class _BidIt> inline
		void reverse(const _BidIt _First, const _BidIt _Last)
	{
		_Adl_verify_range(_First, _Last);
		_Reverse_unchecked(_Get_unwrapped(_First), _Get_unwrapped(_Last));
	}

	template<class _FwdIt> inline
		_FwdIt _Rotate_unchecked1(_FwdIt _First, _FwdIt _Mid, _FwdIt _Last,
			forward_iterator_tag)
	{
		for (_FwdIt _Next = _Mid, _Res = _Last; ; )
		{
			::std::iter_swap(_First, _Next);
			if (++_First == _Mid)
			{
				if (++_Next == _Last)
					return (_Res == _Last ? _Mid : _Res);
				else
					_Mid = _Next;
			}
			else if (++_Next == _Last)
			{
				if (_Res == _Last)
					_Res = _First;
				_Next = _Mid;
			}
		}
	}

	template<class _BidIt> inline
		pair<_BidIt, _BidIt> _Reverse_until_sentinel_unchecked(
			_BidIt _First, _BidIt _Sentinel, _BidIt _Last)
	{
		while (_First != _Sentinel && _Last != _Sentinel)
		{
			::std::iter_swap(_First, --_Last);
			++_First;
		}

		return (::std::make_pair(_First, _Last));
	}

	template<class _BidIt> inline
		_BidIt _Rotate_unchecked1(_BidIt _First, _BidIt _Mid, _BidIt _Last,
			bidirectional_iterator_tag)
	{
		_Reverse_unchecked(_First, _Mid);
		_Reverse_unchecked(_Mid, _Last);
		pair<_BidIt, _BidIt> _Tmp = _Reverse_until_sentinel_unchecked(_First, _Mid, _Last);
		_Reverse_unchecked(_Tmp.first, _Tmp.second);
		return (_Mid != _Tmp.first ? _Tmp.first : _Tmp.second);
	}

	template<class _RanIt> inline
		_RanIt _Rotate_unchecked1(_RanIt _First, _RanIt _Mid, _RanIt _Last,
			random_access_iterator_tag)
	{
		_Reverse_unchecked(_First, _Mid);
		_Reverse_unchecked(_Mid, _Last);
		_Reverse_unchecked(_First, _Last);
		return (_First + (_Last - _Mid));
	}

	template<class _FwdIt> inline
		_FwdIt _Rotate_unchecked(_FwdIt _First, _FwdIt _Mid, _FwdIt _Last)
	{
		if (_First == _Mid)
			return (_Last);
		if (_Mid == _Last)
			return (_First);
		return (_Rotate_unchecked1(_First, _Mid, _Last, _Iter_cat_t<_FwdIt>()));
	}

	template<class _FwdIt> inline
		_FwdIt rotate(_FwdIt _First, _FwdIt _Mid, _FwdIt _Last)
	{

		_Adl_verify_range(_First, _Mid);
		_Adl_verify_range(_Mid, _Last);
		_Seek_wrapped(_First,
			_Rotate_unchecked(_Get_unwrapped(_First), _Get_unwrapped(_Mid),
				_Get_unwrapped(_Last)));
		return (_First);
	}

	template<class _FwdIt,
		class _Ty,
		class _Pr>
		inline _FwdIt lower_bound(_FwdIt _First, const _FwdIt _Last,
			const _Ty& _Val, _Pr _Pred)
	{
		_Adl_verify_range(_First, _Last);
		auto _UFirst = _Get_unwrapped(_First);
		_Iter_diff_t<_FwdIt> _Count = ::std::distance(_UFirst, _Get_unwrapped(_Last));

		while (0 < _Count)
		{
			const _Iter_diff_t<_FwdIt> _Count2 = _Count >> 1;
			const auto _UMid = ::std::next(_UFirst, _Count2);
			if (_Pred(*_UMid, _Val))
			{
				_UFirst = _Next_iter(_UMid);
				_Count -= _Count2 + 1;
			}
			else
			{
				_Count = _Count2;
			}
		}

		_Seek_wrapped(_First, _UFirst);
		return (_First);
	}

	template<class _Diff,
		class _Urng>
		class _Rng_from_urng
	{
	public:
		using _Ty0 = make_unsigned_t<_Diff>;
		using _Ty1 = typename _Urng::result_type;

		using _Udiff = conditional_t < sizeof(_Ty1) < sizeof(_Ty0), _Ty0, _Ty1 > ;

		explicit _Rng_from_urng(_Urng& _Func)
			: _Ref(_Func), _Bits(8 * sizeof(_Udiff)), _Bmask(_Udiff(-1))
		{
			for (; (_Urng::max)() - (_Urng::min)() < _Bmask; _Bmask >>= 1)
				--_Bits;
		}

		_Diff operator()(_Diff _Index)
		{
			for (;;)
			{
				_Udiff _Ret = 0;
				_Udiff _Mask = 0;

				while (_Mask < _Udiff(_Index - 1))
				{
					_Ret <<= _Bits - 1;
					_Ret <<= 1;
					_Ret |= _Get_bits();
					_Mask <<= _Bits - 1;
					_Mask <<= 1;
					_Mask |= _Bmask;
				}

				if (_Ret / _Index < _Mask / _Index
					|| _Mask % _Index == _Udiff(_Index - 1))
					return (static_cast<_Diff>(_Ret % _Index));
			}
		}

		_Udiff _Get_all_bits()
		{
			_Udiff _Ret = 0;

			for (size_t _Num = 0; _Num < 8 * sizeof(_Udiff);
				_Num += _Bits)
			{
				_Ret <<= _Bits - 1;
				_Ret <<= 1;
				_Ret |= _Get_bits();
			}

			return (_Ret);
		}

		_Rng_from_urng(const _Rng_from_urng&) = delete;
		_Rng_from_urng& operator=(const _Rng_from_urng&) = delete;

	private:
		_Udiff _Get_bits()
		{
			for (;;)
			{
				_Udiff _Val = _Ref() - (_Urng::min)();

				if (_Val <= _Bmask)
					return (_Val);
			}
		}

		_Urng& _Ref;
		size_t _Bits;
		_Udiff _Bmask;
	};

	template<class _Elem>
	class __declspec(dllimport) _Yarn
	{
	public:
		_Yarn()
			: _Myptr(nullptr), _Nul(0)
		{
		}

		_Yarn(const _Yarn& _Right)
			: _Myptr(nullptr), _Nul(0)
		{
			*this = _Right;
		}

		_Yarn(const _Elem * _Right)
			: _Myptr(nullptr), _Nul(0)
		{
			*this = _Right;
		}

		_Yarn&  operator=(const _Yarn& _Right)
		{
			return (*this = _Right._Myptr);
		}

		_Yarn&  operator=(const _Elem * _Right)
		{
			if (_Myptr != _Right)
			{
				_Tidy();

				if (_Right != nullptr)
				{
					const _Elem *_Ptr = _Right;
					while (*_Ptr != (_Elem)0)
					{
						++_Ptr;
					}

					const auto _Count = (++_Ptr - _Right) * sizeof(_Elem);

					_Myptr = (_Elem *)_malloc_dbg(_Count, 2,
						"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xutility", 4125);

					if (_Myptr != nullptr)
					{
						::memcpy(_Myptr, _Right, _Count);
					}
				}
			}

			return (*this);
		}

		~_Yarn() noexcept
		{
			_Tidy();
		}

		bool  empty() const
		{
			return (_Myptr == nullptr);
		}

		const _Elem * c_str() const
		{
			return (_Myptr != nullptr ? _Myptr : &_Nul);
		}

		bool  _Empty() const
		{
			return (_Myptr == nullptr);
		}

		const _Elem * _C_str() const
		{
			return (_Myptr != nullptr ? _Myptr : &_Nul);
		}

	private:
		void  _Tidy()
		{
			if (_Myptr != nullptr)

				_free_dbg(_Myptr, 2);

			_Myptr = nullptr;
		}

		_Elem * _Myptr;
		_Elem _Nul;
	};

	template<class _Container>
	class back_insert_iterator
	{
	public:
		using iterator_category = output_iterator_tag;
		using value_type = void;
		using difference_type = void;
		using pointer = void;
		using reference = void;

		using container_type = _Container;

		explicit back_insert_iterator(_Container& _Cont)
			: container(::std::addressof(_Cont))
		{
		}

		back_insert_iterator& operator=(const typename _Container::value_type& _Val)
		{
			container->push_back(_Val);
			return (*this);
		}

		back_insert_iterator& operator=(typename _Container::value_type&& _Val)
		{
			container->push_back(::std::move(_Val));
			return (*this);
		}

		back_insert_iterator& operator*()
		{
			return (*this);
		}

		back_insert_iterator& operator++()
		{
			return (*this);
		}

		back_insert_iterator operator++(int)
		{
			return (*this);
		}

	protected:
		_Container *container;
	};

	template<class _Container>
	inline back_insert_iterator<_Container> back_inserter(_Container& _Cont)
	{
		return (back_insert_iterator<_Container>(_Cont));
	}

	template<class _Ty,
		class _Alloc,
		class = void>
		struct _Has_allocator_type
		: false_type
	{
	};

	template<class _Ty,
		class _Alloc>
		struct _Has_allocator_type<_Ty, _Alloc, void_t<typename _Ty::allocator_type>>
		: is_convertible<_Alloc, typename _Ty::allocator_type>::type
	{
	};

	struct allocator_arg_t
	{
		explicit allocator_arg_t() = default;
	};

	constexpr allocator_arg_t allocator_arg{};

	[[noreturn]]  void __cdecl _Xbad_alloc();
	[[noreturn]]  void __cdecl _Xinvalid_argument(const char *);
	[[noreturn]]  void __cdecl _Xlength_error(const char *);
	[[noreturn]]  void __cdecl _Xout_of_range(const char *);
	[[noreturn]]  void __cdecl _Xoverflow_error(const char *);
	[[noreturn]]  void __cdecl _Xruntime_error(const char *);

	template<class _Ty,
		class _Alloc>
		struct uses_allocator
		: _Has_allocator_type<_Ty, _Alloc>::type
	{
	};

	template<class _Ty,
		class _Alloc>
		constexpr bool uses_allocator_v = uses_allocator<_Ty, _Alloc>::value;

	template<class _Category,
		class _Ty,
		class _Diff = ptrdiff_t,
		class _Pointer = _Ty * ,
		class _Reference = _Ty & >
		struct  iterator
	{
		using iterator_category = _Category;
		using value_type = _Ty;
		using difference_type = _Diff;
		using pointer = _Pointer;
		using reference = _Reference;
	};
}

#pragma warning(pop)
#pragma pack(pop)

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {

	template<bool _Same,
		class _Dest,
		class... _Srcs>
		struct _Tuple_implicit_val0
		: false_type
	{
	};

	template<class... _Dests,
		class... _Srcs>
		struct _Tuple_implicit_val0<true, tuple<_Dests...>, _Srcs...>
		: bool_constant<conjunction_v<
		is_constructible<_Dests, _Srcs>...,
		is_convertible<_Srcs, _Dests>...
		>>
	{
	};

	template<class _Dest,
		class... _Srcs>
		struct _Tuple_implicit_val
		: _Tuple_implicit_val0<tuple_size_v<_Dest> == sizeof...(_Srcs), _Dest, _Srcs...>::type
	{
	};

	template<bool _Same,
		class _Dest,
		class... _Srcs>
		struct _Tuple_explicit_val0
		: false_type
	{
	};

	template<class... _Dests,
		class... _Srcs>
		struct _Tuple_explicit_val0<true, tuple<_Dests...>, _Srcs...>
		: bool_constant<conjunction_v<
		is_constructible<_Dests, _Srcs>...,
		negation<conjunction<is_convertible<_Srcs, _Dests>...>>
		>>
	{
	};

	template<class _Dest,
		class... _Srcs>
		struct _Tuple_explicit_val
		: _Tuple_explicit_val0<tuple_size_v<_Dest> == sizeof...(_Srcs), _Dest, _Srcs...>::type
	{
	};

	template<bool _Same,
		class _Dest,
		class... _Srcs>
		struct _Tuple_constructible_val0
		: false_type
	{
	};

	template<class... _Dests,
		class... _Srcs>
		struct _Tuple_constructible_val0<true, tuple<_Dests...>, _Srcs...>
		: bool_constant<conjunction_v<is_constructible<_Dests, _Srcs>...>>
	{
	};

	template<class _Dest,
		class... _Srcs>
		constexpr bool _Tuple_constructible_v =
		_Tuple_constructible_val0<tuple_size_v<_Dest> == sizeof...(_Srcs), _Dest, _Srcs...>::value;

	template<bool _Same,
		class _Dest,
		class... _Srcs>
		struct _Tuple_nothrow_constructible_val0
		: false_type
	{
	};

	template<class... _Dests,
		class... _Srcs>
		struct _Tuple_nothrow_constructible_val0<true, tuple<_Dests...>, _Srcs...>
		: bool_constant<conjunction_v<is_nothrow_constructible<_Dests, _Srcs>...>>
	{
	};

	template<class _Dest,
		class... _Srcs>
		constexpr bool _Tuple_nothrow_constructible_v =
		_Tuple_nothrow_constructible_val0<tuple_size_v<_Dest> == sizeof...(_Srcs), _Dest, _Srcs...>::value;

	template<bool _Same,
		class _Dest,
		class... _Srcs>
		struct _Tuple_assignable_val0
		: false_type
	{
	};

	template<class... _Dests,
		class... _Srcs>
		struct _Tuple_assignable_val0<true, tuple<_Dests...>, _Srcs...>
		: bool_constant<conjunction_v<is_assignable<_Dests&, _Srcs>...>>
	{
	};

	template<class _Dest,
		class... _Srcs>
		constexpr bool _Tuple_assignable_v =
		_Tuple_assignable_val0<tuple_size_v<_Dest> == sizeof...(_Srcs), _Dest, _Srcs...>::value;

	template<class _Dest,
		class... _Srcs>
		struct _Tuple_assignable_val
		: bool_constant<_Tuple_assignable_v<_Dest, _Srcs...>>
	{
	};

	template<bool _Same,
		class _Dest,
		class... _Srcs>
		struct _Tuple_nothrow_assignable_val0
		: false_type
	{
	};

	template<class... _Dests,
		class... _Srcs>
		struct _Tuple_nothrow_assignable_val0<true, tuple<_Dests...>, _Srcs...>
		: bool_constant<conjunction_v<is_nothrow_assignable<_Dests&, _Srcs>...>>
	{
	};

	template<class _Dest,
		class... _Srcs>
		constexpr bool _Tuple_nothrow_assignable_v =
		_Tuple_nothrow_assignable_val0<tuple_size_v<_Dest> == sizeof...(_Srcs), _Dest, _Srcs...>::value;

	template<class _Myself,
		class... _Other>
		struct _Tuple_convert_copy_val
		: true_type
	{
	};

	template<class _This,
		class _Uty>
		struct _Tuple_convert_copy_val<tuple<_This>, _Uty>
		: bool_constant<!disjunction_v<
		is_same<_This, _Uty>,
		is_constructible<_This, const tuple<_Uty>&>,
		is_convertible<const tuple<_Uty>&, _This>>>
	{
	};

	template<class _Myself,
		class... _Other>
		struct _Tuple_convert_move_val
		: true_type
	{
	};

	template<class _This,
		class _Uty>
		struct _Tuple_convert_move_val<tuple<_This>, _Uty>
		: bool_constant<!disjunction_v<
		is_same<_This, _Uty>,
		is_constructible<_This, tuple<_Uty>>,
		is_convertible<tuple<_Uty>, _This>>>
	{
	};

	template<class _Myself,
		class _This2,
		class... _Rest2>
		struct _Tuple_perfect_val
		: true_type
	{
	};

	template<class _Myself,
		class _This2>
		struct _Tuple_perfect_val<_Myself, _This2>
		: bool_constant<!is_same_v<_Myself, remove_const_t<remove_reference_t<_This2>>>>
	{
	};

	struct _Ignore
	{
		template<class _Ty>
		constexpr const _Ignore& operator=(const _Ty&) const noexcept
		{
			return (*this);
		}
	};

	constexpr _Ignore ignore{};

	template<class _Ty>
	struct _Tuple_val
	{
		constexpr _Tuple_val()
			: _Val()
		{
		}

		template<class _Other>
		constexpr _Tuple_val(_Other&& _Arg)
			: _Val(::std::forward<_Other>(_Arg))
		{
		}

		template<class _Alloc,
			class... _Other,
			enable_if_t<!uses_allocator_v<_Ty, _Alloc>, int> = 0>
			_Tuple_val(const _Alloc&, allocator_arg_t, _Other&&... _Arg)
			: _Val(::std::forward<_Other>(_Arg)...)
		{
		}

		template<class _Alloc,
			class... _Other,
			enable_if_t<conjunction_v<
			uses_allocator<_Ty, _Alloc>,
			is_constructible<_Ty, allocator_arg_t, const _Alloc&, _Other...>
		>, int> = 0>
			_Tuple_val(const _Alloc& _Al, allocator_arg_t, _Other&&... _Arg)
			: _Val(allocator_arg, _Al, ::std::forward<_Other>(_Arg)...)
		{
		}

		template<class _Alloc,
			class... _Other,
			enable_if_t<conjunction_v<
			uses_allocator<_Ty, _Alloc>,
			negation<is_constructible<_Ty, allocator_arg_t, const _Alloc&, _Other...>>
		>, int> = 0>
			_Tuple_val(const _Alloc& _Al, allocator_arg_t, _Other&&... _Arg)
			: _Val(::std::forward<_Other>(_Arg)..., _Al)
		{
		}

		_Ty _Val;
	};

	struct _Exact_args_t
	{
	};

	struct _Unpack_tuple_t
	{
	};

	struct _Alloc_exact_args_t
	{
	};

	struct _Alloc_unpack_tuple_t
	{
	};

	template<class... _Types>
	class tuple;

	template<>
	class tuple<>
	{
	public:
		constexpr tuple() noexcept
		{
		}

		constexpr tuple(const tuple&) noexcept
		{
		}

		template<class _Alloc>
		tuple(allocator_arg_t, const _Alloc&) noexcept
		{
		}

		template<class _Alloc>
		tuple(allocator_arg_t, const _Alloc&, const tuple&) noexcept
		{
		}

		template<class _Tag,
			enable_if_t<is_same_v<_Tag, _Exact_args_t>, int> = 0>
			constexpr tuple(_Tag) noexcept
		{
		}

		template<class _Tag,
			class _Alloc,
			enable_if_t<is_same_v<_Tag, _Alloc_exact_args_t>, int> = 0>
			tuple(_Tag, const _Alloc&) noexcept
		{
		}

		void swap(tuple&) noexcept
		{
		}

		constexpr bool _Equals(const tuple&) const noexcept
		{
			return (true);
		}

		constexpr bool _Less(const tuple&) const noexcept
		{
			return (false);
		}
	};

	template<class _This,
		class... _Rest>
		class tuple<_This, _Rest...>
		: private tuple<_Rest...>
	{
	public:
		typedef _This _This_type;
		typedef tuple<_Rest...> _Mybase;

		template<class _Tag,
			class _This2,
			class... _Rest2,
			enable_if_t<is_same_v<_Tag, _Exact_args_t>, int> = 0>
			constexpr tuple(_Tag, _This2&& _This_arg, _Rest2&&... _Rest_arg)
			: _Mybase(_Exact_args_t{}, ::std::forward<_Rest2>(_Rest_arg)...),
			_Myfirst(::std::forward<_This2>(_This_arg))
		{
		}

		template<class _Tag,
			class _Tpl,
			size_t... _Indices,
			enable_if_t<is_same_v<_Tag, _Unpack_tuple_t>, int> = 0>
			constexpr tuple(_Tag, _Tpl&& _Right, index_sequence<_Indices...>);

		template<class _Tag,
			class _Tpl,
			enable_if_t<is_same_v<_Tag, _Unpack_tuple_t>, int> = 0>
			constexpr tuple(_Tag, _Tpl&& _Right)
			: tuple(_Unpack_tuple_t{}, ::std::forward<_Tpl>(_Right),
				make_index_sequence<tuple_size_v<remove_reference_t<_Tpl>>>{})
		{
		}

		template<class _Tag,
			class _Alloc,
			class _This2,
			class... _Rest2,
			enable_if_t<is_same_v<_Tag, _Alloc_exact_args_t>, int> = 0>
			tuple(_Tag, const _Alloc& _Al, _This2&& _This_arg, _Rest2&&... _Rest_arg)
			: _Mybase(_Alloc_exact_args_t{}, _Al, ::std::forward<_Rest2>(_Rest_arg)...),
			_Myfirst(_Al, allocator_arg, ::std::forward<_This2>(_This_arg))
		{
		}

		template<class _Tag,
			class _Alloc,
			class _Tpl,
			size_t... _Indices,
			enable_if_t<is_same_v<_Tag, _Alloc_unpack_tuple_t>, int> = 0> inline
			tuple(_Tag, const _Alloc& _Al, _Tpl&& _Right, index_sequence<_Indices...>);

		template<class _Tag,
			class _Alloc,
			class _Tpl,
			enable_if_t<is_same_v<_Tag, _Alloc_unpack_tuple_t>, int> = 0>
			tuple(_Tag, const _Alloc& _Al, _Tpl&& _Right)
			: tuple(_Alloc_unpack_tuple_t{}, _Al, ::std::forward<_Tpl>(_Right),
				make_index_sequence<tuple_size_v<remove_reference_t<_Tpl>>>{})
		{
		}

		template<class _This2 = _This,
			enable_if_t<conjunction_v<
			is_default_constructible<_This2>,
			is_default_constructible<_Rest>...,
			_Is_implicitly_default_constructible<_This2>,
			_Is_implicitly_default_constructible<_Rest>...
		>, int> = 0>
			constexpr tuple()
			noexcept(conjunction_v< is_nothrow_default_constructible<_This2>, is_nothrow_default_constructible<_Rest>... >)

			: _Mybase(), _Myfirst()
		{
		}

		template<class _This2 = _This,
			enable_if_t<conjunction_v<
			is_default_constructible<_This2>,
			is_default_constructible<_Rest>...,
			negation<conjunction<
			_Is_implicitly_default_constructible<_This2>,
			_Is_implicitly_default_constructible<_Rest>...
			>>>, int> = 0>
			constexpr explicit tuple()
			noexcept(conjunction_v< is_nothrow_default_constructible<_This2>, is_nothrow_default_constructible<_Rest>... >)

			: _Mybase(), _Myfirst()
		{
		}

		template<class _This2 = _This,
			enable_if_t<_Tuple_implicit_val<tuple, const _This2&, const _Rest&...>::value, int> = 0>
			constexpr tuple(const _This& _This_arg, const _Rest&... _Rest_arg)
			noexcept(conjunction_v< is_nothrow_copy_constructible<_This2>, is_nothrow_copy_constructible<_Rest>... >)

			: tuple(_Exact_args_t{}, _This_arg, _Rest_arg...)
		{
		}

		template<class _This2 = _This,
			enable_if_t<_Tuple_explicit_val<tuple, const _This2&, const _Rest&...>::value, int> = 0>
			constexpr explicit tuple(const _This& _This_arg, const _Rest&... _Rest_arg)
			noexcept(conjunction_v< is_nothrow_copy_constructible<_This2>, is_nothrow_copy_constructible<_Rest>... >)

			: tuple(_Exact_args_t{}, _This_arg, _Rest_arg...)
		{
		}

		template<class _This2,
			class... _Rest2,
			enable_if_t<conjunction_v<
			_Tuple_perfect_val<tuple, _This2, _Rest2...>,
			_Tuple_implicit_val<tuple, _This2, _Rest2...>
		>, int> = 0>
			constexpr tuple(_This2&& _This_arg, _Rest2&&... _Rest_arg)
			noexcept(_Tuple_nothrow_constructible_v<tuple, _This2, _Rest2...>)
			: tuple(_Exact_args_t{}, ::std::forward<_This2>(_This_arg), ::std::forward<_Rest2>(_Rest_arg)...)
		{
		}

		template<class _This2,
			class... _Rest2,
			enable_if_t<conjunction_v<
			_Tuple_perfect_val<tuple, _This2, _Rest2...>,
			_Tuple_explicit_val<tuple, _This2, _Rest2...>
		>, int> = 0>
			constexpr explicit tuple(_This2&& _This_arg, _Rest2&&... _Rest_arg)
			noexcept(_Tuple_nothrow_constructible_v<tuple, _This2, _Rest2...>)
			: tuple(_Exact_args_t{}, ::std::forward<_This2>(_This_arg), ::std::forward<_Rest2>(_Rest_arg)...)
		{
		}

		tuple(const tuple&) = default;
		tuple(tuple&&) = default;

		template<class... _Other,
			enable_if_t<conjunction_v<
			_Tuple_implicit_val<tuple, const _Other&...>,
			_Tuple_convert_copy_val<tuple, _Other...>
		>, int> = 0>
			constexpr tuple(const tuple<_Other...>& _Right)
			noexcept(_Tuple_nothrow_constructible_v<tuple, const _Other&...>)
			: tuple(_Unpack_tuple_t{}, _Right)
		{
		}

		template<class... _Other,
			enable_if_t<conjunction_v<
			_Tuple_explicit_val<tuple, const _Other&...>,
			_Tuple_convert_copy_val<tuple, _Other...>
		>, int> = 0>
			constexpr explicit tuple(const tuple<_Other...>& _Right)
			noexcept(_Tuple_nothrow_constructible_v<tuple, const _Other&...>)
			: tuple(_Unpack_tuple_t{}, _Right)
		{
		}

		template<class... _Other,
			enable_if_t<conjunction_v<
			_Tuple_implicit_val<tuple, _Other...>,
			_Tuple_convert_move_val<tuple, _Other...>
		>, int> = 0>
			constexpr tuple(tuple<_Other...>&& _Right)
			noexcept(_Tuple_nothrow_constructible_v<tuple, _Other...>)
			: tuple(_Unpack_tuple_t{}, ::std::move(_Right))
		{
		}

		template<class... _Other,
			enable_if_t<conjunction_v<
			_Tuple_explicit_val<tuple, _Other...>,
			_Tuple_convert_move_val<tuple, _Other...>
		>, int> = 0>
			constexpr explicit tuple(tuple<_Other...>&& _Right)
			noexcept(_Tuple_nothrow_constructible_v<tuple, _Other...>)
			: tuple(_Unpack_tuple_t{}, ::std::move(_Right))
		{
		}

		template<class _First,
			class _Second,
			enable_if_t<_Tuple_implicit_val<tuple, const _First&, const _Second&>::value, int> = 0>
			constexpr tuple(const pair<_First, _Second>& _Right)
			noexcept(_Tuple_nothrow_constructible_v<tuple, const _First&, const _Second&>)
			: tuple(_Unpack_tuple_t{}, _Right)
		{
		}

		template<class _First,
			class _Second,
			enable_if_t<_Tuple_explicit_val<tuple, const _First&, const _Second&>::value, int> = 0>
			constexpr explicit tuple(const pair<_First, _Second>& _Right)
			noexcept(_Tuple_nothrow_constructible_v<tuple, const _First&, const _Second&>)
			: tuple(_Unpack_tuple_t{}, _Right)
		{
		}

		template<class _First,
			class _Second,
			enable_if_t<_Tuple_implicit_val<tuple, _First, _Second>::value, int> = 0>
			constexpr tuple(pair<_First, _Second>&& _Right)
			noexcept(_Tuple_nothrow_constructible_v<tuple, _First, _Second>)
			: tuple(_Unpack_tuple_t{}, ::std::move(_Right))
		{
		}

		template<class _First,
			class _Second,
			enable_if_t<_Tuple_explicit_val<tuple, _First, _Second>::value, int> = 0>
			constexpr explicit tuple(pair<_First, _Second>&& _Right)
			noexcept(_Tuple_nothrow_constructible_v<tuple, _First, _Second>)
			: tuple(_Unpack_tuple_t{}, ::std::move(_Right))
		{
		}

		template<class _Alloc,
			class _This2 = _This,
			enable_if_t<conjunction_v<
			is_default_constructible<_This2>,
			is_default_constructible<_Rest>...
		>, int> = 0>
			tuple(allocator_arg_t, const _Alloc& _Al)
			: _Mybase(allocator_arg, _Al), _Myfirst(_Al, allocator_arg)
		{
		}

		template<class _Alloc,
			class _This2 = _This,
			enable_if_t<_Tuple_implicit_val<tuple, const _This2&, const _Rest&...>::value, int> = 0>
			tuple(allocator_arg_t, const _Alloc& _Al,
				const _This& _This_arg, const _Rest&... _Rest_arg)
			: tuple(_Alloc_exact_args_t{}, _Al, _This_arg, _Rest_arg...)
		{
		}

		template<class _Alloc,
			class _This2 = _This,
			enable_if_t<_Tuple_explicit_val<tuple, const _This2&, const _Rest&...>::value, int> = 0>
			explicit tuple(allocator_arg_t, const _Alloc& _Al,
				const _This& _This_arg, const _Rest&... _Rest_arg)
			: tuple(_Alloc_exact_args_t{}, _Al, _This_arg, _Rest_arg...)
		{
		}

		template<class _Alloc,
			class _This2,
			class... _Rest2,
			enable_if_t<conjunction_v<
			_Tuple_perfect_val<tuple, _This2, _Rest2...>,
			_Tuple_implicit_val<tuple, _This2, _Rest2...>
		>, int> = 0>
			tuple(allocator_arg_t, const _Alloc& _Al,
				_This2&& _This_arg, _Rest2&&... _Rest_arg)
			: tuple(_Alloc_exact_args_t{}, _Al, ::std::forward<_This2>(_This_arg), ::std::forward<_Rest2>(_Rest_arg)...)
		{
		}

		template<class _Alloc,
			class _This2,
			class... _Rest2,
			enable_if_t<conjunction_v<
			_Tuple_perfect_val<tuple, _This2, _Rest2...>,
			_Tuple_explicit_val<tuple, _This2, _Rest2...>
		>, int> = 0>
			explicit tuple(allocator_arg_t, const _Alloc& _Al,
				_This2&& _This_arg, _Rest2&&... _Rest_arg)
			: tuple(_Alloc_exact_args_t{}, _Al, ::std::forward<_This2>(_This_arg), ::std::forward<_Rest2>(_Rest_arg)...)
		{
		}

		template<class _Alloc,
			class _This2 = _This,
			enable_if_t<_Tuple_constructible_v<tuple, const _This2&, const _Rest&...>, int> = 0>
			tuple(allocator_arg_t, const _Alloc& _Al,
				const tuple& _Right)
			: tuple(_Alloc_unpack_tuple_t{}, _Al, _Right)
		{
		}

		template<class _Alloc,
			class _This2 = _This,
			enable_if_t<_Tuple_constructible_v<tuple, _This2, _Rest...>, int> = 0>
			tuple(allocator_arg_t, const _Alloc& _Al,
				tuple&& _Right)
			: tuple(_Alloc_unpack_tuple_t{}, _Al, ::std::move(_Right))
		{
		}

		template<class _Alloc,
			class... _Other,
			enable_if_t<conjunction_v<
			_Tuple_implicit_val<tuple, const _Other&...>,
			_Tuple_convert_copy_val<tuple, _Other...>
		>, int> = 0>
			tuple(allocator_arg_t, const _Alloc& _Al,
				const tuple<_Other...>& _Right)
			: tuple(_Alloc_unpack_tuple_t{}, _Al, _Right)
		{
		}

		template<class _Alloc,
			class... _Other,
			enable_if_t<conjunction_v<
			_Tuple_explicit_val<tuple, const _Other&...>,
			_Tuple_convert_copy_val<tuple, _Other...>
		>, int> = 0>
			explicit tuple(allocator_arg_t, const _Alloc& _Al,
				const tuple<_Other...>& _Right)
			: tuple(_Alloc_unpack_tuple_t{}, _Al, _Right)
		{
		}

		template<class _Alloc,
			class... _Other,
			enable_if_t<conjunction_v<
			_Tuple_implicit_val<tuple, _Other...>,
			_Tuple_convert_move_val<tuple, _Other...>
		>, int> = 0>
			tuple(allocator_arg_t, const _Alloc& _Al,
				tuple<_Other...>&& _Right)
			: tuple(_Alloc_unpack_tuple_t{}, _Al, ::std::move(_Right))
		{
		}

		template<class _Alloc,
			class... _Other,
			enable_if_t<conjunction_v<
			_Tuple_explicit_val<tuple, _Other...>,
			_Tuple_convert_move_val<tuple, _Other...>
		>, int> = 0>
			explicit tuple(allocator_arg_t, const _Alloc& _Al,
				tuple<_Other...>&& _Right)
			: tuple(_Alloc_unpack_tuple_t{}, _Al, ::std::move(_Right))
		{
		}

		template<class _Alloc,
			class _First,
			class _Second,
			enable_if_t<_Tuple_implicit_val<tuple, const _First&, const _Second&>::value, int> = 0>
			tuple(allocator_arg_t, const _Alloc& _Al,
				const pair<_First, _Second>& _Right)
			: tuple(_Alloc_unpack_tuple_t{}, _Al, _Right)
		{
		}

		template<class _Alloc,
			class _First,
			class _Second,
			enable_if_t<_Tuple_explicit_val<tuple, const _First&, const _Second&>::value, int> = 0>
			explicit tuple(allocator_arg_t, const _Alloc& _Al,
				const pair<_First, _Second>& _Right)
			: tuple(_Alloc_unpack_tuple_t{}, _Al, _Right)
		{
		}

		template<class _Alloc,
			class _First,
			class _Second,
			enable_if_t<_Tuple_implicit_val<tuple, _First, _Second>::value, int> = 0>
			tuple(allocator_arg_t, const _Alloc& _Al,
				pair<_First, _Second>&& _Right)
			: tuple(_Alloc_unpack_tuple_t{}, _Al, ::std::move(_Right))
		{
		}

		template<class _Alloc,
			class _First,
			class _Second,
			enable_if_t<_Tuple_explicit_val<tuple, _First, _Second>::value, int> = 0>
			explicit tuple(allocator_arg_t, const _Alloc& _Al,
				pair<_First, _Second>&& _Right)
			: tuple(_Alloc_unpack_tuple_t{}, _Al, ::std::move(_Right))
		{
		}

		tuple& operator=(const volatile tuple&) = delete;

		template<class _Myself = tuple,
			class _This2 = _This,
			enable_if_t<conjunction_v<
			is_copy_assignable<_This2>,
			is_copy_assignable<_Rest>...
		>, int> = 0>
			tuple& operator=(_Identity_t<const _Myself&> _Right)
			noexcept(conjunction_v< is_nothrow_copy_assignable<_This2>, is_nothrow_copy_assignable<_Rest>... >)

		{
			_Myfirst._Val = _Right._Myfirst._Val;
			_Get_rest() = _Right._Get_rest();
			return (*this);
		}

		template<class _Myself = tuple,
			class _This2 = _This,
			enable_if_t<conjunction_v<
			is_move_assignable<_This2>,
			is_move_assignable<_Rest>...
		>, int> = 0>
			tuple& operator=(_Identity_t<_Myself&&> _Right)
			noexcept(conjunction_v< is_nothrow_move_assignable<_This2>, is_nothrow_move_assignable<_Rest>... >)

		{
			_Myfirst._Val = ::std::forward<_This>(_Right._Myfirst._Val);
			_Get_rest() = ::std::forward<_Mybase>(_Right._Get_rest());
			return (*this);
		}

		template<class... _Other,
			enable_if_t<conjunction_v<
			negation<is_same<tuple, tuple<_Other...>>>,
			_Tuple_assignable_val<tuple, const _Other&...>
		>, int> = 0>
			tuple& operator=(const tuple<_Other...>& _Right)
			noexcept(_Tuple_nothrow_assignable_v<tuple, const _Other&...>)
		{
			_Myfirst._Val = _Right._Myfirst._Val;
			_Get_rest() = _Right._Get_rest();
			return (*this);
		}

		template<class... _Other,
			enable_if_t<conjunction_v<
			negation<is_same<tuple, tuple<_Other...>>>,
			_Tuple_assignable_val<tuple, _Other...>
		>, int> = 0>
			tuple& operator=(tuple<_Other...>&& _Right)
			noexcept(_Tuple_nothrow_assignable_v<tuple, _Other...>)
		{
			_Myfirst._Val = ::std::forward<typename tuple<_Other...>::_This_type>(_Right._Myfirst._Val);
			_Get_rest() = ::std::forward<typename tuple<_Other...>::_Mybase>(_Right._Get_rest());
			return (*this);
		}

		template<class _First,
			class _Second,
			enable_if_t<_Tuple_assignable_v<tuple, const _First&, const _Second&>, int> = 0>
			tuple& operator=(const pair<_First, _Second>& _Right)
			noexcept(_Tuple_nothrow_assignable_v<tuple, const _First&, const _Second&>)
		{
			_Myfirst._Val = _Right.first;
			_Get_rest()._Myfirst._Val = _Right.second;
			return (*this);
		}

		template<class _First,
			class _Second,
			enable_if_t<_Tuple_assignable_v<tuple, _First, _Second>, int> = 0>
			tuple& operator=(pair<_First, _Second>&& _Right)
			noexcept(_Tuple_nothrow_assignable_v<tuple, _First, _Second>)
		{
			_Myfirst._Val = ::std::forward<_First>(_Right.first);
			_Get_rest()._Myfirst._Val = ::std::forward<_Second>(_Right.second);
			return (*this);
		}

		void swap(tuple& _Right)
			noexcept(conjunction_v<_Is_nothrow_swappable<_This>, _Is_nothrow_swappable<_Rest>...>)

		{
			_Swap_adl(_Myfirst._Val, _Right._Myfirst._Val);
			_Mybase::swap(_Right._Get_rest());
		}

		_Mybase& _Get_rest() noexcept
		{
			return (*this);
		}

		constexpr const _Mybase& _Get_rest() const noexcept
		{
			return (*this);
		}

		template<class... _Other>
		constexpr bool _Equals(const tuple<_Other...>& _Right) const
		{
			return (_Myfirst._Val == _Right._Myfirst._Val
				&& _Mybase::_Equals(_Right._Get_rest()));
		}

		template<class... _Other>
		constexpr bool _Less(const tuple<_Other...>& _Right) const
		{
			return (_Myfirst._Val < _Right._Myfirst._Val
				|| (!(_Right._Myfirst._Val < _Myfirst._Val)
					&& _Mybase::_Less(_Right._Get_rest())));
		}

		_Tuple_val<_This> _Myfirst;
	};

	template<class... _Types1,
		class... _Types2>
		constexpr bool operator==(const tuple<_Types1...>& _Left, const tuple<_Types2...>& _Right)
	{
		static_assert(sizeof...(_Types1) == sizeof...(_Types2), "cannot compare tuples of different sizes");
		return (_Left._Equals(_Right));
	}

	template<class... _Types1,
		class... _Types2>
		constexpr bool operator!=(const tuple<_Types1...>& _Left, const tuple<_Types2...>& _Right)
	{
		return (!(_Left == _Right));
	}

	template<class... _Types1,
		class... _Types2>
		constexpr bool operator<(const tuple<_Types1...>& _Left, const tuple<_Types2...>& _Right)
	{
		static_assert(sizeof...(_Types1) == sizeof...(_Types2), "cannot compare tuples of different sizes");
		return (_Left._Less(_Right));
	}

	template<class... _Types1,
		class... _Types2>
		constexpr bool operator>=(const tuple<_Types1...>& _Left, const tuple<_Types2...>& _Right)
	{
		return (!(_Left < _Right));
	}

	template<class... _Types1,
		class... _Types2>
		constexpr bool operator>(const tuple<_Types1...>& _Left, const tuple<_Types2...>& _Right)
	{
		return (_Right < _Left);
	}

	template<class... _Types1,
		class... _Types2>
		constexpr bool operator<=(const tuple<_Types1...>& _Left, const tuple<_Types2...>& _Right)
	{
		return (!(_Right < _Left));
	}

	template<class... _Types,
		enable_if_t<conjunction_v<_Is_swappable<_Types>...>, int> = 0> inline
		void swap(tuple<_Types...>& _Left, tuple<_Types...>& _Right)
		noexcept(noexcept(_Left.swap(_Right)))
	{
		return (_Left.swap(_Right));
	}

	template<class _Ty,
		class _Tuple>
		struct _Tuple_element;

	template<class _This,
		class... _Rest>
		struct _Tuple_element<_This, tuple<_This, _Rest...>>
	{
		typedef int _Check_type;
		static_assert(is_void_v<typename _Tuple_element<_This, tuple<_Rest...>>::_Check_type>,
			"duplicate type T in get<T>(tuple)");

		typedef _This type;
		typedef tuple<_This, _Rest...> _Ttype;
	};

	template<class _Ty,
		class _This,
		class... _Rest>
		struct _Tuple_element<_Ty, tuple<_This, _Rest...>>
		: _Tuple_element<_Ty, tuple<_Rest...>>
	{
	};

	template<class _Ty>
	struct _Tuple_element<_Ty, tuple<>>
	{
		typedef void _Check_type;
	};

	template<size_t _Index,
		class... _Types>
		constexpr tuple_element_t<_Index, tuple<_Types...>>&
		get(tuple<_Types...>& _Tuple) noexcept
	{
		typedef typename tuple_element<_Index, tuple<_Types...>>::_Ttype _Ttype;
		return (((_Ttype&)_Tuple)._Myfirst._Val);
	}

	template<size_t _Index,
		class... _Types>
		constexpr const tuple_element_t<_Index, tuple<_Types...>>&
		get(const tuple<_Types...>& _Tuple) noexcept
	{
		typedef typename tuple_element<_Index, tuple<_Types...>>::_Ttype _Ttype;
		return (((_Ttype&)_Tuple)._Myfirst._Val);
	}

	template<size_t _Index,
		class... _Types>
		constexpr tuple_element_t<_Index, tuple<_Types...>>&&
		get(tuple<_Types...>&& _Tuple) noexcept
	{
		typedef typename tuple_element<_Index, tuple<_Types...>>::_Ttype _Ttype;
		typedef tuple_element_t<_Index, tuple<_Types...>>&& _RRtype;
		return (::std::forward<_RRtype>(((_Ttype&)_Tuple)._Myfirst._Val));
	}

	template<size_t _Index,
		class... _Types>
		constexpr const tuple_element_t<_Index, tuple<_Types...>>&&
		get(const tuple<_Types...>&& _Tuple) noexcept
	{
		typedef typename tuple_element<_Index, tuple<_Types...>>::_Ttype _Ttype;
		typedef const tuple_element_t<_Index, tuple<_Types...>>&& _RRtype;
		return (::std::forward<_RRtype>(((_Ttype&)_Tuple)._Myfirst._Val));
	}

	template<class _Ty,
		class... _Types>
		constexpr _Ty& get(tuple<_Types...>& _Tuple) noexcept
	{
		typedef typename _Tuple_element<_Ty, tuple<_Types...>>::_Ttype _Ttype;
		return (((_Ttype&)_Tuple)._Myfirst._Val);
	}

	template<class _Ty,
		class... _Types>
		constexpr const _Ty& get(const tuple<_Types...>& _Tuple) noexcept
	{
		typedef typename _Tuple_element<_Ty, tuple<_Types...>>::_Ttype _Ttype;
		return (((_Ttype&)_Tuple)._Myfirst._Val);
	}

	template<class _Ty,
		class... _Types>
		constexpr _Ty&& get(tuple<_Types...>&& _Tuple) noexcept
	{
		typedef typename _Tuple_element<_Ty, tuple<_Types...>>::_Ttype _Ttype;
		return (::std::forward<_Ty&&>(((_Ttype&)_Tuple)._Myfirst._Val));
	}

	template<class _Ty,
		class... _Types>
		constexpr const _Ty&& get(const tuple<_Types...>&& _Tuple) noexcept
	{
		typedef typename _Tuple_element<_Ty, tuple<_Types...>>::_Ttype _Ttype;
		return (::std::forward<const _Ty&&>(((_Ttype&)_Tuple)._Myfirst._Val));
	}

	template<class _This,
		class... _Rest>
		template<class _Tag,
		class _Tpl,
		size_t... _Indices,
		enable_if_t<is_same_v<_Tag, _Unpack_tuple_t>, int>>
		constexpr tuple<_This, _Rest...>::tuple(_Tag, _Tpl&& _Right, index_sequence<_Indices...>)
		: tuple(_Exact_args_t{}, ::std::get<_Indices>(::std::forward<_Tpl>(_Right))...)
	{
	}

	template<class _This,
		class... _Rest>
		template<class _Tag,
		class _Alloc,
		class _Tpl,
		size_t... _Indices,
		enable_if_t<is_same_v<_Tag, _Alloc_unpack_tuple_t>, int>> inline
		tuple<_This, _Rest...>::tuple(_Tag, const _Alloc& _Al, _Tpl&& _Right, index_sequence<_Indices...>)
		: tuple(_Alloc_exact_args_t{}, _Al, ::std::get<_Indices>(::std::forward<_Tpl>(_Right))...)
	{
	}

	template<class... _Types>
	constexpr tuple<_Unrefwrap_t<_Types>...>
		make_tuple(_Types&&... _Args)
	{
		typedef tuple<_Unrefwrap_t<_Types>...> _Ttype;
		return (_Ttype(::std::forward<_Types>(_Args)...));
	}

	template<class... _Types>
	constexpr tuple<_Types&...>
		tie(_Types&... _Args) noexcept
	{
		typedef tuple<_Types&...> _Ttype;
		return (_Ttype(_Args...));
	}

	template<class... _Types>
	constexpr tuple<_Types&&...>
		forward_as_tuple(_Types&&... _Args) noexcept
	{
		return (tuple<_Types&&...>(::std::forward<_Types>(_Args)...));
	}

	template<class _Seq_type1,
		class _Seq_type2>
		struct _Cat_sequences;

	template<size_t... _Indexes1,
		size_t... _Indexes2>
		struct _Cat_sequences<index_sequence<_Indexes1...>,
		index_sequence<_Indexes2...>>
	{
		typedef index_sequence<_Indexes1..., _Indexes2...> type;
	};

	template<class _Ty,
		size_t _Size>
		class array;

	template<size_t _Idx,
		class _Ty,
		size_t _Size>
		constexpr _Ty& get(array<_Ty, _Size>& _Arr) noexcept;

	template<size_t _Idx,
		class _Ty,
		size_t _Size>
		constexpr const _Ty& get(const array<_Ty, _Size>& _Arr) noexcept;

	template<size_t _Idx,
		class _Ty,
		size_t _Size>
		constexpr _Ty&& get(array<_Ty, _Size>&& _Arr) noexcept;

	template<size_t _Idx,
		class _Ty,
		size_t _Size>
		constexpr const _Ty&& get(const array<_Ty, _Size>&& _Arr) noexcept;

	template<class _Ty,
		class... _For_array>
		struct _View_as_tuple
	{
		static_assert(_Always_false<_Ty>,
			"Unsupported tuple_cat arguments.");
	};

	template<class... _Types>
	struct _View_as_tuple<tuple<_Types...>>
	{
		typedef tuple<_Types...> type;
	};

	template<class _Ty1,
		class _Ty2>
		struct _View_as_tuple<pair<_Ty1, _Ty2>>
	{
		typedef tuple<_Ty1, _Ty2> type;
	};

	template<class _Ty,
		class... _Types>
		struct _View_as_tuple<array<_Ty, 0>, _Types...>
	{
		typedef tuple<_Types...> type;
	};

	template<class _Ty,
		size_t _Size,
		class... _Types>
		struct _View_as_tuple<array<_Ty, _Size>, _Types...>
		: _View_as_tuple<array<_Ty, _Size - 1>, _Ty, _Types...>
	{
	};

	template<size_t _Nx,
		class _Ty>
		struct _Repeat_for
		: integral_constant<size_t, _Nx>
	{
	};

	template<class _Ret,
		class _Kx_arg,
		class _Ix_arg,
		size_t _Ix_next,
		class... _Tuples>
		struct _Tuple_cat2
	{
		static_assert(sizeof...(_Tuples) == 0,
			"Unsupported tuple_cat arguments.");
		typedef _Ret type;
		typedef _Kx_arg _Kx_arg_seq;
		typedef _Ix_arg _Ix_arg_seq;
	};

	template<class... _Types1,
		class _Kx_arg,
		size_t... _Ix,
		size_t _Ix_next,
		class... _Types2,
		class... _Rest>
		struct _Tuple_cat2<tuple<_Types1...>, _Kx_arg,
		index_sequence<_Ix...>, _Ix_next,
		tuple<_Types2...>, _Rest...>
		: _Tuple_cat2<
		tuple<_Types1..., _Types2...>,
		typename _Cat_sequences<_Kx_arg, index_sequence_for<_Types2...>>::type,
		index_sequence<_Ix..., _Repeat_for<_Ix_next, _Types2>::value...>,
		_Ix_next + 1,
		_Rest...>
	{
	};

	template<class... _Tuples>
	struct _Tuple_cat1
		: _Tuple_cat2<tuple<>, index_sequence<>,
		index_sequence<>, 0,
		typename _View_as_tuple<decay_t<_Tuples>>::type...>
	{
	};

#pragma warning(push)
#pragma warning(disable: 4100)	
	template<class _Ret,
		size_t... _Kx,
		size_t... _Ix,
		class _Ty>
		constexpr _Ret _Tuple_cat(index_sequence<_Kx...>,
			index_sequence<_Ix...>, _Ty&& _Arg)
	{
		return (_Ret(::std::get<_Kx>(::std::get<_Ix>(::std::forward<_Ty>(_Arg)))...));
	}
#pragma warning(pop)

	template<class... _Tuples>
	constexpr typename _Tuple_cat1<_Tuples...>::type
		tuple_cat(_Tuples&&... _Tpls)
	{
		typedef _Tuple_cat1<_Tuples...> _Cat1;
		return (_Tuple_cat<typename _Cat1::type>(
			typename _Cat1::_Kx_arg_seq(), typename _Cat1::_Ix_arg_seq(),
			::std::forward_as_tuple(::std::forward<_Tuples>(_Tpls)...)));
	}

	template<class _Tpl,
		class _Fx,
		size_t... _Indices> inline
		void _For_each_tuple_element_impl(_Tpl&& _Tuple,
			_Fx _Func, index_sequence<_Indices...>)
	{
		int _Ignored[] = { (static_cast<void>(_Func(
			::std::get<_Indices>(::std::forward<_Tpl>(_Tuple))
			)), 0)... };
		(void)_Ignored;
	}

	template<class _Tpl,
		class _Fx> inline
		void _For_each_tuple_element(_Tpl&& _Tuple, _Fx _Func)
	{
		_For_each_tuple_element_impl(
			::std::forward<_Tpl>(_Tuple),
			_Func,
			make_index_sequence<tuple_size_v<remove_reference_t<_Tpl>>>()
		);
	}

#pragma warning(push)
#pragma warning(disable: 4100)	

	template<class _Ty1,
		class _Ty2>
		template<class _Tuple1,
		class _Tuple2,
		size_t... _Indexes1,
		size_t... _Indexes2> inline
		pair<_Ty1, _Ty2>::pair(_Tuple1& _Val1,
			_Tuple2& _Val2,
			index_sequence<_Indexes1...>,
			index_sequence<_Indexes2...>)
		: first(::std::get<_Indexes1>(::std::move(_Val1))...),
		second(::std::get<_Indexes2>(::std::move(_Val2))...)
	{
	}
#pragma warning(pop)

	template<class _Ty1,
		class _Ty2>
		template<class... _Types1,
		class... _Types2> inline
		pair<_Ty1, _Ty2>::pair(piecewise_construct_t,
			tuple<_Types1...> _Val1,
			tuple<_Types2...> _Val2)
		: pair(_Val1, _Val2,
			index_sequence_for<_Types1...>(),
			index_sequence_for<_Types2...>())
	{
	}

	template<class... _Types,
		class _Alloc>
		struct uses_allocator<tuple<_Types...>, _Alloc>
		: true_type
	{
	};

	namespace[[deprecated("warning STL4002: " "The non-Standard std::tr1 namespace and TR1-only machinery are deprecated and will be REMOVED. You can " "define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING to acknowledge that you have received this warning.")]] tr1{
	using ::std::get;
	using ::std::ignore;
	using ::std::make_tuple;
	using ::std::ref;
	using ::std::tie;
	using ::std::tuple;
	}

}

#pragma warning(pop)
#pragma pack(pop)

#pragma once

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

#pragma warning(disable: 4275)	

#pragma once

#pragma pack(push, 8)

struct __type_info_node;

extern __type_info_node __type_info_root_node;

__pragma(pack(push, 8)) extern "C" {

	struct __std_type_info_data
	{
		const char * _UndecoratedName;
		const char   _DecoratedName[1];
		__std_type_info_data() = delete;
		__std_type_info_data(const __std_type_info_data&) = delete;
		__std_type_info_data(__std_type_info_data&&) = delete;

		__std_type_info_data& operator=(const __std_type_info_data&) = delete;
		__std_type_info_data& operator=(__std_type_info_data&&) = delete;
	};

	int __cdecl __std_type_info_compare(
		const __std_type_info_data* _Lhs,
		const __std_type_info_data* _Rhs
	);

	size_t __cdecl __std_type_info_hash(
		const __std_type_info_data* _Data
	);

	const char* __cdecl __std_type_info_name(
		__std_type_info_data* _Data,
		__type_info_node*     _RootNode
	);

} __pragma(pack(pop))

#pragma warning(push)
#pragma warning(disable: 4577) 
class type_info
{
public:

	type_info(const type_info&) = delete;
	type_info& operator=(const type_info&) = delete;

	size_t hash_code() const noexcept
	{
		return __std_type_info_hash(&_Data);
	}

	bool operator==(const type_info& _Other) const noexcept
	{
		return __std_type_info_compare(&_Data, &_Other._Data) == 0;
	}

	bool operator!=(const type_info& _Other) const noexcept
	{
		return __std_type_info_compare(&_Data, &_Other._Data) != 0;
	}

	bool before(const type_info& _Other) const noexcept
	{
		return __std_type_info_compare(&_Data, &_Other._Data) < 0;
	}

	const char* name() const noexcept
	{

		return __std_type_info_name(&_Data, &__type_info_root_node);

	}

	const char* raw_name() const noexcept
	{
		return _Data._DecoratedName;
	}

	virtual ~type_info() noexcept;

private:

	mutable __std_type_info_data _Data;
};
#pragma warning(pop)

namespace std {
	using ::type_info;
}

namespace std {

#pragma warning(push)
#pragma warning(disable: 4577) 
	class bad_cast
		: public exception
	{
	public:

		bad_cast() noexcept
			: exception("bad cast", 1)
		{
		}

		static bad_cast __construct_from_string_literal(const char* const _Message) noexcept
		{
			return bad_cast(_Message, 1);
		}

	private:

		bad_cast(const char* const _Message, int) noexcept
			: exception(_Message, 1)
		{
		}
	};

	class bad_typeid
		: public exception
	{
	public:

		bad_typeid() noexcept
			: exception("bad typeid", 1)
		{
		}

		static bad_typeid __construct_from_string_literal(const char* const _Message) noexcept
		{
			return bad_typeid(_Message, 1);
		}

	private:

		friend class __non_rtti_object;

		bad_typeid(const char* const _Message, int) noexcept
			: exception(_Message, 1)
		{
		}
	};

	class __non_rtti_object
		: public bad_typeid
	{
	public:

		static __non_rtti_object __construct_from_string_literal(const char* const _Message) noexcept
		{
			return __non_rtti_object(_Message, 1);
		}

	private:

		__non_rtti_object(const char* const _Message, int) noexcept
			: bad_typeid(_Message, 1)
		{
		}
	};

#pragma warning(pop)
}

#pragma pack(pop)

namespace std {

	constexpr int _Small_object_num_ptrs = 6 + 16 / sizeof(void *);

}

#pragma pack(pop)
#pragma warning(pop)

#pragma once

#pragma once

#pragma once

#pragma once

typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

typedef signed char        int_least8_t;
typedef short              int_least16_t;
typedef int                int_least32_t;
typedef long long          int_least64_t;
typedef unsigned char      uint_least8_t;
typedef unsigned short     uint_least16_t;
typedef unsigned int       uint_least32_t;
typedef unsigned long long uint_least64_t;

typedef signed char        int_fast8_t;
typedef int                int_fast16_t;
typedef int                int_fast32_t;
typedef long long          int_fast64_t;
typedef unsigned char      uint_fast8_t;
typedef unsigned int       uint_fast16_t;
typedef unsigned int       uint_fast32_t;
typedef unsigned long long uint_fast64_t;

typedef long long          intmax_t;
typedef unsigned long long uintmax_t;

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {
	using ::int8_t; using ::int16_t;
	using ::int32_t; using ::int64_t;
	using ::uint8_t; using ::uint16_t;
	using ::uint32_t; using ::uint64_t;

	using ::int_least8_t; using ::int_least16_t;
	using ::int_least32_t; using ::int_least64_t;
	using ::uint_least8_t; using ::uint_least16_t;
	using ::uint_least32_t; using ::uint_least64_t;

	using ::int_fast8_t; using ::int_fast16_t;
	using ::int_fast32_t; using ::int_fast64_t;
	using ::uint_fast8_t; using ::uint_fast16_t;
	using ::uint_fast32_t; using ::uint_fast64_t;

	using ::intmax_t; using ::intptr_t;
	using ::uintmax_t; using ::uintptr_t;

	namespace[[deprecated("warning STL4002: " "The non-Standard std::tr1 namespace and TR1-only machinery are deprecated and will be REMOVED. You can " "define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING to acknowledge that you have received this warning.")]] tr1{
	using ::int8_t; using ::int16_t;
	using ::int32_t; using ::int64_t;
	using ::uint8_t; using ::uint16_t;
	using ::uint32_t; using ::uint64_t;

	using ::int_least8_t; using ::int_least16_t;
	using ::int_least32_t; using ::int_least64_t;
	using ::uint_least8_t; using ::uint_least16_t;
	using ::uint_least32_t; using ::uint_least64_t;

	using ::int_fast8_t; using ::int_fast16_t;
	using ::int_fast32_t; using ::int_fast64_t;
	using ::uint_fast8_t; using ::uint_fast16_t;
	using ::uint_fast32_t; using ::uint_fast64_t;

	using ::intmax_t; using ::intptr_t;
	using ::uintmax_t; using ::uintptr_t;
	}

}

#pragma warning(pop)
#pragma pack(pop)

#pragma once

#pragma once

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

extern "C" {

	void __cdecl _Feraise(int);

	typedef union
	{
		unsigned short _Word[8];
		float _Float;
		double _Double;
		long double _Long_double;
	} _Dconst;

	double __cdecl _Cosh(double, double);
	short __cdecl _Dtest(double *);
	double __cdecl _Sinh(double, double);

	short __cdecl _Exp(double *, double, short);
	extern __declspec(dllimport)  _Dconst _Denorm, _Hugeval, _Inf,
		_Nan, _Snan;

	float __cdecl _FCosh(float, float);
	short __cdecl _FDtest(float *);
	float __cdecl _FSinh(float, float);

	short __cdecl _FExp(float *, float, short);
	extern __declspec(dllimport)  _Dconst _FDenorm, _FInf, _FNan, _FSnan;

	long double __cdecl _LCosh(long double, long double);
	short __cdecl _LDtest(long double *);
	long double __cdecl _LSinh(long double, long double);

	short __cdecl _LExp(long double *, long double, short);
	extern __declspec(dllimport)  _Dconst _LDenorm, _LInf, _LNan, _LSnan;

}

#pragma warning(pop)
#pragma pack(pop)

#pragma once

#pragma once

__pragma(pack(push, 8)) extern "C" {

	__declspec(dllimport) unsigned int __cdecl _clearfp(void);

#pragma warning(push)
#pragma warning(disable: 4141)

	__declspec(deprecated("This function or variable may be unsafe. Consider using " "_controlfp_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " "See online help for details."))
		__declspec(dllimport) unsigned int __cdecl _controlfp(
			unsigned int _NewValue,
			unsigned int _Mask
		);

#pragma warning(pop)

	__declspec(dllimport) void __cdecl _set_controlfp(
		unsigned int _NewValue,
		unsigned int _Mask
	);

	__declspec(dllimport) errno_t __cdecl _controlfp_s(
		unsigned int* _CurrentState,
		unsigned int  _NewValue,
		unsigned int  _Mask
	);

	__declspec(dllimport) unsigned int __cdecl _statusfp(void);

	__declspec(dllimport) void __cdecl _fpreset(void);

	__declspec(dllimport) void __cdecl _statusfp2(
		unsigned int* _X86Status,
		unsigned int* _SSE2Status
	);

	__declspec(dllimport) unsigned int __cdecl _control87(
		unsigned int _NewValue,
		unsigned int _Mask
	);

	__declspec(dllimport) int __cdecl __control87_2(
		unsigned int  _NewValue,
		unsigned int  _Mask,
		unsigned int* _X86ControlWord,
		unsigned int* _Sse2ControlWord
	);

	__declspec(dllimport) int* __cdecl __fpecode(void);

	__declspec(dllimport) int __cdecl __fpe_flt_rounds(void);

	__declspec(dllimport) double __cdecl _copysign(double _Number, double _Sign);
	__declspec(dllimport) double __cdecl _chgsign(double _X);
	__declspec(dllimport) double __cdecl _scalb(double _X, long _Y);
	__declspec(dllimport) double __cdecl _logb(double _X);
	__declspec(dllimport) double __cdecl _nextafter(double _X, double _Y);
	__declspec(dllimport) int    __cdecl _finite(double _X);
	__declspec(dllimport) int    __cdecl _isnan(double _X);
	__declspec(dllimport) int    __cdecl _fpclass(double _X);

	__declspec(dllimport) void __cdecl fpreset(void);

} __pragma(pack(pop))

#pragma once

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

inline double pow(double _Xx, int _Yx) noexcept
{
	if (_Yx == 2)
		return (_Xx * _Xx);

	return (::pow(_Xx, static_cast<double>(_Yx)));
}

inline float acos(float _Xx) noexcept
{
	return (::acosf(_Xx));
}

inline float acosh(float _Xx) noexcept
{
	return (::acoshf(_Xx));
}

inline float asin(float _Xx) noexcept
{
	return (::asinf(_Xx));
}

inline float asinh(float _Xx) noexcept
{
	return (::asinhf(_Xx));
}

inline float atan(float _Xx) noexcept
{
	return (::atanf(_Xx));
}

inline float atanh(float _Xx) noexcept
{
	return (::atanhf(_Xx));
}

inline float atan2(float _Yx, float _Xx) noexcept
{
	return (::atan2f(_Yx, _Xx));
}

inline float cbrt(float _Xx) noexcept
{
	return (::cbrtf(_Xx));
}

inline float ceil(float _Xx) noexcept
{
	return (::ceilf(_Xx));
}

inline float copysign(float _Number,
	float _Sign) noexcept
{
	return (::copysignf(_Number, _Sign));
}

inline float cos(float _Xx) noexcept
{
	return (::cosf(_Xx));
}

inline float cosh(float _Xx) noexcept
{
	return (::coshf(_Xx));
}

inline float erf(float _Xx) noexcept
{
	return (::erff(_Xx));
}

inline float erfc(float _Xx) noexcept
{
	return (::erfcf(_Xx));
}

inline float exp(float _Xx) noexcept
{
	return (::expf(_Xx));
}

inline float exp2(float _Xx) noexcept
{
	return (::exp2f(_Xx));
}

inline float expm1(float _Xx) noexcept
{
	return (::expm1f(_Xx));
}

inline float fabs(float _Xx) noexcept
{
	return (::fabsf(_Xx));
}

inline float fdim(float _Xx, float _Yx) noexcept
{
	return (::fdimf(_Xx, _Yx));
}

inline float floor(float _Xx) noexcept
{
	return (::floorf(_Xx));
}

inline float fma(float _Xx, float _Yx,
	float _Zx) noexcept
{
	return (::fmaf(_Xx, _Yx, _Zx));
}

inline float fmax(float _Xx, float _Yx) noexcept
{
	return (::fmaxf(_Xx, _Yx));
}

inline float fmin(float _Xx, float _Yx) noexcept
{
	return (::fminf(_Xx, _Yx));
}

inline float fmod(float _Xx, float _Yx) noexcept
{
	return (::fmodf(_Xx, _Yx));
}

inline float frexp(float _Xx, int* _Yx) noexcept
{
	return (::frexpf(_Xx, _Yx));
}

inline float hypot(float _Xx, float _Yx) noexcept
{
	return (::hypotf(_Xx, _Yx));
}

inline int ilogb(float _Xx) noexcept
{
	return (::ilogbf(_Xx));
}

inline float ldexp(float _Xx, int _Yx) noexcept
{
	return (::ldexpf(_Xx, _Yx));
}

inline float lgamma(float _Xx) noexcept
{
	return (::lgammaf(_Xx));
}

inline long long llrint(float _Xx) noexcept
{
	return (::llrintf(_Xx));
}

inline long long llround(float _Xx) noexcept
{
	return (::llroundf(_Xx));
}

inline float log(float _Xx) noexcept
{
	return (::logf(_Xx));
}

inline float log10(float _Xx) noexcept
{
	return (::log10f(_Xx));
}

inline float log1p(float _Xx) noexcept
{
	return (::log1pf(_Xx));
}

inline float log2(float _Xx) noexcept
{
	return (::log2f(_Xx));
}

inline float logb(float _Xx) noexcept
{
	return (::logbf(_Xx));
}

inline long lrint(float _Xx) noexcept
{
	return (::lrintf(_Xx));
}

inline long lround(float _Xx) noexcept
{
	return (::lroundf(_Xx));
}

inline float modf(float _Xx, float* _Yx) noexcept
{
	return (::modff(_Xx, _Yx));
}

inline float nearbyint(float _Xx) noexcept
{
	return (::nearbyintf(_Xx));
}

inline float nextafter(float _Xx, float _Yx) noexcept
{
	return (::nextafterf(_Xx, _Yx));
}

inline float nexttoward(float _Xx,
	long double _Yx) noexcept
{
	return (::nexttowardf(_Xx, _Yx));
}

inline float pow(float _Xx,
	float _Yx) noexcept
{
	return (::powf(_Xx, _Yx));
}

inline float pow(float _Xx, int _Yx) noexcept
{
	if (_Yx == 2)
		return (_Xx * _Xx);

	return (::powf(_Xx, static_cast<float>(_Yx)));
}

inline float remainder(float _Xx, float _Yx) noexcept
{
	return (::remainderf(_Xx, _Yx));
}

inline float remquo(float _Xx, float _Yx,
	int *_Zx) noexcept
{
	return (::remquof(_Xx, _Yx, _Zx));
}

inline float rint(float _Xx) noexcept
{
	return (::rintf(_Xx));
}

inline float round(float _Xx) noexcept
{
	return (::roundf(_Xx));
}

inline float scalbln(float _Xx, long _Yx) noexcept
{
	return (::scalblnf(_Xx, _Yx));
}

inline float scalbn(float _Xx, int _Yx) noexcept
{
	return (::scalbnf(_Xx, _Yx));
}

inline float sin(float _Xx) noexcept
{
	return (::sinf(_Xx));
}

inline float sinh(float _Xx) noexcept
{
	return (::sinhf(_Xx));
}

inline float sqrt(float _Xx) noexcept
{
	return (::sqrtf(_Xx));
}

inline float tan(float _Xx) noexcept
{
	return (::tanf(_Xx));
}

inline float tanh(float _Xx) noexcept
{
	return (::tanhf(_Xx));
}

inline float tgamma(float _Xx) noexcept
{
	return (::tgammaf(_Xx));
}

inline float trunc(float _Xx) noexcept
{
	return (::truncf(_Xx));
}

inline long double acos(long double _Xx) noexcept
{
	return (::acosl(_Xx));
}

inline long double acosh(long double _Xx) noexcept
{
	return (::acoshl(_Xx));
}

inline long double asin(long double _Xx) noexcept
{
	return (::asinl(_Xx));
}

inline long double asinh(long double _Xx) noexcept
{
	return (::asinhl(_Xx));
}

inline long double atan(long double _Xx) noexcept
{
	return (::atanl(_Xx));
}

inline long double atanh(long double _Xx) noexcept
{
	return (::atanhl(_Xx));
}

inline long double atan2(long double _Yx,
	long double _Xx) noexcept
{
	return (::atan2l(_Yx, _Xx));
}

inline long double cbrt(long double _Xx) noexcept
{
	return (::cbrtl(_Xx));
}

inline long double ceil(long double _Xx) noexcept
{
	return (::ceill(_Xx));
}

inline long double copysign(long double _Number,
	long double _Sign) noexcept
{
	return (::copysignl(_Number, _Sign));
}

inline long double cos(long double _Xx) noexcept
{
	return (::cosl(_Xx));
}

inline long double cosh(long double _Xx) noexcept
{
	return (::coshl(_Xx));
}

inline long double erf(long double _Xx) noexcept
{
	return (::erfl(_Xx));
}

inline long double erfc(long double _Xx) noexcept
{
	return (::erfcl(_Xx));
}

inline long double exp(long double _Xx) noexcept
{
	return (::expl(_Xx));
}

inline long double exp2(long double _Xx) noexcept
{
	return (::exp2l(_Xx));
}

inline long double expm1(long double _Xx) noexcept
{
	return (::expm1l(_Xx));
}

inline long double fabs(long double _Xx) noexcept
{
	return (::fabsl(_Xx));
}

inline long double fdim(long double _Xx,
	long double _Yx) noexcept
{
	return (::fdiml(_Xx, _Yx));
}

inline long double floor(long double _Xx) noexcept
{
	return (::floorl(_Xx));
}

inline long double fma(long double _Xx,
	long double _Yx, long double _Zx) noexcept
{
	return (::fmal(_Xx, _Yx, _Zx));
}

inline long double fmax(long double _Xx,
	long double _Yx) noexcept
{
	return (::fmaxl(_Xx, _Yx));
}

inline long double fmin(long double _Xx,
	long double _Yx) noexcept
{
	return (::fminl(_Xx, _Yx));
}

inline long double fmod(long double _Xx,
	long double _Yx) noexcept
{
	return (::fmodl(_Xx, _Yx));
}

inline long double frexp(long double _Xx,
	int* _Yx) noexcept
{
	return (::frexpl(_Xx, _Yx));
}

inline long double hypot(long double _Xx,
	long double _Yx) noexcept
{
	return (::hypotl(_Xx, _Yx));
}

inline int ilogb(long double _Xx) noexcept
{
	return (::ilogbl(_Xx));
}

inline long double ldexp(long double _Xx,
	int _Yx) noexcept
{
	return (::ldexpl(_Xx, _Yx));
}

inline long double lgamma(long double _Xx) noexcept
{
	return (::lgammal(_Xx));
}

inline long long llrint(long double _Xx) noexcept
{
	return (::llrintl(_Xx));
}

inline long long llround(long double _Xx) noexcept
{
	return (::llroundl(_Xx));
}

inline long double log(long double _Xx) noexcept
{
	return (::logl(_Xx));
}

inline long double log10(long double _Xx) noexcept
{
	return (::log10l(_Xx));
}

inline long double log1p(long double _Xx) noexcept
{
	return (::log1pl(_Xx));
}

inline long double log2(long double _Xx) noexcept
{
	return (::log2l(_Xx));
}

inline long double logb(long double _Xx) noexcept
{
	return (::logbl(_Xx));
}

inline long lrint(long double _Xx) noexcept
{
	return (::lrintl(_Xx));
}

inline long lround(long double _Xx) noexcept
{
	return (::lroundl(_Xx));
}

inline long double modf(long double _Xx,
	long double* _Yx) noexcept
{
	return (::modfl(_Xx, _Yx));
}

inline long double nearbyint(long double _Xx) noexcept
{
	return (::nearbyintl(_Xx));
}

inline long double nextafter(long double _Xx,
	long double _Yx) noexcept
{
	return (::nextafterl(_Xx, _Yx));
}

inline long double nexttoward(long double _Xx,
	long double _Yx) noexcept
{
	return (::nexttowardl(_Xx, _Yx));
}

inline long double pow(long double _Xx,
	long double _Yx) noexcept
{
	return (::powl(_Xx, _Yx));
}

inline long double pow(long double _Xx,
	int _Yx) noexcept
{
	if (_Yx == 2)
		return (_Xx * _Xx);

	return (::powl(_Xx, static_cast<long double>(_Yx)));
}

inline long double remainder(long double _Xx,
	long double _Yx) noexcept
{
	return (::remainderl(_Xx, _Yx));
}

inline long double remquo(long double _Xx,
	long double _Yx, int *_Zx) noexcept
{
	return (::remquol(_Xx, _Yx, _Zx));
}

inline long double rint(long double _Xx) noexcept
{
	return (::rintl(_Xx));
}

inline long double round(long double _Xx) noexcept
{
	return (::roundl(_Xx));
}

inline long double scalbln(long double _Xx,
	long _Yx) noexcept
{
	return (::scalblnl(_Xx, _Yx));
}

inline long double scalbn(long double _Xx,
	int _Yx) noexcept
{
	return (::scalbnl(_Xx, _Yx));
}

inline long double sin(long double _Xx) noexcept
{
	return (::sinl(_Xx));
}

inline long double sinh(long double _Xx) noexcept
{
	return (::sinhl(_Xx));
}

inline long double sqrt(long double _Xx) noexcept
{
	return (::sqrtl(_Xx));
}

inline long double tan(long double _Xx) noexcept
{
	return (::tanl(_Xx));
}

inline long double tanh(long double _Xx) noexcept
{
	return (::tanhl(_Xx));
}

inline long double tgamma(long double _Xx) noexcept
{
	return (::tgammal(_Xx));
}

inline long double trunc(long double _Xx) noexcept
{
	return (::truncl(_Xx));
}

#pragma once

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {
	template<class _Ty1,
		class _Ty2>
		using _Common_float_type_t =
		conditional_t<is_same_v<_Ty1, long double> || is_same_v<_Ty2, long double>, long double,
		conditional_t<is_same_v<_Ty1, float> && is_same_v<_Ty2, float>, float,
		double>>;
}

template<class _Ty1,
	class _Ty2,
	class = ::std::enable_if_t<::std::is_arithmetic_v<_Ty1> && ::std::is_arithmetic_v<_Ty2>>>  inline
	::std::_Common_float_type_t<_Ty1, _Ty2> pow(const _Ty1 _Left, const _Ty2 _Right)
{
	using _Common = ::std::_Common_float_type_t<_Ty1, _Ty2>;
	return (::pow(static_cast<_Common>(_Left), static_cast<_Common>(_Right)));
}

extern "C"    double __cdecl acos(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double acos(_Ty _Left) { return (::acos(static_cast<double>(_Left))); }
extern "C"    double __cdecl asin(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double asin(_Ty _Left) { return (::asin(static_cast<double>(_Left))); }
extern "C"    double __cdecl atan(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double atan(_Ty _Left) { return (::atan(static_cast<double>(_Left))); }
extern "C"    double __cdecl atan2(double, double); template<class _Ty1, class _Ty2, class = ::std::enable_if_t<::std::is_arithmetic_v<_Ty1> && ::std::is_arithmetic_v<_Ty2>>>  inline ::std::_Common_float_type_t<_Ty1, _Ty2> atan2(_Ty1 _Left, _Ty2 _Right) { using _Common = ::std::_Common_float_type_t<_Ty1, _Ty2>; return (::atan2(static_cast<_Common>(_Left), static_cast<_Common>(_Right))); }
extern "C"   __declspec(dllimport) double __cdecl ceil(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double ceil(_Ty _Left) { return (::ceil(static_cast<double>(_Left))); }
extern "C"    double __cdecl cos(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double cos(_Ty _Left) { return (::cos(static_cast<double>(_Left))); }
extern "C"    double __cdecl cosh(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double cosh(_Ty _Left) { return (::cosh(static_cast<double>(_Left))); }
extern "C"    double __cdecl exp(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double exp(_Ty _Left) { return (::exp(static_cast<double>(_Left))); }

extern "C"    double __cdecl fabs(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double fabs(_Ty _Left) { return (::fabs(static_cast<double>(_Left))); }

extern "C"   __declspec(dllimport) double __cdecl floor(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double floor(_Ty _Left) { return (::floor(static_cast<double>(_Left))); }
extern "C"    double __cdecl fmod(double, double); template<class _Ty1, class _Ty2, class = ::std::enable_if_t<::std::is_arithmetic_v<_Ty1> && ::std::is_arithmetic_v<_Ty2>>>  inline ::std::_Common_float_type_t<_Ty1, _Ty2> fmod(_Ty1 _Left, _Ty2 _Right) { using _Common = ::std::_Common_float_type_t<_Ty1, _Ty2>; return (::fmod(static_cast<_Common>(_Left), static_cast<_Common>(_Right))); }
extern "C"   __declspec(dllimport) double __cdecl frexp(double, int *); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double frexp(_Ty _Left, int * _Arg2) { return (::frexp(static_cast<double>(_Left), _Arg2)); }
extern "C"   __declspec(dllimport) double __cdecl ldexp(double, int); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double ldexp(_Ty _Left, int _Arg2) { return (::ldexp(static_cast<double>(_Left), _Arg2)); }
extern "C"    double __cdecl log(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double log(_Ty _Left) { return (::log(static_cast<double>(_Left))); }
extern "C"    double __cdecl log10(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double log10(_Ty _Left) { return (::log10(static_cast<double>(_Left))); }

extern "C"    double __cdecl sin(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double sin(_Ty _Left) { return (::sin(static_cast<double>(_Left))); }
extern "C"    double __cdecl sinh(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double sinh(_Ty _Left) { return (::sinh(static_cast<double>(_Left))); }
extern "C"    double __cdecl sqrt(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double sqrt(_Ty _Left) { return (::sqrt(static_cast<double>(_Left))); }
extern "C"    double __cdecl tan(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double tan(_Ty _Left) { return (::tan(static_cast<double>(_Left))); }
extern "C"    double __cdecl tanh(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double tanh(_Ty _Left) { return (::tanh(static_cast<double>(_Left))); }

inline float _Fma(float _Left, float _Middle, float _Right)
{
	return (::fmaf(_Left, _Middle, _Right));
}

inline double _Fma(double _Left, double _Middle, double _Right)
{
	return (::fma(_Left, _Middle, _Right));
}

inline long double _Fma(long double _Left, long double _Middle,
	long double _Right)
{
	return (::fmal(_Left, _Middle, _Right));
}

template<class _Ty1,
	class _Ty2,
	class _Ty3,
	class = ::std::enable_if_t<::std::is_arithmetic_v<_Ty1> && ::std::is_arithmetic_v<_Ty2>
	&& ::std::is_arithmetic_v<_Ty3>>>  inline
	::std::_Common_float_type_t<_Ty1, ::std::_Common_float_type_t<_Ty2, _Ty3>>
	fma(_Ty1 _Left, _Ty2 _Middle, _Ty3 _Right)
{
	using _Common = ::std::_Common_float_type_t<_Ty1, ::std::_Common_float_type_t<_Ty2, _Ty3>>;

	return (_Fma(static_cast<_Common>(_Left), static_cast<_Common>(_Middle), static_cast<_Common>(_Right)));

}

inline float _Remquo(float _Left, float _Right, int *_Pquo)
{
	return (::remquof(_Left, _Right, _Pquo));
}

inline double _Remquo(double _Left, double _Right, int *_Pquo)
{
	return (::remquo(_Left, _Right, _Pquo));
}

inline long double _Remquo(long double _Left, long double _Right, int *_Pquo)
{
	return (::remquol(_Left, _Right, _Pquo));
}

template<class _Ty1,
	class _Ty2,
	class = ::std::enable_if_t<::std::is_arithmetic_v<_Ty1> && ::std::is_arithmetic_v<_Ty2>>> inline
	::std::_Common_float_type_t<_Ty1, _Ty2>
	remquo(_Ty1 _Left, _Ty2 _Right, int *_Pquo)
{
	using _Common = ::std::_Common_float_type_t<_Ty1, _Ty2>;

	return (_Remquo(static_cast<_Common>(_Left), static_cast<_Common>(_Right), _Pquo));

}

extern "C"   __declspec(dllimport) double __cdecl acosh(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double acosh(_Ty _Left) { return (::acosh(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl asinh(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double asinh(_Ty _Left) { return (::asinh(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl atanh(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double atanh(_Ty _Left) { return (::atanh(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl cbrt(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double cbrt(_Ty _Left) { return (::cbrt(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl copysign(double, double); template<class _Ty1, class _Ty2, class = ::std::enable_if_t<::std::is_arithmetic_v<_Ty1> && ::std::is_arithmetic_v<_Ty2>>>  inline ::std::_Common_float_type_t<_Ty1, _Ty2> copysign(_Ty1 _Left, _Ty2 _Right) { using _Common = ::std::_Common_float_type_t<_Ty1, _Ty2>; return (::copysign(static_cast<_Common>(_Left), static_cast<_Common>(_Right))); }
extern "C"   __declspec(dllimport) double __cdecl erf(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double erf(_Ty _Left) { return (::erf(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl erfc(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double erfc(_Ty _Left) { return (::erfc(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl expm1(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double expm1(_Ty _Left) { return (::expm1(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl exp2(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double exp2(_Ty _Left) { return (::exp2(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl fdim(double, double); template<class _Ty1, class _Ty2, class = ::std::enable_if_t<::std::is_arithmetic_v<_Ty1> && ::std::is_arithmetic_v<_Ty2>>>  inline ::std::_Common_float_type_t<_Ty1, _Ty2> fdim(_Ty1 _Left, _Ty2 _Right) { using _Common = ::std::_Common_float_type_t<_Ty1, _Ty2>; return (::fdim(static_cast<_Common>(_Left), static_cast<_Common>(_Right))); }

extern "C"   __declspec(dllimport) double __cdecl fmax(double, double); template<class _Ty1, class _Ty2, class = ::std::enable_if_t<::std::is_arithmetic_v<_Ty1> && ::std::is_arithmetic_v<_Ty2>>>  inline ::std::_Common_float_type_t<_Ty1, _Ty2> fmax(_Ty1 _Left, _Ty2 _Right) { using _Common = ::std::_Common_float_type_t<_Ty1, _Ty2>; return (::fmax(static_cast<_Common>(_Left), static_cast<_Common>(_Right))); }
extern "C"   __declspec(dllimport) double __cdecl fmin(double, double); template<class _Ty1, class _Ty2, class = ::std::enable_if_t<::std::is_arithmetic_v<_Ty1> && ::std::is_arithmetic_v<_Ty2>>>  inline ::std::_Common_float_type_t<_Ty1, _Ty2> fmin(_Ty1 _Left, _Ty2 _Right) { using _Common = ::std::_Common_float_type_t<_Ty1, _Ty2>; return (::fmin(static_cast<_Common>(_Left), static_cast<_Common>(_Right))); }
extern "C"   __declspec(dllimport) double __cdecl hypot(double, double); template<class _Ty1, class _Ty2, class = ::std::enable_if_t<::std::is_arithmetic_v<_Ty1> && ::std::is_arithmetic_v<_Ty2>>>  inline ::std::_Common_float_type_t<_Ty1, _Ty2> hypot(_Ty1 _Left, _Ty2 _Right) { using _Common = ::std::_Common_float_type_t<_Ty1, _Ty2>; return (::hypot(static_cast<_Common>(_Left), static_cast<_Common>(_Right))); }
extern "C"   __declspec(dllimport) int __cdecl ilogb(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline int ilogb(_Ty _Left) { return (::ilogb(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl lgamma(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double lgamma(_Ty _Left) { return (::lgamma(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) long long __cdecl llrint(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline long long llrint(_Ty _Left) { return (::llrint(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) long long __cdecl llround(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline long long llround(_Ty _Left) { return (::llround(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl log1p(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double log1p(_Ty _Left) { return (::log1p(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl log2(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double log2(_Ty _Left) { return (::log2(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl logb(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double logb(_Ty _Left) { return (::logb(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) long __cdecl lrint(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline long lrint(_Ty _Left) { return (::lrint(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) long __cdecl lround(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline long lround(_Ty _Left) { return (::lround(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl nearbyint(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double nearbyint(_Ty _Left) { return (::nearbyint(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl nextafter(double, double); template<class _Ty1, class _Ty2, class = ::std::enable_if_t<::std::is_arithmetic_v<_Ty1> && ::std::is_arithmetic_v<_Ty2>>>  inline ::std::_Common_float_type_t<_Ty1, _Ty2> nextafter(_Ty1 _Left, _Ty2 _Right) { using _Common = ::std::_Common_float_type_t<_Ty1, _Ty2>; return (::nextafter(static_cast<_Common>(_Left), static_cast<_Common>(_Right))); }
extern "C"   __declspec(dllimport) double __cdecl nexttoward(double, long double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double nexttoward(_Ty _Left, long double _Arg2) { return (::nexttoward(static_cast<double>(_Left), _Arg2)); }
extern "C"   __declspec(dllimport) double __cdecl remainder(double, double); template<class _Ty1, class _Ty2, class = ::std::enable_if_t<::std::is_arithmetic_v<_Ty1> && ::std::is_arithmetic_v<_Ty2>>>  inline ::std::_Common_float_type_t<_Ty1, _Ty2> remainder(_Ty1 _Left, _Ty2 _Right) { using _Common = ::std::_Common_float_type_t<_Ty1, _Ty2>; return (::remainder(static_cast<_Common>(_Left), static_cast<_Common>(_Right))); }

extern "C"   __declspec(dllimport) double __cdecl rint(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double rint(_Ty _Left) { return (::rint(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl round(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double round(_Ty _Left) { return (::round(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl scalbln(double, long); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double scalbln(_Ty _Left, long _Arg2) { return (::scalbln(static_cast<double>(_Left), _Arg2)); }
extern "C"   __declspec(dllimport) double __cdecl scalbn(double, int); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double scalbn(_Ty _Left, int _Arg2) { return (::scalbn(static_cast<double>(_Left), _Arg2)); }
extern "C"   __declspec(dllimport) double __cdecl tgamma(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double tgamma(_Ty _Left) { return (::tgamma(static_cast<double>(_Left))); }
extern "C"   __declspec(dllimport) double __cdecl trunc(double); template<class _Ty, class = ::std::enable_if_t<::std::is_integral_v<_Ty>>>  inline double trunc(_Ty _Left) { return (::trunc(static_cast<double>(_Left))); }

#pragma warning(pop)
#pragma pack(pop)

namespace std {
	using ::abs; using ::acos; using ::asin;
	using ::atan; using ::atan2; using ::ceil;
	using ::cos; using ::cosh; using ::exp;
	using ::fabs; using ::floor; using ::fmod;
	using ::frexp; using ::ldexp; using ::log;
	using ::log10; using ::modf; using ::pow;
	using ::sin; using ::sinh; using ::sqrt;
	using ::tan; using ::tanh;

	using ::acosf; using ::asinf;
	using ::atanf; using ::atan2f; using ::ceilf;
	using ::cosf; using ::coshf; using ::expf;
	using ::fabsf; using ::floorf; using ::fmodf;
	using ::frexpf; using ::ldexpf; using ::logf;
	using ::log10f; using ::modff; using ::powf;
	using ::sinf; using ::sinhf; using ::sqrtf;
	using ::tanf; using ::tanhf;

	using ::acosl; using ::asinl;
	using ::atanl; using ::atan2l; using ::ceill;
	using ::cosl; using ::coshl; using ::expl;
	using ::fabsl; using ::floorl; using ::fmodl;
	using ::frexpl; using ::ldexpl; using ::logl;
	using ::log10l; using ::modfl; using ::powl;
	using ::sinl; using ::sinhl; using ::sqrtl;
	using ::tanl; using ::tanhl;

	using ::float_t; using ::double_t;

	using ::acosh; using ::asinh; using ::atanh;
	using ::cbrt; using ::erf; using ::erfc;
	using ::expm1; using ::exp2;
	using ::hypot; using ::ilogb; using ::lgamma;
	using ::log1p; using ::log2; using ::logb;
	using ::llrint; using ::lrint; using ::nearbyint;
	using ::rint; using ::llround; using ::lround;
	using ::fdim; using ::fma; using ::fmax; using ::fmin;
	using ::round; using ::trunc;
	using ::remainder; using ::remquo;
	using ::copysign; using ::nan; using ::nextafter;
	using ::scalbn; using ::scalbln;
	using ::nexttoward; using ::tgamma;

	using ::acoshf; using ::asinhf; using ::atanhf;
	using ::cbrtf; using ::erff; using ::erfcf;
	using ::expm1f; using ::exp2f;
	using ::hypotf; using ::ilogbf; using ::lgammaf;
	using ::log1pf; using ::log2f; using ::logbf;
	using ::llrintf; using ::lrintf; using ::nearbyintf;
	using ::rintf; using ::llroundf; using ::lroundf;
	using ::fdimf; using ::fmaf; using ::fmaxf; using ::fminf;
	using ::roundf; using ::truncf;
	using ::remainderf; using ::remquof;
	using ::copysignf; using ::nanf;
	using ::nextafterf; using ::scalbnf; using ::scalblnf;
	using ::nexttowardf; using ::tgammaf;

	using ::acoshl; using ::asinhl; using ::atanhl;
	using ::cbrtl; using ::erfl; using ::erfcl;
	using ::expm1l; using ::exp2l;
	using ::hypotl; using ::ilogbl; using ::lgammal;
	using ::log1pl; using ::log2l; using ::logbl;
	using ::llrintl; using ::lrintl; using ::nearbyintl;
	using ::rintl; using ::llroundl; using ::lroundl;
	using ::fdiml; using ::fmal; using ::fmaxl; using ::fminl;
	using ::roundl; using ::truncl;
	using ::remainderl; using ::remquol;
	using ::copysignl; using ::nanl;
	using ::nextafterl; using ::scalbnl; using ::scalblnl;
	using ::nexttowardl; using ::tgammal;

	using ::fpclassify; using ::signbit;
	using ::isfinite; using ::isinf;
	using ::isnan; using ::isnormal;
	using ::isgreater; using ::isgreaterequal;
	using ::isless; using ::islessequal;
	using ::islessgreater; using ::isunordered;
}

#pragma warning(pop)
#pragma pack(pop)

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {

	enum float_denorm_style
	{
		denorm_indeterminate = -1,
		denorm_absent = 0,
		denorm_present = 1
	};

	enum float_round_style
	{
		round_indeterminate = -1,
		round_toward_zero = 0,
		round_to_nearest = 1,
		round_toward_infinity = 2,
		round_toward_neg_infinity = 3
	};

	struct _Num_base
	{
		static constexpr float_denorm_style has_denorm = denorm_absent;
		static constexpr bool has_denorm_loss = false;
		static constexpr bool has_infinity = false;
		static constexpr bool has_quiet_NaN = false;
		static constexpr bool has_signaling_NaN = false;
		static constexpr bool is_bounded = false;
		static constexpr bool is_exact = false;
		static constexpr bool is_iec559 = false;
		static constexpr bool is_integer = false;
		static constexpr bool is_modulo = false;
		static constexpr bool is_signed = false;
		static constexpr bool is_specialized = false;
		static constexpr bool tinyness_before = false;
		static constexpr bool traps = false;
		static constexpr float_round_style round_style = round_toward_zero;
		static constexpr int digits = 0;
		static constexpr int digits10 = 0;
		static constexpr int max_digits10 = 0;
		static constexpr int max_exponent = 0;
		static constexpr int max_exponent10 = 0;
		static constexpr int min_exponent = 0;
		static constexpr int min_exponent10 = 0;
		static constexpr int radix = 0;
	};

	template<class _Ty>
	class numeric_limits
		: public _Num_base
	{
	public:
		static constexpr _Ty(min)() noexcept
		{
			return (_Ty());
		}

		static constexpr _Ty(max)() noexcept
		{
			return (_Ty());
		}

		static constexpr _Ty lowest() noexcept
		{
			return (_Ty());
		}

		static constexpr _Ty epsilon() noexcept
		{
			return (_Ty());
		}

		static constexpr _Ty round_error() noexcept
		{
			return (_Ty());
		}

		static constexpr _Ty denorm_min() noexcept
		{
			return (_Ty());
		}

		static constexpr _Ty infinity() noexcept
		{
			return (_Ty());
		}

		static constexpr _Ty quiet_NaN() noexcept
		{
			return (_Ty());
		}

		static constexpr _Ty signaling_NaN() noexcept
		{
			return (_Ty());
		}
	};

	template<class _Ty>
	class numeric_limits<const _Ty>
		: public numeric_limits<_Ty>
	{
	};

	template<class _Ty>
	class numeric_limits<volatile _Ty>
		: public numeric_limits<_Ty>
	{
	};

	template<class _Ty>
	class numeric_limits<const volatile _Ty>
		: public numeric_limits<_Ty>
	{
	};

	struct _Num_int_base
		: _Num_base
	{
		static constexpr bool is_bounded = true;
		static constexpr bool is_exact = true;
		static constexpr bool is_integer = true;
		static constexpr bool is_specialized = true;
		static constexpr int radix = 2;
	};

	struct _Num_float_base
		: _Num_base
	{
		static constexpr float_denorm_style has_denorm = denorm_present;
		static constexpr bool has_infinity = true;
		static constexpr bool has_quiet_NaN = true;
		static constexpr bool has_signaling_NaN = true;
		static constexpr bool is_bounded = true;
		static constexpr bool is_iec559 = true;
		static constexpr bool is_signed = true;
		static constexpr bool is_specialized = true;
		static constexpr float_round_style round_style = round_to_nearest;
		static constexpr int radix = 2;
	};

	template<> class numeric_limits<char>
		: public _Num_int_base
	{
	public:
		static constexpr char (min)() noexcept
		{
			return ((-128));
		}

		static constexpr char (max)() noexcept
		{
			return (127);
		}

		static constexpr char lowest() noexcept
		{
			return ((min)());
		}

		static constexpr char epsilon() noexcept
		{
			return (0);
		}

		static constexpr char round_error() noexcept
		{
			return (0);
		}

		static constexpr char denorm_min() noexcept
		{
			return (0);
		}

		static constexpr char infinity() noexcept
		{
			return (0);
		}

		static constexpr char quiet_NaN() noexcept
		{
			return (0);
		}

		static constexpr char signaling_NaN() noexcept
		{
			return (0);
		}

		static constexpr bool is_signed = (-128) != 0;
		static constexpr bool is_modulo = (-128) == 0;
		static constexpr int digits = 8 - ((-128) != 0);
		static constexpr int digits10 = 2;
	};

		template<> class numeric_limits<wchar_t>
			: public _Num_int_base
		{
		public:
			static constexpr wchar_t (min)() noexcept
			{
				return (0x0000);
			}

			static constexpr wchar_t (max)() noexcept
			{
				return (0xffff);
			}

			static constexpr wchar_t lowest() noexcept
			{
				return ((min)());
			}

			static constexpr wchar_t epsilon() noexcept
			{
				return (0);
			}

			static constexpr wchar_t round_error() noexcept
			{
				return (0);
			}

			static constexpr wchar_t denorm_min() noexcept
			{
				return (0);
			}

			static constexpr wchar_t infinity() noexcept
			{
				return (0);
			}

			static constexpr wchar_t quiet_NaN() noexcept
			{
				return (0);
			}

			static constexpr wchar_t signaling_NaN() noexcept
			{
				return (0);
			}

			static constexpr bool is_modulo = true;
			static constexpr int digits = 16;
			static constexpr int digits10 = 4;
		};

			template<> class numeric_limits<bool>
				: public _Num_int_base
			{
			public:
				static constexpr bool (min)() noexcept
				{
					return (false);
				}

				static constexpr bool (max)() noexcept
				{
					return (true);
				}

				static constexpr bool lowest() noexcept
				{
					return ((min)());
				}

				static constexpr bool epsilon() noexcept
				{
					return (0);
				}

				static constexpr bool round_error() noexcept
				{
					return (0);
				}

				static constexpr bool denorm_min() noexcept
				{
					return (0);
				}

				static constexpr bool infinity() noexcept
				{
					return (0);
				}

				static constexpr bool quiet_NaN() noexcept
				{
					return (0);
				}

				static constexpr bool signaling_NaN() noexcept
				{
					return (0);
				}

				static constexpr int digits = 1;
			};

				template<> class numeric_limits<signed char>
					: public _Num_int_base
				{
				public:
					static constexpr signed char (min)() noexcept
					{
						return ((-128));
					}

					static constexpr signed char (max)() noexcept
					{
						return (127);
					}

					static constexpr signed char lowest() noexcept
					{
						return ((min)());
					}

					static constexpr signed char epsilon() noexcept
					{
						return (0);
					}

					static constexpr signed char round_error() noexcept
					{
						return (0);
					}

					static constexpr signed char denorm_min() noexcept
					{
						return (0);
					}

					static constexpr signed char infinity() noexcept
					{
						return (0);
					}

					static constexpr signed char quiet_NaN() noexcept
					{
						return (0);
					}

					static constexpr signed char signaling_NaN() noexcept
					{
						return (0);
					}

					static constexpr bool is_signed = true;
					static constexpr int digits = 7;
					static constexpr int digits10 = 2;
				};

					template<> class numeric_limits<unsigned char>
						: public _Num_int_base
					{
					public:
						static constexpr unsigned char (min)() noexcept
						{
							return (0);
						}

						static constexpr unsigned char (max)() noexcept
						{
							return (0xff);
						}

						static constexpr unsigned char lowest() noexcept
						{
							return ((min)());
						}

						static constexpr unsigned char epsilon() noexcept
						{
							return (0);
						}

						static constexpr unsigned char round_error() noexcept
						{
							return (0);
						}

						static constexpr unsigned char denorm_min() noexcept
						{
							return (0);
						}

						static constexpr unsigned char infinity() noexcept
						{
							return (0);
						}

						static constexpr unsigned char quiet_NaN() noexcept
						{
							return (0);
						}

						static constexpr unsigned char signaling_NaN() noexcept
						{
							return (0);
						}

						static constexpr bool is_modulo = true;
						static constexpr int digits = 8;
						static constexpr int digits10 = 2;
					};

						template<> class numeric_limits<short>
							: public _Num_int_base
						{
						public:
							static constexpr short (min)() noexcept
							{
								return ((-32768));
							}

							static constexpr short (max)() noexcept
							{
								return (32767);
							}

							static constexpr short lowest() noexcept
							{
								return ((min)());
							}

							static constexpr short epsilon() noexcept
							{
								return (0);
							}

							static constexpr short round_error() noexcept
							{
								return (0);
							}

							static constexpr short denorm_min() noexcept
							{
								return (0);
							}

							static constexpr short infinity() noexcept
							{
								return (0);
							}

							static constexpr short quiet_NaN() noexcept
							{
								return (0);
							}

							static constexpr short signaling_NaN() noexcept
							{
								return (0);
							}

							static constexpr bool is_signed = true;
							static constexpr int digits = 15;
							static constexpr int digits10 = 4;
						};

							template<> class numeric_limits<unsigned short>
								: public _Num_int_base
							{
							public:
								static constexpr unsigned short (min)() noexcept
								{
									return (0);
								}

								static constexpr unsigned short (max)() noexcept
								{
									return (0xffff);
								}

								static constexpr unsigned short lowest() noexcept
								{
									return ((min)());
								}

								static constexpr unsigned short epsilon() noexcept
								{
									return (0);
								}

								static constexpr unsigned short round_error() noexcept
								{
									return (0);
								}

								static constexpr unsigned short denorm_min() noexcept
								{
									return (0);
								}

								static constexpr unsigned short infinity() noexcept
								{
									return (0);
								}

								static constexpr unsigned short quiet_NaN() noexcept
								{
									return (0);
								}

								static constexpr unsigned short signaling_NaN() noexcept
								{
									return (0);
								}

								static constexpr bool is_modulo = true;
								static constexpr int digits = 16;
								static constexpr int digits10 = 4;
							};

								template<> class numeric_limits<char16_t>
									: public _Num_int_base
								{
								public:
									static constexpr char16_t (min)() noexcept
									{
										return (0);
									}

									static constexpr char16_t (max)() noexcept
									{
										return (0xffff);
									}

									static constexpr char16_t lowest() noexcept
									{
										return ((min)());
									}

									static constexpr char16_t epsilon() noexcept
									{
										return (0);
									}

									static constexpr char16_t round_error() noexcept
									{
										return (0);
									}

									static constexpr char16_t denorm_min() noexcept
									{
										return (0);
									}

									static constexpr char16_t infinity() noexcept
									{
										return (0);
									}

									static constexpr char16_t quiet_NaN() noexcept
									{
										return (0);
									}

									static constexpr char16_t signaling_NaN() noexcept
									{
										return (0);
									}

									static constexpr bool is_modulo = true;
									static constexpr int digits = 16;
									static constexpr int digits10 = 4;
								};

									template<> class numeric_limits<int>
										: public _Num_int_base
									{
									public:
										static constexpr int (min)() noexcept
										{
											return ((-2147483647 - 1));
										}

										static constexpr int (max)() noexcept
										{
											return (2147483647);
										}

										static constexpr int lowest() noexcept
										{
											return ((min)());
										}

										static constexpr int epsilon() noexcept
										{
											return (0);
										}

										static constexpr int round_error() noexcept
										{
											return (0);
										}

										static constexpr int denorm_min() noexcept
										{
											return (0);
										}

										static constexpr int infinity() noexcept
										{
											return (0);
										}

										static constexpr int quiet_NaN() noexcept
										{
											return (0);
										}

										static constexpr int signaling_NaN() noexcept
										{
											return (0);
										}

										static constexpr bool is_signed = true;
										static constexpr int digits = 31;
										static constexpr int digits10 = 9;
									};

										template<> class numeric_limits<unsigned int>
											: public _Num_int_base
										{
										public:
											static constexpr unsigned int (min)() noexcept
											{
												return (0);
											}

											static constexpr unsigned int (max)() noexcept
											{
												return (0xffffffff);
											}

											static constexpr unsigned int lowest() noexcept
											{
												return ((min)());
											}

											static constexpr unsigned int epsilon() noexcept
											{
												return (0);
											}

											static constexpr unsigned int round_error() noexcept
											{
												return (0);
											}

											static constexpr unsigned int denorm_min() noexcept
											{
												return (0);
											}

											static constexpr unsigned int infinity() noexcept
											{
												return (0);
											}

											static constexpr unsigned int quiet_NaN() noexcept
											{
												return (0);
											}

											static constexpr unsigned int signaling_NaN() noexcept
											{
												return (0);
											}

											static constexpr bool is_modulo = true;
											static constexpr int digits = 32;
											static constexpr int digits10 = 9;
										};

											template<> class numeric_limits<long>
												: public _Num_int_base
											{
											public:
												static constexpr long (min)() noexcept
												{
													return ((-2147483647L - 1));
												}

												static constexpr long (max)() noexcept
												{
													return (2147483647L);
												}

												static constexpr long lowest() noexcept
												{
													return ((min)());
												}

												static constexpr long epsilon() noexcept
												{
													return (0);
												}

												static constexpr long round_error() noexcept
												{
													return (0);
												}

												static constexpr long denorm_min() noexcept
												{
													return (0);
												}

												static constexpr long infinity() noexcept
												{
													return (0);
												}

												static constexpr long quiet_NaN() noexcept
												{
													return (0);
												}

												static constexpr long signaling_NaN() noexcept
												{
													return (0);
												}

												static_assert(sizeof(int) == sizeof(long), "LLP64 assumption");
												static constexpr bool is_signed = true;
												static constexpr int digits = 31;
												static constexpr int digits10 = 9;
											};

												template<> class numeric_limits<unsigned long>
													: public _Num_int_base
												{
												public:
													static constexpr unsigned long (min)() noexcept
													{
														return (0);
													}

													static constexpr unsigned long (max)() noexcept
													{
														return (0xffffffffUL);
													}

													static constexpr unsigned long lowest() noexcept
													{
														return ((min)());
													}

													static constexpr unsigned long epsilon() noexcept
													{
														return (0);
													}

													static constexpr unsigned long round_error() noexcept
													{
														return (0);
													}

													static constexpr unsigned long denorm_min() noexcept
													{
														return (0);
													}

													static constexpr unsigned long infinity() noexcept
													{
														return (0);
													}

													static constexpr unsigned long quiet_NaN() noexcept
													{
														return (0);
													}

													static constexpr unsigned long signaling_NaN() noexcept
													{
														return (0);
													}

													static_assert(sizeof(unsigned int) == sizeof(unsigned long), "LLP64 assumption");
													static constexpr bool is_modulo = true;
													static constexpr int digits = 32;
													static constexpr int digits10 = 9;
												};

													template<> class numeric_limits<char32_t>
														: public _Num_int_base
													{
													public:
														static constexpr char32_t (min)() noexcept
														{
															return (0);
														}

														static constexpr char32_t (max)() noexcept
														{
															return (0xffffffff);
														}

														static constexpr char32_t lowest() noexcept
														{
															return ((min)());
														}

														static constexpr char32_t epsilon() noexcept
														{
															return (0);
														}

														static constexpr char32_t round_error() noexcept
														{
															return (0);
														}

														static constexpr char32_t denorm_min() noexcept
														{
															return (0);
														}

														static constexpr char32_t infinity() noexcept
														{
															return (0);
														}

														static constexpr char32_t quiet_NaN() noexcept
														{
															return (0);
														}

														static constexpr char32_t signaling_NaN() noexcept
														{
															return (0);
														}

														static constexpr bool is_modulo = true;
														static constexpr int digits = 32;
														static constexpr int digits10 = 9;
													};

														template<> class numeric_limits<long long>
															: public _Num_int_base
														{
														public:
															static constexpr long long (min)() noexcept
															{
																return ((-9223372036854775807i64 - 1));
															}

															static constexpr long long (max)() noexcept
															{
																return (9223372036854775807i64);
															}

															static constexpr long long lowest() noexcept
															{
																return ((min)());
															}

															static constexpr long long epsilon() noexcept
															{
																return (0);
															}

															static constexpr long long round_error() noexcept
															{
																return (0);
															}

															static constexpr long long denorm_min() noexcept
															{
																return (0);
															}

															static constexpr long long infinity() noexcept
															{
																return (0);
															}

															static constexpr long long quiet_NaN() noexcept
															{
																return (0);
															}

															static constexpr long long signaling_NaN() noexcept
															{
																return (0);
															}

															static constexpr bool is_signed = true;
															static constexpr int digits = 63;
															static constexpr int digits10 = 18;
														};

															template<> class numeric_limits<unsigned long long>
																: public _Num_int_base
															{
															public:
																static constexpr unsigned long long (min)() noexcept
																{
																	return (0);
																}

																static constexpr unsigned long long (max)() noexcept
																{
																	return (0xffffffffffffffffui64);
																}

																static constexpr unsigned long long lowest() noexcept
																{
																	return ((min)());
																}

																static constexpr unsigned long long epsilon() noexcept
																{
																	return (0);
																}

																static constexpr unsigned long long round_error() noexcept
																{
																	return (0);
																}

																static constexpr unsigned long long denorm_min() noexcept
																{
																	return (0);
																}

																static constexpr unsigned long long infinity() noexcept
																{
																	return (0);
																}

																static constexpr unsigned long long quiet_NaN() noexcept
																{
																	return (0);
																}

																static constexpr unsigned long long signaling_NaN() noexcept
																{
																	return (0);
																}

																static constexpr bool is_modulo = true;
																static constexpr int digits = 64;
																static constexpr int digits10 = 19;
															};

																template<> class numeric_limits<float>
																	: public _Num_float_base
																{
																public:
																	static constexpr float (min)() noexcept
																	{
																		return (1.175494351e-38F);
																	}

																	static constexpr float (max)() noexcept
																	{
																		return (3.402823466e+38F);
																	}

																	static constexpr float lowest() noexcept
																	{
																		return (-(max)());
																	}

																	static constexpr float epsilon() noexcept
																	{
																		return (1.192092896e-07F);
																	}

																	static constexpr float round_error() noexcept
																	{
																		return (0.5F);
																	}

																	static constexpr float denorm_min() noexcept
																	{
																		return (1.401298464e-45F);
																	}

																	static constexpr float infinity() noexcept
																	{
																		return (__builtin_huge_valf());
																	}

																	static constexpr float quiet_NaN() noexcept
																	{
																		return (__builtin_nanf("0"));
																	}

																	static constexpr float signaling_NaN() noexcept
																	{
																		return (__builtin_nansf("1"));
																	}

																	static constexpr int digits = 24;
																	static constexpr int digits10 = 6;
																	static constexpr int max_digits10 = 9;
																	static constexpr int max_exponent = 128;
																	static constexpr int max_exponent10 = 38;
																	static constexpr int min_exponent = (-125);
																	static constexpr int min_exponent10 = (-37);
																};

																	template<> class numeric_limits<double>
																		: public _Num_float_base
																	{
																	public:
																		static constexpr double (min)() noexcept
																		{
																			return (2.2250738585072014e-308);
																		}

																		static constexpr double (max)() noexcept
																		{
																			return (1.7976931348623158e+308);
																		}

																		static constexpr double lowest() noexcept
																		{
																			return (-(max)());
																		}

																		static constexpr double epsilon() noexcept
																		{
																			return (2.2204460492503131e-016);
																		}

																		static constexpr double round_error() noexcept
																		{
																			return (0.5);
																		}

																		static constexpr double denorm_min() noexcept
																		{
																			return (4.9406564584124654e-324);
																		}

																		static constexpr double infinity() noexcept
																		{
																			return (__builtin_huge_val());
																		}

																		static constexpr double quiet_NaN() noexcept
																		{
																			return (__builtin_nan("0"));
																		}

																		static constexpr double signaling_NaN() noexcept
																		{
																			return (__builtin_nans("1"));
																		}

																		static constexpr int digits = 53;
																		static constexpr int digits10 = 15;
																		static constexpr int max_digits10 = 17;
																		static constexpr int max_exponent = 1024;
																		static constexpr int max_exponent10 = 308;
																		static constexpr int min_exponent = (-1021);
																		static constexpr int min_exponent10 = (-307);
																	};

																		template<> class numeric_limits<long double>
																			: public _Num_float_base
																		{
																		public:
																			static constexpr long double (min)() noexcept
																			{
																				return (2.2250738585072014e-308);
																			}

																			static constexpr long double (max)() noexcept
																			{
																				return (1.7976931348623158e+308);
																			}

																			static constexpr long double lowest() noexcept
																			{
																				return (-(max)());
																			}

																			static constexpr long double epsilon() noexcept
																			{
																				return (2.2204460492503131e-016);
																			}

																			static constexpr long double round_error() noexcept
																			{
																				return (0.5L);
																			}

																			static constexpr long double denorm_min() noexcept
																			{
																				return (4.9406564584124654e-324);
																			}

																			static constexpr long double infinity() noexcept
																			{
																				return (__builtin_huge_val());
																			}

																			static constexpr long double quiet_NaN() noexcept
																			{
																				return (__builtin_nan("0"));
																			}

																			static constexpr long double signaling_NaN() noexcept
																			{
																				return (__builtin_nans("1"));
																			}

																			static constexpr int digits = 53;
																			static constexpr int digits10 = 15;
																			static constexpr int max_digits10 = 17;
																			static constexpr int max_exponent = 1024;
																			static constexpr int max_exponent10 = 308;
																			static constexpr int min_exponent = (-1021);
																			static constexpr int min_exponent10 = (-307);
																		};
}

#pragma warning(pop)
#pragma pack(pop)

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {

	template<size_t _Ty_size> inline
		size_t _Get_size_of_n(const size_t _Count)
	{
		constexpr size_t _Max_possible = static_cast<size_t>(-1) / _Ty_size;
		size_t _Result = _Count * _Ty_size;
		if (_Max_possible < _Count)
		{

			_Result = static_cast<size_t>(-1);
		}

		return (_Result);
	}

	template<> inline
		size_t _Get_size_of_n<1>(const size_t _Count)
	{
		return (_Count);
	}

	template<class _Ty>
	constexpr size_t _New_alignof = _Max_value(alignof(_Ty),
		static_cast<size_t>(8u)
	);

	struct _Default_allocate_traits
	{
		__declspec(allocator) static void * _Allocate(const size_t _Bytes)
		{
			return (::operator new(_Bytes));
		}

	};

	constexpr bool _Is_pow_2(const size_t _Value) noexcept
	{
		return (_Value != 0 && (_Value & (_Value - 1)) == 0);
	}

	constexpr size_t _Big_allocation_threshold = 4096;
	constexpr size_t _Big_allocation_alignment = 32;

	static_assert(2 * sizeof(void *) <= _Big_allocation_alignment,
		"Big allocation alignment should at least match vector register alignment");
	static_assert(_Is_pow_2(_Big_allocation_alignment),
		"Big allocation alignment must be a power of two");

	constexpr size_t _Non_user_size = 2 * sizeof(void *) + _Big_allocation_alignment - 1;

	constexpr size_t _Big_allocation_sentinel = 0xFAFAFAFAUL;

	template<class _Traits> inline
		__declspec(allocator) void * _Allocate_manually_vector_aligned(const size_t _Bytes)
	{
		size_t _Block_size = _Non_user_size + _Bytes;
		if (_Block_size <= _Bytes)
		{

			_Block_size = static_cast<size_t>(-1);
		}

		const uintptr_t _Ptr_container = reinterpret_cast<uintptr_t>(_Traits::_Allocate(_Block_size));
		do { if (_Ptr_container != 0) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xmemory0", 101, 0, "%s", "invalid argument")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"invalid argument\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xmemory0", 101, 0); } while (false); }; } while (false);
		void * const _Ptr = reinterpret_cast<void *>((_Ptr_container + _Non_user_size)
			& ~(_Big_allocation_alignment - 1));
		static_cast<uintptr_t *>(_Ptr)[-1] = _Ptr_container;

		static_cast<uintptr_t *>(_Ptr)[-2] = _Big_allocation_sentinel;

		return (_Ptr);
	}

	inline void _Adjust_manually_vector_aligned(void *& _Ptr, size_t& _Bytes)
	{
		_Bytes += _Non_user_size;

		const uintptr_t * const _Ptr_user = reinterpret_cast<uintptr_t *>(_Ptr);
		const uintptr_t _Ptr_container = _Ptr_user[-1];

		do { if (_Ptr_user[-2] == _Big_allocation_sentinel) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xmemory0", 122, 0, "%s", "invalid argument")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"invalid argument\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xmemory0", 122, 0); } while (false); }; } while (false);

		constexpr uintptr_t _Min_back_shift = 2 * sizeof(void *);

		const uintptr_t _Back_shift = reinterpret_cast<uintptr_t>(_Ptr) - _Ptr_container;
		do { if (_Back_shift >= _Min_back_shift && _Back_shift <= _Non_user_size) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xmemory0", 132, 0, "%s", "invalid argument")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"invalid argument\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xmemory0", 132, 0); } while (false); }; } while (false);
		_Ptr = reinterpret_cast<void *>(_Ptr_container);
	}

	template<size_t _Align,
		class _Traits = _Default_allocate_traits,
		enable_if_t<(!0 || _Align <= 8u), int> = 0> inline
		__declspec(allocator) void *_Allocate(const size_t _Bytes)
	{

		if (_Bytes >= _Big_allocation_threshold)
		{
			return (_Allocate_manually_vector_aligned<_Traits>(_Bytes));
		}

		if (_Bytes != 0)
		{
			return (_Traits::_Allocate(_Bytes));
		}

		return (nullptr);
	}

	template<size_t _Align,
		enable_if_t<(!0 || _Align <= 8u), int> = 0> inline
		void _Deallocate(void * _Ptr, size_t _Bytes)
	{

		if (_Bytes >= _Big_allocation_threshold)
		{
			_Adjust_manually_vector_aligned(_Ptr, _Bytes);
		}

		::operator delete(_Ptr, _Bytes);
	}

	template<class _Ty,
		class... _Types> inline
		void _Construct_in_place(_Ty& _Obj, _Types&&... _Args)
		noexcept(is_nothrow_constructible_v<_Ty, _Types...>)
	{
		::new (const_cast<void *>(static_cast<const volatile void *>(::std::addressof(_Obj))))
			_Ty(::std::forward<_Types>(_Args)...);
	}

	template<class _Ty,
		class... _Types> inline
		_Ty * _Global_new(_Types&&... _Args)
	{
		void * const _Result = _Allocate<_New_alignof<_Ty>>(sizeof(_Ty));
		try {
			::new (_Result) _Ty(::std::forward<_Types>(_Args)...);
		}
		catch (...) {
			_Deallocate<_New_alignof<_Ty>>(_Result, sizeof(_Ty));
			throw;
		}
		return (static_cast<_Ty *>(_Result));
	}

	template<class _Ty>
	struct _Get_first_parameter;

	template<template<class, class...> class _Ty,
		class _First,
		class... _Rest>
		struct _Get_first_parameter<_Ty<_First, _Rest...>>
	{
		using type = _First;
	};

	template<class _Newfirst,
		class _Ty>
		struct _Replace_first_parameter;

	template<class _Newfirst,
		template<class, class...> class _Ty,
		class _First,
		class... _Rest>
		struct _Replace_first_parameter<_Newfirst, _Ty<_First, _Rest...>>
	{
		using type = _Ty<_Newfirst, _Rest...>;
	};

	template<class _Ty,
		class = void>
		struct _Get_element_type
	{
		using type = typename _Get_first_parameter<_Ty>::type;
	};

	template<class _Ty>
	struct _Get_element_type<_Ty, void_t<typename _Ty::element_type>>
	{
		using type = typename _Ty::element_type;
	};

	template<class _Ty,
		class = void>
		struct _Get_ptr_difference_type
	{
		using type = ptrdiff_t;
	};

	template<class _Ty>
	struct _Get_ptr_difference_type<_Ty, void_t<typename _Ty::difference_type>>
	{
		using type = typename _Ty::difference_type;
	};

	template<class _Ty,
		class _Other,
		class = void>
		struct _Get_rebind_alias
	{
		using type = typename _Replace_first_parameter<_Other, _Ty>::type;
	};

	template<class _Ty,
		class _Other>
		struct _Get_rebind_alias<_Ty, _Other, void_t<typename _Ty::template rebind<_Other>>>
	{
		using type = typename _Ty::template rebind<_Other>;
	};

	template<class _Ty>
	struct pointer_traits
	{
		using element_type = typename _Get_element_type<_Ty>::type;
		using pointer = _Ty;
		using difference_type = typename _Get_ptr_difference_type<_Ty>::type;

		template<class _Other>
		using rebind = typename _Get_rebind_alias<_Ty, _Other>::type;

		using _Reftype = conditional_t<is_void_v<element_type>,
			char&,
			add_lvalue_reference_t<element_type>>;

		static pointer pointer_to(_Reftype _Val)
		{
			return (_Ty::pointer_to(_Val));
		}
	};

	template<class _Ty>
	struct pointer_traits<_Ty *>
	{
		using element_type = _Ty;
		using pointer = _Ty * ;
		using difference_type = ptrdiff_t;

		template<class _Other>
		using rebind = _Other * ;

		using _Reftype = conditional_t<is_void_v<_Ty>,
			char&,
			add_lvalue_reference_t<_Ty>>;

		static pointer pointer_to(_Reftype _Val)
		{
			return (::std::addressof(_Val));
		}
	};

	template<class _Ptr,
		class _Ty>
		using _Rebind_pointer_t = typename pointer_traits<_Ptr>::template rebind<_Ty>;

	template<class _Pointer,
		enable_if_t<!is_pointer_v<_Pointer>, int> = 0> inline
		_Pointer _Refancy(typename pointer_traits<_Pointer>::element_type * _Ptr)
	{
		return (pointer_traits<_Pointer>::pointer_to(*_Ptr));
	}

	template<class _Pointer,
		enable_if_t<is_pointer_v<_Pointer>, int> = 0> inline
		_Pointer _Refancy(_Pointer _Ptr)
	{
		return (_Ptr);
	}

	template<class _Ty> inline
		void _Destroy_in_place(_Ty& _Obj) noexcept
	{
		_Obj.~_Ty();
	}

	template<class _Ptrty> inline
		auto _Const_cast(_Ptrty _Ptr)
	{
		using _Elem = typename pointer_traits<_Ptrty>::element_type;
		using _Modifiable = remove_const_t<_Elem>;
		using _Dest = typename pointer_traits<_Ptrty>::template rebind<_Modifiable>;

		return (pointer_traits<_Dest>::pointer_to(const_cast<_Modifiable&>(*_Ptr)));
	}

	template<class _Ty> inline
		auto _Const_cast(_Ty * _Ptr)
	{
		return (const_cast<remove_const_t<_Ty> *>(_Ptr));
	}

	template<class _Ty,
		class = void>
		struct _Get_pointer_type
	{
		using type = typename _Ty::value_type *;
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Ty>
	struct _Get_pointer_type<_Ty, void_t<typename _Ty::pointer>>
	{
		using type = typename _Ty::pointer;
	};
#pragma warning(pop)

	template<class _Ty,
		class = void>
		struct _Get_const_pointer_type
	{
		using _Ptrty = typename _Get_pointer_type<_Ty>::type;
		using _Valty = typename _Ty::value_type;
		using type = typename pointer_traits<_Ptrty>::template rebind<const _Valty>;
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Ty>
	struct _Get_const_pointer_type<_Ty, void_t<typename _Ty::const_pointer>>
	{
		using type = typename _Ty::const_pointer;
	};
#pragma warning(pop)

	template<class _Ty,
		class = void>
		struct _Get_void_pointer_type
	{
		using _Ptrty = typename _Get_pointer_type<_Ty>::type;
		using type = typename pointer_traits<_Ptrty>::template rebind<void>;
	};

	template<class _Ty>
	struct _Get_void_pointer_type<_Ty, void_t<typename _Ty::void_pointer>>
	{
		using type = typename _Ty::void_pointer;
	};

	template<class _Ty,
		class = void>
		struct _Get_const_void_pointer_type
	{
		using _Ptrty = typename _Get_pointer_type<_Ty>::type;
		using type = typename pointer_traits<_Ptrty>::template rebind<const void>;
	};

	template<class _Ty>
	struct _Get_const_void_pointer_type<_Ty, void_t<typename _Ty::const_void_pointer>>
	{
		using type = typename _Ty::const_void_pointer;
	};

	template<class _Ty,
		class = void>
		struct _Get_difference_type
	{
		using _Ptrty = typename _Get_pointer_type<_Ty>::type;
		using type = typename pointer_traits<_Ptrty>::difference_type;
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Ty>
	struct _Get_difference_type<_Ty, void_t<typename _Ty::difference_type>>
	{
		using type = typename _Ty::difference_type;
	};
#pragma warning(pop)

	template<class _Ty,
		class = void>
		struct _Get_size_type
	{
		using type = make_unsigned_t<typename _Get_difference_type<_Ty>::type>;
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Ty>
	struct _Get_size_type<_Ty, void_t<typename _Ty::size_type>>
	{
		using type = typename _Ty::size_type;
	};
#pragma warning(pop)

	template<class _Ty,
		class = void>
		struct _Get_propagate_on_container_copy
	{
		using type = false_type;
	};

	template<class _Ty>
	struct _Get_propagate_on_container_copy<_Ty, void_t<typename _Ty::propagate_on_container_copy_assignment>>
	{
		using type = typename _Ty::propagate_on_container_copy_assignment;
	};

	template<class _Ty,
		class = void>
		struct _Get_propagate_on_container_move
	{
		using type = false_type;
	};

	template<class _Ty>
	struct _Get_propagate_on_container_move<_Ty, void_t<typename _Ty::propagate_on_container_move_assignment>>
	{
		using type = typename _Ty::propagate_on_container_move_assignment;
	};

	template<class _Ty,
		class = void>
		struct _Get_propagate_on_container_swap
	{
		using type = false_type;
	};

	template<class _Ty>
	struct _Get_propagate_on_container_swap<_Ty, void_t<typename _Ty::propagate_on_container_swap>>
	{
		using type = typename _Ty::propagate_on_container_swap;
	};

	template<class _Ty,
		class = void>
		struct _Get_is_always_equal
	{
		using type = typename is_empty<_Ty>::type;
	};

	template<class _Ty>
	struct _Get_is_always_equal<_Ty, void_t<typename _Ty::is_always_equal>>
	{
		using type = typename _Ty::is_always_equal;
	};

	template<class _Ty,
		class _Other,
		class = void>
		struct _Get_rebind_type
	{
		using type = typename _Replace_first_parameter<_Other, _Ty>::type;
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Ty,
		class _Other>
		struct _Get_rebind_type<_Ty, _Other, void_t<typename _Ty::template rebind<_Other>::other>>
	{
		using type = typename _Ty::template rebind<_Other>::other;
	};
#pragma warning(pop)

	template<class _Ty>
	class allocator;

	template<class _Alloc,
		class = void>
		struct _Is_default_allocator
		: false_type
	{
	};

	template<class _Ty>
	struct _Is_default_allocator<allocator<_Ty>, typename allocator<_Ty>::_Not_user_specialized>
		: true_type
	{
	};

	template<class _Void,
		class... _Types>
		struct _Has_no_alloc_construct
		: true_type
	{
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Alloc,
		class _Ptr,
		class... _Args>
		struct _Has_no_alloc_construct<void_t<
		decltype(::std::declval<_Alloc&>().construct(::std::declval<_Ptr>(), ::std::declval<_Args>()...))>,
		_Alloc, _Ptr, _Args...>
		: false_type
	{
	};
#pragma warning(pop)

	template<class _Alloc,
		class _Ptr,
		class... _Args>
		using _Uses_default_construct = disjunction<
		_Is_default_allocator<_Alloc>,
		_Has_no_alloc_construct<void, _Alloc, _Ptr, _Args...>>;

	template<class _Alloc,
		class _Ptr,
		class... _Args>
		using _Uses_default_construct_t = typename _Uses_default_construct<_Alloc, _Ptr, _Args...>::type;

	template<class _Alloc,
		class _Ptr,
		class = void>
		struct _Has_no_alloc_destroy
		: true_type
	{
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Alloc,
		class _Ptr>
		struct _Has_no_alloc_destroy<_Alloc, _Ptr, void_t<decltype(::std::declval<_Alloc&>().destroy(::std::declval<_Ptr>()))>>
		: false_type
	{
	};
#pragma warning(pop)

	template<class _Alloc,
		class _Ptr>
		using _Uses_default_destroy = disjunction<
		_Is_default_allocator<_Alloc>,
		_Has_no_alloc_destroy<_Alloc, _Ptr>>;

	template<class _Alloc,
		class _Ptr>
		using _Uses_default_destroy_t = typename _Uses_default_destroy<_Alloc, _Ptr>::type;

	template<class _Alloc,
		class _Size_type,
		class _Const_void_pointer,
		class = void>
		struct _Has_allocate_hint
		: false_type
	{
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Alloc,
		class _Size_type,
		class _Const_void_pointer>
		struct _Has_allocate_hint<_Alloc, _Size_type, _Const_void_pointer, void_t<
		decltype(::std::declval<_Alloc&>().allocate(
			::std::declval<const _Size_type&>(), ::std::declval<const _Const_void_pointer&>()))>>
		: true_type
	{
	};
#pragma warning(pop)

	template<class _Alloc,
		class = void>
		struct _Has_max_size
		: false_type
	{
	};

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Alloc>
	struct _Has_max_size<_Alloc, void_t<decltype(::std::declval<const _Alloc&>().max_size())>>
		: true_type
	{
	};
#pragma warning(pop)

	template<class _Alloc,
		class = void>
		struct _Has_select_on_container_copy_construction
		: false_type
	{
	};

	template<class _Alloc>
	struct _Has_select_on_container_copy_construction<_Alloc, void_t<
		decltype(::std::declval<const _Alloc&>().select_on_container_copy_construction())>>
		: true_type
	{
	};

	template<class _Alloc>
	struct allocator_traits;

#pragma warning(push)
#pragma warning(disable: 4996)	
	template<class _Alloc>
	struct _Normal_allocator_traits
	{
		using allocator_type = _Alloc;
		using value_type = typename _Alloc::value_type;

		using pointer = typename _Get_pointer_type<_Alloc>::type;
		using const_pointer = typename _Get_const_pointer_type<_Alloc>::type;
		using void_pointer = typename _Get_void_pointer_type<_Alloc>::type;
		using const_void_pointer = typename _Get_const_void_pointer_type<_Alloc>::type;

		using size_type = typename _Get_size_type<_Alloc>::type;
		using difference_type = typename _Get_difference_type<_Alloc>::type;

		using propagate_on_container_copy_assignment = typename _Get_propagate_on_container_copy<_Alloc>::type;
		using propagate_on_container_move_assignment = typename _Get_propagate_on_container_move<_Alloc>::type;
		using propagate_on_container_swap = typename _Get_propagate_on_container_swap<_Alloc>::type;
		using is_always_equal = typename _Get_is_always_equal<_Alloc>::type;

		template<class _Other>
		using rebind_alloc = typename _Get_rebind_type<_Alloc, _Other>::type;

		template<class _Other>
		using rebind_traits = allocator_traits<rebind_alloc<_Other>>;

		static __declspec(allocator) pointer allocate(_Alloc& _Al, const size_type _Count)
		{
			return (_Al.allocate(_Count));
		}

		static __declspec(allocator) pointer _Allocate1(_Alloc& _Al, const size_type _Count,
			const const_void_pointer _Hint, true_type)
		{
			return (_Al.allocate(_Count, _Hint));
		}

		static __declspec(allocator) pointer _Allocate1(_Alloc& _Al, const size_type _Count,
			const_void_pointer, false_type)
		{
			return (_Al.allocate(_Count));
		}

		static __declspec(allocator) pointer allocate(_Alloc& _Al, const size_type _Count,
			const const_void_pointer _Hint)
		{
			return (_Allocate1(_Al, _Count, _Hint, _Has_allocate_hint<_Alloc, size_type, const_void_pointer>{}));
		}

		static void deallocate(_Alloc& _Al, pointer _Ptr, size_type _Count)
		{
			_Al.deallocate(_Ptr, _Count);
		}

		template<class _Ty,
			class... _Types>
			static void _Construct1(true_type, _Alloc&, _Ty *_Ptr, _Types&&... _Args)
		{
			::new (static_cast<void *>(_Ptr)) _Ty(::std::forward<_Types>(_Args)...);
		}

		template<class _Ty,
			class... _Types>
			static void _Construct1(false_type, _Alloc& _Al, _Ty *_Ptr, _Types&&... _Args)
		{
			_Al.construct(_Ptr, ::std::forward<_Types>(_Args)...);
		}

		template<class _Ty,
			class... _Types>
			static void construct(_Alloc& _Al, _Ty *_Ptr, _Types&&... _Args)
		{
			_Construct1(_Uses_default_construct_t<_Alloc, _Ty *, _Types...>(),
				_Al, _Ptr, ::std::forward<_Types>(_Args)...);
		}

		template<class _Ty>
		static void _Destroy1(_Alloc&, _Ty *_Ptr, true_type)
		{
			_Ptr->~_Ty();
		}

		template<class _Ty>
		static void _Destroy1(_Alloc& _Al, _Ty *_Ptr, false_type)
		{
			_Al.destroy(_Ptr);
		}

		template<class _Ty>
		static void destroy(_Alloc& _Al, _Ty *_Ptr)
		{
			_Destroy1(_Al, _Ptr, _Uses_default_destroy_t<_Alloc, _Ty *>());
		}

		static size_type _Max_size1(const _Alloc& _Al, true_type) noexcept
		{
			return (_Al.max_size());
		}

		static size_type _Max_size1(const _Alloc&, false_type) noexcept
		{
			return ((numeric_limits<size_type>::max)() / sizeof(value_type));
		}

		static size_type max_size(const _Alloc& _Al) noexcept
		{
			return (_Max_size1(_Al, _Has_max_size<_Alloc>{}));
		}

		static _Alloc _Select_on_container_copy_construction1(const _Alloc& _Al, true_type)
		{
			return (_Al.select_on_container_copy_construction());
		}

		static _Alloc _Select_on_container_copy_construction1(const _Alloc& _Al, false_type)
		{
			return (_Al);
		}

		static _Alloc select_on_container_copy_construction(const _Alloc& _Al)
		{
			return (_Select_on_container_copy_construction1(_Al, _Has_select_on_container_copy_construction<_Alloc>{}));
		}
	};
#pragma warning(pop)

	template<class _Alloc>
	struct _Default_allocator_traits
	{
		using allocator_type = _Alloc;
		using value_type = typename _Alloc::value_type;

		using pointer = value_type * ;
		using const_pointer = const value_type *;
		using void_pointer = void *;
		using const_void_pointer = const void *;

		using size_type = size_t;
		using difference_type = ptrdiff_t;

		using propagate_on_container_copy_assignment = false_type;
		using propagate_on_container_move_assignment = true_type;
		using propagate_on_container_swap = false_type;
		using is_always_equal = true_type;

		template<class _Other>
		using rebind_alloc = allocator<_Other>;

		template<class _Other>
		using rebind_traits = allocator_traits<allocator<_Other>>;

		static __declspec(allocator) pointer allocate(_Alloc&, const size_type _Count)
		{
			return (static_cast<pointer>(_Allocate<_New_alignof<value_type>>(_Get_size_of_n<sizeof(value_type)>(_Count))));
		}

		static __declspec(allocator) pointer allocate(_Alloc&, const size_type _Count,
			const_void_pointer)
		{
			return (static_cast<pointer>(_Allocate<_New_alignof<value_type>>(_Get_size_of_n<sizeof(value_type)>(_Count))));
		}

		static void deallocate(_Alloc&, const pointer _Ptr, const size_type _Count)
		{

			_Deallocate<_New_alignof<value_type>>(_Ptr, sizeof(value_type) * _Count);
		}

		template<class _Objty,
			class... _Types>
			static void construct(_Alloc&, _Objty * const _Ptr, _Types&&... _Args)
		{
			::new (const_cast<void *>(static_cast<const volatile void *>(_Ptr)))
				_Objty(::std::forward<_Types>(_Args)...);
		}

		template<class _Uty>
		static void destroy(_Alloc&, _Uty * const _Ptr)
		{
			_Ptr->~_Uty();
		}

		static size_type max_size(const _Alloc&) noexcept
		{
			return (static_cast<size_t>(-1) / sizeof(value_type));
		}

		static _Alloc select_on_container_copy_construction(const _Alloc& _Al)
		{
			return (_Al);
		}
	};

	template<class _Alloc>
	struct allocator_traits
		: conditional_t<_Is_default_allocator<_Alloc>::value,
		_Default_allocator_traits<_Alloc>, _Normal_allocator_traits<_Alloc>>
	{
	};

	template<class _Alloc>
	constexpr bool _Always_equal_after_move = allocator_traits<_Alloc>::is_always_equal::value
		|| allocator_traits<_Alloc>::propagate_on_container_move_assignment::value;

	template<class _Alloc,
		class _Value_type>
		using _Rebind_alloc_t = typename allocator_traits<_Alloc>::template rebind_alloc<_Value_type>;

	template<class _Alloc>
	constexpr bool _Is_simple_alloc_v =
		is_same_v<typename allocator_traits<_Alloc>::size_type, size_t>
		&& is_same_v<typename allocator_traits<_Alloc>::difference_type, ptrdiff_t>
		&& is_same_v<typename allocator_traits<_Alloc>::pointer, typename _Alloc::value_type *>
		&& is_same_v<typename allocator_traits<_Alloc>::const_pointer, const typename _Alloc::value_type *>;

	template<class _Value_type>
	struct _Simple_types
	{

		using value_type = _Value_type;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using pointer = value_type * ;
		using const_pointer = const value_type *;
	};

	template<class _Ty>
	class allocator
	{
	public:
		static_assert(!is_const_v<_Ty>,
			"The C++ Standard forbids containers of const elements "
			"because allocator<const T> is ill-formed.");

		using _Not_user_specialized = void;

		using value_type = _Ty;

		typedef _Ty * pointer;
		typedef const _Ty * const_pointer;

		typedef _Ty& reference;
		typedef const _Ty& const_reference;

		typedef size_t size_type;
		typedef ptrdiff_t difference_type;

		using propagate_on_container_move_assignment = true_type;
		using is_always_equal = true_type;

		template<class _Other>
		struct  rebind
		{
			using other = allocator<_Other>;
		};

		_Ty * address(_Ty& _Val) const noexcept
		{
			return (::std::addressof(_Val));
		}

		const _Ty * address(const _Ty& _Val) const noexcept
		{
			return (::std::addressof(_Val));
		}

		constexpr allocator() noexcept
		{
		}

		constexpr allocator(const allocator&) noexcept = default;
		template<class _Other>
		constexpr allocator(const allocator<_Other>&) noexcept
		{
		}

		void deallocate(_Ty * const _Ptr, const size_t _Count)
		{

			_Deallocate<_New_alignof<_Ty>>(_Ptr, sizeof(_Ty) * _Count);
		}

		__declspec(allocator) _Ty * allocate(const size_t _Count)
		{
			return (static_cast<_Ty *>(_Allocate<_New_alignof<_Ty>>(_Get_size_of_n<sizeof(_Ty)>(_Count))));
		}

		__declspec(allocator) _Ty * allocate(
			const size_t _Count, const void *)
		{
			return (allocate(_Count));
		}

		template<class _Objty,
			class... _Types>
			void construct(_Objty * const _Ptr, _Types&&... _Args)
		{
			::new (const_cast<void *>(static_cast<const volatile void *>(_Ptr)))
				_Objty(::std::forward<_Types>(_Args)...);
		}

		template<class _Uty>
		void destroy(_Uty * const _Ptr)
		{
			_Ptr->~_Uty();
		}

		size_t max_size() const noexcept
		{
			return (static_cast<size_t>(-1) / sizeof(_Ty));
		}
	};

	template<>
	class  allocator<void>
	{
	public:
		using value_type = void;
		using pointer = void *;
		using const_pointer = const void *;

		template<class _Other>
		struct rebind
		{
			using other = allocator<_Other>;
		};
	};

	template<class _Ty,
		class _Other>
		inline bool operator==(const allocator<_Ty>&,
			const allocator<_Other>&) noexcept
	{
		return (true);
	}

	template<class _Ty,
		class _Other>
		inline bool operator!=(const allocator<_Ty>&,
			const allocator<_Other>&) noexcept
	{
		return (false);
	}

	template<class _Alloc> inline
		void _Pocca(_Alloc& _Left, const _Alloc& _Right, true_type) noexcept
	{
		_Left = _Right;
	}

	template<class _Alloc> inline
		void _Pocca(_Alloc&, const _Alloc&, false_type) noexcept
	{
	}

	template<class _Alloc> inline
		void _Pocca(_Alloc& _Left, const _Alloc& _Right) noexcept
	{
		typename allocator_traits<_Alloc>::propagate_on_container_copy_assignment _Tag;
		_Pocca(_Left, _Right, _Tag);
	}

	template<class _Alloc> inline
		void _Pocma(_Alloc& _Left, _Alloc& _Right, true_type) noexcept
	{
		_Left = ::std::move(_Right);
	}

	template<class _Alloc> inline
		void _Pocma(_Alloc&, _Alloc&, false_type) noexcept
	{
	}

	template<class _Alloc> inline
		void _Pocma(_Alloc& _Left, _Alloc& _Right) noexcept
	{
		typename allocator_traits<_Alloc>::propagate_on_container_move_assignment _Tag;
		_Pocma(_Left, _Right, _Tag);
	}

	template<class _Alloc> inline
		void _Pocs(_Alloc& _Left, _Alloc& _Right, true_type) noexcept
	{
		_Swap_adl(_Left, _Right);
	}

	template<class _Alloc> inline
		void _Pocs(_Alloc& _Left, _Alloc& _Right, false_type) noexcept
	{
		do { if (_Left == _Right) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xmemory0", 1114, 0, "%s", "containers incompatible for swap")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"containers incompatible for swap\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xmemory0", 1114, 0); } while (false); }; } while (false);
		(void)_Left;
		(void)_Right;
	}

	template<class _Alloc> inline
		void _Pocs(_Alloc& _Left, _Alloc& _Right) noexcept
	{
		typename allocator_traits<_Alloc>::propagate_on_container_swap _Tag;
		_Pocs(_Left, _Right, _Tag);
	}

	template<class _Alloc> inline
		void _Destroy_range1(
			typename allocator_traits<_Alloc>::pointer _First,
			typename allocator_traits<_Alloc>::pointer _Last,
			_Alloc& _Al, false_type)
	{
		for (; _First != _Last; ++_First)
		{
			allocator_traits<_Alloc>::destroy(_Al, _Unfancy(_First));
		}
	}

	template<class _Alloc> inline
		void _Destroy_range1(
			typename allocator_traits<_Alloc>::pointer,
			typename allocator_traits<_Alloc>::pointer,
			_Alloc&, true_type)
	{

	}

	template<class _Alloc> inline
		void _Destroy_range(
			typename allocator_traits<_Alloc>::pointer _First,
			typename allocator_traits<_Alloc>::pointer _Last,
			_Alloc& _Al)
	{

		using _Val = typename _Alloc::value_type;
		_Destroy_range1(_First, _Last, _Al, bool_constant<conjunction_v<
			is_trivially_destructible<_Val>,
			_Uses_default_destroy<_Alloc, _Val *>>>{});
	}

	template<class _FwdIt> inline
		void _Destroy_range1(_FwdIt _First, _FwdIt _Last, false_type)
	{
		for (; _First != _Last; ++_First)
		{
			_Destroy_in_place(*_First);
		}
	}

	template<class _FwdIt> inline
		void _Destroy_range1(_FwdIt, _FwdIt, true_type)
	{

	}

	template<class _FwdIt> inline
		void _Destroy_range(_FwdIt _First, _FwdIt _Last)
	{

		_Destroy_range1(_First, _Last, is_trivially_destructible<_Iter_value_t<_FwdIt>>());
	}

	template<class _Size_type> inline
		_Size_type _Convert_size(const size_t _Len)
	{
		if (_Len > (numeric_limits<_Size_type>::max)())
		{
			_Xlength_error("size_t too long for _Size_type");
		}

		return (static_cast<_Size_type>(_Len));
	}

	template<> inline
		size_t _Convert_size<size_t>(const size_t _Len)
	{
		return (_Len);
	}

	template<class _Alloc,
		enable_if_t<is_same_v<typename allocator_traits<_Alloc>::pointer,
		typename _Alloc::value_type *>, int> = 0> inline
		void _Deallocate_plain(_Alloc& _Al, typename _Alloc::value_type * const _Ptr)
	{
		allocator_traits<_Alloc>::deallocate(_Al, _Ptr, 1);
	}

	template<class _Alloc,
		enable_if_t<!is_same_v<typename allocator_traits<_Alloc>::pointer,
		typename _Alloc::value_type *>, int> = 0> inline
		void _Deallocate_plain(_Alloc& _Al, typename _Alloc::value_type * const _Ptr)
	{
		using _Alloc_traits = allocator_traits<_Alloc>;
		using _Ptr_traits = pointer_traits<typename _Alloc_traits::pointer>;
		_Alloc_traits::deallocate(_Al, _Ptr_traits::pointer_to(*_Ptr), 1);
	}
}

#pragma once

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {

	typedef enum memory_order {
		memory_order_relaxed,
		memory_order_consume,
		memory_order_acquire,
		memory_order_release,
		memory_order_acq_rel,
		memory_order_seq_cst
	} memory_order;

	typedef unsigned long _Uint4_t;
	typedef _Uint4_t _Atomic_integral_t;

	typedef _Atomic_integral_t _Atomic_counter_t;

	inline _Atomic_integral_t
		_Get_atomic_count(const _Atomic_counter_t& _Counter)
	{
		return (_Counter);
	}

}

#pragma warning(pop)
#pragma pack(pop)

#pragma once

extern "C" {

	unsigned char _BitScanForward(unsigned long * _Index, unsigned long _Mask);

	unsigned char _BitScanReverse(unsigned long * _Index, unsigned long _Mask);

	unsigned char _bittest(long const *, long);
	long _InterlockedAnd(long volatile * _Value, long _Mask);
	short _InterlockedAnd16(short volatile * _Value, short _Mask);

	char _InterlockedAnd8(char volatile * _Value, char _Mask);

	long __cdecl _InterlockedCompareExchange(long volatile * _Destination, long _Exchange, long _Comparand);

	short _InterlockedCompareExchange16(short volatile * _Destination, short _Exchange, short _Comparand);

	__int64 _InterlockedCompareExchange64(__int64 volatile * _Destination, __int64 _Exchange, __int64 _Comparand);

	char _InterlockedCompareExchange8(char volatile * _Destination, char _Exchange, char _Comparand);

	long __cdecl _InterlockedDecrement(long volatile * _Addend);

	long __cdecl _InterlockedExchange(long volatile * _Target, long _Value);

	short _InterlockedExchange16(short volatile * _Target, short _Value);

	char _InterlockedExchange8(char volatile * _Target, char _Value);

	long __cdecl _InterlockedExchangeAdd(long volatile * _Addend, long _Value);
	short _InterlockedExchangeAdd16(short volatile * _Addend, short _Value);

	char _InterlockedExchangeAdd8(char volatile * _Addend, char _Value);

	long __cdecl _InterlockedIncrement(long volatile * _Addend);

	long _InterlockedOr(long volatile * _Value, long _Mask);
	short _InterlockedOr16(short volatile * _Value, short _Mask);

	char _InterlockedOr8(char volatile * _Value, char _Mask);

	long _InterlockedXor(long volatile * _Value, long _Mask);
	short _InterlockedXor16(short volatile * _Value, short _Mask);

	char _InterlockedXor8(char volatile * _Value, char _Mask);

	void _ReadWriteBarrier(void);

	unsigned char _interlockedbittestandset(long volatile *, long);

}

#pragma warning(pop)
#pragma pack(pop)

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {
	template<class _Traits>
	using _Traits_ch_t = typename _Traits::char_type;

	template<class _Traits>
	using _Traits_ptr_t = const typename _Traits::char_type *;

	template<class _Traits>
	constexpr bool _Traits_equal(const _Traits_ptr_t<_Traits> _Left, const size_t _Left_size,
		const _Traits_ptr_t<_Traits> _Right, const size_t _Right_size) noexcept
	{
		return (_Left_size == _Right_size && _Traits::compare(_Left, _Right, _Left_size) == 0);
	}

	template<class _Traits>
	constexpr int _Traits_compare(const _Traits_ptr_t<_Traits> _Left, const size_t _Left_size,
		const _Traits_ptr_t<_Traits> _Right, const size_t _Right_size) noexcept
	{
		const int _Ans = _Traits::compare(_Left, _Right, _Min_value(_Left_size, _Right_size));

		if (_Ans != 0)
		{
			return (_Ans);
		}

		if (_Left_size < _Right_size)
		{
			return (-1);
		}

		if (_Left_size > _Right_size)
		{
			return (1);
		}

		return (0);
	}

	template<class _Traits>
	constexpr size_t _Traits_find(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ptr_t<_Traits> _Needle, const size_t _Needle_size) noexcept
	{
		if (_Needle_size > _Hay_size || _Start_at > _Hay_size - _Needle_size)
		{

			return (static_cast<size_t>(-1));
		}

		if (_Needle_size == 0)
		{
			return (_Start_at);
		}

		const auto _Possible_matches_end = _Haystack + (_Hay_size - _Needle_size) + 1;
		for (auto _Match_try = _Haystack + _Start_at; ; ++_Match_try)
		{
			_Match_try = _Traits::find(_Match_try, static_cast<size_t>(_Possible_matches_end - _Match_try), *_Needle);
			if (!_Match_try)
			{
				return (static_cast<size_t>(-1));
			}

			if (_Traits::compare(_Match_try, _Needle, _Needle_size) == 0)
			{
				return (static_cast<size_t>(_Match_try - _Haystack));
			}
		}
	}

	template<class _Traits>
	constexpr size_t _Traits_find_ch(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ch_t<_Traits> _Ch) noexcept
	{
		if (_Start_at < _Hay_size)
		{
			const auto _Found_at = _Traits::find(_Haystack + _Start_at, _Hay_size - _Start_at, _Ch);
			if (_Found_at)
			{
				return (static_cast<size_t>(_Found_at - _Haystack));
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Traits>
	constexpr size_t _Traits_rfind(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ptr_t<_Traits> _Needle, const size_t _Needle_size) noexcept
	{
		if (_Needle_size == 0)
		{
			return (_Min_value(_Start_at, _Hay_size));
		}

		if (_Needle_size <= _Hay_size)
		{
			for (auto _Match_try = _Haystack + _Min_value(_Start_at, _Hay_size - _Needle_size); ; --_Match_try)
			{
				if (_Traits::eq(*_Match_try, *_Needle)
					&& _Traits::compare(_Match_try, _Needle, _Needle_size) == 0)
				{
					return (static_cast<size_t>(_Match_try - _Haystack));
				}

				if (_Match_try == _Haystack)
				{
					break;
				}
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Traits>
	constexpr size_t _Traits_rfind_ch(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ch_t<_Traits> _Ch) noexcept
	{
		if (_Hay_size != 0)
		{
			for (auto _Match_try = _Haystack + _Min_value(_Start_at, _Hay_size - 1); ; --_Match_try)
			{
				if (_Traits::eq(*_Match_try, _Ch))
				{
					return (static_cast<size_t>(_Match_try - _Haystack));
				}

				if (_Match_try == _Haystack)
				{
					break;
				}
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Elem,
		bool = _Is_character<_Elem>::value>
		class _String_bitmap
	{
	public:
		constexpr bool _Mark(const _Elem * _First, const _Elem * const _Last)
		{

			for (; _First != _Last; ++_First)
			{
				_Matches[static_cast<unsigned char>(*_First)] = true;
			}

			return (true);
		}

		constexpr bool _Match(const _Elem _Ch) const
		{
			return (_Matches[static_cast<unsigned char>(_Ch)]);
		}

	private:
		bool _Matches[256] = {};
	};

	template<class _Elem>
	class _String_bitmap<_Elem, false>
	{
	public:
		static_assert(is_unsigned_v<_Elem>,
			"Standard char_traits is only provided for char, wchar_t, char16_t, and char32_t. See N5687 [char.traits]. "
			"Visual C++ accepts other unsigned integral types as an extension.");

		constexpr bool _Mark(const _Elem * _First, const _Elem * const _Last)
		{

			for (; _First != _Last; ++_First)
			{
				const auto _Ch = *_First;
				if (_Ch >= 256U)
				{
					return (false);
				}

				_Matches[static_cast<unsigned char>(_Ch)] = true;
			}

			return (true);
		}

		constexpr bool _Match(const _Elem _Ch) const
		{
			return (_Ch < 256U && _Matches[_Ch]);
		}

	private:
		bool _Matches[256] = {};
	};

	template<class _Traits>
	constexpr size_t _Traits_find_first_of(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ptr_t<_Traits> _Needle, const size_t _Needle_size, false_type) noexcept
	{

		if (_Needle_size != 0 && _Start_at < _Hay_size)
		{
			const auto _End = _Haystack + _Hay_size;
			for (auto _Match_try = _Haystack + _Start_at; _Match_try < _End; ++_Match_try)
			{
				if (_Traits::find(_Needle, _Needle_size, *_Match_try))
				{
					return (static_cast<size_t>(_Match_try - _Haystack));
				}
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Traits>
	constexpr size_t _Traits_find_first_of(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ptr_t<_Traits> _Needle, const size_t _Needle_size, true_type) noexcept
	{

		if (_Needle_size != 0 && _Start_at < _Hay_size)
		{
			_String_bitmap<typename _Traits::char_type> _Matches;
			if (!_Matches._Mark(_Needle, _Needle + _Needle_size))
			{
				return (_Traits_find_first_of<_Traits>(_Haystack, _Hay_size, _Start_at, _Needle, _Needle_size,
					false_type{}));
			}

			const auto _End = _Haystack + _Hay_size;
			for (auto _Match_try = _Haystack + _Start_at; _Match_try < _End; ++_Match_try)
			{
				if (_Matches._Match(*_Match_try))
				{
					return (static_cast<size_t>(_Match_try - _Haystack));
				}
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Traits>
	constexpr size_t _Traits_find_last_of(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ptr_t<_Traits> _Needle, const size_t _Needle_size, false_type) noexcept
	{

		if (_Needle_size != 0 && _Hay_size != 0)
		{
			for (auto _Match_try = _Haystack + _Min_value(_Start_at, _Hay_size - 1); ; --_Match_try)
			{
				if (_Traits::find(_Needle, _Needle_size, *_Match_try))
				{
					return (static_cast<size_t>(_Match_try - _Haystack));
				}

				if (_Match_try == _Haystack)
				{
					break;
				}
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Traits>
	constexpr size_t _Traits_find_last_of(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ptr_t<_Traits> _Needle, const size_t _Needle_size, true_type) noexcept
	{

		if (_Needle_size != 0 && _Hay_size != 0)
		{
			_String_bitmap<typename _Traits::char_type> _Matches;
			if (!_Matches._Mark(_Needle, _Needle + _Needle_size))
			{
				return (_Traits_find_last_of<_Traits>(_Haystack, _Hay_size, _Start_at, _Needle, _Needle_size,
					false_type{}));
			}

			for (auto _Match_try = _Haystack + _Min_value(_Start_at, _Hay_size - 1); ; --_Match_try)
			{
				if (_Matches._Match(*_Match_try))
				{
					return (static_cast<size_t>(_Match_try - _Haystack));
				}

				if (_Match_try == _Haystack)
				{
					break;
				}
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Traits>
	constexpr size_t _Traits_find_first_not_of(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ptr_t<_Traits> _Needle, const size_t _Needle_size, false_type) noexcept
	{

		if (_Start_at < _Hay_size)
		{
			const auto _End = _Haystack + _Hay_size;
			for (auto _Match_try = _Haystack + _Start_at; _Match_try < _End; ++_Match_try)
			{
				if (!_Traits::find(_Needle, _Needle_size, *_Match_try))
				{
					return (static_cast<size_t>(_Match_try - _Haystack));
				}
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Traits>
	constexpr size_t _Traits_find_first_not_of(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ptr_t<_Traits> _Needle, const size_t _Needle_size, true_type) noexcept
	{

		if (_Start_at < _Hay_size)
		{
			_String_bitmap<typename _Traits::char_type> _Matches;
			if (!_Matches._Mark(_Needle, _Needle + _Needle_size))
			{
				return (_Traits_find_first_not_of<_Traits>(_Haystack, _Hay_size, _Start_at, _Needle, _Needle_size,
					false_type{}));
			}

			const auto _End = _Haystack + _Hay_size;
			for (auto _Match_try = _Haystack + _Start_at; _Match_try < _End; ++_Match_try)
			{
				if (!_Matches._Match(*_Match_try))
				{
					return (static_cast<size_t>(_Match_try - _Haystack));
				}
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Traits>
	constexpr size_t _Traits_find_not_ch(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ch_t<_Traits> _Ch) noexcept
	{
		if (_Start_at < _Hay_size)
		{
			const auto _End = _Haystack + _Hay_size;
			for (auto _Match_try = _Haystack + _Start_at; _Match_try < _End; ++_Match_try)
			{
				if (!_Traits::eq(*_Match_try, _Ch))
				{
					return (static_cast<size_t>(_Match_try - _Haystack));
				}
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Traits>
	constexpr size_t _Traits_find_last_not_of(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ptr_t<_Traits> _Needle, const size_t _Needle_size, false_type) noexcept
	{

		if (_Hay_size != 0)
		{
			for (auto _Match_try = _Haystack + _Min_value(_Start_at, _Hay_size - 1); ; --_Match_try)
			{
				if (!_Traits::find(_Needle, _Needle_size, *_Match_try))
				{
					return (static_cast<size_t>(_Match_try - _Haystack));
				}

				if (_Match_try == _Haystack)
				{
					break;
				}
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Traits>
	constexpr size_t _Traits_find_last_not_of(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ptr_t<_Traits> _Needle, const size_t _Needle_size, true_type) noexcept
	{

		if (_Hay_size != 0)
		{
			_String_bitmap<typename _Traits::char_type> _Matches;
			if (!_Matches._Mark(_Needle, _Needle + _Needle_size))
			{
				return (_Traits_find_last_not_of<_Traits>(_Haystack, _Hay_size, _Start_at, _Needle, _Needle_size,
					false_type{}));
			}

			for (auto _Match_try = _Haystack + _Min_value(_Start_at, _Hay_size - 1); ; --_Match_try)
			{
				if (!_Matches._Match(*_Match_try))
				{
					return (static_cast<size_t>(_Match_try - _Haystack));
				}

				if (_Match_try == _Haystack)
				{
					break;
				}
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Traits>
	constexpr size_t _Traits_rfind_not_ch(
		const _Traits_ptr_t<_Traits> _Haystack, const size_t _Hay_size, const size_t _Start_at,
		const _Traits_ch_t<_Traits> _Ch) noexcept
	{
		if (_Hay_size != 0)
		{
			for (auto _Match_try = _Haystack + _Min_value(_Start_at, _Hay_size - 1); ; --_Match_try)
			{
				if (!_Traits::eq(*_Match_try, _Ch))
				{
					return (static_cast<size_t>(_Match_try - _Haystack));
				}

				if (_Match_try == _Haystack)
				{
					break;
				}
			}
		}

		return (static_cast<size_t>(-1));
	}

	template<class _Mystr>
	class _String_const_iterator
		: public _Iterator_base
	{
	public:
		using iterator_category = random_access_iterator_tag;

		using value_type = typename _Mystr::value_type;
		using difference_type = typename _Mystr::difference_type;
		using pointer = typename _Mystr::const_pointer;
		using reference = const value_type&;

		_String_const_iterator()
			: _Ptr()
		{
		}

		_String_const_iterator(pointer _Parg, const _Container_base *_Pstring)
			: _Ptr(_Parg)
		{
			this->_Adopt(_Pstring);
		}

		reference operator*() const
		{

			do { if (_Ptr) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1424, 0, "%s", "cannot dereference value-initialized string iterator")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot dereference value-initialized string iterator\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1424, 0); } while (false); }; } while (false);
			const auto _Mycont = static_cast<const _Mystr *>(this->_Getcont());
			do { if (_Mycont) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1427, 0, "%s", "cannot dereference string iterator because the iterator was" " invalidated (e.g. reallocation occurred, or the string was destroyed)")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot dereference string iterator because the iterator was\" \" invalidated (e.g. reallocation occurred, or the string was destroyed)\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1427, 0); } while (false); }; } while (false);

			const auto _Contptr = _Mycont->_Myptr();
			const auto _Rawptr = _Unfancy(_Ptr);
			do { if (_Contptr <= _Rawptr && _Rawptr < _Contptr + _Mycont->_Mysize) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1431, 0, "%s", "cannot dereference string iterator because it is out of range (e.g. an end iterator)")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot dereference string iterator because it is out of range (e.g. an end iterator)\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1431, 0); } while (false); }; } while (false);

			;
			return (*_Ptr);
		}

		pointer operator->() const
		{
			return (pointer_traits<pointer>::pointer_to(**this));
		}

		_String_const_iterator& operator++()
		{

			do { if (_Ptr) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1446, 0, "%s", "cannot increment value-initialized string iterator")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot increment value-initialized string iterator\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1446, 0); } while (false); }; } while (false);
			const auto _Mycont = static_cast<const _Mystr *>(this->_Getcont());
			do { if (_Mycont) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1449, 0, "%s", "cannot increment string iterator because the iterator was" " invalidated (e.g. reallocation occurred, or the string was destroyed)")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot increment string iterator because the iterator was\" \" invalidated (e.g. reallocation occurred, or the string was destroyed)\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1449, 0); } while (false); }; } while (false);

			do { if (_Unfancy(_Ptr) < _Mycont->_Myptr() + _Mycont->_Mysize) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1451, 0, "%s", "cannot increment string iterator past end")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot increment string iterator past end\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1451, 0); } while (false); }; } while (false);

			++_Ptr;
			return (*this);
		}

		_String_const_iterator operator++(int)
		{
			_String_const_iterator _Tmp = *this;
			++*this;
			return (_Tmp);
		}

		_String_const_iterator& operator--()
		{

			do { if (_Ptr) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1468, 0, "%s", "cannot decrement value-initialized string iterator")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot decrement value-initialized string iterator\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1468, 0); } while (false); }; } while (false);
			const auto _Mycont = static_cast<const _Mystr *>(this->_Getcont());
			do { if (_Mycont) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1471, 0, "%s", "cannot decrement string iterator because the iterator was" " invalidated (e.g. reallocation occurred, or the string was destroyed)")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot decrement string iterator because the iterator was\" \" invalidated (e.g. reallocation occurred, or the string was destroyed)\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1471, 0); } while (false); }; } while (false);

			do { if (_Mycont->_Myptr() < _Unfancy(_Ptr)) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1472, 0, "%s", "cannot decrement string iterator before begin")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot decrement string iterator before begin\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1472, 0); } while (false); }; } while (false);

			--_Ptr;
			return (*this);
		}

		_String_const_iterator operator--(int)
		{
			_String_const_iterator _Tmp = *this;
			--*this;
			return (_Tmp);
		}

		void _Verify_offset(const difference_type _Off) const noexcept
		{

			if (_Off == 0)
			{
				return;
			}

			do { if (_Ptr) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1494, 0, "%s", "cannot seek value-initialized string iterator")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot seek value-initialized string iterator\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1494, 0); } while (false); }; } while (false);
			const auto _Mycont = static_cast<const _Mystr *>(this->_Getcont());
			do { if (_Mycont) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1497, 0, "%s", "cannot seek string iterator because the iterator was" " invalidated (e.g. reallocation occurred, or the string was destroyed)")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot seek string iterator because the iterator was\" \" invalidated (e.g. reallocation occurred, or the string was destroyed)\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1497, 0); } while (false); }; } while (false);

			const auto _Contptr = _Mycont->_Myptr();
			const auto _Rawptr = _Unfancy(_Ptr);

			if (_Off < 0)
			{
#pragma warning(suppress: 4146)	
				do { if (_Contptr - _Rawptr <= _Off) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1504, 0, "%s", "cannot seek string iterator before begin")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot seek string iterator before begin\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1504, 0); } while (false); }; } while (false);
			}

			if (_Off > 0)
			{
				using _Size_type = typename _Mystr::size_type;
				const auto _Left = _Mycont->_Mysize - static_cast<_Size_type>(_Rawptr - _Contptr);
				do { if (static_cast<_Size_type>(_Off) <= _Left) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1511, 0, "%s", "cannot seek string iterator after end")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"cannot seek string iterator after end\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1511, 0); } while (false); }; } while (false);
			}

		}

		_String_const_iterator& operator+=(const difference_type _Off)
		{

			_Verify_offset(_Off);

			_Ptr += _Off;
			return (*this);
		}

		_String_const_iterator operator+(const difference_type _Off) const
		{
			_String_const_iterator _Tmp = *this;
			return (_Tmp += _Off);
		}

		_String_const_iterator& operator-=(const difference_type _Off)
		{
			return (*this += -_Off);
		}

		_String_const_iterator operator-(const difference_type _Off) const
		{
			_String_const_iterator _Tmp = *this;
			return (_Tmp -= _Off);
		}

		difference_type operator-(const _String_const_iterator& _Right) const
		{
			_Compat(_Right);
			return (_Ptr - _Right._Ptr);
		}

		reference operator[](const difference_type _Off) const
		{
			return (*(*this + _Off));
		}

		bool operator==(const _String_const_iterator& _Right) const
		{
			_Compat(_Right);
			return (_Ptr == _Right._Ptr);
		}

		bool operator!=(const _String_const_iterator& _Right) const
		{
			return (!(*this == _Right));
		}

		bool operator<(const _String_const_iterator& _Right) const
		{
			_Compat(_Right);
			return (_Ptr < _Right._Ptr);
		}

		bool operator>(const _String_const_iterator& _Right) const
		{
			return (_Right < *this);
		}

		bool operator<=(const _String_const_iterator& _Right) const
		{
			return (!(_Right < *this));
		}

		bool operator>=(const _String_const_iterator& _Right) const
		{
			return (!(*this < _Right));
		}

		void _Compat(const _String_const_iterator& _Right) const
		{

			do { if (this->_Getcont() == _Right._Getcont()) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1591, 0, "%s", "string iterators incompatible (e.g." " point to different string instances)")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"string iterators incompatible (e.g.\" \" point to different string instances)\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1591, 0); } while (false); }; } while (false);

		}

		friend void _Verify_range(const _String_const_iterator& _First, const _String_const_iterator& _Last)
		{
			do { if (_First._Getcont() == _Last._Getcont()) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1601, 0, "%s", "string iterators in range are from different containers")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"string iterators in range are from different containers\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1601, 0); } while (false); }; } while (false);

			do { if (_First._Ptr <= _Last._Ptr) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1602, 0, "%s", "string iterator range transposed")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"string iterator range transposed\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 1602, 0); } while (false); }; } while (false);
		}

		pointer _Unwrapped() const
		{
			return (_Ptr);
		}

		void _Seek_to(pointer _It)
		{
			_Ptr = _It;
		}

		pointer _Ptr;
	};

	template<class _Mystr>
	inline _String_const_iterator<_Mystr> operator+(
		typename _String_const_iterator<_Mystr>::difference_type _Off,
		_String_const_iterator<_Mystr> _Next)
	{
		return (_Next += _Off);
	}

	template<class _Mystr>
	class _String_iterator
		: public _String_const_iterator<_Mystr>
	{
	public:
		using _Mybase = _String_const_iterator<_Mystr>;
		using iterator_category = random_access_iterator_tag;

		using value_type = typename _Mystr::value_type;
		using difference_type = typename _Mystr::difference_type;
		using pointer = typename _Mystr::pointer;
		using reference = value_type & ;

		_String_iterator()
		{
		}

		_String_iterator(pointer _Parg, const _Container_base *_Pstring)
			: _Mybase(_Parg, _Pstring)
		{
		}

		reference operator*() const
		{
			return (const_cast<reference>(_Mybase::operator*()));
		}

		pointer operator->() const
		{
			return (pointer_traits<pointer>::pointer_to(**this));
		}

		_String_iterator& operator++()
		{
			++*(_Mybase *)this;
			return (*this);
		}

		_String_iterator operator++(int)
		{
			_String_iterator _Tmp = *this;
			++*this;
			return (_Tmp);
		}

		_String_iterator& operator--()
		{
			--*(_Mybase *)this;
			return (*this);
		}

		_String_iterator operator--(int)
		{
			_String_iterator _Tmp = *this;
			--*this;
			return (_Tmp);
		}

		_String_iterator& operator+=(const difference_type _Off)
		{
			*(_Mybase *)this += _Off;
			return (*this);
		}

		_String_iterator operator+(const difference_type _Off) const
		{
			_String_iterator _Tmp = *this;
			return (_Tmp += _Off);
		}

		_String_iterator& operator-=(const difference_type _Off)
		{
			return (*this += -_Off);
		}

		_String_iterator operator-(const difference_type _Off) const
		{
			_String_iterator _Tmp = *this;
			return (_Tmp -= _Off);
		}

		difference_type operator-(const _Mybase& _Right) const
		{
			return (*(_Mybase *)this - _Right);
		}

		reference operator[](const difference_type _Off) const
		{
			return (*(*this + _Off));
		}

		pointer _Unwrapped() const
		{
			return (_Const_cast(this->_Ptr));
		}
	};

	template<class _Mystr>
	inline _String_iterator<_Mystr> operator+(
		typename _String_iterator<_Mystr>::difference_type _Off,
		_String_iterator<_Mystr> _Next)
	{
		return (_Next += _Off);
	}

	template<class _Value_type,
		class _Size_type,
		class _Difference_type,
		class _Pointer,
		class _Const_pointer,
		class _Reference,
		class _Const_reference>
		struct _String_iter_types
	{
		using value_type = _Value_type;
		using size_type = _Size_type;
		using difference_type = _Difference_type;
		using pointer = _Pointer;
		using const_pointer = _Const_pointer;
	};

	template<class _Ty,
		class _Alloc>
		struct _String_base_types
	{
		using _Alty = _Rebind_alloc_t<_Alloc, _Ty>;
		using _Alty_traits = allocator_traits<_Alty>;

		using _Val_types = conditional_t<_Is_simple_alloc_v<_Alty>,
			_Simple_types<_Ty>,
			_String_iter_types<_Ty,
			typename _Alty_traits::size_type,
			typename _Alty_traits::difference_type,
			typename _Alty_traits::pointer,
			typename _Alty_traits::const_pointer,
			_Ty&,
			const _Ty&>>;
	};

	template<class _Val_types>
	class _String_val
		: public _Container_base
	{
	public:
		using value_type = typename _Val_types::value_type;
		using size_type = typename _Val_types::size_type;
		using difference_type = typename _Val_types::difference_type;
		using pointer = typename _Val_types::pointer;
		using const_pointer = typename _Val_types::const_pointer;
		using reference = value_type & ;
		using const_reference = const value_type&;

		_String_val()
			: _Bx(),
			_Mysize(0),
			_Myres(0)
		{
		}

		enum
		{
			_BUF_SIZE = 16 / sizeof(value_type) < 1 ? 1
			: 16 / sizeof(value_type)
		};
		enum
		{
			_ALLOC_MASK = sizeof(value_type) <= 1 ? 15
			: sizeof(value_type) <= 2 ? 7
			: sizeof(value_type) <= 4 ? 3
			: sizeof(value_type) <= 8 ? 1 : 0
		};

		value_type *_Myptr()
		{
			value_type * _Result = _Bx._Buf;
			if (_Large_string_engaged())
			{
				_Result = _Unfancy(_Bx._Ptr);
			}

			return (_Result);
		}

		const value_type *_Myptr() const
		{
			const value_type * _Result = _Bx._Buf;
			if (_Large_string_engaged())
			{
				_Result = _Unfancy(_Bx._Ptr);
			}

			return (_Result);
		}

		bool _Large_string_engaged() const
		{
			return (_BUF_SIZE <= _Myres);
		}

		void _Check_offset(const size_type _Off) const
		{
			if (_Mysize < _Off)
			{
				_Xran();
			}
		}

		void _Check_offset_exclusive(const size_type _Off) const
		{
			if (_Mysize <= _Off)
			{
				_Xran();
			}
		}

		[[noreturn]] static void _Xran()
		{
			_Xout_of_range("invalid string position");
		}

		size_type _Clamp_suffix_size(const size_type _Off, const size_type _Size) const noexcept
		{
			return (_Min_value(_Size, _Mysize - _Off));
		}

		union _Bxty
		{
			_Bxty()
			{
			}

			~_Bxty() noexcept
			{
			}

			value_type _Buf[_BUF_SIZE];
			pointer _Ptr;
			char _Alias[_BUF_SIZE];
		} _Bx;

		size_type _Mysize;
		size_type _Myres;
	};

	template<class _Alloc_types>
	class _String_alloc
	{
	public:
		using _Alty = typename _Alloc_types::_Alty;
		using _Alty_traits = typename _Alloc_types::_Alty_traits;
		using _Alproxy = _Rebind_alloc_t<_Alty, _Container_proxy>;
		using _Alproxy_traits = allocator_traits<_Alproxy>;
		using _Val_types = typename _Alloc_types::_Val_types;
		using _Mydata_t = _String_val<_Val_types>;
		using _Bxty = typename _Mydata_t::_Bxty;

		using value_type = typename _Val_types::value_type;
		using size_type = typename _Val_types::size_type;
		using difference_type = typename _Val_types::difference_type;
		using pointer = typename _Val_types::pointer;
		using const_pointer = typename _Val_types::const_pointer;
		using reference = value_type & ;
		using const_reference = const value_type&;

		using iterator = _String_iterator<_Mydata_t>;
		using const_iterator = _String_const_iterator<_Mydata_t>;

		enum
		{
			_BUF_SIZE = _Mydata_t::_BUF_SIZE
		};

		enum
		{
			_ALLOC_MASK = _Mydata_t::_ALLOC_MASK
		};

		_String_alloc()
			: _Mypair(_Zero_then_variadic_args_t())
		{
			_Alloc_proxy();
		}

		template<class _Any_alloc,
			class = enable_if_t<!is_same_v<remove_cv_t<remove_reference_t<_Any_alloc>>, _String_alloc>>>
			_String_alloc(_Any_alloc&& _Al)
			: _Mypair(_One_then_variadic_args_t(),
				::std::forward<_Any_alloc>(_Al))
		{
			_Alloc_proxy();
		}

		~_String_alloc() noexcept
		{
			_Free_proxy();
		}

		void _Copy_alloc(const _Alty& _Al)
		{
			const bool _Reload = _Alty_traits::propagate_on_container_copy_assignment::value
				&& _Getal() != _Al;

			if (_Reload)
			{
				_Free_proxy();
			}

			_Pocca(_Getal(), _Al);

			if (_Reload)
			{
				_Alloc_proxy();
			}
		}

		void _Move_alloc(_Alty& _Al)
		{
			const bool _Reload = _Alty_traits::propagate_on_container_move_assignment::value
				&& _Getal() != _Al;

			if (_Reload)
			{
				_Free_proxy();
			}

			_Pocma(_Getal(), _Al);

			if (_Reload)
			{
				_Alloc_proxy();
			}
		}

		void _Alloc_proxy()
		{
			_Alproxy _Proxy_allocator(_Getal());
			_Myproxy() = _Unfancy(_Proxy_allocator.allocate(1));
			_Alproxy_traits::construct(_Proxy_allocator, _Myproxy(), _Container_proxy());
			_Myproxy()->_Mycont = ::std::addressof(_Get_data());
		}

		void _Free_proxy()
		{
			_Alproxy _Proxy_allocator(_Getal());
			_Orphan_all();
			_Alproxy_traits::destroy(_Proxy_allocator, _Myproxy());
			_Deallocate_plain(_Proxy_allocator, _Myproxy());
			_Myproxy() = nullptr;
		}

		_Iterator_base12 **_Getpfirst() const
		{
			return (_Get_data()._Getpfirst());
		}

		_Container_proxy * & _Myproxy() noexcept
		{
			return (_Get_data()._Myproxy);
		}

		_Container_proxy * const & _Myproxy() const noexcept
		{
			return (_Get_data()._Myproxy);
		}

		void _Orphan_all()
		{
			_Get_data()._Orphan_all();
		}

		void _Swap_all(_String_alloc& _Right)
		{
			_Get_data()._Swap_all(_Right._Get_data());
		}

		_Alty& _Getal() noexcept
		{
			return (_Mypair._Get_first());
		}

		const _Alty& _Getal() const noexcept
		{
			return (_Mypair._Get_first());
		}

		_Mydata_t& _Get_data() noexcept
		{
			return (_Mypair._Get_second());
		}

		const _Mydata_t& _Get_data() const noexcept
		{
			return (_Mypair._Get_second());
		}

	private:
		_Compressed_pair<_Alty, _Mydata_t> _Mypair;
	};

	template<class _Ty>
	constexpr size_t _Size_after_ebco_v
		= is_empty_v<_Ty> ? 0 : sizeof(_Ty);

	template<class _Elem,
		class _Traits = char_traits<_Elem>,
		class _Alloc = allocator<_Elem>>
		class basic_string
		: public _String_alloc<_String_base_types<_Elem, _Alloc>>
	{
	public:
		static_assert(!0 || is_same_v<_Elem, typename _Alloc::value_type>,
			"basic_string<T, Traits, Allocator>" " requires that Allocator's value_type match " "T" " (See N4659 26.2.1 [container.requirements.general]/16 allocator_type)" " Either fix the allocator value_type or define _ENFORCE_MATCHING_ALLOCATORS=0" " to suppress this diagnostic.");

		static_assert(is_same_v<_Elem, typename _Traits::char_type>,
			"N4659 24.3.2.1 [string.require]/3 requires that the supplied "
			"char_traits character type match the string's character type.");

		using _Mybase = _String_alloc<_String_base_types<_Elem, _Alloc>>;
		using traits_type = _Traits;
		using allocator_type = _Alloc;

		using _Alty = typename _Mybase::_Alty;
		using _Alty_traits = typename _Mybase::_Alty_traits;
		using _Mydata_t = typename _Mybase::_Mydata_t;

		using value_type = typename _Mybase::value_type;
		using size_type = typename _Mybase::size_type;
		using difference_type = typename _Mybase::difference_type;
		using pointer = typename _Mybase::pointer;
		using const_pointer = typename _Mybase::const_pointer;
		using reference = value_type & ;
		using const_reference = const value_type&;

		using iterator = typename _Mybase::iterator;
		using const_iterator = typename _Mybase::const_iterator;

		using reverse_iterator = ::std::reverse_iterator<iterator>;
		using const_reverse_iterator = ::std::reverse_iterator<const_iterator>;

		using _Use_memcpy_move = bool_constant<
			_Is_specialization_v<_Traits, char_traits> && is_trivial_v<pointer>>;

		static constexpr size_t _Memcpy_move_offset = _Size_after_ebco_v<_Container_base>;
		static constexpr size_t _Memcpy_move_size = sizeof(_Mydata_t) - _Memcpy_move_offset;

		template<class _Iter>
		using _Is_elem_cptr = bool_constant<_Is_any_of_v<_Iter,
			const _Elem * const,
			_Elem * const,
			const _Elem *,
			_Elem *>>;

		basic_string(const basic_string& _Right)
			: _Mybase(_Alty_traits::select_on_container_copy_construction(_Right._Getal()))
		{
			_Construct_lv_contents(_Right);
		}

		basic_string(const basic_string& _Right, const _Alloc& _Al)
			: _Mybase(_Al)
		{
			_Construct_lv_contents(_Right);
		}

		basic_string() noexcept(is_nothrow_default_constructible_v<_Alty>)
			: _Mybase()
		{
			_Tidy_init();
		}

		explicit basic_string(const _Alloc& _Al) noexcept
			: _Mybase(_Al)
		{
			_Tidy_init();
		}

		basic_string(const basic_string& _Right, const size_type _Roff, const _Alloc& _Al = _Alloc())
			: _Mybase(_Al)
		{
			_Tidy_init();
			assign(_Right, _Roff, npos);
		}

		basic_string(const basic_string& _Right, const size_type _Roff, const size_type _Count, const _Alloc& _Al = _Alloc())
			: _Mybase(_Al)
		{
			_Tidy_init();
			assign(_Right, _Roff, _Count);
		}

		basic_string(const _Elem * const _Ptr, const size_type _Count)
			: _Mybase()
		{
			_Tidy_init();
			assign(_Ptr, _Count);
		}

		basic_string(const _Elem * const _Ptr, const size_type _Count,
			const _Alloc& _Al)
			: _Mybase(_Al)
		{
			_Tidy_init();
			assign(_Ptr, _Count);
		}

		basic_string(const _Elem * const _Ptr)
			: _Mybase()
		{
			_Tidy_init();
			assign(_Ptr);
		}

		basic_string(const _Elem * const _Ptr, const _Alloc& _Al)
			: _Mybase(_Al)
		{
			_Tidy_init();
			assign(_Ptr);
		}

		basic_string(const size_type _Count, const _Elem _Ch)
			: _Mybase()
		{
			_Tidy_init();
			assign(_Count, _Ch);
		}

		basic_string(const size_type _Count, const _Elem _Ch, const _Alloc& _Al)
			: _Mybase(_Al)
		{
			_Tidy_init();
			assign(_Count, _Ch);
		}

		template<class _Iter,
			class = enable_if_t<_Is_iterator_v<_Iter>>>
			basic_string(_Iter _First, _Iter _Last, const _Alloc& _Al = _Alloc())
			: _Mybase(_Al)
		{
			_Tidy_init();
			_Adl_verify_range(_First, _Last);
			_Construct(_Get_unwrapped(_First), _Get_unwrapped(_Last), _Iter_cat_t<_Iter>());
		}

		template<class _Iter>
		void _Construct(_Iter _First, const _Iter _Last, input_iterator_tag)
		{
			try {
				for (; _First != _Last; ++_First)
				{
					push_back(static_cast<_Elem>(*_First));
				}

			}
			catch (...) {
				_Tidy_deallocate();
				throw;
			}
		}

		template<class _Iter>
		void _Construct(const _Iter _First, const _Iter _Last, forward_iterator_tag)
		{
			const size_type _Count = _Convert_size<size_type>(static_cast<size_t>(::std::distance(_First, _Last)));
			reserve(_Count);
			_Construct(_First, _Last, input_iterator_tag());
		}

		void _Construct(_Elem * const _First, _Elem * const _Last, random_access_iterator_tag)
		{
			if (_First != _Last)
			{
				assign(_First, _Convert_size<size_type>(static_cast<size_t>(_Last - _First)));
			}
		}

		void _Construct(const _Elem * const _First, const _Elem * const _Last, random_access_iterator_tag)
		{
			if (_First != _Last)
			{
				assign(_First, _Convert_size<size_type>(static_cast<size_t>(_Last - _First)));
			}
		}

		basic_string(basic_string&& _Right) noexcept
			: _Mybase(::std::move(_Right._Getal()))
		{
			_Assign_rv_contents_with_alloc_always_equal(::std::move(_Right), _Use_memcpy_move{});
		}

		basic_string(basic_string&& _Right, const _Alloc& _Al)
			noexcept(_Alty_traits::is_always_equal::value)
			: _Mybase(_Al)
		{
			_Assign_rv_contents(::std::move(_Right), typename _Alty_traits::is_always_equal{});
		}

		basic_string& operator=(basic_string&& _Right) noexcept(_Always_equal_after_move<_Alty>)
		{
			if (this != ::std::addressof(_Right))
			{
				_Tidy_deallocate();
				this->_Move_alloc(_Right._Getal());

				_Assign_rv_contents(::std::move(_Right), bool_constant<_Always_equal_after_move<_Alty>>{});
			}

			return (*this);
		}

		basic_string& assign(basic_string&& _Right) noexcept(_Always_equal_after_move<_Alty>)
		{
			*this = ::std::move(_Right);
			return (*this);
		}

		void _Assign_rv_contents(basic_string&& _Right, true_type) noexcept
		{

			_Assign_rv_contents_with_alloc_always_equal(::std::move(_Right), _Use_memcpy_move{});
		}

		void _Assign_rv_contents(basic_string&& _Right, false_type)
		{

			if (this->_Getal() == _Right._Getal())
			{
				_Assign_rv_contents_with_alloc_always_equal(::std::move(_Right), _Use_memcpy_move{});
			}
			else
			{
				_Construct_lv_contents(_Right);
			}
		}

		void _Assign_rv_contents_with_alloc_always_equal(basic_string&& _Right, true_type) noexcept
		{

			auto& _Right_data = _Right._Get_data();

			if (_Right_data._Large_string_engaged())
			{
				this->_Swap_all(_Right);
			}
			else
			{
				_Right._Orphan_all();
			}

			const auto _My_data_mem = reinterpret_cast<unsigned char *>(::std::addressof(this->_Get_data()))
				+ _Memcpy_move_offset;
			const auto _Right_data_mem = reinterpret_cast<unsigned char *>(::std::addressof(_Right_data))
				+ _Memcpy_move_offset;
			::memcpy(_My_data_mem, _Right_data_mem, _Memcpy_move_size);
			_Right._Tidy_init();
		}

		void _Assign_rv_contents_with_alloc_always_equal(basic_string&& _Right, false_type) noexcept
		{

			auto& _My_data = this->_Get_data();
			auto& _Right_data = _Right._Get_data();
			if (_Right_data._Large_string_engaged())
			{
				_Alty_traits::construct(this->_Getal(), ::std::addressof(_My_data._Bx._Ptr), _Right_data._Bx._Ptr);
				_Right_data._Bx._Ptr = pointer();
				this->_Swap_all(_Right);
			}
			else
			{
				_Traits::copy(_My_data._Bx._Buf, _Right_data._Bx._Buf, _Right_data._Mysize + 1);
				_Right._Orphan_all();
			}

			_My_data._Mysize = _Right_data._Mysize;
			_My_data._Myres = _Right_data._Myres;
			_Right._Tidy_init();
		}

		void _Construct_lv_contents(const basic_string& _Right)
		{

			auto& _My_data = this->_Get_data();
			auto& _Right_data = _Right._Get_data();
			const size_type _Right_size = _Right_data._Mysize;
			const _Elem * const _Right_ptr = _Right_data._Myptr();
			if (_Right_size < this->_BUF_SIZE)
			{
				_Traits::copy(_My_data._Bx._Buf, _Right_ptr, this->_BUF_SIZE);
				_My_data._Mysize = _Right_size;
				_My_data._Myres = this->_BUF_SIZE - 1;
				return;
			}

			auto& _Al = this->_Getal();
			const size_type _New_capacity = _Min_value(_Right_size | this->_ALLOC_MASK, max_size());
			const pointer _New_array = _Al.allocate(_New_capacity + 1);
			_Alty_traits::construct(_Al, ::std::addressof(_My_data._Bx._Ptr), _New_array);
			_Traits::copy(_Unfancy(_New_array), _Right_ptr, _Right_size + 1);
			_My_data._Mysize = _Right_size;
			_My_data._Myres = _New_capacity;
		}

		basic_string(initializer_list<_Elem> _Ilist, const _Alloc& _Al = allocator_type())
			: _Mybase(_Al)
		{
			_Tidy_init();
			assign(_Ilist.begin(), _Convert_size<size_type>(_Ilist.size()));
		}

		basic_string& operator=(initializer_list<_Elem> _Ilist)
		{
			return (assign(_Ilist.begin(), _Convert_size<size_type>(_Ilist.size())));
		}

		basic_string& operator+=(initializer_list<_Elem> _Ilist)
		{
			return (append(_Ilist.begin(), _Convert_size<size_type>(_Ilist.size())));
		}

		basic_string& assign(initializer_list<_Elem> _Ilist)
		{
			return (assign(_Ilist.begin(), _Convert_size<size_type>(_Ilist.size())));
		}

		basic_string& append(initializer_list<_Elem> _Ilist)
		{
			return (append(_Ilist.begin(), _Convert_size<size_type>(_Ilist.size())));
		}

		iterator insert(const const_iterator _Where, const initializer_list<_Elem> _Ilist)
		{
			const difference_type _Off = _Where - begin();
			insert(static_cast<size_type>(_Off), _Ilist.begin(), _Convert_size<size_type>(_Ilist.size()));
			return (begin() + _Off);
		}

		basic_string& replace(const const_iterator _First, const const_iterator _Last, const initializer_list<_Elem> _Ilist)
		{
			return (replace(static_cast<size_type>(_First - begin()), static_cast<size_type>(_Last - _First),
				_Ilist.begin(), _Convert_size<size_type>(_Ilist.size())));
		}

		~basic_string() noexcept
		{
			_Tidy_deallocate();
		}

		static constexpr auto npos{ static_cast<size_type>(-1) };

		basic_string& operator=(const basic_string& _Right)
		{
			if (this != ::std::addressof(_Right))
			{
#pragma warning(push)
#pragma warning(disable: 4127)	
				if (_Alty_traits::propagate_on_container_copy_assignment::value
					&& this->_Getal() != _Right._Getal())
				{
					_Tidy_deallocate();
				}
#pragma warning(pop)

				this->_Copy_alloc(_Right._Getal());

				auto& _Right_data = _Right._Get_data();
				assign(_Right_data._Myptr(), _Right_data._Mysize);
			}

			return (*this);
		}

		basic_string& operator=(const _Elem * const _Ptr)
		{
			return (assign(_Ptr));
		}

		basic_string& operator=(const _Elem _Ch)
		{
			auto& _My_data = this->_Get_data();
			_My_data._Mysize = 1;
			_Elem * const _Ptr = _My_data._Myptr();
			_Traits::assign(_Ptr[0], _Ch);
			_Traits::assign(_Ptr[1], _Elem());
			return (*this);
		}

		basic_string& operator+=(const basic_string& _Right)
		{
			return (append(_Right));
		}

		basic_string& operator+=(const _Elem * const _Ptr)
		{
			return (append(_Ptr));
		}

		basic_string& operator+=(_Elem _Ch)
		{
			push_back(_Ch);
			return (*this);
		}

		basic_string& append(const basic_string& _Right)
		{
			auto& _Right_data = _Right._Get_data();
			return (append(_Right_data._Myptr(), _Right_data._Mysize));
		}

		basic_string& append(const basic_string& _Right, const size_type _Roff, size_type _Count = npos)
		{
			auto& _Right_data = _Right._Get_data();
			_Right_data._Check_offset(_Roff);
			_Count = _Right_data._Clamp_suffix_size(_Roff, _Count);
			return (append(_Right_data._Myptr() + _Roff, _Count));
		}

		basic_string& append(const _Elem * const _Ptr, const size_type _Count)
		{
			auto& _My_data = this->_Get_data();
			const size_type _Old_size = _My_data._Mysize;
			if (_Count <= _My_data._Myres - _Old_size)
			{
				_My_data._Mysize = _Old_size + _Count;
				_Elem * const _Old_ptr = _My_data._Myptr();
				_Traits::move(_Old_ptr + _Old_size, _Ptr, _Count);
				_Traits::assign(_Old_ptr[_Old_size + _Count], _Elem());
				return (*this);
			}

			return (_Reallocate_grow_by(_Count,
				[](_Elem * const _New_ptr, const _Elem * const _Old_ptr, const size_type _Old_size,
					const _Elem * const _Ptr, const size_type _Count) {
				_Traits::copy(_New_ptr, _Old_ptr, _Old_size);
				_Traits::copy(_New_ptr + _Old_size, _Ptr, _Count);
				_Traits::assign(_New_ptr[_Old_size + _Count], _Elem());
			}, _Ptr, _Count));
		}

		basic_string& append(const _Elem * const _Ptr)
		{
			return (append(_Ptr, _Convert_size<size_type>(_Traits::length(_Ptr))));
		}

		basic_string& append(const size_type _Count, const _Elem _Ch)
		{
			auto& _My_data = this->_Get_data();
			const size_type _Old_size = _My_data._Mysize;
			if (_Count <= _My_data._Myres - _Old_size)
			{
				_My_data._Mysize = _Old_size + _Count;
				_Elem * const _Old_ptr = _My_data._Myptr();
				_Traits::assign(_Old_ptr + _Old_size, _Count, _Ch);
				_Traits::assign(_Old_ptr[_Old_size + _Count], _Elem());
				return (*this);
			}

			return (_Reallocate_grow_by(_Count,
				[](_Elem * const _New_ptr, const _Elem * const _Old_ptr, const size_type _Old_size,
					const size_type _Count, const _Elem _Ch) {
				_Traits::copy(_New_ptr, _Old_ptr, _Old_size);
				_Traits::assign(_New_ptr + _Old_size, _Count, _Ch);
				_Traits::assign(_New_ptr[_Old_size + _Count], _Elem());
			}, _Count, _Ch));
		}

		template<class _Iter,
			class = enable_if_t<_Is_iterator_v<_Iter>>>
			basic_string& append(const _Iter _First, const _Iter _Last)
		{
			return (replace(end(), end(), _First, _Last));
		}

		basic_string& assign(const basic_string& _Right)
		{
			*this = _Right;
			return (*this);
		}

		basic_string& assign(const basic_string& _Right, const size_type _Roff, size_type _Count = npos)
		{
			auto& _Right_data = _Right._Get_data();
			_Right_data._Check_offset(_Roff);
			_Count = _Right_data._Clamp_suffix_size(_Roff, _Count);
			return (assign(_Right_data._Myptr() + _Roff, _Count));
		}

		basic_string& assign(const _Elem * const _Ptr, const size_type _Count)
		{
			auto& _My_data = this->_Get_data();
			if (_Count <= _My_data._Myres)
			{
				_Elem * const _Old_ptr = _My_data._Myptr();
				_My_data._Mysize = _Count;
				_Traits::move(_Old_ptr, _Ptr, _Count);
				_Traits::assign(_Old_ptr[_Count], _Elem());
				return (*this);
			}

			return (_Reallocate_for(_Count, [](_Elem * const _New_ptr, const size_type _Count, const _Elem * const _Ptr) {
				_Traits::copy(_New_ptr, _Ptr, _Count);
				_Traits::assign(_New_ptr[_Count], _Elem());
			}, _Ptr));
		}

		basic_string& assign(const _Elem * const _Ptr)
		{
			return (assign(_Ptr, _Convert_size<size_type>(_Traits::length(_Ptr))));
		}

		basic_string& assign(const size_type _Count, const _Elem _Ch)
		{
			auto& _My_data = this->_Get_data();
			if (_Count <= _My_data._Myres)
			{
				_Elem * const _Old_ptr = _My_data._Myptr();
				_My_data._Mysize = _Count;
				_Traits::assign(_Old_ptr, _Count, _Ch);
				_Traits::assign(_Old_ptr[_Count], _Elem());
				return (*this);
			}

			return (_Reallocate_for(_Count, [](_Elem * const _New_ptr, const size_type _Count, const _Elem _Ch) {
				_Traits::assign(_New_ptr, _Count, _Ch);
				_Traits::assign(_New_ptr[_Count], _Elem());
			}, _Ch));
		}

		template<class _Iter,
			class = enable_if_t<_Is_iterator_v<_Iter>>>
			basic_string& assign(const _Iter _First, const _Iter _Last)
		{
			return (replace(begin(), end(), _First, _Last));
		}

		basic_string& insert(const size_type _Off, const basic_string& _Right)
		{
			auto& _Right_data = _Right._Get_data();
			return (insert(_Off, _Right_data._Myptr(), _Right_data._Mysize));
		}

		basic_string& insert(const size_type _Off, const basic_string& _Right, const size_type _Roff, size_type _Count = npos)
		{
			auto& _Right_data = _Right._Get_data();
			_Right_data._Check_offset(_Roff);
			_Count = _Right_data._Clamp_suffix_size(_Roff, _Count);
			return (insert(_Off, _Right_data._Myptr() + _Roff, _Count));
		}

		basic_string& insert(const size_type _Off, const _Elem * const _Ptr,
			const size_type _Count)
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset(_Off);
			const size_type _Old_size = _My_data._Mysize;
			if (_Count <= _My_data._Myres - _Old_size)
			{
				_My_data._Mysize = _Old_size + _Count;
				_Elem * const _Old_ptr = _My_data._Myptr();
				_Elem * const _Insert_at = _Old_ptr + _Off;

				size_type _Ptr_shifted_after;
				if (_Ptr + _Count <= _Insert_at || _Ptr > _Old_ptr + _Old_size)
				{
					_Ptr_shifted_after = _Count;
				}
				else if (_Insert_at <= _Ptr)
				{
					_Ptr_shifted_after = 0;
				}
				else
				{
					_Ptr_shifted_after = static_cast<size_type>(_Insert_at - _Ptr);
				}

				_Traits::move(_Insert_at + _Count, _Insert_at, _Old_size - _Off + 1);
				_Traits::copy(_Insert_at, _Ptr, _Ptr_shifted_after);
				_Traits::copy(_Insert_at + _Ptr_shifted_after, _Ptr + _Count + _Ptr_shifted_after,
					_Count - _Ptr_shifted_after);
				return (*this);
			}

			return (_Reallocate_grow_by(_Count,
				[](_Elem * const _New_ptr, const _Elem * const _Old_ptr, const size_type _Old_size,
					const size_type _Off, const _Elem * const _Ptr, const size_type _Count) {
				_Traits::copy(_New_ptr, _Old_ptr, _Off);
				_Traits::copy(_New_ptr + _Off, _Ptr, _Count);
				_Traits::copy(_New_ptr + _Off + _Count, _Old_ptr + _Off, _Old_size - _Off + 1);
			}, _Off, _Ptr, _Count));
		}

		basic_string& insert(const size_type _Off, const _Elem * const _Ptr)
		{
			return (insert(_Off, _Ptr, _Convert_size<size_type>(_Traits::length(_Ptr))));
		}

		basic_string& insert(const size_type _Off, const size_type _Count, const _Elem _Ch)
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset(_Off);
			const size_type _Old_size = _My_data._Mysize;
			if (_Count <= _My_data._Myres - _Old_size)
			{
				_My_data._Mysize = _Old_size + _Count;
				_Elem * const _Old_ptr = _My_data._Myptr();
				_Elem * const _Insert_at = _Old_ptr + _Off;
				_Traits::move(_Insert_at + _Count, _Insert_at, _Old_size - _Off + 1);
				_Traits::assign(_Insert_at, _Count, _Ch);
				return (*this);
			}

			return (_Reallocate_grow_by(_Count,
				[](_Elem * const _New_ptr, const _Elem * const _Old_ptr, const size_type _Old_size,
					const size_type _Off, const size_type _Count, const _Elem _Ch) {
				_Traits::copy(_New_ptr, _Old_ptr, _Off);
				_Traits::assign(_New_ptr + _Off, _Count, _Ch);
				_Traits::copy(_New_ptr + _Off + _Count, _Old_ptr + _Off, _Old_size - _Off + 1);
			}, _Off, _Count, _Ch));
		}

		iterator insert(const const_iterator _Where, const _Elem _Ch)
		{
			const difference_type _Off = _Where - begin();
			insert(static_cast<size_type>(_Off), 1, _Ch);
			return (begin() + _Off);
		}

		iterator insert(const const_iterator _Where, const size_type _Count, const _Elem _Ch)
		{
			const difference_type _Off = _Where - begin();
			insert(static_cast<size_type>(_Off), _Count, _Ch);
			return (begin() + _Off);
		}

		template<class _Iter,
			class = enable_if_t<_Is_iterator_v<_Iter>>>
			iterator insert(const const_iterator _Where, const _Iter _First, const _Iter _Last)
		{
			const difference_type _Off = _Where - begin();
			replace(_Where, _Where, _First, _Last);
			return (begin() + _Off);
		}

		basic_string& erase(const size_type _Off = 0)
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset(_Off);
			_Eos(_Off);
			return (*this);
		}

		basic_string& erase(const size_type _Off, size_type _Count)
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset(_Off);
			_Count = _My_data._Clamp_suffix_size(_Off, _Count);
			const size_type _Old_size = _My_data._Mysize;
			_Elem * const _My_ptr = _My_data._Myptr();
			_Elem * const _Erase_at = _My_ptr + _Off;
			const size_type _New_size = _Old_size - _Count;
			_My_data._Mysize = _New_size;
			_Traits::move(_Erase_at, _Erase_at + _Count, _New_size - _Off + 1);
			return (*this);
		}

		iterator erase(const const_iterator _Where)
		{
			const difference_type _Off = _Where - begin();
			erase(static_cast<size_type>(_Off), 1);
			return (begin() + _Off);
		}

		iterator erase(const const_iterator _First, const const_iterator _Last)
		{
			_Adl_verify_range(_First, _Last);
			const difference_type _Off = _First - begin();
			erase(static_cast<size_type>(_Off), static_cast<size_type>(_Last - _First));
			return (begin() + _Off);
		}

		void clear() noexcept
		{
			_Eos(0);
		}

		basic_string& replace(const size_type _Off, const size_type _N0, const basic_string& _Right)
		{
			auto& _Right_data = _Right._Get_data();
			return (replace(_Off, _N0, _Right_data._Myptr(), _Right_data._Mysize));
		}

		basic_string& replace(const size_type _Off, size_type _N0,
			const basic_string& _Right, const size_type _Roff, size_type _Count = npos)
		{
			auto& _Right_data = _Right._Get_data();
			_Right_data._Check_offset(_Roff);
			_Count = _Right_data._Clamp_suffix_size(_Roff, _Count);
			return (replace(_Off, _N0, _Right_data._Myptr() + _Roff, _Count));
		}

		basic_string& replace(const size_type _Off, size_type _N0,
			const _Elem * const _Ptr, const size_type _Count)
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset(_Off);
			_N0 = _My_data._Clamp_suffix_size(_Off, _N0);
			if (_N0 == _Count)
			{
				_Traits::move(_My_data._Myptr() + _Off, _Ptr, _Count);
				return (*this);
			}

			const size_type _Old_size = _My_data._Mysize;
			const size_type _Suffix_size = _Old_size - _N0 - _Off + 1;
			if (_Count < _N0)
			{
				_My_data._Mysize = _Old_size - (_N0 - _Count);
				_Elem * const _Old_ptr = _My_data._Myptr();
				_Elem * const _Insert_at = _Old_ptr + _Off;
				_Traits::move(_Insert_at, _Ptr, _Count);
				_Traits::move(_Insert_at + _Count, _Insert_at + _N0, _Suffix_size);
				return (*this);
			}

			const size_type _Growth = static_cast<size_type>(_Count - _N0);
			if (_Growth <= _My_data._Myres - _Old_size)
			{
				_My_data._Mysize = _Old_size + _Growth;
				_Elem * const _Old_ptr = _My_data._Myptr();
				_Elem * const _Insert_at = _Old_ptr + _Off;
				_Elem * const _Suffix_at = _Insert_at + _N0;

				size_type _Ptr_shifted_after;
				if (_Ptr + _Count <= _Insert_at || _Ptr > _Old_ptr + _Old_size)
				{
					_Ptr_shifted_after = _Count;
				}
				else if (_Suffix_at <= _Ptr)
				{
					_Ptr_shifted_after = 0;
				}
				else
				{
					_Ptr_shifted_after = static_cast<size_type>(_Suffix_at - _Ptr);
				}

				_Traits::move(_Suffix_at + _Growth, _Suffix_at, _Suffix_size);

				_Traits::move(_Insert_at, _Ptr, _Ptr_shifted_after);

				_Traits::copy(_Insert_at + _Ptr_shifted_after, _Ptr + _Growth + _Ptr_shifted_after,
					_Count - _Ptr_shifted_after);
				return (*this);
			}

			return (_Reallocate_grow_by(_Growth,
				[](_Elem * const _New_ptr, const _Elem * const _Old_ptr, const size_type _Old_size,
					const size_type _Off, const size_type _N0, const _Elem * const _Ptr, const size_type _Count) {
				_Traits::copy(_New_ptr, _Old_ptr, _Off);
				_Traits::copy(_New_ptr + _Off, _Ptr, _Count);
				_Traits::copy(_New_ptr + _Off + _Count, _Old_ptr + _Off + _N0, _Old_size - _N0 - _Off + 1);
			}, _Off, _N0, _Ptr, _Count));
		}

		basic_string& replace(const size_type _Off, const size_type _N0, const _Elem * const _Ptr)
		{
			return (replace(_Off, _N0, _Ptr, _Convert_size<size_type>(_Traits::length(_Ptr))));
		}

		basic_string& replace(const size_type _Off, size_type _N0, const size_type _Count, const _Elem _Ch)
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset(_Off);
			_N0 = _My_data._Clamp_suffix_size(_Off, _N0);
			if (_Count == _N0)
			{
				_Traits::assign(_My_data._Myptr() + _Off, _Count, _Ch);
				return (*this);
			}

			const size_type _Old_size = _My_data._Mysize;
			if (_Count < _N0 || _Count - _N0 <= _My_data._Myres - _Old_size)
			{
				_My_data._Mysize = _Old_size + _Count - _N0;

				_Elem * const _Old_ptr = _My_data._Myptr();
				_Elem * const _Insert_at = _Old_ptr + _Off;
				_Traits::move(_Insert_at + _Count, _Insert_at + _N0, _Old_size - _N0 - _Off + 1);
				_Traits::assign(_Insert_at, _Count, _Ch);
				return (*this);
			}

			return (_Reallocate_grow_by(_Count - _N0,
				[](_Elem * const _New_ptr, const _Elem * const _Old_ptr, const size_type _Old_size,
					const size_type _Off, const size_type _N0, const size_type _Count, const _Elem _Ch) {
				_Traits::copy(_New_ptr, _Old_ptr, _Off);
				_Traits::assign(_New_ptr + _Off, _Count, _Ch);
				_Traits::copy(_New_ptr + _Off + _Count, _Old_ptr + _Off + _N0, _Old_size - _N0 - _Off + 1);
			}, _Off, _N0, _Count, _Ch));
		}

		basic_string& replace(const const_iterator _First, const const_iterator _Last, const basic_string& _Right)
		{
			return (replace(static_cast<size_type>(_First - begin()), static_cast<size_type>(_Last - _First), _Right));
		}

		basic_string& replace(const const_iterator _First, const const_iterator _Last,
			const _Elem * const _Ptr, const size_type _Count)
		{
			return (replace(static_cast<size_type>(_First - begin()), static_cast<size_type>(_Last - _First), _Ptr, _Count));
		}

		basic_string& replace(const const_iterator _First, const const_iterator _Last, const _Elem * const _Ptr)
		{
			return (replace(static_cast<size_type>(_First - begin()), static_cast<size_type>(_Last - _First), _Ptr));
		}

		basic_string& replace(const const_iterator _First, const const_iterator _Last,
			const size_type _Count, const _Elem _Ch)
		{
			return (replace(static_cast<size_type>(_First - begin()), static_cast<size_type>(_Last - _First), _Count, _Ch));
		}

		template<class _Iter>
		basic_string& _Replace_range(const const_iterator _First, const const_iterator _Last,
			const _Iter _First2, const _Iter _Last2, false_type)
		{
			const basic_string _Right(_First2, _Last2, get_allocator());
			replace(_First, _Last, _Right);
			return (*this);
		}

		template<class _Ptr>
		basic_string& _Replace_range(const const_iterator _First, const const_iterator _Last,
			const _Ptr _First2, const _Ptr _Last2, true_type)
		{
			return (replace(static_cast<size_type>(_First - cbegin()), static_cast<size_type>(_Last - _First),
				_First2, static_cast<size_type>(_Last2 - _First2)));
		}

		template<class _Iter,
			class = enable_if_t<_Is_iterator_v<_Iter>>>
			basic_string& replace(const const_iterator _First, const const_iterator _Last,
				const _Iter _First2, const _Iter _Last2)
		{
			_Adl_verify_range(_First2, _Last2);
			const auto _UFirst2 = _Get_unwrapped(_First2);
			const auto _ULast2 = _Get_unwrapped(_Last2);
			return (_Replace_range(_First, _Last, _UFirst2, _ULast2, _Is_elem_cptr<decltype(_UFirst2)>()));
		}

		iterator begin() noexcept
		{
			auto _My_data = ::std::addressof(this->_Get_data());
			return (iterator(_Refancy<pointer>(_My_data->_Myptr()), _My_data));
		}

		const_iterator begin() const noexcept
		{
			auto _My_data = ::std::addressof(this->_Get_data());
			return (const_iterator(_Refancy<const_pointer>(_My_data->_Myptr()), _My_data));
		}

		iterator end() noexcept
		{
			auto _My_data = ::std::addressof(this->_Get_data());
			return (iterator(_Refancy<pointer>(_My_data->_Myptr())
				+ static_cast<difference_type>(_My_data->_Mysize), _My_data));
		}

		const_iterator end() const noexcept
		{
			auto _My_data = ::std::addressof(this->_Get_data());
			return (const_iterator(_Refancy<const_pointer>(_My_data->_Myptr())
				+ static_cast<difference_type>(_My_data->_Mysize), _My_data));
		}

		_Elem * _Unchecked_begin() noexcept
		{
			return (this->_Get_data()._Myptr());
		}

		const _Elem * _Unchecked_begin() const noexcept
		{
			return (this->_Get_data()._Myptr());
		}

		_Elem * _Unchecked_end() noexcept
		{
			auto& _My_data = this->_Get_data();
			return (_My_data._Myptr() + _My_data._Mysize);
		}

		const _Elem * _Unchecked_end() const noexcept
		{
			const auto& _My_data = this->_Get_data();
			return (_My_data._Myptr() + _My_data._Mysize);
		}

		reverse_iterator rbegin() noexcept
		{
			return (reverse_iterator(end()));
		}

		const_reverse_iterator rbegin() const noexcept
		{
			return (const_reverse_iterator(end()));
		}

		reverse_iterator rend() noexcept
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rend() const noexcept
		{
			return (const_reverse_iterator(begin()));
		}

		const_iterator cbegin() const noexcept
		{
			return (begin());
		}

		const_iterator cend() const noexcept
		{
			return (end());
		}

		const_reverse_iterator crbegin() const noexcept
		{
			return (rbegin());
		}

		const_reverse_iterator crend() const noexcept
		{
			return (rend());
		}

		void shrink_to_fit()
		{
			auto& _My_data = this->_Get_data();
			if (!_My_data._Large_string_engaged())
			{
				return;
			}

			if (_My_data._Mysize < this->_BUF_SIZE)
			{
				_Become_small();
				return;
			}

			const size_type _Target_capacity = _Min_value(_My_data._Mysize | this->_ALLOC_MASK, max_size());
			if (_Target_capacity < _My_data._Myres)
			{
				auto& _Al = this->_Getal();
				const pointer _New_ptr = _Al.allocate(_Target_capacity + 1);
				this->_Orphan_all();
				_Traits::copy(_Unfancy(_New_ptr), _Unfancy(_My_data._Bx._Ptr), _My_data._Mysize + 1);
				_Al.deallocate(_My_data._Bx._Ptr, _My_data._Myres + 1);
				_My_data._Bx._Ptr = _New_ptr;
				_My_data._Myres = _Target_capacity;
			}
		}

		reference at(const size_type _Off)
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset_exclusive(_Off);
			return (_My_data._Myptr()[_Off]);
		}

		const_reference at(const size_type _Off) const
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset_exclusive(_Off);
			return (_My_data._Myptr()[_Off]);
		}

		reference operator[](const size_type _Off)
		{
			auto& _My_data = this->_Get_data();

			do { if (_Off <= _My_data._Mysize) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 3204, 0, "%s", "string subscript out of range")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"string subscript out of range\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 3204, 0); } while (false); }; } while (false);

			return (_My_data._Myptr()[_Off]);
		}

		const_reference operator[](const size_type _Off) const
		{
			auto& _My_data = this->_Get_data();

			do { if (_Off <= _My_data._Mysize) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 3213, 0, "%s", "string subscript out of range")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"string subscript out of range\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 3213, 0); } while (false); }; } while (false);

			return (_My_data._Myptr()[_Off]);
		}

		void push_back(const _Elem _Ch)
		{
			auto& _My_data = this->_Get_data();
			const size_type _Old_size = _My_data._Mysize;
			if (_Old_size < _My_data._Myres)
			{
				_My_data._Mysize = _Old_size + 1;
				_Elem * const _Ptr = _My_data._Myptr();
				_Traits::assign(_Ptr[_Old_size], _Ch);
				_Traits::assign(_Ptr[_Old_size + 1], _Elem());
				return;
			}

			_Reallocate_grow_by(1,
				[](_Elem * const _New_ptr, const _Elem * const _Old_ptr, const size_type _Old_size,
					const _Elem _Ch) {
				_Traits::copy(_New_ptr, _Old_ptr, _Old_size);
				_Traits::assign(_New_ptr[_Old_size], _Ch);
				_Traits::assign(_New_ptr[_Old_size + 1], _Elem());
			}, _Ch);
		}

		void pop_back()
		{
			auto& _My_data = this->_Get_data();
			const size_type _Old_size = _My_data._Mysize;

			do { if (_Old_size != 0) {} else { do { (void)((1 != _CrtDbgReport(2, "c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 3253, 0, "%s", "invalid to pop_back empty string")) || (__debugbreak(), 0)); ::_invalid_parameter(L"\"invalid to pop_back empty string\"", __LPREFIX(__FUNCTION__), L"c:\\program files\\microsoft visual studio\\2017\\community\\vc\\tools\\msvc\\14.16.27023\\include\\xstring", 3253, 0); } while (false); }; } while (false);

			_Eos(_Old_size - 1);
		}

		reference front()
		{
			return (*begin());
		}

		const_reference front() const
		{
			return (*begin());
		}

		reference back()
		{
			return (*(end() - 1));
		}

		const_reference back() const
		{
			return (*(end() - 1));
		}

		const _Elem * c_str() const noexcept
		{
			return (this->_Get_data()._Myptr());
		}

		const _Elem * data() const noexcept
		{
			return (this->_Get_data()._Myptr());
		}

		size_type length() const noexcept
		{
			return (this->_Get_data()._Mysize);
		}

		size_type size() const noexcept
		{
			return (this->_Get_data()._Mysize);
		}

		size_type max_size() const noexcept
		{
			const size_type _Alloc_max = _Alty_traits::max_size(this->_Getal());
			const size_type _Storage_max =
				_Max_value(_Alloc_max, static_cast<size_type>(this->_BUF_SIZE));
			return (_Min_value(
				static_cast<size_type>((numeric_limits<difference_type>::max)()),
				_Storage_max - 1
			));

		}

		void resize(const size_type _Newsize, const _Elem _Ch = _Elem())
		{
			const size_type _Old_size = size();
			if (_Newsize <= _Old_size)
			{
				_Eos(_Newsize);
			}
			else
			{
				append(_Newsize - _Old_size, _Ch);
			}
		}

		size_type capacity() const noexcept
		{
			return (this->_Get_data()._Myres);
		}

		void reserve(const size_type _Newcap = 0)
		{
			auto& _My_data = this->_Get_data();
			if (_My_data._Mysize > _Newcap)
			{
				return;
			}

			if (_My_data._Myres == _Newcap)
			{
				return;
			}

			if (_My_data._Myres < _Newcap)
			{
				const size_type _Old_size = _My_data._Mysize;
				_Reallocate_grow_by(_Newcap - _Old_size,
					[](_Elem * const _New_ptr, const _Elem * const _Old_ptr, const size_type _Old_size) {
					_Traits::copy(_New_ptr, _Old_ptr, _Old_size + 1);
				});

				_My_data._Mysize = _Old_size;
				return;
			}

			if (this->_BUF_SIZE > _Newcap && _My_data._Large_string_engaged())
			{
				_Become_small();
				return;
			}

		}

		bool empty() const noexcept
		{
			return (size() == 0);
		}

		size_type copy(_Elem * const _Ptr,
			size_type _Count, const size_type _Off = 0) const
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset(_Off);
			_Count = _My_data._Clamp_suffix_size(_Off, _Count);
			_Traits::copy(_Ptr, _My_data._Myptr() + _Off, _Count);
			return (_Count);
		}

		size_type _Copy_s(
			_Elem * const _Dest, const size_type _Dest_size,
			size_type _Count, const size_type _Off = 0) const
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset(_Off);
			_Count = _My_data._Clamp_suffix_size(_Off, _Count);
			_Traits::_Copy_s(_Dest, _Dest_size, _My_data._Myptr() + _Off, _Count);
			return (_Count);
		}

		void _Swap_data(basic_string& _Right, true_type)
		{
			const auto _My_data_mem = reinterpret_cast<unsigned char *>(::std::addressof(this->_Get_data()))
				+ _Memcpy_move_offset;
			const auto _Right_data_mem = reinterpret_cast<unsigned char *>(::std::addressof(_Right._Get_data()))
				+ _Memcpy_move_offset;
			unsigned char _Temp_mem[_Memcpy_move_size];
			::memcpy(_Temp_mem, _My_data_mem, _Memcpy_move_size);
			::memcpy(_My_data_mem, _Right_data_mem, _Memcpy_move_size);
			::memcpy(_Right_data_mem, _Temp_mem, _Memcpy_move_size);
		}

		void _Swap_bx_large_with_small(_Mydata_t& _Starts_large, _Mydata_t& _Starts_small)
		{
			const pointer _Ptr = _Starts_large._Bx._Ptr;
			auto& _Al = this->_Getal();
			_Alty_traits::destroy(_Al, ::std::addressof(_Starts_large._Bx._Ptr));
			_Traits::copy(_Starts_large._Bx._Buf, _Starts_small._Bx._Buf, this->_BUF_SIZE);
			_Alty_traits::construct(_Al, ::std::addressof(_Starts_small._Bx._Ptr), _Ptr);
		}

		void _Swap_data(basic_string& _Right, false_type)
		{
			auto& _My_data = this->_Get_data();
			auto& _Right_data = _Right._Get_data();
			const bool _My_large = _My_data._Large_string_engaged();
			const bool _Right_large = _Right_data._Large_string_engaged();
			if (_My_large)
			{
				if (_Right_large)
				{
					_Swap_adl(_My_data._Bx._Ptr, _Right_data._Bx._Ptr);
				}
				else
				{
					_Swap_bx_large_with_small(_My_data, _Right_data);
				}
			}
			else
			{
				if (_Right_large)
				{
					_Swap_bx_large_with_small(_Right_data, _My_data);
				}
				else
				{
					_Elem _Temp_buf[this->_BUF_SIZE];
					_Traits::copy(_Temp_buf, _My_data._Bx._Buf, this->_BUF_SIZE);
					_Traits::copy(_My_data._Bx._Buf, _Right_data._Bx._Buf, this->_BUF_SIZE);
					_Traits::copy(_Right_data._Bx._Buf, _Temp_buf, this->_BUF_SIZE);
				}
			}

			::std::swap(_My_data._Mysize, _Right_data._Mysize);
			::std::swap(_My_data._Myres, _Right_data._Myres);
		}

		void swap(basic_string& _Right) noexcept
		{
			if (this != ::std::addressof(_Right))
			{
				_Pocs(this->_Getal(), _Right._Getal());

				auto& _My_data = this->_Get_data();
				auto& _Right_data = _Right._Get_data();
				const bool _My_large = _My_data._Large_string_engaged();
				const bool _Right_large = _Right_data._Large_string_engaged();
				if (!_My_large)
				{
					_My_data._Orphan_all();
				}

				if (!_Right_large)
				{
					_Right_data._Orphan_all();
				}

				if (_My_large || _Right_large)
				{
					_My_data._Swap_all(_Right_data);
				}

			}

			_Swap_data(_Right, _Use_memcpy_move{});
		}

		size_type find(const basic_string& _Right, const size_type _Off = 0) const noexcept
		{
			auto& _My_data = this->_Get_data();
			auto& _Right_data = _Right._Get_data();
			return (static_cast<size_type>(
				_Traits_find<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off,
					_Right_data._Myptr(), _Right_data._Mysize)));
		}

		size_type find(const _Elem * const _Ptr, const size_type _Off, const size_type _Count)
			const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_find<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ptr, _Count)));
		}

		size_type find(const _Elem * const _Ptr, const size_type _Off = 0) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_find<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ptr, _Traits::length(_Ptr))));
		}

		size_type find(const _Elem _Ch, const size_type _Off = 0) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_find_ch<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ch)));
		}

		size_type rfind(const basic_string& _Right, const size_type _Off = npos) const noexcept
		{
			auto& _My_data = this->_Get_data();
			auto& _Right_data = _Right._Get_data();
			return (static_cast<size_type>(
				_Traits_rfind<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off,
					_Right_data._Myptr(), _Right_data._Mysize)));
		}

		size_type rfind(const _Elem * const _Ptr, const size_type _Off,
			const size_type _Count) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_rfind<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ptr, _Count)));
		}

		size_type rfind(const _Elem * const _Ptr, const size_type _Off = npos)
			const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_rfind<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ptr, _Traits::length(_Ptr))));
		}

		size_type rfind(const _Elem _Ch, const size_type _Off = npos) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_rfind_ch<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ch)));
		}

		size_type find_first_of(const basic_string& _Right, const size_type _Off = 0) const noexcept
		{
			auto& _My_data = this->_Get_data();
			auto& _Right_data = _Right._Get_data();
			return (static_cast<size_type>(_Traits_find_first_of<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off,
				_Right_data._Myptr(), _Right_data._Mysize, _Is_specialization<_Traits, char_traits>{})));
		}

		size_type find_first_of(const _Elem * const _Ptr, const size_type _Off,
			const size_type _Count) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_find_first_of<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ptr, _Count,
					_Is_specialization<_Traits, char_traits>{})));
		}

		size_type find_first_of(const _Elem * const _Ptr, const size_type _Off = 0)
			const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_find_first_of<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ptr, _Traits::length(_Ptr),
					_Is_specialization<_Traits, char_traits>{})));
		}

		size_type find_first_of(const _Elem _Ch, const size_type _Off = 0) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_find_ch<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ch)));
		}

		size_type find_last_of(const basic_string& _Right, size_type _Off = npos) const noexcept
		{
			auto& _My_data = this->_Get_data();
			auto& _Right_data = _Right._Get_data();
			return (static_cast<size_type>(_Traits_find_last_of<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off,
				_Right_data._Myptr(), _Right_data._Mysize, _Is_specialization<_Traits, char_traits>{})));
		}

		size_type find_last_of(const _Elem * const _Ptr, const size_type _Off,
			const size_type _Count) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_find_last_of<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ptr, _Count,
					_Is_specialization<_Traits, char_traits>{})));
		}

		size_type find_last_of(const _Elem * const _Ptr, const size_type _Off = npos)
			const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_find_last_of<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ptr, _Traits::length(_Ptr),
					_Is_specialization<_Traits, char_traits>{})));
		}

		size_type find_last_of(const _Elem _Ch, const size_type _Off = npos) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(_Traits_rfind_ch<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ch)));
		}

		size_type find_first_not_of(const basic_string& _Right, const size_type _Off = 0) const noexcept
		{
			auto& _My_data = this->_Get_data();
			auto& _Right_data = _Right._Get_data();
			return (static_cast<size_type>(_Traits_find_first_not_of<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off,
				_Right_data._Myptr(), _Right_data._Mysize, _Is_specialization<_Traits, char_traits>{})));
		}

		size_type find_first_not_of(const _Elem * const _Ptr, const size_type _Off,
			const size_type _Count) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_find_first_not_of<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ptr, _Count,
					_Is_specialization<_Traits, char_traits>{})));
		}

		size_type find_first_not_of(const _Elem * const _Ptr, size_type _Off = 0) const
			noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_find_first_not_of<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ptr,
					_Traits::length(_Ptr), _Is_specialization<_Traits, char_traits>{})));
		}

		size_type find_first_not_of(const _Elem _Ch, const size_type _Off = 0) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(_Traits_find_not_ch<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ch)));
		}

		size_type find_last_not_of(const basic_string& _Right, const size_type _Off = npos) const noexcept
		{
			auto& _My_data = this->_Get_data();
			auto& _Right_data = _Right._Get_data();
			return (static_cast<size_type>(_Traits_find_last_not_of<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off,
				_Right_data._Myptr(), _Right_data._Mysize, _Is_specialization<_Traits, char_traits>{})));
		}

		size_type find_last_not_of(const _Elem * const _Ptr, const size_type _Off,
			const size_type _Count) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_find_last_not_of<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ptr, _Count,
					_Is_specialization<_Traits, char_traits>{})));
		}

		size_type find_last_not_of(const _Elem * const _Ptr, const size_type _Off = npos) const
			noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(_Traits_find_last_not_of<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off,
				_Ptr, _Traits::length(_Ptr), _Is_specialization<_Traits, char_traits>{})));
		}

		size_type find_last_not_of(const _Elem _Ch, const size_type _Off = npos) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (static_cast<size_type>(
				_Traits_rfind_not_ch<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Off, _Ch)));
		}

		basic_string substr(const size_type _Off = 0, const size_type _Count = npos) const
		{
			return (basic_string(*this, _Off, _Count, get_allocator()));
		}

		bool _Equal(const basic_string& _Right) const noexcept
		{
			auto& _My_data = this->_Get_data();
			auto& _Right_data = _Right._Get_data();
			return (_Traits_equal<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Right_data._Myptr(), _Right_data._Mysize));
		}

		bool _Equal(const _Elem * const _Ptr) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (_Traits_equal<_Traits>(_My_data._Myptr(), _My_data._Mysize, _Ptr, _Traits::length(_Ptr)));
		}

		int compare(const basic_string& _Right) const noexcept
		{
			auto& _My_data = this->_Get_data();
			auto& _Right_data = _Right._Get_data();
			return (_Traits_compare<_Traits>(_My_data._Myptr(), _My_data._Mysize,
				_Right_data._Myptr(), _Right_data._Mysize));
		}

		int compare(size_type _Off, size_type _N0, const basic_string& _Right) const
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset(_Off);
			auto& _Right_data = _Right._Get_data();
			return (_Traits_compare<_Traits>(_My_data._Myptr() + _Off, _My_data._Clamp_suffix_size(_Off, _N0),
				_Right_data._Myptr(), _Right_data._Mysize));
		}

		int compare(const size_type _Off, const size_type _N0, const basic_string& _Right,
			const size_type _Roff, const size_type _Count = npos) const
		{
			auto& _My_data = this->_Get_data();
			auto& _Right_data = _Right._Get_data();
			_My_data._Check_offset(_Off);
			_Right_data._Check_offset(_Roff);
			return (_Traits_compare<_Traits>(_My_data._Myptr() + _Off, _My_data._Clamp_suffix_size(_Off, _N0),
				_Right_data._Myptr() + _Roff, _Right_data._Clamp_suffix_size(_Roff, _Count)));
		}

		int compare(const _Elem * const _Ptr) const noexcept
		{
			auto& _My_data = this->_Get_data();
			return (_Traits_compare<_Traits>(_My_data._Myptr(), _My_data._Mysize,
				_Ptr, _Traits::length(_Ptr)));
		}

		int compare(const size_type _Off, const size_type _N0, const _Elem * const _Ptr) const
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset(_Off);
			return (_Traits_compare<_Traits>(_My_data._Myptr() + _Off, _My_data._Clamp_suffix_size(_Off, _N0),
				_Ptr, _Traits::length(_Ptr)));
		}

		int compare(const size_type _Off, const size_type _N0, const _Elem * const _Ptr,
			const size_type _Count) const
		{
			auto& _My_data = this->_Get_data();
			_My_data._Check_offset(_Off);
			return (_Traits_compare<_Traits>(_My_data._Myptr() + _Off, _My_data._Clamp_suffix_size(_Off, _N0),
				_Ptr, _Count));
		}

		allocator_type get_allocator() const noexcept
		{
			return (static_cast<allocator_type>(this->_Getal()));
		}

		size_type _Calculate_growth(const size_type _Requested) const
		{
			const size_type _Max = max_size();
			auto& _My_data = this->_Get_data();
			const size_type _Masked = _Requested | this->_ALLOC_MASK;
			if (_Masked > _Max)
			{
				return (_Max);
			}

			const size_type _Old = _My_data._Myres;
			if (_Old > _Max - _Old / 2)
			{
				return (_Max);
			}

			return (_Max_value(_Masked, _Old + _Old / 2));
		}

		template<class _Fty,
			class... _ArgTys>
			basic_string& _Reallocate_for(const size_type _New_size, _Fty _Fn, _ArgTys... _Args)
		{

			if (_New_size > max_size())
			{
				_Xlen();
			}

			auto& _My_data = this->_Get_data();
			const size_type _Old_capacity = _My_data._Myres;
			const size_type _New_capacity = _Calculate_growth(_New_size);
			auto& _Al = this->_Getal();
			const pointer _New_ptr = _Al.allocate(_New_capacity + 1);
			_My_data._Orphan_all();
			_My_data._Mysize = _New_size;
			_My_data._Myres = _New_capacity;
			_Fn(_Unfancy(_New_ptr), _New_size, _Args...);
			if (this->_BUF_SIZE <= _Old_capacity)
			{
				_Al.deallocate(_My_data._Bx._Ptr, _Old_capacity + 1);
				_My_data._Bx._Ptr = _New_ptr;
			}
			else
			{
				_Alty_traits::construct(_Al, ::std::addressof(_My_data._Bx._Ptr), _New_ptr);
			}

			return (*this);
		}

		template<class _Fty,
			class... _ArgTys>
			basic_string& _Reallocate_grow_by(const size_type _Size_increase, _Fty _Fn, _ArgTys... _Args)
		{

			auto& _My_data = this->_Get_data();
			const size_type _Old_size = _My_data._Mysize;
			if (max_size() - _Old_size < _Size_increase)
			{
				_Xlen();
			}

			const size_type _New_size = _Old_size + _Size_increase;
			const size_type _Old_capacity = _My_data._Myres;
			const size_type _New_capacity = _Calculate_growth(_New_size);
			auto& _Al = this->_Getal();
			const pointer _New_ptr = _Al.allocate(_New_capacity + 1);
			_My_data._Orphan_all();
			_My_data._Mysize = _New_size;
			_My_data._Myres = _New_capacity;
			_Elem * const _Raw_new = _Unfancy(_New_ptr);
			if (this->_BUF_SIZE <= _Old_capacity)
			{
				const pointer _Old_ptr = _My_data._Bx._Ptr;
				_Fn(_Raw_new, _Unfancy(_Old_ptr), _Old_size, _Args...);
				_Al.deallocate(_Old_ptr, _Old_capacity + 1);
				_My_data._Bx._Ptr = _New_ptr;
			}
			else
			{
				_Fn(_Raw_new, _My_data._Bx._Buf, _Old_size, _Args...);
				_Alty_traits::construct(_Al, ::std::addressof(_My_data._Bx._Ptr), _New_ptr);
			}

			return (*this);
		}

		void _Become_small()
		{

			auto& _My_data = this->_Get_data();
			_My_data._Orphan_all();
			const pointer _Ptr = _My_data._Bx._Ptr;
			auto& _Al = this->_Getal();
			_Alty_traits::destroy(_Al, ::std::addressof(_My_data._Bx._Ptr));
			_Traits::copy(_My_data._Bx._Buf, _Unfancy(_Ptr), _My_data._Mysize + 1);
			_Al.deallocate(_Ptr, _My_data._Myres + 1);
			_My_data._Myres = this->_BUF_SIZE - 1;
		}

		void _Eos(const size_type _Newsize)
		{
			auto& _My_data = this->_Get_data();
			_Traits::assign(_My_data._Myptr()[_My_data._Mysize = _Newsize], _Elem());
		}

		void _Tidy_init()
		{
			auto& _My_data = this->_Get_data();
			_My_data._Mysize = 0;
			_My_data._Myres = this->_BUF_SIZE - 1;

			_Traits::assign(_My_data._Bx._Buf[0], _Elem());
		}

		void _Tidy_deallocate()
		{
			this->_Orphan_all();
			auto& _My_data = this->_Get_data();
			if (_My_data._Large_string_engaged())
			{
				const pointer _Ptr = _My_data._Bx._Ptr;
				auto& _Al = this->_Getal();
				_Alty_traits::destroy(_Al, ::std::addressof(_My_data._Bx._Ptr));
				_Al.deallocate(_Ptr, _My_data._Myres + 1);
			}

			_My_data._Mysize = 0;
			_My_data._Myres = this->_BUF_SIZE - 1;

			_Traits::assign(_My_data._Bx._Buf[0], _Elem());
		}

		[[noreturn]] static void _Xlen()
		{
			_Xlength_error("string too long");
		}
	};

	template<class _Elem,
		class _Traits,
		class _Alloc> inline
		void swap(basic_string<_Elem, _Traits, _Alloc>& _Left,
			basic_string<_Elem, _Traits, _Alloc>& _Right) noexcept
	{
		_Left.swap(_Right);
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline basic_string<_Elem, _Traits, _Alloc> operator+(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{
		basic_string<_Elem, _Traits, _Alloc> _Ans;
		_Ans.reserve(_Left.size() + _Right.size());
		_Ans += _Left;
		_Ans += _Right;
		return (_Ans);
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline basic_string<_Elem, _Traits, _Alloc> operator+(
			const _Elem * const _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{
		using _String_type = basic_string<_Elem, _Traits, _Alloc>;
		using _Size_type = typename _String_type::size_type;
		_String_type _Ans;
		_Ans.reserve(_Convert_size<_Size_type>(_Traits::length(_Left) + _Right.size()));
		_Ans += _Left;
		_Ans += _Right;
		return (_Ans);
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline basic_string<_Elem, _Traits, _Alloc> operator+(
			const _Elem _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{
		basic_string<_Elem, _Traits, _Alloc> _Ans;
		_Ans.reserve(1 + _Right.size());
		_Ans += _Left;
		_Ans += _Right;
		return (_Ans);
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline basic_string<_Elem, _Traits, _Alloc> operator+(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const _Elem * const _Right)
	{
		using _String_type = basic_string<_Elem, _Traits, _Alloc>;
		using _Size_type = typename _String_type::size_type;
		_String_type _Ans;
		_Ans.reserve(_Convert_size<_Size_type>(_Left.size() + _Traits::length(_Right)));
		_Ans += _Left;
		_Ans += _Right;
		return (_Ans);
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline basic_string<_Elem, _Traits, _Alloc> operator+(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const _Elem _Right)
	{
		basic_string<_Elem, _Traits, _Alloc> _Ans;
		_Ans.reserve(_Left.size() + 1);
		_Ans += _Left;
		_Ans += _Right;
		return (_Ans);
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline basic_string<_Elem, _Traits, _Alloc> operator+(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			basic_string<_Elem, _Traits, _Alloc>&& _Right)
	{
		return (::std::move(_Right.insert(0, _Left)));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline basic_string<_Elem, _Traits, _Alloc> operator+(
			basic_string<_Elem, _Traits, _Alloc>&& _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{
		return (::std::move(_Left.append(_Right)));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline basic_string<_Elem, _Traits, _Alloc> operator+(
			basic_string<_Elem, _Traits, _Alloc>&& _Left,
			basic_string<_Elem, _Traits, _Alloc>&& _Right)
	{
		if (_Right.size() <= _Left.capacity() - _Left.size()
			|| _Right.capacity() - _Right.size() < _Left.size())
			return (::std::move(_Left.append(_Right)));
		else
			return (::std::move(_Right.insert(0, _Left)));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline basic_string<_Elem, _Traits, _Alloc> operator+(
			const _Elem * const _Left,
			basic_string<_Elem, _Traits, _Alloc>&& _Right)
	{
		return (::std::move(_Right.insert(0, _Left)));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline basic_string<_Elem, _Traits, _Alloc> operator+(
			const _Elem _Left,
			basic_string<_Elem, _Traits, _Alloc>&& _Right)
	{
		using size_type = typename allocator_traits<_Alloc>::size_type;
		return (::std::move(_Right.insert(static_cast<size_type>(0), static_cast<size_type>(1), _Left)));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline basic_string<_Elem, _Traits, _Alloc> operator+(
			basic_string<_Elem, _Traits, _Alloc>&& _Left,
			const _Elem * const _Right)
	{
		return (::std::move(_Left.append(_Right)));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline basic_string<_Elem, _Traits, _Alloc> operator+(
			basic_string<_Elem, _Traits, _Alloc>&& _Left,
			const _Elem _Right)
	{
		_Left.push_back(_Right);
		return (::std::move(_Left));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator==(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right) noexcept
	{
		return (_Left._Equal(_Right));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator==(
			const _Elem * const _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{
		return (_Right._Equal(_Left));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator==(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const _Elem * const _Right)
	{
		return (_Left._Equal(_Right));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator!=(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right) noexcept
	{
		return (!(_Left == _Right));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator!=(
			const _Elem * const _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{
		return (!(_Left == _Right));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator!=(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const _Elem * const _Right)
	{
		return (!(_Left == _Right));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator<(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right) noexcept
	{
		return (_Left.compare(_Right) < 0);
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator<(
			const _Elem * const _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{
		return (_Right.compare(_Left) > 0);
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator<(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const _Elem * const _Right)
	{
		return (_Left.compare(_Right) < 0);
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator>(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right) noexcept
	{
		return (_Right < _Left);
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator>(
			const _Elem * const _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{
		return (_Right < _Left);
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator>(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const _Elem * const _Right)
	{
		return (_Right < _Left);
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator<=(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right) noexcept
	{
		return (!(_Right < _Left));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator<=(
			const _Elem * const _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{
		return (!(_Right < _Left));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator<=(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const _Elem * const _Right)
	{
		return (!(_Right < _Left));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator>=(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right) noexcept
	{
		return (!(_Left < _Right));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator>=(
			const _Elem * const _Left,
			const basic_string<_Elem, _Traits, _Alloc>& _Right)
	{
		return (!(_Left < _Right));
	}

	template<class _Elem,
		class _Traits,
		class _Alloc>
		inline bool operator>=(
			const basic_string<_Elem, _Traits, _Alloc>& _Left,
			const _Elem * const _Right)
	{
		return (!(_Left < _Right));
	}

	using string = basic_string<char, char_traits<char>, allocator<char>>;
	using wstring = basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>;
	using u16string = basic_string<char16_t, char_traits<char16_t>, allocator<char16_t>>;
	using u32string = basic_string<char32_t, char_traits<char32_t>, allocator<char32_t>>;

	template<class _Elem,
		class _Traits,
		class _Alloc>
		struct hash<basic_string<_Elem, _Traits, _Alloc>>
	{
		typedef basic_string<_Elem, _Traits, _Alloc> argument_type;
		typedef size_t result_type;

		size_t operator()(const basic_string<_Elem, _Traits, _Alloc>& _Keyval) const noexcept
		{
			return (_Hash_array_representation(_Keyval.c_str(), _Keyval.size()));
		}
	};
}

#pragma warning(pop)
#pragma pack(pop)

#pragma pack(push,8)
#pragma warning(push,3)
#pragma warning(disable: 4455 4494  4619 4643 4702 4984 4988 )

namespace std {

	template<class _Ty = void>
	struct divides
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef _Ty result_type;

		constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left / _Right);
		}
	};

	template<class _Ty = void>
	struct modulus
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef _Ty result_type;

		constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left % _Right);
		}
	};

	template<class _Ty = void>
	struct negate
	{
		typedef _Ty argument_type;
		typedef _Ty result_type;

		constexpr _Ty operator()(const _Ty& _Left) const
		{
			return (-_Left);
		}
	};

	template<class _Ty = void>
	struct logical_and
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left && _Right);
		}
	};

	template<class _Ty = void>
	struct logical_or
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left || _Right);
		}
	};

	template<class _Ty = void>
	struct logical_not
	{
		typedef _Ty argument_type;
		typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left) const
		{
			return (!_Left);
		}
	};

	template<class _Ty = void>
	struct bit_and
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef _Ty result_type;

		constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left & _Right);
		}
	};

	template<class _Ty = void>
	struct bit_or
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef _Ty result_type;

		constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left | _Right);
		}
	};

	template<class _Ty = void>
	struct bit_xor
	{
		typedef _Ty first_argument_type;
		typedef _Ty second_argument_type;
		typedef _Ty result_type;

		constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{
			return (_Left ^ _Right);
		}
	};

	template<class _Ty = void>
	struct bit_not
	{
		typedef _Ty argument_type;
		typedef _Ty result_type;

		constexpr _Ty operator()(const _Ty& _Left) const
		{
			return (~_Left);
		}
	};

	template<>
	struct divides<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(::std::forward<_Ty1>(_Left) / ::std::forward<_Ty2>(_Right))
		{
			return (::std::forward<_Ty1>(_Left) / ::std::forward<_Ty2>(_Right));
		}
	};

	template<>
	struct modulus<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(::std::forward<_Ty1>(_Left) % ::std::forward<_Ty2>(_Right))
		{
			return (::std::forward<_Ty1>(_Left) % ::std::forward<_Ty2>(_Right));
		}
	};

	template<>
	struct negate<void>
	{
		typedef int is_transparent;

		template<class _Ty>
		constexpr auto operator()(_Ty&& _Left) const
			-> decltype(-::std::forward<_Ty>(_Left))
		{
			return (-::std::forward<_Ty>(_Left));
		}
	};

	template<>
	struct logical_and<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(::std::forward<_Ty1>(_Left) && ::std::forward<_Ty2>(_Right))
		{
			return (::std::forward<_Ty1>(_Left) && ::std::forward<_Ty2>(_Right));
		}
	};

	template<>
	struct logical_or<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(::std::forward<_Ty1>(_Left) || ::std::forward<_Ty2>(_Right))
		{
			return (::std::forward<_Ty1>(_Left) || ::std::forward<_Ty2>(_Right));
		}
	};

	template<>
	struct logical_not<void>
	{
		typedef int is_transparent;

		template<class _Ty>
		constexpr auto operator()(_Ty&& _Left) const
			-> decltype(!::std::forward<_Ty>(_Left))
		{
			return (!::std::forward<_Ty>(_Left));
		}
	};

	template<>
	struct bit_and<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(::std::forward<_Ty1>(_Left) & ::std::forward<_Ty2>(_Right))
		{
			return (::std::forward<_Ty1>(_Left) & ::std::forward<_Ty2>(_Right));
		}
	};

	template<>
	struct bit_or<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(::std::forward<_Ty1>(_Left) | ::std::forward<_Ty2>(_Right))
		{
			return (::std::forward<_Ty1>(_Left) | ::std::forward<_Ty2>(_Right));
		}
	};

	template<>
	struct bit_xor<void>
	{
		typedef int is_transparent;

		template<class _Ty1,
			class _Ty2>
			constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
			-> decltype(::std::forward<_Ty1>(_Left) ^ ::std::forward<_Ty2>(_Right))
		{
			return (::std::forward<_Ty1>(_Left) ^ ::std::forward<_Ty2>(_Right));
		}
	};

	template<>
	struct bit_not<void>
	{
		typedef int is_transparent;

		template<class _Ty>
		constexpr auto operator()(_Ty&& _Left) const
			-> decltype(~::std::forward<_Ty>(_Left))
		{
			return (~::std::forward<_Ty>(_Left));
		}
	};

#pragma warning(push)
#pragma warning(disable: 4996)	

	template<class _Fn>
	class  unary_negate
	{
	public:
		typedef typename _Fn::argument_type argument_type;
		typedef bool result_type;

		constexpr explicit unary_negate(const _Fn& _Func)
			: _Functor(_Func)
		{
		}

		constexpr bool operator()(const argument_type& _Left) const
		{
			return (!_Functor(_Left));
		}

	private:
		_Fn _Functor;
	};

	template<class _Fn>
	constexpr unary_negate<_Fn> not1(const _Fn& _Func)
	{
		return (unary_negate<_Fn>(_Func));
	}

	template<class _Fn>
	class  binary_negate
	{
	public:
		typedef typename _Fn::first_argument_type first_argument_type;
		typedef typename _Fn::second_argument_type second_argument_type;
		typedef bool result_type;

		constexpr explicit binary_negate(const _Fn& _Func)
			: _Functor(_Func)
		{
		}

		constexpr bool operator()(const first_argument_type& _Left,
			const second_argument_type& _Right) const
		{
			return (!_Functor(_Left, _Right));
		}

	private:
		_Fn _Functor;
	};

	template<class _Fn>
	constexpr binary_negate<_Fn> not2(const _Fn& _Func)
	{
		return (binary_negate<_Fn>(_Func));
	}
#pragma warning(pop)

#pragma warning(push)
#pragma warning(disable: 4996)	

	template<class _Fn>
	class binder1st
		: public unary_function<typename _Fn::second_argument_type,
		typename _Fn::result_type>
	{
	public:
		typedef unary_function<typename _Fn::second_argument_type,
			typename _Fn::result_type> _Base;
		typedef typename _Base::argument_type argument_type;
		typedef typename _Base::result_type result_type;

		binder1st(const _Fn& _Func,
			const typename _Fn::first_argument_type& _Left)
			: op(_Func), value(_Left)
		{
		}

		result_type operator()(const argument_type& _Right) const
		{
			return (op(value, _Right));
		}

		result_type operator()(argument_type& _Right) const
		{
			return (op(value, _Right));
		}

	protected:
		_Fn op;
		typename _Fn::first_argument_type value;
	};

	template<class _Fn,
		class _Ty>
		inline binder1st<_Fn> bind1st(const _Fn& _Func, const _Ty& _Left)
	{
		typename _Fn::first_argument_type _Val(_Left);
		return (binder1st<_Fn>(_Func, _Val));
	}

	template<class _Fn>
	class binder2nd
		: public unary_function<typename _Fn::first_argument_type,
		typename _Fn::result_type>
	{
	public:
		typedef unary_function<typename _Fn::first_argument_type,
			typename _Fn::result_type> _Base;
		typedef typename _Base::argument_type argument_type;
		typedef typename _Base::result_type result_type;

		binder2nd(const _Fn& _Func,
			const typename _Fn::second_argument_type& _Right)
			: op(_Func), value(_Right)
		{
		}

		result_type operator()(const argument_type& _Left) const
		{
			return (op(_Left, value));
		}

		result_type operator()(argument_type& _Left) const
		{
			return (op(_Left, value));
		}

	protected:
		_Fn op;
		typename _Fn::second_argument_type value;
	};

	template<class _Fn,
		class _Ty>
		inline binder2nd<_Fn> bind2nd(const _Fn& _Func, const _Ty& _Right)
	{
		typename _Fn::second_argument_type _Val(_Right);
		return (binder2nd<_Fn>(_Func, _Val));
	}
#pragma warning(pop)

	template<class _Arg,
		class _Result,
		class _Fn = _Result(*)(_Arg)>
		class pointer_to_unary_function
		: public unary_function<_Arg, _Result>
	{
	public:
		explicit pointer_to_unary_function(_Fn _Left)
			: _Pfun(_Left)
		{
		}

		_Result operator()(_Arg _Left) const
		{
			return (_Pfun(_Left));
		}

	protected:
		_Fn _Pfun;
	};

	template<class _Arg1,
		class _Arg2,
		class _Result,
		class _Fn = _Result(*)(_Arg1, _Arg2)>
		class pointer_to_binary_function
		: public binary_function<_Arg1, _Arg2, _Result>
	{
	public:
		explicit pointer_to_binary_function(_Fn _Left)
			: _Pfun(_Left)
		{
		}

		_Result operator()(_Arg1 _Left, _Arg2 _Right) const
		{
			return (_Pfun(_Left, _Right));
		}

	protected:
		_Fn _Pfun;
	};

	template<class _Arg, class _Result>  inline pointer_to_unary_function<_Arg, _Result, _Result(__cdecl *)(_Arg)> ptr_fun(_Result(__cdecl *_Left)(_Arg)) { return (pointer_to_unary_function<_Arg, _Result, _Result(__cdecl *)(_Arg)>(_Left)); } template<class _Arg1, class _Arg2, class _Result>  inline pointer_to_binary_function<_Arg1, _Arg2, _Result, _Result(__cdecl *)(_Arg1, _Arg2)> ptr_fun(_Result(__cdecl *_Left)(_Arg1, _Arg2)) { return (pointer_to_binary_function<_Arg1, _Arg2, _Result, _Result(__cdecl *)(_Arg1, _Arg2)>(_Left)); }  template<class _Arg, class _Result>  inline pointer_to_unary_function<_Arg, _Result, _Result(__fastcall *)(_Arg)> ptr_fun(_Result(__fastcall *_Left)(_Arg)) { return (pointer_to_unary_function<_Arg, _Result, _Result(__fastcall *)(_Arg)>(_Left)); } template<class _Arg1, class _Arg2, class _Result>  inline pointer_to_binary_function<_Arg1, _Arg2, _Result, _Result(__fastcall *)(_Arg1, _Arg2)> ptr_fun(_Result(__fastcall *_Left)(_Arg1, _Arg2)) { return (pointer_to_binary_function<_Arg1, _Arg2, _Result, _Result(__fastcall *)(_Arg1, _Arg2)>(_Left)); } template<class _Arg, class _Result>  inline pointer_to_unary_function<_Arg, _Result, _Result(__stdcall *)(_Arg)> ptr_fun(_Result(__stdcall *_Left)(_Arg)) { return (pointer_to_unary_function<_Arg, _Result, _Result(__stdcall *)(_Arg)>(_Left)); } template<class _Arg1, class _Arg2, class _Result>  inline pointer_to_binary_function<_Arg1, _Arg2, _Result, _Result(__stdcall *)(_Arg1, _Arg2)> ptr_fun(_Result(__stdcall *_Left)(_Arg1, _Arg2)) { return (pointer_to_binary_function<_Arg1, _Arg2, _Result, _Result(__stdcall *)(_Arg1, _Arg2)>(_Left)); } template<class _Arg, class _Result>  inline pointer_to_unary_function<_Arg, _Result, _Result(__vectorcall *)(_Arg)> ptr_fun(_Result(__vectorcall *_Left)(_Arg)) { return (pointer_to_unary_function<_Arg, _Result, _Result(__vectorcall *)(_Arg)>(_Left)); } template<class _Arg1, class _Arg2, class _Result>  inline pointer_to_binary_function<_Arg1, _Arg2, _Result, _Result(__vectorcall *)(_Arg1, _Arg2)> ptr_fun(_Result(__vectorcall *_Left)(_Arg1, _Arg2)) { return (pointer_to_binary_function<_Arg1, _Arg2, _Result, _Result(__vectorcall *)(_Arg1, _Arg2)>(_Left)); }

	template<class _Result,
		class _Ty>
		class mem_fun_t
		: public unary_function<_Ty *, _Result>
	{
	public:
		explicit mem_fun_t(_Result(_Ty::*_Pm)())
			: _Pmemfun(_Pm)
		{
		}

		_Result operator()(_Ty *_Pleft) const
		{
			return ((_Pleft->*_Pmemfun)());
		}

	private:
		_Result(_Ty::*_Pmemfun)();
	};

	template<class _Result,
		class _Ty,
		class _Arg>
		class mem_fun1_t
		: public binary_function<_Ty *, _Arg, _Result>
	{
	public:
		explicit mem_fun1_t(_Result(_Ty::*_Pm)(_Arg))
			: _Pmemfun(_Pm)
		{
		}

		_Result operator()(_Ty *_Pleft, _Arg _Right) const
		{
			return ((_Pleft->*_Pmemfun)(_Right));
		}

	private:
		_Result(_Ty::*_Pmemfun)(_Arg);
	};

	template<class _Result,
		class _Ty>
		class const_mem_fun_t
		: public unary_function<const _Ty *, _Result>
	{
	public:
		explicit const_mem_fun_t(_Result(_Ty::*_Pm)() const)
			: _Pmemfun(_Pm)
		{
		}

		_Result operator()(const _Ty *_Pleft) const
		{
			return ((_Pleft->*_Pmemfun)());
		}

	private:
		_Result(_Ty::*_Pmemfun)() const;
	};

	template<class _Result,
		class _Ty,
		class _Arg>
		class const_mem_fun1_t
		: public binary_function<const _Ty *, _Arg, _Result>
	{
	public:
		explicit const_mem_fun1_t(_Result(_Ty::*_Pm)(_Arg) const)
			: _Pmemfun(_Pm)
		{
		}

		_Result operator()(const _Ty *_Pleft, _Arg _Right) const
		{
			return ((_Pleft->*_Pmemfun)(_Right));
		}

	private:
		_Result(_Ty::*_Pmemfun)(_Arg) const;
	};

	template<class _Result,
		class _Ty>
		inline mem_fun_t<_Result, _Ty> mem_fun(_Result(_Ty::*_Pm)())
	{
		return (mem_fun_t<_Result, _Ty>(_Pm));
	}

	template<class _Result,
		class _Ty,
		class _Arg>
		inline mem_fun1_t<_Result, _Ty, _Arg> mem_fun(_Result(_Ty::*_Pm)(_Arg))
	{
		return (mem_fun1_t<_Result, _Ty, _Arg>(_Pm));
	}

	template<class _Result,
		class _Ty>
		inline const_mem_fun_t<_Result, _Ty> mem_fun(_Result(_Ty::*_Pm)() const)
	{
		return (const_mem_fun_t<_Result, _Ty>(_Pm));
	}

	template<class _Result,
		class _Ty,
		class _Arg>
		inline const_mem_fun1_t<_Result, _Ty, _Arg> mem_fun(_Result(_Ty::*_Pm)(_Arg) const)
	{
		return (const_mem_fun1_t<_Result, _Ty, _Arg>(_Pm));
	}

	template<class _Result,
		class _Ty>
		class mem_fun_ref_t
		: public unary_function<_Ty, _Result>
	{
	public:
		explicit mem_fun_ref_t(_Result(_Ty::*_Pm)())
			: _Pmemfun(_Pm)
		{
		}

		_Result operator()(_Ty& _Left) const
		{
			return ((_Left.*_Pmemfun)());
		}

	private:
		_Result(_Ty::*_Pmemfun)();
	};

	template<class _Result,
		class _Ty,
		class _Arg>
		class mem_fun1_ref_t
		: public binary_function<_Ty, _Arg, _Result>
	{
	public:
		explicit mem_fun1_ref_t(_Result(_Ty::*_Pm)(_Arg))
			: _Pmemfun(_Pm)
		{
		}

		_Result operator()(_Ty& _Left, _Arg _Right) const
		{
			return ((_Left.*_Pmemfun)(_Right));
		}

	private:
		_Result(_Ty::*_Pmemfun)(_Arg);
	};

	template<class _Result,
		class _Ty>
		class const_mem_fun_ref_t
		: public unary_function<_Ty, _Result>
	{
	public:
		explicit const_mem_fun_ref_t(_Result(_Ty::*_Pm)() const)
			: _Pmemfun(_Pm)
		{
		}

		_Result operator()(const _Ty& _Left) const
		{
			return ((_Left.*_Pmemfun)());
		}

	private:
		_Result(_Ty::*_Pmemfun)() const;
	};

	template<class _Result,
		class _Ty,
		class _Arg>
		class const_mem_fun1_ref_t
		: public binary_function<_Ty, _Arg, _Result>
	{
	public:
		explicit const_mem_fun1_ref_t(_Result(_Ty::*_Pm)(_Arg) const)
			: _Pmemfun(_Pm)
		{
		}

		_Result operator()(const _Ty& _Left, _Arg _Right) const
		{
			return ((_Left.*_Pmemfun)(_Right));
		}

	private:
		_Result(_Ty::*_Pmemfun)(_Arg) const;
	};

	template<class _Result,
		class _Ty>
		inline mem_fun_ref_t<_Result, _Ty> mem_fun_ref(_Result(_Ty::*_Pm)())
	{
		return (mem_fun_ref_t<_Result, _Ty>(_Pm));
	}

	template<class _Result,
		class _Ty,
		class _Arg>
		inline mem_fun1_ref_t<_Result, _Ty, _Arg> mem_fun_ref(_Result(_Ty::*_Pm)(_Arg))
	{
		return (mem_fun1_ref_t<_Result, _Ty, _Arg>(_Pm));
	}

	template<class _Result,
		class _Ty>
		inline const_mem_fun_ref_t<_Result, _Ty> mem_fun_ref(_Result(_Ty::*_Pm)() const)
	{
		return (const_mem_fun_ref_t<_Result, _Ty>(_Pm));
	}

	template<class _Result,
		class _Ty,
		class _Arg>
		inline const_mem_fun1_ref_t<_Result, _Ty, _Arg> mem_fun_ref(_Result(_Ty::*_Pm)(_Arg) const)
	{
		return (const_mem_fun1_ref_t<_Result, _Ty, _Arg>(_Pm));
	}

	template<class _Memptr>
	class _Mem_fn
		: public _Weak_types<_Memptr>::type
	{
	private:
		_Memptr _Pm;

	public:
		explicit _Mem_fn(_Memptr _Val) noexcept
			: _Pm(_Val)
		{
		}

		template<class... _Types>
		auto operator()(_Types&&... _Args) const
			noexcept(noexcept(::std::invoke(_Pm, ::std::forward<_Types>(_Args)...)))
			-> decltype(::std::invoke(_Pm, ::std::forward<_Types>(_Args)...))
		{
			return (::std::invoke(_Pm, ::std::forward<_Types>(_Args)...));
		}
	};

	template<class _Rx,
		class _Ty>
		inline _Mem_fn<_Rx _Ty::*> mem_fn(_Rx _Ty::* _Pm) noexcept
	{
		return (_Mem_fn<_Rx _Ty::*>(_Pm));
	}

	class bad_function_call
		: public exception
	{
	public:
		bad_function_call() noexcept
		{
		}

		virtual const char *  what() const noexcept override
		{
			return ("bad function call");
		}
	};

	[[noreturn]]  void __cdecl _Xbad_function_call();

	template<class _Fty>
	class function;

	template<class _Ty> inline
		bool _Test_callable(const _Ty& _Arg, true_type) noexcept
	{
		return (!!_Arg);
	}

	template<class _Ty> inline
		bool _Test_callable(const _Ty&, false_type) noexcept
	{
		return (true);
	}

	template<class _Ty> inline
		bool _Test_callable(const _Ty& _Arg) noexcept
	{
		bool_constant<is_member_pointer_v<_Ty> || (is_pointer_v<_Ty>
			&& is_function_v<remove_pointer_t<_Ty>>)> _Testable;
		return (_Test_callable(_Arg, _Testable));
	}

	template<class _Fty> inline
		bool _Test_callable(const function<_Fty>& _Arg) noexcept
	{
		return (!!_Arg);
	}

#pragma warning(push)
#pragma warning(disable: 4265)	

	template<class _Rx,
		class... _Types>
		class __declspec(novtable) _Func_base
	{
	public:
		virtual _Func_base * _Copy(void *) const = 0;
		virtual _Func_base * _Move(void *) = 0;
		virtual _Rx _Do_call(_Types&&...) = 0;
		virtual const type_info& _Target_type() const noexcept = 0;
		virtual void _Delete_this(bool) noexcept = 0;

		const void *_Target(const type_info& _Info) const noexcept
		{
			return (_Target_type() == _Info ? _Get() : nullptr);
		}

		_Func_base() = default;
		_Func_base(const _Func_base&) = delete;
		_Func_base& operator=(const _Func_base&) = delete;

	private:
		virtual const void *_Get() const noexcept = 0;
	};
#pragma warning(pop)

	constexpr size_t _Space_size = (_Small_object_num_ptrs - 1) * sizeof(void *);

	template<class _Impl>
	struct _Is_large
		: bool_constant < _Space_size < sizeof(_Impl)
		|| !_Impl::_Nothrow_move::value>
	{
	};

#pragma warning(push)
#pragma warning(disable: 4265)	

	template<class _Callable,
		class _Alloc,
		class _Rx,
		class... _Types>
		class _Func_impl final
		: public _Func_base<_Rx, _Types...>
	{
	public:
		typedef _Func_base<_Rx, _Types...> _Mybase;
		typedef _Rebind_alloc_t<_Alloc, _Func_impl> _Myalty;
		typedef allocator_traits<_Myalty> _Myalty_traits;
		typedef is_nothrow_move_constructible<_Callable> _Nothrow_move;

		template<class _Other1,
			class _Other2>
			_Func_impl(_Other1&& _Val, _Other2&& _Ax)
			: _Mypair(_One_then_variadic_args_t(),
				::std::forward<_Other2>(_Ax), ::std::forward<_Other1>(_Val))
		{
		}

	private:
		virtual _Mybase *_Copy(void *_Where) const override
		{
			return (_Clone(_Where, _Is_large<_Func_impl>()));
		}

		_Mybase *_Clone(void *, true_type) const
		{
			_Myalty _Al(_Myax());
			const auto _Ptr = _Myalty_traits::allocate(_Al, 1);

			try {
				_Myalty_traits::construct(_Al, _Unfancy(_Ptr), _Callee(), _Myax());
			}
			catch (...) {
				_Myalty_traits::deallocate(_Al, _Ptr, 1);
				throw;
			}

			return (_Unfancy(_Ptr));
		}

		_Mybase *_Clone(void *_Where, false_type) const
		{
			_Myalty _Al(_Myax());
			_Func_impl * _Ptr = static_cast<_Func_impl *>(_Where);
			_Myalty_traits::construct(_Al, _Ptr, _Callee(), _Myax());
			return (_Ptr);
		}

		virtual _Mybase *_Move(void *_Where) override
		{
			_Myalty _Al(_Myax());
			_Func_impl *_Ptr = static_cast<_Func_impl *>(_Where);
			_Myalty_traits::construct(_Al, _Ptr, ::std::move(_Callee()), ::std::move(_Myax()));
			return (_Ptr);
		}

		virtual _Rx _Do_call(_Types&&... _Args) override;

		virtual const type_info& _Target_type() const noexcept override
		{

			return (typeid(_Callable));

		}

		virtual const void *_Get() const noexcept override
		{
			return (::std::addressof(_Callee()));
		}

		virtual void _Delete_this(bool _Deallocate) noexcept override
		{
			_Myalty _Al(_Myax());
			_Myalty_traits::destroy(_Al, this);
			if (_Deallocate)
			{
				_Deallocate_plain(_Al, this);
			}
		}

		_Compressed_pair<_Alloc, _Callable> _Mypair;

		_Alloc& _Myax() noexcept
		{
			return (_Mypair._Get_first());
		}

		const _Alloc& _Myax() const noexcept
		{
			return (_Mypair._Get_first());
		}

		_Callable& _Callee() noexcept
		{
			return (_Mypair._Get_second());
		}

		const _Callable& _Callee() const noexcept
		{
			return (_Mypair._Get_second());
		}
	};

	template<class _Callable,
		class _Rx,
		class... _Types>
		class _Func_impl_no_alloc final
		: public _Func_base<_Rx, _Types...>
	{
	public:
		typedef _Func_base<_Rx, _Types...> _Mybase;
		typedef is_nothrow_move_constructible<_Callable> _Nothrow_move;

		template<class _Other,
			class = enable_if_t<!is_same_v<_Func_impl_no_alloc, decay_t<_Other>>>>
			explicit _Func_impl_no_alloc(_Other&& _Val)
			: _Callee(::std::forward<_Other>(_Val))
		{
		}

	private:
		virtual _Mybase *_Copy(void *_Where) const override
		{
			return (_Clone(_Where, _Is_large<_Func_impl_no_alloc>()));
		}

		_Mybase *_Clone(void *, true_type) const
		{
			return (_Global_new<_Func_impl_no_alloc>(_Callee));
		}

		_Mybase *_Clone(void *_Where, false_type) const
		{
			return (::new (_Where) _Func_impl_no_alloc(_Callee));
		}

		virtual _Mybase *_Move(void *_Where) override
		{
			return (::new (_Where) _Func_impl_no_alloc(::std::move(_Callee)));
		}

		virtual _Rx _Do_call(_Types&&... _Args) override;

		virtual const type_info& _Target_type() const noexcept override
		{

			return (typeid(_Callable));

		}

		virtual const void *_Get() const noexcept override
		{
			return (::std::addressof(_Callee));
		}

		virtual void _Delete_this(bool _Dealloc) noexcept override
		{
			this->~_Func_impl_no_alloc();
			if (_Dealloc)
			{
				_Deallocate<alignof(_Func_impl_no_alloc)>(this, sizeof(_Func_impl_no_alloc));
			}
		}

		_Callable _Callee;
	};
#pragma warning(pop)

	template<class _Ret,
		class... _Types>
		class _Func_class
		: public _Arg_types<_Types...>
	{
	public:
		typedef _Ret result_type;

		typedef _Func_base<_Ret, _Types...> _Ptrt;

		_Func_class() noexcept
		{
			_Set(nullptr);
		}

		_Ret operator()(_Types... _Args) const;

		~_Func_class() noexcept
		{
			_Tidy();
		}

	protected:
		template<class _Fx,
			class _Function>
			using _Enable_if_callable_t = enable_if_t<conjunction_v<
			negation<is_same<decay_t<_Fx>, _Function>>,
			_Is_invocable_r<_Ret, _Fx, _Types...>>>;

		bool _Empty() const noexcept
		{
			return (_Getimpl() == nullptr);
		}

		void _Reset_copy(const _Func_class& _Right)
		{
			if (!_Right._Empty())
			{
				_Set(_Right._Getimpl()->_Copy(_Getspace()));
			}
		}

		void _Reset_move(_Func_class&& _Right)
		{
			if (!_Right._Empty())
			{
				if (_Right._Local())
				{
					_Set(_Right._Getimpl()->_Move(_Getspace()));
					_Right._Tidy();
				}
				else
				{
					_Set(_Right._Getimpl());
					_Right._Set(nullptr);
				}
			}
		}

		template<class _Fx>
		void _Reset(_Fx&& _Val)
		{
			if (!_Test_callable(_Val))
			{
				return;
			}

			using _Impl = _Func_impl_no_alloc<decay_t<_Fx>, _Ret, _Types...>;
			_Reset_impl<_Impl>(::std::forward<_Fx>(_Val), _Is_large<_Impl>());
		}

		template<class _Myimpl,
			class _Fx>
			void _Reset_impl(_Fx&& _Val, true_type)
		{
			_Set(_Global_new<_Myimpl>(::std::forward<_Fx>(_Val)));
		}

		template<class _Myimpl,
			class _Fx>
			void _Reset_impl(_Fx&& _Val, false_type)
		{
			_Set(::new (_Getspace()) _Myimpl(::std::forward<_Fx>(_Val)));
		}

		template<class _Fx,
			class _Alloc>
			void _Reset_alloc(_Fx&& _Val, const _Alloc& _Ax)
		{
			if (!_Test_callable(_Val))
			{
				return;
			}

			using _Myimpl = _Func_impl<decay_t<_Fx>, _Alloc, _Ret, _Types...>;
			_Myimpl *_Ptr = nullptr;

			_Rebind_alloc_t<_Alloc, _Myimpl> _Al(_Ax);
			_Reset_impl_alloc(::std::forward<_Fx>(_Val), _Ax, _Ptr, _Al, _Is_large<_Myimpl>());
		}

		template<class _Fx,
			class _Alloc,
			class _Myimpl,
			class _Alimpl>
			void _Reset_impl_alloc(_Fx&& _Val, const _Alloc& _Ax,
				_Myimpl *, _Alimpl& _Al, true_type)
		{
			using _Alimpl_traits = allocator_traits<_Alimpl>;
			const auto _Ptr = _Alimpl_traits::allocate(_Al, 1);

			try {
				_Alimpl_traits::construct(_Al, _Unfancy(_Ptr), ::std::forward<_Fx>(_Val), _Ax);
			}
			catch (...) {
				_Alimpl_traits::deallocate(_Al, _Ptr, 1);
				throw;
			}

			_Set(_Unfancy(_Ptr));
		}

		template<class _Fx,
			class _Alloc,
			class _Myimpl,
			class _Alimpl>
			void _Reset_impl_alloc(_Fx&& _Val, const _Alloc& _Ax,
				_Myimpl *, _Alimpl& _Al, false_type)
		{
			_Myimpl *_Ptr = static_cast<_Myimpl *>(_Getspace());
			allocator_traits<_Alimpl>::construct(_Al, _Ptr, ::std::forward<_Fx>(_Val), _Ax);
			_Set(_Ptr);
		}

		void _Tidy() noexcept
		{
			if (!_Empty())
			{
				_Getimpl()->_Delete_this(!_Local());
				_Set(nullptr);
			}
		}

		void _Swap(_Func_class& _Right) noexcept
		{
			if (!_Local() && !_Right._Local())
			{
				_Ptrt *_Temp = _Getimpl();
				_Set(_Right._Getimpl());
				_Right._Set(_Temp);
			}
			else
			{
				_Func_class _Temp;
				_Temp._Reset_move(::std::move(*this));
				_Reset_move(::std::move(_Right));
				_Right._Reset_move(::std::move(_Temp));
			}
		}

		const type_info& _Target_type() const noexcept
		{
			return (_Getimpl() ? _Getimpl()->_Target_type() : typeid(void));
		}

		const void *_Target(const type_info& _Info) const noexcept
		{
			return (_Getimpl() ? _Getimpl()->_Target(_Info) : nullptr);
		}

	private:
		bool _Local() const noexcept
		{
			return (_Getimpl() == _Getspace());
		}

		union _Storage
		{
			max_align_t _Dummy1;
			char _Dummy2[_Space_size];
			_Ptrt *_Ptrs[_Small_object_num_ptrs];
		};

		_Storage _Mystorage;
		enum { _EEN_IMPL = _Small_object_num_ptrs - 1 };
		_Ptrt *_Getimpl() const noexcept
		{
			return (_Mystorage._Ptrs[_Small_object_num_ptrs - 1]);
		}

		void _Set(_Ptrt *_Ptr) noexcept
		{
			_Mystorage._Ptrs[_Small_object_num_ptrs - 1] = _Ptr;
		}

		void *_Getspace() noexcept
		{
			return (&_Mystorage);
		}

		const void *_Getspace() const noexcept
		{
			return (&_Mystorage);
		}
	};

	template<class _Tx>
	struct _Get_function_impl;

	template<class _Ret, class... _Types>
	struct _Get_function_impl<_Ret __cdecl (_Types...)>
	{
		typedef _Func_class<_Ret, _Types...> type;
	};
	template<class _Ret, class... _Types>
	struct _Get_function_impl<_Ret __fastcall (_Types...)>
	{
		typedef _Func_class<_Ret, _Types...> type;
	};
	template<class _Ret, class... _Types>
	struct _Get_function_impl<_Ret __stdcall (_Types...)>
	{
		typedef _Func_class<_Ret, _Types...> type;
	};
	template<class _Ret, class... _Types>
	struct _Get_function_impl<_Ret __vectorcall (_Types...)>
	{
		typedef _Func_class<_Ret, _Types...> type;
	};

	template<class _Fty>
	class function
		: public _Get_function_impl<_Fty>::type
	{
	private:
		typedef typename _Get_function_impl<_Fty>::type _Mybase;

	public:
		function() noexcept
		{
		}

		function(nullptr_t) noexcept
		{
		}

		function(const function& _Right)
		{
			this->_Reset_copy(_Right);
		}

		template<class _Fx,
			class = typename _Mybase::template _Enable_if_callable_t<_Fx&, function>>
			function(_Fx _Func)
		{
			this->_Reset(::std::move(_Func));
		}

		template<class _Alloc>
		function(allocator_arg_t, const _Alloc&) noexcept
		{
		}

		template<class _Alloc>
		function(allocator_arg_t, const _Alloc&, nullptr_t) noexcept
		{
		}

		template<class _Alloc>
		function(allocator_arg_t, const _Alloc& _Ax, const function& _Right)
		{
			this->_Reset_alloc(_Right, _Ax);
		}

		template<class _Fx,
			class _Alloc,
			class = typename _Mybase::template _Enable_if_callable_t<_Fx&, function>>
			function(allocator_arg_t, const _Alloc& _Ax, _Fx _Func)
		{
			this->_Reset_alloc(::std::move(_Func), _Ax);
		}

		function& operator=(const function& _Right)
		{
			function(_Right).swap(*this);
			return (*this);
		}

		function(function&& _Right)
		{
			this->_Reset_move(::std::move(_Right));
		}

		template<class _Alloc>
		function(allocator_arg_t, const _Alloc& _Al, function&& _Right)
		{
			this->_Reset_alloc(::std::move(_Right), _Al);
		}

		function& operator=(function&& _Right)
		{
			if (this != ::std::addressof(_Right))
			{
				this->_Tidy();
				this->_Reset_move(::std::move(_Right));
			}
			return (*this);
		}

		template<class _Fx,
			class = typename _Mybase::template _Enable_if_callable_t<decay_t<_Fx>&, function>>
			function & operator=(_Fx&& _Func)
		{
			function(::std::forward<_Fx>(_Func)).swap(*this);
			return (*this);
		}

		template<class _Fx,
			class _Alloc>
			void assign(_Fx&& _Func, const _Alloc& _Ax)
		{
			function(allocator_arg, _Ax, ::std::forward<_Fx>(_Func)).swap(*this);
		}

		function& operator=(nullptr_t) noexcept
		{
			this->_Tidy();
			return (*this);
		}

		template<class _Fx>
		function& operator=(reference_wrapper<_Fx> _Func) noexcept
		{
			this->_Tidy();
			this->_Reset(_Func);
			return (*this);
		}

		void swap(function& _Right) noexcept
		{
			this->_Swap(_Right);
		}

		explicit operator bool() const noexcept
		{
			return (!this->_Empty());
		}

		const type_info& target_type() const noexcept
		{
			return (this->_Target_type());
		}

		template<class _Fx>
		_Fx * target() noexcept
		{
			return (reinterpret_cast<_Fx *>(const_cast<void *>(this->_Target(typeid(_Fx)))));
		}

		template<class _Fx>
		const _Fx * target() const noexcept
		{
			return (reinterpret_cast<const _Fx *>(this->_Target(typeid(_Fx))));
		}

	};

	template<class _Fty> inline
		void swap(function<_Fty>& _Left, function<_Fty>& _Right) noexcept
	{
		_Left.swap(_Right);
	}

	template<class _Fty>
	inline bool operator==(const function<_Fty>& _Other, nullptr_t) noexcept
	{
		return (!_Other);
	}

	template<class _Fty>
	inline bool operator==(nullptr_t, const function<_Fty>& _Other) noexcept
	{
		return (!_Other);
	}

	template<class _Fty>
	inline bool operator!=(const function<_Fty>& _Other, nullptr_t) noexcept
	{
		return (static_cast<bool>(_Other));
	}

	template<class _Fty>
	inline bool operator!=(nullptr_t, const function<_Fty>& _Other) noexcept
	{
		return (static_cast<bool>(_Other));
	}

	template<int _Nx>
	struct _Ph
	{
	};

	template<class _Tx>
	struct is_placeholder
		: integral_constant<int, 0>
	{
	};

	template<int _Nx>
	struct is_placeholder<_Ph<_Nx>>
		: integral_constant<int, _Nx>
	{
	};

	template<class _Tx>
	struct is_placeholder<const _Tx>
		: is_placeholder<_Tx>::type
	{
	};

	template<class _Tx>
	struct is_placeholder<volatile _Tx>
		: is_placeholder<_Tx>::type
	{
	};

	template<class _Tx>
	struct is_placeholder<const volatile _Tx>
		: is_placeholder<_Tx>::type
	{
	};

	template<class _Ty>
	constexpr int is_placeholder_v = is_placeholder<_Ty>::value;

	template<class _Ret,
		class _Fx,
		class... _Types>
		class _Binder;

	template<class _Tx>
	struct is_bind_expression
		: false_type
	{
	};

	template<class _Ret,
		class _Fx,
		class... _Types>
		struct is_bind_expression<_Binder<_Ret, _Fx, _Types...>>
		: true_type
	{
	};

	template<class _Tx>
	struct is_bind_expression<const _Tx>
		: is_bind_expression<_Tx>::type
	{
	};

	template<class _Tx>
	struct is_bind_expression<volatile _Tx>
		: is_bind_expression<_Tx>::type
	{
	};

	template<class _Tx>
	struct is_bind_expression<const volatile _Tx>
		: is_bind_expression<_Tx>::type
	{
	};

	template<class _Ty>
	constexpr bool is_bind_expression_v = is_bind_expression<_Ty>::value;

	template<class _Cv_TiD,
		bool = _Is_specialization_v<remove_cv_t<_Cv_TiD>, reference_wrapper>,
		bool = is_bind_expression_v<_Cv_TiD>,
		int = is_placeholder_v<_Cv_TiD>>
		struct _Select_fixer;

	template<class _Cv_TiD>
	struct _Select_fixer<_Cv_TiD, true, false, 0>
	{
		template<class _Untuple>
		static auto _Fix(_Cv_TiD& _Tid, _Untuple&&)
			-> typename _Cv_TiD::type&
		{
			return (_Tid.get());
		}
	};

	template<class _Cv_TiD>
	struct _Select_fixer<_Cv_TiD, false, true, 0>
	{
#pragma warning(push)
#pragma warning(disable: 4100)	
		template<class _Untuple,
			size_t... _Jx>
			static auto _Apply(_Cv_TiD& _Tid, _Untuple&& _Ut,
				index_sequence<_Jx...>)
			-> decltype(_Tid(::std::get<_Jx>(::std::move(_Ut))...))
		{
			return (_Tid(::std::get<_Jx>(::std::move(_Ut))...));
		}
#pragma warning(pop)

		template<class _Untuple>
		static auto _Fix(_Cv_TiD& _Tid, _Untuple&& _Ut)
			-> decltype(_Apply(_Tid, ::std::move(_Ut),
				make_index_sequence<tuple_size_v<_Untuple>>()))
		{
			return (_Apply(_Tid, ::std::move(_Ut),
				make_index_sequence<tuple_size_v<_Untuple>>()));
		}
	};

	template<class _Cv_TiD>
	struct _Select_fixer<_Cv_TiD, false, false, 0>
	{
		template<class _Untuple>
		static _Cv_TiD& _Fix(_Cv_TiD& _Tid, _Untuple&&)
		{
			return (_Tid);
		}
	};

	template<class _Cv_TiD,
		int _Jx>
		struct _Select_fixer<_Cv_TiD, false, false, _Jx>
	{
		static_assert(_Jx > 0, "invalid is_placeholder value");

		template<class _Untuple>
		static auto _Fix(_Cv_TiD&, _Untuple&& _Ut)
			-> decltype(::std::get<_Jx - 1>(::std::move(_Ut)))
		{
			return (::std::get<_Jx - 1>(::std::move(_Ut)));
		}
	};

	template<class _Cv_TiD,
		class _Untuple> inline
		auto _Fix_arg(_Cv_TiD& _Tid, _Untuple&& _Ut)
		-> decltype(_Select_fixer<_Cv_TiD>::_Fix(_Tid, ::std::move(_Ut)))
	{
		return (_Select_fixer<_Cv_TiD>::_Fix(_Tid, ::std::move(_Ut)));
	}

#pragma warning(push)
#pragma warning(disable: 4100)	

	template<class _Ret,
		size_t... _Ix,
		class _Cv_FD,
		class _Cv_tuple_TiD,
		class _Untuple> inline
		auto _Call_binder(_Invoker_ret<_Ret>, index_sequence<_Ix...>,
			_Cv_FD& _Obj, _Cv_tuple_TiD& _Tpl, _Untuple&& _Ut)
		-> decltype(_Invoker_ret<_Ret>::_Call(_Obj, _Fix_arg(::std::get<_Ix>(_Tpl), ::std::move(_Ut))...))
	{
		return (_Invoker_ret<_Ret>::_Call(_Obj, _Fix_arg(::std::get<_Ix>(_Tpl), ::std::move(_Ut))...));
	}
#pragma warning(pop)

	template<class _Ret>
	struct _Forced_result_type
	{
		typedef _Ret result_type;
	};

	template<class _Ret,
		class _Fx>
		struct _Binder_result_type
	{
		typedef decay_t<_Fx> _Decayed;

		typedef typename _Weak_types<_Decayed>::type _All_weak_types;

		typedef conditional_t<is_same_v<_Ret, _Unforced>,
			_Weak_result_type<_All_weak_types>,
			_Forced_result_type<_Ret>> type;
	};

	template<class _Ret,
		class _Fx,
		class... _Types>
		class _Binder
		: public _Binder_result_type<_Ret, _Fx>::type
	{
	private:
		typedef index_sequence_for<_Types...> _Seq;
		typedef decay_t<_Fx> _First;
		typedef tuple<decay_t<_Types>...> _Second;

		_Compressed_pair<_First, _Second> _Mypair;

	public:
		explicit _Binder(_Fx&& _Func, _Types&&... _Args)
			: _Mypair(_One_then_variadic_args_t(),
				::std::forward<_Fx>(_Func), ::std::forward<_Types>(_Args)...)
		{
		}

		template<class... _Unbound> auto operator()(_Unbound&&... _Unbargs)  -> decltype(_Call_binder(_Invoker_ret<_Ret>(), _Seq(), _Mypair._Get_first(), _Mypair._Get_second(), ::std::forward_as_tuple(::std::forward<_Unbound>(_Unbargs)...))) { return (_Call_binder(_Invoker_ret<_Ret>(), _Seq(), _Mypair._Get_first(), _Mypair._Get_second(), ::std::forward_as_tuple(::std::forward<_Unbound>(_Unbargs)...))); } template<class... _Unbound> auto operator()(_Unbound&&... _Unbargs) const -> decltype(_Call_binder(_Invoker_ret<_Ret>(), _Seq(), _Mypair._Get_first(), _Mypair._Get_second(), ::std::forward_as_tuple(::std::forward<_Unbound>(_Unbargs)...))) { return (_Call_binder(_Invoker_ret<_Ret>(), _Seq(), _Mypair._Get_first(), _Mypair._Get_second(), ::std::forward_as_tuple(::std::forward<_Unbound>(_Unbargs)...))); }

	};

	template<class _Fx,
		class... _Types>
		inline _Binder<_Unforced, _Fx, _Types...> bind(_Fx&& _Func, _Types&&... _Args)
	{
		return (_Binder<_Unforced, _Fx, _Types...>(::std::forward<_Fx>(_Func), ::std::forward<_Types>(_Args)...));
	}

	template<class _Ret,
		class _Fx,
		class... _Types>
		_Binder<_Ret, _Fx, _Types...> bind(_Fx&& _Func, _Types&&... _Args)
	{
		return (_Binder<_Ret, _Fx, _Types...>(::std::forward<_Fx>(_Func), ::std::forward<_Types>(_Args)...));
	}

	namespace placeholders {
		constexpr _Ph<1> _1{};
		constexpr _Ph<2> _2{};
		constexpr _Ph<3> _3{};
		constexpr _Ph<4> _4{};
		constexpr _Ph<5> _5{};
		constexpr _Ph<6> _6{};
		constexpr _Ph<7> _7{};
		constexpr _Ph<8> _8{};
		constexpr _Ph<9> _9{};
		constexpr _Ph<10> _10{};
		constexpr _Ph<11> _11{};
		constexpr _Ph<12> _12{};
		constexpr _Ph<13> _13{};
		constexpr _Ph<14> _14{};
		constexpr _Ph<15> _15{};
		constexpr _Ph<16> _16{};
		constexpr _Ph<17> _17{};
		constexpr _Ph<18> _18{};
		constexpr _Ph<19> _19{};
		constexpr _Ph<20> _20{};
	}

	template<class _Fty,
		class _Alloc>
		struct uses_allocator<function<_Fty>, _Alloc>
		: true_type
	{
	};

	namespace[[deprecated("warning STL4002: " "The non-Standard std::tr1 namespace and TR1-only machinery are deprecated and will be REMOVED. You can " "define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING to acknowledge that you have received this warning.")]] tr1{
	using ::std::bad_function_call;
	using ::std::bind;
	using ::std::function;
	using ::std::is_bind_expression;
	using ::std::is_placeholder;
	using ::std::mem_fn;
	using ::std::swap;
	namespace placeholders {
		using namespace ::std::placeholders;
	}
	}

		template<class _Callable,
		class _Alloc,
		class _Rx,
		class... _Types> inline
		_Rx _Func_impl<_Callable, _Alloc, _Rx, _Types...>::_Do_call(_Types&&... _Args)

	{

		auto& _The_callee = _Callee();

		return (_Invoker_ret<_Rx>::_Call(_The_callee, ::std::forward<_Types>(_Args)...));

	}

	template<class _Callable,
		class _Rx,
		class... _Types> inline
		_Rx _Func_impl_no_alloc<_Callable, _Rx, _Types...>::_Do_call(_Types&&... _Args)

	{

		return (_Invoker_ret<_Rx>::_Call(_Callee, ::std::forward<_Types>(_Args)...));

	}

	template<class _Ret,
		class... _Types> inline
		_Ret _Func_class<_Ret, _Types...>::operator()(_Types... _Args) const

	{

		if (_Empty())

		{

			_Xbad_function_call();

		}

		const auto _Impl = _Getimpl();

		return (_Impl->_Do_call(::std::forward<_Types>(_Args)...));

	}

}

#pragma warning(pop)
#pragma pack(pop)

