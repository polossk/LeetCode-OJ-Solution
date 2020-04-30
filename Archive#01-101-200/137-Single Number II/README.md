# Single Number II

![Medium](../../materials/-Medium-f0ad4e.svg) ![Bit_Manipulation](../../materials/位运算-Bit_Manipulation-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode137-cpp-f34b7d.svg)   | 8 ms    | 7.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode137-py-3572A5.svg) | 56 ms   | 15.6 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode137-rb-701516.svg)   | 36 ms   | 9.8 Mb       |

## DESCRIPTION

Given a **non-empty** array of integers, every element appears *three* times except for one, which appears exactly once. Find that single one.

## EXAMPLE 1

```plain
Input: [2,2,3,2]
Output: 3
```

## EXAMPLE 2

```plain
Input: [0,1,0,1,0,1,99]
Output: 99
```

## NOTE

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

## SOLUTION

* 对任意二进制带符号整数 `a` 而言，其对于异或运算的逆元即为本身，因为显然根据定义有 `a xor a == 0`，同样可以根据定义得到异或运算的单位元，即 `0`
* 现在开始考虑可能的状态。注意到每一个数位遇到的状态有 4 种：A 该位为 0，B 该位为 1 且第一次遇见, C 该位为 1 且第二次遇见，D 该位为 1 且第三次遇见。其可能的状态转移路线有这些：逐渐遇见 `1`；没有遇到 `1`；遇到了三个 `1` 之后再次遇到 `1`。如图所示，最后一种情况说明，这次是来新的数字了。

```plain
A     B     C     D # (A|B|C) -> (A|B|C): x = 0
^     ^     ^     ^ # A -> B: x = 1
|     |     |     | # B -> C: x = 1
A --> B --> C --> D # C -> D: x = 1
      ^           | # D -> B: x = 1
      |___________v
```

* 既然有了有限状态，我们就可以用掩码来表示状态。注意到有 4 种互斥的状态，所以至少应当用 2 个 bit 来编码。而实际上，由于状态 D 和状态 A 是等价的（因为 `D -> B` 说明来了新数字，和 `A -> B` 的意义相同）。因此最终的掩码标记的定义为：
  
| state | mask a | mask b |
| ----- | ------ | ------ |
| A     | 0      | 0      |
| B     | 1      | 0      |
| C     | 0      | 1      |

* 剩下的就是整理状态转移方程，可以通过真值表或者直接观察数字规律求得。对于掩码 `a`，只有状态 B 时其取值为 1，该取值的途径路线为 `A -> B` 或 `B -> B`，分别对应掩码（`xab`） `100->110` 和 `010->010`，注意到这两个的 `b` 始终为 0，且满足 `a ^ x == 1` 所以可以直接对于此时设置为 `a_next := (a ^ x) & (~b)`；对于掩码 `b`，只有状态 C 时其取值为 1，该取值的途径路线为 `B -> C` 或 `C -> C`，分别对应掩码（`xab`） `110->101` 和 `001->001`，注意到此时有 `b ^ x == 1` 和 `b ^ a == 1` 且满足所以可以直接对于此时设置为 `b_next := (b ^ x) & (b ^ a)`
* 有了初步的式子之后开始检查其他状态能否正确转移。注意到，由于状态 C 在计算过程中，无论如何都会使得掩码 `a` 的值固定在 0，所以掩码 `b` 的转移方程可以进一步简化 `b_next := (b ^ x) & (~a_next)`，前提是先算 `a_next`

## CODE

### C++

```cpp
class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int a = 0, b = 0;
        for (auto e : nums)
        {
            a = (a ^ e) & (~b);
            b = (b ^ e) & (~a);
        }
        return a;
    }
};
```

### Python3

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a, b = 0, 0
        for e in nums:
            a = (a ^ e) & (~b)
            b = (b ^ e) & (~a)
        return a
```

### Ruby

```ruby
# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)
  a, b = 0, 0
  nums.each{ |e| a, b = (a ^ e) & (~b), (b ^ e) & (a ^ b) }
  a
end
```

