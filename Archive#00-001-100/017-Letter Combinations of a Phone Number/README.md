# Letter Combinations of a Phone Number

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg) ![Backtracking](https://img.shields.io/badge/回溯法-Backtracking-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode017-cpp-f34b7d.svg)   | 8 ms    | 9.0 Mb       |
| ![python](https://img.shields.io/badge/leetcode017-py-3572A5.svg) | 36 ms   | 13.1 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode017-rb-701516.svg)   | 36 ms   | 9.9 Mb       |

## DESCRIPTION

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

## EXAMPLE

```plain
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
```

## NOTE

Although the above answer is in lexicographical order, your answer could be in any order you want.

## SOLUTION

1. 外部构造一个字典
2. 然后对每一个数字查询对应的字母
3. 用笛卡儿积缩并

## CODE

### C++

```cpp
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size == 0) return vector<string>();
        return __dfs(digits);
    }

private:
    map<char, vector<string>> __keyboard_ = {
        {'2', vector<string>{"a", "b", "c"}}, {'3', vector<string>{"d", "e", "f"}},
        {'4', vector<string>{"g", "h", "i"}}, {'5', vector<string>{"j", "k", "l"}},
        {'6', vector<string>{"m", "n", "o"}}, {'7', vector<string>{"p", "q", "r", "s"}},
        {'8', vector<string>{"t", "u", "v"}}, {'9', vector<string>{"w", "x", "y", "z"}},
    };

    vector<string> __dfs(const string &digits)
    {
        if (digits.size() == 1)
            return __keyboard_[digits[0]];
        else
            return __deal(__keyboard_[digits[0]], __dfs(digits.substr(1)));
    }

    vector<string> __deal(const vector<string> &a, const vector<string> &b)
    {
        vector<string> ret;
        for (int i = 0, isz = a.size(); i < isz; i++)
            for (int j = 0, jsz = b.size(); j < jsz; j++)
                ret.push_back(a[i] + b[j]);
        return ret;
    }
};
```

### Python3

```python
from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        return [] if len(digits) == 0 else self.__dfs(digits)

    def __dfs(self, digits: str) -> List[str]:
        return self.__mapping[digits] if len(digits) == 1 else [
            s_1 + _2 for _1 in self.__mapping[digits[0]]
            for _2 in self.__dfs(digits[1:])
        ]

    __mapping = {
        '2': ["a", "b", "c"],
        '3': ["d", "e", "f"],
        '4': ["g", "h", "i"],
        '5': ["j", "k", "l"],
        '6': ["m", "n", "o"],
        '7': ["p", "q", "r", "s"],
        '8': ["t", "u", "v"],
        '9': ["w", "x", "y", "z"],
    }
```

### Ruby

```ruby
# @param {String} digits
# @return {String[]}
def letter_combinations(digits)
  return Array.new() if digits.length == 0
  return dfs(digits)
end

def dfs(digits)
  if digits.length <= 1
    $mapping[digits]
  else
    cartProd($mapping[digits[0]], dfs(digits[1..digits.length]))
  end
end

def cartProd(a, b)
  a.product(b).map{ |a| a.join() }
end

$mapping = {
  '2' => ["a", "b", "c"],
  '3' => ["d", "e", "f"],
  '4' => ["g", "h", "i"],
  '5' => ["j", "k", "l"],
  '6' => ["m", "n", "o"],
  '7' => ["p", "q", "r", "s"],
  '8' => ["t", "u", "v"],
  '9' => ["w", "x", "y", "z"],
}
```
