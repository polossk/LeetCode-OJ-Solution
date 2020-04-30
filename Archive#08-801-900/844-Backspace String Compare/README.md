# Backspace String Compare

![Easy](../../materials/-Easy-5cb85c.svg) ![Two_Pointers](../../materials/双指针法-Two_Pointers-007ec6.svg) ![Stack](../../materials/堆栈-Stack-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode844-cpp-f34b7d.svg)   | 0 ms    | 6.2 Mb       |
| ![python](https://img.shields.io/badge/leetcode844-py-3572A5.svg) | 28 ms   | 13.6 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode844-rb-701516.svg)   | 28 ms   | 9.4 Mb       |

## DESCRIPTION

Given two strings `S` and `T`, return if they are equal when both are typed into empty text editors. `#` means a backspace character.

## EXAMPLE 1

```plain
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
```

## EXAMPLE 2

```plain
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
```

## EXAMPLE 3

```plain
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
```

## EXAMPLE 4

```plain
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
```

## NOTE

1. `1 <= S.length <= 200`
2. `1 <= T.length <= 200`
3. `S` and `T` only contain lowercase letters and `'#'` characters.

## SOLUTION

* 逐字符模拟即可

## CODE

### C++

```cpp
class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        int lenS = 0, lenT = 0;
        for (int i = 0, sz = S.size(); i < sz; i++)
        {
            if (S[i] == '#') lenS -= lenS != 0;
            else S[lenS++] = S[i];
        }
        for (int i = 0, sz = T.size(); i < sz; i++)
        {
            if (T[i] == '#') lenT -= lenT != 0;
            else T[lenT++] = T[i];
        }
        if (lenS != lenT) return false;
        for (int i = 0; i < lenS; i++)
            if (S[i] != T[i]) return false;
        return true;
    }
};
```

### Python3

```python
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        def remake(s: str) -> str:
            ret = []
            for ch in s: ret = ret + [ch] if ch != '#' else ret[:-1]
            return ret
        return remake(S) == remake(T)
```

### Ruby

```ruby
# @param {String} s
# @param {String} t
# @return {Boolean}
def backspace_compare(s, t)
  def remake(s)
    ret = []
    s.each_char { |ch| ret = ch == '#' ? ret[0...-1] : ret + [ch] }
    ret
  end
  remake(s) == remake(t)
end
```