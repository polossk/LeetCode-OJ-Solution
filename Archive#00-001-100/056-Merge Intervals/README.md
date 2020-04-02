# Merge Intervals

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Array](https://img.shields.io/badge/数组-Array-007ec6.svg) ![Sort](https://img.shields.io/badge/排序-Sort-007ec6.svg)
## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode056-cpp-f34b7d.svg)   | 24 ms   | 11 Mb        |
| ![python](https://img.shields.io/badge/leetcode056-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode056-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a collection of intervals, merge all overlapping intervals.

## EXAMPLE 1

```plain
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

## EXAMPLE 2

```plain
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

## NOTE

input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

## SOLUTION

* 重力合并法。不妨假设区间 `[a, b]` 是由 `(b-a+1)` 个 1 立方米的积木组成的一个长条，我们将所有的区间都想象成这样的长条，然后将这些长条从高度 0 开始放置，这时候给一个重力场，所有下方没有支撑的积木就会自由落体到高度 0 的水平面，最后从左到右扫描一遍高度 0 的水平面就可以统计出所有的合并区间。
* 对区间预先离散化，然后用重力法扫描一遍即可

## CODE

### C++

```cpp
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        ios::sync_with_stdio(false);
        int sz = intervals.size();
        if (sz <= 1) return intervals;
        vector<int> values;
        unordered_set<int> singluar;
        unordered_map<int, int> index;
        vector<vector<int>> ret;
        for (int i = 0; i < sz; i++)
        {
            values.push_back(intervals[i][0]);
            values.push_back(intervals[i][1]);
            if (intervals[i][0] == intervals[i][1])
                singluar.insert(intervals[i][0]);
        }
        std::sort(values.begin(), values.end());
        auto last = std::unique(values.begin(), values.end());
        values.erase(last, values.end());
        int vsz = values.size();
        vector<int> pool(vsz, 0);
        for (int i = 0; i < vsz; i++)
            index[values[i]] = i;
        for (int i = 0; i < sz; i++)
        {
            pool[ index[ intervals[i][0] ] ]++;
            pool[ index[ intervals[i][1] ] ]--;
        }
        bool notemptyflag = !singluar.empty();
        for (int i = 0, left = 0, height = 0; i < vsz; i++)
        {
            if (pool[i] > 0)
            {
                if (height == 0) { left = i; }
                height += pool[i];
            }
            else if (pool[i] < 0)
            {
                if (height + pool[i] == 0)
                {
                    ret.emplace_back(std::initializer_list<int>{values[left], values[i]});
                    left = 0;
                }
                height += pool[i];
            }
            else // pool[i] == 0
            {
                if (height != 0) continue;
                if (notemptyflag && singluar.find(values[i]) != singluar.end())
                {
                    ret.emplace_back(2, values[i]);
                }
            }
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

### Java

```java
```
