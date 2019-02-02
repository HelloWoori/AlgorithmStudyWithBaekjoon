/*
이동하기
https://www.acmicpc.net/problem/11048
*/
#include <iostream>
#include <vector>

using namespace std;

struct Pos
{
    int x;
    int y;

    Pos() : x(0), y(0) {}
    Pos(int _x, int _y) : x(_x), y(_y) {}

    bool isValid(Pos pos)
    {
        return(x >= 1 && x <= pos.x && y >= 1 && y <= pos.y);
    }

    Pos operator+(const Pos other) const
    {
        return Pos(x + other.x, y + other.y);
    }

    bool operator==(const Pos other) const
    {
        return (x == other.x && y == other.y);
    }
};


void solveProblem(const Pos& pos,
                  const Pos& now, 
                  const vector<Pos>& directions,
                  const vector<vector<int>>& maze, 
                        vector<vector<int>>& maxEat)
{
    for (const auto& direction : directions)
    {
        Pos next = now + direction;
        if (next.isValid(pos))
        {
            int temp = maxEat[now.y][now.x] + maze[next.y][next.x];
            if (temp > maxEat[next.y][next.x])
            {
                maxEat[next.y][next.x] = temp;
            }
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int height(0), width(0);
    cin >> height >> width;
   
    Pos pos(width, height);
    Pos start(1, 1);

    vector<vector<int>> maze(height + 1, vector<int>(width + 1, 0));
    vector<vector<int>> maxEat(height + 1, vector<int>(width + 1, 0));
  
    vector<Pos> directions;
    directions.reserve(3);
    directions.push_back(Pos(1, 0));
    directions.push_back(Pos(0, 1));
    directions.push_back(Pos(1, 1));

    for (int h = 1; h <= height; ++h)
    {
        for (int w = 1; w <= width; ++w)
        {
            cin >> maze[h][w];
        }
    }

    maxEat[start.y][start.x] = maze[start.y][start.x];
    for (int h = 1; h <= height; ++h)
    {
        for (int w = 1; w <= width; ++w)
        {
            solveProblem(pos, Pos(w, h), directions, maze, maxEat);
        }
    }

    //for debug
    //cout << '\n';
    //for (int h = 1; h <= height; ++h)
    //{
    //    for (int w = 1; w <= width; ++w)
    //    {
    //        cout << maxEat[h][w] << "  ";
    //    }
    //    cout << '\n';
    //}

    cout << maxEat[height][width] << '\n';
   
    return 0;
}