/*
가장 긴 증가하는 부분 수열
https://www.acmicpc.net/problem/11053
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int sizeOfSequence(0);
    cin >> sizeOfSequence;

    //dp[n] = n번째 수열이 마지막 수일 때의 수열 sequence의 가장 긴 증가하는 부분 수열의 길이 
    //항상 자기 자신을 포함하므로 1로 초기화함
    //max도 마찬가지로 길이가 1인 수열의 가장 긴 증가하는 부분 수열의 길이는 1이므로 1로 초기화
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
            if (sequence[prev] < sequence[now])
            {
                const int temp = dp[prev] + 1;
                if (dp[now] < temp)
                {
                    dp[now] = temp;
                }
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
    //cout << "max: " << max << '\n';
    cout << max << '\n';

    return 0;
}
/*
반례
4
1 4 2 3
답: 3

8
1 5 10 3 13 18 15 16
답: 6

3
2 1 2
답: 2
*/