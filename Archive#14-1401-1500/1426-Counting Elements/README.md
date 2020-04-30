# Counting Elements

![Easy](../../materials/-Easy-5cb85c.svg) ![Array](../../materials/数组-Array-007ec6.svg)

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1426-cpp-f34b7d.svg)   | 0 ms    | 6.9 Mb       |
| ![python](https://img.shields.io/badge/leetcode1426-py-3572A5.svg) | 80 ms   | 14.1 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode1426-rb-701516.svg)   | 52 ms   | 9.5 Mb       |

## DESCRIPTION

Given an integer array `arr`, count element `x` such that `x + 1` is also in `arr`.

If there're duplicates in `arr`, count them seperately.

## EXAMPLE 1

```plain
Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
```

## EXAMPLE 2

```plain
Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.
```

## EXAMPLE 3

```plain
Input: arr = [1,3,2,3,5,0]
Output: 3
Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
```

## EXAMPLE 4

```plain
Input: arr = [1,1,2,2]
Output: 2
Explanation: Two 1s are counted cause 2 is in arr.
```

## CONSTRAINTS

* `1 <= arr.length <= 1000`
* `0 <= arr[i] <= 1000`

## SOLUTION

* hash 表存个数，然后检索一边即可

## CODE

### C++

```cpp
class Solution
{
    unordered_map<int, int> cnt_;
public:
    int countElements(vector<int>& arr)
    {
        for (auto e : arr) cnt_[e] += 1;
        int ret = 0;
        for (auto it = cnt_.begin(); it != cnt_.end(); it++)
        {
            auto [key, value] = *it;
            auto got = cnt_.find(key + 1);
            if (got != cnt_.end())
                ret += value;
        } 
        return ret;
    }
};
```

### Python3

```python
class Solution:
    def countElements(self, arr: List[int]) -> int:
        return sum(i + 1 in set(arr) for i in arr)
```

### Ruby

```ruby
# @param {Integer[]} arr
# @return {Integer}
def count_elements(arr)
  cnt, brr = Hash.new, arr.sort
  cnt.default = 0
  ret = 0
  brr.each { |e| cnt[e] += 1 }
  cnt.each { |key, value| ret += cnt[key + 1] > 0 ? cnt[key] : 0 }
  ret
end
```