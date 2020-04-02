# First Unique Number

## RESULT

| Submission                                                         | Runtime | Memory Usage |
| ------------------------------------------------------------------ | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcodeXXXX-cpp-f34b7d.svg)   | 4 ms    | 6.7 Mb       |
| ![python](https://img.shields.io/badge/leetcodeXXXX-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcodeXXXX-rb-701516.svg)   | -       | -            |

## DESCRIPTION

You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the `FirstUnique` class:

* `FirstUnique(int[] nums)` Initializes the object with the numbers in the queue.
* `int showFirstUnique()` returns the value of the **first unique integer** of the queue, and returns **-1** if there is no such integer.
* `void add(int value)` insert value to the queue.

## EXAMPLE 1

```plain
Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output: 
[null,2,null,2,null,3,null,-1]

Explanation: 
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1
```

## EXAMPLE 2

```plain
Input: 
["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
[[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
Output: 
[null,-1,null,null,null,null,null,17]

Explanation: 
FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
firstUnique.showFirstUnique(); // return -1
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
firstUnique.add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
firstUnique.showFirstUnique(); // return 17
```

## EXAMPLE 3

```plain
Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique"]
[[[809]],[],[809],[]]
Output: 
[null,809,null,-1]

Explanation: 
FirstUnique firstUnique = new FirstUnique([809]);
firstUnique.showFirstUnique(); // return 809
firstUnique.add(809);          // the queue is now [809,809]
firstUnique.showFirstUnique(); // return -1
```

## CONSTRAINTS

* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^8`
* `1 <= value <= 10^8`
* At most `50000` calls will be made to `showFirstUnique` and `add`.

## SOLUTION

* 预处理 `shift` 表，然后移动字符即可

## CODE

### C++

```cpp
namespace std
{
    using KV = std::pair<int, int>;
    template <>
    struct less<KV> : public binary_function<KV, KV, bool>
    {
        using result_type = bool;
        using first_argument_type = KV;
        using second_argument_type = KV;
        constexpr bool operator()(const KV &a, const KV &b) const
        {
            return a.second > b.second;
        }
    };
}

class FirstUnique
{
    using KV = std::pair<int, int>;
    std::unordered_map<int, int> cnt_;
    std::priority_queue<KV> heap_;
    int length;

public:
    FirstUnique(vector<int>& nums)
    {
        cnt_.clear();
        heap_ = std::priority_queue<KV>();
        length = 0;
        for (auto elem : nums) add(elem);
    }
    
    int showFirstUnique()
    {
        while(!heap_.empty())
        {
            auto [key, value] = heap_.top();
            if (cnt_[key] == 1) return key;
            heap_.pop();
        }
        return -1;
    }
    
    void add(int value)
    {
        cnt_[value]++;
        if (cnt_[value] == 1) heap_.push({value, length});
        length++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
```

### Python3

```python
```

### Ruby

```ruby
```