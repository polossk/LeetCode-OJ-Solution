# Evaluate Reverse Polish Notation

![Medium](../../materials/-Medium-f0ad4e.svg) ![Stack](../../materials/堆栈-Stack-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode150-cpp-f34b7d.svg)   | 12 ms   | 11.7 Mb      |
| ![python](https://img.shields.io/badge/leetcode150-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode150-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are `+`, `-`, `*`, `/`. Each operand may be an integer or another expression.

## NOTE

* Division between two integers should truncate toward zero.
* The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

## EXAMPLE 1

```plain
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```

## EXAMPLE 2

```plain
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
```

## EXAMPLE 3

```plain
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

## SOLUTION

* 堆栈模拟基础

## CODE

### C++

```cpp
class Solution {
    map<string, std::function<int(int, int)>> op
    {
        {"+", [](int a, int b)->int { return a + b; }},
        {"-", [](int a, int b)->int { return a - b; }},
        {"*", [](int a, int b)->int { return a * b; }},
        {"/", [](int a, int b)->int { return a / b; }},
    };

public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> host;
        for (auto &str : tokens)
        {
            if (op.count(str))
            {
                int rhs = host.top(); host.pop();
                int lhs = host.top(); host.pop();
                host.push(op[str](lhs, rhs));
            }
            else host.push(atoi(str.c_str()));
        }
        return host.top();
    }
};
```

### Python3

### Ruby
