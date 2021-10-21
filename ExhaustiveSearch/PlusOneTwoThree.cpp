/*
1, 2, 3 더하기
https://www.acmicpc.net/problem/9095
*/
#include <iostream>

using namespace std;

int calc(int sum, int goal);
int main()
{
    int testCaseNum = 0;
    cin >> testCaseNum;

    while (testCaseNum-- > 0)
    {
        int goal = 0;
        cin >> goal;
        cout << calc(0, goal) << '\n';
    }
  
    return 0;
}


int calc(int sum, int goal)
{
    if (sum == goal)
    {
        return 1;
    }

    if (sum > goal)
    {
        return 0;
    }

    int ret = 0;
    for (int i = 1; i <= 3; i++)
    {
        ret += calc(sum + i, goal);
    }

    return ret;
}