# Sort an Array

![Medium](../../materials/-Medium-f0ad4e.svg) ![QuickSort](../../materials/快速排序-QuickSort-009688.svg) ![MergeSort](../../materials/归并排序-MergeSort-009688.svg) ![ShellSort](../../materials/希尔排序-ShellSort-009688.svg) ![HeapSort](../../materials/堆排序-HeapSort-009688.svg)

## RESULT

| Submission                                                                       | Runtime | Memory Usage |
| -------------------------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode912--std::sort-cpp-f34b7d.svg)       | 52 ms   | 15.7 Mb      |
| ![cpp](https://img.shields.io/badge/leetcode912--quicksort-cpp-f34b7d.svg)       | 40 ms   | 15.9 Mb      |
| ![cpp](https://img.shields.io/badge/leetcode912--quicksort__iter-cpp-f34b7d.svg) | 52 ms   | 15.7 Mb      |
| ![cpp](https://img.shields.io/badge/leetcode912--mergesort-cpp-f34b7d.svg)       | 44 ms   | 16.1 Mb      |
| ![cpp](https://img.shields.io/badge/leetcode912--mergesort__iter-cpp-f34b7d.svg) | 68 ms   | 16 Mb        |
| ![cpp](https://img.shields.io/badge/leetcode912--shellsort-cpp-f34b7d.svg)       | 48 ms   | 15.7 Mb      |
| ![cpp](https://img.shields.io/badge/leetcode912--shellsort__iter-cpp-f34b7d.svg) | 112 ms  | 15.7 Mb      |
| ![cpp](https://img.shields.io/badge/leetcode912--heapsort-cpp-f34b7d.svg)        | 52 ms   | 15.7 Mb      |
| ![python](https://img.shields.io/badge/leetcode912-py-3572A5.svg)                | 144 ms  | 20.2 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode912-rb-701516.svg)                  | 68 ms   | 12.7 Mb      |
| ![java](https://img.shields.io/badge/leetcode912-java-b07219.svg)                | 3 ms    | 47.2 Mb      |

## DESCRIPTION

Given an array of integers `nums`, sort the array in ascending order.

## NOTE

1. `1 <= nums.length <= 50000`
2. `-50000 <= nums[i] <= 50000`

## EXAMPLE 1

```plain
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
```

## EXAMPLE 2

```plain
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
```

## SOLUTION

* 快速排序
* 归并排序
* 希尔排序
* 堆排序

## CODE

### C++

```cpp
class Solution
{
    void quicksort(vector<int> &a, int left, int right) // inclusive
    {
        if (left >= right) return;
        if (left + 1 == right && a[left] > a[right])
            std::swap(a[left], a[right]);
        int i = left, j = right, tmp = a[left];
        while (i != j)
        {
            while (i < j && a[j] >= tmp) j--;
            while (i < j && a[i] <= tmp) i++;
            if (i >= j) continue;
            std::swap(a[i], a[j]);
        }
        std::swap(a[left], a[i]);
        quicksort(a, left, i - 1);
        quicksort(a, i + 1, right);
    }

    inline void quicksort(vector<int> &a) { quicksort(a, 0, a.size() - 1); }

    template <class _RIter>
    void quicksort_iter(_RIter left, _RIter right) // not inclusive
    {
        if (left >= right) return;
        // if (std::distance(left, right) == 2 && *left > *(left+1))
        //     std::swap(*left, *(left+1));
        _RIter i = left, j = right - 1;
        auto tmp = *left;
        while (i != j)
        {
            while (i < j && *j >= tmp) j--;
            while (i < j && *i <= tmp) i++;
            if (i >= j) continue;
            std::swap(*i, *j);
        }
        std::swap(*left, *i);
        quicksort_iter(left, i);
        quicksort_iter(i + 1, right);
    }

    vector<int> help;

    void merge(vector<int> &a, int left, int mid, int right)
    {
        int i = left, j = mid + 1, k = left;
        std::copy(a.begin() + left, head + right + 1, help.begin() + left);
        for (; i <= mid && j <= right; k++)
        {
            if (help[i] < help[j]) 
                a[k] = help[i++];
            else
                a[k] = help[j++];
        }
        while (i <= mid) a[k++] = help[i++];
        while (j <= right) a[k++] = help[j++];
    }
    
    void mergesort(vector<int> &a, int left, int right) // inclusive
    {
        if (left >= right) return;
        int mid = left + ((right - left) >> 1);
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        merge(a, left, mid, right);
    }

    inline void mergesort(vector<int> &a)
    {
        this->help = vector<int>(a.begin(), a.end());
        mergesort(a, 0, a.size() - 1);
    }

    template <class _RIter>
    void merge_iter(_RIter h_left, _RIter h_mid, _RIter h_right, _RIter left, _RIter right) // not inclusive
    {
        _RIter i = h_left, j = h_mid, k = left;
        std::copy(left, right, h_left);
        for (; i < h_mid && j < h_right; k++)
        {
            if (*i < *j) 
                *k = *(i++);
            else
                *k = *(j++);
        }
        while (i < h_mid) *(k++) = *(i++);
        while (j < h_right) *(k++) = *(j++);
    }

    template <class _RIter>
    void _mergesort_iter(_RIter left, _RIter right, _RIter h_left, _RIter h_right) // not inclusive
    {
        if (std::distance(left, right) <= 1) return;
        _RIter mid = left + (std::distance(left, right) >> 1);
        _RIter h_mid = h_left + (std::distance(h_left, h_right) >> 1);
        _mergesort_iter(left, mid, h_left, h_mid);
        _mergesort_iter(mid, right, h_mid, h_right);
        merge_iter(h_left, h_mid, h_right, left, right);
    }

    template <class _RIter>
    void mergesort_iter(_RIter st, _RIter ed) // not inclusive
    {
        this->help = vector<int>(st, ed);
        _mergesort_iter(st, ed, help.begin(), help.end());
    }

    template <typename _RIter>
    void insert_sort(_RIter st, _RIter ed, int delta) // not inclusive
    {
        for(_RIter i = st + delta; i < ed; i += delta)
            for(_RIter j = i; j > st; j -= delta)
                if(*j < *(j - delta)) std::swap(*j, *(j - delta));
                else break;
    }
    
    template <typename _RIter>
    void shellsort_iter(_RIter st, _RIter ed) // not inclusive
    {
        for(int delta = ed - st; delta; delta /= 2)
            for(int i = 0; i < delta; i++)
                insert_sort(st + i, ed, delta);
    }

    const int MAXT = 20;
    vector<int> shell_d;

    void shell_init()
    {
        shell_d = vector<int>(20, 0);
        shell_d[MAXT - 1] = 1;
        shell_d[MAXT - 2] = 2;
        for (int i = MAXT - 3; i >= 0; i--)
            shell_d[i] = (shell_d[i + 1] * 2) - 1;
    }

    void shell_insert(vector<int>& a, int sz, int d)
    {
        for (int i = d, j = 0, tmp = 0; i < sz; i++)
        {
            if (a[i] >= a[i - d]) continue;
            tmp = a[i];
            for (j = i - d; j >= 0 && tmp < a[j]; j -= d)
                a[j + d] = a[j];
            a[j + d] = tmp;
        }
    }

    void shellsort(vector<int> &a)
    {
        int sz = a.size(), t = 0;
        for (int i = 1; i < sz; i *= 2, t++);
        for (int k = MAXT - t; k < MAXT; k++)
            shell_insert(a, sz, shell_d[k]);
    }

    void max_heapify(vector<int> &a, int st, int ed)
    {
        int fa = st, child = (st << 1) + 1;
        while (child <= ed)
        {
            if (child + 1 <= ed && a[child] < a[child + 1]) child++;
            if (a[fa] > a[child]) return;
            std::swap(a[fa], a[child]);
            fa = child;
            child = (fa << 1) + 1;
        }
    }

    void heapsort(vector<int> &a)
    {
        int sz = a.size();
        for (int i = len / 2 - 1; i >= 0; i--) max_heapify(a, i, len - 1);
        for (int i = len - 1; i >= 0; i--)
        {
            std::swap(a[0], a[i]);
            max_heapify(a, 0, i - 1);
        }
    }

public:
    // Solution(){ shell_init(); }

    vector<int> sortArray(vector<int> &nums)
    {
        // std::sort(nums.begin(), nums.end());
        // quicksort_iter(nums.begin(), nums.end());
        // mergesort_iter(nums.begin(), nums.end());
        // shellsort_iter(nums.begin(), nums.end());
        // quicksort(nums, 0, nums.size() - 1);
        // mergesort(nums, 0, nums.size() - 1);
        // mergesort(nums);
        // shellsort(nums); // run init first!
        // heapsort(nums);
        return nums;
    }
};
```

### Python3

```python
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        return sorted(nums)
```

### Ruby

```ruby
# @param {Integer[]} nums
# @return {Integer[]}
def sort_array(nums)
  nums.sort
end
```

### Java

```java
class Solution {
    public int[] sortArray(int[] nums) {
        Arrays.sort(nums);
        return nums;
    }
}
```
