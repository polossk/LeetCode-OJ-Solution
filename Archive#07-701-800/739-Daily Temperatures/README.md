# Daily Temperatures

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Hash%20Table](https://img.shields.io/badge/-Hash%20Table-007ec6.svg) ![Stack](https://img.shields.io/badge/-Stack-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode739-cpp-f34b7d.svg)   | 192 ms  | 14.9 Mb      |
| ![python](https://img.shields.io/badge/leetcode739-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode739-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a list of daily temperatures `T`, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put `0` instead.

For example, given the list of temperatures` T = [73, 74, 75, 71, 69, 72, 76, 73]`, your output should be `[1, 1, 4, 2, 1, 1, 0, 0]`.

## NOTE

The length of `temperatures` will be in the range `[1, 30000]`. Each temperature will be an integer in the range `[30, 100]`.

## SOLUTION

* 单调栈，维护一个堆栈，使其元素同时保持单调性，也就是说只有满足单调性的元素才能进栈，反之则反复出栈直到保持单调性为止
* 比如依次压入元素 `[3, 5, 9, 2, 6, 1]` 时，单调增堆栈的结果依次为 `[3]`，`[3, 5]`，`[3, 5, 9]`，`[2]`，`[2, 6]`，`[1]`，单调减堆栈的结果以此为 `[3]`，`[5]`，`[9]`，`[9, 2]`，`[9, 6]`，`[9, 6, 1]`

## CODE

### C++

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        stack<int> s;
        int sz = T.size();
        vector<int> ret(sz, 0);
        for (int i = sz - 1; i >= 0; i--)
        {
            while (!s.empty() && T[i] >= T[s.top()]) s.pop();
            ret[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        return ret;
    }
};
```

### Python3

### Ruby

### Java
