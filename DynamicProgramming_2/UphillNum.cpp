/*
오르막 수
https://www.acmicpc.net/problem/11057
*/
#include <iostream>
#include <vector>

#define MOD 10007

using namespace std;

int main()
{
    int input(0);
    cin >> input;
    
    vector<vector<int>> memo(input + 1, vector<int>(10));
    
    // 길이가 1 이고, 마지막 숫자가 last 인 오르막 수의 개수는 1
    for (int last = 0; last <= 9; last++)
    {
        memo[1][last] = 1;
    }
    
    // memo[len][last] += memo[len - 1][k] (단, 0 <= k <= j)
    for (int len = 2; len <= input; len++)
    {
        for (int last = 0; last <= 9; last++)
        {
            for (int k = 0; k <= last; k++)
            {
                memo[len][last] += memo[len-1][k];
                memo[len][last] %= MOD;
            }
        }
    }
    
    long long result(0);
    for (int i = 0; i <= 9; i++)
    {
        result += memo[input][i];
    }
    
    cout << result  % MOD << '\n';

    return 0;
}