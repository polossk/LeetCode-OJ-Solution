# Open the Lock

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Breadth--first_Search](https://img.shields.io/badge/广度优先搜索-Breadth--first_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode752-cpp-f34b7d.svg)   | 136 ms  | 29.2 Mb      |
| ![python](https://img.shields.io/badge/leetcode752-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode752-rb-701516.svg)   | -       | -            |

## DESCRIPTION

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: `'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'`. The wheels can rotate freely and wrap around: for example we can turn `'9'` to be `'0'`, or `'0'` to be `'9'`. Each move consists of turning one wheel one slot.

The lock initially starts at `'0000'`, a string representing the state of the 4 wheels.

You are given a list of `deadends` dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a `target` representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

## NOTE

1. The length of `deadends` will be in the range `[1, 500]`.
2. `target` will not be in the list `deadends`.
3. Every string in `deadends` and the string `target` will be a string of 4 digits from the 10,000 possibilities `'0000'` to `'9999'`.

## EXAMPLE 1

```plain
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
```

## EXAMPLE 2

```plain
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
```

## EXAMPLE 3

```plain
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
```

## Example 4:

```plain
Input: deadends = ["0000"], target = "8888"
Output: -1
```

## SOLUTION

* BFS 变种，对状态空间逐层搜索（状态空间最短路问题）

## CODE

### C++

```cpp
class Solution {
private:
    const string start = "0000";
    unordered_set<string> deadset, vis{start};
    int bfs(const string &target)
    {
        int ret = 0;
        queue<string> q;
        q.push(start);
        while (!q.empty())
        {
            ret++;
            for (int i = 0, sz = q.size(); i < sz; i++)
            {
                string now = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        int leap = j * 2 - 1;
                        string r = now;
                        r[i] = (r[i] - '0' + leap + 10) % 10 + '0';
                        if (r == target) return ret;
                        if (deadset.count(r) || vis.count(r)) continue;
                        q.push(r); vis.insert(r);
                    }
                }
            }
        }
        return -1;
    }
public:
    int openLock(vector<string>& deadends, string target)
    {
        deadset = unordered_set<string>(deadends.begin(), deadends.end());
        if (deadset.count(start)) return -1;
        return bfs(target);
    }
};
```

### Python3

### Ruby

### Java
