# Contiguous Array

![Medium](../../materials/-Medium-f0ad4e.svg) ![Hash_Table](../../materials/哈希表-Hash_Table-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode525-cpp-f34b7d.svg)   | 84 ms   | 19.8 Mb      |
| ![python](https://img.shields.io/badge/leetcode525-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode525-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

## EXAMPLE 1

```plain
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
```

## EXAMPLE 2

```plain
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
```

## NOTE

The length of the given binary array will not exceed 50,000.

## SOLUTION

* 做变换将 0 改为 -1，然后累进求和（求前缀和）。当某一刻的求和为 0 时，恰好为 1 与 0 的数量相等的时刻。进一步推广，如果某一刻的求和值 `d` 已经被算出过，那么说明从上一次出现到这次出现的这个区间内部恰好各有一半的 1 和 0
* 用数组 `tmp[d]` 记录从 `-nums.length()` 到 `nums.length()` 这些所有可能的前缀和可能结果的第一次计算出 `d = sum(nums[0], ..., sum[i])` 的下标 `i`
* 下标是恒大于等于 0 的整数，而计算求得前缀和为 0 的起点一定是 -1（没有元素参与计算，其前缀和必然为 0）

## CODE

### C++

```cpp
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int sz = nums.size();
        // tmp = [-sz, ..., 0, ..., sz]
        vector<int> tmp(1 + (sz << 1), -2);
        tmp[sz] = -1;
        int ret = 0, cnt = 0;
        for (int i = 0; i < sz; i++)
        {
            cnt += nums[i] == 0 ? -1 : 1;
            if (tmp[cnt + sz] >= -1)
                ret = std::max(ret, i - tmp[cnt + sz]);
            else
                tmp[cnt + sz] = i;
        }
        return ret;
    }
};
```

### Python3


### Ruby

