/*
A + B - 8
https://www.acmicpc.net/problem/11022
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
    int theNumOfTestCases(0);
    scanf("%d", &theNumOfTestCases);

    int input1(0), input2(0);
    for (int i = 1; i <= theNumOfTestCases; ++i)
    {
        scanf("%d %d", &input1, &input2);
        printf("Case #%d: %d + %d = %d\n", i, input1, input2, input1 + input2);
    
    }

    return 0;
}