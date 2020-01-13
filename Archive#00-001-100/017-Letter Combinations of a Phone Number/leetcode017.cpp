// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 017                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size == 0) return vector<string>();
        return __dfs(digits);
    }

private:
    map<char, vector<string>> __keyboard_ = {
        {'2', vector<string>{"a", "b", "c"}}, {'3', vector<string>{"d", "e", "f"}},
        {'4', vector<string>{"g", "h", "i"}}, {'5', vector<string>{"j", "k", "l"}},
        {'6', vector<string>{"m", "n", "o"}}, {'7', vector<string>{"p", "q", "r", "s"}},
        {'8', vector<string>{"t", "u", "v"}}, {'9', vector<string>{"w", "x", "y", "z"}},
    };

    vector<string> __dfs(const string &digits)
    {
        if (digits.size() == 1)
            return __keyboard_[digits[0]];
        else
            return __deal(__keyboard_[digits[0]], __dfs(digits.substr(1)));
    }

    vector<string> __deal(const vector<string> &a, const vector<string> &b)
    {
        vector<string> ret;
        for (int i = 0, isz = a.size(); i < isz; i++)
            for (int j = 0, jsz = b.size(); j < jsz; j++)
                ret.push_back(a[i] + b[j]);
        return ret;
    }
};

void test()
{
    Solution sol = Solution();
    auto ret = sol.letterCombinations("23");
    for (auto e : ret)
        cout << " " << e;
    cout << endl;
}

int main()
{
    test();
    return 0;
}
