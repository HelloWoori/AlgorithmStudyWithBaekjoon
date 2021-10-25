/*
스도쿠
https://www.acmicpc.net/problem/2580
*/
#include <iostream>

#define MAX 9

using namespace std;

// 필요한 변수 전역으로 설정
int board[MAX][MAX];
bool row[MAX][MAX];
bool col[MAX][MAX];
bool square[MAX][MAX];

// 함수 정의
int which_square_is_it(int x, int y);
void print_board();
void calc(int cnt);
int main()
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            // 입력받기
            int num = 0;
            cin >> num;
            
            // 현재 스도쿠 상태를 담는다
            board[x][y] = num;
            
            // 이미 숫자가 정해진 곳을 표시한다 (가로, 세로, 작은 사각형)
            if (board[x][y] != 0)
            {
                row[x][num] = true;    // x 행에 숫자 num 이 있으면 true
                col[y][num] = true;    // y 열에 숫자 num 이 있으면 true

                int n = which_square_is_it(x, y);
                square[n][num] = true; // 작은 n번째 정사각형에 숫자 num 이 있으면 true
            }
        }
    }

    // 재귀 시작
    calc(0);
  
    return 0;
}

int which_square_is_it(int x, int y)
{
    return (int)(x / 3) * 3 + (int)(y / 3);
}

void print_board()
{
    // cout << "-----------------" << '\n';
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            cout << board[x][y] << " ";
        }
        cout << '\n';
    }
}

void calc(int cnt)
{
    int x = (int)(cnt / 9);
    int y = (int)(cnt % 9);
    int n = which_square_is_it(x, y);
  
    if (cnt == MAX * MAX)
    {
        print_board();
        exit(0);
    }

    if (board[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (row[x][i] == false &&
                col[y][i] == false &&
                square[n][i] == false)
            {
                row[x][i] = true;
                col[y][i] = true;
                square[n][i] = true;
                board[x][y] = i;
              
                calc(cnt + 1);

                board[x][y] = 0;
                square[n][i] = false;
                col[y][i] = false;
                row[x][i] = false;
            }
        }
    }
    else
    {
        calc(cnt + 1);
    }
}