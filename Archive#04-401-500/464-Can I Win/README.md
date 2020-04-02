# Can I Win

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg) ![Minimax](https://img.shields.io/badge/极小极大算法-Minimax-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode464-cpp-f34b7d.svg)   | 180 ms  | 19 Mb        |
| ![python](https://img.shields.io/badge/leetcode464-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode464-rb-701516.svg)   | -       | -            |

## DESCRIPTION

In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer `maxChoosableInteger` and another integer `desiredTotal`, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that `maxChoosableInteger` will not be larger than 20 and `desiredTotal` will not be larger than 300.

## EXAMPLE

```plain
Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
```

## SOLUTION

* 先找规律：当 `maxChoosableInteger >= desiredTotal` 时，先手必胜；当所有剩余的数字都没有 `desiredTotal` 大时，先手必败；
* 利用二进制位表示所选择的数字情形，记忆化搜索即可

## CODE

### C++

```cpp
class Solution
{
    unordered_map<int, bool> dp_;
    static const int MAXI = 20;
    bool dfs(int desiredTotal, int mask)
    {
        if (dp_.count(mask)) return dp_[mask];
        for (int i = MAXI; i > 0; i--)
        {
            int bit = 1 << i;
            if (mask & bit)
            {
                if (i >= desiredTotal) { return dp_[i] = true; }
                bool flag = dfs(desiredTotal - i, mask ^ bit);
                dp_[mask ^ bit] = flag;
                if (!flag) return true;
            }
        }
        return false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
#define hoge maxChoosableInteger
        if (hoge >= desiredTotal) return true;
        if ((((hoge + 1) * hoge) >> 1) < desiredTotal) return false;
        int mask = 0;
        for (int i = 0; i <= hoge; i++)
        {
            mask = (mask << 1) + 1;
        }
        return dfs(desiredTotal, mask);
#undef hoge
    }
};
```

### Python3

### Ruby

### Java
