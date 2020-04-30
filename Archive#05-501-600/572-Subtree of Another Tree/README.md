# Subtree of Another Tree

![Easy](../../materials/-Easy-5cb85c.svg) ![Tree](../../materials/树-Tree-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode572-cpp-f34b7d.svg)   | 32 ms   | 30.7 Mb      |
| ![python](https://img.shields.io/badge/leetcode572-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode572-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given two **non-empty** binary trees `s` and `t`, check whether tree `t` has exactly the same structure and node values with a subtree of `s`. A subtree of `s` is a tree consists of a node in `s` and all of this node's descendants. The tree `s` could also be considered as a subtree of itself.

## EXAMPLE 1

```plain
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
```

## EXAMPLE 2

```plain
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
```

## SOLUTION

* 先对两个树求先序遍历然后做字符串匹配即可

## CODE

### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    int maxElement, LEFT_NULL_MARK, RIGHT_NULL_MARK;

    void dfs_max(TreeNode *node)
    {
        if (!node) return;
        maxElement = max(maxElement, node->val);
        dfs_max(node->left);
        dfs_max(node->right);
    }

    void dfs_DLR(TreeNode *node, vector<int> &ret)
    {
        if (!node) return;
        ret.push_back(node->val);
        if (node->left) dfs_DLR(node->left, ret);
        else ret.push_back(LEFT_NULL_MARK);
        if (node->right) dfs_DLR(node->right, ret);
        else ret.push_back(RIGHT_NULL_MARK);
    }

    bool match(vector<int> &s, vector<int> &t)
    {
        // kmp
        int sz_1 = s.size(), sz_2 = t.size();
        vector<int> next(t.size(), -1);
        for (int i = 1, j = -1; i < sz_2; ++i)
        {
            while (j != -1 && t[i] != t[j + 1]) j = next[j];
            if (t[i] == t[j + 1]) ++j;
            next[i] = j;
        }
        for (int i = 0, j = -1; i < sz_1; ++i)
        {
            while (j != -1 && s[i] != t[j + 1]) j = next[j];
            if (s[i] == t[j + 1]) ++j;
            if (j == sz_2 - 1) return true;
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        maxElement = INT_MIN;
        dfs_max(s);
        dfs_max(t);
        LEFT_NULL_MARK = maxElement + 1;
        RIGHT_NULL_MARK = maxElement + 2;
        vector<int> _1, _2;
        dfs_DLR(s, _1);
        dfs_DLR(t, _2);
        return match(_1, _2);
    }
};
```

### Python3


### Ruby

