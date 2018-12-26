/*
카드 구매하기
https://www.acmicpc.net/problem/11052
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int input(0);
    cin >> input;
    
    vector<int> card(input + 1, 0);
    vector<int> dp(input + 1, 0);

    for (int i = 1; i <= input; ++i)
    {
        int price(0);
        cin >> price;
        card[i] = price;
    }

    dp[1] = card[1];
    for (int n= 2; n <= input; ++n)
    {
        for (int i = 1; i <= n; ++i)
        {
            int temp = card[i] + dp[n - i];
            if (dp[n] < temp)
                dp[n] = temp;
        }
    }

    cout << dp[input] << '\n';

    return 0;
}