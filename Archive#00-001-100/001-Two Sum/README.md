# Two Sum

![Easy](../../materials/-Easy-5cb85c.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Hash_Table](../../materials/哈希表-Hash_Table-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode001-cpp-f34b7d.svg)   | 8 ms    | 10.0 Mb      |
| ![python](https://img.shields.io/badge/leetcode001-py-3572A5.svg) | 40 ms   | 14.5 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode001-rb-701516.svg)   | 48 ms   | 10.1 Mb      |

## DESCRIPTION

Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have *exactly* one solution, and you may not use the same element twice.

## EXAMPLE

```plain
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

## SOLUTION

* 查找 `x := target - i`，可以用二分查找，或者 Hash 表

## CODE

### C++

```cpp
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> index;
        typedef pair<int, int> Item;
        vector<Item> table;
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            table.push_back(make_pair(nums[i], i));
        }
        sort(table.begin(), table.end(), [](const Item &a, const Item &b) -> bool { return a.first < b.first; });
        sort(nums.begin(), nums.end());
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            int piyo = nums[i];
            if (binary_search(nums.begin(), nums.end(), target - piyo))
            {
                int hoge = lower_bound(nums.begin(), nums.end(), target - piyo) - nums.begin();
                while (hoge == i && nums[hoge] == piyo)
                    hoge++;
                if (piyo + nums[hoge] == target)
                {
                    index.push_back(table[i].second);
                    index.push_back(table[hoge].second);
                    sort(index.begin(), index.end());
                    return index;
                }
            }
        }
        return vector<int>();
    }
};
```

### Python3

```python
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}
        for i, e in enumerate(nums):
            if table.get(e) != None:
                return [table[e], i]
            table[target - e] = i
```

### Ruby

```ruby
# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
  table = {}
  nums.each_with_index { |e, i|
    return [table[e], i] if table.has_key?(e)
    table[target - e] = i
  }
end
```
