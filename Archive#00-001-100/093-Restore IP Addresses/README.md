# Restore IP Addresses

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg) ![Backtracking](https://img.shields.io/badge/回溯法-Backtracking-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode093-cpp-f34b7d.svg)   | 16 ms   | 6.7 Mb       |
| ![python](https://img.shields.io/badge/leetcode093-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode093-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address consists of exactly four integers (each integer is between 0 and 255) separated by single points.

## EXAMPLE

```plain
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
```

## SOLUTION

* 字符串基本处理，深搜检索所有可能数字即可

## CODE

### C++

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12)
            return res;
        dfs(res, "", s, 0);
        return res;
    }

    void dfs(vector<string>& res, string prev, string next, int n)
    {
        if (n == 3 && next.size() <= 3 && judge(next))
        {
            res.push_back(prev + next);
            return;
        }
        for (int i = 1, sz = next.size(); i < 4 && i < sz; i++)
        {
            string nstr = next.substr(0, i);
            if (judge(nstr))
                dfs(res, prev + nstr + ".", next.substr(i), n + 1);
            else continue;
        }
    }

    inline int toNum(string s)
    {
        stringstream buf; buf << s;
        int num; buf >> num;
        return num;
    }

    bool judge(string s)
    {
        if (s[0] == '0') return s == "0";
        // int v = atoi(s.c_str()); // 9ms
        auto str2num = [=](string s)->int{
            stringstream buf; buf << s;
            int ret; buf >> ret;
            return ret;
        };
        int v = str2num(s); // 20 ms
        return v > 0 && v <= 255;
    }

    void _dbg(vector<string> res)
    {
        for (int i = 0, sz = res.size(); i < sz; i++)
            cout << "res[" << i << "] = [" << res[i] << "];" << endl;
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

```java
```
