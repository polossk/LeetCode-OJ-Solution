# 圆圈中最后剩下的数字

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Simulation_Method](https://img.shields.io/badge/模拟法-Simulation_Method-009688.svg) ![Josephus](https://img.shields.io/badge/约瑟夫环-Josephus-009688.svg)

## RESULT

| Submission                                                  | Runtime | Memory Usage |
| ----------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/cof40-cpp-f34b7d.svg)   | 4 ms    | 5.8 Mb       |
| ![python](https://img.shields.io/badge/cof40-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/cof40-rb-701516.svg)   | -       | -            |

## DESCRIPTION

0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

## EXAMPLE 1

```plain
输入: n = 5, m = 3
输出: 3
```

## EXAMPLE 2

```plain
输入: n = 10, m = 17
输出: 2
```

## RESTRICTION

* `1 <= n <= 10^5`
* `1 <= m <= 10^6`

## SOLUTION

* 约瑟夫环裸题
* 对于长度为 `n` 的序列，当删除了第 `m` 个数字后，其长度变为 `n-1`（废话）。不妨假设删除的这个数字为 `x0`，显然 `x0 = (m-1) % n`。
* 继续这样做，去删除数字时，不妨对这个序列重新编号，从 `x0+1` 开始用 `0` 编号，直到 `n-1` 为止，这样的话不难求出，这一轮被删除的数字的新编号为 `y1 := (m-1) % (n-1)`，而老编号可以用 `y0 := (y1+x0+1) % n` 映射得到。所以简而言之，这次被删掉的数字的原始编号 `y0` 可以通过两次加法取模运算求得。
* 继续这样做，假设我们令记号 `f(n, m)` 表示长度为 `n` 的序列，不断删除了第 `m` 个数字后，所剩的最后结果。显然有 `f(n, m) := (f(n-1, m) + ((m-1) % n) + 1) % n`
* 注意到整个式子都是在模 n 的环境下的，所以可以将加法拆开化简为 `f(n, m) := (f(n-1, m) + (m-1) + 1) % n = (f(n-1, m) + m) % n`
* 当只剩下一个值时，`n==1`，此时一定剩下编号为 0 的元素，所以从 `n==2` 开始逐次反推即可。

## CODE

### C++

```cpp
class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        int ret = 0;
        // last round will just be 2 people left
        for (int i = 2; i <= n; i++)
            ret = (ret + m) % i;
        return ret;
    }
};
```

### Python3


### Ruby

