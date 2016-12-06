// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 273                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
	const string _1[20] = {
		"Zero", "One", "Two", "Three", "Four", "Five",
		"Six", "Seven", "Eight", "Nine", "Ten", 
		"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
		"Sixteen", "Seventeen", "Eighteen", "Nineteen"
	};

	const string _2[10] = {
		"Zero", "Ten", "Twenty", "Thirty", "Forty",
		"Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
	};

	const int _3[3] = { 1000000000, 1000000, 1000 };

	string int2str(int n)
	{
		if (n >= _3[0])
			return int2str(n / _3[0]) + " Billion" + int2str(n % _3[0]);
		else if (n >= _3[1])
			return int2str(n / _3[1]) + " Million" + int2str(n % _3[1]);
		else if (n >= _3[2])
			return int2str(n / _3[2]) + " Thousand" + int2str(n % _3[2]);
		else if (n >= 100)
			return int2str(n / 100) + " Hundred" + int2str(n % 100);
		else if (n >= 20)
			return " " + _2[n / 10] + int2str(n % 10);
		else if (n >= 1)
			return " " + _1[n];
		else return "";
	}

public:
	string numberToWords(int num)
	{
		if (num == 0) return _1[0];
		else return int2str(num).substr(1);
	}
};

void test()
{

}

int main()
{

	return 0;
}
