/*
오르막 수
https://www.acmicpc.net/problem/11057
*/
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    
    const int mod = 10007;
    int input(0);
    cin >> input;

    vector<vector<int>> dp(input + 1, vector<int>(10, 0));

    for (int i = 0; i <= 9; ++i)
    {
        dp[1][i] = 1;
    }

    for (int n = 2; n <= input; ++n)
    {
        for (int last = 0; last <= 9; ++last)
        {
            ull temp(0);
            for (int i = last; i <= 9; ++i)
            {
                temp += dp[n - 1][i];
      
                dp[n][last] = temp % mod;
            }
        }
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