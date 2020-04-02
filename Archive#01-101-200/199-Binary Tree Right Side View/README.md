# Binary Tree Right Side View

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Tree](https://img.shields.io/badge/树-Tree-007ec6.svg) ![Depth--first_Search](https://img.shields.io/badge/深度优先搜索-Depth--first_Search-007ec6.svg) ![Breadth--first_Search](https://img.shields.io/badge/广度优先搜索-Breadth--first_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode199-cpp-f34b7d.svg)   | 0 ms    | 7.4 Mb       |
| ![python](https://img.shields.io/badge/leetcode199-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode199-rb-701516.svg)   | 28 ms   | 9.3 Mb       |

## DESCRIPTION

Given a binary tree, imagine yourself standing on the *right* side of it, return the values of the nodes you can see ordered from top to bottom.

## EXAMPLE

```plain
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
```

## SOLUTION

* 从树根开始 dfs，先右节点，再左节点。dfs 时同时维护当前的深度。当答案数组的大小小于当前深度时，说明这是第一个暴露在当前深度的节点，存进答案数组即可

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
    void dfs(TreeNode* root, vector<int>& res, int dep)
    {
        if (!root) return;
        if (dep >= res.size()) res.push_back(root -> val);
        dfs(root -> right, res, dep + 1);
        dfs(root -> left, res, dep + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};
```

### Python3

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
# @return {Integer[]}

def right_side_view(root)
  return [] if not root
  right = right_side_view(root.right)
  left = right_side_view(root.left)
  return [root.val] + right + left.drop(right.length)
end
```

### Java
