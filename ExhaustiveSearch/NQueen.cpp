/*
N-Queen
https://www.acmicpc.net/problem/9663
*/
#include <iostream>

using namespace std;

// 필요한 변수 전역으로 설정
int boardSize;          // 단, boardSize 는 1 <= boardSize <= 15
bool map[15][15];       // 퀸을 놓았는 지 여부
bool checkCol[30];      // | col 이 같음
bool checkRightDia[30]; // / row + col 이 같음
bool checkLeftDia[30];  // \ row + col + boardSize 가 같음

bool check(int row, int col);
int calc(int row);
int main()
{
    cin >> boardSize;
  
    cout << calc(0) << '\n';
    
    return 0;
}

bool check(int row, int col)
{
    if (checkCol[col])
    {
        return false;
    }

    if (checkRightDia[row + col])
    {
        return false;
    }

    if (checkLeftDia[row - col + boardSize])
    {
        return false;
    }

    // | / \ 에 해당하지 않아서, 퀸을 놓을 수 있다
    return true;
}

int calc(int row)
{
    if(row == boardSize)
    {
        return 1;
    }

    int cnt = 0;
    for (int col = 0; col < boardSize; col++)
    {
        if (check(row, col))
        {
            checkCol[col] = true;
            checkRightDia[row + col] = true;
            checkLeftDia[row - col + boardSize] = true;
            map[row][col] = true;
          
            cnt += calc(row + 1);
          
            map[row][col] = false;
            checkLeftDia[row - col + boardSize] = false;
            checkRightDia[row + col] = false;
            checkCol[col] = false;
          
        }
    }

    return cnt;
}