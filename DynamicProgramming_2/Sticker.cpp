/*
스티커
https://www.acmicpc.net/problem/9465
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>

#define maxRow 2
#define state 3

using namespace std;

int main()
{
    int testCaseNum(0);
    cin >> testCaseNum;
    while (testCaseNum-- > 0)
    {
        int maxCol(0);
        cin >> maxCol;
        
        vector<vector<int>> sticker(maxRow, vector<int>(maxCol, 0));
        vector<vector<int>> memo(maxCol, vector<int>(state, 0));
        
        for (int row = 0; row < maxRow; row++)
        {
            for (int col = 0; col < maxCol; col++)
            {
                cin >> sticker[row][col];
            }
        }
        
        memo[0][0] = 0;
        memo[0][1] = sticker[0][0];
        memo[0][2] = sticker[1][0];
        
        for (int col = 1; col < maxCol; col++)
        {
            memo[col][0] = max({memo[col - 1][0], memo[col - 1][1], memo[col - 1][2]});
            memo[col][1] = max({memo[col - 1][0], memo[col - 1][2]}) + sticker[0][col];
            memo[col][2] = max({memo[col - 1][0], memo[col - 1][1]}) + sticker[1][col];
        }

        cout << max({memo[maxCol - 1][0], memo[maxCol - 1][1], memo[maxCol - 1][2]}) << '\n';
    }

    return 0;
}