# Trapping Rain Water

![Hard](../../materials/-Hard-e05d44.svg) ![Array](../../materials/数组-Array-007ec6.svg) ![Two_Pointers](../../materials/双指针法-Two_Pointers-007ec6.svg) ![Stack](../../materials/堆栈-Stack-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode042-cpp-f34b7d.svg)   | 12 ms   | 6.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode042-py-3572A5.svg) | 148 ms  | 14.3 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode042-rb-701516.svg)   | 32 ms   | 9.8 Mb       |

## DESCRIPTION

Given *n* non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

## EXAMPLE

```plain
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```

## SOLUTION

* 维护一个单调栈，该单调栈满足单调递减（栈顶元素永远是当前堆栈中最小的元素）。如果当前的条形块小于等于栈顶的条形块，我们将条形块的索引入栈，意思是当前的条形块被栈中的前一个条形块界定。如果我们发现一个条形块长于栈顶，我们可以确定栈顶的条形块被当前条形块和栈的前一个条形块界定，因此我们可以弹出栈顶元素并且累加答案

## CODE

### C++

```cpp
class Solution
{
public:
    int trap(vector<int>& height)
    {
        int ans = 0, cur = 0;
        stack<int> s;
        while (cur < height.size())
        {
            while (!s.empty() && height[cur] > height[s.top()])
            {
                int top = s.top(); s.pop();
                if (s.empty()) break;
                int well_width = cur - s.top() - 1;
                int well_depth = min(height[cur], height[s.top()]) - height[top];
                ans += well_width * well_depth;
            }
            s.push(cur++);
        }
        return ans;
    }
};
```

### Python3

```python
class Solution:
    def trap(self, height: List[int]) -> int:
        ans, cur, stk = 0, 0, []
        while cur < len(height):
            while len(stk) != 0 and height[cur] > height[stk[-1]]:
                top, stk = stk[-1], stk[:-1]
                if len(stk) == 0: break
                width = cur - stk[-1] - 1
                depth = min(height[cur], height[stk[-1]]) - height[top]
                ans += width * depth
            stk.append(cur)
            cur += 1
        return ans
```

### Ruby

```ruby
# @param {Integer[]} height
# @return {Integer}
def trap(height)
  ans, cur, stk = 0, 0, []
  while cur < height.length do
    while stk.length > 0 && height[cur] > height[stk[-1]] do
      top = stk.delete_at(-1)
      if stk.length == 0 then
        break
      end
      width = cur - stk[-1] - 1
      depth = [height[cur], height[stk[-1]]].min - height[top]
      ans += width * depth
    end
    stk << cur
    cur += 1
  end
  ans
end
```
