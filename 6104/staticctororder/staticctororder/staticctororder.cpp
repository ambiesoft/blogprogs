
using namespace System;

ref class A {
	static A() {
		Console::WriteLine("static A()");
	}
};
ref class B : public A {
	static B() {
		Console::WriteLine("static B()");
	}
};
//int main()
//{
//	A a;
//	B b;
//}
int main()
{
	B b;
	A a;
}
//interface class I1
//{
//	static I1() {
//		Console::WriteLine("static I1()");
//	}
//};
//interface class I2
//{
//	static I2() {
//		Console::WriteLine("static I2()");
//	}
//};
//ref class C : public I1, public I2
//{
//	static C() {
//		Console::WriteLine("static C()");
//	}
//};
//
//int main()
//{
//	C c;
//}

