/*
토마토
https://www.acmicpc.net/problem/7576
*/
#include <iostream>
#include <vector>
#include <deque>

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


int main()
{
    ios_base::sync_with_stdio(false);

    int width(0);
    int height(0);
    cin >> width >> height;
    
    vector<vector<int>> tomato(height, vector<int>(width, -1));
    vector<vector<int>> check(height, vector<int>(width, -1));
    deque<Pos> q; //토마토 탐색용

    int theNumOfTomatoes(0);    //전체 토마토 개수
    int theNumRipenTomatoes(0); //처음부터 익어있던 토마토 개수
    int count(0);
    int day(0);

    //익은 토마토는 익지않은 토마토에 영향을 준다, 4방향
    vector<Pos> directions;
    directions.reserve(4);
    directions.push_back(Pos(0, 1));
    directions.push_back(Pos(0, -1));
    directions.push_back(Pos(-1, 0));
    directions.push_back(Pos(1, 0));

    //토마토 상자 만들기
    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < width; ++w)
        {
            int input(0);
            cin >> input;
            
            tomato[h][w] = input;

            //토마토 개수 세기
            if (input != -1)
            {
                theNumOfTomatoes++;
            }

            //토마토가 익을 시작점
            if (tomato[h][w] == 1)
            {
                q.push_back(Pos(w, h));
                check[h][w] = 0;
                count++;
                theNumRipenTomatoes++;
            }
        }
    }
    
    //토마토 익히기 시작
    while (false == q.empty())
    {
        Pos current = q.front();
        q.pop_front();

        for (const auto& direction : directions)
        {
            Pos next = current + direction;

            if (next.isValid(Pos(width, height)))
            {
                //아직 방문하지 않았고, 토마토가 익지않았다면
                if (check[next.y][next.x] == -1 &&
                    tomato[next.y][next.x] == 0)
                {
                    q.push_back(next);
                    check[next.y][next.x] = check[current.y][current.x] + 1;

                    //익힌 토마토 개수
                    count++;

                    //날짜
                    day = check[next.y][next.x];
                }
            }
        }
    }


    //for debug
    //cout << '\n';
    //for (int h = 0; h < height; ++h)
    //{
    //    for (int w = 0; w < width; ++w)
    //    {
    //        cout << check[h][w] << ' ';
    //    }
    //    cout << '\n';
    //}

    //cout << "count: " << count << '\n';
    //cout << "theNumOfTomatoes: " << theNumOfTomatoes << '\n';

    //result
    if(theNumRipenTomatoes == theNumOfTomatoes) //이미 모든 토마토가 익어있다면
    {
        cout << "0" << '\n';
    }
    else if(count != theNumOfTomatoes) //모든 토마토가 익지 못하면
    {
        cout << "-1" << '\n';
    }
    else //모든 토마토가 익었다면, 익을 때까지의 최소날짜
    {
        cout << day << '\n';
    }

    return 0;
}