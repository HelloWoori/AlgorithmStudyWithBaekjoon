/*
K번째 수
https://www.acmicpc.net/problem/11004
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int theNumOfNumbers(0), th(0);
    scanf("%d %d", &theNumOfNumbers, &th);
    
    th--; //index와 번째를 맞춰주기 위함
    
    vector<int> numbers;
    while (theNumOfNumbers-- > 0)
    {
        int num(0);
        scanf("%d", &num);
        numbers.push_back(num);
    }

    nth_element(numbers.begin(), numbers.begin() + th, numbers.end());

    printf("%d\n", numbers[th]);

    return 0;
}