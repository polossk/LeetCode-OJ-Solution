# Longest Palindrome

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Hash_Table](https://img.shields.io/badge/哈希表-Hash_Table-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode409-cpp-f34b7d.svg)   | 0 ms    | 7.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode409-py-3572A5.svg) | 32 ms   | 13 Mb        |
| ![ruby](https://img.shields.io/badge/leetcode409-rb-701516.svg)   | 40 ms   | 9.2 Mb       |

## DESCRIPTION

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example `"Aa"` is not considered a palindrome here.

## EXAMPLE

```plain
Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
```

## NOTE

Assume the length of given string will not exceed 1,010.

## SOLUTION

* 偶数个同一字符可以无条件满足回文串的构造，奇数个同一字符时需要分类讨论
* 当只有一个该字符时，此字符只能用在回文串的中间位置；当有多个字符时，可以直接舍去一个使其变成偶数个
* 假设最终统计有 `m` 个奇数字符，中央位置可以额外利用 1 个，其余都需要减少 1 个，所以对于这 `m` 个奇数字符，需要舍弃 `m-1` 个字符

## CODE

### C++

```cpp
class Solution {
public:
    int longestPalindrome(string s)
    {
        vector<int> alphabet(26 * 2, 0);
        for (char ch : s)
        {
            int offset = isupper(ch) ? 0 : 26;
            alphabet[ch - (offset ? 'a' : 'A') + offset]++;
        }
        int ret = s.size();
        int odd = std::accumulate(alphabet.begin(), alphabet.end(), 0, [](int __, int _) -> int
        {
            return __ + (_ & 1);
        });
        return odd == 0 ? ret : ret - odd + 1;
    }
};
```

### Python3

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        ret, odd = len(s), 0
        alphabet = {chr(ord(ch) + _):0 for ch in ['A', 'a'] for _ in range(26)}
        for ch in s:
            alphabet[ch] += 1
        odd = sum([1 for v in alphabet.values() if v % 2 == 1])
        return ret if odd == 0 else ret - odd + 1
```

### Ruby

```ruby
# @param {String} s
# @return {Integer}
def longest_palindrome(s)
  ret, odd = s.size, 0
  alphabet = {}
  ('A'..'Z').each{ |ch| alphabet[ch] = alphabet[ch.downcase] = 0 }
  s.each_char{ |ch| alphabet[ch] += 1}
  odd = alphabet.each_value.select { |value| value % 2 == 1 }.size
  odd == 0 ? ret : ret - odd + 1
end
```