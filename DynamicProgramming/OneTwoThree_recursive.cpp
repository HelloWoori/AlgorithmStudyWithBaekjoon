/*
1, 2, 3 더하기
https://www.acmicpc.net/problem/9095
*/
#include <iostream>
#include <vector>

using namespace std;

int calc(const int n, vector<int>& dp)
{
    if (dp[n] > 0)
        return dp[n];

    dp[n] = calc(n - 1, dp) + calc(n - 2, dp) + calc(n - 3, dp);

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int theNumOfTestCases(0);
    cin >> theNumOfTestCases;

    while (theNumOfTestCases-- > 0)
    {
        int input(0);
        cin >> input;

        vector<int> dp(input + 1, 0);
        
        if (input < 4)
        {
            switch (input)
            {
            case 3:
                dp[3] = 4;
            case 2:
                dp[2] = 2;
            case 1:
                dp[1] = 1;
            }
        }
        else
        {
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;

            calc(input, dp);
        }

        cout << dp[input] << '\n';
    }
    return 0;
}