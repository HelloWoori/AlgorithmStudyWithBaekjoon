/*
합분해
https://www.acmicpc.net/problem/2225
*/
#include <iostream>
#include <vector>
#define mod 1000000000

using namespace std;

typedef unsigned long long ull;

int sum(int n, int k, vector<vector<int>>& dp);
int main()
{
    ios_base::sync_with_stdio(false);
    
    int N(0), K(0);
    cin >> N >> K;

    //dp[N][K] = 정수 K개를 더해 N을 만드는 경우의 수
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    //정수 1개를 더해 N을 만드는 경우의 수는 자기자신이므로 1
    for (int i = 0; i <= N; ++i)
    {
        dp[i][1] = 1;
    }

    if (K >= 2)
    {
        //정수 2개를 더해 N을 만드는 경우의 수
        for (int i = 0; i <= N; ++i)
        {
            dp[i][2] = i + 1;
        }
    }

    if (K >= 3)
    {
        for (int k = 3; k <= K; ++k)
        {
            for (int n = 0; n <= N; ++n)
            {
                dp[n][k] = sum(n, k, dp);
            }
        }
    }
    cout << dp[N][K] << '\n';

    return 0;
}

int sum(int n, int k, vector<vector<int>>& dp)
{
    ull sum = 0;
    for (int i = 0; i <= n; ++i)
    {
        sum += dp[i][k - 1];
    }
    sum %= mod;
    return sum;
}
/*
반례
50 10
답: 565671261

3 3
답: 10

4 4
답: 35

200 200
답: 753387060
*/