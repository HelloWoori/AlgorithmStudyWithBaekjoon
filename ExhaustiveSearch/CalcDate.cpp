/*
날짜 계산
https://www.acmicpc.net/problem/1476
*/
#include <cstdio>

using namespace std;

int main()
{ 
    const int E = 15;
    const int S = 28;
    const int M = 19;

    int earth(0), sun(0), moon(0);
    scanf("%d %d %d", &earth, &sun, &moon);
    
    int e(0), s(0), m(0);
    int loop(0);
    int result(0);

    while (true)
    {
        if (e == earth && s == sun && m == moon)
            break;

        result = E * loop + earth;

        e = result % E;
        s = result % S;
        m = result % M;

        if (e == 0) e = E;
        if (s == 0) s = S;
        if (m == 0) m = M;

        loop++;
    }

    printf("%d\n", result);

    return 0;
}