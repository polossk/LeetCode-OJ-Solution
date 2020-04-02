// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 289                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
    static const int MAXD = 8;
    const int dx[MAXD] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[MAXD] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int row_, col_;

public:
    void gameOfLife(vector<vector<int>>& board)
    {
        this->row_ = board.size();
        if (this->row_ == 0) return;
        this->col_ = board[0].size();
        if (this->col_ == 0) return;
        for (int i = 0; i < row_; i++)
            for (int j = 0; j < col_; j++)
        {
            int cnt = 0, &ref = board[i][j];
            for (int k = 0; k < MAXD; k++)
            {
                int ii = i + dx[k], jj = j + dy[k];
                if (ii < 0 || ii >= row_ || jj < 0 || jj >= col_) continue;
                cnt += (board[ii][jj] & 1);
            }
            if (ref == 1 && (cnt == 2 || cnt == 3))
                ref = 3; // 0b11
            if (ref == 0 && cnt == 3)
                ref = 2; // 0b10
            // otherwise 0b00 or 0b01
        }
        for (int i = 0; i < row_; i++)
            for (int j = 0; j < col_; j++)
                board[i][j] >>= 1;
    }
};

void test() {}

int main() { test(); return 0; }
