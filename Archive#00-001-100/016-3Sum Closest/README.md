# 3Sum Closest

![Medium](../../materials/-Medium-f0ad4e.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Two_Pointers](../../materials/双指针法-Two_Pointers-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode016-cpp-f34b7d.svg)   | 24 ms   | 9.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode016-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode016-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

## EXAMPLE

```plain
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

## SOLUTION

* 固定三个数中的一个 `nums[i]`，然后双指针前后分别搜索判断当前距离 `dis(nums[j] + nums[k], target - nums[i])` 是否比上一个距离小。同时根据此时的结果计算下一步指针的变化，即如果超过了 `target` 则说明当前值过大，靠右的指针往左走一步，反之操作另一个指针。

## CODE

### C++

```cpp
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        for (int i = 0, sz = nums.size(); i + 2 < sz; i++)
        {
            int j = i + 1, k = sz - 1;
            while (j < k)
            {
                int hoge = nums[i] + nums[j] + nums[k];
                if (abs(hoge - target) < abs(ret - target))
                    ret = hoge;
                hoge < target ? j++ : k--;
            }
        }
        return ret;
    }
};
```

### Python3

### Ruby

