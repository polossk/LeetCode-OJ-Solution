# 数组中数字出现的次数

![Medium](../../materials/-Medium-f0ad4e.svg) ![Bit_Manipulation2](../../materials/位运算-Bit_Manipulation-009688.svg)

## RESULT

| Submission                                                   | Runtime | Memory Usage |
| ------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/cof56a-cpp-f34b7d.svg)   | 48 ms   | 16.1 Mb      |
| ![python](https://img.shields.io/badge/cof56a-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/cof56a-rb-701516.svg)   | -       | -            |

## DESCRIPTION

一个整型数组 `nums` 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

## EXAMPLE 1

```plain
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
```

## EXAMPLE 2

```plain
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
```

## RESTRICTION

* `2 <= nums <= 10000`

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
    vector<int> singleNumbers(vector<int>& nums)
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


### Ruby

