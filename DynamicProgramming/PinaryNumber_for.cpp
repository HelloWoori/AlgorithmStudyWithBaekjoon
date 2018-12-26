/*
이친수
https://www.acmicpc.net/problem/2193
*/
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int input(0);
    cin >> input;

    /*
        dp[n][0] => n자리 이면서, 0으로 끝나는 이친수의 개수
        dp[n][1] => n자리 이면서, 1으로 끝나는 이친수의 개수
    */
    vector<vector<ull>> dp(input + 1, vector<ull>(2, 0));

    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int n = 2; n <= input; ++n)
    {
        dp[n][0] = dp[n - 1][0] + dp[n - 1][1];
        dp[n][1] = dp[n - 1][0];
    }

    ull result = dp[input][0] + dp[input][1];
    cout << result << '\n';
    
    return 0;
}