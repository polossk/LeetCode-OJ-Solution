# Perform String Shifts

![Easy](../../materials/-Easy-5cb85c.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Math](../../materials/数学-Math-007ec6.svg) 

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1427-cpp-f34b7d.svg)   | 4 ms    | 6.7 Mb       |
| ![python](https://img.shields.io/badge/leetcode1427-py-3572A5.svg) | 36 ms   | 13.7 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode1427-rb-701516.svg)   | 28 ms   | 9.3 Mb       |

## DESCRIPTION

You are given a string `s` containing lowercase English letters, and a matrix `shift`, where `shift[i] = [direction, amount]`:

* `direction` can be `0` (for left shift) or `1` (for right shift). 
* `amount` is the amount by which string `s` is to be shifted.
* A left shift by 1 means remove the first character of `s` and append it to the end.
* Similarly, a right shift by 1 means remove the last character of `s` and add it to the beginning.

Return the final string after all operations.

## EXAMPLE 1

```plain
Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"
```

## EXAMPLE 2

```plain
Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
```

## CONSTRAINTS

* `1 <= s.length <= 100`
* `s` only contains lower case English letters.
* `1 <= shift.length <= 100`
* `shift[i].length == 2`
* `0 <= shift[i][0] <= 1`
* `0 <= shift[i][1] <= 100`

## SOLUTION

* 预处理 `shift` 表，然后移动字符即可

## CODE

### C++

```cpp
class Solution
{
public:
    string stringShift(string s, vector<vector<int>>& shift)
    {
        int sz = s.size();
        int movement = accumulate(shift.begin(), shift.end(), 0,
            [](int _1, const vector<int> &_2)->int
            {
                return _1 + (_2[0] == 1 ? _2[1] : -_2[1]);
            });
        movement = (movement % sz + sz) % sz;
        if (movement == 0) return s;
        movement = sz - movement;
        return s.substr(movement) + s.substr(0, movement);
    }
};
```

### Python3

```python
class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        movement = sum((d * 2 - 1) * v for d, v in shift) % len(s)
        if movement == 0:
            return s
        else:
            return s[-movement:] + s[:-movement]
```

### Ruby

```ruby
# @param {String} s
# @param {Integer[][]} shift
# @return {String}
def string_shift(s, shift)
  sz = s.length()
  movement = shift.map {|e| e[0] == 1 ? e[1] : -e[1] }.inject(:+) % sz
  return s if movement == 0
  s[-movement..-1] + s[0...-movement]
end
```