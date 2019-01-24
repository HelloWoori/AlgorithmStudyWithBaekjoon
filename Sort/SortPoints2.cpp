/*
좌표 정렬하기 2
https://www.acmicpc.net/problem/11651
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

    bool operator < (const Point other) const
    {
        if (y == other.y)
        {
            return x < other.x;
        }
        else
        {
            return y < other.y;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
   
    int theNumOfTestCases(0);
    cin >> theNumOfTestCases;

    vector<Point> points;
    points.reserve(theNumOfTestCases);

    while (theNumOfTestCases-- > 0)
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