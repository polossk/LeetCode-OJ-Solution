// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 155                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template <class T> inline bool updateMin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> inline bool updateMax(T &a, T b) { return a < b ? a = b, 1 : 0; }

class MinStack {
private:
    stack<int> dat_, min_;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x)
    {
        dat_.push(x);
        if (min_.empty()) min_.push(x);
        else
        {
            int tmp = min_.top();
            min_.push(x < tmp ? x : tmp);
        }
    }
    
    inline void pop() { dat_.pop(); min_.pop(); }
    
    inline int top() { return dat_.top(); }
    
    inline int getMin() { return min_.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

void test() {}

int main()
{
    test();
    return 0;
}
