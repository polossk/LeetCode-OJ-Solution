# Evaluate Reverse Polish Notation

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Design](https://img.shields.io/badge/设计-Design-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode146-cpp-f34b7d.svg)   | 144 ms  | 35.5 Mb      |
| ![python](https://img.shields.io/badge/leetcode146-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode146-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Design and implement a data structure for [Least Recently Used (LRU) cache](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU). It should support the following operations: `get` and `put`.

`get(key)` - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.

`put(key, value)` - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

## FOLLOW UP

Could you do both operations in **O(1)** time complexity?

## EXAMPLE

```plain
LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
```

## SOLUTION

* 维护一个定长度的双端链表和一个哈希表来实现 O(1) 随机访问

## CODE

### C++

```cpp
class LRUCache
{
    size_t _capacity;
    using KeyValuePair = pair<int, int> ;
    list<KeyValuePair> _list;
    unordered_map<int, list<KeyValuePair>::iterator> _map;
public:
    LRUCache(int _) : _capacity(_) { }
    
    int get(int key)
    {
        auto ret = _map.find(key);
        if (ret == _map.end()) return -1;
        _list.splice(_list.begin(), _list, ret->second);
        return ret->second->second;
    }
    
    void put(int key, int value)
    {
        auto ret = _map.find(key);
        if (ret != _map.end())
        {
            _list.splice(_list.begin(), _list, ret->second);
            ret->second->second = value;
            return;
        }
        if (_map.size() == _capacity)
        {
            int trash = _list.back().first;
            _list.pop_back();
            _map.erase(trash);
        }
        _list.emplace_front(key, value);
        _map[key] = _list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

### Python3

### Ruby
