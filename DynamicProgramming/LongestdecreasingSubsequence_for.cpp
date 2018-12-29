/*
가장 긴 감소하는 부분 수열
https://www.acmicpc.net/problem/11722
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int sizeOfSequence(0);
    cin >> sizeOfSequence;

    //가장 긴 감소하는 부분 수열의 최소값은 1이므로 dp와 max를 1로 초기화 
    vector<int> dp(sizeOfSequence + 1, 1);
    vector<int> sequence(sizeOfSequence + 1, 0);
    int max(1);

    //수열 입력
    for (int i = 1; i <= sizeOfSequence; ++i)
    {
        cin >> sequence[i];
    }
    
    for (int now = 2; now <= sizeOfSequence; ++now)
    {
        for (int prev = 1; prev < now; ++prev)
        {
            if (sequence[now] < sequence[prev])
            {
                int temp = dp[prev] + 1;
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
7 5 3 1 10
정답: 4
*/