# Different Ways to Add Parentheses

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Divide_and_Conquer](https://img.shields.io/badge/分治法-Divide_and_Conquer-007ec6.svg)
## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode241-cpp-f34b7d.svg)   | 4 ms    | 13.6 Mb      |
| ![python](https://img.shields.io/badge/leetcode241-py-3572A5.svg) | 40 ms   | 13.1 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode300-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are `+`, `-` and `*`.

## EXAMPLE 1

```plain
Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2
```

## EXAMPLE 2

```plain
Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
```

## SOLUTION

* 分治法。对表达式中的每一个符号，按该符号为中间点，递归计算左边与右边表达式的结果。而对每一个新表达式，也同样继续递归处理。
* C/C++ 中有一些函数来执行字符类别的判断，如 `isalpha` 大小写字母，`isupper` 大写字母，`islower` 小写字母，`ispunct` 连接字符，`isdigit` 数字字符等，也有函数来执行字符串到数字的转换，如 `stoi` 与 `atoi`。


## CODE

### C++

```cpp
class Solution
{
public:
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> output;
        for (int i = 0, sz = input.size(); i < sz; i++)
        {
            if (ispunct(input[i]))
                for (int a : diffWaysToCompute(input.substr(0, i)))
                    for (int b : diffWaysToCompute(input.substr(i + 1)))
                        output.push_back(input[i] == '+' ? a + b :
                            input[i] == '-' ? a - b : a * b);
        }
        return output.size() ? output : vector<int>{stoi(input)};
    }
};
```

### Python3

```python
class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        return [a + b if c == '+' else a - b if c == '-' else a * b
            for i, c in enumerate(input) if c in '+-*'
            for a in self.diffWaysToCompute(input[:i])
            for b in self.diffWaysToCompute(input[i+1:])
        ] or [int(input)]
```

### Ruby

### Java
