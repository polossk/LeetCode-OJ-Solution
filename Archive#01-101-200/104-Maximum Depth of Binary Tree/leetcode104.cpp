// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 104                                                 *
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
class Solution
{
    int dfs(TreeNode *root)
    {
        if (root == nullptr) return 0;
        int l_depth = dfs(root->left);
        int r_depth = dfs(root->right);
        return 1 + max(l_depth, r_depth);
    }
public:
    int maxDepth(TreeNode *root) { return dfs(root); }
};

void test() {}

int main() { test(); return 0; }
