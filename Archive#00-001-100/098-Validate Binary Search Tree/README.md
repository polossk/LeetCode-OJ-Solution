# Validate Binary Search Tree

![Medium](../../materials/-Medium-f0ad4e.svg) ![Tree](../../materials/树-Tree-007ec6.svg) ![Depth--first_Search](../../materials/深度优先搜索-Depth--first_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode098-cpp-f34b7d.svg)   | 20 ms   | 21.7 Mb      |
| ![python](https://img.shields.io/badge/leetcode098-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode098-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

* The left subtree of a node contains only nodes with keys **less than** the node's key.
* The right subtree of a node contains only nodes with keys **greater than** the node's key.
* Both the left and right subtrees must also be binary search trees.

## EXAMPLE 1

```plain
    2
   / \
  1   3

Input: [2,1,3]
Output: true
```

## EXAMPLE 2

```plain
    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```

## SOLUTION

* 从根节点开始遍历，使得其每一个节点都落在允许的区间内即可

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
    using int64 = long long;
    constexpr static int64 int64_min = std::numeric_limits<int64>::min();
    constexpr static int64 int64_max = std::numeric_limits<int64>::max();
    bool dfs(TreeNode *root, int64 lower=int64_min, int64 upper=int64_max)
    {
        if (root == nullptr) return true;
        if ((root->val <= lower) || (root->val >= upper)) return false;
        return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
    }
public:
    bool isValidBST(TreeNode* root) { return dfs(root); }
};
```

### Python3

```python
```

### Ruby

```ruby
```

### Java

```java
```
