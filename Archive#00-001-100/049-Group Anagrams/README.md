# Group Anagrams

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Hash_Table](https://img.shields.io/badge/哈希表-Hash_Table-007ec6.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode049-cpp-f34b7d.svg)   | 56 ms   | 17.5 Mb      |
| ![python](https://img.shields.io/badge/leetcode049-py-3572A5.svg) | 100 ms  | 17.8 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode049-rb-701516.svg)   | 132 ms  | 13.2 Mb      |

## DESCRIPTION

Given an array of strings, group anagrams together.

## EXAMPLE

```plain
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
```

## NOTE

* All inputs will be in lowercase.
* The order of your output does not matter.

## SOLUTION

* 维护一个 Hash 表。键设置为按字母排序后的字符串。

## CODE

### C++

```cpp
class Solution
{
    vector<int> encrypt(const string &s)
    {
        vector<int> ret(26, 0);
        for (auto it = s.begin(); it != s.end(); it++)
        ret[*it - 'a']++;
        return ret;
    }
    
    // BKDR Hash Function
    unsigned int BKDRHash(const vector<int> &s)
    {
        unsigned int seed = 31; // 31 131 1313 13131 131313 etc..
        unsigned int hash = 0;
        for (auto it = s.begin(); it != s.end(); it++)
            hash = hash * seed + (*it);
        return (hash & 0x7FFFFFFF);
    }
    
    std::unordered_map<unsigned int, int> get_index_;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ret;
        get_index_.clear();
        int offset = 0;
        for (int i = 0, sz = strs.size(); i < sz; i++)
        {
            const string &elem = strs[i];
            unsigned int ikey = BKDRHash(encrypt(elem));
            if (get_index_.count(ikey) > 0)
                ret[get_index_[ikey]].push_back(elem);
            else
            {
                get_index_[ikey] = offset++;
                ret.push_back(vector<string>({elem}));
            }
        }
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
