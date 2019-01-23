/*
좌표 정렬하기
https://www.acmicpc.net/problem/11650
- https://www.acmicpc.net/blog/view/22 (비교 연산자 오버로딩과 관련해서 참고한 글)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}

    Point bigger(Point other)
    {
        if (x == other.x)
        {
            if (y > other.y)
                return Point(x, y);
        }
        else if (x > other.x)
        {
            return Point(x, y);
        }
        else
        {
            return Point(other.x, other.y);
        }
    }

    bool operator < (const Point& other) const
    {
        if (x == other.x)
        {
            return (y < other.y);
        }
        return (x < other.x);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    
    int num(0);
    cin >> num;
    
    vector<Point> points;
    points.reserve(num);

    while (num-- > 0)
    {
        int x(0), y(0);
        cin >> x >> y;
        points.push_back(Point(x, y));
    }

    sort(points.begin(), points.end());

    for (const auto point : points)
    {
        cout << point.x << " " << point.y << '\n';
    }

    return 0;
}