/*
2xn 타일링 1
https://www.acmicpc.net/problem/11726
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

    dp[0] = 1; //보이지않는 하나 있다고 생각하기
    dp[1] = 1;
    
    if (input >= 2)
    {
        for (int i = 2; i <= input; ++i)
        {
            int temp = dp[i - 1] + dp[i - 2];
            dp[i] = temp % 10007;
        }
    }

    cout << dp[input] << '\n';

    return 0;
}