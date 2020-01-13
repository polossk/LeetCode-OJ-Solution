// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 622                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

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

void test() {}

int main() { test(); return 0; }
