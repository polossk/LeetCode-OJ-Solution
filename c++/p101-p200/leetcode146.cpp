// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 146                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

class LRUCache
{
    size_t _capacity;
    typedef pair<int, int> KeyValuePair;
    list<KeyValuePair> _list;
    unordered_map<int, list<KeyValuePair>::iterator> _map;

public:
    LRUCache(int _) : _capacity(_) { }
    
    int get(int key)
    {
        auto ret = _map.find(key);
        if (ret == _map.end()) return -1;
        _list.splice(_list.begin(), _list, ret -> second);
        return ret -> second -> second;
    }
    
    void set(int key, int value)
    {
        auto ret = _map.find(key);
        if (ret != _map.end())
        {
            _list.splice(_list.begin(), _list, ret -> second);
            ret -> second -> second = value;
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

void test() {}

int main() { test(); return 0; }
