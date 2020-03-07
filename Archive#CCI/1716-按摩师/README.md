# 按摩师

![Easy](https://img.shields.io/badge/-Easy-5cb85c.svg) ![Dynamic_Programming](https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg)

## RESULT

| Submission                                                    | Runtime | Memory Usage |
| ------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/cci1716-cpp-f34b7d.svg)   | 0 ms    | 7.6 Mb       |
| ![python](https://img.shields.io/badge/cci1716-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/cci1716-rb-701516.svg)   | -       | -            |

## DESCRIPTION

一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

注意：本题相对原题稍作改动

## EXAMPLE 1

```plain
输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
示例 2：
```

## EXAMPLE 2

```plain
输入： [2,7,9,3,1]
输出： 12
解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
示例 3：
```

## EXAMPLE 3

```plain
输入： [2,1,4,5,3,1,1,3]
输出： 12
解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。
```

## SOLUTION

* 定义 `dp[i][0]` 表示考虑前 `i` 个预约，第 `i` 个预约不接的最长预约时间，`dp[i][1]` 表示考虑前 `i` 个预约，第 `i` 个预约接的最长预约时间。
* 对于前者，显然由于这次已经不接预约了，所以前 `i-1` 个预约并不影响后面的决策，由此可得状态转移方程 `dp[i][0] = max(dp[i-1][0], dp[i-1][1])`
* 对于后者，既然这次的预约已经接纳，也就说明前一个预约（第 `i-1` 个）不能接受，所以此时的状态转移方程为 `dp[i][1] = dp[i-1][0] + nums[i]`
* 注意到，这是一个线性递推问题，所以不需要额外开数组，只需要记录两个值即可

## CODE

### C++

```cpp
class Solution
{
public:
    int massage(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0) return 0;
        int dp0 = 0, dp1 = nums[0];
        for (int i = 1; i < n; i++){
            int tmp_dp0 = max(dp0, dp1);
            int tmp_dp1 = dp0 + nums[i];
            dp0 = tmp_dp0;
            dp1 = tmp_dp1;
        }
        return max(dp0, dp1);
    }
};
```

### Python3


### Ruby

