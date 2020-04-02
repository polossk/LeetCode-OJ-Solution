# Subarray Sum Equals K

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Array](https://img.shields.io/badge/数组-Array-007ec6.svg) ![Hash_Table](https://img.shields.io/badge/哈希表-Hash_Table-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode560-cpp-f34b7d.svg)   | 48 ms   | 12.4 Mb      |
| ![python](https://img.shields.io/badge/leetcode560-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode560-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an array of integers and an integer **k**, you need to find the total number of continuous subarrays whose sum equals to **k**.

## EXAMPLE

```plain
Input:nums = [1,1,1], k = 2
Output: 2
```

## RESTRICTIONS

* The length of the array is in range [1, 20,000].
* The range of numbers in the array is [-1000, 1000] and the range of the integer **k** is [-1e7, 1e7].

## SOLUTION

* 令记号 `sum(i, j)` 表示从元素 i 到元素 j 的累加求和结果，那么显然有递推关系 `sum(i, j) = sum(i, j-1) + nums[j]`
* 考虑如何快速维护 `sum(i, j)`，令 `sum[j] := sum(0, j)`，那么任意合法的 `sum(i, j) := sum[j] - sum[i-1]`
* 不妨假设存在一组这样的 `(i, j)` 使得 `sum(i, j) = k`，则显然有 `sum(i, j) := sum[j] - sum[i-1] == k`，即 `k + sum[i-1] == sum[j]`，所以只需要在计算到 `sum[j]` 时，去检索是否出现过 `sum[j] - k` 即可。建立一个哈希表来维护所有出现过的 `sum[i]` 和对应的次数。

## CODE

### C++

```cpp
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0, ret = 0;
        std::unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (int elem : nums)
        {
            sum += elem;
            if (cnt.find(sum - k) != cnt.end())
                ret += cnt[sum - k];
            cnt[sum]++;
        }
        return ret;
    }
};
```

### Python3


### Ruby

