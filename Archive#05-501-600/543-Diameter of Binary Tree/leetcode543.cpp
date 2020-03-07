// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 543                                                 *
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
class Solution
{
    int dfs(TreeNode *root, int &length)
    {
        if (root == nullptr) return 0;
        int l_depth = dfs(root->left, length);
        int r_depth = dfs(root->right, length);
        updateMax(length, l_depth + r_depth);
        return 1 + max(l_depth, r_depth);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ret = 0;
        int dep = dfs(root, ret);
        return ret;
    }
};

void test() {}

int main() { test(); return 0; }
