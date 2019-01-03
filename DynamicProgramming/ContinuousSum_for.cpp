/*
연속합
https://www.acmicpc.net/problem/1912
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int sizeOfSequence(0);
    cin >> sizeOfSequence;

    vector<int> sequence(sizeOfSequence + 1, 0);
    vector<int> dp(sizeOfSequence + 1, 0);

    //수열 입력
    for (int i = 1; i <= sizeOfSequence; ++i)
    {
        cin >> sequence[i];
    }

    int max = sequence[1]; //가장 처음 값을 선택했다고 가정하고, max값으로 지정

    dp[1] = sequence[1];
    for (int i = 2; i <= sizeOfSequence; ++i)
    {
        dp[i] = sequence[i];
        int temp = dp[i - 1] + sequence[i];

        if (dp[i] < temp)
            dp[i] = temp;

        if (max < dp[i])
            max = dp[i];
    }

    //for debug
    //for (int i = 1; i <= sizeOfSequence; ++i)
    //{
    //    cout << "dp[" << i << "]= " << dp[i] << '\n';
    //}

    cout << max << '\n';

    return 0;
}
/*
반례
5
2 3 -1 -3 2
답: 5

3
1000 -1 1000
답: 1999
*/