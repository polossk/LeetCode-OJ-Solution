# Jump Game

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Array](https://img.shields.io/badge/数组-Array-007ec6.svg) ![Greedy](https://img.shields.io/badge/贪心-Greedy-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode055-cpp-f34b7d.svg)   | 8 ms    | 8 Mb         |
| ![python](https://img.shields.io/badge/leetcode055-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode055-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

## EXAMPLE 1

```plain
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

## EXAMPLE 2

```plain
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
```

## SOLUTION

* 扫一遍记录能到达的最右端的位置，然后判断是否超过了终点即可

## CODE

### C++

```cpp
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i > rightmost) continue;
            rightmost = max(rightmost, i + nums[i]);
            if (rightmost >= n - 1) return true;
        }
        return false;
    }
};
```

### Python3

```python
import collections

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = collections.defaultdict(list)
        for s in strs:
            ans[tuple(sorted(s))].append(s)
        return ans.values()
```

### Ruby

```ruby
# @param {String[]} strs
# @return {String[][]}
def group_anagrams(strs)
  tmp = Hash.new([])
  strs.each { |s| tmp[s.chars.sort.join("")] += [s] }
  tmp.values
end
```
