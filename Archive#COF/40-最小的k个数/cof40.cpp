// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   COF 40                                                       *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    // sort then select
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        vector<int> ret(k, 0);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) ret[i] = arr[i];
        return ret;
    }
    // heap and scan
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        vector<int> ret(k, 0);
        if (k == 0) return ret;
        std::priority_queue<int> pq;
        for (int i = 0; i < k; i++) pq.push(arr[i]);
        for (int i = k, sz = arr.size(); i < sz; i++)
        {
            if (pq.top() > arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i)
        {
            ret[i] = pq.top();
            pq.pop();
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
