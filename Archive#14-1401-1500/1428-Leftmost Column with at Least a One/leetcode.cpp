// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode XXXX                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */
class Solution
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        vector<int> size = binaryMatrix.dimensions();
        int n = size[0], m = size[1];
        int x = 0, y = m - 1;
        int y_move = 0, x_move = 0;
        while (x < n && y >= 0)
        {
            if (binaryMatrix.get(x, y))
                { y--; x_move = 0; y_move++; }
            else
                { x++; y_move = 0; x_move++; }
        }
        if (y_move) return 0;
        else if (x - x_move < n && y + 1 < m)
            return binaryMatrix.get(x - x_move, y + 1) ? y + 1 : -1;
        else return -1;
    }
};

void test() {}

int main() { test(); return 0; }
