/*
포도주 시식
https://www.acmicpc.net/problem/2156
- https://www.acmicpc.net/board/view/21703#comment-37134 (반례)
*/
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int theNumOfGlasses(0);
    cin >> theNumOfGlasses;
    
    vector<int> dp(theNumOfGlasses + 1, 0);
    vector<int> wine(theNumOfGlasses + 1, 0);

    //포도잔의 개수만큼 포도주의 양을 입력받는다
    for(int i = 1; i <= theNumOfGlasses; ++i)
    {
        cin >> wine[i];
    }

    dp[1] = wine[1];
    
    if (theNumOfGlasses > 1)
    {
        dp[2] = wine[1] + wine[2];

        if (theNumOfGlasses > 2)
        {
            for (int i = 3; i <= theNumOfGlasses; ++i)
            {
                const int continuousZero = dp[i - 1];
                const int continuousOne = dp[i - 2] + wine[i];
                const int continuousTwo = dp[i - 3] + wine[i - 1] + wine[i];
                
                dp[i] = max(max(continuousZero, continuousOne), continuousTwo);
            }
        }
    }

    cout << dp[theNumOfGlasses] << '\n';
 
    return 0;
}