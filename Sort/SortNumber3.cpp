/*
수 정렬하기 3
https://www.acmicpc.net/problem/10989
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <unordered_map>
#include <map>

using namespace std;

int main()
{
    int theNumOfNumbers = 0;
    scanf("%d", &theNumOfNumbers);

    unordered_map<int, int> m; //숫자, 그 숫자의 개수

    int num = 0;
    while (theNumOfNumbers-- > 0)
    {
        scanf("%d", &num);
   
        auto it = m.find(num);
    
        if (it != m.end())
        {
            int& count = it->second;
            count++;
        }
        else
        {
            m.insert(make_pair(num, 1));
        }
    }
    
    map<int, int> m2(m.begin(), m.end());

    for (const auto& num : m2)
    {
        for (int i = 0; i < num.second; ++i)
        {
            printf("%d\n", num.first);
        }
    }

    return 0;
}