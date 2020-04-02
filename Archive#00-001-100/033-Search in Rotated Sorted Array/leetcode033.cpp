// <!-- encoding UTF-8 --!>
/*****************************************************************************
 *                     ----Stay Hungry Stay Foolish----                       *
 *   @author :   Shen                                                         *
 *   @name   :   Leetcode 033                                                 *
 *****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) return mid;
            if (nums[mid] > nums[l])
            {
                if (nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else l = mid + 1;
            }
            else if (nums[mid] < nums[l])
            {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else r = mid - 1;
            }
            else l++;
        }
        return -1;
    }
};

void test() {}

int main() { test(); return 0; }
