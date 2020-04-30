# Maximum Subarray

![Easy](../../materials/-Easy-5cb85c.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Dynamic_Programming](../../materials/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode152-cpp-f34b7d.svg)   | 4 ms    | 6.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode152-py-3572A5.svg) | 108 ms  | 14.1 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode152-rb-701516.svg)   | 64 ms   | 9.6 Mb       |

## DESCRIPTION

Given an integer array `nums`, find the contiguous subarray within an array (containing at least one number) which has the largest product.

## EXAMPLE 1

```plain
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

## EXAMPLE 2

```plain
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

## SOLUTION

* 贪心扫描一遍。乘法与加法的区别在于负负得正，所以不仅需要维护一个正值的最大 `positive`，同时也要维护一个负值的最小 `negative`（负的且绝对值最大）
* 下面考虑需要维护的变量。对于正值的最大，对于每一个元素 `elem` 有需要先去检索累乘上他之后的值的大小，注意到这个值只保留整数，所以状态转义方程可以写成 `positive = max(max(elem * positive, elem * negative), elem)`；与之类似，负值的最小的态转义方程可以写成 `negative = min(min(nagetive * positive, nagetive * negative), nagetive)`
* 最终只检查 `positive` 是否为当前最大值即可

## CODE

### C++

```cpp
class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int sz = nums.size(), ret = 0;
        if (sz == 0) return ret;
        int positive, negative, tmp_p, tmp_n;
        ret = tmp_p = tmp_n = nums[0];
        for (int i = 1; i < sz; i++)
        {
            positive = max(max(nums[i] * tmp_p, nums[i] * tmp_n), nums[i]);
            negative = min(min(nums[i] * tmp_p, nums[i] * tmp_n), nums[i]);
            ret = max(positive, ret);
            tmp_p = positive;
            tmp_n = negative;
        }
        return ret;
    }
};
```

### Python3

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ret, tmp_p, tmp_n = nums[0], nums[0], nums[0]
        for elem in nums[1:]:
            positive = max(max(elem * tmp_p, elem * tmp_n), elem)
            negative = min(min(elem * tmp_p, elem * tmp_n), elem)
            ret = max(positive, ret)
            tmp_p, tmp_n = positive, negative
        return ret
```

### Ruby

```ruby
# @param {Integer[]} nums
# @return {Integer}
def max_product(nums)
  ret, tmp_p, tmp_n = nums[0], nums[0], nums[0]
  nums[1..-1].each { |elem|
    positive = [[elem * tmp_p, elem * tmp_n].max, elem].max
    negative = [[elem * tmp_p, elem * tmp_n].min, elem].min
    ret = ret > positive ? ret : positive
    tmp_p, tmp_n = positive, negative
  }
  ret
end
```
