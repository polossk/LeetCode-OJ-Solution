# Strong Password Checker

![Hard](https://img.shields.io/badge/-Hard-e05d44.svg) ![Structured_Approach](https://img.shields.io/badge/构造法-Structured_Approach-009688.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode420-cpp-f34b7d.svg)   | 0 ms    | 7.7 Mb       |
| ![python](https://img.shields.io/badge/leetcode420-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode420-rb-701516.svg)   | -       | -            |

## DESCRIPTION

A password is considered strong if below conditions are all met:

1. It has at least 6 characters and at most 20 characters.
2. It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
3. It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the **MINIMUM** change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.

## SOLUTION

构造法题目

通过题目我们可知以下三种情况：

1. 当长度小于 6 时，对应的操作中必须有添加字符，那么可以借此机会添加缺少的字符，处理连续相同字符
2. 当长度大于 20 时，对应的操作中必须有删除字符，删除并不改变字符种类（除非全部删光），但能处理连续字符类错误
3. 当长度在 6 到 20 之间时，对应的操作只有修改字符，修改字符可以借机替换成缺失字符，同时也可以处理连续相同字符

问题的核心在于如何构造出适合不同操作的序列作为蓝本，从而推广到所有情况。假设有多种长度的字符相同的子串，我们分别讨论所需要的单一种类修改步骤和最优解

| 长度  | 情况       | 只删除  | 只添加           | 只修改        |
| :---: | :--------- | :------ | :--------------- | :------------ |
|   3   | `aaa`      | 1: `aa` | 1: `abaa`        | 1: `aba`      |
|   4   | `aaaa`     | 2: `aa` | 1: `aabaa`       | 1: `abaa`     |
|   5   | `aaaaa`    | 3: `aa` | 2: `abaabaa`     | 1: `aabaa`    |
|   6   | `aaaaaa`   | 4: `aa` | 2: `aabaabaa`    | 2: `ababaa`   |
|   7   | `aaaaaaa`  | 5: `aa` | 3: `abaabaabaa`  | 2: `abaabaa`  |
|   8   | `aaaaaaaa` | 6: `aa` | 3: `aabaabaabaa` | 2: `aabaabaa` |
|  ...  |            | ...     | ...              | ...           |
|   L   |            | L-2     | floor (L-1)/2    | floor L/3     |

注意到，只删除时，实际上将问题从 S 退化成了 S-1（`delete "aaaaa" => 1 "a" + delete "aaaa"`），所以只用删除来处理长度为 L 的串需要 L-1 步。同样，只添加操作我们可以发现实际上每一步相当于把问题 S 退化成了 S-2（`add "aaaaa" => 1 "baa" + add "aaa"`），所以只用添加来处理长度为 L 的串需要 (L-1)/2 步。修改操作每一次都把问题 S 退化成了 S-3（`replace "aaaaa" => 1 "baa" + replace "aaa"`），同样可以得到其最少步数为 L/3。显然，修改操作所需的操作步数可能是较小的。

由于存在向下取整算符，也就是说当字符串的长度为 2 (mod 3) 时，是在同样的只修改操作数下所能控制的最长子串。所以可以考虑将其余的通过增加与删除变换到字符串长度为 2 (mod 3)。具体而言，对于 0 (mod 3) 先删除，再修改；对于 1 (mod 3) 先增加在修改。我们来对比这两种路线的结果，字符 `d`，`a`，`r` 分别代表删除，增加，修改。

| 长度  | 情况                | 路线 A 先变换再修改                                      | 路线 B 只修改          |
| :---: | :------------------ | :------------------------------------------------------- | :--------------------- |
|   3   | `aaa`               | 1: (d) `aa`                                              | 1: `aba`               |
|   4   | `aaaa`              | 1: (a) `aabaa`                                           | 1: `abaa`              |
|   5   | `aaaaa`             | 1: (r) `aabaa`                                           | 1: `aabaa`             |
|   6   | `aaaaaa`            | 2: (dr) -> `aaaaa` -> `aabaa`                            | 2: `ababaa`            |
|   7   | `aaaaaaa`           | 2: (ar) -> `aaaaabaa` -> `aabaabaa`                      | 2: `abaabaa`           |
|   8   | `aaaaaaaa`          | 2: (rr) -> `aaaaabaa` -> `aabaabaa`                      | 2: `aabaabaa`          |
|   9   | `aaaaaaaaa`         | 3: (drr) -> `aaaaaaaa` -> `aabaabaa`                     | 3: `ababaabaa`         |
|  10   | `aaaaaaaaaa`        | 3: (arr) -> `aaaaaaaabaa` -> `aabaabaabaa`               | 3: `abaabaabaa`        |
|  11   | `aaaaaaaaaaa`       | 3: (rrr) -> `aabaabaabaa`                                | 3: `aabaabaabaa`       |
|  12   | `aaaaaaaaaaaa`      | 4: (drrr) -> `aaaaaaaaaaa` -> `aabaabaabaa`              | 4: `ababaabaabaa`      |
|  13   | `aaaaaaaaaaaaa`     | 4: (arrr) -> `aaaaaaaaaaabaa` -> `aabaabaabaabaa`        | 4: `abaabaabaabaa`     |
|  14   | `aaaaaaaaaaaaaa`    | 4: (rrrr) -> `aabaabaabaabaa`                            | 4: `aabaabaabaabaa`    |
|  15   | `aaaaaaaaaaaaaaa`   | 5: (drrrr) -> `aaaaaaaaaaaaaa` -> `aabaabaabaabaa`       | 5: `ababaabaabaabaa`   |
|  16   | `aaaaaaaaaaaaaaaa`  | 5: (arrrr) -> `aaaaaaaaaaaaaabaa` -> `aabaabaabaabaabaa` | 5: `abaabaabaabaabaa`  |
|  17   | `aaaaaaaaaaaaaaaaa` | 5: (rrrrr) -> `aabaabaabaabaabaa`                        | 5: `aabaabaabaabaabaa` |

也就是说，如果需要增加（或删除）字符时，可以通过贪心方式先增加（或删除）这些相同字符的子串中的字符，让其变换为可以通过只修改路线的简单方法。剩下的问题就是如何选择处理的先后顺序。假设有多条相同字符的子串需要处理，由鸽笼原理可知总会有一个与这些字符不重复的字符可以用来隔开相同字符，所以只需要考虑先后顺序。我们进行分类讨论。对于必须增加的场合，应当优先 A 再 B 从而一举两得，此时的优先级顺序为 `0=1>2`，因为最后一种情况至少需要插入两个字符来减少一次修改，从而达到最优情形。对于必须删除的场合，应当优先处理长度为 0 (mod 3) 的子串才能一举两得。此时的优先级顺序为 `0>1>2`。所以代码中最终的优先级顺序为 `0 > 1 > 2`，而添加与删除操作可以在循环中自主判断。

## CODE

### C++

```cpp
class Solution
{
public:
    int strongPasswordChecker(string s)
    {
        int n = s.size();
        bool upper = false, lower = false, digit = false;
        int _add = max(0, 6 - n), _del = max(0, n - 20);
        int add = 0, del = 0, rep = 0;

        vector<vector<int> > hoge(3);
        for (int i = 0, j = 0; i <= n; i++)
        {
            if (i == n || s[i] != s[j])
            {
                int gap = i - j;
                if (gap >= 3) hoge[gap % 3].push_back(gap);
                j = i;
            }
            if (i == n) break;
            digit |= isdigit(s[i]);
            upper |= isupper(s[i]);
            lower |= islower(s[i]);
        }
        for (int i = 0; i < 3; i++)
        {
            auto piyo = hoge[i];
            for (int j = 0; j < piyo.size(); j++)
            {
                if (i < 2)
                {
                    if (_add > add) { add++; piyo[j] -= i + 1; }
                    if (_del > del) { del += i + 1; piyo[j] -= i + 1; }
                }
                rep += piyo[j] / 3;
            }
        }
        rep = _del > del ? max(0, rep - (_del - del) / 3) : rep + del - _del;
        return _del + max(_add + rep, (!upper) + (!lower) + (!digit));
    }
};
```

### Python3

### Ruby

### Java
