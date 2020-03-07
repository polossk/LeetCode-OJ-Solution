# 最小的 k 个数

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Heap](https://img.shields.io/badge/堆-Heap-007ec6.svg) ![Divide_and_Conquer](https://img.shields.io/badge/分治法-Divide_and_Conquer-007ec6.svg)

## RESULT

| Submission                                                      | Runtime | Memory Usage |
| --------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/cof40--sort-cpp-f34b7d.svg) | 48 ms   | 20.4 Mb      |
| ![cpp](https://img.shields.io/badge/cof40--heap-cpp-f34b7d.svg) | 52 ms   | 21.2 Mb      |
| ![python](https://img.shields.io/badge/cof40-py-3572A5.svg)     | -       | -            |
| ![ruby](https://img.shields.io/badge/cof40-rb-701516.svg)       | -       | -            |

## DESCRIPTION

输入整数数组 `arr` ，找出其中最小的 `k` 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

## EXAMPLE 1

```plain
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
```

## EXAMPLE 2

```plain
输入：arr = [0,1,2,1], k = 1
输出：[0]
```

## RESTRICTION

* `0 <= k <= arr.length <= 10000`
* `0 <= arr[i] <= 10000`

## SOLUTION

* 整体排序取前 k 个
* 维护一个最小堆，控制堆的容量为 k

## CODE

### C++

```cpp
class Solution
{
public:
    // sort then select
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        vector<int> ret(k, 0);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) ret[i] = arr[i];
        return ret;
    }
    // heap and scan
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        vector<int> ret(k, 0);
        if (k == 0) return ret;
        std::priority_queue<int> pq;
        for (int i = 0; i < k; i++) pq.push(arr[i]);
        for (int i = k, sz = arr.size(); i < sz; i++)
        {
            if (pq.top() > arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i)
        {
            ret[i] = pq.top();
            pq.pop();
        }
        return ret;
    }
};
```

### Python3


### Ruby

