# 交点

![Hard](https://img.shields.io/badge/-Hard-e05d44.svg) ![Geometry](https://img.shields.io/badge/几何-Geometry-007ec6.svg) ![Math](https://img.shields.io/badge/数学-Math-007ec6.svg) 

## RESULT

| Submission                                                    | Runtime | Memory Usage |
| ------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/cci1603-cpp-f34b7d.svg)   | 0 ms    | 11.2 Mb      |
| ![python](https://img.shields.io/badge/cci1603-py-3572A5.svg) | -       | -            |
| ![ruby](https://img.shields.io/badge/cci1603-rb-701516.svg)   | -       | -            |

## DESCRIPTION

给定两条线段（表示为起点 `start = {X1, Y1}` 和终点 `end = {X2, Y2}` ），如果它们有交点，请计算其交点，没有交点则返回空值。

要求浮点型误差不超过 `10^-6`。若有多个交点（线段重叠）则返回 X 值最小的点，X 坐标相同则返回 Y 值最小的点。

## EXAMPLE 1

```plain
输入：
line1 = {0, 0}, {1, 0}
line2 = {1, 1}, {0, -1}
输出： {0.5, 0}
```

## EXAMPLE 2

```plain
输入：
line1 = {0, 0}, {3, 3}
line2 = {1, 1}, {2, 2}
输出： {1, 1}
```

## EXAMPLE 3

```plain
输入：
line1 = {0, 0}, {1, 1}
line2 = {1, 0}, {2, 1}
输出： {}，两条线段没有交点
```

## NOTE

* 坐标绝对值不会超过 2^7
* 输入的坐标均是有效的二维坐标

## SOLUTION

* 计算几何基础，通过向量叉乘判断共线与是否同侧（异侧）

## CODE

### C++

```cpp
const double EPS = 1e-8;
const double MAX = 1e12;

inline double zero(double x) { return (x > 0 ? x : -x) < EPS; }

struct Point { double x, y;
    Point(): x(0), y(0) {}
    Point(double _x, double _y): x(_x), y(_y) {}
    friend ostream& operator<<(ostream &os, const Point _)
    {
        os << "(" << _.x << ", " << _.y << ")";
        return os;
    }
};
using CRPoint = const Point&;

struct Segment { Point a, b;
    Segment(): a(Point()), b(Point()) {}
    Segment(CRPoint _a, CRPoint _b): a(_a), b(_b) {}
    friend ostream& operator<<(ostream &os, const Segment _)
    {
        os << "[" << _.a << "->" << _.b << "]";
        return os;
    }
};

using CRSegment = const Segment&;

// cross product (P1 - P0) x (P2 - P0)
inline double xmult(CRPoint p1, CRPoint p2, CRPoint p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

inline int dots_inline(CRPoint p1, CRPoint p2, CRPoint p3)
{
    return zero(xmult(p1, p2, p3));
}

// include the endpoints
inline int dot_online_in(CRPoint p, CRSegment l)
{
    return zero(xmult(p, l.a, l.b))
        && (l.a.x - p.x) * (l.b.x - p.x) < EPS
        && (l.a.y - p.y) * (l.b.y - p.y) < EPS;
}

// return 1 if same line
inline int same_line(CRSegment u, CRSegment v)
{
    return dots_inline(u.a, u.b, v.a) || dots_inline(u.a, u.b, v.b);
}

// return 1 if same side
// when point is on segment, it yields 0
inline int same_side(CRPoint p1, CRPoint p2, CRSegment l)
{
    return xmult(l.a, p1, l.b) * xmult(l.a, p2, l.b) > EPS;
}

// 判两线段相交,包括端点和部分重合
int intersect_in(CRSegment u, CRSegment v)
{
    if (!dots_inline(u.a, u.b, v.a) || !dots_inline(u.a, u.b, v.b))
        return !same_side(u.a, u.b, v) && !same_side(v.a, v.b, u);
    return dot_online_in(u.a, v) || dot_online_in(u.b, v)
        || dot_online_in(v.a, u) || dot_online_in(v.b, u);
}

Point get_intersection(CRPoint u1, CRPoint u2, CRPoint v1, CRPoint v2)
{
    Point ret = u1;
    double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x))
        / ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
    ret.x += (u2.x - u1.x) * t;
    ret.y += (u2.y - u1.y) * t;
    return ret;
}

class Solution
{
    using P2dI = std::vector<int>;
    using P2dD = std::vector<double>;
public:
    P2dD intersection(P2dI &_A, P2dI &_B, P2dI &_C, P2dI &_D)
    {
#define meta(X) X = Point(_##X[0], _##X[1])
        Point meta(A), meta(B), meta(C), meta(D);
#undef meta
        Segment u{A, B}, v{C, D};
        if (same_line(u, v))
        {
            // for (ijk) in [(023), (123), (201), (301)]
            // test of p_i in {p_j, p_k} and return MOST LEFT-DOWN point
            Point *P[4] = {&A, &B, &C, &D};
            Segment *S[2] = {&v, &u};
            auto cmp_MOST_LEFT_DOWN = [](CRPoint a, CRPoint b) -> bool
            {
                return a.x != b.x ? (a.x < b.x) : (a.y < b.y);
            };
            Point ret = {MAX, MAX};
            bool flag = false;
            for (int i = 0; i < 4; i++)
            {
                if (!dot_online_in(*P[i], *S[i>>1]))
                    continue;
                ret = min(ret, *P[i], cmp_MOST_LEFT_DOWN);
                flag = true;
            }
            if (!flag) return P2dD();
            return P2dD({ret.x, ret.y});
        }
        if (!intersect_in(u, v)) return P2dD();
        Point ret = get_intersection(A, B, C, D);
        return P2dD({ret.x, ret.y});
    }
};
```

### Python3


### Ruby

