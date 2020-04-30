# Edit Distance

![Hard](../../materials/-Hard-e05d44.svg) ![String](../../materials/字符串-String-007ec6.svg) ![Dynamic_Programming](../../materials/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode072-cpp-f34b7d.svg)   | 20 ms   | 9.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode072-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode072-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given two words *word1* and *word2*, find the minimum number of operations required to convert *word1* to *word2*.

You have the following 3 operations permitted on a word:

1. Insert a character
2. Delete a character
3. Replace a character

## EXAMPLE 1

```plain
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

## EXAMPLE 2

```plain
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
```

## SOLUTION

* 定义 `dp[i][j]` 表示 `word1` 中前 `i` 个字符，变换到 `word2` 中前 `j` 个字符，最短需要操作的次数
* `i` 与 `j` 可以取值到 0，对应的情形为其中一个串为空串，所以需要全增全删操作，此时对应的取值为 `dp[i][0] := i`，`dp[0][j] := j`
* 对于增删操作，增加字符相当于从 `dp[i][j-1]` 变化到 `dp[i][j]`，代价为 1 个字符，所以有 `dp[i][j] := dp[i][j-1] + 1`，删除字符相当于从 `dp[i-1][j]` 变化到 `dp[i][j]`，代价为 1 个字符，所以有 `dp[i][j] := dp[i-1][j] + 1`
* 如果字符串中两字符相等 `word[i-1] == word[j-1]`，此时则不需要额外更改，那么相当于新旧状态的取值相同，即 `dp[i][j] := dp[i-1][j-1]`
* 如果字符不相等，则需要更改字符，代价为 1 个字符，有 `dp[i][j] := dp[i-1][j-1] + 1`

## CODE

### C++

```cpp
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length(), m = word2.length();
        if (n * m == 0) return n + m;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
        {
            // dp[i-1][j-1] --> dp[i-1][j]
            //  |                |
            //  V                V
            // dp[ i ][j-1] --> dp[ i ][j]
            int ii = dp[i - 1][j] + 1;
            int jj = dp[i][j - 1] + 1;
            int ij = dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);
            dp[i][j] = min(ii, min(jj, ij));
        }
        return dp[n][m];
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```
