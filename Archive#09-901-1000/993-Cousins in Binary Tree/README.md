# Cousins in Binary Tree

![Easy](../../materials/-Easy-5cb85c.svg) ![Tree](../../materials/树-Tree-007ec6.svg) ![Breadth--first_Search](../../materials/广度优先搜索-Breadth--first_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode993-cpp-f34b7d.svg)   | 4 ms    | 12 Mb        |
| ![python](https://img.shields.io/badge/leetcode993-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode993-rb-701516.svg)   | -       | -            |

## DESCRIPTION

In a binary tree, the root node is at depth `0`, and children of each depth `k` node are at depth `k+1`.

Two nodes of a binary tree are *cousins* if they have the same depth, but have **different parents**.

We are given the *root* of a binary tree with unique values, and the values `x` and `y` of two different nodes in the tree.

Return `true` if and only if the nodes corresponding to the values `x` and `y` are cousins.

## NOTE

1. The number of nodes in the tree will be between `2` and `100`.
2. Each node has a unique integer value from `1` to `100`.

## EXAMPLE 1

```plain
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
```

## EXAMPLE 2

```plain
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
```

## EXAMPLE 3

```plain
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
```

## SOLUTION

* dfs 时记录节点的深度与父节点，随后判断 x 和 y 的深度是否相同且父节点不同即可。

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
    std::unordered_map<int, int> depth;
    std::unordered_map<int, TreeNode*> fa;
    
    void dfs(TreeNode *node, TreeNode *parent)
    {
        if (node != nullptr)
        {
            depth[node->val] = parent == nullptr ? 0 : 1 + depth[parent->val];
            fa[node->val] = parent;
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
public:
    bool isCousins(TreeNode* root, int x, int y)
    {
        depth.clear(); fa.clear();
        dfs(root, nullptr);
        return (depth[x] == depth[y]) && (fa[x] != fa[y]);
    }
};
```

### Python3

### Ruby

### Java
