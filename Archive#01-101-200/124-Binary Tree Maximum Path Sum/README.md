# Binary Tree Maximum Path Sum

 ![Hard](https://img.shields.io/badge/-Hard-e05d44.svg) ![Tree](https://img.shields.io/badge/-Tree-007ec6.svg) ![Depth--first%20Search](https://img.shields.io/badge/-Depth--first%20Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode124-cpp-f34b7d.svg)   | 36 ms   | 24.6 Mb      |
| ![python](https://img.shields.io/badge/leetcode124-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode124-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a **non-empty** binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain **at least one node** and does not need to go through the root.

## NOTE

* Division between two integers should truncate toward zero.
* The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

## EXAMPLE 1

```plain
Input: [1,2,3]

       1
      / \
     2   3

Output: 6
```

## EXAMPLE 2

```plain
Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
```

## SOLUTION

* 从根节点开始 dfs，`ret = max(ret, dfs(node->left, ret) + dfs(node->right, ret) + node->val)`

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
class Solution {

    template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

    int dfs(TreeNode* node, int&& ret)
    {
        if (!node) return 0;
        int l = dfs(node->left, std::move(ret));
        int r = dfs(node->right, std::move(ret));
        updateMax(l, 0); updateMax(r, 0);
        updateMax(ret, l + r + node->val);
        return node->val += max(l, r);
    }

public:
    int maxPathSum(TreeNode* root)
    {
        int ret = INT_MIN;
        dfs(root, std::move(ret));
        return ret;
    }
};
```

### Python3

### Ruby
