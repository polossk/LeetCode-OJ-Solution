// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 204                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

const int MAXN = 10000005;
int prime[MAXN >> 1];
bool isPrime[MAXN];

class Solution {
public:
    int countPrimes(int n)
    {
        int cnt = 0;
        fill(isPrime + 2, isPrime + MAXN, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i]) prime[cnt++] = i;
            for (int j = 0; j < cnt & prime[j] * i < n; j++)
            {
                isPrime[prime[j] * i] = false;
                if (!(i % prime[j])) break;
            }
        }
        return cnt;
    }
};

void test() {}

int main() { test(); return 0; }
