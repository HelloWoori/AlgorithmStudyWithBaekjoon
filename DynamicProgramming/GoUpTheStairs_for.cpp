/*
계단 오르기
https://www.acmicpc.net/problem/2579
*/
#include <iostream>
#include <vector>

using namespace std;

enum State
{
    CONTINUE_ONE, //연속 계단 1번
    CONTINUE_TWO, //연속 계단 2번
    STATE_SIZE
};

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int sizeOfStairs(0);
    cin >> sizeOfStairs;

    vector<int> stairs(sizeOfStairs + 1, 0);
    vector<vector<int>> dp(sizeOfStairs + 1, vector<int> (STATE_SIZE, 0)); //연속으로 1계단, 연속으로 2계산

    for (int i = 1; i <= sizeOfStairs; ++i)
    {
        cin >> stairs[i];
    }

    dp[1][CONTINUE_ONE] = stairs[1];

    if (sizeOfStairs > 2)
    {
        for (int i = 2; i <= sizeOfStairs; ++i)
        {
            const int temp1 = dp[i - 2][CONTINUE_TWO] + stairs[i];
            const int temp2 = dp[i - 2][CONTINUE_ONE] + stairs[i];
            dp[i][CONTINUE_ONE] = max(temp1, temp2);

            dp[i][CONTINUE_TWO] = dp[i - 1][CONTINUE_ONE] + stairs[i];
        }
    }

    //for debug
    //for (int i = 1; i <= sizeOfStairs; ++i)
    //{
    //    cout << i << " - " << "연속 1계단: " << dp[i][CONTINUE_ONE] << ", 연속 2계단: " << dp[i][CONTINUE_TWO] << '\n';
    //}

    cout << max(dp[sizeOfStairs][CONTINUE_ONE], dp[sizeOfStairs][CONTINUE_TWO]) << '\n';

    return 0;
}
/*
반례
6
1
1
2
2
1
1
정답: 6
*/