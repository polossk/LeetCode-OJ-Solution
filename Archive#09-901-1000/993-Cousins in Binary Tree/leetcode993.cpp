// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 993                                                 *
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
    std::unordered_map<int, int> depth;
    std::unordered_map<int, TreeNode*> fa;
    
    void dfs(TreeNode *node, TreeNode *parent)
    {
        if (node != nullptr)
        {
            depth[node->val] = parent == nullptr ? 0 : 1 + depth[parent->val];
            fa[node->val] = parent;
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
public:
    bool isCousins(TreeNode* root, int x, int y)
    {
        depth.clear(); fa.clear();
        dfs(root, nullptr);
        return (depth[x] == depth[y]) && (fa[x] != fa[y]);
    }
};

void test() {}

int main() { test(); return 0; }
