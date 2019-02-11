/*
숨바꼭질
https://www.acmicpc.net/problem/1697
*/
#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 200000;
int check[MAX + 1];//0: 방문하지 않음, 1: 방문함
int dist[MAX + 1]; //트리의 높이 저장

void solveProblem(const int startPos, 
                  const int NextPos, 
                  queue<int>& q)
{
    if (NextPos >= 0 && NextPos < MAX)
    {
        if (check[NextPos] == 0)
        {
            q.push(NextPos);
            check[NextPos] = 1;
            dist[NextPos] = dist[startPos] + 1;
        }
    }
}

int main()
{ 
    queue<int> q;

    int me(0), sister(0);
    scanf("%d %d", &me, &sister);

    q.push(me);
    check[me] = 1;
    dist[me] = 0;
    
    while (false == q.empty())
    {
        int position = q.front();
        q.pop();

        if (position == sister) break;

        solveProblem(position, position - 1, q);
        solveProblem(position, position + 1, q);
        solveProblem(position, position * 2, q);
    }

    printf("%d\n", dist[sister]);

    return 0;
}