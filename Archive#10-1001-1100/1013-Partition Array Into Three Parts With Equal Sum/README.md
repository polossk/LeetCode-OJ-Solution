# Partition Array Into Three Parts With Equal Sum

![Easy](../../materials/-Easy-5cb85c.svg) ![Array](../../materials/数组-Array-007ec6.svg)

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1013-cpp-f34b7d.svg)   | 64 ms   | 12 Mb        |
| ![python](https://img.shields.io/badge/leetcode1013-py-3572A5.svg) | 344 ms  | 19.4 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode1013-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an array `A` of integers, return `true` if and only if we can partition the array into three **non-empty** parts with equal sums.

Formally, we can partition the array if we can find indexes `i+1 < j` with `(A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])`

## EXAMPLE 1

```plain
Input: A = [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true
Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
```

## EXAMPLE 2

```plain
Input: A = [0,2,1,-6,6,7,9,-1,2,0,1]
Output: false
```

## EXAMPLE 3

```plain
Input: A = [3,3,6,5,-2,2,5,1,-9,4]
Output: true
Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
```

## CONSTRAINTS

* `3 <= A.length <= 50000`
* `-10^4 <= A[i] <= 10^4`

## SOLUTION

* 切分成三个数值和相同的子数组等价于要求原数组的和可以被三整除，且每一个新数组的和为其三分之一
* 通过求前缀和然后直接线性扫一遍查找 sum/3 和 sum/3*2 即可
* 实际上不需要完整的前缀和数组，所以只维护一个当前前缀和即可

## CODE

### C++

```cpp
class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &A)
    {
        int s = accumulate(A.begin(), A.end(), 0);
        if (s % 3 != 0) return false;
        int target = s / 3, current = 0;
        int i = 0, sz = A.size();
        while (i < sz)
        {
            current += A[i++];
            if (current == target) break;
        }
        if (current != target) return false;
        current = 0;
        while (i + 1 < sz)
        {
            current += A[i++];
            if (current == target) break;
        }
        return current == target;
    }
};
```

### Python3

```python
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s = sum(A)
        if s % 3 != 0: return False
        s //= 3
        current, flag = 0, 0
        for i, e in enumerate(A):
            current += e
            if flag == 0:
                flag = 1 if current == s else 0
            elif flag == 1:
                if current == s * 2 and i + 1 < len(A):
                    return True
        return False
```

### Ruby

