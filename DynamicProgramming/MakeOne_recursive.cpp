/*
1로 만들기
https://www.acmicpc.net/problem/1463
*/
#include <iostream>
#include <vector>

using namespace std;

int calc(const int n, vector<int>& dp)
{
    if (n <= 1)
        return dp[n];

    if (dp[n] > 0)
        return dp[n];

    dp[n] = calc(n - 1, dp) + 1;
    if (n % 3 == 0)
    {
        int temp = calc(n / 3, dp) + 1;
        if (temp < dp[n])
            dp[n] = temp;
    }

    if (n % 2 == 0)
    {
        int temp = calc(n / 2, dp) + 1;
        if (temp < dp[n])
            dp[n] = temp;
    }

    return dp[n];
}


int main()
{
    ios_base::sync_with_stdio(false);
    //dp[n] = 1을 만들기 위해 연산을 사용하는 횟수의 최솟값
    int n(0);
    cin >> n;

    vector<int> dp(n + 1, 0);

    cout << calc(n, dp) << '\n';

    return 0;
}