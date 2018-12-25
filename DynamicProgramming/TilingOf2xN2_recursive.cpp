/*
2xn 타일링 2
https://www.acmicpc.net/problem/11727
*/
#include <iostream>
#include <vector>

using namespace std;

int calc(const int n, vector<int>& dp)
{
    if (dp[n] > 0)
        return dp[n];

    if (n < 2)
    {
        dp[n] = 1;
    }
    else
    {
        int temp = calc(n - 1, dp) + 2 * calc(n - 2, dp);
        dp[n] = temp % 10007;
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int input(0);
    cin >> input;

    vector<int> dp(input + 1, 0);

    cout << calc(input, dp) << '\n';

    return 0;
}