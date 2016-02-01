// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 004 Median of Two Sorted Arrays                     *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int l1 = nums1.size(), l2 = nums2.size();
		vector<int> &sh = l1 > l2 ? nums2 : nums1;
		vector<int> &lg = l1 > l2 ? nums1 : nums2;
		if (l1 < l2) swap(l1, l2); // l1 = lg.size(), l2 = sh.size()
		if (l2 == 0) return (lg[(l1 - 1) / 2] + lg[l1 / 2]) / 2.0;

		int l = 0, r = l2 * 2;
		while (l <= r)
		{
			int mid2 = (l + r) >> 1;
			int mid1 = l1 + l2 - mid2;
			int sh_lo = (mid2 == 0) ? INT_MIN : sh[(mid2 - 1) / 2];
			int lg_lo = (mid1 == 0) ? INT_MIN : lg[(mid1 - 1) / 2];
			int sh_hi = (mid2 == l2 * 2) ? INT_MAX : sh[mid2 / 2];
			int lg_hi = (mid1 == l1 * 2) ? INT_MAX : lg[mid1 / 2];
			if (lg_lo > sh_hi)
				l = mid2 + 1;
			else if (sh_lo > lg_hi)
				r = mid2 - 1;
			else return (max(sh_lo, lg_lo) + min(sh_hi, lg_hi)) / 2.0;
		}
		return -1;
	}
};

void test()
{

}

int main()
{

	return 0;
}
