#include <iostream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

#pragma warning(disable:4566)
using namespace std;

bool less_a(int a, int b)
{
	return (bool)((a < b) ? 1 : 0);
};

class less_b : public binary_function<int, int, bool>
{
public:
	result_type operator() (first_argument_type a, second_argument_type b)
	{
		return (result_type)((a < b) ? 1 : 0);
	}
};

void main3()
{
	vector<int> v1;
	vector<int>::iterator it;
	// push_heap と pop_heap によるソート
	printf("**初期状態 v1**\n");
	v1.push_back(5);
	v1.push_back(10);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(7);
	for (it = v1.begin(); it != v1.end(); it++)
		printf("  %d", *it);
	printf("\n");

	printf("push_heap\n");
	for (int i1 = 2; i1 < 5; i1++) {
		push_heap(v1.begin(), v1.begin() + i1);
		for (it = v1.begin(); it <= v1.begin() + i1; it++)
			printf("  %d", *it);
		printf("\n");
	}

	printf("pop_heap\n");
	for (int i1 = 5; i1 >= 2; i1--) {
		pop_heap(v1.begin(), v1.begin() + i1);
		for (it = v1.begin(); it < v1.begin() + i1; it++)
			printf("  %d", *it);
		printf("\n");
	}

	printf("push_heap と pop_heap によるソート結果\n");
	for (it = v1.begin(); it != v1.end(); it++)
		printf("  %d", *it);
	printf("\n");
	// make_heap と sort_heap によるソート
	printf("**初期状態 v1**\n");
	random_shuffle(v1.begin(), v1.end());
	for (it = v1.begin(); it != v1.end(); it++)
		printf("  %d", *it);
	printf("\n");

	printf("make_heap\n");
	make_heap(v1.begin(), v1.end());
	// 以下の方法でも可能
	//	make_heap(v1.begin(), v1.end(), less_a);
	//	make_heap(v1.begin(), v1.end(), less_b());
	//	make_heap(v1.begin(), v1.end(), less<int>());
	for (it = v1.begin(); it != v1.end(); it++)
		printf("  %d", *it);
	printf("\n");

	printf("make_heap と sort_heap によるソート結果\n");
	sort_heap(v1.begin(), v1.end());
	for (it = v1.begin(); it != v1.end(); it++)
		printf("  %d", *it);
	printf("\n");
}

void main2()
{
	std::cout << "Max heap:\n";

	std::vector<int> v{ 3, 2, 4, 1, 5, 9 };

	std::cout << "initially, v: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';

	std::make_heap(v.begin(), v.end());

	std::cout << "after make_heap, v: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';

	std::pop_heap(v.begin(), v.end());

	std::cout << "after pop_heap, v: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';

	auto top = v.back();
	v.pop_back();
	std::cout << "former top element: " << top << '\n';

	std::cout << "after removing the former top element, v: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n' << '\n';

	std::cout << "Min heap:\n";

	std::vector<int> v1{ 3, 2, 4, 1, 5, 9 };

	std::cout << "initially, v1: ";
	for (auto i : v1) std::cout << i << ' ';
	std::cout << '\n';

	std::make_heap(v1.begin(), v1.end(), std::greater<>{});

	std::cout << "after make_heap, v1: ";
	for (auto i : v1) std::cout << i << ' ';
	std::cout << '\n';

	std::pop_heap(v1.begin(), v1.end(), std::greater<>{});

	std::cout << "after pop_heap, v1: ";
	for (auto i : v1) std::cout << i << ' ';
	std::cout << '\n';

	auto top1 = v1.back();
	v1.pop_back();
	std::cout << "former top element: " << top1 << '\n';

	std::cout << "after removing the former top element, v1: ";
	for (auto i : v1) std::cout << i << ' ';
	std::cout << '\n';
}

void main1()
{
	std::vector<int> v = { 3, 1, 4 };

	std::make_heap(v.begin(), v.end());

	// 要素を追加してヒープ化
	v.push_back(2);
	std::push_heap(v.begin(), v.end());

	std::sort_heap(v.begin(), v.end());

	std::for_each(v.begin(), v.end(), [](int x) {
		std::cout << x << std::endl;
	});
}

int main()
{
	main1();
	main2();
	main3();
}