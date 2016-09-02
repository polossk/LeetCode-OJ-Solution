// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author	:   Shen                                                         *
*   @name   :   Leetcode 074                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int n = matrix.size();
		int m = matrix[0].size();
		int l = 0, r = m * n - 1;
		while (l != r)
		{
			int mid = (l + r - 1) >> 1;
			if (matrix[mid / m][mid % m] < target)
				l = mid + 1;
			else r = mid;
		}
		return target == matrix[r / m][r % m];
	}
};

void test()
{

}

int main()
{

	return 0;
}
