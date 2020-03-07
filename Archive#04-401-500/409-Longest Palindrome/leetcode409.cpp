// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 409                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution {
public:
    int longestPalindrome(string s)
    {
        vector<int> alphabet(26 * 2, 0);
        for (char ch : s)
        {
            int offset = isupper(ch) ? 0 : 26;
            alphabet[ch - (offset ? 'a' : 'A') + offset]++;
        }
        int ret = s.size();
        int odd = std::accumulate(alphabet.begin(), alphabet.end(), 0, [](int __, int _) -> int
        {
            return __ + (_ & 1);
        });
        return odd == 0 ? ret : ret - odd + 1;
    }
};

void test() {}

int main() { test(); return 0; }
