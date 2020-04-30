# Minimum Increment to Make Array Unique

![Medium](../../materials/-Medium-f0ad4e.svg) ![Array](../../materials/数组-Array-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode945-cpp-f34b7d.svg)   | 76 ms   | 31.1 Mb      |
| ![python](https://img.shields.io/badge/leetcode945-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode945-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an array of integers A, a move consists of choosing any `A[i]`, and incrementing it by 1.

Return the least number of moves to make every value in `A` unique.

## NOTE

1. `0 <= A.length <= 40000`
2. `0 <= A[i] < 40000`

## EXAMPLE 1

```plain
Input: [1,2,2]
Output: 1
Explanation:  After 1 move, the array could be [1, 2, 3].
```

## EXAMPLE 2

```plain
Input: [3,2,1,2,1,7]
Output: 6
Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
```

## SOLUTION

* hash 记录，然后从小到大扫描一遍

## CODE

### C++

```cpp
class Solution
{
    const int MAXV = 2 * 40000 + 10;
public:
    int minIncrementForUnique(vector<int>& A)
    {
        vector<int> hoge(MAXV, 0);
        for (int i = 0, sz = A.size(); i < sz; i++)
            hoge[A[i]]++;
        int ret = 0;
        for (int i = 0; i < MAXV; i++)
        {
            if (hoge[i] <= 1) continue;
            ret += hoge[i] - 1;
            hoge[i + 1] += hoge[i] - 1;
            hoge[i] = 1;
        }
        return ret;
    }
};
```

### Python3

### Ruby

### Java
