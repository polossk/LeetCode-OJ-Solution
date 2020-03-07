# ZigZag Conversion

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode006-cpp-f34b7d.svg)   | 12 ms   | 10.3 Mb      |
| ![python](https://img.shields.io/badge/leetcode006-py-3572A5.svg) | 44 ms   | 12.8 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode006-rb-701516.svg)   | 60 ms   | 9.2 Mb       |

## DESCRIPTION

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```plain
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

`string convert(string s, int numRows);`

## EXAMPLE 1

```plain
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

## EXAMPLE 2

```plain
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
```

## SOLUTION

* 简单字符串模拟

## CODE

### C++

```cpp
class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) return s;
        string ret;
        int inc = (numRows - 1) << 1;
        int len = s.size();
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < len + numRows; j += inc)
            {
                if (j > i && j - i < len && i != 0 && i != numRows - 1)
                    ret += s[j - i];
                if (j + i < len) ret += s[j + i];
            }
        }
        return ret;
    }
};
```

### Python3

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        L, index, step = [''] * numRows, 0, 1
        for x in s:
            L[index] += x
            if index == 0:
                step = 1
            elif index == numRows -1:
                step = -1
            index += step
        return ''.join(L)
```

### Ruby

```ruby
# @param {String} s
# @param {Integer} num_rows
# @return {String}
def convert(s, num_rows)
  return s if num_rows == 1 or num_rows >= s.length
  l, index, step = [''] * num_rows, 0, 1
  s.each_char { |x|
    l[index] += x;
    step = 1 if index == 0
    step = -1 if index == num_rows - 1
    index += step
  }
  l.join()
end
```
