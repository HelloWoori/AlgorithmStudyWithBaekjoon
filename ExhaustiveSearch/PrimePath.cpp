/*
소수 경로
https://www.acmicpc.net/problem/1963
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

const int N = 10000; //10,000까지의 소수
bool prime[N + 1];   //지워졌으면 true, 따라서 false이면 소수

bool visit[N + 1];   //방문 여부
int dist[N + 1];     //소수 변환에 필요한 최소 회수 저장

int solveProblem(int num, int idx, int digit)
{
    if (idx == 0 && digit == 0) return -1; //첫번째자리가 0인건 불가능
    //숫자를 문자열로 변경해, 해당 자리수의 숫자를 변경
    //문자열을 숫자로 변환해 리턴
    string s = to_string(num);
    s[idx] = digit + '0'; //숫자를 문자로
    return stoi(s);
}

int main()
{ 
    //소수인지 아닌지, 에라토스테네스의 체
    for (int i = 2; i <= N; ++i)
    {
        if (prime[i] == false)
        {
            for (int j = i * i; j <= N; j += i)
            {
                prime[j] = true;
            }
        }
    }

    int theNumOfTestCases = 0;
    scanf("%d", &theNumOfTestCases);

    //테스트 케이스 만큼 순회
    while (theNumOfTestCases-- > 0)
    {
        int origin = 0, goal = 0;
        scanf("%d %d", &origin, &goal);
       
        queue<int> q;
        q.push(origin);

        memset(visit, false, sizeof(visit));
        memset(dist, 0, sizeof(dist));

        visit[origin] = true;
        dist[origin] = 0;

        while (false == q.empty())
        {
            int now = q.front();
            q.pop();

            for (int idx = 0; idx < 4; ++idx)
            {
                for (int digit = 0; digit <= 9; ++digit)
                {
                    int next = solveProblem(now, idx, digit);
                    if (next != -1) //변경이 불가능 하지 않고
                    {
                        //소수이면서, 아직 방문하지 않았다면
                        if (prime[next] == false && visit[next] == false)
                        {
                            q.push(next);
                            dist[next] = dist[now] + 1;
                            visit[next] = true;
                        }
                    }
                }
            }
        }

        printf("%d\n", dist[goal]);
    }

    return 0;
}