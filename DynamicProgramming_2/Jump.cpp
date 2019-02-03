/*
점프
- https://www.acmicpc.net/problem/1890
- https://www.cs.helsinki.fi/group/boi2006/ (테스트케이스, Day 2의 Jump)
*/
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    int size(0);
    cin >> size;

    vector<vector<int>> map(size, vector<int>(size, 0));
    vector<vector<ull>> dp(size, vector<ull>(size, 0));

    for (int h = 0; h < size; ++h)
    {
        for (int w = 0; w < size; ++w)
        {
            cin >> map[h][w];
        }
    }

    dp[0][0] = 1;
    for (int h = 0; h < size; ++h)
    {
        for (int w = 0; w < size; ++w)
        {
            if (map[h][w] != 0)
            {
                int right = w + map[h][w];
                if (right < size)
                {
                    dp[h][right] += dp[h][w];
                }
                
                int down = h + map[h][w];
                if (down < size)
                {
                    dp[down][w] += dp[h][w];
                }
            }       
        }
    }

    //for debug
    //cout << '\n';
    //for (int h = 0; h < size; ++h)
    //{
    //    for (int w = 0; w < size; ++w)
    //    {
    //        cout << dp[h][w] << " ";
    //    }
    //    cout << '\n';
    //}

    cout << dp[size - 1][size - 1] << '\n';

    return 0;
}
/*
예제 1:
11
1 1 2 2 3 3 3 3 2 3 1
1 1 3 2 2 2 3 1 3 2 3
1 3 3 2 2 2 3 3 2 2 1
3 2 2 3 2 3 1 2 3 1 1
3 1 3 3 3 1 2 1 3 3 2
3 1 1 3 3 1 2 3 3 1 1
3 2 2 1 1 1 2 1 1 3 2
2 2 3 2 1 1 2 3 2 2 3
3 3 1 3 2 1 3 1 1 2 2
3 3 3 2 3 2 2 3 2 1 3
2 2 1 2 3 3 2 2 1 1 0
답: 232

예제 2:
11
1 1 0 2 3 3 3 3 2 3 1
1 1 3 2 2 9 3 1 3 2 3
0 3 3 2 2 2 3 3 2 2 1
3 2 2 3 2 3 1 2 3 1 1
3 1 9 3 3 1 2 1 3 3 2
3 1 1 3 3 1 2 3 3 1 1
3 2 2 1 1 1 2 1 1 3 2
2 2 3 2 1 1 2 4 4 4 4
3 3 1 3 2 1 3 4 3 3 3
3 3 3 2 3 2 2 4 3 2 2
2 2 1 2 3 3 2 4 3 2 0
답: 0

예제 3:
17
2 2 1 1 3 2 1 1 1 1 3 2 3 1 3 3 3
1 1 1 3 2 1 1 3 3 1 3 3 1 1 1 1 2
1 2 2 1 1 1 2 1 2 1 1 3 2 3 3 3 1
1 1 1 3 3 1 1 2 3 3 3 2 1 2 1 1 2
2 3 2 1 1 2 1 1 2 3 3 3 2 1 2 3 3
3 3 3 2 3 2 1 2 3 1 3 1 1 2 2 3 3
3 1 2 1 3 2 1 2 1 3 3 1 2 1 2 1 1
3 3 2 1 2 1 1 2 3 3 3 3 3 3 3 2 1
2 3 1 2 1 2 2 2 3 1 3 3 2 3 1 1 3
1 3 1 1 3 1 1 3 1 3 3 1 3 3 2 1 1
1 3 1 2 2 3 1 2 2 2 3 1 3 2 2 1 2
3 2 1 3 2 1 2 2 1 2 1 2 2 2 2 3 2
2 3 2 1 1 1 1 2 2 3 2 1 1 1 3 3 2
2 3 1 2 2 1 3 1 1 2 2 2 2 3 2 2 1
2 2 1 3 2 1 3 2 1 2 1 1 3 2 3 1 2
2 3 2 3 3 2 1 3 2 3 3 2 2 3 1 2 1
3 1 1 1 2 3 2 2 3 3 2 2 1 3 3 1 0
답: 14881
*/