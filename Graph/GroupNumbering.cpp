/*
단지번호붙이기
https://www.acmicpc.net/problem/2667
- https://www.acmicpc.net/board/view/30151 (문제풀때 주의해야할 점)
- https://www.acmicpc.net/board/view/22747 (추가예제)
*/
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
using namespace std;


struct Pos
{
    int x;
    int y;

    Pos() : x(0), y(0) {}
    Pos(const int _x, const int _y) : x(_x), y(_y) {}

    Pos operator+(const Pos& other)
    {
        return Pos(x + other.x, y + other.y);
    }

    bool operator==(const Pos& other)
    {
        return (x == other.x && y == other.y);
    }

    
    bool isValid(const int size)
    {
        return (x >= 0 && x < size && y >=0 && y < size);
    }
};

//(x, y)좌표 map, check, groupIndex(몇 단지인지), count (집의 수 구하기 위함)
void bfs(
    const Pos pos, 
    const vector<vector<int>>& map, 
    const vector<Pos>& directions,
    vector<vector<int>>& groups,
    int groupIndex,
    int* pCount)
{
    *pCount = 1;

    queue<Pos> q;
    q.push(pos);
    groups[pos.y][pos.x] = groupIndex;

    while (false == q.empty())
    {
        Pos current = q.front();
        q.pop();

        //상하좌우 체크
        for (const Pos& direction : directions)
        {
            Pos pos = current + direction;

            //위치가 범위를 넘어서면 재낀다
            if (false == pos.isValid(map.size()))
            {
                continue;
            }

            //위치가 범위 내고, 방문가능하며(1), 아직 방문하지 않았을 경우
            if (map[pos.y][pos.x] == 1 &&
                groups[pos.y][pos.x] == 0)
            {
                (*pCount)++;
                q.push(pos);
                groups[pos.y][pos.x] = groupIndex;
            }
        
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int size; //지도의 크기
    cin >> size;

    vector<vector<int>> map(size);
    vector<vector<int>> groups(size, vector<int> (size, 0)); //방문했는지, 방문했다면 단지 번호 붙이기
    
    vector<Pos> directions;
    directions.reserve(4);
    
    multiset<int> theNumOfHouses; //중복값 저장 위함 + 오름차순

    directions.push_back(Pos(0,  1)); //상
    directions.push_back(Pos(0, -1)); //하
    directions.push_back(Pos(-1, 0)); //좌
    directions.push_back(Pos( 1, 0)); //우
    
    for (int x = 0; x < size; ++x)
    {
        string numbers;
        cin >> numbers;
        for (auto& num : numbers)
        {
            map[x].push_back(num - '0');
        }
    }

    //for debug
    //cout << '\n';
    //for (int y = 0; y < size; ++y)
    //{
    //    for (int x = 0; x < size; ++x)
    //    {
    //        cout << map[y][x] << ' ';
    //    }
    //    cout << '\n';
    //}

    int groupIndex = 0;
    int count = 0;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            if (map[y][x] == 1 && groups[y][x] == 0)
            {
                //집이 있는 곳(1) 이면서, 아직 방문하지 않았다면
                //너비 우선 탐색 시작
                Pos pos(x, y);
                groupIndex++;

                bfs(pos, map, directions, groups, groupIndex, &count);

                theNumOfHouses.insert(count);
            }
        }
    }

    //for debug
    //cout << '\n';
    //for (int y = 0; y < size; ++y)
    //{
    //    for (int x = 0; x < size; ++x)
    //    {
    //        cout << groups[y][x] << ' ';
    //    }
    //    cout << '\n';
    //}
    
    //result
    cout << groupIndex << '\n';
    for (auto& num : theNumOfHouses)
    {
        cout << num << '\n';
    }

    return 0;
}