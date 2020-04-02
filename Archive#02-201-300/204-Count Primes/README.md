# Count Primes

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Hash_Table](https://img.shields.io/badge/哈希表-Hash_Table-007ec6.svg) ![Math](https://img.shields.io/badge/数学-Math-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode204-cpp-f34b7d.svg)   | 188 ms  | 39.2 Mb      |
| ![python](https://img.shields.io/badge/leetcode204-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode204-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Count the number of prime numbers less than a non-negative number, **n**.

## EXAMPLE

```plain
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```

## SOLUTION

* 线性筛打表法

## CODE

### C++

```cpp
class Solution {
    const static int MAXN = 10000005;
    int prime[MAXN >> 1];
    bool isPrime[MAXN];
public:
    int countPrimes(int n)
    {
        int cnt = 0;
        fill(isPrime + 2, isPrime + MAXN, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i]) prime[cnt++] = i;
            for (int j = 0; j < cnt & prime[j] * i < n; j++)
            {
                isPrime[prime[j] * i] = false;
                if (!(i % prime[j])) break;
            }
        }
        return cnt;
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```
