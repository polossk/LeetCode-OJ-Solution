# 数组中的逆序对

![Hard](https://img.shields.io/badge/-Hard-e05d44.svg) ![MergeSort](https://img.shields.io/badge/归并排序-MergeSort-009688.svg)

## RESULT

| Submission                                                  | Runtime | Memory Usage |
| ----------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/cof51-cpp-f34b7d.svg)   | 716 ms  | 107.4 Mb     |
| ![python](https://img.shields.io/badge/cof51-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/cof51-rb-701516.svg)   | -       | -            |

## DESCRIPTION

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

## EXAMPLE

```plain
输入: [7,5,6,4]
输出: 5
```

## CONSTRAINTS

`0 <= 数组长度 <= 50000`

## SOLUTION

* 归并排序。将数组一分为二，最终答案显然等于只考虑左半部分的逆序对，只考虑右半部分的逆序对，和跨分界线的逆序对。对于左右部分，分别递归处理即可。对于跨分界线部分，新建两个指针同时从各自的头部开始查询是否满足 `i < j && nums[i] > nums[j]` 定义即可。

## CODE

### C++

```cpp
class Solution
{
    int merge_sort(vector<int>::iterator first, vector<int>::iterator last)
    {
        if (last - first <= 1) return 0;
        auto mid = first + (last - first) / 2;
        int ret = merge_sort(first, mid) + merge_sort(mid, last);
        for (auto i = first, j = mid; i != mid; i++)
        {
            while (j != last && ( (*i) > (*j) ) ) j++;
            ret += j - mid;
        }
        std::inplace_merge(first, mid, last);
        return ret;
    }
public:
    int reversePairs(vector<int>& nums)
    {
        return merge_sort(nums.begin(), nums.end());
    }
};
```

### Python3

### Ruby

### Java
