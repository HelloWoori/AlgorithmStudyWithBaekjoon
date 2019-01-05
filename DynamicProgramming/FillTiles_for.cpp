/*
타일 채우기
https://www.acmicpc.net/problem/2133
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
    dp[0] = 1; 

    if (input >= 2)
    {
        for (int i = 2; i <= input; i += 2)
        {
            dp[i] = dp[i - 2] * 3;
        
            if (i >= 4)
            {
                int multipleOfTwo = 4;
                while (true)
                {
                    const int temp = i - multipleOfTwo;

                    dp[i] += 2 * dp[temp];
                    if (temp == 0)
                        break;

                    multipleOfTwo += 2;
                }
            }
        }
    }

    cout << dp[input] << '\n';

    return 0;
}