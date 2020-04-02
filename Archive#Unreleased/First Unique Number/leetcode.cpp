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

namespace std
{
    using KV = std::pair<int, int>;
    template <>
    struct less<KV> : public binary_function<KV, KV, bool>
    {
        using result_type = bool;
        using first_argument_type = KV;
        using second_argument_type = KV;
        constexpr bool operator()(const KV &a, const KV &b) const
        {
            return a.second > b.second;
        }
    };
}

class FirstUnique
{
    using KV = std::pair<int, int>;
    std::unordered_map<int, int> cnt_;
    std::priority_queue<KV> heap_;
    int length;

public:
    FirstUnique(vector<int>& nums)
    {
        cnt_.clear();
        heap_ = std::priority_queue<KV>();
        length = 0;
        for (auto elem : nums) add(elem);
    }
    
    int showFirstUnique()
    {
        while(!heap_.empty())
        {
            auto [key, value] = heap_.top();
            if (cnt_[key] == 1) return key;
            heap_.pop();
        }
        return -1;
    }
    
    void add(int value)
    {
        cnt_[value]++;
        if (cnt_[value] == 1) heap_.push({value, length});
        length++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

void test() {}

int main() { test(); return 0; }
