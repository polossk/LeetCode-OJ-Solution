// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 149                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution
{
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
public:
	int maxPoints(vector<Point>& points)
	{
		int ret = 0;
		for (auto p1 : points)
		{
			unordered_map<double, int> mp;
			int hoge = 0, piyo = 0;
			for (auto p2 : points)
			{
				if (p1.x == p2.x)
				{
					(p1.y == p2.y) ? hoge++ : piyo++;
				}
				else
				{
					double k = double(p2.y - p1.y) / (p2.x - p1.x);
					mp[k]++;
				}
			}
			for (auto elem : mp) updateMax(ret, elem.second + hoge);
			updateMax(ret, hoge + piyo);
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
