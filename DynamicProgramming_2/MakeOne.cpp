/*
1로 만들기
https://www.acmicpc.net/problem/1463
*/
#include <iostream>
#include <vector>

using namespace std;

int calc(vector<int>& memo, int num);
int main()
{
    int input(0);
    cin >> input;

    vector<int> memo(input + 1, 0);
    memo[2] = 1;
    memo[3] = 1;

    cout << calc(memo, input) << '\n';

    return 0;
}

int calc(vector<int>& memo, int num)
{
    if (num == 1)
    {
       return 0;
    }

    if (memo[num] > 0)
    {
        return memo[num];
    }

    memo[num] = calc(memo, num - 1) + 1;
    if (num % 2 == 0)
    {
        int temp = calc(memo, num / 2) + 1;
        if (temp < memo[num])
        {
            memo[num] = temp;
        }
    }
    if (num % 3 == 0)
    {
        int temp = calc(memo, num / 3) + 1;
        if (temp < memo[num])
        {
            memo[num] = temp;      
        }
    }

    return memo[num];
}