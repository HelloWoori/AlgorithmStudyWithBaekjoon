/*
DSLR
https://www.acmicpc.net/problem/9019
*/
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int D(int num)
{
    num *= 2;
    if (num > 9999)
        num %= 10000;

    return num;
}

int S(int num)
{
    if (num == 0)
        num = 9999;
    else
        num -= 1;

    return num;
}

int L(int num)
{
    return static_cast<int>(num % 1000) * 10 + static_cast<int>(num / 1000);
}

int R(int num)
{
    return static_cast<int>(num / 10) + (num % 10) * 1000;
}

void checkAndPush(const int now, 
                        vector<bool>& check, 
                        vector<char>& cmd, 
                        vector<int>& parent,
                        queue<int>& q, int next, char ch)
{
    if (check[next] == false)
    {
        q.push(next);
        check[next] = true;
        
        parent[next] = now;
        cmd[next] = ch;
    }
}

int main()
{
    const int MAX = 10000;

    int theNumOfTestCases = 0;
    scanf("%d", &theNumOfTestCases);

    while (theNumOfTestCases-- > 0)
    {
        int origin = 0, goal = 0;
        scanf("%d %d", &origin, &goal);

        vector<bool> check(MAX + 1);
        vector<char> cmd(MAX + 1);
        vector<int> parent(MAX + 1, -1);
        queue<int> q;

        q.push(origin);
        check[origin] = true;

        while (false == q.empty())
        {
            int now = q.front();
            q.pop();

            if (now == goal)
                break;

            int d = D(now), s = S(now), l = L(now), r = R(now);
            checkAndPush(now, check, cmd, parent, q, d, 'D');
            checkAndPush(now, check, cmd, parent, q, s, 'S');
            checkAndPush(now, check, cmd, parent, q, l, 'L');
            checkAndPush(now, check, cmd, parent, q, r, 'R');
        }

        vector<int> answer;
        int p = goal;    
        while (p != origin)
        {
            int ch = cmd[p];
            answer.push_back(ch);
            p = parent[p];
        }

        for (auto it = answer.rbegin(); it != answer.rend(); ++it)
        {
            printf("%c", *it);
        }
        printf("\n");
    }

    return 0;
}
/*
1
9999 0
답: DDLSLDDRDDDD
*/