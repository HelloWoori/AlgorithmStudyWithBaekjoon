/*
카드 구매하기
https://www.acmicpc.net/problem/11052
*/
#include <iostream>
#include <vector>

using namespace std;

int calc(vector<int>& card, vector<int>& memo, int n);
int main()
{
    int goal(0);
    cin >> goal;

    vector<int> card(goal + 1);
    vector<int> memo(goal + 1, 0);
  
    for (int i = 1; i <= goal; i++)
    {
        cin >> card[i];    
    }

    memo[1] = card[1];
    for (int i = goal - 1; i >= 1; i--)
    {
        int temp = card[i] + memo[goal - i];
    }

    cout << calc(card, memo, goal) << "\n";
  
    return 0;
}

int calc(vector<int>& card, vector<int>& memo, int n)
{
    if (memo[n]> 0)
    {
        return memo[n];
    }

    int price = 0;
    for (int i = 1; i <= n; i++)
    {
        price = card[i] + calc(card, memo, n - i);

        if (memo[n] < price)
        {
            memo[n] = price;
        }
    }

    return memo[n];
}