/*
쉬운 계단 수
https://www.acmicpc.net/problem/10844
*/
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);

    const int mod = 1000000000;
    
    int input(0);
    cin >> input;

    vector<vector<int>> dp(input + 1, vector<int>(10, 0));

    for (int i = 1; i <= 9; ++i)
    {
        dp[1][i] = 1;
    }

    for (int n = 2; n <= input; ++n)
    {
        for (int last = 1; last <= 8; ++last)
        {
            ull temp = dp[n - 1][last + 1] + dp[n - 1][last - 1];
            dp[n][last] = temp % mod;
        }

        dp[n][0] = dp[n - 1][1] % mod;
        dp[n][9] = dp[n - 1][8] % mod;
    }

    ull result(0);
    for (const auto val : dp[input])
    {
        result += val;
    }
    result %= mod;

    cout << result << '\n';

    return 0;
}