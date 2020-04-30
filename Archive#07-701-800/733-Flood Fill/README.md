# Flood Fill

![Easy](../../materials/-Easy-5cb85c.svg) ![Depth--first_Search](../../materials/深度优先搜索-Depth--first_Search-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode733-cpp-f34b7d.svg)   | 20 ms   | 13.9 Mb      |
| ![python](https://img.shields.io/badge/leetcode733-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/leetcode733-rb-701516.svg)   | -       | -            |

## DESCRIPTION

An `image` is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate `(sr, sc)` representing the starting pixel (row and column) of the flood fill, and a pixel value `newColor`, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

## NOTE

* The length of `image` and `image[0]` will be in the range `[1, 50]`.
* The given starting pixel will satisfy `0 <= sr < image.length` and `0 <= sc < image[0].length`.
The value of each color in `image[i][j]` and `newColor` will be an integer in `[0, 65535]`.

## EXAMPLE 1

```plain
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
```

## SOLUTION

* 从起点开始深度优先搜索即可

## CODE

### C++

```cpp
class Solution
{
    using Image = std::vector<std::vector<int>>;
    int old_, new_, maxrow_, maxcol_;
    constexpr static int dx[] = {0, 1, 0, -1};
    constexpr static int dy[] = {1, 0, -1, 0};
    constexpr static int MAXD = 4;

    inline bool valid(int x, int y)
    {
        return x >= 0 && x < maxrow_ && y >= 0 && y < maxcol_;
    }

    void render(Image &image, int x, int y)
    {
        if (old_ != image[x][y]) return;
        image[x][y] = new_;
        for (int i = 0; i < MAXD; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (!valid(nx, ny)) continue;
            render(image, nx, ny);
        }
    }
public:
    Image floodFill(Image &image, int sr, int sc, int newColor)
    {
        this->old_ = image[sr][sc];
        this->new_ = newColor;
        this->maxrow_ = image.size();
        this->maxcol_ = image[0].size();
        if (old_ != new_) render(image, sr, sc);
        return image;
    }
};
```

### Python3

### Ruby

### Java
