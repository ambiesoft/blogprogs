#include <iostream>
#include <memory>

using namespace std;

int main()
{
	{
		unique_ptr<char> p;
		if (p)
			cout << "true" << endl;
		if (!p)
			cout << "false" << endl;

		if(p.get())
			cout << "true" << endl;

		unique_ptr<char> q(new char);
		if (q)
			cout << "true" << endl;
		if (!q)
			cout << "false" << endl;

		if (q.get())
			cout << "true" << endl;

		// q = p; // error
		// unique_ptr<char> r(q); // error
		// unique_ptr<char> r(q.get()); // not an error, but never do this
		auto r = make_unique<char>('a');
	}
    unique_ptr<char> p(new char);
    p.reset(new char);
    return 0;
}
