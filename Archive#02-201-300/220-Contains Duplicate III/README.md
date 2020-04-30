# Contains Duplicate III

![Medium](../../materials/-Medium-f0ad4e.svg) ![Sort](../../materials/排序-Sort-007ec6.svg) ![Ordered_Map](../../materials/保序映射-Ordered_Map-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode220-cpp-f34b7d.svg)   | 32 ms   | 9 Mb         |
| ![python](https://img.shields.io/badge/leetcode220-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode220-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the **absolute** difference between `nums[i]` and `nums[j]` is at most t and the **absolute** difference between i and j is at most k.

## EXAMPLE 1

```plain
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
```

## EXAMPLE 2

```plain
Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
```

## EXAMPLE 3

```plain
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
```

## SOLUTION

* 维护一个检索树（红黑树、平衡树、`treap`、`std::set` 都可以），去检索符合条件的值即可

## CODE

### C++

```cpp
class Solution
{
    using int64 = long long;
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        set<int64> table;
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            if (i > k) table.erase(nums[i - k - 1]);
            auto pos = table.lower_bound(nums[i] - int64(t));
            if (pos != table.end() && *pos - nums[i] <= t) return true;
            table.insert(nums[i]);
        }
        return false;
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```
