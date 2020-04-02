# Single Number III

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Bit_Manipulation](https://img.shields.io/badge/位运算-Bit_Manipulation-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode260-cpp-f34b7d.svg)   | 12 ms   | 7.8 Mb       |
| ![python](https://img.shields.io/badge/leetcode260-py-3572A5.svg) | 56 ms   | 15.1 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode260-rb-701516.svg)   | 40 ms   | 10 Mb        |

## DESCRIPTION

Given an array of numbers `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

## EXAMPLE

```plain
Input:  [1,2,1,3,2,5]
Output: [3,5]
```

## NOTE

1. The order of the result is not important. So in the above example, `[5, 3]` is also correct.
2. Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

## SOLUTION

* 假设这个序列是由 `[a, b, c, c, d, d, ...]` 这样一串数字构成的，对其做累积异或运算（位运算的不进位加法），得到 `result := a ^ b`
* 根据异或运算的定义，只有同一位置的值不同时才会得到 1，所以对刚才的结果求 lowbit 得到最后一位为 1 的值。举例，比如样例中的（整理后的）序列 `[3, 5, 1, 1, 2, 2]`，显然可知 `result := 3 ^ 5`，注意到 `3 := 0b0011`，`5 := 0b0101`，其异或结果为 `0b0011 (3) ^ 0b0101 (5) == 0b0110 (6)`，最后一位为 1 的值为 `lowbit(0b0110) == 0b0010 (2)`
* 有了 lowbit 之后，实际上我们就知道了两个数字在二进制下发生分歧的位置之一，所以，直接把原有数字分成两组，一组为这一位为 1 的，另一组为这一位为 0 的。分组之后，分别求各自组的累积异或即可，这样就找到了唯二的只出现一次的数字

## CODE

### C++

```cpp
class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int hoge = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        hoge &= -hoge;
        vector<int> ret(2, 0);
        for (int num : nums)
            ret[!(num & hoge)] ^= num;
        return ret;
    }
};
```

### Python3

```python
from functools import reduce

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        flag = reduce(nums, __xor__)
        flag &= -flag
        a, b = 0, 0
        for e in nums:
            if e & flag: a ^= e
            else: b ^= e
        return [a, b]
```

### Ruby

```ruby
# @param {Integer[]} nums
# @return {Integer[]}
def single_number(nums)
  hoge = nums.reduce(:^)
  hoge &= -hoge
  a = nums.select { |e| e & hoge == 0 }.reduce(:^)
  b = nums.select { |e| e & hoge != 0 }.reduce(:^)
  [a, b]
end
```

### Java
