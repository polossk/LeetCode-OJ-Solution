# Count of Range Sum

![Hard](https://img.shields.io/badge/-Hard-e05d44.svg) ![Binary_Search](https://img.shields.io/badge/二分查找-Binary_Search-007ec6.svg) ![Divide_and_Conquer](https://img.shields.io/badge/分治法-Divide_and_Conquer-007ec6.svg) ![Sort](https://img.shields.io/badge/排序-Sort-007ec6.svg) ![Binary_Indexed_Tree](https://img.shields.io/badge/树状数组-Binary_Indexed_Tree-007ec6.svg) ![Segment_Tree](https://img.shields.io/badge/线段树-Segment_Tree-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode307-cpp-f34b7d.svg)   | 112 ms  | 11.2 Mb      |
| ![python](https://img.shields.io/badge/leetcode307-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode307-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an integer array `nums`, return the number of range sums that lie in `[lower, upper]` inclusive.
Range sum `S(i, j)` is defined as the sum of the elements in `nums` between indices `i` and `j` `(i ≤ j)`, inclusive.

## EXAMPLE

```plain
Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```

## NOTE

A naive algorithm of *O(n^2)* is trivial. You MUST do better than that.

## SOLUTION

* 维护一个前缀和，记录前缀和对应下标，然后二分搜索

## CODE

### C++

```cpp
class Solution
{
    multimap<int64_t, int> _hash;
    vector<int64_t> _prefix;
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        _hash.clear(); _prefix.clear();
        _prefix.push_back(0);
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            _prefix.push_back(_prefix.back() + nums[i]);
            _hash.insert({_prefix.back(), i + 1});
        }
        int ret = 0;
        for (int i = 0, sz = _prefix.size(); i < sz; i++)
        {
            int64_t hoge = _prefix[i];
            for (auto it = _hash.lower_bound(hoge + lower);
                it != _hash.end() && it -> first <= hoge + upper; it++ )
                if (it -> second > i)
                    ret++;
        }
        return ret;
    }
};
```

### Python3

```python
```

### Ruby

### Java
