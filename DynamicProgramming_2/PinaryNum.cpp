/*
이친수
https://www.acmicpc.net/problem/2193
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int input(0);
    cin >> input;
    
    vector<long long> memo(input + 1, 0);
    
    memo[1] = 1;
    memo[2] = 1;
    
    for (int i = 3; i <= input; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    
    cout << memo[input] << '\n';

    return 0;
}
