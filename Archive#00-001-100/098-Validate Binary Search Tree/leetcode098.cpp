// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 098                                                 *
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
    using int64 = long long;
    constexpr static int64 int64_min = std::numeric_limits<int64>::min();
    constexpr static int64 int64_max = std::numeric_limits<int64>::max();
    bool dfs(TreeNode *root, int64 lower=int64_min, int64 upper=int64_max)
    {
        if (root == nullptr) return true;
        if ((root->val <= lower) || (root->val >= upper)) return false;
        return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
    }
public:
    bool isValidBST(TreeNode* root) { return dfs(root); }
};

void test() { }

int main() { test(); return 0; }
