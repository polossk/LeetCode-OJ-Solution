// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode XXX                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
	string reverseStr(string s, int k)
	{
		for (int it = 0, _ = s.size() / (2 * k); it <= _; it++)
		{
			int i = it * 2 * k; int j = i + k - 1;
			j = j > s.size() - 1 ? s.size() - 1 : j;
			while (i < j) std::swap(s[i++], s[j--]);
		}
		return s;
	}
};

void test()
{

}

int main()
{
	Solution _;
	cout << _.reverseStr("123456789", 2) << endl;
	return 0;
}
