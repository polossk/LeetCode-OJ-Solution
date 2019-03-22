// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 199                                                 *
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

void test() {}

int main() { test(); return 0; }
