// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 124                                                 *
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

void test() {}

int main() { test(); return 0; }
