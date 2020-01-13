// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 133                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
};
*/
class Solution {
    map<Node*, Node*> vis;

    Node* dfs(Node *head)
    {
        if (head == nullptr) return nullptr;
        if (vis.count(head)) return vis[head];
        Node *clone = new Node(head->val);
        vis[head] = clone;
        for (Node *next : head->neighbors)
        {
            clone->neighbors.push_back(dfs(next));
        }
        return clone;
    }
public:
    Node* cloneGraph(Node *node) { return dfs(node); }
};

void test() {}

int main()
{
    test();
    return 0;
}
