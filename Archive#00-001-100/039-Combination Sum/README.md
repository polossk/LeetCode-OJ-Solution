# Combination Sum

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Array](https://img.shields.io/badge/-Array-007ec6.svg) ![Backtracking](https://img.shields.io/badge/-Backtracking-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode039-cpp-f34b7d.svg)   | 12 ms   | 9.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode039-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode039-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a **set** of candidate numbers (`candidates`) **(without duplicates)** and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.

The **same** repeated number may be chosen from `candidates` unlimited number of times.

## NOTE

* All numbers (including target) will be positive integers.
* The solution set must not contain duplicate combinations.

## EXAMPLE 1:

```plain
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
```

## Example 2:

```plain
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
```

## SOLUTION

* DFS

## CODE

### C++

```cpp
class Solution {
private:
    vector<vector<int>> ret;

    void dfs(const vector<int>& candidates, vector<int>& tmp, int start, int residual)
    {
        if (residual == 0) { ret.push_back(tmp); return; }
        for (int i = start, sz = candidates.size();
            i < sz && candidates[i] <= residual; i++)
        {
            tmp.push_back(candidates[i]);
            dfs(candidates, tmp, i, residual - candidates[i]);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        // std::sort(candidates.begin(), candidates.end(), std::less<int>());
        std::sort(candidates.begin(), candidates.end());
        vector<int> ans;
        dfs(candidates, ans, 0, target);
        return ret;
    }
};
```

### Python3

### Ruby

### Java
