// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1427                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    string stringShift(string s, vector<vector<int>>& shift)
    {
        int sz = s.size();
        int movement = accumulate(shift.begin(), shift.end(), 0,
            [](int _1, const vector<int> &_2)->int
            {
                return _1 + (_2[0] == 1 ? _2[1] : -_2[1]);
            });
        movement = (movement % sz + sz) % sz;
        if (movement == 0) return s;
        movement = sz - movement;
        return s.substr(movement) + s.substr(0, movement);
    }
};


void test() {}

int main() { test(); return 0; }
