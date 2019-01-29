/*
그대로 출력하기 2
https://www.acmicpc.net/problem/11719
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