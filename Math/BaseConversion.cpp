/*
Base Conversion
https://www.acmicpc.net/problem/11576
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);

    vector<int> result;
    int A(0), B(0); //A진법을 B진법으로 변환하여 출력
    int m(0);       //자리수의 개수
    cin >> A >> B >> m;
    
    //A진법 -> 10진법
    int digit(0);
    for (int i = m - 1; i >= 0; --i)
    {
        int num(0);
        cin >> num;
        digit += num * static_cast<int>(pow(A, i));
    }
    
    //10진법 -> B진법
    while (digit != 0)
    {
        result.push_back(digit % B);
        digit /= B;
    }

    for (auto it = result.rbegin(); it != result.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << '\n';

    return 0;
}