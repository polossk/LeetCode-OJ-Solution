# Happy Number

![Easy](../../materials/-Easy-5cb85c.svg) ![Hash_Table](../../materials/哈希表-Hash_Table-007ec6.svg) ![Math](../../materials/数学-Math-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode202-cpp-f34b7d.svg)   | 0 ms    | 5.8 Mb       |
| ![python](https://img.shields.io/badge/leetcode202-py-3572A5.svg) | 28 ms   | 13.8 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode202-rb-701516.svg)   | 28 ms   | 9.3 Mb       |

## DESCRIPTION

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

## EXAMPLE

```plain
Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
```

## SOLUTION

* 预处理平方不超过 10 的数字，可以发现除了 `1 * 1 == 1` 之外，0，2 和 3 都不满足条件，所以可以设置 `0b0010` 来表示结果
* 为了存储方便，我们设置一个 16 位的无符号整数来储存 0-15 的结果，然后对每一个数字将其处理至小于 16 即可

## CODE

### C++

```cpp
class Solution
{
    // bit equals to 1 if and only if index equals to 1 or 7
    // diagram for that
    // bit index: 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
    // bit value:  0  0  1  0  0  1  0  0  1  0  0  0  0  0  1  0
    // hex value:           2           4           8           2
    const std::bitset<16> ans = std::bitset<16>(0x2482);
    
    inline int next(int n)
    {
        int ret = 0;
        while (n > 0)
        {
            int d = n % 10;
            n /= 10;
            ret += d * d;
        }
        return ret;
    }
public:
    bool isHappy(int n)
    {
        while (n >= 16) n = next(n);
        return ans[n];
    }
};
```

### Python3

```python
class Solution:
    ans = [False, True, False, False, False, False, False, True,
           False, False, True, False, False, True, False, False]
    def next(self, n: int) -> int:
        return sum([int(_) ** 2 for _ in str(n)])
    
    def isHappy(self, n: int) -> bool:
        while n >= 16: n = self.next(n)
        return self.ans[n]
```

### Ruby

```ruby
# @param {Integer} n
# @return {Integer}
def get_next(n)
  n.to_s.each_char.map{|i| (i.to_i)**2 }.reduce(:+)
end


# @param {Integer} n
# @return {Boolean}
def is_happy(n)
  while n >= 8 do n = get_next(n) end
  n == 1 || n == 7
end
```
