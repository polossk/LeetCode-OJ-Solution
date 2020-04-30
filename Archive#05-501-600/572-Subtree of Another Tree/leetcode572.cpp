// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 572                                                 *
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
    int maxElement, LEFT_NULL_MARK, RIGHT_NULL_MARK;

    void dfs_max(TreeNode *node)
    {
        if (!node) return;
        maxElement = max(maxElement, node->val);
        dfs_max(node->left);
        dfs_max(node->right);
    }

    void dfs_DLR(TreeNode *node, vector<int> &ret)
    {
        if (!node) return;
        ret.push_back(node->val);
        if (node->left) dfs_DLR(node->left, ret);
        else ret.push_back(LEFT_NULL_MARK);
        if (node->right) dfs_DLR(node->right, ret);
        else ret.push_back(RIGHT_NULL_MARK);
    }

    bool match(vector<int> &s, vector<int> &t)
    {
        // kmp
        int sz_1 = s.size(), sz_2 = t.size();
        vector<int> next(t.size(), -1);
        for (int i = 1, j = -1; i < sz_2; ++i)
        {
            while (j != -1 && t[i] != t[j + 1]) j = next[j];
            if (t[i] == t[j + 1]) ++j;
            next[i] = j;
        }
        for (int i = 0, j = -1; i < sz_1; ++i)
        {
            while (j != -1 && s[i] != t[j + 1]) j = next[j];
            if (s[i] == t[j + 1]) ++j;
            if (j == sz_2 - 1) return true;
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        maxElement = INT_MIN;
        dfs_max(s);
        dfs_max(t);
        LEFT_NULL_MARK = maxElement + 1;
        RIGHT_NULL_MARK = maxElement + 2;
        vector<int> _1, _2;
        dfs_DLR(s, _1);
        dfs_DLR(t, _2);
        return match(_1, _2);
    }
};

void test() {}

int main() { test(); return 0; }
