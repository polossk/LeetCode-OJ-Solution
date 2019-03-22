// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 307                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class NumArray {
    vector<int> tree_;
    vector<int> arr_;
    int maxn_;

    inline int lowbit(int x) { return x & (-x); }

    inline void add(int idx, int val)
    {
        for (int i = idx; i <= maxn_; i += lowbit(i))
            tree_[i] += val;
        arr_[idx] += val;
    }

    inline int get(int idx)
    {
        int sum = 0;
        for (int i = idx; i > 0; i -= lowbit(i))
            sum += tree_[i];
        return sum;
    }

public:
    NumArray(vector<int> &nums)
    {
        maxn_ = nums.size() + 2;
        tree_.resize(maxn_); arr_.resize(maxn_);
        fill(tree_.begin(), tree_.end(), 0);
        fill(arr_.begin(), arr_.end(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            add(i + 1, nums[i]);
            arr_[i + 1] = nums[i];
        }
    }

    void update(int i, int val)
    {
        add(i + 1, val - arr_[i + 1]);
    }

    int sumRange(int i, int j)
    {
        return get(j + 1) - get(i);
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

void test()
{
    vector<int> a = {1, 3, 5};
    NumArray _(a);
    cout << _.sumRange(0, 2) << endl;
    _.update(1, 2);
    cout << _.sumRange(0, 2) << endl;
    cout << _.sumRange(1, 2) << endl;
}

int main() { test(); return 0; }

