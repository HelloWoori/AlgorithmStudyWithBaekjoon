/*
2xn 타일링 2
https://www.acmicpc.net/problem/11727
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int input(0);
    cin >> input;

    vector<int> dp(input + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    if (input >= 2)
    {
        for (int i = 2; i <= input; ++i)
        {
            int temp = dp[i - 1] + 2 * dp[i - 2];
            dp[i] = temp % 10007;
        }
    }

    cout << dp[input] << '\n';

    return 0;
}