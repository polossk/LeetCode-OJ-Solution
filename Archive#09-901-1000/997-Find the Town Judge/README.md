# Find the Town Judge

![Easy](../../materials/-Easy-5cb85c.svg) ![Graph](../../materials/图-Graph-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode997-cpp-f34b7d.svg)   | 348 ms  | 61 Mb        |
| ![python](https://img.shields.io/badge/leetcode997-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode997-rb-701516.svg)   | -       | -            |

## DESCRIPTION

In a town, there are `N` people labelled from `1` to `N`.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

1. The town judge trusts nobody.
2. Everybody (except for the town judge) trusts the town judge.
3. There is exactly one person that satisfies properties 1 and 2.

You are given `trust`, an array of pairs `trust[i] = [a, b]` representing that the person labelled `a` trusts the person labelled `b`.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return `-1`.

## NOTE

1. `1 <= N <= 1000`
2. `trust.length <= 10000`
3. `trust[i]` are all different
4. `trust[i][0] != trust[i][1]`
5. `1 <= trust[i][0], trust[i][1] <= N`

## EXAMPLE 1

```plain
Input: N = 2, trust = [[1,2]]
Output: 2
```

## EXAMPLE 2

```plain
Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
```

## EXAMPLE 3

```plain
Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```

## EXAMPLE 4

```plain
Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
```

## EXAMPLE 5

```plain
Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
```

## SOLUTION

* 建立有向图，A 信任 B 相当于在 AB 之间有一条有向边
* 小镇法官被 `N-1` 个人（小镇上的所有人）信任，且他自己不信任任何人，对应的是出度为 0，入度为 `N-1`，所以统计出入度即可

## CODE

### C++

```cpp
class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<int> in(N + 1, 0), out(N + 1, 0);
        int ret = 1;
        for (int i = 0, sz = trust.size(); i < sz; i++)
        {
                int a = trust[i][0], b = trust[i][1];
                in[b]++;
                out[a]++;
                ret = in[ret] < in[b] ? b : ret;
        }
        return (in[ret] == N - 1 && out[ret] == 0) ? ret : -1;
    }
};
```

### Python3

### Ruby

### Java
