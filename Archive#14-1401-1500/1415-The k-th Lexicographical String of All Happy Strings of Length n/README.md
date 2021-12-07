# The k-th Lexicographical String of All Happy Strings of Length n

![Medium](../../materials/-Medium-f0ad4e.svg) ![String](../../materials/字符串-String-007ec6.svg) ![Backtracking](../../materials/回溯法-Backtracking-007ec6.svg)

## RESULT

| Submission                                                       | Runtime | Memory Usage |
| ---------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1426-cpp-f34b7d.svg) | 4 ms    | 6 Mb         |

## DESCRIPTION

A **happy string** is a string that:

* consists only of letters of the set ['a', 'b', 'c'].
* s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).

For example, strings **"abc"**, **"ac"**, **"b"** and **"abcbabcbcb"** are all happy strings and strings **"aa"**, **"baa"** and **"ababbc"** are not happy strings.

Given two integers `n` and `k`, consider a list of all happy strings of length `n` sorted in lexicographical order.

Return the *kth* string of this list or return an empty string if there are less than `k` happy strings of length `n`.

## EXAMPLE 1

```plain
Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
```

## EXAMPLE 2

```plain
Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
```

## EXAMPLE 3

```plain
Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
```

## EXAMPLE 4

```plain
Input: n = 2, k = 7
Output: ""
```

## EXAMPLE 5

```plain
Input: n = 10, k = 100
Output: "abacbabacb"
```

## CONSTRAINTS

* `1 <= n <= 10`
* `1 <= k <= 100`

## SOLUTION

* 特殊二进制数，第一位是三进制

## CODE

### C++

```cpp
class Solution {
public:
    inline char next(char prev, int value)
    {
        if (prev == 'a')
            return value == 0 ? 'b' : 'c';
        if (prev == 'b')
            return value == 0 ? 'a' : 'c';
        if (prev == 'c')
            return value == 0 ? 'a' : 'b';
        return '\0';
    }

    string getHappyString(int n, int k)
    {
        int num = 1 << (n - 1);
        k -= 1;
        int r = k % num，first_char = k / num;
        if (first_char > 2) return "";
        string ret = "";
        int size = 1;
        ret += 'a' + first_char;
        while (num >>= 1)
        {
            if (r >= num)
            {
                ret += next(ret[size - 1], 1);
                r -= num;
            }
            else
            {
                ret += next(ret[size - 1], 0);
            }
            size += 1;
        }
        return ret;
    }
};
```
