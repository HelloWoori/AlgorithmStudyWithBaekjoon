/*
골드바흐의 추측
https://www.acmicpc.net/problem/6588
- https://www.acmicpc.net/board/view/20221 (시간초과 관련해서 도움을 받은 글)
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>

const int MAX = 1000000;
int prime[MAX]; //소수 저장
int pn = 0;     //소수의 개수
bool check[MAX + 1]; //지워졌으면 true

int main()
{
    //에라토스테네스의 체
    for (int i = 2; i * i <= MAX; ++i)
    {
        if (false == check[i]) //지워지지 않았다. 즉, 소수이다.
            prime[pn++] = i;

        for (int j = i * 2; j <= MAX; j += i)
        {
            check[j] = true;  //i를 제외한 i의 배수인걸 지워나간다.
        }
    }

    int n(0);
    while (scanf("%d", &n))
    {
        if (n == 0)
            break;
    
        for (size_t i = 1; i <= pn; ++i) //prime[0] = 2이므로, 2를 제외하기 위해 1부터 시작
        {
            const int temp = n - prime[i];
            if (false == check[temp])
            {
                printf("%d = %d + %d\n", n, prime[i], temp);
                break;
            }   
        }
    }

    return 0;
}