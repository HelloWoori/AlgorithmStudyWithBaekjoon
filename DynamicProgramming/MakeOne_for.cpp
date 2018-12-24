/*
1로 만들기
https://www.acmicpc.net/problem/1463
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    //dp[n] = 1을 만들기 위해 연산을 사용하는 횟수의 최솟값
    int input(0);
    cin >> input;

    vector<int> dp(input + 1, 0);

    for (int i = 2; i <= input; ++i)
    {
        dp[i] = dp[i - 1] + 1;

        if (i % 3 == 0)
        {
            int temp = dp[i / 3] + 1;
            if (temp < dp[i])
                dp[i] = temp;
        }
        
        if (i % 2 == 0)
        {
            int temp = dp[i / 2] + 1;
            if (temp < dp[i])
                dp[i] = temp;
        }
    }

    cout << dp[input] << '\n';

    return 0;
}