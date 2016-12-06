// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 468                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
	const string IPV4 = "IPv4";
	const string IPV6 = "IPv6";
	const string NAY = "Neither";
	const string HEX = "0123456789ABCDEFabcdef";

	inline bool isHexDigit(char ch)
	{
		return binary_search(HEX.begin(), HEX.end(), ch);
	}

	bool isIPv4Block(const string &block)
	{
		int hoge = 0, sz = block.size();
		if (sz <= 0 || sz > 3) return false;
		for (int i = 0; i < sz; i++)
		{
			char ch = block[i];
			if (!isdigit(ch)) return false;
			if (i == 0 && ch == '0' && sz > 1) return false;
			hoge = 10 * hoge + ch - '0';
		}
		return hoge <= 255;
	}

	bool isIPv6Block(const string &block)
	{
		int sz = block.size();
		if (sz <= 0 || sz > 4) return false;
		for (int i = 0; i < sz; i++)
		{
			if (!isHexDigit(block[i])) return false;
		}
		return true;
	}

	vector<string> split(const string &str, char sep)
	{
		vector<string> ret;
		if (str.empty()) return ret;
		stringstream iss(str);
		for (string _; getline(iss, _, sep); ret.push_back(_));
		return ret;
	}

public:
	string validIPAddress(string IP)
	{
		if (IP.substr(0, 4).find('.') != string::npos)
		{
			vector<string> blocks = split(IP, '.');
			if (blocks.size() != 4) return NAY;
			int piyo = accumulate(blocks.begin(), blocks.end(), 0, 
				[](int a, string _) -> int { return a + _.size(); });
			if (piyo + 3 != IP.size()) return NAY;
			for (auto item : blocks)
			{
				if (!isIPv4Block(item)) return NAY;
			}

			return IPV4;
		}
		else if (IP.substr(0, 5).find(':') != string::npos)
		{
			vector<string> blocks = split(IP, ':');
			if (blocks.size() != 8) return NAY;
			int piyo = accumulate(blocks.begin(), blocks.end(), 0, 
				[](int a, string _) -> int { return a + _.size(); });
			if (piyo + 7 != IP.size()) return NAY;
			for (auto item : blocks)
			{
				if (!isIPv6Block(item)) return NAY;
			}
			return IPV6;
		}
		else return NAY;
	}
};

void test()
{
	Solution _;
	cout << _.validIPAddress(string("192.168.0.1"));
	string __;
	while (cin >> __)
		cout << _.validIPAddress(__);

}

int main()
{
	test();
	return 0;
}
