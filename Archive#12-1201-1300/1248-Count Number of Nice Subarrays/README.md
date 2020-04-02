# Count Number of Nice Subarrays

 ![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Two_Pointers](https://img.shields.io/badge/双指针法-Two_Pointers-007ec6.svg)
## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1248-cpp-f34b7d.svg)   | 196 ms  | 22.4 Mb      |
| ![python](https://img.shields.io/badge/leetcode1248-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode1248-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an array of integers `nums` and an integer `k`. A subarray is called **nice** if there are `k` odd numbers on it.

Return the number of **nice** sub-arrays.

## EXAMPLE 1

```plain
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
```

## EXAMPLE 2

```plain
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
```

## EXAMPLE 3

```plain
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
```

## CONSTRAINTS

* `1 <= nums.length <= 50000`
* `1 <= nums[i] <= 10^5`
* `1 <= k <= nums.length`

## SOLUTION

* 统计奇数之间的间隔
* 然后累乘即可

## CODE

### C++

```cpp
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        vector<int> odds(1, -1), gap;
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
            if (nums[i] & 1) odds.push_back(i);
        int ret = 0;
        if (odds.size() < k) return ret;
        odds.push_back(sz);
        for (int i = 1, osz = odds.size(); i < osz; i++)
            gap.push_back(odds[i] - odds[i - 1]);
        for (int i = 0, gsz = gap.size(); i + k < gsz; i++)
            ret += gap[i] * gap[i + k];
        return ret;
    }
};
```

### Python3


### Ruby

