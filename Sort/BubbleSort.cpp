/*
버블 소트
https://www.acmicpc.net/problem/1377
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Num
{
    int num;
    int prePos;

    Num() : num(0), prePos(0) {}
    Num(int _num, int _prePos) : num(_num), prePos(_prePos) {}

    bool operator < (const Num& other) const
    {
        return num < other.num;
    }
};

int main()
{
    int theNumOfNumbers(0);
    scanf("%d", &theNumOfNumbers);

    vector<Num> numbers;
    numbers.reserve(theNumOfNumbers);

    for (int i = 0; i < theNumOfNumbers; ++i)
    {
        int input(0);
        scanf("%d", &input);
        numbers.push_back(Num(input, i));
    }

    stable_sort(numbers.begin(), numbers.end());

    //정렬 후의 더 앞으로 정렬된 숫자의 인덱스 차이를 구함
    int max(0);
    for (int i = 0; i < theNumOfNumbers; ++i)
    {
        //printf("%d의 원래 위치: %d, 뒤바뀐 위치: %d\n", numbers[i].num, numbers[i].prePos, i);
        int temp = numbers[i].prePos - i;
        if (temp > max)
        {
            max = temp;
        }
    }

    printf("%d\n", max + 1);

    return 0;
}