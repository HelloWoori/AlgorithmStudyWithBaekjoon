/*
열 개씩 끊어 출력하기
https://www.acmicpc.net/problem/11721
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string str("");
    cin >> str;

    for (size_t i = 1; i <= str.size(); ++i)
    {
        cout << str[i - 1];
        if (i % 10 == 0)
            cout << '\n';
    }
    cout << '\n';

    return 0;
}