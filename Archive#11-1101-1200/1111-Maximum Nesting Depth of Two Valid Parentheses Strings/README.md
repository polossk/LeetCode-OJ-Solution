# Maximum Nesting Depth of Two Valid Parentheses Strings

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Binary_Search](https://img.shields.io/badge/二分查找-Binary_Search-007ec6.svg) ![Greedy](https://img.shields.io/badge/贪心-Greedy-007ec6.svg)

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1111-cpp-f34b7d.svg)   | 16 ms   | 7.1 Mb       |
| ![python](https://img.shields.io/badge/leetcode1111-py-3572A5.svg) | 44 ms   | 14.5 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode1111-rb-701516.svg)   | 60 ms   | 10.9 Mb      |

## DESCRIPTION

A string is a valid parentheses string (denoted VPS) if and only if it consists of `"("` and `")"` characters only, and:

* It is the empty string, or
* It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are VPS's, or
* It can be written as `(A)`, where `A` is a VPS.

We can similarly define the nesting depth `depth(S)` of any VPS `S` as follows:

* `depth("") = 0`
* `depth(A + B) = max(depth(A), depth(B))`, where `A` and `B` are VPS's
* `depth("(" + A + ")") = 1 + depth(A)`, where `A` is a VPS.

For example, `""`, `"()()"`, and `"()(()())"` are VPS's (with nesting depths 0, 1, and 2), and `")("` and `"(()"` are not VPS's.

Given a VPS `seq`, split it into two disjoint subsequences `A` and `B`, such that `A` and `B` are VPS's (and A`.length + B.length = seq.length`).

Now choose **any** such `A` and `B` such that `max(depth(A), depth(B))` is the minimum possible value.

Return an `answer` array (of length `seq.length`) that encodes such a choice of `A` and `B`: `answer[i] = 0` if `seq[i]` is part of `A`, else `answer[i] = 1`. Note that even though multiple answers may exist, you may return any of them.

## EXAMPLE 1

```plain
Input: seq = "(()())"
Output: [0,1,1,1,1,0]
```

## EXAMPLE 2

```plain
Input: seq = "()(())()"
Output: [0,0,0,1,1,0,1,1]
```

## CONSTRAINTS

* `1 <= seq.size <= 10000`

## SOLUTION

* 题目的意思是通过 `01` 标记出两个子序列 `A` 和 `B`，使这两个序列都是合法的括号序列，同时其括号的深度要尽可能的小
* 注意到原始的字符串一定是合法的括号序列，所以重点在于如何把嵌套深度处理的更好一些
* 考虑一个极端的例子 `(()((()))())` 这个串的深度是 4，考虑这样一种贪心的处理方式：左右分配法。即维护一个括号堆栈，将深度为奇数的括号给 `A`，偶数的括号给 `B`。比如上面的这个串可以这样编号

```plain
seq:    (  (  )  (  (  (  )  )  )  (  )  )
index:  0  1  2  3  4  5  6  7  8  9 10 11
depth:  1  2  2  2  3  4  4  3  2  2  2  1
ans:    1  0  0  0  1  0  0  1  0  0  0  1
sub-A:  (           (        )           )
sub-B:     (  )  (     (  )     )  (  )
```

* 注意，括号深度是与字符所在的位置相关的。假设位置下标从 0 开始编号，那么由于 0 号字符一定是 `(`，这就意味着，如果想要在 `seq[i]` 处得到偶数的括号深度 `2k`，必须使得从 0 号字符到 `i` 号字符位置至少有 `2k + m - m` 个左括号，其中 `m` 表示被抵消的左括号个数，此时有 `2k + m + m == i + 1`。因为等式左边一定为偶数，所以想要等式成立，`i` 必须是奇数。这就有了一个推论：当下标 `i` 为奇数，且同时满足此时的字符为 `(` 时，说明此时的括号深度是偶数，也就是说，这个括号要给序列 `B`。反之，如果下标 `i` 为偶数，且同时满足此时的字符为 `(` 时，说明此时的括号深度为奇数，也就是说，这个括号要给序列 `A`。由此，如果用 `1-0` 分别表示 `A-B`，那么对于字符 `(` 而言，其结果为 `seq[i] == '(' and i % 2 == 0`
* 类似的可以得到右括号的奇偶性质，正好与左括号相反，即 `seq[i] == ')' and i % 2 == 1`
* 注意到原字符串始终只有两个字符，所以可以进一步简化真值表

|  No.  | index | `i & 1` | char  | `ch == '('` | result |
| :---: | :---: | :-----: | :---: | :---------: | :----: |
|   1   |  odd  |    1    |  `(`  |      1      |   0    |
|   2   | even  |    0    |  `(`  |      1      |   1    |
|   3   |  odd  |    0    |  `)`  |      0      |   1    |
|   4   | even  |    1    |  `)`  |      0      |   0    |

* 显然，此时的真值表恰好为异或运算，所以可得到最终的判断语句 `(i & 1 ^ (seq[i] == '('))`

## CODE

### C++

```cpp
class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        int sz = seq.size();
        vector<int> ans(sz, 0);
        for (int i = 0; i < sz; i++)
            ans[i] = (i & 1 ^ (seq[i] == '('));
        return ans;
    }
};
```

### Python3

```python
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        return [((i & 1) ^ (e == '(')) for i, e in enumerate(seq)]
```

### Ruby

```ruby
# @param {String} seq
# @return {Integer[]}
def max_depth_after_split(seq)
  seq.each_char.to_a.zip((0..seq.length)).map { |ch, i|
    (i & 1 == 1) ^ (ch == '(') ? 1 : 0
  }
end
```

