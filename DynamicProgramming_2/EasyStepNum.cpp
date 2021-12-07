/*
쉬운 계단 수
https://www.acmicpc.net/problem/10844
*/
#include <iostream>
#include <vector>

#define mod 1000000000

using namespace std;

int main()
{
    int len(0);
    cin >> len;
    
    vector<vector<int>> memo(len + 1, vector<int>(9));
    
    for (int i = 1; i <= 9; i++) // 0으로 시작하는 수는 계단수가 아니다
    {
        memo[1][i] = 1;
    }
    
    for (int i = 2; i <= len; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j - 1 >= 0) memo[i][j] += memo[i -1][j - 1];
            if (j + 1 <= 9) memo[i][j] += memo[i - 1][j + 1];
            memo[i][j] %= mod;
        }
    }
    
    long long ans(0);
    for (int i = 0; i <= 9; i++)
    {
        ans += memo[len][i];
    }
    
    cout << ans % mod << '\n';

    return 0;
}