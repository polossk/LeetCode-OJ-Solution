# Lowest Common Ancestor of a Binary Search Tree

![Easy](../../materials/-Easy-5cb85c.svg) ![Tree](../../materials/树-Tree-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode235-cpp-f34b7d.svg)   | 36 ms   | 23.4 Mb      |
| ![python](https://img.shields.io/badge/leetcode235-py-3572A5.svg) | 80 ms   | 17.9 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode235-rb-701516.svg)   | 56 ms   | 10.4 Mb      |

## DESCRIPTION

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow **a node to be a descendant of itself**).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

## EXAMPLE 1

```plain
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
```

## EXAMPLE 2

```plain
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
```

## NOTE

* All of the nodes' values will be unique.
* p and q are different and both values will exist in the BST.

## SOLUTION

* 借助二叉搜索树的性质，从根节点往下搜索即可。

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
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            int v = root->val, pv = p->val, qv = q->val;
            if (v > std::max(pv, qv))
                root = root->left;
            else if (v < std::min(pv, qv))
                root = root->right;
            else return root;
        }
        return root;
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
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        while root:
            v, pv, qv = root.val, p.val, q.val
            if v > max(pv, qv): root = root.left
            elif v < min(pv, qv): root = root.right
            else: return root
```

### Ruby

```ruby
# Definition for a binary tree node.
# class TreeNode
#   attr_accessor :val, :left, :right
#   def initialize(val)
#     @val = val
#     @left, @right = nil, nil
#   end
# end

# @param {TreeNode} root
# @param {TreeNode} p
# @param {TreeNode} q
# @return {TreeNode}
def lowest_common_ancestor(root, p, q)
  while (root != nil) do
    v, pv, qv = root.val, p.val, q.val
    if (v > [pv, qv].max) then
      root = root.left
    elsif (v < [pv, qv].min) then
      root = root.right
    else
      return root
    end
  end
end
```

### Java
