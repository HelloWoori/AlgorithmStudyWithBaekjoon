/*
타일 장식물
- https://programmers.co.kr/learn/courses/30/lessons/43104
*/
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    
    vector<long long> dp(N + 1, 1);

    if(N == 1)
    {
        answer = 1;
    }
    else if(N >= 2)
    {
        if(N >= 3)
        {
            for(int i = 3; i <= N; ++i)
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        }
        
        long long width = dp[N];
        long long height = dp[N] + dp[N - 1];
        answer = (width + height) * 2;
    }

    return answer;
}