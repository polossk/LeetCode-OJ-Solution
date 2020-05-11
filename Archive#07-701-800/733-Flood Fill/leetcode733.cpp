// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                     ----Stay Hungry Stay Foolish----                       *
*   @author :   Shen                                                         *
*   @name   :   Leetcode 733                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

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

void test() {}

int main() { test(); return 0; }
