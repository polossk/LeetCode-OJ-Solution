# Jump Game II

![Hard](../../materials/-Hard-e05d44.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Greedy](../../materials/贪心-Greedy-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode045-cpp-f34b7d.svg)   | 20 ms   | 13.4 Mb      |
| ![python](https://img.shields.io/badge/leetcode045-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode045-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

## NOTE

You can assume that you can always reach the last index.

## EXAMPLE

```plain
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

## SOLUTION

* 从左往右扫一遍，维护当前所能到达的最大值，如果走到了这个最大值，则更新步数和新的能走到的最大值

## CODE

### C++

```cpp
class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int ret = 0, right_most = 0, end_point = 0;
        for (int i = 0, sz = nums.size(); i < sz - 1; i++)
        {
            right_most = std::max(right_most, nums[i] + i);
            if (i == end_point) { end_point = right_most; ret++; }
        }
        return ret;
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```
