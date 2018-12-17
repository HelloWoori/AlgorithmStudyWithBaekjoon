/*
섬의 개수 구하기 심화
섬의 둘레 구하기
*/

/*
예제 1)
4 4
1 0 1 1
0 0 1 1
1 1 0 1
1 1 0 0
섬 각각의 둘레는 4, 8, 10
답: 22

예제 2)
4 5
0 0 1 0 0
0 1 1 0 1
0 0 1 0 1
1 1 1 0 1
섬 각각의 둘레는 16, 8
답: 24
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
        return (x >= 0 && x < size.x && y >= 0 && y < size.y);
    }

};

int bfs(const Pos& start,
        const Pos& size,
        const vector<vector<int>>& map,
        const vector<Pos>& directions,
        const int group,
               vector<vector<int>>& check)
{
    queue<Pos> q;
    q.push(start);
    check[start.y][start.x] = group; //방문함

    queue<Pos> circumQ; //둘레 구하기용
    circumQ.push(start);

    //섬 구하기
    while (false == q.empty())
    {
        Pos current = q.front();
        q.pop();

        for (const auto& direction : directions)
        {
            Pos next = current + direction;
            if (next.isValid(size))
            {
                if (map[next.y][next.x] == 1 &&
                    check[next.y][next.x] == 0)
                {
                    q.push(next);
                    check[next.y][next.x] = group;

                    circumQ.push(next);                      
                }
            }
        }
    }

    //섬 둘레 구하기
    int circum = 0;
    while (false == circumQ.empty())
    {
        Pos current = circumQ.front();
        circumQ.pop();

        for (const auto& direction : directions)
        {
            Pos next = current + direction;
            if (false == next.isValid(size))
            {
                circum++;
                continue;
            }

            if (check[next.y][next.x] != check[current.y][current.x])
            {
                circum++;
            }        
        }
    }
    return circum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int height(0), width(0);
    cin >> height >> width;

    Pos size(width, height);

    vector<vector<int>> map(height, vector<int>(width, 0));
    vector<vector<int>> check(height, vector<int>(width, 0));

    vector<Pos> directions;
    directions.reserve(4);
    directions.push_back(Pos(0, 1));
    directions.push_back(Pos(0, -1));
    directions.push_back(Pos(-1, 0));
    directions.push_back(Pos(1, 0));

    //맵 생성
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int input(0);
            cin >> input;
            map[y][x] = input;
        }
    }

    //섬 구하기
    vector<int> circums;
    int circum = 0;
    int group = 1;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (map[y][x] == 1 &&
                check[y][x] == 0) //섬이면서, 아직 방문하지 않았다면 탐색 시작 
            {
                circum = bfs(Pos(x, y), size, map, directions, group, check);
                group++;
                circums.push_back(circum);
            }
        }
    }

    //for debug
    cout << '\n';
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            cout << check[y][x] << ' ';
        }
        cout << '\n';
    }

    //각각의 섬 둘레 및 전체 합 출력
    cout << '\n';
    int sum = 0;
    for (const auto& c : circums)
    {
        sum += c;
        cout << c << ' ';
    }
    cout << '\n' << "sum: " << sum << '\n';

    return 0;
}