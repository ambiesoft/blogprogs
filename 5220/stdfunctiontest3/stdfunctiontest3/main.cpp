#include <iostream>

int __cdecl cdeclFunc(int i)
{
	return i + 1;
}
int __fastcall fastcallFunc(int i)
{
	return i + 1;
}

//typedef int (__cdecl *CDECLFUNC)(int);
//typedef int (__fastcall *FASTCALLFUNC)(int);

template<typename F>
struct MyFunctionBase;
//{
//	typedef void type;
//};

template<>
struct MyFunctionBase<int __cdecl (int)>
{
	typedef int(__cdecl type)(int);
	type *f_;
	void SetFunc(type& f)
	{
		f_ = f;
	}
};
template<>
struct MyFunctionBase<int __fastcall (int)>
{
	typedef int(__fastcall type)(int);
	type *f_;
	void SetFunc(type& f)
	{
		f_ = f;
	}

};


template<typename F>
class MyFunction : public MyFunctionBase<F>
{
public:
	//typedef typename MyFunctionBase<F>::type FuncType;
	//FuncType& f_;
	void* f_;
	template<typename F2>
	MyFunction(F2& func) 
	{
		f_ = (void*)new MyFunctionBase<F2>();
	}

	int operator()(int i)
	{
		return f_(i);
	}
};

int main()
{
	MyFunction<int(int)> mycdeclFunction(cdeclFunc);
	std::cout << mycdeclFunction(1) << std::endl;

	MyFunction<int(int)> myFastcallFunction(fastcallFunc);
	std::cout << myFastcallFunction(1) << std::endl;
}