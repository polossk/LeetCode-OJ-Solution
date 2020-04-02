// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 1008                                                *
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

void test() {}

int main() { test(); return 0; }
