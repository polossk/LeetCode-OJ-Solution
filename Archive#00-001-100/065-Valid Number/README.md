# Valid Number

![Hard](https://img.shields.io/badge/-Hard-e05d44.svg) ![Math](https://img.shields.io/badge/数学-Math-007ec6.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode031-cpp-f34b7d.svg)   | 0 ms    | 6.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode031-py-3572A5.svg) | 36 ms   | 14 Mb        |
| ![ruby](https://img.shields.io/badge/leetcode031-rb-701516.svg)   | 48 ms   | 9.3 Mb       |

## DESCRIPTION

Validate if a given string can be interpreted as a decimal number.

Some examples:

```plain
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
```

## NOTE

It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

* Numbers 0-9
* Exponent - "e"
* Positive/negative sign - "+"/"-"
* Decimal point - "."

Of course, the context of these characters also matters in the input.

**Update (2015-02-10):**

The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

## SOLUTION

* 处理好 note 中的所有细节，即，正负号（可能出现在指数位 `1e-2`），小数点（不允许多个小数点），科学计数法标记（只允许小写字符 `e`）
* 也可以当作正则表达式的练习题，匹配序列为 `^[\ ]*[+-]?(\d+\.?\d*|\d*\.?\d+)(e[+-]?\d+)?[\ ]*$`

## CODE

### C++

```cpp
class Solution
{
public:
    bool isNumber(string s)
    {
        int dot = 0, dgt = 0, idx = 0;
        while (s[idx] == ' ') idx++;
        if (s[idx] == '+' || s[idx] == '-') idx++;
        for (; isdigit(s[idx]) || s[idx] == '.'; )
            s[idx++] == '.' ? dot++ : dgt++;
        if (dot > 1 || dgt < 1) return false;
        if (s[idx] == 'e')
        {
            idx++; dgt = 0;
            if (s[idx] == '+' || s[idx] == '-') idx++;
            for (; isdigit(s[idx]); dgt++, idx++);
            if (dgt < 1) return false;
        }
        while (s[idx] == ' ') idx++;
        return idx == s.size();
    }
};
```

### Python3

```python
import re

class Solution:
    hoge = re.compile("^[\ ]*[+-]?(\d+\.?\d*|\d*\.?\d+)(e[+-]?\d+)?[\ ]*$")
    
    def isNumber(self, s: str) -> bool:
        return bool(self.hoge.match(s))
```

### Ruby

```ruby
# @param {String} s
# @return {Boolean}
def is_number(s)
  /\s*[+-]?(\d+\.\d+|\d+\.?|\.\d+)([eE][+-]?\d+)?\s*/.match(s).to_s == s and s.length > 0
end
```

### Java
