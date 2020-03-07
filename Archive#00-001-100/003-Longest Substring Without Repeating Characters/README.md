# Longest Substring Without Repeating Characters

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Hash_Table](https://img.shields.io/badge/哈希表-Hash_Table-007ec6.svg) ![Two_Pointers](https://img.shields.io/badge/双指针法-Two_Pointers-007ec6.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg) ![Sliding_Window](https://img.shields.io/badge/滑窗法-Sliding_Window-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode003-cpp-f34b7d.svg)   | 4 ms    | 9.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode003-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode003-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a string, find the length of the **longest substring** without repeating characters.

## EXAMPLE 1

```plain
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
```

## EXAMPLE 2

```plain
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

## EXAMPLE 3

```plain
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

## SOLUTION

* 扫一遍，并用数组 `fin[ch]` 维护字符 `ch` 上次出现在字符串中的位置
* 如果没有出现相同的字符，则当前长度直接 +1 即可
* 反之则更新当前的长度为从上一次出现该字符时的到此时与当前长度之间的较小值
* 每走一步更新一次答案，`ans[i] = max(ans[i - 1], dp[i])`
* `dp[i] = fin[str[i]] == -1 ? dp[i] + 1 : min(dp[i] + 1, i - fin[str[i]])`
* 初值设置：`dp[0] = 1`（走到第一个字符时当前长度为 1）, `fin[str[0]] = 0`（第一个字符上一次出现的位置为 0）

## CODE

### C++

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int fin[400];
        memset(fin, -1, sizeof(fin));
        int sz = s.size();
        if (sz == 0) return 0;
        int hoge = 1;
        int ans = 1;
        fin[s[0]] = 0;
        for (int i = 1; i < sz; i++)
        {
            int idx = fin[s[i]];
            if (idx == -1) hoge++;
            else hoge = min(hoge + 1, i - idx);
            fin[s[i]] = i;
            ans = max(ans, hoge);
        }
        return ans;
    }
};
```

### Python3

### Ruby
