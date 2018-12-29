/*
가장 큰 증가 부분 수열
https://www.acmicpc.net/problem/11055
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int sizeOfSequence(0);
    cin >> sizeOfSequence;
    
    vector<int> dp(sizeOfSequence + 1, 0);
    vector<int> sequence(sizeOfSequence + 1, 0);
    int max(0);

    //수열 입력
    for (int i = 1; i <= sizeOfSequence; ++i)
    {
        cin >> sequence[i];
        dp[i] = sequence[i];
    }

    for (int now = 1; now <= sizeOfSequence; ++now)
    {
        for (int prev = 0; prev < now; ++prev)
        {
            if (sequence[prev] < sequence[now])
            {
                int temp = dp[prev] + sequence[now];
                if (dp[now] < temp)
                    dp[now] = temp;
            }
        }
        if (max < dp[now])
            max = dp[now];
    }

    //for debug
    //for (int i = 1; i <= sizeOfSequence; ++i)
    //{
    //    cout << dp[i] << ' ';
    //}
    //cout << '\n';

    cout << max << '\n';

    return 0;
}
/*
반례
5
1 100 3 4 101
답: 202

8
3 10 2 7 11 5 13 8
답: 37
*/