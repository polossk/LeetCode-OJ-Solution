# Container With Most Water

![Medium](../../materials/-Medium-f0ad4e.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Two_Pointers](../../materials/双指针法-Two_Pointers-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode011-cpp-f34b7d.svg)   | 16 ms   | 7.5 Mb       |
| ![python](https://img.shields.io/badge/leetcode011-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode011-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given *n* non-negative integers *a1*, *a2*, ..., *an*, where each represents a point at coordinate *(i, ai)*. *n* vertical lines are drawn such that the two endpoints of line *i* is at *(i, ai)* and *(i, 0)*. Find two lines, which together with x-axis forms a container, such that the container contains the most water.

## EXAMPLE

```plain
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
```

## NOTE

You may not slant the container and n is at least 2.

## SOLUTION

* 贪心。左右双指针逐渐往中央走，贪心选择保留较大的板。

## CODE

### C++

```cpp
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // if (height.empty()) return 0;
        int i = 0, j = height.size() - 1, ret = 0;
        while (i < j)
        {
            int tmp = std::min(height[i], height[j]) * (j - i);
            ret = std::max(ret, tmp);
            if (height[i] < height[j]) i++;
            else j--;
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
