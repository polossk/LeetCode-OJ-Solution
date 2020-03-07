# Bitwise AND of Numbers Range

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Bit_Manipulation](https://img.shields.io/badge/位运算-Bit_Manipulation-007ec6.svg)

## RESULT

| Submission                                                                              | Runtime | Memory Usage |
| --------------------------------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode201-cpp-f34b7d.svg)                         | 16 ms   | 8.2 Mb       |
| ![python](https://img.shields.io/badge/leetcode201-py-3572A5.svg)                       | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode201-rb-701516.svg) Normal Version          | 48 ms   | 9.3 Mb       |
| ![ruby](https://img.shields.io/badge/leetcode201-rb-701516.svg) Functional-Like Version | 100 ms  | 9.3 Mb       |

## DESCRIPTION

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

## EXAMPLE 1

```plain
Input: [5,7]
Output: 4
```

## EXAMPLE 2

```plain
Input: [0,1]
Output: 0
```

## SOLUTION

* 位运算性质，与运算在遇到 `0` 时就会返回 `0`, 所以目标是找到哪一位有 `0`
* 与十进制类似，从 `m` 到 `n` 实际上只有后面的位在变化，前面的位并没有动
* 通过异或运算找出不动的位和变化的位，然后再通过 `1` 的右移运算找到最高的变动位
* 直接判断该结果与 `m` 的与运算结果即可 

## CODE

### C++

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int hoge = m ^ n, ret = 0;
        for (int i = 1; ; i <<= 1)
        {
            if (i > n || i < 0) break;
            if (i > hoge) ret += i;
        }
        return ret & m;
    }
};
```

### Python3

### Ruby

```ruby
def range_bitwise_and(m, n)
    # Normal Version
    h, hoge, piyo = m ^ n, 0, 1
    while (piyo <= n && piyo >= 0)
        hoge = hoge + piyo if piyo > h
        piyo = piyo << 1
    end
    hoge & m
end

def range_bitwise_and(m, n)
    # Functional-Like Version, Using Enumerator and select
    piyo = Enumerator.new do |y|
        fuga = 1
        loop do
            y << fuga
            fuga = fuga << 1
        end
    end
    m & piyo.take(32).select { |x| x > (m ^ n) && x <= n }.reduce(0, :+)
end
```

### Java
