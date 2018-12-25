/*
1, 2, 3 더하기
https://www.acmicpc.net/problem/9095
*/
#include <iostream>
#include <vector>

using namespace std;

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
                break;
            }
        }
        else
        {
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;

            for (int i = 4; i <= input; ++i)
            {
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            }
        }

        cout << dp[input] << '\n';
    }
    return 0;
}