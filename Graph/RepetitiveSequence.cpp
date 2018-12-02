/*
반복수열
https://www.acmicpc.net/problem/2331
*/
#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int CalNextNum(int num, int P);

int main()
{
    map<int, int> m;

    int firstNum, P;
    cin >> firstNum >> P;

    int index = 1;
    m[firstNum] = index;

    int next = firstNum;

    while (true)
    {
        index++;

        next = CalNextNum(next, P);
            
        if (m.find(next) == m.end())
        {
            //아직 없다
            m[next] = index;
            //cout << next << ", " << m[next] << endl;
        }
        else
        {
            //이미 있다
            break;
        }

    }
    cout << m[next] - 1 << '\n';

    return 0;
}

//각 자리수를 P번 곱한 수들의 합 리턴
int CalNextNum(int num, int P)
{
    string str = to_string(num);
    int sum = 0;

    for (auto ch : str)
    {
        int n = ch - '0';
        sum += pow(n, P);
    }

    return sum;
}