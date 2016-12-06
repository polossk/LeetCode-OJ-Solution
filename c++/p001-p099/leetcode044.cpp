// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 044                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
	int dfs(const string &s, const string &p, int sidx, int pidx)
	{
		if (sidx == s.size() && pidx == p.size()) return 1;
		if (sidx == s.size() && p[pidx] != '*') return 0;
		if (pidx == p.size()) return -1;
		if (p[pidx] == '*')
		{
			if (pidx + 1 < p.size() && p[pidx + 1] == '*')
				return dfs(s, p, sidx, pidx + 1);
			for (int i = 0; sidx + i <= s.size(); i++)
			{
				int ret = dfs(s, p, sidx + i, pidx + 1);
				if (ret > -1) return ret;
			}
		}
		if (p[pidx] == '?' or s[sidx] == p[pidx])
			return dfs(s, p, sidx + 1, pidx + 1);
		return -1;
	}
public:
	bool isMatch(string s, string p)
	{
		return dfs(s, p, 0, 0) == 1;
	}
};

void test()
{

}

int main()
{

	return 0;
}
