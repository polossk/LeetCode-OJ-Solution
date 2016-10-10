// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 166                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
	typedef long long int64;
public:
	string fractionToDecimal(int64 n, int64 d)
	{
		if (n == 0) return "0";
		string ret = "";
		if (n < 0 ^ d < 0) ret += '-';
		n = abs(n); d = abs(d);
		ret += to_string(n / d);
		if (n % d == 0) return ret;
		ret += '.';
		unordered_map<int64, int> m;
		for (int64 r = n % d; r; r %= d)
		{
			if (m.count(r) > 0)
			{
				ret.insert(m[r], 1, '(');
				ret += ')';
				return ret;
			}
			m[r] = ret.size();
			r *= 10;
			ret += to_string(r / d);
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
