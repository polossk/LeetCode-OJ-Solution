# Permutations

![Medium](../../materials/-Medium-f0ad4e.svg) ![Backtracking](../../materials/回溯法-Backtracking-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode046-cpp-f34b7d.svg)   | 8 ms    | 6.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode046-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode046-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a collection of **distinct** integers, return all possible permutations.

## EXAMPLE

```plain
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

## SOLUTION

* 从给定数组首部开始递归添加元素，然后交换元素即可

## CODE

### C++

```cpp
class Solution
{
    void backtrack(vector<vector<int>> &host, vector<int> &pool,
        int cnt, int len)
    {
        if (cnt == len)
        {
            host.emplace_back(pool);
            return;
        }
        for (int i = cnt; i < len; i++)
        {
            std::swap(pool[i], pool[cnt]);
            backtrack(host, pool, cnt + 1, len);
            std::swap(pool[i], pool[cnt]);
        }
    }
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ret;
        backtrack(ret, nums, 0, nums.size());
        return ret;
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
