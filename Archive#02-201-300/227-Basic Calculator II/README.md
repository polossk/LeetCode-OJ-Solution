# Basic Calculator II

![Medium](../../materials/-Medium-f0ad4e.svg) ![String](../../materials/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode224-cpp-f34b7d.svg)   | 12 ms   | 7.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode224-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode224-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only **non-negative** integers, `+`, `-`, `*`, `/` operators and empty spaces ` `. The integer division should truncate toward zero.

## EXAMPLE 1

```plain
Input: "3+2*2"
Output: 7
```

## EXAMPLE 2

```plain
Input: " 3/2 "
Output: 1
```

## EXAMPLE 3

```plain
Input: " 3+5 / 2 "
Output: 5
```

## NOTE

* You may assume that the given expression is always valid.
* **Do not** use the eval built-in library function.

## SOLUTION

* 维护两个堆栈，一个储存数字，另一个储存算符

## CODE

### C++

```cpp
class Solution
{
public:
	int calculate(string s)
	{
		if (s.size() < 1) return 0;
		auto ch2i = [](char ch) -> int { return ch - '0'; };
		int sign = 1, ret = 0, top = 0, tmp = 0;
		char last = '+';

		for (int i = 0, sz = s.size(); i <= sz; )
		{
			if (isspace(s[i])) { i++; continue; }
			if (s[i] == '-' || s[i] == '+' || !s[i])
			{
				ret += top * sign;
				last = s[i++];
				sign = last == '+' ? 1 : -1;
				top = 1;
			}
			else if (s[i] == '*' || s[i] == '/')
			{
				last = s[i++];
			}
            if (i >= sz) break;
			if (isdigit(s[i]))
			{
				tmp = 0;
				while (i < sz && isdigit(s[i]))
					tmp = tmp * 10 + ch2i(s[i++]);
				if (last == '*') top *= tmp;
				else if (last == '/') top /= tmp;
				else top = tmp; 
			}
		}
		return ret;
	}
};
```

### Python3

```python
```

### Ruby

```ruby
```

### Java
