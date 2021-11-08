/*
2xn 타일링 2
https://www.acmicpc.net/problem/11727
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int input(0);
    cin >> input;
  
    vector<int> memo(input + 1, 0);
    memo[1] = 1;
    memo[2] = 3;

    for (int i = 3; i <= input; i++)
    {
        memo[i] = (memo[i - 2] * 2 + memo[i - 1]) % 10007;
    }

    cout << memo[input] << '\n';

    return 0;
}