/*
A+B - 5
https://www.acmicpc.net/problem/10952
*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main()
{
    int input1 = 0, input2 = 0;

    while (scanf("%d %d", &input1, &input2))
    {
        if (input1 == 0 && input2 == 0)
            break;

        printf("%d\n", input1 + input2);
    }

    return 0;
}