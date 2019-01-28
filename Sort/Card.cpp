/*
카드
https://www.acmicpc.net/problem/11652
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <map>

using namespace std;

int main()
{
    map<long long, int> cards; //숫자, 그 숫자의 개수

    int theNumOfCards(0);
    scanf("%d", &theNumOfCards);

    long long num(0);
    while (theNumOfCards-- > 0)
    {
        scanf("%lld", &num);
        cards[num] += 1;
    }

    //가장 많이 가지고 있는 숫자카드의 숫자
    long long result(0);
    int count(0);
    for (const auto card : cards)
    {
        if (card.second > count) //더 많이 있는 카드가 있다면 그걸로 값 변경
        {
            count = card.second;
            result = card.first;
        }
        else if(card.second == count && card.first < result) //개수가 같은데, 더 작은 숫자라면 숫자 변경
        {
            result = card.first;
        }
    }

    printf("%lld\n", result);

    return 0;
}