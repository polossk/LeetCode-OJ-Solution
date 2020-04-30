// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1430                                                *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

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

void test() {}

int main() { test(); return 0; }
