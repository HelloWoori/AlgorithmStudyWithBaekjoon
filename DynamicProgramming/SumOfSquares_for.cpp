/*
제곱수의 합
https://www.acmicpc.net/problem/1699
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int input(0);
    cin >> input;

    vector<int> dp(input + 1, numeric_limits<int>::max());

    dp[0] = 0;
    dp[1] = 1;
    if (input > 2)
    {
        for (int n = 2; n <= input; ++n)
        {
            for (int i = 1; i <= sqrt(n); ++i)
            {
                int temp = dp[n - pow(i, 2)] + 1;
                if (temp < dp[n])
                {
                    dp[n] = temp;
                }
            }
        }
    }
    cout << dp[input] << '\n';

    return 0;
}