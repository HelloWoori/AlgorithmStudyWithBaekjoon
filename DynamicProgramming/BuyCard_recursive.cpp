/*
카드 구매하기
https://www.acmicpc.net/problem/11052
*/
#include <iostream>
#include <vector>

using namespace std;

int calc(const int n, const vector<int>& card, vector<int>& dp)
{
    if (dp[n] > 0)
        return dp[n];

    for (int i = 1; i <= n; ++i)
    {
        int temp = card[i] + calc(n - i, card, dp);
        if (temp > dp[n])
            dp[n] = temp;
    }
    
    return dp[n];
}

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
    cout << calc(input, card, dp) << '\n';

    return 0;
}