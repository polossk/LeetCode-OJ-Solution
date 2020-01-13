# Clone Graph

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Depth--first%20Search](https://img.shields.io/badge/-Depth--first%20Search-007ec6.svg) ![Breadth--first%20Search](https://img.shields.io/badge/-Breadth--first%20Search-007ec6.svg) ![Graph](https://img.shields.io/badge/-Graph-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode150-cpp-f34b7d.svg)   | 8 ms    | 11.5 Mb      |
| ![python](https://img.shields.io/badge/leetcode150-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode150-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given a reference of a node in a **connected** undirected graph.

Return a **deep copy** (clone) of the graph.

Each node in the graph contains a val (`int`) and a list (`List[Node]`) of its neighbors.

```plain
class Node {
    public int val;
    public List<Node> neighbors;
}
```

**Test case format:**

For simplicity sake, each node's value is the same as the node's index (1-indexed). For example, the first node with `val = 1`, the second node with `val = 2`, and so on. The graph is represented in the test case using an adjacency list.

**Adjacency list** is a collection of unordered **lists** used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with `val = 1`. You must return the **copy of the given node** as a reference to the cloned graph.

## NOTE

* Division between two integers should truncate toward zero.
* The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

## EXAMPLE 1

```plain
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
```

## EXAMPLE 2

```plain
Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
```

## EXAMPLE 3

```plain
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
```

## EXAMPLE 4

```plain
Input: adjList = [[2],[1]]
Output: [[2],[1]]
```

## CONSTRAINTS:

* `1 <= Node.val <= 100`
* `Node.val` is unique for each node.
* Number of Nodes will not exceed 100.
* There is no repeated edges and no self-loops in the graph.
* The Graph is connected and all nodes can be visited starting from the given node.

## SOLUTION

* DFS 基本题目

## CODE

### C++

```cpp
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
```

### Python3

### Ruby
