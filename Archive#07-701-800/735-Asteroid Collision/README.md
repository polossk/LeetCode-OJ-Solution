# Asteroid Collision

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Stack](https://img.shields.io/badge/-Stack-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode735-cpp-f34b7d.svg)   | 12 ms   | 9.5 Mb       |
| ![python](https://img.shields.io/badge/leetcode735-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode735-rb-701516.svg)   | -       | -            |

## DESCRIPTION

We are given an array `asteroids` of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

## NOTE

* The length of `asteroids` will be at most `10000`.
* Each asteroid will be a non-zero integer in the range `[-1000, 1000]`.

## EXAMPLE 1:

```plain
Input: 
asteroids = [5, 10, -5]
Output: [5, 10]
Explanation: 
The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
```

## Example 2:

```plain
Input: 
asteroids = [8, -8]
Output: []
Explanation: 
The 8 and -8 collide exploding each other.
```

## Example 3:

```plain
Input: 
asteroids = [10, 2, -5]
Output: [10]
Explanation: 
The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.
```

## Example 4:

```plain
Input: 
asteroids = [-2, -1, 1, 2]
Output: [-2, -1, 1, 2]
Explanation: 
The -2 and -1 are moving left, while the 1 and 2 are moving right.
Asteroids moving the same direction never meet, so no asteroids will meet each other.
```

## SOLUTION

* 堆栈模拟即可，只有在相向而行的情况下才会相撞

## CODE

### C++

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        vector<int> ret;
        for (int i = 0, sz = asteroids.size(); i < sz; i++)
        {
            if (ret.empty() || asteroids[i] > 0 || (ret.back() < 0 && asteroids[i] < 0))
            {
                ret.push_back(asteroids[i]);
                continue;
            }
            // only (ret.back() > 0 && asteroids[i] < 0)
            if (ret.back() + asteroids[i] == 0)
            {
                ret.pop_back();
            }
            else if (ret.back() + asteroids[i] < 0)
            {
                ret.pop_back(); i--;
            }
        }
        return ret;
    }
};
```

### Python3

### Ruby

### Java
