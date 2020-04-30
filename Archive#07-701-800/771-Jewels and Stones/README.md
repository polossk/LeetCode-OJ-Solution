# Jewels and Stones

![Easy](../../materials/-Easy-5cb85c.svg) ![Hash_Table](../../materials/哈希表-Hash_Table-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode771-cpp-f34b7d.svg)   | 12 ms   | 6.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode771-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode771-rb-701516.svg)   | -       | -            |

## DESCRIPTION

You're given strings `J` representing the types of stones that are jewels, and `S` representing the stones you have.  Each character in `S` is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in `J` are guaranteed distinct, and all characters in `J` and `S` are letters. Letters are case sensitive, so `"a"` is considered a different type of stone from `"A"`.

## NOTE

* `S` and `J` will consist of letters and have length at most 50.
* The characters in `J` are distinct.

## EXAMPLE 1

```plain
Input: J = "aA", S = "aAAbbbb"
Output: 3
```

## EXAMPLE 2

```plain
Input: J = "z", S = "ZZ"
Output: 0
```

## SOLUTION

* 分别记录宝石的字符和石头的字符出现次数，然后统计一遍即可

## CODE

### C++

```cpp
class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_map<char, int> jewels, stones;
        for (auto ch : J) jewels[ch]++;
        for (auto ch : S) stones[ch]++;
        int ret = 0;
        for (auto record : jewels)
        {
            if (stones.find(record.first) == stones.end())
                continue;
            ret += stones[record.first];
        }
        return ret;
    }
};
```

### Python3

### Ruby

### Java
