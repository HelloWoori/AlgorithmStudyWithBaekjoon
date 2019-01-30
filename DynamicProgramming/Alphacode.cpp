/*
암호코드
https://www.acmicpc.net/problem/2011
- http://acm-ecna.ysu.edu/PastResults/2004/problems.html (테스트케이스를 확인해 볼 수 있는 곳)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ull;
const int MOD = 1000000;

bool isIn1to9(char ch)
{
    int num = ch - '0';
    return (num >= 1 && num <= 9);
}

bool isIn10to26(char ten, char one)
{
    int num = (ten - '0') * 10 + (one - '0');
    return (num >= 10 && num <= 26);
}

int solveProblem(string& str)
{
    int strLen = (int)(str.size());

    if (strLen == 0)
        return 0;

    vector<ull> dp(strLen, 0);

    if (strLen >= 1 && isIn1to9(str[0]))
    {
        dp[0] = 1;
    }

    if (strLen >= 2)
    {
        if (isIn1to9(str[1]))
        {
            dp[1] += dp[0];
        }
        if (isIn10to26(str[0], str[1]))
        {
            dp[1] += 1;
        }
    }

    if (strLen >= 3)
    {
        for (int i = 2; i < strLen; ++i)
        {
            //현재 숫자가 1이상 9이하 일 때
            if (isIn1to9(str[i]))
            {
                dp[i] += dp[i - 1];
                dp[i] %= MOD;
            }
            //이전 숫자와 현재 숫자의 조합이 10이상 26이하 일때
            if (str[i - 1] != '0') 
            {
                if (isIn10to26(str[i - 1], str[i]))
                {
                    dp[i] += dp[i - 2];
                    dp[i] %= MOD;
                }
            }
        }
    }

    //for debug
    //for (size_t i = 0; i < dp.size(); ++i)
    //{
    //    cout << "dp[" << i << "] = " << dp[i] << '\n';
    //}

    return dp[strLen - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);

    string str("");
    cin >> str;

    cout << solveProblem(str) << '\n';

    return 0;
}
/*
테스트케이스

25114
답: 6
1111111111
답: 89
3333333333
답: 1
101010101010101010101010101010101010101010101010101010101010
답: 1
1010101010101010101010101010101010101010101010101010101010101
답: 1
1111111111111111111111111
답: 121393
2085172193112181523146152410211316191522518112126254157
답: 169280
2085
답: 1
1
답: 1 
3
답: 1
11
답: 2
33
답: 1
*/