// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   CCI 0107                                                     *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i)
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n - i - 1][j]);
        // 主对角线翻转
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};

void test() {}

int main() { test(); return 0; }
