# Design Circular Queue

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Design](https://img.shields.io/badge/-Design-007ec6.svg) ![Queue](https://img.shields.io/badge/-Queue-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode622-cpp-f34b7d.svg)   | 28 ms   | 16.6 Mb      |
| ![python](https://img.shields.io/badge/leetcode622-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode622-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

* `MyCircularQueue(k)`: Constructor, set the size of the queue to be k.
* `Front`: Get the front item from the queue. If the queue is empty, return -1.
* `Rear`: Get the last item from the queue. If the queue is empty, return -1.
* `enQueue(value`): Insert an element into the circular queue. Return true if the operation is successful.
* `deQueue()`: Delete an element from the circular queue. Return true if the operation is successful.
* `isEmpty()`: Checks whether the circular queue is empty or not.
* `isFull()`: Checks whether the circular queue is full or not.

## NOTE

* All values will be in the range of [0, 1000].
* The number of operations will be in the range of [1, 1000].
* Please do not use the built-in Queue library.

## EXAMPLE:

```cpp
MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4
```

## SOLUTION

* 基本循环队列的实现
* 同时维护三个标记值：头 `front_`，尾 `rear_` 和总容量 `capacity_`，通过调节头尾指针的位置标记来控制循环队列内的元素
* 有可能出现数值上头指针大于尾指针的情况，所以用取模运算来保证不出现数组越界

## CODE

### C++

```cpp
class MyCircularQueue {
private:
    vector<int> cq_;
    int front_, rear_, capacity_;
    // cq_ := [front_, rear_)
    // front_: head data
    // rear_: empty place for next element
    static const int DEFAULT_NEXT_OFFSET = 1;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        capacity_ = k + DEFAULT_NEXT_OFFSET;
        cq_.assign(capacity_, 0);
        front_ = rear_ = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (isFull()) return false;
        cq_[rear_] = value;
        rear_ = (rear_ + DEFAULT_NEXT_OFFSET) % capacity_;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    inline bool deQueue()
    {
        if (isEmpty()) return false;
        front_ = (front_ + DEFAULT_NEXT_OFFSET) % capacity_;
        return true;
    }
    
    /** Get the front item from the queue. */
    inline int Front()
    {
        if (isEmpty()) return -1;
        return cq_[front_];
    }
    
    /** Get the last item from the queue. */
    inline int Rear()
    {
        if (isEmpty()) return -1;
        return cq_[(rear_ - DEFAULT_NEXT_OFFSET + capacity_) % capacity_];
    }
    
    /** Checks whether the circular queue is empty or not. */
    inline bool isEmpty() { return front_ == rear_; }
    
    /** Checks whether the circular queue is full or not. */
    inline bool isFull() { return (rear_ + DEFAULT_NEXT_OFFSET) % capacity_ == front_; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```

### Python3

### Ruby

### Java
