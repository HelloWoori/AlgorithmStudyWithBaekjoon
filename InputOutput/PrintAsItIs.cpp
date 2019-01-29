/*
그대로 출력하기
https://www.acmicpc.net/problem/11718
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string str("");
    while (getline(cin, str))
    {
        cout << str << '\n';
    }

    return 0;
}