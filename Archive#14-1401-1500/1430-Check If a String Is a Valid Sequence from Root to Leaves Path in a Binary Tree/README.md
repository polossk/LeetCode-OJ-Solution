# Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree

![Medium](../../materials/-Medium-f0ad4e.svg) ![Tree](../../materials/树-Tree-007ec6.svg)

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode1430-cpp-f34b7d.svg)   | 4 ms    | 6.7 Mb       |
| ![python](https://img.shields.io/badge/leetcode1430-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode1430-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a binary tree where each path going from the root to any leaf form a **valid sequence**, check if a given string is a **valid sequence** in such binary tree. 

We get the given string from the concatenation of an array of integers `arr` and the concatenation of all values of the nodes along a path results in a **sequence** in the given binary tree.

## EXAMPLE 1

```plain
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true
Explanation: 
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure). 
Other valid sequences are: 
0 -> 1 -> 1 -> 0 
0 -> 0 -> 0
```

## EXAMPLE 2

```plain
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
Output: false 
Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a sequence.
```

## EXAMPLE 3

```plain
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
Output: false
Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.
```

## CONSTRAINTS

* `1 <= arr.length <= 5000`
* `0 <= arr[i] <= 9`
* Each node's value is between [0 - 9].

## SOLUTION

* dfs 搜索即可，注意特判最终的节点应当为叶子节点

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
    vector<int> *aptr_;
    int size_;
    bool dfs(TreeNode *node, int offset)
    {
        if (node == nullptr) return false;
        int lhs = node->val, rhs = aptr_->operator[](offset);
        if (lhs != rhs) return false;
        if (offset + 1 == size_) { return node->left == nullptr && node->right == nullptr; }
        bool left = dfs(node->left, offset + 1);
        bool right = dfs(node->right, offset + 1);
        return left || right;
    }
public:
    bool isValidSequence(TreeNode *root, vector<int> &arr)
    {
        this->aptr_ = &arr;
        this->size_ = aptr_->size();
        return dfs(root, 0);
    }
};
```

### Python3

```python
```

### Ruby

```ruby
```