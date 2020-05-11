# Lowest Common Ancestor of a Binary Tree

![Medium](../../materials/-Medium-f0ad4e.svg) ![Tree](../../materials/树-Tree-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode236-cpp-f34b7d.svg)   | 28 ms   | 14.4 Mb      |
| ![python](https://img.shields.io/badge/leetcode236-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode236-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow **a node to be a descendant of itself**).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

## EXAMPLE 1

```plain
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```

## EXAMPLE 2

```plain
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
```

## NOTE

* All of the nodes' values will be unique.
* p and q are different and both values will exist in the binary tree.

## SOLUTION

* 从根节点往下搜索，用空指针 `nullptr` 表示同时不为 `p` 和 `q` 的祖先，传递当前的 `p` 的祖先或 `q` 的祖先，当且仅当左右子树都不为空指针时，返回父节点，否则返回不为空指针的节点

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
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) return right;
        if (right == nullptr) return left;      
        if (left && right) return root;
        return nullptr;
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```

### Java
