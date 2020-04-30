# Min Stack

![Easy](../../materials/-Easy-5cb85c.svg) ![Stack](../../materials/堆栈-Stack-007ec6.svg) ![Design](../../materials/设计-Design-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode155-cpp-f34b7d.svg)   | 32 ms   | 17 Mb        |
| ![python](https://img.shields.io/badge/leetcode155-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode155-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

* push(x) -- Push element x onto stack.
* pop() -- Removes the element on top of the stack.
* top() -- Get the top element.
* getMin() -- Retrieve the minimum element in the stack.

## EXAMPLE

```plain
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
```

## SOLUTION

* 最小栈，同时维护数据域与最小值域
* 每当有一个值进栈时，实际上会压入两个数据：一个压在数据域，另一个处理当前的最小值，并且压入最小值的堆栈中
* 每当有元素退栈时，数据域与最小值栈都退栈，这样就保持了最小值栈剩余元素的栈顶永远是当前状态下的最小元素

## CODE

### C++

```cpp
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
```

### Python3

### Ruby
