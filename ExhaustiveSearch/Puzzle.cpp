/*
퍼즐
https://www.acmicpc.net/problem/1525
*/
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool cantGoRight(int n)
{
    return (n == 2 || n == 5 || n == 8); //2, 5, 8
}

bool cantGoLeft(int n)
{
    return (n == 0 || n == 3 || n == 6); //0, 3, 6
}

bool cantGoUp(int n)
{
    return (n <= 2); //0, 1, 2
}

bool cantGoDown(int n)
{
    return (n >= 6); //6, 7, 8
}

int main()
{
    const int SIZE = 9;
    const int end = 123456789;
    vector<int> directions = { -3, 3, -1, 1 }; //상, 하, 좌, 우
    
    string str;
    for (int i = 0; i < SIZE; ++i)
    {
        int input(0);
        scanf("%d", &input);
        if (input == 0) input = 9; //0이면 9로 바꾼다 (int 변환 때문)
        str.push_back(input + '0');
    }

    int start = stoi(str);
    map<int, int> distance; //순열, 최소의 이동 횟수
    queue<int> q; 

    q.push(start);
    distance[start] = 0;

    while (false == q.empty())
    {
        int now = q.front();
        if (now == end) break;
        q.pop();

        string zeroIdxStr = to_string(now);
        int zeroIdx = static_cast<int>(zeroIdxStr.find('9'));

        for (const auto& direction : directions)
        {
            if (cantGoUp(zeroIdx)    && direction == -3) continue;
            if (cantGoDown(zeroIdx)  && direction ==  3) continue;
            if (cantGoLeft(zeroIdx)  && direction == -1) continue;
            if (cantGoRight(zeroIdx) && direction ==  1) continue;

            int nextIdx = zeroIdx + direction;

            string nextStr = zeroIdxStr;
            char temp = nextStr[zeroIdx];
            nextStr[zeroIdx] = nextStr[nextIdx];
            nextStr[nextIdx] = temp;

            int next = stoi(nextStr);
            if (distance.count(next) == 0)
            {
                q.push(next);
                distance[next] = distance[now] + 1;
                //printf("next: %d, distance: %d\n", next, distance[next]);
            }
        }
    }

    if (distance.count(end) == 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", distance[end]);
    }

    return 0;
}

/*
2 5 7
8 0 3
4 1 6
답: 18

6 4 7
8 5 0
3 2 1
답: 31
*/