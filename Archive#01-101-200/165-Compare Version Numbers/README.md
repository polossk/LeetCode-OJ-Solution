# Compare Version Numbers

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode165-cpp-f34b7d.svg)   | 0 ms    | 6.3 Mb       |
| ![python](https://img.shields.io/badge/leetcode165-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode165-rb-701516.svg)   | -       | -            |
| ![java](https://img.shields.io/badge/leetcode165-java-b07219.svg) | -       | -            |

## DESCRIPTION

Compare two version numbers *version1* and *version2*.
If `version1 > version2` return `1`; if `version1 < version2` return `-1`; otherwise return `0`.

You may assume that the version strings are non-empty and contain only digits and the `.` character.

The `.` character does not represent a decimal point and is used to separate number sequences.

For instance, `2.5` is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be `0`. For example, version number `3.4` has a revision number of `3` and `4` for its first and second level revision number. Its third and fourth level revision number are both `0`.

## EXAMPLE 1

```plain
Input: version1 = "0.1", version2 = "1.1"
Output: -1
```

## EXAMPLE 2

```plain
Input: version1 = "1.0.1", version2 = "1"
Output: 1
```

## EXAMPLE 3

```plain
Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
```


## EXAMPLE 4:

```
Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”
```


## EXAMPLE 5:

```
Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"
```

## NOTE

* Version strings are composed of numeric strings separated by dots `.` and this numeric strings **may** have leading zeroes.
* Version strings do not start or end with dots, and they will not be two consecutive dots.

## FOLLOW UP

* Can you solve it without using extra space?


## SOLUTION

* 将版本号按 `.` 分隔，然后依次对比即可

## CODE

### C++

```cpp
class Solution
{
    vector<string> split(const string &str, char sep)
    {
        vector<string> ret;
        if (str.empty()) return ret;
        stringstream iss(str);
        for (string _; getline(iss, _, sep); ret.push_back(_));
        return ret;
    }
public:
    int compareVersion(string version1, string version2)
    {
        vector<string> _1 = split(version1, '.');
        vector<string> _2 = split(version2, '.');
        auto modifier = [&](const vector<string>& in, vector<int>& out) -> void
        {
            transform(in.begin(), in.end(), out.begin(),
                [](string s) -> int { return atoi(s.c_str()); });
        };
        vector<int> v1(_1.size()), v2(_2.size());
        modifier(_1, v1); modifier(_2, v2);
        int sz1 = _1.size(), sz2 = _2.size();
        int sz = std::max(sz1, sz2);
        for (int i = 0; i < sz; i++)
        {
            int a = i < sz1 ? v1[i] : 0;
            int b = i < sz2 ? v2[i] : 0;
            if (a != b) return a > b ? 1 : -1;
        }
        return 0;
    }
};
```

### Python3


### Ruby


### Java

