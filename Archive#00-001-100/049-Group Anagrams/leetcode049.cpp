// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 049                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
    vector<int> encrypt(const string &s)
    {
        vector<int> ret(26, 0);
        for (auto it = s.begin(); it != s.end(); it++)
        ret[*it - 'a']++;
        return ret;
    }
    
    // BKDR Hash Function
    unsigned int BKDRHash(const vector<int> &s)
    {
        unsigned int seed = 31; // 31 131 1313 13131 131313 etc..
        unsigned int hash = 0;
        for (auto it = s.begin(); it != s.end(); it++)
            hash = hash * seed + (*it);
        return (hash & 0x7FFFFFFF);
    }
    
    std::unordered_map<unsigned int, int> get_index_;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ret;
        get_index_.clear();
        int offset = 0;
        for (int i = 0, sz = strs.size(); i < sz; i++)
        {
            const string &elem = strs[i];
            unsigned int ikey = BKDRHash(encrypt(elem));
            if (get_index_.count(ikey) > 0)
                ret[get_index_[ikey]].push_back(elem);
            else
            {
                get_index_[ikey] = offset++;
                ret.push_back(vector<string>({elem}));
            }
        }
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
