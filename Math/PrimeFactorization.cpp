/*
소인수분해
https://www.acmicpc.net/problem/11653
- https://www.acmicpc.net/board/view/31728 (1과 관련해서 도움을 받은글)
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>

const int MAX = 10000000;
int prime[MAX];
int pn = 0;
bool check[MAX + 1];

void primeFactorization(int n);

int main()
{
    int input = 0;
    scanf("%d", &input);

    //에라토스테네스의 체
    for (int i = 2; i <= input; ++i)
    {
        if (false == check[i])
            prime[pn++] = i;

        for (int j = i * 2; j <= input; j += i)
        {
            check[j] = true; //true이면 지워졌다
        }
    }

    primeFactorization(input);
  
    return 0;
}

void primeFactorization(int n)
{
    int i = 0;
    while (n != 1)
    {
        if (n % prime[i] == 0)
        {
            printf("%d\n", prime[i]);
            n /= prime[i];
            i = 0;
        }
        else 
        {
            i++;
        }
    }
}