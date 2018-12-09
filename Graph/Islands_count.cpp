/*
섬의 개수
https://www.acmicpc.net/problem/4963
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos
{
    int x;
    int y;

    Pos() : x(0), y(0) {}
    Pos(int _x, int _y) : x(_x), y(_y) {}

    Pos operator+(const Pos& other)
    {
        return Pos(x + other.x, y + other.y);
    }

    bool isValid(const Pos& size)
    {
        return (x >= 0 && x < size.x && y >= 0 && y <  size.y);
    }
};


void bfs(
    const Pos& start, 
    const Pos& size, //너비, 높이
    const vector<vector<int>>& map,
    const vector<Pos>& directions,
    vector<vector<int>>& visited,
    const int count)
{
    queue<Pos> q;
    q.push(start);
    visited[start.y][start.x] = count;

    while (false == q.empty())
    {
        Pos current = q.front();
        q.pop();
        
        //8방면 체크
        for (const Pos& direction : directions)
        {
            Pos pos = current + direction;

            //범위 내에 있고
            if (pos.isValid(size))
            {
                if (map[pos.y][pos.x] == 1 &&
                    visited[pos.y][pos.x] == 0)
                {
                    q.push(pos);
                    visited[pos.y][pos.x] = count;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    while (true)
    {
        int width, height;
        cin >> width >> height;

        //입력의 마지막 줄에는 0이 두 개 주어진다
        if (width == 0 && height == 0)
            break;

        Pos size(width, height);

        vector<vector<int>> map(height);
        vector<vector<int>> visited(height, vector<int>(width, 0));

        vector<Pos> directions;
        directions.reserve(8); //가로, 세로, 대각선

        directions.push_back(Pos(0, 1));   //상
        directions.push_back(Pos(0, -1));  //하
        directions.push_back(Pos(-1, 0));  //좌
        directions.push_back(Pos(1, 0));   //우

        directions.push_back(Pos(-1, 1));  //좌상
        directions.push_back(Pos(1, 1));   //우상
        directions.push_back(Pos(-1, -1)); //좌하
        directions.push_back(Pos(1, -1));  //우하

        //맵 생성
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                int input;
                cin >> input;
                map[y].push_back(input);
            }
        }

        //for debug
        //cout << '\n';
        //for (int y = 0; y < height; ++y)
        //{
        //    for (int x = 0; x < width; ++x)
        //    {
        //        cout << map[y][x] << ' ';
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';

        int count = 0;
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                //1이고, 방문하지 않았다면 너비 우선 탐색 진행
                if (map[y][x] == 1 &&
                    visited[y][x] == 0)
                {
                    count++;
                    bfs(Pos(x, y), size, map, directions, visited, count);
                }
            }

        }

        //for debug
        //cout << '\n';
        //for (int y = 0; y < height; ++y)
        //{
        //    for (int x = 0; x < width; ++x)
        //    {
        //        cout << visited[y][x] << ' ';
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';


        //result
        cout << count << '\n';
    }

    return 0;
}