
using namespace System;
using namespace System::Collections::Generic;

typedef KeyValuePair<String^, int> KVP;

ref class MyComparer : public System::Collections::Generic::IComparer<KVP>
{
public:
	enum class SORTBY {
		KEY,
		VALUE,
	};
private:
	SORTBY sortby_;
public:
	MyComparer(SORTBY sortby) : sortby_(sortby){}
	virtual int Compare(KVP kvp1, KVP kvp2)
	{
		switch (sortby_)
		{
		case SORTBY::KEY:
			return kvp1.Key->CompareTo(kvp2.Key);
		case SORTBY::VALUE:
			return kvp1.Value.CompareTo(kvp2.Value);
		}
		return 0;
	}
};

int main()
{
	List<KVP> silist;
	silist.Add(KVP("x", 1));
	silist.Add(KVP("y", 2));
	silist.Add(KVP("z", 300));
	silist.Add(KVP("a", 400));
	silist.Add(KVP("b", 500));
	silist.Add(KVP("c", 50));

	// Exception!
	// silist.Sort();

	// Sort by key
	MyComparer compByKey(MyComparer::SORTBY::KEY);
	silist.Sort(% compByKey);
	for each (KVP kvp in silist)
		Console::WriteLine(kvp.Key + "=" + kvp.Value);

	Console::WriteLine();

	// Sort by value
	MyComparer compByValue(MyComparer::SORTBY::VALUE);
	silist.Sort(% compByValue);
	for each (KVP kvp in silist)
		Console::WriteLine(kvp.Key + "=" + kvp.Value);

	return 0;
}