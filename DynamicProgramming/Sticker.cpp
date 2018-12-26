/*
스티커
https://www.acmicpc.net/problem/9465
*/
#include <iostream>
#include <vector>

using namespace std;

enum State
{
    UP,
    DOWN,
    NOTHING
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
    
    int theNumOfTestCases(0);
    cin >> theNumOfTestCases;

    while (theNumOfTestCases-- > 0)
    {
        int column(0);
        cin >> column;
        vector<vector<int>> scores(column + 1, vector<int>(2, 0));
        vector<vector<int>> dp(column + 1, vector<int>(3, 0));

        //스티커 점수 입력
        for (int col = 1; col <= column; ++col)
        {
            int input(0);
            cin >> input;
            scores[col][0] = input;
        }

        for (int col = 1; col <= column; ++col)
        {
            int input(0);
            cin >> input;
            scores[col][1] = input;
        }
   
        //스티커 점수의 최댓값 구하기
        dp[1][UP] = scores[1][UP];
        dp[1][DOWN] = scores[1][DOWN];
        dp[1][NOTHING] = 0;

        for (int i = 2; i <= column; ++i)
        {
            dp[i][UP] = max(dp[i - 1][DOWN], dp[i - 1][NOTHING]) + scores[i][UP];
            dp[i][DOWN] = max(dp[i - 1][UP], dp[i - 1][NOTHING]) + scores[i][DOWN];
            dp[i][NOTHING] = max(max(dp[i - 1][UP], dp[i - 1][DOWN]), dp[i - 1][NOTHING]);
        }

        int result(0);
        result = max(max(dp[column][UP], dp[column][DOWN]), dp[column][NOTHING]);

        cout << result << '\n';
    }

    return 0;
}