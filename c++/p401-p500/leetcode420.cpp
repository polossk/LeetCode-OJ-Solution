// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 420                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int strongPasswordChecker(string s)
    {
        int n = s.size();
        bool upper = false, lower = false, digit = false;
        int _add = max(0, 6 - n), _del = max(0, n - 20);
        int add = 0, del = 0, rep = 0;

        vector<vector<int> > hoge(3);
        for (int i = 0, j = 0; i <= n; i++)
        {
            if (i == n || s[i] != s[j])
            {
                int gap = i - j;
                if (gap >= 3) hoge[gap % 3].push_back(gap);
                j = i;
            }
            if (i == n) break;
            digit |= isdigit(s[i]);
            upper |= isupper(s[i]);
            lower |= islower(s[i]);
        }
        for (int i = 0; i < 3; i++)
        {
            auto piyo = hoge[i];
            for (int j = 0; j < piyo.size(); j++)
            {
                if (i < 2)
                {
                    if (_add > add) { add++; piyo[j] -= i + 1; }
                    if (_del > del) { del += i + 1; piyo[j] -= i + 1; }
                }
                rep += piyo[j] / 3;
            }
        }
        rep = _del > del ? max(0, rep - (_del - del) / 3) : rep + del - _del;
        return _del + max(_add + rep, (!upper) + (!lower) + (!digit));
    }
};

void test() {}

int main() { test(); return 0; }
