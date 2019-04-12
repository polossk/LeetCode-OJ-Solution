// <!-- encoding UTF-8 --!>
/*****************************************************************************
 *                     ----Stay Hungry Stay Foolish----                       *
 *   @author :   Shen                                                         *
 *   @name   :   Leetcode 001                                                 *
 *****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> index;
        typedef pair<int, int> Item;
        vector<Item> table;
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            table.push_back(make_pair(nums[i], i));
        }
        sort(table.begin(), table.end(), [](const Item &a, const Item &b) -> bool { return a.first < b.first; });
        sort(nums.begin(), nums.end());
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            int piyo = nums[i];
            if (binary_search(nums.begin(), nums.end(), target - piyo))
            {
                int hoge = lower_bound(nums.begin(), nums.end(), target - piyo) - nums.begin();
                while (hoge == i && nums[hoge] == piyo)
                    hoge++;
                if (piyo + nums[hoge] == target)
                {
                    index.push_back(table[i].second);
                    index.push_back(table[hoge].second);
                    sort(index.begin(), index.end());
                    return index;
                }
            }
        }
        return vector<int>();
    }
};

void test() {}

int main()
{
    test();
    return 0;
}
