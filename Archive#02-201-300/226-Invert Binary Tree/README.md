# Invert Binary Tree

![Easy](../../materials/-Easy-5cb85c.svg) ![Tree](../../materials/树-Tree-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode226-cpp-f34b7d.svg)   | 0 ms    | 7.8 Mb       |
| ![python](https://img.shields.io/badge/leetcode226-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode226-rb-701516.svg)   | 48 ms   | 9.3 Mb       |

## DESCRIPTION

Invert a binary tree.

## EXAMPLE

```plain
Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

## TRIVIA

This problem was inspired by [this original tweet](https://twitter.com/mxcl/status/608682016205344768) by [Max Howell](https://twitter.com/mxcl):

> Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.

## SOLUTION

* 递归翻转即可

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root) return NULL;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *r = root->right;
        TreeNode *l = root->left;
        root->right = l; root->left = r;
        return root;
    }
};
```

### Python3

```python
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
# @return {TreeNode}
def invert_tree(root)
  if root
    root.left, root.right = invert_tree(root.right), invert_tree(root.left)
  end
  root
end
```
