/*
팩토리얼
https://www.acmicpc.net/problem/10872
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>

int factorial(int n, int& result)
{
    if (n == 0)
        return result;

    result *= n;
    factorial(n - 1, result);
}

int main()
{
    int input = 0;
    scanf("%d", &input);

    int result = 1;
    printf("%d\n", factorial(input, result));
    
    return 0;
}