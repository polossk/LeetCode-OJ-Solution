# Single Number

![Easy](../../materials/-Easy-5cb85c.svg) ![Hash_Table](../../materials/哈希表-Hash_Table-007ec6.svg) ![Bit_Manipulation](../../materials/位运算-Bit_Manipulation-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode136-cpp-f34b7d.svg)   | 12 ms   | 7.7 Mb       |
| ![python](https://img.shields.io/badge/leetcode136-py-3572A5.svg) | 72 ms   | 16.3 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode136-rb-701516.svg)   | 36 ms   | 10 Mb        |

## DESCRIPTION

Given a **non-empty** array of integers, every element appears *twice* except for one. Find that single one.

## EXAMPLE 1

```plain
Input: [2,2,1]
Output: 1
```

## EXAMPLE 2

```plain
Input: [4,1,2,1,2]
Output: 4
```

## NOTE

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

## SOLUTION

* 累积异或

## CODE

### C++

```cpp
class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<>());
        return ret;
    }
};
```

### Python3

```python
from functools import reduce

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(lambda a, b: a ^ b, nums, 0)
```

### Ruby

```ruby
# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)
  nums.inject(:^)
end
```

