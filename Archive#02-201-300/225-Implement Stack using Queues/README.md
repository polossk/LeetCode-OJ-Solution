# Implement Stack using Queues

![Easy](../../materials/-Easy-5cb85c.svg) ![Stack](../../materials/堆栈-Stack-007ec6.svg) ![Design](../../materials/设计-Design-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode225-cpp-f34b7d.svg)   | 0 ms    | 6.4 Mb       |
| ![python](https://img.shields.io/badge/leetcode225-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode225-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Implement the following operations of a stack using queues.

* push(x) -- Push element x onto stack.
* pop() -- Removes the element on top of the stack.
* top() -- Get the top element.
* empty() -- Return whether the stack is empty.

## EXAMPLE

```plain
MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
```

## NOTE

* You must use only standard operations of a queue -- which means only `push to back`, `peek/pop from front`, `size`, and `is empty` operations are valid.
* Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
* You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

## SOLUTION

* 单队列模拟即可

## CODE

### C++

```cpp
class MyStack
{
    queue<int> _;
public:
    /** Initialize your data structure here. */
    MyStack() {  }

    /** Push element x onto stack. */
    void push(int x)
    {
        _.push(x);
        for (int i = 0; i < _.size() - 1; i++)
        {
            _.push(_.front()); _.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() { int __ = _.front(); _.pop(); return __; }

    /** Get the top element. */
    int top() { return _.front(); }

    /** Returns whether the stack is empty. */
    bool empty() { return _.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

### Python3

```python
```

### Ruby

```ruby
```

### Java
