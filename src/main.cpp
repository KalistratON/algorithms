#include  <vector>
#include  <list>
#include  <algorithm>


#include "sort_algorithm.h"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	const unsigned int size = 15;

	std::vector<int>	vec(size);
	std::list<int>		list;
	for (size_t i = 0; i < size; i++)
	{
		vec[i] = rand() % 10;
		list.push_back(rand() % 10);
	}

	auto for_bubble_vec = vec;
	auto for_merge_vec	= vec;
	auto for_quick_vec	= vec;

	auto for_bubble_list= list;
	auto for_merge_list	= list;
	auto for_quick_list	= list;

	sort_alg::bubble_sort(for_bubble_vec.begin(), for_bubble_vec.end(), [](int x, int y) { return x < y; });
	sort_alg::merge_sort(for_merge_vec.begin(), for_merge_vec.end(), [](int x, int y) { return x < y; });
	sort_alg::quick_sort(for_quick_vec.begin(), for_quick_vec.end(), [](int x, int y) { return x < y; });

	sort_alg::bubble_sort(for_bubble_list.begin(), for_bubble_list.end(), [](int x, int y) { return x < y; });
	sort_alg::merge_sort(for_merge_list.begin(), for_merge_list.end(), [](int x, int y) { return x < y; });
	sort_alg::quick_sort(for_quick_list.begin(), for_quick_list.end(), [](int x, int y) { return x < y; });

	std::cout << "bubble/merge/quick : vector" << std::endl;
	for (const auto& it : for_bubble_vec)
		std::cout << it << ' ';
	std::cout << std::endl;
	for (const auto& it : for_merge_vec)
		std::cout << it << ' ';
	std::cout << std::endl;
	for (const auto& it : for_quick_vec)
		std::cout << it << ' ';
	std::cout << std::endl;

	std::cout << "bubble/merge/quick : list" << std::endl;
	for (const auto& it : for_bubble_list)
		std::cout << it << ' ';
	std::cout << std::endl;
	for (const auto& it : for_merge_list)
		std::cout << it << ' ';
	std::cout << std::endl;
	for (const auto& it : for_quick_list)
		std::cout << it << ' ';
	std::cout << std::endl;
	return 0;
}