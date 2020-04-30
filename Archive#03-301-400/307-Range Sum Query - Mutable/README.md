# Range Sum Query - Mutable

![Medium](../../materials/-Medium-f0ad4e.svg) ![Binary_Indexed_Tree](../../materials/树状数组-Binary_Indexed_Tree-007ec6.svg) ![Segment_Tree](../../materials/线段树-Segment_Tree-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode307-cpp-f34b7d.svg)   | 40 ms   | 16.9 Mb      |
| ![python](https://img.shields.io/badge/leetcode307-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode307-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an integer array `nums`, find the sum of the elements between indices `i` and `j` (`i ≤ j`), inclusive.

The `update(i, val)` function modifies `nums` by updating the element at index `i` to `val`.

## EXAMPLE 1

```plain
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
```

## NOTE

1. The array is only modifiable by the *update* function.
2. You may assume the number of calls to *update* and *sumRange* function is distributed evenly.

## SOLUTION

* 树状数组模板题

## CODE

### C++

```cpp
class NumArray {
    vector<int> tree_;
    vector<int> arr_;
    int maxn_, _cap_;

    inline int lowbit(int x) { return x & (-x); }

    inline void add(int idx, int val)
    {
        for (int i = idx; i <= maxn_; i += lowbit(i))
        {
            tree_[i] += val;
        }
        arr_[idx] += val;
    }

    inline int get(int idx)
    {
        int sum = 0;
        for (int i = idx; i > 0; i -= lowbit(i))
            sum += tree_[i];
        return sum;
    }

public:
    NumArray(vector<int> &nums)
    {
        maxn_ = nums.size();
        _cap_ = maxn_ + 5;
        tree_.resize(_cap_); arr_.resize(_cap_);
        fill(tree_.begin(), tree_.end(), 0);
        fill(arr_.begin(), arr_.end(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            add(i + 1, nums[i]);
            arr_[i + 1] = nums[i];
        }
    }

    void update(int i, int val)
    {
        add(i + 1, val - arr_[i + 1]);
    }

    int sumRange(int i, int j)
    {
        return get(j + 1) - get(i);
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
```

### Python3

```python
```

### Ruby

### Java
