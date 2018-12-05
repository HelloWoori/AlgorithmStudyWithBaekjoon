#include <iostream>
#include <vector>
#include <string>
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
        return (x >= 1 && x <= size.x && y >= 1 && y <= size.y);
    }

};

void bfs(const Pos& start,
         const Pos& size,
         const vector<vector<int>>& maze,
         const vector<Pos>& directions,
               vector<vector<int>>& check)
{
    queue<Pos> q;
    q.push(start);
    check[start.y][start.x] = 1;

    while (false == q.empty())
    {
        Pos current = q.front();
        q.pop();

        for (const Pos& direction : directions)
        {
            Pos pos = current + direction;

            if (false == pos.isValid(size))
            {
                continue;
            }

            if (maze[pos.y][pos.x] == 1 &&
                check[pos.y][pos.x] == 0)
            {
                q.push(pos);
                check[pos.y][pos.x] = check[current.y][current.x] + 1;
            }
        }
    
    }

}

int main()
{
    ios_base::sync_with_stdio(false);

    int height(0), width(0);
    cin >> height >> width;

    Pos size(width, height);

    vector<vector<int>> maze(height + 1, vector<int>(width + 1, 0)); //0번째 열은 사용하지 않는다
    vector<vector<int>> check(height + 1, vector<int>(width + 1, 0));
  
    vector<Pos> directions;
    directions.reserve(4);
    directions.push_back(Pos(0,  1)); //상
    directions.push_back(Pos(0, -1)); //하
    directions.push_back(Pos(-1, 0)); //좌
    directions.push_back(Pos( 1, 0)); //우

    //미로 생성
    for (int y = 1; y <= size.y; ++y)
    {
        int cnt = 0;
        string str("");
        cin >> str;
        for (const auto& ch : str)
        {
            cnt++;
            maze[y][cnt] = ch - '0';
        }
    }

    //for debug
    //cout << '\n';
    //for (int y = 1; y <= size.y; ++y)
    //{
    //    for (int x = 1; x <= size.x; ++x)
    //    {
    //        cout << maze[y][x] << ' ';
    //    }
    //    cout << '\n';
    //}

    //미로 탐색 시작
    Pos start(1, 1);
    bfs(start, size, maze, directions, check);

    //result
    cout << check[size.y][size.x] << '\n';

    return 0;
}