# Diameter of Binary Tree

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Tree](https://img.shields.io/badge/树-Tree-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode543-cpp-f34b7d.svg)   | 8 ms    | 18.7 Mb      |
| ![python](https://img.shields.io/badge/leetcode543-py-3572A5.svg) | 44 ms   | 14.8 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode543-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the **longest** path between any two nodes in a tree. This path may or may not pass through the root.

## EXAMPLE

```plain
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
```

## NOTE

The length of path between two nodes is represented by the number of edges between them.

## SOLUTION

* 二叉树基本题。二叉树的直径等同于寻找最长通路，即一个节点的左右节点深度之和加一。所以可以用 dfs 先处理深度，然后更新当前的最长通路的大小。

## CODE

### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
class Solution
{
    int dfs(TreeNode *root, int &length)
    {
        if (root == nullptr) return 0;
        int l_depth = dfs(root->left, length);
        int r_depth = dfs(root->right, length);
        updateMax(length, l_depth + r_depth);
        return 1 + max(l_depth, r_depth);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ret = 0;
        int dep = dfs(root, ret);
        return ret;
    }
};
```

### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ret = 0
        def dfs(node: TreeNode):
            if not node: return 0
            l_depth = dfs(node.left)
            r_depth = dfs(node.right)
            self.ret = max(self.ret, l_depth + r_depth)
            return 1 + max(l_depth, r_depth)
        dfs(root)
        return self.ret
```

### Ruby

