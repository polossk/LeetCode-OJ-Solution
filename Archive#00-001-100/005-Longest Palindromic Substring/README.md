# Longest Palindromic Substring

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg) ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode005-cpp-f34b7d.svg)   | 4 ms    | 8.7 Mb       |
| ![python](https://img.shields.io/badge/leetcode005-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode005-rb-701516.svg)   | 144 ms  | 11.1 Mb      |

## DESCRIPTION

Given a string **s**, find the longest palindromic substring in **s**. You may assume that the maximum length of **s** is 1000.

## EXAMPLE 1

```plain
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
```

## EXAMPLE 2

```plain
Input: "cbbd"
Output: "bb"
```

## SOLUTION

* Manacher's Algorithm

## CODE

### C++

```cpp
class Solution {
public:
    static const int MAXL = 1024;
    char Ma[MAXL * 2];
    int Mp[MAXL * 2];
    string longestPalindrome(string s)
    {
        int sz = s.size();
        int l = 0;
        /// manacher algorithm O(n)
        // memset(Ma, 0, sizeof(Ma));
        // memset(Mp, 0, sizeof(Mp));
        Ma[l++] = '$'; Ma[l++] = '#';
        for (int i = 0; i < sz; i++)
        {
            Ma[l++] = s[i];
            Ma[l++] = '#';
        }
        Ma[l] = 0;
        int mx = 0, id = 0;
        for (int i = 0; i < l; i++)
        {
            Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;
            while ((i - Mp[i] > 0) && (Ma[i + Mp[i]] == Ma[i - Mp[i]])) Mp[i]++;
            if (i + Mp[i] > mx)
            {
                mx = i + Mp[i];
                id = i;
            }
        }
        /// get palindrome
        int pos = std::max_element(Mp, Mp + l) - Mp;
        int val = Mp[pos] - 1;
        string ret = "";
        for (int start = pos - val, end = pos + val; start <= end; start++)
            if (Ma[start] == '#' || Ma[start] == '$')
                continue;
            else ret += Ma[start];
        return ret;
    }
};
```

### Python3

### Ruby

```ruby
# @param {String} s
# @return {String}
def longest_palindrome(s)
  # manacher algorithm O(n)
  s = '$' + s;
  ma = s.each_char.map { |e| e + '#' }.inject(:+)
  l = ma.length
  mp = Array.new(l) { 0 }
  mx, id = 0, 0
  l.times { |i|
    mp[i] = mx > i ? [mp[2 * id - i], mx - i].min : 1
    while i - mp[i] > 0 && ma[i + mp[i]] == ma[i - mp[i]] do 
      mp[i] = mp[i] + 1
    end
    mx, id = i + mp[i], i if i + mp[i] > mx
  }
  # get palindrome
  pkg = mp.zip(0..l).max { |a, b| a[0] <=> b[0] }
  pos, val = pkg[1], pkg[0] - 1
  ma[(pos - val) .. (pos + val)].delete('#').delete('$')
end
```
