// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 093 Restore IP Addresses                            *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
	vector<string> restoreIpAddresses(string s)
	{
		vector<string> res;
		if (s.size() < 4 || s.size() > 12)
			return res;
		dfs(res, "", s, 0);
		return res;
	}

	void dfs(vector<string>& res, string prev, string next, int n)
	{
		if (n == 3 && next.size() <= 3 && judge(next))
		{
			res.push_back(prev + next);
			return;
		}
		for (int i = 1, sz = next.size(); i < 4 && i < sz; i++)
		{
			string nstr = next.substr(0, i);
			if (judge(nstr))
				dfs(res, prev + nstr + ".", next.substr(i), n + 1);
			else continue;
		}
	}

	inline int toNum(string s)
	{
		stringstream buf; buf << s;
		int num; buf >> num;
		return num;
	}

	bool judge(string s)
	{
		if (s[0] == '0') return s == "0";
		// int v = atoi(s.c_str()); // 9ms
		auto str2num = [=](string s)->int{
			stringstream buf; buf << s;
			int ret; buf >> ret;
			return ret;
		};
		int v = str2num(s); // 20 ms
		return v > 0 && v <= 255;
	}

	void _dbg(vector<string> res)
	{
		for (int i = 0, sz = res.size(); i < sz; i++)
			cout << "res[" << i << "] = [" << res[i] << "];" << endl;
	}
};

void test()
{
	vector<string> input;
	input.push_back("123123123123");
	input.push_back("25525511135");
	for (int i = 0, sz = input.size(); i < sz; i++)
	{
		cout << "Case #" << i << ":" << endl;
		Solution s;
		vector<string> ans = s.restoreIpAddresses(input[i]);
		s._dbg(ans);
		cout << endl;
	}
	cout << "end." << endl;
}

int main()
{
	test();
    return 0;
}
