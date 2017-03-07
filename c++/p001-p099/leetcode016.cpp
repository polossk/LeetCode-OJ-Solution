// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 015                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		sort(nums.begin(), nums.end());
		int ret = nums[0] + nums[1] + nums[2];
		for (int i = 0, sz = nums.size(); i + 2 < sz; i++)
		{
			int j = i + 1, k = sz - 1;
			while (j < k)
			{
				int hoge = nums[i] + nums[j] + nums[k];
				if (abs(hoge - target) < abs(ret - target))
					ret = hoge;
				hoge < target ? j++ : k--;
			}
		}
		return ret;
	}
};

void test()
{

}

int main()
{

	return 0;
}
