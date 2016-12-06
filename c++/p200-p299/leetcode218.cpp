// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 218                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
	typedef pair<int, int> pnt;
	typedef vector<vector<int> > bdg;
	typedef vector<pnt> poly;
	poly getSkyline(bdg& buildings) {
		poly h, res;
		multiset<int> m; m.insert(0);
		int hoge = 0, piyo = 0;
		for (auto& a : buildings)
		{
			h.push_back(make_pair(a[0], -a[2]));
			h.push_back(make_pair(a[1], a[2]));
		}
		sort(h.begin(), h.end(), [](const pnt& a, const pnt& b) -> bool
		{
			return a.first == b.first ? a.second < b.second : a.first < b.first;
		});
		for (auto& a : h)
		{
			if (a.second < 0) m.insert(-a.second);
			else m.erase(m.find(a.second));
			piyo = *(m.rbegin());
			if (hoge != piyo)
			{
				res.push_back(make_pair(a.first, piyo));
				hoge = piyo;
			}
		}
		return res;
	}
};

void test()
{

}

int main()
{

	return 0;
}
