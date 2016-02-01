// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 005 Longest Palindromic Substring                   *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
	static const int MAXL = 1024;
	char Ma[MAXL * 2];
	int Mp[MAXL * 2];
	string longestPalindrome(string s)
	{
		int sz = s.size();
		int l = 0;
		/// manacher algorithm O(n)
		Ma[l++] = '$'; Ma[l++] = '#';
		for (int i = 0; i < sz; i++)
		{
			Ma[l++] = s[i];
			Ma[l++] = '#';
		}
		Ma[l] = 0;
		int mx = 0, id = 0;
		for (int i = 0; i < l; i++)
		{
			Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;
			while (Ma[i + Mp[i]] == Ma[i - Mp[i]]) Mp[i]++;
			if (i + Mp[i] > mx)
			{
				mx = i + Mp[i];
				id = i;
			}
		}
		/// get palindrome
		int pos = std::max_element(Mp, Mp + l) - Mp;
		int val = Mp[pos] - 1;
		string ret = "";
		for (int start = pos - val, end = pos + val; start <= end; start++)
			if (Ma[start] == '#' || Ma[start] == '$')
				continue;
			else ret += Ma[start];
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
