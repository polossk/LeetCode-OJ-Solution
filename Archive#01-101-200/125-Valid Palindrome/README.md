# Maximum Depth of Binary Tree

![Easy](../../materials/-Easy-5cb85c.svg) ![Two_Pointers](../../materials/双指针法-Two_Pointers-007ec6.svg) ![String](../../materials/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode543-cpp-f34b7d.svg)   | 4 ms    | 7.5 Mb       |
| ![python](https://img.shields.io/badge/leetcode543-py-3572A5.svg) | 40 ms   | 15.1 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode543-rb-701516.svg)   | 52 ms   | 12.8 Mb      |

## DESCRIPTION

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

## EXAMPLE 1

```plain
Input: "A man, a plan, a canal: Panama"
Output: true
```

## EXAMPLE 2

```plain
Input: "race a car"
Output: false
```

## NOTE

For the purpose of this problem, we define empty string as valid palindrome.

## SOLUTION

* 字符串基本题目

## CODE

### C++

```cpp
class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            while (!isalnum(s[i]) && i < j) i++;
            while (!isalnum(s[j]) && i < j) j--;
            if (tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};
```

### Python3

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        t = [ch for ch in s.lower() if ch.isalnum()]
        return t == t[::-1]
```

### Ruby

```ruby
# @param {String} s
# @return {Boolean}
def is_palindrome(s)
  tmp = s.scan(/[A-Za-z0-9]/).join.downcase
  tmp == tmp.reverse
end
```