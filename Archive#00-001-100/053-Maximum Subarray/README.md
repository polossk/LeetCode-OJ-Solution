# Maximum Subarray

![Easy](../../materials/-Easy-5cb85c.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Divide_and_Conquer](../../materials/分治法-Divide_and_Conquer-007ec6.svg) ![Dynamic_Programming](../../materials/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode053-cpp-f34b7d.svg)   | 4 ms    | 6.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode053-py-3572A5.svg) | 116 ms  | 14.6 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode053-rb-701516.svg)   | 68 ms   | 9.8 Mb       |

## DESCRIPTION

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

## EXAMPLE

```plain
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

## FOLLOW UP

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

## SOLUTION

* 贪心扫描一遍。记录一个 `tmp` 变量表示走到数组元素 `elem` 时的子数列之和。保持 `tmp` 也满足当前最大的性质，所以有 `tmp := max(elem, tmp + elem)`，即要么从新开始，要么继续累加
* 注意到状态转移方程的右边可以简化为 `max(0, tmp) + elem`

## CODE

### C++

```cpp
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int sz = nums.size(), ret = 0, tmp = 0;
        if (sz == 0) return ret;
        tmp = ret = nums[0];
        for (int i = 1; i < sz; i++)
        {
            tmp = max(0, tmp) + nums[i];
            ret = max(ret, tmp);
        }
        return ret;
    }
};
```

### Python3

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        tmp, ret = 0, -2**31
        for elem in nums:
            tmp = max(elem, tmp + elem)
            ret = max(ret, tmp)
        return ret
```

### Ruby

```ruby
# @param {Integer[]} nums
# @return {Integer}
def max_sub_array(nums)
  tmp, ret = 0, -2**31
  nums.each { |elem|
    tmp = tmp > 0 ? tmp + elem : elem
    ret = ret > tmp ? ret : tmp
  }
  ret
end
```
