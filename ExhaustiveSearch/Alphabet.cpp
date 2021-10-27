/*
알파벳
https://www.acmicpc.net/problem/1987
*/
#include <iostream>
#include <vector>

#define SIZE 4

using namespace std;

// 전역으로 사용할 변수 선언
int leftRight[SIZE] = {-1, 1, 0, 0};
int upDown[SIZE] = {0, 0, -1, 1}; 

int calc(vector<vector<char>>& board, vector<bool>& check, int currX, int currY);
int main()
{
    int row(0), col(0);
    cin >> row >> col;
    
    vector<vector<char>> board(row, vector<char>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> board[i][j];
        }
    }
    
    // 재귀에서 사용할 변수 선언
    vector<bool> check(26); // A ~ Z, 총 26개의 알파벳
    
    // 1행 1열은 이미 말이 놓여있으므로, 사용했음 처리
    int idx = board[0][0] - 'A'; // ex) 'C' 가 저장되어있다면 'C'(99) - 'A'(97) = 2
    check[idx] = true;

    // 재귀 시작
    cout << calc(board, check, 0, 0) << '\n';

    return 0;
}

int calc(vector<vector<char>>& board, vector<bool>& check, int currX, int currY)
{
    int answer = 0;
    for (int n = 0; n < SIZE; n++)
    {
        int nextX = currX + leftRight[n];
        int nextY = currY + upDown[n];
        
        // 주어진 행과 열이 범위 내에 있고 아직 방문하지 않았다면 재귀를 돌 수 있다
        if(nextX >= 0 && nextX < board.size() && nextY >= 0 && nextY < board[0].size())
        {
            int idx = board[nextX][nextY] - 'A';
            if (check[idx] == false)
            {
                check[idx] = true;
                
                int cnt =  calc(board, check, nextX, nextY);
                
                if (answer < cnt)
                {
                    answer = cnt;
                }
                
                check[idx] = false;
            }
        }        
    }

    return answer + 1;
}