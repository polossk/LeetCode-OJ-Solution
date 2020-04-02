# Construct Binary Search Tree from Preorder Traversal

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Tree](https://img.shields.io/badge/树-Tree-007ec6.svg)

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1008-cpp-f34b7d.svg)   | 0 ms    | 11.6 Mb      |
| ![python](https://img.shields.io/badge/leetcode1008-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode1008-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Return the root node of a binary **search** tree that matches the given preorder traversal.

*(Recall that a binary search tree is a binary tree where for every node, any descendant of `node.left` has a value `< node.val`, and any descendant of `node.right` has a value `> node.val`.  Also recall that a preorder traversal displays the value of the node first, then traverses `node.left`, then traverses `node.right`.)*

## EXAMPLE

```plain
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
```

## CONSTRAINTS

* `1 <= preorder.length <= 100`
* The values of `preorder` are distinct.

## SOLUTION

* 注意二叉树的先序遍历的顺序：根节点、先序遍历左节点、先序遍历右节点。所以先序遍历结果的第一个元素一定是二叉树的树根
* 二叉搜索树的性质是，根节点左边的数据一定比根节点小，右边的一定比根节点大，所以可以根据这个性质先判断下一个数据是否在允许的区间内部，如果不在，则判断是否在右子节点可能的取值范围内。逐层递归即可。

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
    vector<int> pre_;
    int n_;
    TreeNode* dfs(int &i, int l, int r)
    {
        if (i == n_) return nullptr;
        int val = pre_[i];
        if (val < l || val > r) return nullptr;
        i++;
        TreeNode *node = new TreeNode(val);
        node->left = dfs(i, l, val);
        node->right = dfs(i, val, r);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int> &preorder)
    {
        pre_ = preorder;
        n_ = preorder.size();
        int i = 0;
        return dfs(i, INT_MIN, INT_MAX);
    }
};
```

### Python3

```python
```

### Ruby

