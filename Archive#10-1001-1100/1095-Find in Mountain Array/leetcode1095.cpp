// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1095                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
    int target_, size_;
    int binSearch(MountainArray &mArr, int left, int right, bool is_inc)
    {
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            int val = mArr.get(mid);
            if (val == target_) { return mid; }
            if (is_inc) val < target_ ? (left = mid + 1) : (right = mid - 1);
            else val < target_ ? (right = mid - 1) : (left = mid + 1);
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mArr)
    {
        this->size_ = mArr.length();
        this->target_ = target;
        int left = 0, right = size_ - 1;
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            int val = mArr.get(mid);
            int mid_next = mArr.get(mid + 1);
            if (val < mid_next) left = mid + 1;
            else right = mid;
        }
        int peak = left;
        int tmp = binSearch(mArr, 0, peak, true);
        return tmp == -1 ? binSearch(mArr, peak + 1, size_ - 1, false) : tmp;
    }
};

void test() {}

int main() { test(); return 0; }
