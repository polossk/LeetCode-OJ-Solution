# First Bad Version

![Easy](../../materials/-Easy-5cb85c.svg) ![Binary_Search](../../materials/二分查找-Binary_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode278-cpp-f34b7d.svg)   | 0 ms    | 6.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode278-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode278-rb-701516.svg)   | -       | -            |

## DESCRIPTION

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version)` which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

## EXAMPLE

```plain
Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
```

## SOLUTION

* 二分查找即可

## CODE

### C++

```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, right = n;
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
```

### Python3

### Ruby

### Java
