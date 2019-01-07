/*
파도반 수열
https://www.acmicpc.net/problem/9461
*/
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);

    int numOfTestCases(0);
    cin >> numOfTestCases;

    while (numOfTestCases-- > 0)
    {
        int input(0);
        cin >> input;

        vector<ull> dp(input + 1, 1);

        if (input >= 4)
            dp[4] = 2;
        if (input >= 5)
            dp[5] = 2;
        
        if (input >= 6)
        {
            for (int i = 6; i <= input; ++i)
            {
                dp[i] = dp[i - 5] + dp[i - 1];
            }
        }

        cout << dp[input] << '\n';
    }

    return 0;
}