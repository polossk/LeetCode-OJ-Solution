# Game of Life

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![Array](https://img.shields.io/badge/数组-Array-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode289-cpp-f34b7d.svg)   | 0 ms    | 6.6 Mb       |
| ![python](https://img.shields.io/badge/leetcode289-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode289-rb-701516.svg)   | -       | -            |

## DESCRIPTION

According to the [Wikipedia's article](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life): "The **Game of Life**, also known simply as **Life**, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with [its eight neighbors](https://en.wikipedia.org/wiki/Moore_neighborhood) (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by over-population..
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

## EXAMPLE

```plain
Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
```

## FOLLOW UP

1. Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
2. In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

## SOLUTION

* 用 `0b1x` 表示下一阶段活着的元胞状态，`0b0x` 表示下一阶段死亡的元胞状态，然后按规则赋值即可
* 处理完之后，整体右移一位，就得到了下一阶段的状态

## CODE

### C++

```cpp
class Solution {
    static const int MAXD = 8;
    const int dx[MAXD] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[MAXD] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int row_, col_;

public:
    void gameOfLife(vector<vector<int>>& board)
    {
        this->row_ = board.size();
        if (this->row_ == 0) return;
        this->col_ = board[0].size();
        if (this->col_ == 0) return;
        for (int i = 0; i < row_; i++)
            for (int j = 0; j < col_; j++)
        {
            int cnt = 0, &ref = board[i][j];
            for (int k = 0; k < MAXD; k++)
            {
                int ii = i + dx[k], jj = j + dy[k];
                if (ii < 0 || ii >= row_ || jj < 0 || jj >= col_) continue;
                cnt += (board[ii][jj] & 1);
            }
            if (ref == 1 && (cnt == 2 || cnt == 3))
                ref = 3; // 0b11
            if (ref == 0 && cnt == 3)
                ref = 2; // 0b10
            // otherwise 0b00 or 0b01
        }
        for (int i = 0; i < row_; i++)
            for (int j = 0; j < col_; j++)
                board[i][j] >>= 1;
    }
};
```

### Python3

### Ruby

### Java
