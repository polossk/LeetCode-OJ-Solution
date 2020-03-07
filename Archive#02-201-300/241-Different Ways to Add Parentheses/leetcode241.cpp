// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 241                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> output;
        for (int i = 0, sz = input.size(); i < sz; i++)
        {
            if (ispunct(input[i]))
                for (int a : diffWaysToCompute(input.substr(0, i)))
                    for (int b : diffWaysToCompute(input.substr(i + 1)))
                        output.push_back(input[i] == '+' ? a + b :
                            input[i] == '-' ? a - b : a * b);
        }
        return output.size() ? output : vector<int>{stoi(input)};
    }
};

void test() {}

int main() { test(); return 0; }
