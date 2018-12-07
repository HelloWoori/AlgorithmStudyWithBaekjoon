/*
다리 만들기
https://www.acmicpc.net/problem/2146
- https://www.acmicpc.net/board/view/16995 (추가 예제)
*/
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Pos
{
    int x;
    int y;

    Pos() : x(0), y(0){}
    Pos(int _x, int _y) : x(_x), y(_y){}

    Pos operator+(const Pos& other)
    {
        return Pos(x + other.x, y + other.y);
    }

    bool isValid(int size)
    {
        return (x >= 0 && x < size &&  y >= 0 && y < size);
    }

};

void bfs(const Pos& start,
         const int size,
         const vector<Pos>& directions,
         const vector<vector<int>>& map,
               vector<vector<int>>& groups,
               int group)
{
    deque<Pos> q;
    q.push_back(start);
    groups[start.y][start.x] = group;

    while (false == q.empty())
    {
        Pos current = q.front();
        q.pop_front();

        for (const auto& direction : directions)
        {
            Pos next = current + direction;

            if (next.isValid(size))
            {
                if (map[next.y][next.x] == 1 &&
                    groups[next.y][next.x] == 0)
                {
                    q.push_back(next);
                    groups[next.y][next.x] = group;
                }
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);

    int size(0);
    cin >> size;
    vector<vector<int>> map(size, vector<int>(size, 0));
    vector<vector<int>> groups(size, vector<int>(size, 0));
    vector<vector<int>> distance(size, vector<int>(size, -1)); //섬까지의 거리 저장용
    
    vector<Pos> directions;
    directions.reserve(4);
    directions.push_back(Pos(0, 1));
    directions.push_back(Pos(0, -1));
    directions.push_back(Pos(-1, 0));
    directions.push_back(Pos(1, 0));


    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            int input(0);
            cin >> input;
            map[i][j] = input;
        }
    }

    //섬 구하기
    int group(1);
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (map[i][j] == 1 &&
                groups[i][j] == 0)
            {
                bfs(Pos(j, i), size, directions, map, groups, group);
                group++;
            }
        }
    }

    //섬 사이 거리 구하기 준비
    deque<Pos> distanceQ;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (map[i][j] == 1)
            {
                distanceQ.push_back(Pos(j, i));
                distance[i][j] = 0;
            }
        }
    }

    while (false == distanceQ.empty())
    {
        Pos current = distanceQ.front();
        distanceQ.pop_front();

        for (const auto& direction : directions)
        {
            Pos next = current + direction;
            if (next.isValid(size))
            {
                if (distance[next.y][next.x] == -1)
                {
                    distanceQ.push_back(next);
                    
                    groups[next.y][next.x] = groups[current.y][current.x];
                    distance[next.y][next.x] = distance[current.y][current.x] + 1;

                    distanceQ.push_back(next);
                }
            }
        }
    }


    //섬 사이 거리 구하기
    //상하좌우를 체크했는데 같은 그룹이 아닌경우 그 거리를 더함
    //이 거리가 가장 짧은 거리가 정답
    int ans = -1;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            for (const auto& direction : directions)
            {
                Pos next = Pos(j, i) + direction;
                if (next.isValid(size))
                {
                    int distCurrent = distance[i][j];
                    int distNext = distance[next.y][next.x];
                    if (groups[i][j] != groups[next.y][next.x])
                    {
                        if (ans == -1 || ans > distCurrent + distNext)
                        {
                            ans = distCurrent + distNext;
                        }
                    }
                }
            }
        }
    }

    //result
    cout << ans << '\n';


    //for debug
    //cout << '\n';
    //for (int i = 0; i < size; ++i)
    //{
    //    for (int j = 0; j < size; ++j)
    //    {
    //        cout << groups[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}

    //cout << '\n';
    //for (int i = 0; i < size; ++i)
    //{
    //    for (int j = 0; j < size; ++j)
    //    {
    //        cout << distance[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}

    return 0;
}