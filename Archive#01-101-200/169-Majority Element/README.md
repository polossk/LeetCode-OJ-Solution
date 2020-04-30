# Majority Element

![Easy](../../materials/-Easy-5cb85c.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Divide_and_Conquer](../../materials/分治法-Divide_and_Conquer-007ec6.svg) ![Bit_Manipulation](../../materials/位运算-Bit_Manipulation-007ec6.svg)

## RESULT

| Submission                                                            | Runtime | Memory Usage |
| --------------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode169--bmv-cpp-f34b7d.svg)  | 20 ms   | 10.2 Mb      |
| ![cpp](https://img.shields.io/badge/leetcode169--bit-cpp-f34b7d.svg)  | 24 ms   | 10.5 Mb      |
| ![cpp](https://img.shields.io/badge/leetcode169--sort-cpp-f34b7d.svg) | 28 ms   | 10.2 Mb      |
| ![python](https://img.shields.io/badge/leetcode169-py-3572A5.svg)     | 172 ms  | 14.3 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode169-rb-701516.svg)       | -       | -            |

## DESCRIPTION

Given an array of size `n`, find the majority element. The majority element is the element that appears **more than** `⌊ n/2 ⌋` times.

You may assume that the array is non-empty and the majority element always exist in the array.

## EXAMPLE 1

```plain
Input: [3,2,3]
Output: 3
```

## EXAMPLE 2

```plain
Input: [2,2,1,1,1,2,2]
Output: 2
```

## SOLUTION

* 摩尔投票法。注意到多数的意思是有至少一般以上的元素都是一个同一个。我们可以假设，多数元素为 1，其余元素为 -1，那么对这个数组求和的结果一定是大于零的。所以可以用摩尔投票法，相同的数 `+1`，否则 `-1`。当票数为 0 时淘汰并替换下一个选手。由于刚才的特性（数组求和大于 1），所以剩下的存活的选手一定是目标所要求的多数。
* 位运算法。逐位判断。一个数是多数元素，等价于对每一位而言，该位上的数字一定是此时的多数元素。所以利用这一性质通过位运算来统计判断即可。
* 排序法。注意到因为存在多数元素，那么对原数组排序的话，中间位置一定是多数元素。

## CODE

### C++

```cpp
class Solution
{
public:
    // Boyer-Moore Majority Voting Algorithm
    int majorityElement(vector<int>& nums)
    {
        int cur = 0, cnt = 0;
        for (auto elem : nums)
        {
            if (cnt == 0) cur = elem;
            cnt += cur == elem ? 1 : -1;
        }
        return cur;
    }
    // Bit Checking
    int majorityElement(vector<int>& nums)
    {
        int ret = 0, threshold = nums.size() >> 1;
        for (int i = 0; i < 32; i++)
        {
            int cnt = 0;
            for (auto elem : nums) cnt += (elem >> i) & 1;
            ret += (cnt > threshold) << i;
        }
        return ret;
    }
    // Sorting
    int majorityElement(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() >> 1];
    }
};
```

### Python3

```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return sorted(nums)[len(nums) // 2]
```

### Ruby

