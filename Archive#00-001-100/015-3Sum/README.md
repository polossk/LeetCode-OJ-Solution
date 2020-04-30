# 3Sum

![Medium](../../materials/-Medium-f0ad4e.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Two_Pointers](../../materials/双指针法-Two_Pointers-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode015-cpp-f34b7d.svg)   | 64 ms   | 19.6 Mb      |
| ![python](https://img.shields.io/badge/leetcode015-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode015-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an array `nums` of *n* integers, are there elements *a*, *b*, *c* in `nums` such that *a + b + c = 0*? Find all unique triplets in the array which gives the sum of zero.

## EXAMPLE

```plain
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

## NOTE

The solution set must not contain duplicate triplets.

## SOLUTION

* 固定三个数中的一个 `nums[i]`，然后双指针前后分别搜索 `nums[j] + nums[k] == -nums[i]`

## CODE

### C++

```cpp
class Solution
{
    using Tuple = std::vector<int>;
public:
    vector<Tuple> threeSum(vector<int> &nums)
    {
        vector<Tuple> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            int target = -nums[i];
            if (target < 0) break;
            int l = i + 1, r = sz - 1;
            while (l < r)
            {
                int cur = nums[l] + nums[r];
                if (cur < target) l++;
                else if (cur > target) r--;
                else
                {
                    ret.push_back(Tuple({nums[i], nums[l], nums[r]}));
                    while (l < r && nums[l] == ret.back().at(1)) l++;
                    while (l < r && nums[r] == ret.back().at(2)) r--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return ret;
    }
};
```

### Python3

### Ruby

