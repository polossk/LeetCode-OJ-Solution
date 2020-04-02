# Count The Repetitions

![Hard](https://img.shields.io/badge/-Hard-e05d44.svg) ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode466-cpp-f34b7d.svg)   | 0 ms    | 6.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode466-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode466-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Define `S = [s,n]` as the string S which consists of n connected strings s. For example, `["abc", 3]` ="abcabcabc".

On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1. For example, “abc” can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.

You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers 0 ≤ n1 ≤ 10^6 and 1 ≤ n2 ≤ 10^6. Now consider the strings S1 and S2, where `S1=[s1,n1]` and `S2=[s2,n2]`. Find the maximum integer M such that `[S2,M]` can be obtained from `S1`.

## EXAMPLE

```plain
Input:
s1="acb", n1=4
s2="ab", n2=2

Return:
2
```

## SOLUTION

* 定义匹配数组 `match[i] := j` 表示 `s1[j]` 是循环匹配过程中第一个匹配到 `S2[i]` 的字符；
* 如 `s1 := "abaacdbac"` 和 `S2 := ["adcbd", 2]` 这两个串，`match[]` 的取值依次为 `{0, 5, 8, 1, 5, 7, 5, 8, 1, 5, 7, 5, 8, 1, 5, ...}`；
* 仅仅有匹配数组还是不够的，需要统计在这次匹配过程当中，`s1` 和 `s2` 分别重复了多少次。记数组 `order[k][i]` 为循环匹配过程中，匹配到 `S2[i]` 的字符时所用到的 `sk` 的个数（从 1 开始记数，`k=1/2`），如上面的例子，此时 `order[1][i]` 的取值依次为 `{1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 6, ...}`，`order[2][i]` 的取值依次为 `{1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, ...}`；
* 记录了重复次数之后，只需要判断重复值即可，也就是当 `s2[i]` 被匹配上时，记录此时的 `order[1/2][i]` 是多少，当第二次、第三次、甚至更多次被匹配上时，相当于找到了循环节，即 `s1` 重复 `order[1][i'] - order[1][i]` 次就可以匹配到 `order[2][i'] - order[2][i]` 个 `s2`
* 最后结尾暴力匹配即可

## CODE

### C++

```cpp
class Solution
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        if (n1 == 0) return 0;
        int i = 0, order_1 = 0, order_2 = 0;
        int len_1 = s1.size(), len_2 = s2.size();
        unordered_map<int, pair<int, int>> memo;
        pair<int, int> head, loop;
        while (true)
        {
            order_1++;
            for (char ch : s1)
                if (ch == s2[i])
            {
                i++;
                if (i == len_2) { ++order_2; i = 0; }
            }
            // no more s1
            if (order_1 == n1) return order_2 / n2;
            // find s2[i] once again
            if (memo.count(i))
            {
                auto [order_1_fst, order_2_fst] = memo[i];
                head = {order_1_fst, order_2_fst};
                loop = {order_1 - order_1_fst, order_2 - order_2_fst};
                break;
            }
            else memo[i] = {order_1, order_2};
        }
        int ret = head.second + (n1 - head.first) / loop.first * loop.second;
        int rest = (n1 - head.first) % loop.first;
        for (int _ = 0; _ < rest; _++)
            for (char ch: s1)
                if (ch == s2[i])
        {
            i++;
            if (i == s2.size()) { ret++; i = 0; }
        }
        return ret / n2;
    }
};
```

### Python3

### Ruby

### Java
