// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 225                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class Stack {
    queue<int> _;
public:
    // Push element x onto stack.
    void push(int x) {
        _.push(x);
        for (int i = 0; i < _.size() - 1; i++)
        {
            _.push(_.front()); _.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() { _.pop(); }

    // Get the top element.
    int top() { return _.front(); }

    // Return whether the stack is empty.
    bool empty() { return _.empty(); }
};

void test() {}

int main() { test(); return 0; }
