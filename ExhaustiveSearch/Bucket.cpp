/*
물통
https://www.acmicpc.net/problem/2251
*/
#include <cstdio>
#include <queue>
#include <vector>
#include <set>

using namespace std;

struct Bucket
{
    int a;
    int b;

    Bucket() : a(0), b(0) {}
    Bucket(int _a, int _b) : a(_a), b(_b) {}
};

void checkAndPush(vector<vector<int>>& check, 
                  queue<Bucket>& q, 
                  set<int>& answer,
                  const int C, 
                  const int a, const int b)
{
    if (0 == check[a][b])
    {
        check[a][b] = 1;
        q.push(Bucket(a, b));

        if (a == 0) answer.insert(C - (a + b));
    }
}

int main()
{
    const int MAX = 201;
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    queue<Bucket> q;
    vector<vector<int>> check(MAX, vector<int>(MAX, 0));
    set<int> answer;

    q.push(Bucket(0, 0));
    check[0][0] = true;
    answer.insert(C);

    while (false == q.empty())
    {
        Bucket now = q.front();
        check[now.a][now.b] = 1; //1은 true
        q.pop();

        int to = 0;
        int from = 0;
        int nowC = C - (now.a + now.b);

        //A -> B
        from = now.a;
        to = now.b;

        to += from;
        from = 0;

        if (to > B)        //넘침!!
        {
            from = to - B; //넘치는 만큼 다시 가져감
            to = B;        //가득참
        }
        checkAndPush(check, q, answer, C, from, to);

        //A -> C
        from = now.a;
        to = nowC;

        to += from;
        from = 0;
        if (to > C)
        {
            from = to - C;
            to = C;
        }
        checkAndPush(check, q, answer, C, from, now.b);

        //B -> A
        from = now.b;
        to = now.a;

        to += from;
        from = 0;
        if (to > A)
        {
            from = to - A;
            to = A;
        }
        checkAndPush(check, q, answer, C, to, from);
        //B -> C
        from = now.b;
        to = nowC;

        to += from;
        from = 0;
        if (to > C)
        {
            from = to - C;
            to = C;
        }
        checkAndPush(check, q, answer, C, now.a, from);

        //C -> A
        from = nowC;
        to = now.a;

        to += from;
        from = 0;
        if (to > A)
        {
            from = to - A;
            to = A;
        }
        checkAndPush(check, q, answer, C, to, now.b);

        //C -> B
        from = nowC;
        to = now.b;

        to += from;
        from = 0;
        if (to > B)
        {
            from = to - B;
            to = B;
        }
        checkAndPush(check, q, answer, C, now.a, to);
    }

    //결과출력
    for (const auto& element : answer)
    {
        printf("%d ", element);
    }
    printf("\n");
    
    return 0;
}