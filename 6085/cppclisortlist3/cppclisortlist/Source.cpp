
using namespace System;
using namespace System::Collections::Generic;


ref class MyClass 
{
private:
	String^ s1_;
public:
	MyClass(String^ s1) : s1_(s1) {}
public:
	static int Compare(MyClass^ m1, MyClass^ m2) {
		return String::Compare(m1->s1_, m2->s1_);
	}

	virtual String^ ToString() override {
		return s1_;
	}
};
ref class MyClassComparer : public System::Collections::Generic::IComparer<MyClass^>
{
public:
	virtual int Compare(MyClass^ mc1, MyClass^ mc2)
	{
		return MyClass::Compare(mc1, mc2);
	}
};

int main()
{
	List<MyClass^> mclist;
	mclist.Add(gcnew MyClass("fjwoeijf"));
	mclist.Add(gcnew MyClass("bzz32r"));
	mclist.Add(gcnew MyClass("+fwe3vv2r"));
	mclist.Add(gcnew MyClass("a32432faf"));
	mclist.Add(gcnew MyClass("3ff"));
	mclist.Add(gcnew MyClass("-fw654f"));

	// Exception!
	// mclist.Sort();

	mclist.Sort(gcnew MyClassComparer());

	// Sort by key
	for each (MyClass ^ mc in mclist)
		Console::WriteLine(mc->ToString());

	return 0;
}