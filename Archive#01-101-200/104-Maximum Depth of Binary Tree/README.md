# Maximum Depth of Binary Tree

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Tree](https://img.shields.io/badge/树-Tree-007ec6.svg) ![Depth--first_Search](https://img.shields.io/badge/深度优先搜索-Depth--first_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode104-cpp-f34b7d.svg)   | 16 ms   | 18.6 Mb      |
| ![python](https://img.shields.io/badge/leetcode104-py-3572A5.svg) | 44 ms   | 15 Mb        |
| ![ruby](https://img.shields.io/badge/leetcode104-rb-701516.svg)   | 40 ms   | 9.8 Mb       |

## DESCRIPTION

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

## EXAMPLE

```plain
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
```

## NOTE

A leaf is a node with no children.

## SOLUTION

* 二叉树基本题。二叉树的深度等于其左右子树深度的最大值加一。

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
class Solution
{
    int dfs(TreeNode *root)
    {
        if (root == nullptr) return 0;
        int l_depth = dfs(root->left);
        int r_depth = dfs(root->right);
        return 1 + max(l_depth, r_depth);
    }
public:
    int maxDepth(TreeNode *root) { return dfs(root); }
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
    def maxDepth(self, root: TreeNode) -> int:
        def dfs(node: TreeNode):
            if not node: return 0
            l_depth = dfs(node.left)
            r_depth = dfs(node.right)
            return 1 + max(l_depth, r_depth)
        return dfs(root)
```

### Ruby

```ruby
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer}
def dfs(node)
  return 0 unless node
  1 + [dfs(node.left), dfs(node.right)].max
end

# @param {TreeNode} root
# @return {Integer}
def max_depth(root)
  # dfs = lambda { |node| 
  #   return 0 unless node
  #   1 + [dfs.call(node.left), dfs.call(node.right)].max
  # }
  # dfs.call(root)
  dfs(root)
end
```