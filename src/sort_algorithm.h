#pragma once
#include <iostream>
#include <vector>

namespace sort_alg {

	template <typename _Iter, typename _Comp>
	void bubble_sort(_Iter beg, _Iter end, _Comp comp)
	{
		for (auto it1 = beg; it1 != end; ++it1)
		{
			for (auto it2 = it1; it2 != end; ++it2)
			{
				if (!comp(*it1, *it2))
				{
					auto temp = *it1;
					*it1 = *it2;
					*it2 = temp;
				}
			}
		}
	}

	template <typename _Iter, typename _Comp>
	void merge_sort(_Iter beg, _Iter end, _Comp comp)
	{
		auto size = std::distance(beg, end) / 2;
		if (size <= 0)
			return;

		auto mid = beg;
	
		std::advance(mid, size);

		merge_sort(beg, mid, comp);
		merge_sort(mid, end, comp);
		
		auto _beg = beg;
		auto _end = end;

		std::vector<decltype(_beg)::value_type> X(_beg, mid);
		std::vector<decltype(_beg)::value_type> Y(mid, _end);

		int i = 0;
		int j = 0;

		while (i < X.size() && j < Y.size())
		{
			if (comp(X[i], Y[j]))
			{
				*_beg = X[i];
				i++;
			}
			else
			{
				*_beg = Y[j];
				j++;
			}
			++_beg;
		}

		while (i < X.size())
		{

			*_beg = X[i];
			i++;
			++_beg;
		}
		while (j < Y.size())
		{

			*_beg = Y[j];
			j++;
			++_beg;
		}
	}

	template <typename _Iter, typename _Comp>
	void quick_sort(_Iter beg, _Iter end, _Comp comp)
	{
		auto size = std::distance(beg, end);
		if (size <= 0)
			return;

		auto _beg_for_pivot = beg;
		std::advance(_beg_for_pivot, size - 1);
		auto pivot = *_beg_for_pivot;
		auto pInd = beg;

		auto _beg = beg;
		for (auto i = _beg; i != end; ++i)
		{
			if (comp(*i, pivot))
			{
				auto temp = *pInd;
				*pInd = *i;
				*i = temp;
				++pInd;
			}
		}

		*_beg_for_pivot = *pInd;
		*pInd = pivot;

		auto pInd_l = pInd;
		auto pInd_r = pInd;

		if (pInd_l != beg)
			quick_sort(beg, --pInd_l, comp);
		quick_sort(++pInd_r, end, comp);
	}

	// selection_sort
	// insert_sort
	// head_sort

	// counting_sort
	// radix_sort
} 