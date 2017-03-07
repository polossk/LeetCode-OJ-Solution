// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 315                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
	void merge_sort(vector<int>::iterator _first, vector<int>::iterator _last,
		vector<int>::iterator cnt, vector<int>::iterator idx,
		vector<int>::iterator d_first
		)
	{
		int first = _first - d_first, last = _last - d_first;
		int length = last - first;

		if (length <= 1) return;
		auto mid = first + length / 2;
		auto _mid = _first + length / 2;
		merge_sort(_first, _mid, cnt, idx, d_first);
		merge_sort(_mid, _last, cnt, idx, d_first);
		vector<int> tmp; tmp.reserve(length);
		auto i = first, j = mid;
		int hoge = 0;
		while (i < mid || j < last)
		{
			if (j == last || (i < mid && 
				*(d_first + *(idx + i)) <= *(d_first + *(idx + j)) ) )
			{
				tmp.push_back( *(idx + i) );
				*(cnt + *(idx + i++)) += hoge;
			}
			else
			{
				tmp.push_back( *(idx + j++) ); hoge++;
			}
		}
		std::move(tmp.begin(), tmp.end(), idx + first);
	}

public:
	vector<int> countSmaller(vector<int>& nums)
	{
		int n = nums.size();
		vector<int> cnt(n, 0), idx(n, 0);
		std::iota(idx.begin(), idx.end(), 0);
		merge_sort(nums.begin(), nums.end(), cnt.begin(), idx.begin(), nums.begin());
		return cnt;
	}
};

void test()
{

}

int main()
{
	test();
	return 0;
}
