# Last Stone Weight

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Heap](https://img.shields.io/badge/堆-Heap-007ec6.svg) ![Greedy](https://img.shields.io/badge/贪心-Greedy-007ec6.svg)

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1046-cpp-f34b7d.svg)   | 0 ms    | 6 Mb         |
| ![python](https://img.shields.io/badge/leetcode1046-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode1046-rb-701516.svg)   | -       | -            |

## DESCRIPTION

We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two **heaviest** stones and smash them together.  Suppose the stones have weights `x` and `y` with `x <= y`.  The result of this smash is:

* If `x == y`, both stones are totally destroyed;
* If `x != y`, the stone of weight `x` is totally destroyed, and the stone of weight `y` has new weight `y-x`.

At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

## EXAMPLE 1

```plain
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
```

## NOTE

* `1 <= stones.length <= 30`
* `1 <= stones[i] <= 1000`

## SOLUTION

* 用堆来维护最大石头即可

## CODE

### C++

```cpp
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (int v : stones) pq.push(v);
        while (pq.size() >= 2)
        {
            int top1 = pq.top(); pq.pop();
            int top2 = pq.top(); pq.pop();
            int v = abs(top1 - top2);
            if (v) pq.push(v);
        }
        return pq.size() == 1 ? pq.top() : 0;
    }
};
```

### Python3

```python
```

### Ruby

